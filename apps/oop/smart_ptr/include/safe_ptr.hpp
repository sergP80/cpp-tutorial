#pragma once
#include <cstddef>
#include <stdexcept>
#include <iostream>

namespace smart_ptr {

	struct xEmptyResource {};

	struct xIndexOutOfBound {};
	
	template<typename T>
	class UniquePtr {
		T* data;
	public:
		UniquePtr()
			: data(nullptr) {}

		UniquePtr(T* src)
			: data(src) {}

		UniquePtr(const UniquePtr&) = delete;
		
		UniquePtr& operator=(const UniquePtr&) = delete;

		UniquePtr(UniquePtr&& other) noexcept
			: ptr(other.ptr) {
			other.ptr = nullptr;
		}

		UniquePtr& operator=(UniquePtr&& other) noexcept {
			if (this != &other) {
				delete ptr;

				ptr = other.ptr;
				other.ptr = nullptr;
			}

			return *this;
		}

		~UniquePtr() {
			if (data) {
				delete data;
			}
		}

		const T* operator->() const {
			if (!data) {
				throw xEmptyResource();
			}
			return data;
		}

		const T& operator*() const {
			if (!data) {
				throw xEmptyResource();
			}

			return *data;
		}

		explicit operator bool() const {
			return data != nullptr;
		}
	};

	template<typename T>
	class UniquePtr<T[]> {
		T* data;
		std::size_t size;
	public:
		UniquePtr()
			: data(nullptr)
			, size(0)
		{}

		UniquePtr(int sz) 
			: data(new T[sz])
			, size(sz)
		{}
		
		UniquePtr(const UniquePtr&) = delete;

		UniquePtr& operator=(const UniquePtr&) = delete;

		UniquePtr(UniquePtr&& other) noexcept
			: data(other.data)
			, size(other.size)
		{
			other.data = nullptr;
			other.size = 0;
		}

		UniquePtr& operator=(UniquePtr&& other) noexcept {
			if (this != &other) {
				delete[] data;

				data = other.data;
				size = other.size;

				other.data = nullptr;
				other.size = 0;
			}

			return *this;
		}

		~UniquePtr() {
			if (data) {
				delete[] data;
			}
		}

		T& operator[](std::size_t index) {
			if (!data)
			{
				throw xEmptyResource();
			}

			if (index < 0 || index >= size)
			{
				throw xIndexOutOfBound();
			}

			return data[index];
		}

		const T& operator[](std::size_t index) const {
			if (!data)
			{
				throw xEmptyResource();
			}

			if (idex < 0 || index >= size)
			{
				throw xIndexOutOfBound();
			}

			return data[index];
		}

		std::size_t length() const {
			return size;
		}

		explicit operator bool() const {
			return data != nullptr;
		}
	};

	template<>
	class UniquePtr<int> {
		int* data;
	public:
		UniquePtr()
			: data(nullptr) {}
		
		UniquePtr(int* src) : data(src) {}

		~UniquePtr() {
			if (data) {
				delete data;
			}
		}

		const int* operator->() const {
			if (!data) {
				throw xEmptyResource();
			}
			return data;
		}

		const int& operator*() const {
			if (!data) {
				throw xEmptyResource();
			}

			return *data;
		}
	};


	template<>
	class UniquePtr<bool[]> {
	private:
		unsigned char* data;
		std::size_t size;      // number of bool values
		std::size_t bytes;     // number of allocated bytes

	public:
		class BoolReference {
		private:
			unsigned char& byte;
			unsigned char mask;

		public:
			BoolReference(unsigned char& byte, unsigned char mask)
				: byte(byte), mask(mask) {}

			BoolReference& operator=(bool value) {
				if (value) {
					byte |= mask;
				}
				else {
					byte &= ~mask;
				}
				return *this;
			}

			operator bool() const {
				return (byte & mask) != 0;
			}
		};

		UniquePtr()
			: data(nullptr)
			, size(0)
			, bytes(0)
		{}

		explicit UniquePtr(std::size_t sz)
			: size(sz)
			, bytes((sz + 7) / 8)
		{
			data = new unsigned char[bytes]();
		}

		~UniquePtr() {
			if (data) {
				delete[] data;
			}			
		}

		UniquePtr(const UniquePtr&) = delete;
		
		UniquePtr& operator=(const UniquePtr&) = delete;

		UniquePtr(UniquePtr&& other) noexcept
			: data(other.data)
			, size(other.size)
			, bytes(other.bytes)
		{
			other.data = nullptr;
			other.size = 0;
			other.bytes = 0;
		}

		UniquePtr& operator=(UniquePtr&& other) noexcept {
			if (this != &other) {
				delete[] data;

				data = other.data;
				size = other.size;
				bytes = other.bytes;

				other.data = nullptr;
				other.size = 0;
				other.bytes = 0;
			}

			return *this;
		}

		BoolReference operator[](std::size_t index) {
			validateIndex(index);

			std::size_t byteIndex = index / 8;
			std::size_t bitIndex = index % 8;

			unsigned char mask = static_cast<unsigned char>(1u << bitIndex);

			return BoolReference(data[byteIndex], mask);
		}

		bool operator[](std::size_t index) const {
			validateIndex(index);

			std::size_t byteIndex = index / 8;
			std::size_t bitIndex = index % 8;

			unsigned char mask = static_cast<unsigned char>(1u << bitIndex);

			return (data[byteIndex] & mask) != 0;
		}

		std::size_t length() const {
			return size;
		}

		std::size_t memoryBytes() const {
			return bytes;
		}

		explicit operator bool() const {
			return data != nullptr;
		}

	private:
		void validateIndex(std::size_t index) const {
			if (index >= size) {
				throw std::out_of_range("Index out of range");
			}
		}
	};

	template<typename T, typename... Args>
	UniquePtr<T> make_unique(Args&&... args) {
		return UniquePtr<T>(new T(std::forward<Args>(args)...));
	}

	template<typename T>
	UniquePtr<T[]> make_unique_array(std::size_t size) {
		return UniquePtr<T[]>(size);
	}

	template<typename T>
	class SharedPtr {
	private:
		T* data;
		std::size_t* counter;

		void releaseCurrent() {
			if (counter == nullptr) {
				return;
			}

			--(*counter);

			if (*counter == 0) {
				delete data;
				delete counter;
			}
		}

	public:
		SharedPtr()
			: data(nullptr)
			, counter(nullptr)
		{}

		explicit SharedPtr(T* p)
			: data(p)
			, counter(new std::size_t(1))
		{}

		SharedPtr(const SharedPtr& other)
			: data(other.data)
			, counter(other.counter) {

			if (counter != nullptr) {
				++(*counter);
			}
		}

		SharedPtr(SharedPtr&& other) noexcept
			: data(other.ptr)
			, counter(other.counter) {

			other.data = nullptr;
			other.counter = nullptr;
		}

		SharedPtr& operator=(const SharedPtr& other) {

			if (this == &other) {
				return *this;
			}

			releaseCurrent();

			data = other.data;
			counter = other.counter;

			if (counter != nullptr) {
				++(*counter);
			}

			return *this;
		}

		SharedPtr& operator=(SharedPtr&& other) noexcept {

			if (this == &other) {
				return *this;
			}

			releaseCurrent();

			data = other.data;
			counter = other.counter;

			other.data = nullptr;
			other.counter = nullptr;

			return *this;
		}

		~SharedPtr() {
			releaseCurrent();
		}

		T& operator*() const {
			return *data;
		}

		T* operator->() const {
			return data;
		}

		
		std::size_t use_count() const {
			return counter == nullptr ? 0 : *counter;
		}

		explicit operator bool() const {
			return ptr != nullptr;
		}
	};

	template<typename T, typename... Args>
	SharedPtr<T> make_shared(Args&&... args) {
		return SharedPtr<T>(new T(std::forward<Args>(args)...));
	}
}
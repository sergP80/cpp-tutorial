project("integral")

file(GLOB SRC src/*.cpp src/*.cxx)

include_directories(include)

add_library(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} ${COMMON_LIB_DEPS})

target_include_directories(
        ${PROJECT_NAME}
        PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)
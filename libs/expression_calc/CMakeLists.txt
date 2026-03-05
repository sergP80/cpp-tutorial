project("expression_calc")

include_directories(include)

file(GLOB SRC "src/*.cpp" "src/*.cxx")

add_library(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} ${COMMON_DEPS})

target_include_directories(
        ${PROJECT_NAME}
        PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)
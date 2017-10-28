cmake_minimum_required(VERSION 3.8)
set(TARGET handling_legacy_code_in_cpp_with_runtime_polymorphism_kata)
project(${TARGET})

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(flight_library)

set(SOURCE_FILES
        main.cpp Solution.h)

add_executable(${TARGET} ${SOURCE_FILES})
target_link_libraries(${TARGET} flight_library)
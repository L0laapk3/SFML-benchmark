cmake_minimum_required (VERSION 3.16)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# Include Google Benchmark
include(../cmake/GoogleBenchmark.cmake)

# SFML
include(FetchContent)
if (0)
    add_definitions(-DFASTER_TRANSFORM)
    FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/L0laapk3/SFML.git
        GIT_TAG "feature/faster-transform")
    FetchContent_MakeAvailable(SFML)
else()
    FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git)
    FetchContent_MakeAvailable(SFML)
endif()

# Add source to this project's executable.
add_executable (Transform "transform.cpp" "transform.h")

# Link Google Benchmark to the project
target_link_libraries(Transform sfml-graphics benchmark::benchmark)
target_compile_features(Transform PRIVATE cxx_std_23)
set_property(TARGET Transform PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)

# Link Shlwapi to the project
if ("${CMAKE_SYSTEM_NAME}" MATCHES "Windows")
    target_link_libraries(Transform Shlwapi)
endif()

if(WIN32)
    add_custom_command(
        TARGET Transform
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:Transform>
        VERBATIM)
endif()

install(TARGETS Transform)
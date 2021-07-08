cmake_minimum_required (VERSION 2.6)

# set the project name
if (POLICY CMP0048)
cmake_policy(SET CMP0048 OLD)
endif (POLICY CMP0048)

project(fabrica CXX)
set(CMAKE_PROJECT_VERSION "1")
set(CMAKE_PROJECT_VERSION_MAJOR "1")
set(CMAKE_PROJECT_VERSION_MINOR "0")
set(LIB_VERSION_STRING "${CMAKE_PROJECT_VERSION}.${CMAKE_PROJECT_VERSION_MAJOR}.${CMAKE_PROJECT_VERSION_MINOR}")
# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

add_subdirectory(swtc)

file(GLOB srcs "src/*.cpp")

add_executable(fabrica ${srcs})
target_include_directories(fabrica PRIVATE ./swtc)
target_link_libraries(fabrica PRIVATE swtp)

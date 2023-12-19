cmake_minimum_required(VERSION 3.25)
project(packetcaster)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE srcFiles "src/*")

# FMT
find_package(fmt CONFIG REQUIRED)
link_libraries(fmt::fmt-header-only)

add_executable(packetcaster ${srcFiles})

set_target_properties(packetcaster PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})
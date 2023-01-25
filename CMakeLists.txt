cmake_minimum_required(VERSION 3.19)
project(tinygltf)

set(TARGET tinygltf)

# ==================================================================================================
# Sources and headers
# ==================================================================================================
file(GLOB SRCS src/*.cpp)

# ==================================================================================================
# Include and target definitions
# ==================================================================================================
add_library(${TARGET} STATIC ${SRCS})
target_compile_definitions(${TARGET} PUBLIC TINYGLTF_USE_CPP14)
target_include_directories(${TARGET} PUBLIC include)
target_include_directories(${TARGET} PRIVATE src)

# ==================================================================================================
# Dependencies
# ==================================================================================================

find_package(stb CONFIG REQUIRED)
target_link_libraries(${TARGET} PUBLIC stb)

# ==================================================================================================
# Installation
# ==================================================================================================
install(TARGETS ${TARGET} ARCHIVE DESTINATION lib/${DIST_DIR})
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_PREFIX}/include)

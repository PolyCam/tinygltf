cmake_minimum_required(VERSION 3.19)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED yes)
set(ENABLE_EXCEPTIONS yes)
set(ENABLE_RTTI yes)

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
target_include_directories(${TARGET} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# ==================================================================================================
# Dependencies
# ==================================================================================================

find_package(stb CONFIG REQUIRED)
target_link_libraries(${TARGET} PUBLIC stb)

# ==================================================================================================
# Installation
# ==================================================================================================
install(TARGETS ${TARGET}
    EXPORT "${TARGET}Config"
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    INCLUDES DESTINATION include)
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_PREFIX}/include)
install(EXPORT "${TARGET}Config" DESTINATION "share/${TARGET}")

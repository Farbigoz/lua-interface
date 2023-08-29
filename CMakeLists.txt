cmake_minimum_required(VERSION 3.22)
project(lua_interface
        LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)


add_subdirectory(lua)


add_library(${PROJECT_NAME} STATIC)


file(GLOB_RECURSE interface_src
        "${CMAKE_CURRENT_SOURCE_DIR}/interface/*.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/interface/*.cpp"
)


target_sources(${PROJECT_NAME}
    PUBLIC
        ${interface_src}
)


target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/defs
        ${CMAKE_CURRENT_SOURCE_DIR}/interface
)


target_link_libraries(${PROJECT_NAME}
    PUBLIC
        lua
)
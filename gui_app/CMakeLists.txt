cmake_minimum_required(VERSION 3.16)
project(lua_interface_gui
        LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)


add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/../" "cmake-build-debug")


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

#set(CMAKE_PREFIX_PATH "C:/Qt/6.5.0/mingw_64/lib/cmake")


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)


add_executable(${PROJECT_NAME})


set(gui_src
        ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/state_tree.cpp
)

set(source_highliter_src
        ${CMAKE_CURRENT_SOURCE_DIR}/QSourceHighlite/languagedata.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/QSourceHighlite/qsourcehighliterthemes.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/QSourceHighlite/qsourcehighliter.cpp
)


target_sources(${PROJECT_NAME}
    PRIVATE
        ${gui_src}
        ${source_highliter_src}
)


target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/QSourceHighlite
        ${CMAKE_CURRENT_SOURCE_DIR}/hardware_interface
)


target_link_libraries(${PROJECT_NAME}
    PUBLIC
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets

        lua_interface
)


target_include_directories(lua_interface
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/hardware_interface
)



if (WIN32)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()

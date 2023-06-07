cmake_minimum_required(VERSION 3.22)

# Параметры проекта
project(lua
        LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)


# Создание библиотеки
add_library(${PROJECT_NAME} STATIC)


# Заголовочные файлы библиотеки
target_include_directories(${PROJECT_NAME}
    PRIVATE

    PUBLIC
        # Заголовки для импорта
        #$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/lua>
        ${CMAKE_CURRENT_SOURCE_DIR}/lua
)


# Исходные файлы библиотеки
file(GLOB_RECURSE private_sources
        "${CMAKE_CURRENT_SOURCE_DIR}/lua/*.c"
)

# Удаление файла создания standalone-интерпретатора
list(REMOVE_ITEM private_sources "${CMAKE_CURRENT_SOURCE_DIR}/lua/lua.c")       # Удаление файлов сборки standalone
list(REMOVE_ITEM private_sources "${CMAKE_CURRENT_SOURCE_DIR}/lua/onelua.c")    # Удаление файлов сборки standalone

# Исключение библиотек
list(REMOVE_ITEM private_sources "${CMAKE_CURRENT_SOURCE_DIR}/lua/lutf8lib.c")  # Отключение библиотеки utf8
list(REMOVE_ITEM private_sources "${CMAKE_CURRENT_SOURCE_DIR}/lua/ltablib.c")   # Отключение библиотеки работы с таблицами
list(REMOVE_ITEM private_sources "${CMAKE_CURRENT_SOURCE_DIR}/lua/lstrlib.c")   # Отключение библиотеки работы с строками
list(REMOVE_ITEM private_sources "${CMAKE_CURRENT_SOURCE_DIR}/lua/loslib.c")    # Отключение библиотеки работы с ОС
list(REMOVE_ITEM private_sources "${CMAKE_CURRENT_SOURCE_DIR}/lua/lmathlib.c")  # Отключение библиотеки матем. функций
list(REMOVE_ITEM private_sources "${CMAKE_CURRENT_SOURCE_DIR}/lua/liolib.c")    # Отключение библиотеки IO
list(REMOVE_ITEM private_sources "${CMAKE_CURRENT_SOURCE_DIR}/lua/ldblib.c")    # Отключение библиотеки отладки
list(REMOVE_ITEM private_sources "${CMAKE_CURRENT_SOURCE_DIR}/lua/lcorolib.c")  # Отключение библиотеки корутин
# Библиотеки так же нужно отключить/включить в lua/linit.c (в "loadedlibs")

# Исключение тестов
list(REMOVE_ITEM private_sources "${CMAKE_CURRENT_SOURCE_DIR}/lua/testes/libs/lib1.c")
list(REMOVE_ITEM private_sources "${CMAKE_CURRENT_SOURCE_DIR}/lua/testes/libs/lib2.c")
list(REMOVE_ITEM private_sources "${CMAKE_CURRENT_SOURCE_DIR}/lua/testes/libs/lib11.c")
list(REMOVE_ITEM private_sources "${CMAKE_CURRENT_SOURCE_DIR}/lua/testes/libs/lib21.c")
list(REMOVE_ITEM private_sources "${CMAKE_CURRENT_SOURCE_DIR}/lua/testes/libs/lib22.c")

target_sources(${PROJECT_NAME}
    PUBLIC
        ${private_sources}
)


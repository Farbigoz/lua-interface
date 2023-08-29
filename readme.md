## Зависимости проекта:
- [hardware_interface](https://gitlab.npcprom.ru/abtci/hardware_interface)

Добавление зависимости **hardware_interface**
- В *CMakeLists.txt* внешнего проекта нужно добавить директорию для импорта

``` CMake
target_include_directories(lua_interface
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/hardware_interface
)
```

## Сборка графического приложения
Сборка осуществляется из директории **gui_app**. Все зависимости уже подключены.
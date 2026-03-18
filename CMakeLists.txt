cmake_minimum_required(VERSION 3.16)

project(Inventory-New LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Inventory-New main.cpp
    item.hpp item.cpp
    inventory.hpp inventory.cpp
    player.hpp player.cpp

    attribute.hpp attribute.cpp
    weapon.hpp weapon.cpp

    inventory.hpp inventory.cpp
    performActions.hpp performActions.cpp
    game.hpp game.cpp
    Displaycell.hpp Displaycell.cpp
    store.cpp
    store.hpp
    enemy.hpp enemy.cpp
    dungeon.hpp dungeon.cpp
    floor.hpp floor.cpp
    orc.hpp orc.cpp
    fightingsystem.hpp fightingsystem.cpp
    sprites/Orc.txt sprites/BrickWall.txt
    battleground.cpp battleground.hpp sprites.cpp sprite.hpp
    fightdisplay.hpp fightdisplay.cpp

    material.hpp material.cpp
    armor.hpp armor.cpp
    displaycells.hpp displaycells.cpp
    sprites/BrickWall.txt sprites/Orc.txt
    equipment.hpp equipment.cpp
    padding.hpp padding.cpp

)

# Typically you don't care so much for a third party library's tests to be
# run from your own project's code.
set(JSON_BuildTests OFF CACHE INTERNAL "")

# If you only include this third party in PRIVATE source files, you do not
# need to install it when your main project gets installed.
# set(JSON_Install OFF CACHE INTERNAL "")

# Don't use include(nlohmann_json/CMakeLists.txt) since that carries with it
# unintended consequences that will break the build.  It's generally
# discouraged (although not necessarily well documented as such) to use
# include(...) for pulling in other CMake projects anyways.
add_subdirectory(nlohmann_json)

target_link_libraries(Inventory-New PRIVATE nlohmann_json::nlohmann_json)

include(GNUInstallDirs)
install(TARGETS Inventory-New
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

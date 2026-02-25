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
    singleCharacter.hpp singleCharacter.cpp
    game.hpp game.cpp
    inventorycell.hpp inventorycell.cpp
    store.cpp
    store.hpp
    enemy.hpp enemy.cpp
    dungeon.hpp dungeon.cpp
    floor.hpp floor.cpp
    orc.hpp orc.cpp
    fightingsystem.hpp fightingsystem.cpp
    sprites/Orc.txt sprites/Walls.txt
    battleground.cpp battleground.hpp sprites.cpp sprite.hpp
    fightdisplay.hpp fightdisplay.cpp

    material.hpp material.cpp
    armor.hpp armor.cpp
)

include(GNUInstallDirs)
install(TARGETS Inventory-New
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

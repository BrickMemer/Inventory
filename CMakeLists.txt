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
    material.h material.cpp


)

include(GNUInstallDirs)
install(TARGETS Inventory-New
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

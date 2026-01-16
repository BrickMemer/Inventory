cmake_minimum_required(VERSION 3.16)

project(Inventory-New LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Inventory-New main.cpp
    item.hpp item.cpp

    attribute.h attribute.cpp
)

include(GNUInstallDirs)
install(TARGETS Inventory-New
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

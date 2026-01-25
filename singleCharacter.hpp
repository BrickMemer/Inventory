#ifndef SINGLECHARACTER_H
#define SINGLECHARACTER_H

#include <iostream>
#include "player.hpp"

#ifdef _WIN32
#include <conio.h> // For _getch() on Windows
#define OS_NAME "Windows"
#define CLEAR "cls"
#elif __APPLE__
#include <TargetConditionals.h>
#include <termios.h>
#include <unistd.h>
#if TARGET_OS_MAC
#define OS_NAME "macOS"
#define CLEAR "clear"
#endif
#else
#define OS_NAME "Unknown OS"
#define CLEAR "clear"
#endif

char getSingleChar();
bool performAction(player& CurrentPlayer);


#endif // SINGLECHARACTER_H

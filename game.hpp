#ifndef GAME_HPP
#define GAME_HPP

#include "player.hpp"
#include "singleCharacter.hpp"

class game
{
private:
    player& CurrentPlayer;
    bool IsRunning = false;
public:
    game(player &CurrentPlayer);

    void Run();
    bool getIsRunning() const;
};

#endif // GAME_HPP

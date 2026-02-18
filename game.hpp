#ifndef GAME_HPP
#define GAME_HPP

#include "player.hpp"
#include "singleCharacter.hpp"
#include "store.hpp"

class game
{
private:
    player& CurrentPlayer;
    Store store;
    bool IsRunning = true;
public:
    game(player &CurrentPlayer);

    void RunGame();
    void RunStore();
    bool getIsRunning() const;
    void StopGame();
};

#endif // GAME_HPP

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
    void RunInventory();
    void RunStore();
    int RunMainMenu();
    void DisplayMainMenu(const unsigned char& SelectedOption);
public:
    game(player &CurrentPlayer);

    void RunGame();
    bool getIsRunning() const;
    void StopGame();
};

#endif // GAME_HPP

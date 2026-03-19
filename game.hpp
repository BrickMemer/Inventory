#ifndef GAME_HPP
#define GAME_HPP

#include "player.hpp"
#include "store.hpp"
#include "performActions.hpp"
#include "dungeon.hpp"

class game
{
private:
    player CurrentPlayer;
    Store store;
    bool IsRunning = true;
    void RunInventory();
    void RunStore();
    int RunMainMenu();
    void DisplayMainMenu(const unsigned char& SelectedOption);
public:
    game();

    void LoadPlayer();
    void RunDungeon();
    void RunGame();
    bool getIsRunning() const;
    void StopGame();
};

#endif // GAME_HPP

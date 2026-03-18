#include "game.hpp"
#include "displaycells.hpp"

game::game()
{
    this->CurrentPlayer.AddItem(new Weapon);
    ClearTerminal();
}

bool game::getIsRunning() const
{
    return IsRunning;
}

void game::DisplayMainMenu(const unsigned char& SelectedOption)
{
    ClearTerminal();
    for(int i = 0; i < 3; i++)
    {
        if(i == SelectedOption)
        {
            std::cout << "->";
        }
        switch(i)
        {
            case 0:
                std::cout << "Inventory" << '\n';
                break;
            case 1:
                std::cout << "Store" << '\n';
                break;
            case 2:
                std::cout << "Dungeons" << '\n';
                break;
        }
    }
}

void game::RunGame()
{
    while(this->IsRunning == true)
    {
        switch(this->RunMainMenu())
        {
        case 0:
            RunInventory();
            break;
        case 1:
            RunStore();
            break;
        case 2:
            RunDungeon();
            break;
        default:
            StopGame();
            break;
        }
    }
}

int game::RunMainMenu()
{
    ClearTerminal();
    static unsigned char CurrentOption = 0;
    while(this->IsRunning)
    {
        this->DisplayMainMenu(CurrentOption);
        switch(performActionMainMenu(CurrentOption))
        {
        case 0:
            StopGame();
            break;
        case 2:
            return CurrentOption;
            break;
        default:
            break;
        }
        if(CurrentOption >= 3)
        {
           CurrentOption--;
        }
    }
    StopGame();
    return -1;
}

void game::RunInventory()
{
    ClearTerminal();
    std::cout << "Welcome to Inventory Symulator, if you need help, press 'h'" << '\n';

    while(this->IsRunning)
    {
        ClearTerminal();
        this->CurrentPlayer.DisplayInventory();
        switch(performActionGame(this->CurrentPlayer))
        {
        case 0:
            return;
            break;
        case 2:
            break;
        default:
            break;
        }
    }
}

void game::RunDungeon()
{
    /*
    *    Configuration
    */

    dungeon GameDungeon;

    bool IsDungeonRunning = true;
    bool PlayerTurn = true;
    unsigned char CurrentChoice = 0;
    unsigned int MoneyGained = 0;

    //While the game is running and dungeon is running
    while(this->IsRunning == true && IsDungeonRunning == true)
    {
        ClearTerminal();
        if(GameDungeon.getFloor().IsEmpty() == true)
        {
            // if there is no more floors to go throw, end the dungeon
            if(GameDungeon.MoveForward() == false)
            {
                std::cout << "You sad complited the dungeon";
                IsDungeonRunning = !IsDungeonRunning;
            }
            else
            {
                do
                {
                    std::cout << "You had defeted the enemy, your currently gained: " << MoneyGained;
                    ClearTerminal();
                }while(!getSingleChar());
                continue;
            }
        }

        // Display the Dungeon

        GameDungeon.DisplayFight(CurrentChoice, "BrickWall");

        //

        //If it's player turn
        if(PlayerTurn == true)
        {
            switch (performActionDungeon(CurrentChoice, this->CurrentPlayer))
            {
            case 0:
                IsDungeonRunning = !IsDungeonRunning;
                ClearTerminal();
                break;
            case 2:
                switch(CurrentChoice)
                {
                case 0:
                {
                    ClearTerminal();
                    int TempMoney = GameDungeon.PlayerAttack(this->CurrentPlayer.Attack(), 0);
                    if(TempMoney > 0)
                    {
                        MoneyGained += TempMoney;
                        do
                        {
                            std::cout << "You had defeted the selected enemy";
                        }while(!getSingleChar());
                        break;
                    }
                    else
                    {
                        do
                        {
                            std::cout << "You did: " << this->CurrentPlayer.Attack() << " damage" << '\n'
                                      << "Current enemy health: " << GameDungeon.GetEnemy(0).getHp();
                        }while(!getSingleChar());
                        PlayerTurn = !PlayerTurn;
                        break;
                    }

                }
                case 1:
                    IsDungeonRunning = !IsDungeonRunning;
                    ClearTerminal();
                    break;
                default:
                    break;
                }
                break;

            default:
                break;
            }
        }

        //else If player health is lower or equal to zero, end run
        else if(CurrentPlayer.getHealth() <= 0)
        {
            IsDungeonRunning = !IsDungeonRunning;
            this->CurrentPlayer.Death();
        }

        //else if it's not player move, random monster will do his.
        else if(PlayerTurn == false)
        {
            GameDungeon.EnemyAttack(this->CurrentPlayer);
            ClearTerminal();
            do
            {
                std::cout << "Enemy attacked you for: " << GameDungeon.GetEnemy(0).getDamage() << " damage" << '\n'
                          << "you currenty have: " << this->CurrentPlayer.getHealth() << " health";
            }while(!getSingleChar());
            PlayerTurn = !PlayerTurn;
        }
        // Return player, if he want to go future with the choices then 2
        if (CurrentChoice >= 2)
        {
            CurrentChoice--;
        }
    }

    // After the run, show how much gold you've gained
    do
    {
        std::cout << "You gained: " << MoneyGained << " money";
    } while (!getSingleChar());
    CurrentPlayer.Revive();
    CurrentPlayer.AddMoney(MoneyGained);
    return;
}

void game::LoadPlayer()
{
    CurrentPlayer.LoadInventory();
}

void game::RunStore()
{
    ClearTerminal();
    std::cout << "Welcome to the Store, if you need help, press 'h'" << '\n';

    bool IsStoreRunning = true;
    while (IsStoreRunning)
    {
        this->store.DisplayStore();
        switch (performActionStore(this->CurrentPlayer, this->store))
        {
        case 0:
            this->CurrentPlayer.ResetCorrdinates();
            ClearTerminal();
            return;
        default:
            break;
        }
    }
}

void game::StopGame()
{
    this->IsRunning = false;
}

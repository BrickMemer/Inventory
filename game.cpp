#include "game.hpp"

game::game(player &CurrentPlayer) : CurrentPlayer(CurrentPlayer)
{
    //this->CurrentPlayer.AddItem(new Weapon);
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
    return 99;
}

void game::RunInventory()
{
    ClearTerminal();
    std::cout << "Welcome to Inventory Symulator, if you need help, press 'h'" << '\n';

    while(this->IsRunning)
    {
        this->CurrentPlayer.DisplayInventory();
        switch(performActionGame(this->CurrentPlayer))
        {
        case 0:
            return;
            break;
        case 2:
            this->CurrentPlayer.ResetCorrdinates();
            ClearTerminal();
            this->RunStore();
            break;
        default:
            break;
        }
    }
}

void game::RunDungeon()
{
    dungeon GameDungeon;

    bool IsDungeonRunning = true;
    bool PlayerTurn = true;
    unsigned char CurrentChoice = 0;
    unsigned int MoneyGained = 0;

    while(this->IsRunning == true && IsDungeonRunning == true)
    {
        ClearTerminal();
        GameDungeon.DisplayFight(CurrentChoice);
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
                    MoneyGained += GameDungeon.PlayerAttack(this->CurrentPlayer.Attack(), 0);
                    ClearTerminal();
                    do
                    {
                        std::cout << "You did: " << this->CurrentPlayer.Attack() << "damage" << '\n'
                                  << "Current enemy health: " << GameDungeon.GetEnemy(0).getHp();
                    }while(!getSingleChar());
                        PlayerTurn = !PlayerTurn;
                    break;
                }
                case 1:
                    IsDungeonRunning = !IsDungeonRunning;
                    ClearTerminal();
                    break;
                }
                break;
            default:
                break;
            }
        }
        if(CurrentPlayer.getHealth() <= 0)
        {
            IsDungeonRunning = !IsDungeonRunning;
        }
        else if(PlayerTurn == false)
        {
            GameDungeon.EnemyAttack(this->CurrentPlayer);
            ClearTerminal();
            do
            {
                std::cout << "Enemy attacked you for: " << GameDungeon.GetEnemy(0).getDamage() << "damage" << '\n'
                          << "you currenty have: " << this->CurrentPlayer.getHealth() << "health";
            }while(!getSingleChar());
            PlayerTurn = !PlayerTurn;
        }
        if(GameDungeon.getFloor().IsEmpty() == true)
        {
            GameDungeon.MoveForward();
        }
        else if (CurrentChoice >= 2)
        {
            CurrentChoice--;
        }
    }
    do
    {
        std::cout << "You gained: " << MoneyGained << " money";
    } while (!getSingleChar());
    CurrentPlayer.Revive();
    CurrentPlayer.AddMoney(MoneyGained);
    return;
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

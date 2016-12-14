#include "game.h"
#include "board.h"

#include <ncurses.h>
#include <cstdlib>
#include <sstream>

static const std::string PlayerStr("Player");

Game::Game()
{
    CreatePlayer('1', 'X', true);
    CreatePlayer('2', 'O', false);
}

void Game::RunGame()
{
    initscr();
    Board gameBoard;
    bool isWinner = false;
    uint iter = 0;
    do
    {
        clear();
        gameBoard.DrawBoard();
        const Player& activePlayer = GetActivePlayer();

        if(isWinner)
        {
            printw("\n\t%s WIN!!!", activePlayer.m_Name.c_str());
            break;
        }
        else
        {
            if(iter == 9)
            {
                printw("\n\tDRAW!!!");
                break;
            }
            GetCurrentPlayerInfo();
        }

        char posVal = getch();
        int pos = posVal - '0';
        if(pos > 9 || pos < 1)
            continue;

        gameBoard.UpdateBoard(pos, activePlayer.m_Symbol);
        isWinner = gameBoard.CheckWin();

        if(!isWinner)
        {
            UpdateCurrentPlayer();
            iter ++;
        }
    }while(true);
    getch();
    endwin();
}

void Game::CreatePlayer(const char playerNum, const char playerVal, bool isActive)
{
    Player player;
    player.m_Name += PlayerStr + playerNum;
    player.m_Symbol = playerVal;
    player.m_IsActive = isActive;
    m_Players.push_back(player);
}

void Game::UpdateCurrentPlayer()
{
    for(Player& p : m_Players)
        p.m_IsActive = !p.m_IsActive;
}

Player Game::GetActivePlayer() const
{
    for(Player p : m_Players)
        if(p.m_IsActive)
            return p;

    return Player();
}

void Game::GetCurrentPlayerInfo() const
{
    std::string playersInfo;
    for(const Player& p : m_Players)
        playersInfo += p.GetPlayerName();

    printw("\n\t%s", playersInfo.c_str());
}

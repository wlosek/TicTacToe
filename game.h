#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>

struct Player
{
    std::string     m_Name;
    char            m_Symbol;
    bool            m_IsActive;

    std::string GetPlayerName() const
    {
        return m_IsActive ? " > " + m_Name : "   " + m_Name;
    }
};

class Game
{
public:
    Game();
    void        RunGame();

private:
    std::vector<Player>     m_Players;

    void                    CreatePlayer(const char playerNum, const char playerVal, bool isActive);
    void                    UpdateCurrentPlayer();
    Player                  GetActivePlayer() const;
    void                    GetCurrentPlayerInfo() const;
};

#endif // GAME_H

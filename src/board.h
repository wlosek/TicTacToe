#ifndef BOARD_H
#define BOARD_H

#include <ncurses.h>
#include <array>

#define ASIZE 9

class Board
{
public:
    Board();

    void        DrawBoard() const;
    void        UpdateBoard(const unsigned int pos, const char value);
    bool        CheckWin() const;

private:
    std::array<char, ASIZE>     m_Table;
};

#endif // BOARD_H

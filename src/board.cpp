#include "board.h"
#include <ncurses.h>

Board::Board()
    : m_Table{'1', '2', '3', '4', '5', '6', '7', '8', '9'}
{
    //
}

void Board::DrawBoard() const
{
    printw("\t\tTicTacToe\n");
    printw("\tPlayer1 (X) - Player2 (O)\n");
    printw("\t     |     |     \n");
    printw("\t  %c  |  %c  |  %c  \n", m_Table.at(0), m_Table.at(1), m_Table.at(2));
    printw("\t_____|_____|_____\n");
    printw("\t     |     |     \n");
    printw("\t  %c  |  %c  |  %c  \n", m_Table.at(3), m_Table.at(4), m_Table.at(5));
    printw("\t_____|_____|_____\n");
    printw("\t     |     |     \n");
    printw("\t  %c  |  %c  |  %c  \n", m_Table.at(6), m_Table.at(7), m_Table.at(8));
    printw("\t     |     |     \n");
}

void Board::UpdateBoard(const unsigned int pos, const char value)
{
    m_Table.at(pos - 1) = value;
}

bool Board::CheckWin() const
{
    if((m_Table.at(0) == m_Table.at(1) && m_Table.at(1) == m_Table.at(2))
      || (m_Table.at(3) == m_Table.at(4) && m_Table.at(4) == m_Table.at(5))
      || (m_Table.at(6) == m_Table.at(7) && m_Table.at(7) == m_Table.at(8)))
        return true;

    if((m_Table.at(0) == m_Table.at(3) && m_Table.at(3) == m_Table.at(6))
      || (m_Table.at(1) == m_Table.at(4) && m_Table.at(4) == m_Table.at(7))
      || (m_Table.at(2) == m_Table.at(5) && m_Table.at(5) == m_Table.at(8)))
        return true;

    if((m_Table.at(0) == m_Table.at(4) && m_Table.at(4) == m_Table.at(8))
      || (m_Table.at(2) == m_Table.at(4) && m_Table.at(4) == m_Table.at(6)))
        return true;

    return false;
}

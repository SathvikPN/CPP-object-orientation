/* 
 * Tic-Tac-Toe game via object orientated implementation
 * Test run: https://www.onlinegdb.com/online_c++_compiler
 */
#include <iostream>
#include <cstdlib> /* system cmds */

class TicTacToe {
public:
    TicTacToe();
    virtual ~TicTacToe();
    void run();
private:
    char board[3][3];
    int player;
    int winner;
    int entries;
    void clearConsole();
    void showBoard();
    void play();
    bool validPosition(int row, int column);
    bool gameOver();
};

TicTacToe::TicTacToe()
{
    entries = 0;
    winner = 0;
    /* reset board */
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            board[i][j] = '_';
}

TicTacToe::~TicTacToe()
{
    std::cout << "Game ended.\n";
}

void TicTacToe::clearConsole()
{
    #ifdef _WIN32
    system("cls");
    #else 
    system("clear");
    #endif
}

void TicTacToe::showBoard()
{
    clearConsole();
    std::cout << "Board Status < Tic-Tac-Toe >\n";
    std::cout << "   0   1   2  \n";
    for(int i=0; i<3; i++)
    {
        std::cout<< i << " ";
        for(int j=0; j<3; j++)
        {
            std::cout << "[" << board[i][j] << "] ";
        }
        std::cout << std::endl;
    }
}

bool TicTacToe::validPosition(int row, int column)
{
    bool validRow = (row>=0 && row<=2) ? true:false;
    bool validColumn = (column>=0 && column<=2) ? true:false;
    if(validRow && validColumn && board[row][column]=='_')
        return true;
    return false;
}

void TicTacToe::play()
{
    player = (entries&1) ? 2:1;

    std::cout << "[ROW COLUMN] Player" << player << ": ";
    int row, column;
    std::cin >> row >> column;

    if(validPosition(row, column))
    {
        board[row][column] = (player==1) ? 'X':'O';
        entries++;
        showBoard();
    }
    else
    {
        std::cout << "<Invalid position>\n";
        play();
    }
}

bool TicTacToe::gameOver()
{    
    /* check winning situation */
    for(int i=0; i<3; i++)
    {
        if((board[i][0] != '_') && (board[i][0] == board[i][1]) && (board[i][0] == board[i][2])) /* row check */
            winner = (board[i][0] == 'X') ? 1:2;

        if((board[0][i] != '_') && (board[0][i] == board[1][i]) && (board[0][i] == board [2][i])) /* column check */
            winner = (board[0][i] == 'X') ? 1:2;
    }
    /* diagonal check */
    if(board[1][1]!='_')
    {
        bool diagonal1 = ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) ? true:false;
        bool diagonal2 = ((board[2][0] == board[1][1]) && (board[1][1] == board[0][2])) ? true:false;
        if(diagonal1 || diagonal2)
            winner = (board[1][1] == 'X') ? 1:2;
    }
    if(winner)
        return true;

    /* check match draw condition */
    if(entries==9)
        return true; 

    return false;
}

void TicTacToe::run()
{
    showBoard();
    while(!gameOver())
        play();

    if(winner)
        std::cout <<"WINNER: Player" << winner << std::endl;
    else
        std::cout << "< MATCH DRAW >" << std::endl;
}

/* driver code ---------------------------------------------------------------------------------------------- */
int main()
{
    TicTacToe game;
    game.run();
    return EXIT_SUCCESS;
}

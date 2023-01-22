#include <iostream>

using namespace std;

int seed;                  // * game number that generates the game
int randNum[4];            // * This is an array that keeps the value of a pseudo-random number
int x_pos, y_pos;          // * position of the user input number
bool filled = 1;           // * when not swapped to '0', all the spaces are used, hence the end of game
bool make_mistake = false; // * 'true' if a mistake was made in the game
bool end_game;             // * 'true' when game is finished (when all the spaces are filled)
class boards
{
public:
    string coordinate;      // * This is the coordinate of the board chosen by the player
    string myNum;           // * This is the number chosen by the player
    string user_num[9][9] = // * Graph of user-placed numbers
        {
            {" ", " ", " ", " ", " ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " ", " ", " ", " ", " "}};

    void brd()
    {
        cout << "    1   2   3   4   5   6   7   8   9" << endl;
        cout << "  =====================================" << endl;
        cout << "A | " << user_num[0][0] << " । " << user_num[0][1] << " । " << user_num[0][2] << " | " << user_num[0][3] << " । " << user_num[0][4] << " । " << user_num[0][5] << " | " << user_num[0][6] << " । " << user_num[0][7] << " । " << user_num[0][8] << " |" << endl;
        cout << "  —————————————————————————————————————" << endl;
        cout << "B | " << user_num[1][0] << " । " << user_num[1][1] << " । " << user_num[1][2] << " | " << user_num[1][3] << " । " << user_num[1][4] << " । " << user_num[1][5] << " | " << user_num[1][6] << " । " << user_num[1][7] << " । " << user_num[1][8] << " |" << endl;
        cout << "  —————————————————————————————————————" << endl;
        cout << "C | " << user_num[2][0] << " । " << user_num[2][1] << " । " << user_num[2][2] << " | " << user_num[2][3] << " । " << user_num[2][4] << " । " << user_num[2][5] << " | " << user_num[2][6] << " । " << user_num[2][7] << " । " << user_num[2][8] << " |" << endl;
        cout << "  =====================================" << endl;

        cout << "D | " << user_num[3][0] << " । " << user_num[3][1] << " । " << user_num[3][2] << " | " << user_num[3][3] << " । " << user_num[3][4] << " । " << user_num[3][5] << " | " << user_num[3][6] << " । " << user_num[3][7] << " । " << user_num[3][8] << " |" << endl;
        cout << "  —————————————————————————————————————" << endl;
        cout << "E | " << user_num[4][0] << " । " << user_num[4][1] << " । " << user_num[4][2] << " | " << user_num[4][3] << " । " << user_num[4][4] << " । " << user_num[4][5] << " | " << user_num[4][6] << " । " << user_num[4][7] << " । " << user_num[4][8] << " |" << endl;
        cout << "  —————————————————————————————————————" << endl;
        cout << "F | " << user_num[5][0] << " । " << user_num[5][1] << " । " << user_num[5][2] << " | " << user_num[5][3] << " । " << user_num[5][4] << " । " << user_num[5][5] << " | " << user_num[5][6] << " । " << user_num[5][7] << " । " << user_num[5][8] << " |" << endl;
        cout << "  =====================================" << endl;

        cout << "G | " << user_num[6][0] << " । " << user_num[6][1] << " । " << user_num[6][2] << " | " << user_num[6][3] << " । " << user_num[6][4] << " । " << user_num[6][5] << " | " << user_num[6][6] << " । " << user_num[6][7] << " । " << user_num[6][8] << " |" << endl;
        cout << "  —————————————————————————————————————" << endl;
        cout << "H | " << user_num[7][0] << " । " << user_num[7][1] << " । " << user_num[7][2] << " | " << user_num[7][3] << " । " << user_num[7][4] << " । " << user_num[7][5] << " | " << user_num[7][6] << " । " << user_num[7][7] << " । " << user_num[7][8] << " |" << endl;
        cout << "  —————————————————————————————————————" << endl;
        cout << "I | " << user_num[8][0] << " । " << user_num[8][1] << " । " << user_num[8][2] << " | " << user_num[8][3] << " । " << user_num[8][4] << " । " << user_num[8][5] << " | " << user_num[8][6] << " । " << user_num[8][7] << " । " << user_num[8][8] << " |" << endl;
        cout << "  =====================================" << endl;
    }
    static const int N = 9;

    bool checkRow(int board[N][N], int row, int num)
    {
        for (int i = 0; i < N; i++)
        {
            if (board[row][i] == num)
            {
                return false;
            }
        }
        return true;
    }

    bool checkCol(int board[N][N], int col, int num)
    {
        for (int i = 0; i < N; i++)
        {
            if (board[i][col] == num)
            {
                return false;
            }
        }
        return true;
    }

    bool checkBox(int board[N][N], int startRow, int startCol, int num)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i + startRow][j + startCol] == num)
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool isSafe(int board[N][N], int row, int col, int num)
    {
        return checkRow(board, row, num) && checkCol(board, col, num) && checkBox(board, row - row % 3, col - col % 3, num);
    }

    bool solveSudoku(int board[N][N], int row, int col)
    {
        if (row == N - 1 && col == N)
        {
            return true;
        }

        if (col == N)
        {
            row++;
            col = 0;
        }

        if (board[row][col] != 0)
        {
            return solveSudoku(board, row, col + 1);
        }

        for (int num = 1; num <= N; num++)
        {
            if (isSafe(board, row, col, num))
            {
                board[row][col] = num;

                if (solveSudoku(board, row, col + 1))
                {
                    return true;
                }

                board[row][col] = 0;
            }
        }
        return false;
    }
    void user_input(string position)
    {
        switch (coordinate[0])
        {
        case 'a':
            x_pos = 0;
            break;
        case 'b':
            x_pos = 1;
            break;
        case 'c':
            x_pos = 2;
            break;
        case 'd':
            x_pos = 3;
            break;
        case 'e':
            x_pos = 4;
            break;
        case 'f':
            x_pos = 5;
            break;
        case 'g':
            x_pos = 6;
            break;
        case 'h':
            x_pos = 7;
            break;
        case 'i':
            x_pos = 8;
            break;
        }
        switch (coordinate[1])
        {
        case '1':
            y_pos = 0;
            break;
        case '2':
            y_pos = 1;
            break;
        case '3':
            y_pos = 2;
            break;
        case '4':
            y_pos = 3;
            break;
        case '5':
            y_pos = 4;
            break;
        case '6':
            y_pos = 5;
            break;
        case '7':
            y_pos = 6;
            break;
        case '8':
            y_pos = 7;
            break;
        case '9':
            y_pos = 8;
            break;
        }
    }
    void add_val()
    {
        user_num[x_pos][y_pos] = myNum;
    }
    void check_space()
    {
        filled = true;
        for (int a = 0; a < 9; a++)
        {
            for (int b = 0; b < 9; b++)
            {
                if (user_num[a][b] == " ")
                {
                    filled = false;
                }
            }
        }
        if (filled == true)
        {
            end_game = true;
        }
    }
};

int main()
{
    boards myBrd;

    cout << "                 SUDOKU\nPut in a random seed" << endl;

    myBrd.brd();
    cout << "\nseed: ";
    cin >> seed;

    const int N = 9;

    int board[N][N] =
        {
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0}};

    for (int i = 0; i < seed; i++)
    {
        randNum[0] = rand() % 10; // generates a number between 1 and 9
        randNum[1] = rand() % 10;
    }

    for (int i = 1; i < 10; i++)
    {
        do
        {
            randNum[0] = rand() % 3 + 0;
            randNum[1] = rand() % 3 + 0;
        } while (board[randNum[0]][randNum[1]] != 0);
        board[randNum[0]][randNum[1]] = (i);
    }

    for (int i = 1; i < 10; i++)
    {
        do
        {
            randNum[0] = rand() % 3 + 6;
            randNum[1] = rand() % 3 + 6;
        } while (board[randNum[0]][randNum[1]] != 0);
        board[randNum[0]][randNum[1]] = (i);
    }

    // * This generates all the correct numbers and prepares them to be checked with human input values later
    myBrd.solveSudoku(board, 0, 0);

    // * randNum[2] is a variable used for the amount of random numbers that will show up in first place
    randNum[2] = rand() % 10 + 30;
    for (int i = 0; i < randNum[2]; i++)
    {
        randNum[0] = rand() % 9;
        randNum[1] = rand() % 9;
        myBrd.user_num[randNum[0]][randNum[1]] = to_string(board[randNum[0]][randNum[1]]);
    }

    while (end_game == false)
    {
        cout << "                 SUDOKU" << endl;
        myBrd.brd();
        cout << "\nCoordinate: ";
        cin >> myBrd.coordinate;
        myBrd.user_input(myBrd.coordinate);
        cout << "Number: ";
        cin >> myBrd.myNum;
        myBrd.add_val();
        myBrd.check_space();
    }
    myBrd.brd();
    for (int a = 0; a < 9; a++)
    {
        for (int b = 0; b < 9; b++)
        {
            if (myBrd.user_num[a][b] != to_string(board[a][b]))
            {
                make_mistake = true;
            }
            else
            {
                make_mistake = false;
            }
        }
    }
    if (make_mistake == true)
    {
        cout << "You did not successfully finish the game!\n The correct game would look like this:" << endl;

        cout << "    1   2   3   4   5   6   7   8   9" << endl;
        cout << "  =====================================" << endl;
        cout << "A | " << board[0][0] << " । " << board[0][1] << " । " << board[0][2] << " | " << board[0][3] << " । " << board[0][4] << " । " << board[0][5] << " | " << board[0][6] << " । " << board[0][7] << " । " << board[0][8] << " |" << endl;
        cout << "  —————————————————————————————————————" << endl;
        cout << "B | " << board[1][0] << " । " << board[1][1] << " । " << board[1][2] << " | " << board[1][3] << " । " << board[1][4] << " । " << board[1][5] << " | " << board[1][6] << " । " << board[1][7] << " । " << board[1][8] << " |" << endl;
        cout << "  —————————————————————————————————————" << endl;
        cout << "C | " << board[2][0] << " । " << board[2][1] << " । " << board[2][2] << " | " << board[2][3] << " । " << board[2][4] << " । " << board[2][5] << " | " << board[2][6] << " । " << board[2][7] << " । " << board[2][8] << " |" << endl;
        cout << "  =====================================" << endl;

        cout << "D | " << board[3][0] << " । " << board[3][1] << " । " << board[3][2] << " | " << board[3][3] << " । " << board[3][4] << " । " << board[3][5] << " | " << board[3][6] << " । " << board[3][7] << " । " << board[3][8] << " |" << endl;
        cout << "  —————————————————————————————————————" << endl;
        cout << "E | " << board[4][0] << " । " << board[4][1] << " । " << board[4][2] << " | " << board[4][3] << " । " << board[4][4] << " । " << board[4][5] << " | " << board[4][6] << " । " << board[4][7] << " । " << board[4][8] << " |" << endl;
        cout << "  —————————————————————————————————————" << endl;
        cout << "F | " << board[5][0] << " । " << board[5][1] << " । " << board[5][2] << " | " << board[5][3] << " । " << board[5][4] << " । " << board[5][5] << " | " << board[5][6] << " । " << board[5][7] << " । " << board[5][8] << " |" << endl;
        cout << "  =====================================" << endl;

        cout << "G | " << board[6][0] << " । " << board[6][1] << " । " << board[6][2] << " | " << board[6][3] << " । " << board[6][4] << " । " << board[6][5] << " | " << board[6][6] << " । " << board[6][7] << " । " << board[6][8] << " |" << endl;
        cout << "  —————————————————————————————————————" << endl;
        cout << "H | " << board[7][0] << " । " << board[7][1] << " । " << board[7][2] << " | " << board[7][3] << " । " << board[7][4] << " । " << board[7][5] << " | " << board[7][6] << " । " << board[7][7] << " । " << board[7][8] << " |" << endl;
        cout << "  —————————————————————————————————————" << endl;
        cout << "I | " << board[8][0] << " । " << board[8][1] << " । " << board[8][2] << " | " << board[8][3] << " । " << board[8][4] << " । " << board[8][5] << " | " << board[8][6] << " । " << board[8][7] << " । " << board[8][8] << " |" << endl;

        cout << endl;
    }
    else
    {
        cout << "You have successfully finished the game! great job!" << endl;
    }

    return 0;
}
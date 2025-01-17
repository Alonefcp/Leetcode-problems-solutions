#include <vector>

using namespace std;

/*
According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state of the board is determined by applying the above rules simultaneously to every cell in the current state of the m x n grid board. In this process, births and deaths occur simultaneously.

Given the current state of the board, update the board to reflect its next state.

Note that you do not need to return anything.

Example 1:

Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]

Example 2:

Input: board = [[1,1],[1,0]]
Output: [[1,1],[1,1]]


Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 25
board[i][j] is 0 or 1.
*/

int getNumberOfNeighbords(const vector<vector<int>>& board, int i, int j)
{
    vector <pair<int, int>>dirs = { make_pair(1,0), make_pair(-1,0), make_pair(0,1), make_pair(0,-1),
    make_pair(1,1), make_pair(-1,-1), make_pair(-1,1), make_pair(1,-1) };

    int neighbords = 0;

    for (const auto& dir : dirs)
    {
        int newDirI = i + dir.first;
        int newDirJ = j + dir.second;

        if (newDirI >= 0 && newDirJ >= 0 && newDirI < board.size() && newDirJ < board[0].size())
        {
            neighbords += board[newDirI][newDirJ];
        }
    }

    return neighbords;
}

void gameOfLife(vector<vector<int>>& board)
{
    vector<vector<int>> boardCopy = board;

    for (size_t i = 0; i < boardCopy.size(); i++)
    {
        for (size_t j = 0; j < boardCopy[0].size(); j++)
        {
            int liveNeighbords = getNumberOfNeighbords(boardCopy, i, j);

            if (boardCopy[i][j] == 1)
            {
                if (liveNeighbords < 2)
                {
                    board[i][j] = 0;
                }
                else if (liveNeighbords == 2 || liveNeighbords == 3)
                {
                    board[i][j] = 1;
                }
                else if (liveNeighbords > 3)
                {
                    board[i][j] = 0;
                }
            }
            else if (boardCopy[i][j] == 0)
            {
                if (liveNeighbords == 3)
                {
                    board[i][j] = 1;
                }
            }
        }
    }
}

int main()
{
    vector<vector<int>> board = { {0,1,0},{0,0,1},{1,1,1},{0,0,0} };
    gameOfLife(board);

    return 0;
}
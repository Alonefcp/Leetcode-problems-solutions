#include <vector>

using namespace std;

/*
You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example 1:

Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.

Example 2:

Input: grid = [[1]]
Output: 4

Example 3:

Input: grid = [[1,0]]
Output: 4

Constraints:

row == grid.length
col == grid[i].length
1 <= row, col <= 100
grid[i][j] is 0 or 1.
There is exactly one island in grid.

*/

int getCellPerimeter(int i, int j, vector<vector<int>>& grid)
{
	int perimeter = 0;
	vector<pair<int, int>> dirs = { make_pair(0,1), make_pair(0,-1), make_pair(1,0), make_pair(-1,0) };

	for (const auto& dir : dirs)
	{
		int nextIPos = i + dir.first;
		int nextJPos = j + dir.second;

		if (nextIPos >= 0 && nextIPos < grid.size() && nextJPos >= 0 && nextJPos < grid[0].size())
		{
			if (grid[nextIPos][nextJPos] == 0)
			{
				++perimeter;
			}
		}
		else
		{
			++perimeter;
		}
	}

	return perimeter;
}

int islandPerimeter(vector<vector<int>>& grid)
{
	int perimeter = 0;

	for (int i = 0; i < grid.size(); ++i)
	{
		for (int j = 0; j < grid[0].size(); ++j)
		{
			if (grid[i][j] == 1)
			{
				perimeter += getCellPerimeter(i, j, grid);
			}
		}
	}

	return perimeter;
}

int main()
{
	vector<vector<int>> grid = { {0, 1, 0, 0},{1, 1, 1, 0},{0, 1, 0, 0},{1, 1, 0, 0} };
	int result = islandPerimeter(grid);

	return 0;
}
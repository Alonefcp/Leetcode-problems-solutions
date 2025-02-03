#include <vector>

using namespace  std;

/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.


Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false


Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
 */


 // O(n+m) solution
bool searchMatrix(vector<vector<int>>& matrix, int target)
{
	int rowToSearch = 0;

	for (int row = 0; row < matrix.size(); ++row)
	{
		int lastRowIndex = matrix[row].size() - 1;
		if (target >= matrix[row][0] && target <= matrix[row][lastRowIndex])
		{
			rowToSearch = row;
			break;
		}
	}

	bool found = false;

	for (int col = 0; col < matrix[rowToSearch].size(); ++col)
	{
		if (matrix[rowToSearch][col] == target)
		{
			found = true;
			break;
		}
	}


	return found;
}

int main()
{
	vector<vector<int>> matrix = { {1,3,5,7} ,{10,11,16,20},{23,30,34,60} };
	int target = 3;
	bool result = searchMatrix(matrix, target);

	return 0;
}
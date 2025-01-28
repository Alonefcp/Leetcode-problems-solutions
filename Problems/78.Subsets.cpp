#include <vector>

using namespace  std;

/*
Given an integer array nums of unique elements, return all possible
subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:

Input: nums = [0]
Output: [[],[0]]


Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
 */

void backtrack(int start, vector<int>& nums, vector<int>& path, vector<vector<int>>& result)
{
	result.push_back(path);

	for (int i = start; i < nums.size(); ++i)
	{
		path.push_back(nums[i]);

		backtrack(i + 1, nums, path, result);

		path.pop_back();
	}
}

vector<vector<int>> subsets(vector<int>& nums)
{
	vector<int> path = vector<int>();
	vector<vector<int>> result = vector<vector<int>>();

	backtrack(0, nums, path, result);

	return result;
}

int main()
{
	vector<int> nums = { 1,2,3 };

	vector<vector<int>> result = subsets(nums);

	return 0;
}
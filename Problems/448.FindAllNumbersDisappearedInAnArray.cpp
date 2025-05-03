#include <vector>
#include <unordered_set>
using namespace std;

/*
Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]

Example 2:

Input: nums = [1,1]
Output: [2]

Constraints:

n == nums.length
1 <= n <= 105
1 <= nums[i] <= n


Follow up: Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
 */

vector<int> findDisappearedNumbers(vector<int>& nums) {

	unordered_set<int> numbers(nums.begin(), nums.end());

	vector<int> disappearNums = vector<int>();

	for (int i = 1; i <= nums.size(); ++i)
	{
		if (numbers.find(i) == numbers.end())
		{
			disappearNums.emplace_back(i);
		}
	}

	return disappearNums;
}

int main()
{
	vector<int> nums = { 4, 3, 2, 7, 8, 2, 3, 1 };
	vector<int> result = findDisappearedNumbers(nums);

	return 0;
}
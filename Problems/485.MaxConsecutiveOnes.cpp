#include <vector>

using namespace std;

/*
Given a binary array nums, return the maximum number of consecutive 1's in the array.

Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.

Example 2:

Input: nums = [1,0,1,1,0,1]
Output: 2

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
 */

int findMaxConsecutiveOnes(vector<int>& nums)
{
	int maxCounter = -1;
	int counter = 0;

	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] == 1)
		{
			++counter;
		}
		else
		{
			maxCounter = max(maxCounter, counter);
			counter = 0;
		}
	}

	//Check if last consecutive group of 1s is the max
	maxCounter = max(maxCounter, counter);

	return maxCounter;
}

int main()
{
	vector<int> nums = { 1, 1, 0, 1, 1, 1 };
	int result = findMaxConsecutiveOnes(nums);

	return 0;
}
#include <vector>

using namespace  std;

/*
 An array is considered special if every pair of its adjacent elements contains two numbers with different parity.

You are given an array of integers nums. Return true if nums is a special array, otherwise, return false.


Example 1:

Input: nums = [1]

Output: true

Explanation:

There is only one element. So the answer is true.


Example 2:

Input: nums = [2,1,4]

Output: true

Explanation:

There is only two pairs: (2,1) and (1,4), and both of them contain numbers with different parity. So the answer is true.


Example 3:

Input: nums = [4,3,1,6]

Output: false

Explanation:

nums[1] and nums[2] are both odd. So the answer is false.



Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
 */


 //Two numbers are "of the same parity" if, when divided by 2, they have the same remainder.

bool isArraySpecial(vector<int>& nums)
{
	bool haveDifferentParity = true;

	for (int i = 1; i < nums.size(); ++i)
	{
		if (nums[i] % 2 == nums[i - 1] % 2)
		{
			haveDifferentParity = false;
		}
	}

	return haveDifferentParity;
}

int main()
{
	vector<int> nums = { 2,1,4 };

	bool result = isArraySpecial(nums);

	return 0;
}
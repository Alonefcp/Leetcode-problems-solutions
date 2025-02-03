#include <vector>
#include <unordered_set>

using namespace std;

/*
You are given an array of integers nums. Return the length of the longest
subarray of nums which is either strictly increasing or strictly decreasing.


Example 1:

Input: nums = [1,4,3,3,2]

Output: 2

Explanation:

The strictly increasing subarrays of nums are [1], [2], [3], [3], [4], and [1,4].

The strictly decreasing subarrays of nums are [1], [2], [3], [3], [4], [3,2], and [4,3].

Hence, we return 2.


Example 2:

Input: nums = [3,3,3,3]

Output: 1

Explanation:

The strictly increasing subarrays of nums are [3], [3], [3], and [3].

The strictly decreasing subarrays of nums are [3], [3], [3], and [3].

Hence, we return 1.


Example 3:

Input: nums = [3,2,1]

Output: 3

Explanation:

The strictly increasing subarrays of nums are [3], [2], and [1].

The strictly decreasing subarrays of nums are [3], [2], [1], [3,2], [2,1], and [3,2,1].

Hence, we return 3.


Constraints:

1 <= nums.length <= 50
1 <= nums[i] <= 50
 */

int longestMonotonicSubarray(vector<int>& nums)
{
	int maxLength = 1;

	unordered_set<int> asc;
	unordered_set<int> des;

	int maxDesLength = 1;
	int maxAscLength = 1;

	for (int i = 1; i < nums.size(); ++i)
	{
		if (nums[i - 1] < nums[i])
		{
			asc.insert(nums[i - 1]);
			asc.insert(nums[i]);

			if (des.size() > maxDesLength)
			{
				maxDesLength = des.size();
			}

			des.clear();
		}
		else if (nums[i - 1] > nums[i])
		{
			des.insert(nums[i - 1]);
			des.insert(nums[i]);

			if (asc.size() > maxAscLength)
			{
				maxAscLength = asc.size();
			}

			asc.clear();
		}
		else
		{
			if (des.size() > maxDesLength)
			{
				maxDesLength = des.size();
			}

			des.clear();

			if (asc.size() > maxAscLength)
			{
				maxAscLength = asc.size();
			}

			asc.clear();
		}
	}

	if (des.size() > maxDesLength)
	{
		maxDesLength = des.size();
	}

	des.clear();

	if (asc.size() > maxAscLength)
	{
		maxAscLength = asc.size();
	}

	asc.clear();

	maxLength = maxDesLength > maxAscLength ? maxDesLength : maxAscLength;

	return maxLength;
}

int main()
{
	vector<int> nums = { 1,4,3,3,2 };
	int result = longestMonotonicSubarray(nums);

	return 0;
}
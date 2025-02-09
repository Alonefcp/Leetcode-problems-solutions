#include <unordered_set>
#include <vector>
using namespace std;

/*
Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.

Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.

Example 1:

Input: nums1 = [1,2,3], nums2 = [2,4]
Output: 2
Explanation: The smallest element common to both arrays is 2, so we return 2.

Example 2:

Input: nums1 = [1,2,3,6], nums2 = [2,3,4,5]
Output: 2
Explanation: There are two common elements in the array 2 and 3 out of which 2 is the smallest, so 2 is returned.


Constraints:

1 <= nums1.length, nums2.length <= 105
1 <= nums1[i], nums2[j] <= 109
Both nums1 and nums2 are sorted in non-decreasing order.
 */

int getCommon(vector<int>& nums1, vector<int>& nums2)
{
	unordered_set<int> set1(nums1.begin(), nums1.end());

	int minCommonValue = numeric_limits<int>::max();

	for (int n : nums2)
	{
		if (set1.count(n))
		{
			if (n < minCommonValue)
			{
				minCommonValue = n;
			}
		}
	}

	return minCommonValue == numeric_limits<int>::max() ? -1 : minCommonValue;
}

int main()
{
	vector<int> nums1 = { 1,2,3 };
	vector<int> nums2 = { 2,4 };
	int result = getCommon(nums1, nums2);

	return 0;
}
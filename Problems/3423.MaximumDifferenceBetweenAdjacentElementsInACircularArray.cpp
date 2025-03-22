#include <vector>

using namespace std;

/*
Given a circular array nums, find the maximum absolute difference between adjacent elements.

Note: In a circular array, the first and last elements are adjacent.



Example 1:

Input: nums = [1,2,4]

Output: 3

Explanation:

Because nums is circular, nums[0] and nums[2] are adjacent. They have the maximum absolute difference of |4 - 1| = 3.

Example 2:

Input: nums = [-5,-10,-5]

Output: 5

Explanation:

The adjacent elements nums[0] and nums[1] have the maximum absolute difference of |-5 - (-10)| = 5.


Constraints:

2 <= nums.length <= 100
-100 <= nums[i] <= 100

*/

int maxAdjacentDistance(vector<int>& nums)
{
    int maxDiff = abs(nums[nums.size() - 1] - nums[0]);

    for (int i = 1; i < nums.size(); ++i)
    {
        int diff = abs(nums[i - 1] - nums[i]);
        maxDiff = max(maxDiff, diff);
    }

    return maxDiff;
}

int main()
{
    vector<int> nums = { 1,2,4 };
    int result = maxAdjacentDistance(nums);

    return 0;
}
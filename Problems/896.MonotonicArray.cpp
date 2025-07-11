#include <vector>
#include <algorithm>

using namespace std;

/*
An array is monotonic if it is either monotone increasing or monotone decreasing.

An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].

Given an integer array nums, return true if the given array is monotonic, or false otherwise.

Example 1:

Input: nums = [1,2,2,3]
Output: true

Example 2:

Input: nums = [6,5,4,4]
Output: true

Example 3:

Input: nums = [1,3,2]
Output: false

Constraints:

1 <= nums.length <= 105
-105 <= nums[i] <= 105
*/

bool isMonotoneDecreasing(const vector<int>& nums)  //for all i <= j, nums[i] >= nums[j]
{
    int prev = nums[0];
    for (int i = 1; i < nums.size(); ++i)
    {
        if (prev < nums[i])
        {
            return false;
        }

        prev = nums[i];
    }

    return true;
}

bool isMonotoneIncreasing(const vector<int>& nums) // for all i <= j, nums[i] <= nums[j]
{
    int prev = nums[0];
    for (int i = 1; i < nums.size(); ++i)
    {
        if (prev > nums[i])
        {
            return false;
        }

        prev = nums[i];
    }

    return true;
}

bool isMonotonic(vector<int>& nums)
{
    return isMonotoneDecreasing(nums) || isMonotoneIncreasing(nums);
}

int main()
{
    vector<int> nums = { 1,2,2,3 };
    bool result = isMonotonic(nums);

    return 0;
}
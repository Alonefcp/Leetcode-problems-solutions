
#include <vector>

using namespace std;

/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.


Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:

Input: nums = [], target = 0
Output: [-1,-1]


Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/

int findFirst(vector<int> nums, int x)
{
    int left = 0, right = nums.size() - 1, first = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == x)
        {
            first = mid;
            right = mid - 1;
        }
        else  if (nums[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return first;
}

int findLast(vector<int> nums, int x)
{
    int left = 0, right = nums.size() - 1, last = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == x)
        {
            last = mid;
            left = mid + 1;
        }
        else if (nums[mid] < x)
        {
            left = mid + 1;
        }
        else
        {

            right = mid - 1;
        }
    }

    return last;
}

vector<int> searchRange(vector<int>& nums, int target)
{
    return { findFirst(nums,target), findLast(nums,target) };
}

int main()
{
    vector<int> nums = { 5, 7, 7, 8, 8, 10 };
    int target = 8;
    vector<int> result = searchRange(nums, target);

    return 0;
}
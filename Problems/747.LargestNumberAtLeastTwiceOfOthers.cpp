#include <vector>
using namespace std;

/*
You are given an integer array nums where the largest integer is unique.
Determine whether the largest element in the array is at least twice as much as every other number in the array. If it is, return the index of the largest element, or return -1 otherwise.

Example 1:

Input: nums = [3,6,1,0]
Output: 1
Explanation: 6 is the largest integer.
For every other number in the array x, 6 is at least twice as big as x.
The index of value 6 is 1, so we return 1.

Example 2:

Input: nums = [1,2,3,4]
Output: -1
Explanation: 4 is less than twice the value of 3, so we return -1.

Constraints:

2 <= nums.length <= 50
0 <= nums[i] <= 100
The largest element in nums is unique.
*/

int dominantIndex(vector<int>& nums) {

    auto it = max_element(nums.begin(), nums.end());
    int largestNumberIndex = distance(nums.begin(), it);
    int largestNumber = *it;

    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] != largestNumber && largestNumber < 2 * nums[i])
        {
            return -1;
        }
    }

    return largestNumberIndex;
}

int main()
{
    vector<int> nums = { 3, 6, 1, 0 };
    int result = dominantIndex(nums);

    return 0;
}
#include <vector>
#include <unordered_map>

using namespace std;
/*
Given an array of integers nums, return the number of good pairs.

A pair (i, j) is called good if nums[i] == nums[j] and i < j.


Example 1:

Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.

Example 2:

Input: nums = [1,1,1,1]
Output: 6
Explanation: Each pair in the array are good.

Example 3:

Input: nums = [1,2,3]
Output: 0

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
*/

int numIdenticalPairs(vector<int>& nums)
{
    unordered_map<int, int> ocurrences = unordered_map<int, int>();

    for (int i = 0; i < nums.size(); ++i)
    {
        ++ocurrences[nums[i]];
    }

    int nPairs = 0;
    for (const auto& pair : ocurrences)
    {
        nPairs += pair.second * (pair.second - 1) / 2;
    }

    return nPairs;
}

int main()
{
    vector<int> nums = { 1, 2, 3, 1, 1, 3 };

    int result = numIdenticalPairs(nums);

    return 0;
}
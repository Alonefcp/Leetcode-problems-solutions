#include <unordered_map>
#include <vector>

using namespace std;

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.



Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]


Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
*/


vector<int> twoSum(vector<int>& nums, int target)
{

    /*
        Cuadratic solution

    for(int i = 0; i<nums.size(); ++i)
    {
        for(int j = i+1; j<nums.size(); ++j)
        {
            if(nums[i] + nums[j] == target)
            {
                return {i,j};
            }
        }
    }
    */

    std::unordered_map<int, int> complements = unordered_map<int, int>();
    for (int i = 0; i < nums.size(); ++i)
    {
        int complement = target - nums[i];
        if (complements.find(complement) != complements.end()) // exists
        {
            return { i, complements[complement] };
        }
        else
        {
            complements[nums[i]] = i;
        }

    }

    return {};

}

int main()
{
    vector<int> nums = { 2,7,11,15 };
    int target = 9;
    vector<int> result = twoSum(nums, target);


    return 0;
}
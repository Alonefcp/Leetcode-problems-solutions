#include <vector>
#include <algorithm>

using namespace std;

/*
You are given an integer array nums. In one operation, you can add or subtract 1 from any element of nums.

Return the minimum number of operations to make all elements of nums divisible by 3.

Example 1:

Input: nums = [1,2,3,4]

Output: 3

Explanation:

All array elements can be made divisible by 3 using 3 operations:

Subtract 1 from 1.
Add 1 to 2.
Subtract 1 from 4.
Example 2:

Input: nums = [3,6,9]

Output: 0


Constraints:

1 <= nums.length <= 50
1 <= nums[i] <= 50
*/


/*
A number is divisible by 3 if the remainder when divided by 3 is zero (num % 3 == 0).
For a number with a remainder of 1, you can either subtract 1 or add 2 to make it divisible by 3.
For a number with a remainder of 2, you can either add 1 or subtract 2 to make it divisible by 3.
*/

int minimumOperations(vector<int>& nums)
{
    int minOperations = 0;

    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] % 3 == 1 || nums[i] % 3 == 2)
        {
            minOperations++;
        }
        //minOperations += min(nums[i] % 3, 3 - (nums[i] % 3));
    }

    return minOperations;
}

int main()
{
    vector<int> nums = { 1,2,3,4 };
    int result = minimumOperations(nums);

    return 0;
}
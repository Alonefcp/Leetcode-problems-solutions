#include <vector>

using namespace std;

/*
Given an array of integers nums and an integer k, an element nums[i] is considered good if it is strictly greater than the elements at indices i - k and i + k (if those indices exist). If neither of these indices exists, nums[i] is still considered good.

Return the sum of all the good elements in the array.


Example 1:

Input: nums = [1,3,2,1,5,4], k = 2

Output: 12

Explanation:

The good numbers are nums[1] = 3, nums[4] = 5, and nums[5] = 4 because they are strictly greater than the numbers at indices i - k and i + k.

Example 2:

Input: nums = [2,1], k = 1

Output: 2

Explanation:

The only good number is nums[0] = 2 because it is strictly greater than nums[1].


Constraints:

2 <= nums.length <= 100
1 <= nums[i] <= 1000
1 <= k <= floor(nums.length / 2)
*/

int sumOfGoodNumbers(vector<int>& nums, int k)
{
    int sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (i - k < 0 && i + k >= nums.size()) // i-k and i+k dont exist
        {
            sum += nums[i];
        }
        // i-k or i+k dont exist and the other one exist
        else if (i - k < 0 && nums[i] > nums[i + k] || i + k >= nums.size() && nums[i] > nums[i - k])
        {
            sum += nums[i];
        }
        // i-k and i+k exist and nums[i] is good
        else if (i - k >= 0 && nums[i] > nums[i - k] && i + k < nums.size() && nums[i] > nums[i + k])
        {
            sum += nums[i];
        }
    }

    return sum;
}

int main()
{
    vector<int> nums = { 1, 3, 2, 1, 5, 4 };
    int k = 2;
    int result = sumOfGoodNumbers(nums, k);

    return 0;
}
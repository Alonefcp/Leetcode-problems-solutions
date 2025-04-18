#include <vector>
#include <algorithm>

using namespace std;

/*
You are given an integer array nums. You have to find the maximum sum of a pair of numbers from nums such that the largest digit in both numbers is equal.

For example, 2373 is made up of three distinct digits: 2, 3, and 7, where 7 is the largest among them.

Return the maximum sum or -1 if no such pair exists.


Example 1:

Input: nums = [112,131,411]

Output: -1

Explanation:

Each numbers largest digit in order is [2,3,4].

Example 2:

Input: nums = [2536,1613,3366,162]

Output: 5902

Explanation:

All the numbers have 6 as their largest digit, so the answer is 2536 + 3366 = 5902.

Example 3:

Input: nums = [51,71,17,24,42]

Output: 88

Explanation:

Each number's largest digit in order is [5,7,7,4,4].

So we have only two possible pairs, 71 + 17 = 88 and 24 + 42 = 66.


Constraints:

2 <= nums.length <= 100
1 <= nums[i] <= 104
*/

int getHighestDigit(int number)
{
    int maxDigit = -1;
    while (number > 0)
    {
        int currentDigit = number % 10;
        number /= 10;

        if (currentDigit > maxDigit)
        {
            maxDigit = currentDigit;
        }
    }

    return maxDigit;
}

int findNumberWithSameMaxDigit(const vector<int>& nums, int currentNumberIndex, int maxDigit)
{
    for (int i = currentNumberIndex + 1; i < nums.size(); ++i)
    {
        int currentMaxDigit = getHighestDigit(nums[i]);

        if (currentMaxDigit == maxDigit)
        {
            return nums[i];
        }
    }

    return -1;
}

int maxSum(vector<int>& nums)
{
    sort(nums.begin(), nums.end(), greater<int>());

    int currentNumberIndex = 0;
    int maxSum = -1;
    while (currentNumberIndex < nums.size())
    {
        int maxNumber = nums[currentNumberIndex];
        int maxDigit = getHighestDigit(maxNumber);

        int secondMaxNumber = findNumberWithSameMaxDigit(nums, currentNumberIndex, maxDigit);
        if (secondMaxNumber == -1)
        {
            ++currentNumberIndex;
        }
        else if (maxNumber + secondMaxNumber > maxSum)
        {
            maxSum = maxNumber + secondMaxNumber;
            ++currentNumberIndex;
        }
        else
        {
            ++currentNumberIndex;
        }
    }

    return maxSum;
}

int main()
{
    vector<int> nums = { 84,91,18,59,27,9,81,33,17,58 };
    int result = maxSum(nums);

    return 0;
}
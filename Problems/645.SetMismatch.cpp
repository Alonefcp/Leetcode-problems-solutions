#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.
You are given an integer array nums representing the data status of this set after the error.
Find the number that occurs twice and the number that is missing and return them in the form of an array.

Example 1:

Input: nums = [1,2,2,4]
Output: [2,3]

Example 2:

Input: nums = [1,1]
Output: [1,2]

Constraints:

2 <= nums.length <= 104
1 <= nums[i] <= 104
*/

/*
vector<int> findErrorNums(vector<int>& nums) {

    unordered_map<int, int> ocurrences = unordered_map<int, int>();
    sort(nums.begin(),nums.end());

    int repeatedNumber = 1;
    int missingNumber = 1;
    for (int n : nums)
    {
        ocurrences[n]++;

        if (ocurrences[n] > 1)
        {
            repeatedNumber = n;
        }

        if (missingNumber == n)
        {
            ++missingNumber;
        }
    }

    return { repeatedNumber, missingNumber };
}
*/
vector<int> findErrorNums(vector<int>& nums) {
    int duplicate = -1, missing = -1;

    for (int x : nums)
    {
        int idx = abs(x) - 1;
        if (nums[idx] < 0)
        {
            duplicate = abs(x); // seen before -> duplicate
        }
        else {
            nums[idx] *= -1; // mark visited
        }
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0) // never visited
        {
            missing = i + 1;
            break;
        }
    }

    return { duplicate, missing };
}


int main()
{
    vector<int> nums = { 1, 2, 2, 4 };
    vector<int> result = findErrorNums(nums);

    return 0;
}
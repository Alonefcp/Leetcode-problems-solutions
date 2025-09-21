#include <vector>
using namespace std;

/*
Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].
Return the array in the form [x1,y1,x2,y2,...,xn,yn].

Example 1:

Input: nums = [2,5,1,3,4,7], n = 3
Output: [2,3,5,4,1,7]
Explanation: Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is [2,3,5,4,1,7].

Example 2:

Input: nums = [1,2,3,4,4,3,2,1], n = 4
Output: [1,4,2,3,3,2,4,1]

Example 3:

Input: nums = [1,1,2,2], n = 2
Output: [1,2,1,2]

Constraints:

1 <= n <= 500
nums.length == 2n
1 <= nums[i] <= 10^3
*/

/*
vector<int> shuffle(vector<int>& nums, int n) {

    vector<int> firstHalf = vector<int>();
    vector<int> secondHalf = vector<int>();

    for (int i = 0; i < n; ++i)
    {
        firstHalf.push_back(nums[i]);
    }

    for (int i = n; i < 2*n; ++i)
    {
        secondHalf.push_back(nums[i]);
    }

    vector<int> shuffleNums = vector<int>();
    for (int i = 0; i < n; ++i)
    {
        shuffleNums.push_back(firstHalf[i]);
        shuffleNums.push_back(secondHalf[i]);
    }

    return shuffleNums;
}
*/

vector<int> shuffle(vector<int>& nums, int n) {

    vector<int> shuffleNums = vector<int>();
    shuffleNums.reserve(2 * n);

    for (int i = 0; i < n; ++i)
    {
        shuffleNums.push_back(nums[i]);
        shuffleNums.push_back(nums[i + n]);
    }

    return shuffleNums;
}

int main()
{
    vector<int> nums = { 2, 5, 1, 3, 4, 7 };
    int n = 3;

    vector<int> reusult = shuffle(nums, n);

    return 0;
}
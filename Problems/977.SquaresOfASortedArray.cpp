#include <vector>
#include<algorithm>

using namespace std;

/*
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]


Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.


Follow up: Squaring each element and sorting the new array is very trivial, could you find an O(n) solution using a different approach?
*/

vector<int> sortedSquares(vector<int>& nums)
{
    vector<int> squares = vector<int>();

    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        if (abs(nums[left]) > abs(nums[right]))
        {
            squares.push_back(pow(nums[left], 2));

            ++left;
        }
        else
        {
            squares.push_back(pow(nums[right], 2));

            --right;
        }
    }

    reverse(squares.begin(), squares.end());

    return squares;
}

//vector<int> sortedSquares(vector<int>& nums)
//{
//    vector<int> squares = vector<int>();
//
//    for (int n : nums)
//    {
//        squares.push_back(pow(n, 2));
//    }
//
//    sort(squares.begin(), squares.end());
//
//    return squares;
//}



int main()
{
    vector<int> nums = { -4,-1,0,3,10 };

    vector<int> result = sortedSquares(nums);

    return 0;
}
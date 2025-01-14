#include <vector>

using namespace std;

/*Given an integer array nums, handle multiple queries of the following type:

Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).


Example 1:

Input
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
Output
[null, 1, -1, -3]

Explanation
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3


Constraints:

1 <= nums.length <= 104
-105 <= nums[i] <= 105
0 <= left <= right < nums.length
At most 104 calls will be made to sumRange.
*/

class NumArray
{
public:

    NumArray(vector<int>& nums)/*: numbers(nums)*/
    {

        numbers = vector<int>();
        numbers.push_back(nums[0]);

        for (int i = 1; i < nums.size(); ++i)
        {
            numbers.push_back(nums[i] + numbers[i - 1]);
        }
    }

    int sumRange(int left, int right)
    {

        if (left == 0) return numbers[right];
        return numbers[right] - numbers[left - 1];

        /*  int sum = 0;

          for (int i = left; i <= right; ++i)
          {
              sum += numbers[i];
          }

          return sum;*/
    }

private:
    vector<int> numbers;
};


int main()
{
    vector<int> nums = { -2,0,3,-5,2,-1 };
    NumArray numArray = NumArray(nums);
    int result = numArray.sumRange(0, 2);
    return 0;
}
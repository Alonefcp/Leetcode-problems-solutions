#include<algorithm>
#include <vector>
#include <string>

using namespace std;

/*
You are given an integer array nums containing positive integers. We define a function encrypt such that encrypt(x) replaces every digit in x with the largest digit in x. For example, encrypt(523) = 555 and encrypt(213) = 333.

Return the sum of encrypted elements.


Example 1:

Input: nums = [1,2,3]

Output: 6

Explanation: The encrypted elements are [1,2,3]. The sum of encrypted elements is 1 + 2 + 3 == 6.

Example 2:

Input: nums = [10,21,31]

Output: 66

Explanation: The encrypted elements are [11,22,33]. The sum of encrypted elements is 11 + 22 + 33 == 66.


Constraints:

1 <= nums.length <= 50
1 <= nums[i] <= 1000
*/

int encrypt(int num)
{
    int maxDigit = -1;
    int number = num;
    int numberOfDigits = 0;

    //Get max digit
    while (number > 0)
    {
        int currentDigit = number % 10;
        number /= 10;
        ++numberOfDigits;

        if (currentDigit > maxDigit)
        {
            maxDigit = currentDigit;
        }
    }

    //Replace each element with maxDigit
    int encryptedNumber = 0;
    for (int i = 0; i < numberOfDigits; ++i)
    {
        encryptedNumber *= 10;
        encryptedNumber += maxDigit;
    }
    return encryptedNumber;

    /* string strNumber = to_string(num);
     for (int i = 0; i < strNumber.size(); ++i)
     {
         strNumber[i] = '0' + maxDigit;
     }

     return stoi(strNumber); */
}

int sumOfEncryptedInt(vector<int>& nums)
{
    int sum = 0;

    for (int i = 0; i < nums.size(); ++i)
    {
        sum += encrypt(nums[i]);
    }

    return sum;
}

int main()
{
    vector<int> nums = { 10,21,31 };
    int result = sumOfEncryptedInt(nums);

    return 0;
}
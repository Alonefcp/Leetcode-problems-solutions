#include <string> 
#include <vector>

using namespace std;

/*
Given an integer x, return true if x is a palindrome, and false otherwise.

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.


Constraints:

-231 <= x <= 231 - 1*/

bool isPalindrome(int x)
{
    string number = to_string(x);

    int left = 0;
    int right = number.size() - 1;

    while (left < right)
    {
        if (number[left] != number[right])
        {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

int main()
{
    bool result = isPalindrome(121);

    return 0;
}
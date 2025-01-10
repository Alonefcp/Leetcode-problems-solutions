#include <vector>
#include <unordered_set>

using namespace std;

/*
You are given two integers n and t. Return the smallest number greater than or equal to n such that the product of its digits is divisible by t.

Example 1:

Input: n = 10, t = 2

Output: 10

Explanation:

The digit product of 10 is 0, which is divisible by 2, making it the smallest number greater than or equal to 10 that satisfies the condition.

Example 2:

Input: n = 15, t = 3

Output: 16

Explanation:

The digit product of 16 is 6, which is divisible by 3, making it the smallest number greater than or equal to 15 that satisfies the condition.


Constraints:

1 <= n <= 100
1 <= t <= 10
*/

int smallestNumber(int n, int t)
{
    int smallest = n;

    while (true)
    {
        int digitsProduct = 1;
        int num = smallest;

        while (num != 0)
        {
            int digit = num % 10;
            num /= 10;
            digitsProduct *= digit;
        }

        if (digitsProduct % t == 0)
        {
            return smallest;
        }
        else
        {
            ++smallest;
        }

    }

}

int main()
{
    int n = 15;
    int t = 3;
    int result = smallestNumber(n, t);

    return 0;
}
using namespace std;

/*
An integer n is a power of four, if there exists an integer x such that n == 4x.

Example 1:

Input: n = 16
Output: true

Example 2:

Input: n = 5
Output: false

Example 3:

Input: n = 1
Output: true

Constraints:

-231 <= n <= 231 - 1

Follow up: Could you solve it without loops/recursion?
*/

bool isPowerOfFour(int n) {
    return n > 0 && (n & (n - 1)) == 0 && (n & 0x55555555);
}


int main()
{
    int n = 16;
    bool result = isPowerOfFour(n);

    return 0;
}
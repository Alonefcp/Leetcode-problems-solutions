#include <vector>
#include <string>

using namespace std;

/*
Given two integers a and b, return any string s such that:

s has length a + b and contains exactly a 'a' letters, and exactly b 'b' letters,
The substring 'aaa' does not occur in s, and
The substring 'bbb' does not occur in s.

Example 1:

Input: a = 1, b = 2
Output: "abb"
Explanation: "abb", "bab" and "bba" are all correct answers.
Example 2:

Input: a = 4, b = 1
Output: "aabaa"

Constraints:

0 <= a, b <= 100
It is guaranteed such an s exists for the given a and b.
*/

string strWithout3a3b(int a, int b)
{
    string s = "";

    while (a > 0 || b > 0)
    {
        if (a > b)
        {
            if (a >= 2)
            {
                s += "aa";
                a -= 2;
            }
            else
            {
                s += "a";
                --a;
            }

            if (b > 0)
            {
                s += "b";
                --b;
            }
        }
        else if (b > a)
        {
            if (b >= 2)
            {
                s += "bb";
                b -= 2;
            }
            else
            {
                s += "b";
                --b;
            }

            if (a > 0)
            {
                s += "a";
                --a;
            }
        }
        else
        {
            if (a > 0)
            {
                s += "a";
                --a;
            }

            if (b > 0)
            {
                s += "b";
                --b;
            }
        }
    }

    return s;
}

int main()
{
    int a = 1, b = 1;
    string result = strWithout3a3b(a, b);

    return 0;
}
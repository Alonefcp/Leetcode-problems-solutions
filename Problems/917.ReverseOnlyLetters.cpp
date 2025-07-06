#include <vector>
#include <string>

using namespace std;

/*
Given a string s, reverse the string according to the following rules:

All the characters that are not English letters remain in the same position.
All the English letters (lowercase or uppercase) should be reversed.
Return s after reversing it.

Example 1:

Input: s = "ab-cd"
Output: "dc-ba"

Example 2:

Input: s = "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"

Example 3:

Input: s = "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"

Constraints:

1 <= s.length <= 100
s consists of characters with ASCII values in the range [33, 122].
s does not contain '\"' or '\\'.*/

string reverseOnlyLetters(string s)
{
    int left = 0, right = s.size() - 1;

    while (left < right)
    {
        if (isalpha(s[left]) && isalpha(s[right])) //both are letters
        {
            swap(s[left], s[right]);
            ++left;
            --right;
        }
        else if (!isalpha(s[right])) //one is not a letter
        {
            --right;
        }
        else if (!isalpha(s[left])) //one is not a letter
        {
            ++left;
        }
    }

    return s;
}

int main()
{
    string s = "ab-cd";
    string result = reverseOnlyLetters(s);

    return 0;
}
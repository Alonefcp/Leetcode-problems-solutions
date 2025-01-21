#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

/*
Given a string s, find the length of the longest
substring without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

int lengthOfLongestSubstring(string s)
{
    if (s.empty())
    {
        return 0;
    }

    unordered_set<char> subString = unordered_set<char>();

    int maxSize = numeric_limits<int>::min();
    int left = 0; //in which index starts the substring

    for (int i = 0; i < s.size(); ++i)
    {
        while (subString.find(s[i]) != subString.end())
        {
            subString.erase(s[left]);

            ++left;
        }

        subString.insert(s[i]);

        int currentSize = i - left + 1;

        if (currentSize > maxSize)
        {
            maxSize = currentSize;
        }

    }

    return maxSize;
}


int main()
{
    string s = "pwwkew";//"dvdf";
    int result = lengthOfLongestSubstring(s);

    return 0;
}
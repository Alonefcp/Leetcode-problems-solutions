#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

/*
Given a string s, return the length of the longest substring between two equal characters, excluding the two characters. If there is no such substring return -1.
A substring is a contiguous sequence of characters within a string.

Example 1:

Input: s = "aa"
Output: 0
Explanation: The optimal substring here is an empty substring between the two 'a's.

Example 2:

Input: s = "abca"
Output: 2
Explanation: The optimal substring here is "bc".

Example 3:

Input: s = "cbzxy"
Output: -1
Explanation: There are no characters that appear twice in s.

Constraints:

1 <= s.length <= 300
s contains only lowercase English letters.
*/

int maxLengthBetweenEqualCharacters(string s) {

    unordered_map<char, vector<int>> letters = unordered_map<char, vector<int>>();

    for (int i = 0; i < s.size(); ++i)
    {
        letters[s[i]].push_back(i);
    }
    int maxLength = -1;
    for (const auto& p : letters)
    {
        if (letters[p.first].size() < 2)
        {
            continue;
        }

        int length = letters[p.first].back() - letters[p.first].front() - 1;
        maxLength = max(length, maxLength);
    }

    return maxLength;
}

int main()
{
    string s = "abca";
    int result = maxLengthBetweenEqualCharacters(s);

    return 0;
}
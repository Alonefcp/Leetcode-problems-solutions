#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
The power of the string is the maximum length of a non-empty substring that contains only one unique character.

Given a string s, return the power of s.


Example 1:

Input: s = "leetcode"
Output: 2
Explanation: The substring "ee" is of length 2 with the character 'e' only.

Example 2:

Input: s = "abbcccddddeeeeedcba"
Output: 5
Explanation: The substring "eeeee" is of length 5 with the character 'e' only.


Constraints:

1 <= s.length <= 500
s consists of only lowercase English letters.
*/

int getPower(const string& s, int letterIndex)
{
    int power = 1;
    int i = letterIndex;
    while (i + 1 < s.size() && s[i] == s[i + 1])
    {
        ++power;
        ++i;
    }

    return power;
}

int maxPower(string s)
{
    vector<int> power(s.size(), 0);

    int i = 0;
    int powerIndex = 0;
    while (i < s.size())
    {
        power[i] = getPower(s, i);
        ++i;
    }

    return *max_element(power.begin(), power.end());
}

/*
Faster solution

int maxPower(std::string s) {
    int max_power = 1;
    int current_power = 1;

    for (int i = 1; i < s.length(); ++i) {
        if (s[i] == s[i - 1]) {
            current_power++;
            max_power = std::max(max_power, current_power);
        } else {
            current_power = 1;
        }
    }

    return max_power;
}
*/

int main()
{
    string s = "leetcode";
    int result = maxPower(s);

    return 0;
}
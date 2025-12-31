#include <unordered_map>
#include <string>
using namespace std;

/*
Given a string s, return true if s is a good string, or false otherwise.
A string s is good if all the characters that appear in s have the same number of occurrences (i.e., the same frequency).

Example 1:

Input: s = "abacbc"
Output: true
Explanation: The characters that appear in s are 'a', 'b', and 'c'. All characters occur 2 times in s.

Example 2:

Input: s = "aaabb"
Output: false
Explanation: The characters that appear in s are 'a' and 'b'.
'a' occurs 3 times while 'b' occurs 2 times, which is not the same number of times.

Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.

*/

bool areOccurrencesEqual(string s)
{
    unordered_map<char, int> ocurrences = unordered_map<char, int>();
    for (const char& c : s)
    {
        ocurrences[c]++;
    }

    int ocurrencesFirstLetter = ocurrences.begin()->second;

    for (const auto& p : ocurrences)
    {
        if (p.second != ocurrencesFirstLetter)
        {
            return false;
        }
    }

    return true;
}


int main()
{
    string s = "abacbc";
    bool result = areOccurrencesEqual(s);

    return 0;
}
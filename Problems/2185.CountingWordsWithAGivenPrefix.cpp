#include <vector>
#include <string>

using namespace std;

/*
You are given an array of strings words and a string pref.

Return the number of strings in words that contain pref as a prefix.

A prefix of a string s is any leading contiguous substring of s.

Example 1:

Input: words = ["pay","attention","practice","attend"], pref = "at"
Output: 2
Explanation: The 2 strings that contain "at" as a prefix are: "attention" and "attend".
Example 2:

Input: words = ["leetcode","win","loops","success"], pref = "code"
Output: 0
Explanation: There are no strings that contain "code" as a prefix.


Constraints:

1 <= words.length <= 100
1 <= words[i].length, pref.length <= 100
words[i] and pref consist of lowercase English letters.*/

int prefixCount(vector<string>& words, string pref)
{
    int prefixCount = 0;

    for (const string& s : words)
    {
        int j = 0;
        while (j < pref.size() && j < s.size() && pref[j] == s[j])
        {
            ++j;
        }

        if (j >= pref.size())
        {
            ++prefixCount;
        }

    }

    return prefixCount;
}

int main()
{
    vector<string> words = { "pay","attention","practice","attend" };
    string pref = "at";
    int result = prefixCount(words, pref);

    return 0;
}
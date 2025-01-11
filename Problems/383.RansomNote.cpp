#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

/*
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true

Constraints:

1 <= ransomNote.length, magazine.length <= 105
ransomNote and magazine consist of lowercase English letters.
*/

bool canConstruct(string ransomNote, string magazine)
{
    unordered_map<char, int> ransomNoteOcurrences;

    for (char c : ransomNote)
    {
        ransomNoteOcurrences[c]++;
    }

    unordered_map<char, int> magazineOcurrences;

    for (char c : magazine)
    {
        magazineOcurrences[c]++;
    }

    for (const auto& pair : ransomNoteOcurrences)
    {
        if (magazineOcurrences[pair.first] < pair.second)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string ransomNote = "aa";
    string magazine = "aab";
    bool result = canConstruct(ransomNote, magazine);

    return 0;
}
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

Example 1:

Input: words = ["bella","label","roller"]
Output: ["e","l","l"]

Example 2:

Input: words = ["cool","lock","cook"]
Output: ["c","o"]

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] consists of lowercase English letters.
*/

vector<string> commonChars(vector<string>& words)
{
    vector<int> ocurrences(26, numeric_limits<int>::max());

    for (const string& word : words)
    {
        //Compute character frequency for each word
        vector<int> wordOcurrences(26, 0);

        for (const char& c : word)
        {
            wordOcurrences[c - 'a']++;
        }

        //Update common frequence to the min
        for (int i = 0; i < 26; ++i)
        {
            ocurrences[i] = min(ocurrences[i], wordOcurrences[i]);
        }
    }

    vector<string> commomLetters = vector<string>();
    for (int i = 0; i < 26; ++i)
    {
        for (int j = 0; j < ocurrences[i]; ++j)
        {
            commomLetters.push_back(string(1, i + 'a'));
        }
    }

    return commomLetters;
}

int main()
{
    vector<string> words = { "bella", "label", "roller" };
    vector<string> result = commonChars(words);


    return 0;
}
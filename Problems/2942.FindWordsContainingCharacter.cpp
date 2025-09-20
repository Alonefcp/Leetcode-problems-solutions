#include <vector>
#include <string>
using namespace std;

/*
You are given a 0-indexed array of strings words and a character x.
Return an array of indices representing the words that contain the character x.
Note that the returned array may be in any order.

Example 1:

Input: words = ["leet","code"], x = "e"
Output: [0,1]
Explanation: "e" occurs in both words: "leet", and "code". Hence, we return indices 0 and 1.

Example 2:

Input: words = ["abc","bcd","aaaa","cbc"], x = "a"
Output: [0,2]
Explanation: "a" occurs in "abc", and "aaaa". Hence, we return indices 0 and 2.

Example 3:

Input: words = ["abc","bcd","aaaa","cbc"], x = "z"
Output: []
Explanation: "z" does not occur in any of the words. Hence, we return an empty array.

Constraints:

1 <= words.length <= 50
1 <= words[i].length <= 50
x is a lowercase English letter.
words[i] consists only of lowercase English letters.
*/

vector<int> findWordsContaining(vector<string>& words, char x) {

    vector<int> indexes = vector<int>();

    for (int i = 0; i < words.size(); ++i)
    {
        if (words[i].find(x) != string::npos)
        {
            indexes.push_back(i);
        }
    }

    return indexes;
}

int main()
{

    vector<string>words = { "leet", "code" };
    char x = 'e';

    vector<int> result = findWordsContaining(words, x);

    return 0;
}
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

/*
Given an array of strings words, return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.

Note that the strings are case-insensitive, both lowercased and uppercased of the same letter are treated as if they are at the same row.

In the American keyboard:

the first row consists of the characters "qwertyuiop",
the second row consists of the characters "asdfghjkl", and
the third row consists of the characters "zxcvbnm".


Example 1:

Input: words = ["Hello","Alaska","Dad","Peace"]

Output: ["Alaska","Dad"]

Explanation:

Both "a" and "A" are in the 2nd row of the American keyboard due to case insensitivity.

Example 2:

Input: words = ["omk"]

Output: []

Example 3:

Input: words = ["adsdf","sfd"]

Output: ["adsdf","sfd"]


Constraints:

1 <= words.length <= 20
1 <= words[i].length <= 100
words[i] consists of English letters (both lowercase and uppercase).
 */

bool wordCanBeTypedInRow(const string& word, const string& row)
{
	for (const char& c : word)
	{
		if (find(row.begin(), row.end(), tolower(c)) == row.end())
		{
			return false;
		}
	}

	return  true;
}

vector<string> findWords(vector<string>& words)
{
	vector<string> rows = { "qwertyuiop" ,"asdfghjkl", "zxcvbnm" };

	vector<string> wordsInRow = vector<string>();
	for (const string& row : rows)
	{
		for (const string& word : words)
		{
			if (wordCanBeTypedInRow(word, row))
			{
				wordsInRow.emplace_back(word);
			}

		}
	}

	return wordsInRow;
}

int main()
{
	vector<string> words = { "Hello","Alaska","Dad","Peace" };
	vector<string> result = findWords(words);

	return 0;
}
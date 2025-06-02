#include <string>

using namespace std;

/*
We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Given a string word, return true if the usage of capitals in it is right.

Example 1:

Input: word = "USA"
Output: true

Example 2:

Input: word = "FlaG"
Output: false

Constraints:

1 <= word.length <= 100
word consists of lowercase and uppercase English letters.
 */

bool allLetterAreCapital(const string& word)
{
	for (const auto& c : word)
	{
		if (!isupper(c))
		{
			return false;
		}
	}

	return true;
}

bool allLetterAreNotCapital(const string& word)
{
	for (const auto& c : word)
	{
		if (!islower(c))
		{
			return false;
		}
	}

	return true;
}

bool firstLetterIsCapitalAndRestAreNotCapital(const string& word)
{
	bool restOfLetterAreNotCapital = true;

	for (int i = 1; i < word.size(); ++i)
	{
		if (isupper(word[i]))
		{
			restOfLetterAreNotCapital = false;
			break;
		}
	}

	return isupper(word[0]) && restOfLetterAreNotCapital;
}


bool detectCapitalUse(string word)
{
	return allLetterAreCapital(word) || allLetterAreNotCapital(word) || firstLetterIsCapitalAndRestAreNotCapital(word);
}

int main()
{
	string word = "FlaG";
	bool result = detectCapitalUse(word);

	return 0;
}
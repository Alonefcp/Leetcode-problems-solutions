#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

/*
Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.

Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].

For example, swapping at indices 0 and 2 in "abcd" results in "cbad".


Example 1:

Input: s = "ab", goal = "ba"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.

Example 2:

Input: s = "ab", goal = "ab"
Output: false
Explanation: The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.

Example 3:

Input: s = "aa", goal = "aa"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal to goal.


Constraints:

1 <= s.length, goal.length <= 2 * 104
s and goal consist of lowercase letters.
 */

bool buddyStrings(string s, string goal)
{
	if (s.size() != goal.size())
	{
		return false;
	}

	//If are equal, we check for duplicates
	if (s == goal)
	{
		unordered_set<char> charSet(s.begin(), s.end());

		return charSet.size() < goal.size();
	}


	//Get index position which differs
	vector<int> indexDiff = vector<int>();

	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] != goal[i])
		{
			indexDiff.push_back(i);
		}
	}

	return indexDiff.size() == 2 && s[indexDiff[0]] == goal[indexDiff[1]] && s[indexDiff[1]] == goal[indexDiff[0]];
}

int main()
{
	string s = "ab";
	string goal = "ab";
	bool result = buddyStrings(s, goal);

	return 0;
}
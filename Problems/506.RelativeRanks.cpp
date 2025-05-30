#include <algorithm>
#include <string>
#include <vector>

using namespace std;

/*
You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. All the scores are guaranteed to be unique.

The athletes are placed based on their scores, where the 1st place athlete has the highest score, the 2nd place athlete has the 2nd highest score, and so on. The placement of each athlete determines their rank:

The 1st place athlete's rank is "Gold Medal".
The 2nd place athlete's rank is "Silver Medal".
The 3rd place athlete's rank is "Bronze Medal".
For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").
Return an array answer of size n where answer[i] is the rank of the ith athlete.



Example 1:

Input: score = [5,4,3,2,1]
Output: ["Gold Medal","Silver Medal","Bronze Medal","4","5"]
Explanation: The placements are [1st, 2nd, 3rd, 4th, 5th].
Example 2:

Input: score = [10,3,8,9,4]
Output: ["Gold Medal","5","Bronze Medal","Silver Medal","4"]
Explanation: The placements are [1st, 5th, 3rd, 2nd, 4th].



Constraints:

n == score.length
1 <= n <= 104
0 <= score[i] <= 106
All the values in score are unique.
 */

vector<string> findRelativeRanks(vector<int>& score)
{
	vector<pair<int, int>> orderedScores(score.size());
	for (int i = 0; i < orderedScores.size(); ++i)
	{
		orderedScores[i].first = score[i];
		orderedScores[i].second = i;
	}
	sort(orderedScores.begin(), orderedScores.end(),
		[](const pair<int, int>& a, const pair<int, int>& b)
		{
			return a.first > b.first;
		});

	vector<string> ranks(score.size());
	for (int i = 0; i < ranks.size(); ++i)
	{
		int index = orderedScores[i].second;
		if (i == 0)
		{
			ranks[index] = "Gold Medal";
		}
		else if (i == 1)
		{
			ranks[index] = "Silver Medal";
		}
		else if (i == 2)
		{
			ranks[index] = "Bronze Medal";
		}
		else
		{
			ranks[index] = to_string(i + 1);
		}
	}
	return ranks;
}

int main()
{
	vector<int> score = { 10,3,8,9,4 };
	vector<string> result = findRelativeRanks(score);

	return 0;
}
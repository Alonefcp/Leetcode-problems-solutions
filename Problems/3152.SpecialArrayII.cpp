#include <vector>

using namespace  std;

/*
 An array is considered special if every pair of its adjacent elements contains two numbers with different parity.

You are given an array of integer nums and a 2D integer matrix queries, where for queries[i] = [fromi, toi] your task is to check that
subarray
 nums[fromi..toi] is special or not.

Return an array of booleans answer such that answer[i] is true if nums[fromi..toi] is special.


Example 1:

Input: nums = [3,4,1,2,6], queries = [[0,4]]

Output: [false]

Explanation:

The subarray is [3,4,1,2,6]. 2 and 6 are both even.


Example 2:

Input: nums = [4,3,1,6], queries = [[0,2],[2,3]]

Output: [false,true]

Explanation:

The subarray is [4,3,1]. 3 and 1 are both odd. So the answer to this query is false.
The subarray is [1,6]. There is only one pair: (1,6) and it contains numbers with different parity. So the answer to this query is true.


Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105
1 <= queries.length <= 105
queries[i].length == 2
0 <= queries[i][0] <= queries[i][1] <= nums.length - 1
 */


 //OTHER SOLUTION ( SLOWER :( )
 /*bool isSubsetSpecial(const vector<int>& nums, int ini, int fin)
 {
	 bool isSpecial = true;

	 for(int i = ini + 1; i <= fin; ++i)
	 {
		 if(nums[i] % 2 == nums[i-1] % 2)
		 {
			 isSpecial = false;
			 break;
		 }
	 }

	 return isSpecial;
 }

 vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries)
 {
	 vector<bool> specialArrays = vector<bool>();

	 for(auto query : queries)
	 {
		 int ini = query[0];
		 int fin = query[1];

		 bool isSpecial = isSubsetSpecial(nums, ini, fin);
		 specialArrays.push_back(isSpecial);

	 }

	 return specialArrays;
 }*/

vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries)
{
	vector<bool> parityCheck = vector<bool>();

	for (int i = 1; i < nums.size(); ++i)
	{
		if (nums[i] % 2 == nums[i - 1] % 2)
		{
			parityCheck.push_back(false);
		}
		else
		{
			parityCheck.push_back(true);
		}
	}

	vector<int> prefixSum = vector<int>(nums.size());

	for (int i = 1; i < prefixSum.size(); ++i)
	{
		prefixSum[i] = prefixSum[i - 1] + parityCheck[i - 1];
	}

	vector<bool> result = vector<bool>();
	for (const auto& query : queries)
	{
		int ini = query[0];
		int fin = query[1];

		int actualPairs = prefixSum[fin] - prefixSum[ini];
		int expectedPairs = fin - ini;

		result.push_back(actualPairs == expectedPairs);
	}

	return result;
}

int main()
{
	vector<int> nums = { 3,4,1,2,6 };
	vector<vector<int>> queries = { {0,4} };
	vector<bool> result = isArraySpecial(nums, queries);

	return 0;
}
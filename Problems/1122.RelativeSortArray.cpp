#include <vector>
#include <map>
#include <unordered_set>

using namespace  std;

/*
 Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.

Example 1:

Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]

Example 2:

Input: arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
Output: [22,28,8,6,17,44]


Constraints:

1 <= arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
All the elements of arr2 are distinct.
Each arr2[i] is in arr1.
 */


vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2)
{
	map<int, int> ocurrences = map<int, int>();

	for (int number : arr1)
	{
		ocurrences[number]++;
	}

	vector<int> result = vector<int>();


	//Add numbers of arr2
	for (int number : arr2)
	{
		while (ocurrences[number] > 0)
		{
			result.push_back(number);

			--ocurrences[number];
		}
	}

	//Add numbers that are not in arr2
	for (auto& pair : ocurrences)
	{
		if (pair.second > 0)
		{
			while (pair.second > 0)
			{
				result.push_back(pair.first);

				--pair.second;
			}
		}
	}

	return result;
}

// OTHER SOLUTION

//vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2)
//{
//	map<int, int> ocurrences = map<int, int>();
//
//	for(int number : arr1)
//	{
//		ocurrences[number]++;
//	}
//
//	unordered_set<int> arr2Numbers(arr2.begin(), arr2.end());
//
//	vector<int> result = vector<int>();
//
//	for(int number : arr2)
//	{
//		for(int i = 0; i < ocurrences[number]; ++i)
//		{
//			result.push_back(number);
//		}
//	}
//
//	for (const auto& pair : ocurrences)
//	{
//		if (!arr2Numbers.count(pair.first))
//		{
//			for (int i = 0; i < pair.second; ++i)
//			{
//				result.push_back(pair.first);
//			}
//		}
//	}
//
//	return result;
//}


int main()
{
	vector<int> arr1 = { 2,3,1,3,2,4,6,7,9,2,19 };
	vector<int> arr2 = { 2,1,4,3,9,6 };
	vector<int> result = relativeSortArray(arr1, arr2);

	return 0;
}
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

/*
Given two arrays of strings list1 and list2, find the common strings with the least index sum.

A common string is a string that appeared in both list1 and list2.

A common string with the least index sum is a common string such that if it appeared at list1[i] and list2[j] then i + j should be the minimum value among all the other common strings.

Return all the common strings with the least index sum. Return the answer in any order.


Example 1:

Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"]
Output: ["Shogun"]
Explanation: The only common string is "Shogun".
Example 2:

Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["KFC","Shogun","Burger King"]
Output: ["Shogun"]
Explanation: The common string with the least index sum is "Shogun" with index sum = (0 + 1) = 1.
Example 3:

Input: list1 = ["happy","sad","good"], list2 = ["sad","happy","good"]
Output: ["sad","happy"]
Explanation: There are three common strings:
"happy" with index sum = (0 + 1) = 1.
"sad" with index sum = (1 + 0) = 1.
"good" with index sum = (2 + 2) = 4.
The strings with the least index sum are "sad" and "happy".


Constraints:

1 <= list1.length, list2.length <= 1000
1 <= list1[i].length, list2[i].length <= 30
list1[i] and list2[i] consist of spaces ' ' and English letters.
All the strings of list1 are unique.
All the strings of list2 are unique.
There is at least a common string between list1 and list2.
*/

vector<string> findRestaurant(vector<string>& list1, vector<string>& list2)
{
    unordered_map<string, int> list1Index = unordered_map<string, int>();
    int minSum = numeric_limits<int>::max();
    vector<string> wordsWithMinSum = vector<string>();


    for (int i = 0; i < list1.size(); ++i)
    {
        list1Index[list1[i]] = i;
    }

    for (int i = 0; i < list2.size(); ++i)
    {
        if (list1Index.find(list2[i]) != list1Index.end())
        {
            int indexSum = i + list1Index[list2[i]];

            if (indexSum < minSum)
            {
                minSum = indexSum;
                wordsWithMinSum = { list2[i] };
            }
            else if (indexSum == minSum)
            {
                wordsWithMinSum.push_back(list2[i]);
            }

        }
    }

    return wordsWithMinSum;

    // Other solution
    /*unordered_map<string, int> wordsMinSum = unordered_map<string, int>();

    int minSum = numeric_limits<int>::max();

    for (size_t i = 0; i < list1.size(); ++i)
    {
        for (size_t j = 0; j < list2.size(); ++j)
        {
            if (list1[i] == list2[j])
            {
                int indexSum = i + j;
                if (indexSum < minSum)
                {
                    minSum = indexSum;
                }

                wordsMinSum[list1[i]] = indexSum;
            }
        }
    }

    vector<string> wordsWithMinSum = vector<string>();

    for (const auto& pair : wordsMinSum)
    {
        if (pair.second == minSum)
        {
            wordsWithMinSum.push_back(pair.first);
        }
    }

    return wordsWithMinSum;*/
}

int main()
{
    vector<string> list1 = { "Shogun","Tapioca Express","Burger King","KFC" };
    vector<string> list2 = { "KFC","Shogun","Burger King" };

    vector<string> result = findRestaurant(list1, list2);

    return 0;
}
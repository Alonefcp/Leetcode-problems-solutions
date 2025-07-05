#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

/*
You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.

Letters are case sensitive, so "a" is considered a different type of stone from "A".


Example 1:

Input: jewels = "aA", stones = "aAAbbbb"
Output: 3

Example 2:

Input: jewels = "z", stones = "ZZ"
Output: 0

Constraints:

1 <= jewels.length, stones.length <= 50
jewels and stones consist of only English letters.
All the characters of jewels are unique.
*/


/*
int numJewelsInStones(string jewels, string stones)
{
    int numJewels = 0;
    for (const char& stone : stones)
    {
        if (find(jewels.begin(), jewels.end(), stone) != jewels.end())
        {
            ++numJewels;
        }
    }

    return numJewels;
}
*/

int numJewelsInStones(string jewels, string stones)
{
    unordered_map<char, int> stonesOcurrences = unordered_map<char, int>();

    for (const char& stone : stones)
    {
        stonesOcurrences[stone]++;
    }
    int numJewels = 0;
    for (const char& jew : jewels)
    {
        numJewels += stonesOcurrences[jew];
    }

    return numJewels;
}

int main()
{
    string jewels = "aA", stones = "aAAbbbb";
    int result = numJewelsInStones(jewels, stones);

    return 0;
}
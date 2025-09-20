#include <vector>
#include <string>
using namespace std;

/*
You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different characters in letters.
Return the smallest character in letters that is lexicographically greater than target. If such a character does not exist, return the first character in letters.


Example 1:

Input: letters = ["c","f","j"], target = "a"
Output: "c"
Explanation: The smallest character that is lexicographically greater than 'a' in letters is 'c'.

Example 2:

Input: letters = ["c","f","j"], target = "c"
Output: "f"
Explanation: The smallest character that is lexicographically greater than 'c' in letters is 'f'.

Example 3:

Input: letters = ["x","x","y","y"], target = "z"
Output: "x"
Explanation: There are no characters in letters that is lexicographically greater than 'z' so we return letters[0].

Constraints:

2 <= letters.length <= 104
letters[i] is a lowercase English letter.
letters is sorted in non-decreasing order.
letters contains at least two different characters.
target is a lowercase English letter.
*/

/*
char nextGreatestLetter(vector<char>& letters, char target) {

    for (const char& c : letters)
    {
        if (c > target)
        {
            return c;
        }
    }

    return letters[0];
}
*/

/*
char nextGreatestLetter(vector<char>& letters, char target) {
    int left = 0, right = letters.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (letters[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    // if left == letters.size(), wrap around to first element
    return letters[left % letters.size()];

*/

char nextGreatestLetter(vector<char>& letters, char target) {

    auto it = upper_bound(letters.begin(), letters.end(), target);
    return it != letters.end() ? *it : letters[0];
}

int main()
{
    vector<char> letters = { 'c', 'f', 'j' };
    char target = 'a';

    char result = nextGreatestLetter(letters, target);

    return 0;
}
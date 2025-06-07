#include <sstream>
#include <string>
#include <vector>

using namespace std;

/*
Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Example 2:

Input: s = "Mr Ding"
Output: "rM gniD"

Constraints:

1 <= s.length <= 5 * 104
s contains printable ASCII characters.
s does not contain any leading or trailing spaces.
There is at least one word in s.
All the words in s are separated by a single space.
 */

string reverseWords(string s) {

    istringstream iss(s);
    string word;

    string reverseString;
    while (iss >> word)
    {
        reverse(word.begin(), word.end());
        reverseString += word + " ";
    }

    reverseString.pop_back(); //remove last space

    return reverseString;
}

int main()
{
    string s = "Let's take LeetCode contest";
    string result = reverseWords(s);

    return 0;
}
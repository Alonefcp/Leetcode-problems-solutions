#include <sstream>
#include <string>
#include <vector>

using namespace std;

/*
Given a string s, return the number of segments in the string.

A segment is defined to be a contiguous sequence of non-space characters.

Example 1:

Input: s = "Hello, my name is John"
Output: 5
Explanation: The five segments are ["Hello,", "my", "name", "is", "John"]

Example 2:

Input: s = "Hello"
Output: 1

Constraints:

0 <= s.length <= 300
s consists of lowercase and uppercase English letters, digits, or one of the following characters "!@#$%^&*()_+-=',.:".
The only space character in s is ' '.
 */

int countSegments(string s)
{
    istringstream iss(s);
    string word;
    vector<string> words;

    while (iss >> word)
    {
        words.push_back(word);
    }

    return static_cast<uint8_t>(words.size());
}


int main()
{
    string s = "Hello, my name is John";
    int result = countSegments(s);
    return 0;
}
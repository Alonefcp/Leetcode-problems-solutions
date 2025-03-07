#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

/*
Given a valid (IPv4) IP address, return a defanged version of that IP address.

A defanged IP address replaces every period "." with "[.]".

Example 1:

Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"

Example 2:

Input: address = "255.100.50.0"
Output: "255[.]100[.]50[.]0"


Constraints:

The given address is a valid IPv4 address.
*/

string defangIPaddr(string address)
{
    string defanged = "";

    for (char& c : address)
    {
        if (c == '.')
        {
            defanged.push_back('[');
            defanged.push_back('.');
            defanged.push_back(']');
        }
        else
        {
            defanged.push_back(c);
        }
    }

    return defanged;
}

int main()
{
    string address = "1.1.1.1";
    string result = defangIPaddr(address);

    return 0;
}
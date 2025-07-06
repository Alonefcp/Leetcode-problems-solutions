#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
You are given three arrays of length n that describe the properties of n coupons: code, businessLine, and isActive. The ith coupon has:

- code[i]: a string representing the coupon identifier.
- businessLine[i]: a string denoting the business category of the coupon.
- isActive[i]: a boolean indicating whether the coupon is currently active.
A coupon is considered valid if all of the following conditions hold:

- code[i] is non-empty and consists only of alphanumeric characters (a-z, A-Z, 0-9) and underscores (_).
- businessLine[i] is one of the following four categories: "electronics", "grocery", "pharmacy", "restaurant".
- isActive[i] is true.
Return an array of the codes of all valid coupons, sorted first by their businessLine in the order: "electronics", "grocery", "pharmacy", "restaurant", and then by code in lexicographical (ascending) order within each category.

Example 1:

Input: code = ["SAVE20","","PHARMA5","SAVE@20"], businessLine = ["restaurant","grocery","pharmacy","restaurant"], isActive = [true,true,true,true]

Output: ["PHARMA5","SAVE20"]

Explanation:

First coupon is valid.
Second coupon has empty code (invalid).
Third coupon is valid.
Fourth coupon has special character @ (invalid).

Example 2:

Input: code = ["GROCERY15","ELECTRONICS_50","DISCOUNT10"], businessLine = ["grocery","electronics","invalid"], isActive = [false,true,true]

Output: ["ELECTRONICS_50"]

Explanation:

First coupon is inactive (invalid).
Second coupon is valid.
Third coupon has invalid business line (invalid).


Constraints:

n == code.length == businessLine.length == isActive.length
1 <= n <= 100
0 <= code[i].length, businessLine[i].length <= 100
code[i] and businessLine[i] consist of printable ASCII characters.
isActive[i] is either true or false.
*/

bool hasValidCode(const string& code)
{
    if (code.empty())
    {
        return false;
    }

    for (const auto& c : code)
    {
        if (!isalnum(c) && c != '_')
        {
            return false;
        }
    }

    return true;
}

vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive)
{
    vector<pair<string, vector<string>>> categories = { make_pair("electronics",vector<string>()), make_pair("grocery",vector<string>()), make_pair("pharmacy",vector<string>()), make_pair("restaurant",vector<string>()) };

    for (int i = 0; i < code.size(); ++i)
    {
        auto it = find_if(categories.begin(), categories.end(),
            [&](const pair<string, vector<string>>& category)
            {
                return category.first == businessLine[i];
            });

        if (isActive[i] && it != categories.end() && hasValidCode(code[i]))
        {
            if ((*it).first == "electronics")
            {
                categories[0].second.emplace_back(code[i]);
            }
            else if ((*it).first == "grocery")
            {
                categories[1].second.emplace_back(code[i]);
            }
            else if ((*it).first == "pharmacy")
            {
                categories[2].second.emplace_back(code[i]);
            }
            else if ((*it).first == "restaurant")
            {
                categories[3].second.emplace_back(code[i]);
            }
        }
    }
    vector<string> validCupons = vector<string>();
    for (auto& codes : categories)
    {
        sort(codes.second.begin(), codes.second.end());
        for (const auto& code : codes.second)
        {
            validCupons.emplace_back(code);
        }
    }

    return validCupons;
}


int main()
{
    vector<string> code = { "SAVE20", "", "PHARMA5", "SAVE@20" };
    vector<string> businessLine = { "restaurant", "grocery", "pharmacy", "restaurant" };
    vector<bool> isActive = { true, true, true, true };

    vector<string> result = validateCoupons(code, businessLine, isActive);

    return 0;
}
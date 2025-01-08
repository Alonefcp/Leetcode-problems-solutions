#include <vector>
using namespace std;

/*
* Given an integer n, return any array containing n unique integers such that they add up to 0.

Example 1:

Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].
Example 2:

Input: n = 3
Output: [-1,0,1]
Example 3:

Input: n = 1
Output: [0]
 

Constraints:

1 <= n <= 1000
*/

vector<int> sumZero(int n)
{
    vector<int> nums = vector<int>();

    int iterations = 0;

    if (n % 2 == 0)
    {
        iterations = n / 2;
    }
    else
    {
        iterations = (n - 1) / 2;
        nums.push_back(0);
    }

    for (int i = 1; i <= iterations; ++i)
    {
        nums.push_back(i);
        nums.push_back(-i);
    }

    return nums;
}

int main()
{
    int n = 5;
    vector<int> nums = sumZero(n);

    return 0;
}
#include <vector>
#include <algorithm>
using namespace std;

/*
You are given an array of unique integers salary where salary[i] is the salary of the ith employee.
Return the average salary of employees excluding the minimum and maximum salary. Answers within 10^-5 of the actual answer will be accepted.

Example 1:

Input: salary = [4000,3000,1000,2000]
Output: 2500.00000
Explanation: Minimum salary and maximum salary are 1000 and 4000 respectively.
Average salary excluding minimum and maximum salary is (2000+3000) / 2 = 2500

Example 2:

Input: salary = [1000,2000,3000]
Output: 2000.00000
Explanation: Minimum salary and maximum salary are 1000 and 3000 respectively.
Average salary excluding minimum and maximum salary is (2000) / 1 = 2000

Constraints:

3 <= salary.length <= 100
1000 <= salary[i] <= 106
All the integers of salary are unique.
*/

/*
double average(vector<int>& salary) {

    sort(salary.begin(), salary.end());

    double avr = 0;
    for (int i = 1; i < salary.size() - 1; ++i)
    {
        avr += salary[i];
    }

    return avr / (salary.size() - 2);
}
*/

double average(vector<int>& salary) {

    int maxSalary = numeric_limits<int>::min();
    int minSalary = numeric_limits<int>::max();

    double avr = 0;
    for (int i = 0; i < salary.size(); ++i)
    {
        avr += salary[i];
        maxSalary = max(maxSalary, salary[i]);
        minSalary = min(minSalary, salary[i]);
    }
    avr -= (maxSalary + minSalary);
    return avr / (salary.size() - 2);
}

int main()
{
    vector<int> salary = { 4000, 3000, 1000, 2000 };
    double result = average(salary);

    return 0;
}
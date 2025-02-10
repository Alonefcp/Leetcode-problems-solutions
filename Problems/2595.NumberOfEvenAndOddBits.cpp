#include <string>
#include <vector>
using namespace std;

/*
You are given a positive integer n.

Let even denote the number of even indices in the binary representation of n with value 1.

Let odd denote the number of odd indices in the binary representation of n with value 1.

Note that bits are indexed from right to left in the binary representation of a number.

Return the array [even, odd].


Example 1:

Input: n = 50

Output: [1,2]

Explanation:

The binary representation of 50 is 110010.

It contains 1 on indices 1, 4, and 5.


Example 2:

Input: n = 2

Output: [0,1]

Explanation:

The binary representation of 2 is 10.

It contains 1 only on index 1.



Constraints:

1 <= n <= 1000
 */

string toBinary(int n)
{
	if (n == 0)
	{
		return "0";
	}

	string binary = "";

	while (n > 0)
	{
		binary = to_string(n % 2) + binary;

		n /= 2;
	}

	return binary;
}

vector<int> evenOddBit(int n)
{
	int even = 0;
	int odd = 0;

	string binaryNumber = toBinary(n);
	reverse(binaryNumber.begin(), binaryNumber.end());

	for (int i = 0; i < binaryNumber.size(); ++i)
	{
		if (binaryNumber[i] != '1')
		{
			continue;
		}

		if (i % 2 == 0)
		{
			++even;
		}
		else
		{
			++odd;
		}
	}

	return { even,odd };
}

int main()
{
	int n = 50;

	vector<int> result = evenOddBit(n);

	return 0;
}
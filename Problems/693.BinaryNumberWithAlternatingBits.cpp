#include <string>

using namespace std;

/*
Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

Example 1:

Input: n = 5
Output: true
Explanation: The binary representation of 5 is: 101

Example 2:

Input: n = 7
Output: false
Explanation: The binary representation of 7 is: 111.

Example 3:

Input: n = 11
Output: false
Explanation: The binary representation of 11 is: 1011.

Constraints:

1 <= n <= 231 - 1
 */

string toBinary(int number) {
	if (number == 0) {

		return "0";
	}

	string binary = "";
	while (number > 0) {
		binary = (number % 2 == 0 ? "0" : "1") + binary;
		number /= 2;
	}

	return binary;
}


bool hasAlternatingBits(int n)
{
	string binary = toBinary(n);

	char prev = binary[0];
	for (size_t i = 1; i < binary.size(); ++i)
	{
		if (prev == binary[i])
		{
			return false;
		}
		prev = binary[i];
	}

	return true;
}

int main()
{
	int n = 5;
	bool result = hasAlternatingBits(n);


	return 0;
}
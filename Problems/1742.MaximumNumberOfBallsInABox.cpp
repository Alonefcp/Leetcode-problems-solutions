#include <vector>
#include <unordered_map>

using namespace std;

/*
You are working in a ball factory where you have n balls numbered from lowLimit up to highLimit inclusive (i.e., n == highLimit - lowLimit + 1), and an infinite number of boxes numbered from 1 to infinity.
Your job at this factory is to put each ball in the box with a number equal to the sum of digits of the ball's number. For example, the ball number 321 will be put in the box number 3 + 2 + 1 = 6 and the ball number 10 will be put in the box number 1 + 0 = 1.
Given two integers lowLimit and highLimit, return the number of balls in the box with the most balls.

Example 1:

Input: lowLimit = 1, highLimit = 10
Output: 2
Explanation:
Box Number:  1 2 3 4 5 6 7 8 9 10 11 ...
Ball Count:  2 1 1 1 1 1 1 1 1 0  0  ...
Box 1 has the most number of balls with 2 balls.

Example 2:

Input: lowLimit = 5, highLimit = 15
Output: 2
Explanation:
Box Number:  1 2 3 4 5 6 7 8 9 10 11 ...
Ball Count:  1 1 1 1 2 2 1 1 1 0  0  ...
Boxes 5 and 6 have the most number of balls with 2 balls in each.

Example 3:

Input: lowLimit = 19, highLimit = 28
Output: 2
Explanation:
Box Number:  1 2 3 4 5 6 7 8 9 10 11 12 ...
Ball Count:  0 1 1 1 1 1 1 1 1 2  0  0  ...
Box 10 has the most number of balls with 2 balls.

Constraints:

1 <= lowLimit <= highLimit <= 105
*/

int sumBallDigits(int boxNumber)
{
	int sum = 0;
	while (boxNumber > 0)
	{
		sum += (boxNumber % 10);
		boxNumber /= 10;
	}

	return sum;
}

//With an unorderd_map
//int countBalls(int lowLimit, int highLimit) 
//{
//	unordered_map<int, int> boxes = unordered_map<int, int>(); //box number, number of balls
//
//	int maxBalls = -1;
//
//	for (int i = lowLimit; i <= highLimit; ++i)
//	{
//		int ballDigits = sumBallDigits(i);
//
//		++boxes[ballDigits];
//		if (boxes[ballDigits] > maxBalls)
//		{
//			maxBalls = boxes[ballDigits];
//		}
//	}
//
//	return maxBalls;
//}

int countBalls(int lowLimit, int highLimit)
{

	/*
	The largest possible number in the range is 99999 (up to 5 digits).

	The digit sum of 99999 is: 9+9+9+9+9=45
	So the maximum box number (i.e., sum of digits) is 45.

	Why use size 46?
	We need to index boxes[0] through boxes[45], inclusive — that's 46 elements total.
	*/

	vector<int> boxes(46, 0);

	int maxBalls = -1;

	for (int i = lowLimit; i <= highLimit; ++i)
	{
		int ballDigits = sumBallDigits(i);

		++boxes[ballDigits];
		if (boxes[ballDigits] > maxBalls)
		{
			maxBalls = boxes[ballDigits];
		}
	}

	return maxBalls;
}

int main()
{
	int lowLimit = 5, highLimit = 15;
	int result = countBalls(lowLimit, highLimit);

	return 0;
}
#include <vector>

using namespace std;

/*
Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

The most significant bit is at the head of the linked list.


Example 1:

Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10

Example 2:

Input: head = [0]
Output: 0


Constraints:

The Linked List is not empty.
Number of nodes will not exceed 30.
Each node's value is either 0 or 1.
*/


struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

};

ListNode* createList(const std::vector<int>& values)
{
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int value : values) {
        ListNode* newNode = new ListNode(value);
        if (!head) {
            head = newNode;
            tail = head;
        }
        else {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    return head;
}

//int getDecimalValue(ListNode* head) 
//{
//    vector<int> binaryNum = vector<int>();
//
//    while (head)
//    {
//        binaryNum.push_back(head->val);
//
//        head = head->next;
//    }
//
//    reverse(binaryNum.begin(), binaryNum.end());
//
//    int result = 0;
//    for (int i = 0; i < binaryNum.size(); ++i)
//    {
//        if (binaryNum[i] == 1)
//        {
//            result += pow(2, i);
//        }
//    }
//
//    return result;
//}

int getDecimalValue(ListNode* head)
{
    int binaryNumber = 0;

    while (head)
    {
        binaryNumber = (binaryNumber << 1) | head->val;

        head = head->next;
    }

    return binaryNumber;
}

int main()
{
    vector<int> nums = { 1,0,0,1,0,0,1,1,1,0,0,0,0,0,0 };

    ListNode* list = createList(nums);

    int result = getDecimalValue(list);

    return 0;
}
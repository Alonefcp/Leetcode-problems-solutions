#include <vector>

using namespace std;

/*
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

Example 1:

Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

Example 2:

Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.

Constraints:

The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

};

ListNode* createList(const std::vector<int>& values) {
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

ListNode* middleNode(ListNode* head)
{
    ListNode* current = head;
    int n = 0;

    while (current)
    {
        n++;
        current = current->next;
    }

    int middle = n / 2 + 1;
    int index = 1;
    current = head;

    while (current && index < middle)
    {
        ++index;
        current = current->next;
    }

    return current;
}

int main()
{
    vector<int> nums = { 1,2,3,4,5,6 };
    ListNode* list = createList(nums);

    ListNode* result = middleNode(list);

    delete list;
    delete result;

    return 0;
}
#include <vector>
using namespace std;

/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]


Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz*/


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

ListNode* removeNthFromEnd(ListNode* head, int n) {

    ListNode* dummy = new ListNode(); // Dummy node to handle edge cases
    dummy->next = head;
    ListNode* first = dummy;
    ListNode* second = dummy;

    // Move the first pointer n + 1 steps ahead
    for (int i = 0; i <= n; ++i) {
        first = first->next;
    }

    // Move both pointers until the first reaches the end
    while (first) {
        first = first->next;
        second = second->next;
    }

    // Remove the nth node
    ListNode* temp = second->next;
    second->next = second->next->next;
    delete temp;

    ListNode* newHead = dummy->next;
    delete dummy;
    return newHead;
}

int main()
{
    int n = 2;
    ListNode* list = createList({ 1,2,3,4,5 });

    list = removeNthFromEnd(list, n);

    delete list;
    return 0;
}
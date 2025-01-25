#include <vector>
#include <algorithm>

using namespace std;

/*
Given the head of a linked list, return the list after sorting it in ascending order.

Example 1:

Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:

Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

Example 3:

Input: head = []
Output: []


Constraints:

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

};

ListNode* createList(const vector<int>& values) {
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

ListNode* sortList(ListNode* head)
{
    vector<int> listVector = vector<int>();

    while (head)
    {
        listVector.push_back(head->val);

        head = head->next;
    }


    sort(listVector.begin(), listVector.end());

    return createList(listVector);
}

int main()
{
    vector<int> nums = { 4,2,1,3 };

    ListNode* list = createList(nums);

    ListNode* result = sortList(list);

    delete result;
    delete list;

    return 0;
}
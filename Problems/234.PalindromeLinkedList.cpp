#include <vector>

using namespace std;

/*
Given the head of a singly linked list, return true if it is a
palindrome or false otherwise.

Example 1:

Input: head = [1,2,2,1]
Output: true

Example 2:

Input: head = [1,2]
Output: false

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
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

bool isPalindrome(ListNode* head)
{
    vector<int> nums = vector<int>();

    while (head)
    {
        nums.push_back(head->val);

        head = head->next;
    }

    int ini = 0;
    int fin = nums.size() - 1;

    while (ini < fin)
    {
        if (nums[ini] != nums[fin])
        {
            return false;
        }


        ++ini;
        --fin;
    }

    return true;
}

int main()
{
    vector<int> nums = { 1,2,2,1 };

    ListNode* listNode = createList(nums);

    bool result = isPalindrome(listNode);

    delete listNode;

    return 0;
}
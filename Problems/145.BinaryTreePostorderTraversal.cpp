#include <vector>

using namespace std;

/*
Given the root of a binary tree, return the postorder traversal of its nodes' values.

Example 1:

Input: root = [1,null,2,3]

Output: [3,2,1]


Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [4,6,7,5,2,9,8,3,1]


Example 3:

Input: root = []

Output: []


Example 4:

Input: root = [1]

Output: [1]


Constraints:

The number of the nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/

//Postorder traversal visits the node in the order: Left -> Right -> Root

//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


void traverse(TreeNode* node, vector<int>& result)
{
    if (node == nullptr)
    {
        return;
    }

    traverse(node->left, result);

    traverse(node->right, result);

    result.push_back(node->val);
}

vector<int> postorderTraversal(TreeNode* root)
{
    vector<int> result = vector<int>();

    traverse(root, result);

    return result;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> result = postorderTraversal(root);

    return 0;
}
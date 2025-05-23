#include <vector>

using namespace std;

/*
Given the root of a binary tree, return the preorder traversal of its nodes' values.


Example 1:

Input: root = [1,null,2,3]

Output: [1,2,3]


Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [1,2,4,5,6,7,3,8,9]


Example 3:

Input: root = []

Output: []

Example 4:

Input: root = [1]

Output: [1]


Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/

//Preorder traversal visits the node in the order : Root->Left->Right

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

    result.push_back(node->val);

    traverse(node->left, result);

    traverse(node->right, result);
}

vector<int> preorderTraversal(TreeNode* root)
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

    vector<int> result = preorderTraversal(root);

    delete root;

    return 0;
}
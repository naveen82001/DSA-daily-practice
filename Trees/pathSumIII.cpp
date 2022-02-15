// Leetcode Q No.437 : Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.
// The path does not need to start or end at the root or a leaf,but it must go downwards(i.e., traveling only from parent nodes to child nodes).

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void check(TreeNode *node, int sum, int &ans, int val)
    {
        if (!node)
            return;

        val += node->val;
        if (sum == val)
            ans++;

        check(node->left, sum, ans, val);
        check(node->right, sum, ans, val);
        val -= node->val;
    }

    void dfs(TreeNode *node, int sum, int &ans)
    {
        if (!node)
            return;

        dfs(node->left, sum, ans);
        check(node, sum, ans, 0);
        dfs(node->right, sum, ans);
    }

    int pathSum(TreeNode *root, int targetSum)
    {
        int ans = 0;
        dfs(root, targetSum, ans);

        return ans;
    }
};

int main()
{

    return 0;
}
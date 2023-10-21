/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void add(TreeNode *root, int k, int l, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (l == k)
        ans.push_back(root->val);
    add(root->left, k, l + 1, ans);
    add(root->right, k, l + 1, ans);
}

int run(TreeNode *root, int target, int k, int l, vector<int> &ans)
{
    if (root == NULL)
        return 0;

    if (root->val == target)
    {
        add(root, k, 0, ans);
        return l;
    }
    else
    {
        int lt = run(root->left, target, k, l + 1, ans);
        int rt = run(root->right, target, k, l + 1, ans);

        //  cout<<root->val<<" "<<rt<<" "<<lt<<" "<<l<<endl;
        if (lt == 0 && rt != 0)
        {
            if (k - (rt - l) == 0)
                ans.push_back(root->val);
            add(root->left, k - (rt - l) - 1, 0, ans);
        }
        if (rt == 0 && lt != 0)
        {
            if (k - (lt - l) == 0)
                ans.push_back(root->val);
            add(root->right, k - (lt - l) - 1, 0, ans);
        }

        return lt + rt;
    }
}

vector<int> Solution::distanceK(TreeNode *A, int B, int C)
{
    vector<int> ans;
    run(A, B, C, 0, ans);
    return ans;
}

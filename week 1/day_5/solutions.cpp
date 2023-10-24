TreeNode *run(vector<int> &A, int l, int r, map<int, int> &mp, int &idx)
{
    if (l > r)
        return NULL;
    TreeNode *root = new TreeNode(A[idx++]);
    root->left = run(A, l, mp[root->val] - 1, mp, idx);
    root->right = run(A, mp[root->val] + 1, r, mp, idx);
    return root;
}

TreeNode *Solution::buildTree(vector<int> &A, vector<int> &B)
{
    map<int, int> mp;
    int idx = 0;
    for (int i = 0; i < B.size(); i++)
    {
        mp[B[i]] = i;
    }
    return run(A, 0, A.size() - 1, mp, idx);
}

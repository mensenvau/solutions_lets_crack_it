int run(TreeNode *A, int B, int C, int &ans)
{
    if (A == NULL)
        return 0;

    int l = run(A->left, B, C, ans);
    int r = run(A->right, B, C, ans);

    int res = l + r;
    if (A->val == B || A->val == C)
        res++;
    if ((res == 2 || (B == C && res == 1)) && ans == -1)
        ans = A->val;

    return res;
}
int Solution::lca(TreeNode *A, int B, int C)
{

    int ans = -1;
    run(A, B, C, ans);

    return ans;
}

// add update

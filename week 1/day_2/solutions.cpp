void run(TreeNode *A, vector<int> &ANS)
{
    if (A == NULL)
        return;

    ANS.push_back(A->val);
    run(A->left, ANS);
    run(A->right, ANS);
}
vector<int> Solution::preorderTraversal(TreeNode *A)
{
    vector<int> ANS;
    run(A, ANS);

    return ANS;
}

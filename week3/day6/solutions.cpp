vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B)
{

    vector<int> ans;
    int l1 = 0;
    int l2 = 0;

    while (l1 < A.size() && l2 < B.size())
    {
        if (A[l1] == B[l2])
        {
            ans.push_back(A[l1]);
            l1++;
            l2++;
        }
        else if (A[l1] < B[l2])
            l1++;
        else
            l2++;
    }

    return ans;
}
// add update
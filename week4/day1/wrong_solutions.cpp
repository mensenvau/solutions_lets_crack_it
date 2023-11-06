void run(vector<int> &A, int idx, vector<int> &arr, vector<vector<int>> &ans)
{

    if (idx == A.size())
    {
        ans.push_back(arr);
    }
    else
    {
        for (int i = 0; i < A.size(); i++)
        {
            arr.push_back(A[i]);
            run(A, i + 1, arr, ans);
            arr.pop_back();
        }
    }
}
vector<vector<int>> Solution::permute(vector<int> &A)
{
    vector<vector<int>> ans;
    vector<int> arr;
    run(A, 0, arr, ans);
    return ans;
}

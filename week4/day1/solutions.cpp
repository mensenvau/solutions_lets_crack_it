vector<vector<int>> Solution::permute(vector<int> &A)
{
    vector<vector<int>> ans;
    vector<int> arr = A;
    sort(arr.begin(), arr.end());
    do
    {
        ans.push_back(arr);
    } while (next_permutation(arr.begin(), arr.end()));
    return ans;
}
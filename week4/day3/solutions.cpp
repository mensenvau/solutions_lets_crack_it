bool isPalindrome(string &s)
{
    int l = 0, r = s.size() - 1;
    while (l < r)
    {
        if (s[l++] != s[r--])
            return false;
    }
    return true;
}
void run(string &s, int l, vector<string> &arr, vector<vector<string>> &ans)
{
    if (s.size() == l)
    {
        ans.push_back(arr);
    }
    else
    {
        string current = "";
        for (int i = l; i < s.size(); i++)
        {
            current.push_back(s[i]);
            if (isPalindrome(current))
            {
                arr.push_back(current);
                run(s, i + 1, arr, ans);
                arr.pop_back();
            }
        }
    }
}
vector<vector<string>> Solution::partition(string s)
{
    vector<string> arr;
    vector<vector<string>> ans;
    int l = 0;
    run(s, l, arr, ans);

    return ans;
}

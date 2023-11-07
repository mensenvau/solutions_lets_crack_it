string def = "";
bool is_possible(vector<pair<int, int>> &res, int x, int y)
{
    for (int i = 0; i < res.size(); i++)
    {
        if (res[i].first == x ||
            res[i].second == y ||
            abs(res[i].first - x) == abs(res[i].second - y))
            return false;
    }
    return true;
}
void run(int n, int count, int i,
         vector<pair<int, int>> &res,
         vector<vector<string>> &ans)
{
    if (n == count)
    {
        vector<string> tmp(n, def);
        for (int i = 0; i < res.size(); i++)
        {
            tmp[res[i].first][res[i].second] = 'Q';
        }
        ans.push_back(tmp);
    }
    else
    {
        for (int j = 0; j < n; j++)
        {
            if (is_possible(res, i, j) == true)
            {
                res.push_back({i, j});
                run(n, count + 1, i + 1, res, ans);
                res.pop_back();
            }
        }
    }
}
vector<vector<string>> Solution::solveNQueens(int n)
{
    vector<pair<int, int>> res;
    vector<vector<string>> ans;
    def = "";
    for (int i = 0; i < n; i++)
        def += '.';
    for (int j = 0; j < n; j++)
    {
        res.push_back({0, j});
        run(n, 1, 1, res, ans);
        res.pop_back();
    }

    return ans;
}

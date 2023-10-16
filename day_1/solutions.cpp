#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

bool check(string &a, string &b)
{
    int count = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
            count++;
    }
    return (count == 1);
}

void run(vector<vector<int>> &mp, vector<int> lt[], int n, int st, int et)
{
    vector<int> ops(n, 100000);
    queue<int> q;
    q.push(st);
    lt[st] = {-1};
    ops[st] = 0;

    while (!q.empty())
    {
        int val = q.front();
        q.pop();
        for (auto item : mp[val])
        {
            if (ops[item] > ops[val] + 1)
            {
                ops[item] = ops[val] + 1;
                q.push(item);
                lt[item].clear();
                lt[item].push_back(val);
            }
            else if (ops[item] == ops[val] + 1)
            {
                lt[item].push_back(val);
            }
        }
    }
}

void searchPath(vector<vector<int>> &P, vector<int> &path, vector<int> lt[], int item)
{
    if (item == -1)
    {
        P.push_back(path);
        return;
    }
    for (auto it : lt[item])
    {
        path.push_back(it);
        searchPath(P, path, lt, it);
        path.pop_back();
    }
}

vector<vector<string>> Solution::findLadders(string start, string end, vector<string> &dict)
{
    vector<vector<string>> ans;
    vector<vector<int>> P;

    if (start == end)
    {
        return {{start}};
    }
    int n = dict.size();

    int st = -1, et = -1;

    for (int i = 0; i < dict.size(); i++)
    {
        if (dict[i] == start)
            st = i;
        if (dict[i] == end)
            et = i;
    }

    if (et == -1)
    {
        dict.insert(dict.end(), end);
        et = n;
        n++;
    }
    if (st == -1)
    {
        dict.insert(dict.begin(), start);
        st = 0;
        et++;
        n++;
    }

    //   cout<<n<<" "<<start<<" "<<end;

    vector<vector<int>> mp(n, vector<int>());

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (check(dict[i], dict[j]))
            {
                mp[i].push_back(j);
                mp[j].push_back(i);
            }

    vector<int> lt[n], path;
    run(mp, lt, n, st, et);
    searchPath(P, path, lt, et);

    // cout<<lt[et].size();

    for (auto u : P)
    {
        vector<string> now;
        for (int i = 0; i < u.size() - 1; i++)
            now.push_back(dict[u[i]]);
        reverse(now.begin(), now.end());
        now.push_back(dict[et]);
        ans.push_back(now);
    }

    //  cout<<ans.size();
    // if(ans.size()==1) return ans[0];
    set<vector<string>> uv(ans.begin(), ans.end());
    vector<vector<string>> ANS(uv.begin(), uv.end());
    return ANS;
}
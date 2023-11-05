int Solution::knight(int A, int B, int C, int D, int E, int F)
{

    int ans = 0, st[A + 1][B + 1] = {0, 0};
    deque<vector<int>> dq;
    dq.push_back({C, D});

    while (!dq.empty())
    {
        vector<vector<int>> tmp;
        while (!dq.empty())
        {
            vector<int> x = dq.front();
            dq.pop_front();

            if (x[0] == E && x[1] == F)
            {
                return ans;
            }
            if (x[0] >= 1 && x[0] <= A && x[1] >= 1 && x[1] <= B && st[x[0]][x[1]] == 0)
            {
                st[x[0]][x[1]] = 1;
                tmp.push_back({x[0] + 1, x[1] + 2});
                tmp.push_back({x[0] + 1, x[1] - 2});
                tmp.push_back({x[0] - 1, x[1] + 2});
                tmp.push_back({x[0] - 1, x[1] - 2});
                tmp.push_back({x[0] + 2, x[1] + 1});
                tmp.push_back({x[0] + 2, x[1] - 1});
                tmp.push_back({x[0] - 2, x[1] + 1});
                tmp.push_back({x[0] - 2, x[1] - 1});
            }
        }

        for (int i = 0; i < tmp.size(); i++)
        {
            dq.push_back(tmp[i]);
        }

        ans++;
    }

    return -1;
}

// add update
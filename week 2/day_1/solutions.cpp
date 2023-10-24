void Solution::rotate(vector<vector<int>> &a)
{

    int n = a.size();

    for (int i = 0; i < n / 2 + n % 2; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            int x = i, y = j, l = 4, c = a[x][y], k, d;
            while (l--)
            {
                d = x;
                x = y;
                y = n - 1 - d;
                k = a[x][y];
                a[x][y] = c;
                c = k;
                //  cout<<i<<" "<<j<<" "<<x<<" "<<y<<"~";
            }
        }
    }
}

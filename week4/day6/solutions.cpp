bool compareChildVector(vector<int> a, vector<int> b)
{
    // if(a[0]==b[0]) return a[1]<b[1];
    return (a[0] < b[0]);
}

int Solution::solve(vector<vector<int>> &A)
{

    priority_queue<int, vector<int>, greater<int>> pq;

    int sum = 0, ans = 0;
    sort(A.begin(), A.end(), compareChildVector);
    for (int i = 0; i < A.size(); i++)
    {
        sum++;
        pq.push(A[i][1]);
        while (!pq.empty() && pq.top() <= A[i][0])
        {
            pq.pop();
            sum--;
        }
        ans = max(ans, sum);
    }

    return ans;
}

/*
 1 18~
 2 11~
 4 15~
 5 13~
 15 29~
 18 23~
 6

 */

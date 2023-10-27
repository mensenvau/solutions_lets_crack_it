struct T
{
    int val, idx;
    bool operator<(const T &p) const
    {
        return this->val > p.val;
    }
};

int Solution::maximumGap(const vector<int> &A)
{

    int ans = 0;
    priority_queue<T> pq;
    for (int i = 0; i < A.size(); i++)
        pq.push({A[i], i});

    int Min = INT_MAX, Max = INT_MIN;
    while (!pq.empty())
    {
        T val = pq.top();
        Min = min(Min, val.idx);
        ans = max(ans, val.idx - Min);
        pq.pop();
    }

    return ans;
}

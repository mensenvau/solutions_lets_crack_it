struct T
{
    int a, b;
    T(int a, int b)
        : a(a), b(b)
    {
    }
    bool operator<(const T &p) const
    {
        return this->a < p.a;
    }
};

int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C)
{

    priority_queue<T> pq;

    int ans = INT_MAX;
    int i = A.size() - 1;
    int j = B.size() - 1;
    int k = C.size() - 1;
    pq.push({A[i], 0});
    pq.push({B[j], 1});
    pq.push({C[k], 2});

    while (!pq.empty() && i >= 0 && j >= 0 && k >= 0)
    {

        int sum = max({abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])});

        T tr = pq.top();
        pq.pop();

        if (tr.b == 0)
        {
            i--;
            pq.push({A[i], 0});
        }
        else if (tr.b == 1)
        {
            j--;
            pq.push({B[j], 1});
        }
        else
        {
            k--;
            pq.push({C[k], 2});
        }

        ans = min(ans, sum);
    }

    return ans;
}

// add update
int Solution::maxArea(vector<int> &A)
{

    int l = 0, r = A.size() - 1;
    int sum = 0, ans = 0;

    while (l < r)
    {
        sum = min(A[l], A[r]) * (r - l);
        ans = max(ans, sum);

        if (A[l] < A[r])
        {
            l++;
        }
        else
        {
            r--;
        }
    }

    return ans;
}

// add update

// add
bool compareChildVector(vector<int> a, vector<int> b)
{
    return (a[1] < b[1]);
}
int Solution::solve(vector<vector<int>> &A)
{

    sort(A.begin(), A.end(), compareChildVector);
    int count = 1, end = A[0][1];
    for (int i = 1; i < A.size(); i++)
    {
        if (A[i][0] > end)
        {
            // cout<<A[i][1]<< " ~ ";
            end = A[i][1];
            count++;
        }
    }

    return count;
}

// 2,3
// 1,4
// 4,6
// 8,9

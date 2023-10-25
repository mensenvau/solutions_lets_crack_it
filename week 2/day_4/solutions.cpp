vector<int> Solution::plusOne(vector<int> &A)
{
    int x = 1;
    for (int i = A.size() - 1; i >= 0; i--)
    {
        x = x + A[i];
        A[i] = x % 10;
        x = x / 10;
    }

    if (x > 0)
        A.insert(A.begin(), x);

    while (A[0] == 0)
    {
        A.erase(A.begin());
    }

    return A;
}

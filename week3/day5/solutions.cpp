int Solution::singleNumber(const vector<int> &A)
{

    int ans = 0, l = 1;
    for (int j = 0; j < 32; j++)
    {
        int count = 0;
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] & l)
                count++;
        }
        ans = ans + (count % 3) * l;
        l = l * 2;
    }

    return ans;
}

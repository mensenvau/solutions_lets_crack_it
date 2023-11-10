int Solution::majorityElement(const vector<int> &A)
{

    int count = -1, num;

    for (int i = 0; i < A.size(); i++)
    {
        if (count == -1)
        {
            num = A[i];
            count++;
        }
        else
        {
            if (num == A[i])
                count++;
            else
                count--;
        }
    }

    return num;
}

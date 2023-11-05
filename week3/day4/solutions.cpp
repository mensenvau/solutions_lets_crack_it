int Solution::cntBits(vector<int> &A)
{

    int n = A.size(), sum = 0;
    int arr_bits[33][2] = {0, 0};
    int m = 1000000007;

    for (int i = 0; i < n; i++)
    {

        int x = A[i];
        for (int k = 0; k < 33; k++)
        {
            if (x % 2 == 1)
            {
                sum = (sum + arr_bits[k][0]) % 1000000007;
                arr_bits[k][1]++;
            }
            else
            {
                sum = (sum + arr_bits[k][1]) % 1000000007;
                arr_bits[k][0]++;
            }
            x = x / 2;
        }
    }

    return (2 * sum) % 1000000007;
}

// add update
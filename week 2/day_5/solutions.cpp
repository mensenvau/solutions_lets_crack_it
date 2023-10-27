int Solution::repeatedNumber(const vector<int> &A)
{

    int n = A.size() / 3, count1 = 0, count2 = 0, e1 = INT_MAX, e2 = INT_MAX;

    for (auto item : A)
    {
        if (e1 == item)
        {
            count1++;
        }
        else if (e2 == item)
        {
            count2++;
        }
        else if (count1 == 0)
        {
            e1 = item;
            count1++;
        }
        else if (count2 == 0)
        {
            e2 = item;
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    count1 = 0;
    count2 = 0;
    for (auto item : A)
    {
        if (item == e1)
            count1++;
        if (item == e2)
            count2++;
    }

    // cout<<e1<<" "<<e2<<" "<<count1<<" "<<count2;
    if (count1 > n)
        return e1;
    if (count2 > n)
        return e2;

    return -1;
}

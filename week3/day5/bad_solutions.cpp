int Solution::singleNumber(const vector<int> &A)
{

    unordered_map<int, int> mp;
    for (int i = 0; i < A.size(); i++)
    {
        mp[A[i]]++;
    }

    for (auto x : mp)
    {
        if (x.second == 1)
            return x.first;
    }
}
// TL

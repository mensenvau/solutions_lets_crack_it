int Solution::removeDuplicates(vector<int> &A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> B;
    set<int> st;
    for (auto x : A)
    {
        int l = st.size();
        st.insert(x);
        if (st.size() != l)
            B.push_back(x);
    }
    A = B;
    return st.size();
}

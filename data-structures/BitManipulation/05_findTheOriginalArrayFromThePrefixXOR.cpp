#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findArray(vector<int> &pref)
    {
        int n = pref.size();
        vector<int> result(n);

        result[0] = pref[0];
        for (int i = 1; i < pref.size(); i++)
        {
            result[i] = pref[i] ^ pref[i - 1];
        }

        return result;
    }
};

int main()
{

    return 0;
}
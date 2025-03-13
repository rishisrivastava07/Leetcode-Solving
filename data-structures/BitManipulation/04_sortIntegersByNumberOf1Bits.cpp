#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> sortByBits(vector<int> &arr){
        int n = arr.size();

        auto lambda = [&](int &a, int &b){
            int count_a = __builtin_popcount(a);
            int count_b = __builtin_popcount(b);

            if (count_a == count_b){
                return a < b;
            }

            return count_a < count_b;
        };

        sort(begin(arr), end(arr), lambda);
        return arr;
    }
};

int main(){
    // driver code
    return 0;
}
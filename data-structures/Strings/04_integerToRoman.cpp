#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> i2R = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
        string result = "";
        int i = 0;
        while(num > 0){
            while(num >= i2R[i].first){
                num -= i2R[i].first;
                result += i2R[i].second;
            }
            i++;
        }
        return result;
    }
};

int main(){
    // Driver Code  
    return 0;
}
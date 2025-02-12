//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
    int findMin(vector<int>& nums) {
        int st = 0;
        int en = nums.size()-1;

        while(st < en){
            int mid = st + (en - st)/2;
            if(nums[mid] > nums[en]){
                // pivot lies in right side
                st = mid + 1;
            } else{
                en = mid;
            }
        } 
        return en;
    }
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        return findMin(arr);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
    }
}
// } Driver Code Ends
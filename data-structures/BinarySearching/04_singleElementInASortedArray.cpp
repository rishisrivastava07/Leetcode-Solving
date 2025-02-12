//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int search(int n, int arr[]) {
        // code
        int st = 0;
        int en = n-1;
        
        
        while(st < en){
            int mid = st + (en - st)/2;
            bool isOdd = (en - mid)%2 != 0 ? 1 : 0;
            
            if(arr[mid] == arr[mid+1]){
                if(isOdd){
                    en = mid - 1;
                }
                else{
                    st = mid + 2;
                }
            }
            else{
                if(isOdd){
                    st = mid + 1;
                }
                else{
                    en = mid;
                }
            }
        }
        
        return arr[en];
    }
};

//{ Driver Code Starts.

// Driver program
int main() {
    int t, len;
    cin >> t;
    while (t--) {
        cin >> len;
        int arr[len];
        for (int i = 0; i < len; i++) {
            cin >> arr[i];
        }
        Solution ob;
        cout << ob.search(len, arr) << '\n';
    }
    return 0;
}

// } Driver Code Ends
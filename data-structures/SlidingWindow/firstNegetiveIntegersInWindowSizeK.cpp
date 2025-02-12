//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> printFirstNegativeInteger(long long int nums[], long long int N, long long int K) {
    // Storing the result
    vector<ll> result;
    // Storing all negetive numbers encountered during the traversal through vector/ array
    queue<ll> negNum;
    int i = 0, j = 0;
    
    while(j < N){
        // if the number at j-th index is negetive push into the queue DS
        if(nums[j] < 0) negNum.push(nums[j]);
        
        // if the window size limit reached then
        if(j - i + 1 == K){
            // if it is not an empty queue simply store front element of queue to result array
            if(!negNum.empty()){
                result.push_back(negNum.front());
            } else {
                // else store 0
                result.push_back(0);
            }
            // If the ith element is the element in queue then we need to pop it
            if(nums[i] < 0) negNum.pop();
            i++;
        }
        j++;
    }
    
    return result;
}

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int st = 0;
        int en = n-1;

        while(st <= en){
            int mid = st + (en - st)/2;

            if((arr[mid] - (mid+1)) < k) st = mid + 1;
            else en = mid-1;
        }
        return st + k;
    }
};
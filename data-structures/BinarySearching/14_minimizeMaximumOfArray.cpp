class Solution {
    bool isPossible(vector<int>& nums, int n, int maxVal){
        vector<long long> arr(begin(nums), end(nums));

        for(int i = 0; i < n-1; i++){
            if(arr[i] > maxVal) return false;
            
            long long buffer = maxVal - arr[i];
            arr[i+1] -= buffer;
        }

        return arr[n-1] <= maxVal;
    }
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();

        int st = 0;
        int en = *max_element(begin(nums), end(nums));

        int ans = 0;
        while(st <= en){
            int mid = st + (en-st)/2;

            if(isPossible(nums, n, mid)){
                ans = mid;
                en = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        return ans;
    }
};
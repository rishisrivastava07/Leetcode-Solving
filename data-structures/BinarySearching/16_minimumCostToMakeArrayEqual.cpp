class Solution {
public:
    typedef long long ll;

    ll calculateCost(vector<int>& nums, vector<int>& cost, int midEle){
        ll ans = 0; 
        for(int i = 0; i < nums.size(); i++){
            ans += (ll)abs(midEle - nums[i]) * cost[i];
        }
        return ans;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        ll ans = INT_MAX;

        int st = *min_element(begin(nums), end(nums));
        int en = *max_element(begin(nums), end(nums));

        while(st <= en){
            int mid = st + (en - st)/2;
            ll cost1 = calculateCost(nums, cost, mid);
            ll cost2 = calculateCost(nums, cost, mid+1);
            ans = min(cost1, cost2);

            if(cost1 < cost2){
                en = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }

        return ans == INT_MAX ? 0 : ans;
        
    }
};
class Solution {
    public:
        int n;
        int q;
    
        bool checkWithDifferenceArrayTechnique(vector<int>& nums, vector<vector<int>>& queries, int k){
            vector<int> diff(n, 0);
    
            for(int i = 0; i <= k; i++){
                int st = queries[i][0];
                int en = queries[i][1];
                int val = queries[i][2];
    
                diff[st] += val;
                if(en+1 < n) diff[en+1] -= val;
            }
    
            // cummulative sum
            int cumSum = 0;
            for(int i = 0; i < n; i++){
                cumSum += diff[i];
    
                diff[i] = cumSum;
                if(nums[i] - diff[i] > 0){
                    return false;
                }
            }
    
            return true;
        }
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            n = nums.size();
            q = queries.size();
    
            auto lambda = [](int x){
                return x == 0;
            };
    
            // no query required if all the elements of nums is already zero
            if(all_of(begin(nums), end(nums), lambda)) return 0;
    
            int result = -1;
            int st = 0;
            int en = q-1;
    
            while(st <= en){
                int mid = st + (en - st)/2;
                if(checkWithDifferenceArrayTechnique(nums, queries, mid) == true){
                    result = mid + 1;
                    en = mid - 1;
                } else {
                    st = mid + 1;
                }
            }
    
            return result;
        }
    };
class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            int pos_count = 0, neg_count = 0;
    
            for(int it : nums){
                if(it < 0) neg_count++;
                else if(it > 0) pos_count++;
                else continue;
            }
    
            return max(pos_count, neg_count);
        }
    };
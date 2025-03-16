class Solution {
    public:
        bool canDistribute(vector<int> &candies, long long k, int maxCandyPos){
            for(int &candy : candies){
                k -= (candy / maxCandyPos);
                if(k <= 0) return true;
            }
    
            return k <= 0;
        }
        int maximumCandies(vector<int>& candies, long long k) {
            int n = candies.size();
    
            int maxCandy = 0;
            long long totalCandy = 0;
    
            for(int& candy : candies){
                maxCandy = max(maxCandy, candy);
                totalCandy += candy;
            }
    
            if(totalCandy < k) return 0;
    
            int result = 0;
            int st = 1, en = maxCandy;
            
            while(st <= en){
                int mid = st + (en - st)/2;
                if(canDistribute(candies, k, mid)){
                    result = mid;
                    st = mid + 1;
                } else {
                    en = mid - 1;
                }
            }
    
            return result;
        }
    };
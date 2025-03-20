class Solution {
    public:
        int minOperations(vector<int>& nums) {
            int n = nums.size();
            int tempCount = 0, flipCount = 0;
            int i = 0;
    
            deque<int> flipQue;
    
            while(i < n){
                if(i >= 3){
                    tempCount -= flipQue.front();
                    flipQue.pop_front();
                }
    
                if(tempCount%2 == nums[i]){
                    if(i + 3 > n) return -1;
    
                    flipCount++;
                    tempCount++;
                    flipQue.push_back(1);
                }
                else{
                    flipQue.push_back(0);
                }
                i++;
            }
    
            return flipCount;
        }
    };
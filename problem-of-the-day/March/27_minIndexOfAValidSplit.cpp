class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            int n = nums.size();
            unordered_map<int, int> left_mp; // keep one element in the left map
            unordered_map<int, int> right_mp; // populate the 1 to n-1 element in the right map
            for(int i = 0; i < n; i++){
                right_mp[nums[i]] += 1;
            }
    
            for(int i = 0; i < n; i++){
                left_mp[nums[i]]++;
                right_mp[nums[i]]--;
    
                int n1 = i+1;
                int n2 = n-i-1;
    
                if(left_mp[nums[i]] > n1/2 && right_mp[nums[i]] > n2/2){
                    return i;
                }
            }
    
            return -1;
        }
    };


    // Approach - 02

    class Solution {
        public:
            int minimumIndex(vector<int>& nums) {
                int n = nums.size();
            
                int majority = 0;
                int count = 0;
                
                for(int i = 0; i < n; i++){
                    if(count == 0){
                        majority = nums[i];
                    } else if(majority == nums[i]){
                        count++;
                    } else {
                        count--;
                    }
                }
        
                int majCount = 0;
                for(int i = 0; i < n; i++){
                    if(nums[i] == majority){
                        majCount++;
                    }
                }
        
                count = 0;
                for(int i = 0; i < n; i++){
                    if(nums[i] == majority){
                        count++;
                    }
        
                    int remaining = majCount - count;
                    int n1 = i+1;
                    int n2 = n-i-1;
        
                    if(count*2 > n1 && remaining*2 > n2){
                        return i;
                    }
                }
        
                return -1;
            }
        };
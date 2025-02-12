// Approach - 01 : Brute Force approach (TLE)
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        // TC : O(n^4) SC : O(1)
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    for(int l = 0; l < n; l++){
                        if(nums[i] != nums[j] && nums[i] != nums[k] && nums[i] != nums[l] 
                        && nums[j] != nums[k] && nums[j] != nums[l] && nums[k] != nums[l]){
                            if(nums[i] * nums[j] == nums[k] * nums[l]) count++;
                        }
                    }
                }
            }
        }

        return count;
    }
};

// Approach - 02 : Using sort function (TLE)
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int tuples = 0;

        // TC : O(nlogn)
        sort(nums.begin(), nums.end());

        // TC : O(n^4) & SC : O(1)
        for(int i = 0; i < n; i++){
            for(int j = n-1; j > i; j--){
                for(int k = i+1; k < j; k++){
                    for(int l = j-1; l > k; l--){
                        int p1 = nums[i] * nums[j];
                        int p2 = nums[k] * nums[l];

                        if(p1 == p2) tuples++;
                    }
                }
            }
        }

        return tuples * 8;
    }
};

// Approach - 03 using set
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int tuples = 0;

        // TC : O(nlogn)
        sort(nums.begin(), nums.end()); 

        // TC : O(n^3) SC : O(n)
        for(int i = 0; i < n; i++){
            for(int j = n-1; j > i; j--){
                int product = nums[i] * nums[j];
                unordered_set<int> st;

                for(int k = i+1; k < j; k++){
                    if(product % nums[k] == 0){
                        int d_value = product / nums[k];
                        if(st.count(d_value)){
                            tuples++;
                        }
                        st.insert(nums[k]);
                    }
                }
            }
        }

        return tuples * 8;
    }
};

// Approach - 04 - Optimal
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        // TC : O(nlogn)
        sort(begin(nums), end(nums));

        // SC : O(n * n-1)
        unordered_map<int, int> mp; // {product --> count}

        // storing the frquency count of each product in the array
        // TC : O(n^2)
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int product = nums[i] * nums[j];
                mp[product] += 1;
            }
        }

        int tuples = 0;
        
        // TC : O(n)
        for(auto& it : mp){
            if(it.second > 1){
                int freq = it.second;
                tuples += (freq * (freq - 1))/2;
            }
        }

        return tuples * 8;
    }
};
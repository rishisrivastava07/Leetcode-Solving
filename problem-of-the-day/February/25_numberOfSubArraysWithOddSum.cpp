// Approach - 01

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long oddCount = 0, prefixSum = 0;
        for(int a : arr) {
            prefixSum += a;
            oddCount += prefixSum % 2;
        }
        oddCount += (arr.size() - oddCount) * oddCount;
        return oddCount % 1'000'000'007;
    }
};


// Approach - 02 
class Solution {
public:
    int M = 1e9 + 7;
    int numOfSubarrays(vector<int>& nums) {
        int n = nums.size();
    
        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        int evenCount = 1; // we consider 0 as even so initially we set evenCount = 1
        int oddCount = 0;
        int result = 0;
    
        for(int ps : prefixSum){
            if(ps % 2 == 0){
                // even + odd = odd
                if(oddCount > 0) result = (result + oddCount) % M;
                evenCount++;
            } else {
                // odd + even = odd
                if(evenCount > 0) result = (result + evenCount) % M;
                oddCount++;
            }
        }

        return result;
    }
};
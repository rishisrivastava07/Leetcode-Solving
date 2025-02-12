class Solution {
public:
    bool calculateCapacity(int mid, int n, vector<int>& weights, int days){
        int capacity = 1;
        int wt = 0;
        for(int i = 0; i < n; i++){
            if(weights[i] > mid) return false;
            if(wt + weights[i] > mid){
                capacity++;
                wt = weights[i];
                if(capacity > days) return false;
            }
            else{
                wt += weights[i];
            }
        } 
        
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int st = 0;
        int en = accumulate(begin(weights), end(weights), 0);

        int result = -1;
        while(st <= en){
            int mid = st + (en - st)/2;

            if(calculateCapacity(mid, n, weights, days)){
                result = mid;
                en = mid - 1;
            } else {
                st = mid + 1;
            }
        }

        return result;
    }
};
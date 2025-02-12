class Solution {
    double calculateTime(int mid, vector<int>& dist, double hour, int n){
        double timeTaken = 0.0;

        for(int i = 0; i < n; i++){
            double t = (double)dist[i] / (double)mid;
            if(i == n-1) timeTaken += t;
            else timeTaken += ceil(t);
        } 
        
        return timeTaken;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        int st = 1;
        int en = 1e7;

        int result = -1;
        while(st <= en){
            int mid = st + (en - st)/2;
            if(calculateTime(mid, dist, hour, n) <= hour){
                result = mid;
                en = mid - 1;
            } else{
                st = mid + 1;
            }
        }

        return result;
    }
};
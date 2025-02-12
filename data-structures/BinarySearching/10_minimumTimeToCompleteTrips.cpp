class Solution {
    bool checkTime(vector<int>& time, int totalTrips, long long givenTime){
        long long actualTime = 0;
        for(auto& it: time){
            actualTime += (givenTime/it);
        }
        
        return actualTime >= totalTrips;
    }
public:
    long long minimumTime(vector<int>& time, int totalTrips) {        
        long long st = 1;
        long long en = (long long) *min_element(begin(time), end(time)) * totalTrips;

        while(st < en){
            long long trips = st + (en - st)/2;
            if(checkTime(time, totalTrips, trips)) en = trips;
            else st = trips+1;
        }

        return st;
    }
};
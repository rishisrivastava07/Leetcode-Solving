class Solution {
public:
    typedef long long ll;
    bool isPossible(vector<int> batteries, int N, ll& midTime){
        // total time required by N computers if the battery lifespan is midTime
        ll targetMinutes = N * midTime;
        ll sum = 0;

        for(int i = 0; i < batteries.size(); i++){
            // we take minimum of batteries[i] & midTime which ever possible add to sum
            sum += min((ll)batteries[i], midTime);
            // if we get targetMinutes or more return true because it is possible
            if(sum >= targetMinutes) return true;
        }

        return false;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        int m = batteries.size();
        // Calculate the total time given by all batteries
        ll totalMinutes = accumulate(begin(batteries), end(batteries), (ll)0);
        // starting pointer must be the minimum of all batteries
        ll st = *min_element(begin(batteries), end(batteries));
        // ending pointer is the average of total time given by all batteries by the n number of computers
        ll en = totalMinutes/n;
        
        ll result = 0;
        while(st <= en){
            ll mid = st + (en - st)/2;

            // Check for the possible that currentTime can fullfill the time required by N computers
            if(isPossible(batteries, n, mid) == true){
                result = mid;
                st = mid + 1;
            } else { 
                en = mid - 1;
            } 
        }

        return result;
    }
};
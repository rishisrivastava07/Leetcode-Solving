class Solution {
    public:
        typedef long long ll;
    
        bool isPossible(vector<int>& ranks, int& cars, ll &time){
            ll carsFixed = 0;
            for(int &r : ranks){
                carsFixed += sqrt(time/r);
                if(carsFixed >= cars) return true;
            }
    
            return carsFixed >= cars; 
        }
        long long repairCars(vector<int>& ranks, int cars) {
            int n = ranks.size();
            int maxRank = *max_element(begin(ranks), end(ranks));
    
            ll st = 1; 
            ll en = 1LL * maxRank * cars * cars;
            ll result = 0;
    
            while(st <= en){
                ll mid = st + (en - st)/2;
            
                if(isPossible(ranks, cars, mid)){
                    result = mid;
                    en = mid - 1;
                } else {
                    st = mid + 1;
                }
            }
    
            return result;
        }
    };
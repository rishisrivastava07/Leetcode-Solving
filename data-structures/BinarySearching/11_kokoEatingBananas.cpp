class Solution {
    bool isPossible(vector<int>& piles, int h, int midSpeed){
        int timeTaken = 0;
        for(auto& it : piles){
            if(it % midSpeed == 0) timeTaken += (it / midSpeed);
            else timeTaken = timeTaken + (it / midSpeed) + 1;
        }

        return timeTaken <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int st = 1;
        int en = *max_element(begin(piles), end(piles));

        while(st < en){
            int midSpeed = st + (en - st)/2;

            if(isPossible(piles, h, midSpeed)) en = midSpeed;
            else st = midSpeed + 1;
        }

        return st;
    }
};
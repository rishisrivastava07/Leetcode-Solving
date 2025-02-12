class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> ans;
        
        sort(begin(potions), end(potions));

        for(int i = 0; i < n; i++){
            long long minPotion = ceil((1.0 * success)/spells[i]);
            int maxPotionValue = potions[m-1];

            if(minPotion > maxPotionValue){
                ans.push_back(0);
                continue;
            }

            int index = lower_bound(begin(potions), end(potions), minPotion) - begin(potions);
            int count = m - index;

            ans.push_back(count);
        }

        return ans;
    }
};class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> ans;
        
        sort(begin(potions), end(potions));

        for(int i = 0; i < n; i++){
            long long minPotion = ceil((1.0 * success)/spells[i]);
            int maxPotionValue = potions[m-1];

            if(minPotion > maxPotionValue){
                ans.push_back(0);
                continue;
            }

            int index = lower_bound(begin(potions), end(potions), minPotion) - begin(potions);
            int count = m - index;

            ans.push_back(count);
        }

        return ans;
    }
};
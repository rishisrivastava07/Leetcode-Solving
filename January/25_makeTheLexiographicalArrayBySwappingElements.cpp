class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> vec = nums; // copy the original vector
        sort(begin(vec), end(vec)); // sort the vector

        int groupNum = 0; // initially group number is set to 0
        unordered_map<int, int> numToGroup; // to store which nums[i] goes to which particular group
        numToGroup[vec[0]] = groupNum;

        unordered_map<int, list<int>> groupToList; // we will use map of lists to store and operate numbers in O(1)
        groupToList[groupNum].push_back(vec[0]);

        // building the group
        for(int i = 1; i < n; i++){
            if(abs(vec[i] - vec[i-1]) > limit){
                // switch to another group if limit exceeds
                groupNum += 1;
            }

            numToGroup[vec[i]] = groupNum;
            groupToList[groupNum].push_back(vec[i]);
        }

        // merge the groups
        vector<int> result(n);
        for(int i = 0; i < n; i++){
            int num = nums[i];
            int group = numToGroup[num];

            // smallest available num in this group
            result[i] = *(groupToList[group].begin());
            groupToList[group].pop_front();
        }

        // return the result
        return result;
    }
};
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> st;
        int n = nums.size();

        for(string &num : nums){
            st.insert(stoi(num, 0, 2));
        }

        string result = "";
        for(int i = 0; i <= n; i++){
            if(st.find(i) == st.end()){
                result = bitset<16>(i).to_string();
                return result.substr(16-n, n);
            }
        }

        return "";
    }
};
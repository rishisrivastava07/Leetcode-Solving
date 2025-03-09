class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        for(int i = 0; i < k-1; i++){
            colors.push_back(colors[i]);
        }

        // new array 
        int N = n + (k - 1);
        int i = 0, j = 1;

        int result = 0;
        while(j < N){
            if(colors[j] == colors[j-1]){
                i = j;
                j++;
                continue;
            }

            if(j - i + 1 == k){
                result += 1;
                i++;
            }

            j++;
        }

        return result;
    }
};
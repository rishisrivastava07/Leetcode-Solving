class Solution {
public:
    // Approach - 01 ---> TC - O(N^3) SC - O(N)
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> result(n, 0);

        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = 0; j <= i; j++){
                for(int k = 0; k <= i; k++){
                    if(A[j] == B[k]){
                        count++;
                        break;
                    }
                }
            }
            result[i] = count;
        }

        return result;
    }
    // Approach - 2 ---> TC - O(N^2) SC - O(N)
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> result;

        vector<bool> Present_A(n+1, false);
        vector<bool> Present_B(n+1, false);

        for(int i = 0; i < n; i++){
            Present_A[A[i]] = true;
            Present_B[B[i]] = true;

            int count = 0;
            for(int j = 0; j <= n; j++){
                if(Present_A[j] && Present_B[j]) count++;
            }
            result.push_back(count);    
        }

        return result;
    }

    // Approach - 3 ---> TC - O(N) SC - O(N)
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        unordered_map<int, int> mp;

        vector<int> result;
        int count = 0;

        for(int i = 0; i < n; i++){
            mp[A[i]]++;
            if(mp[A[i]] == 2) count++;

            mp[B[i]]++;
            if(mp[B[i]] == 2) count++;

            result.push_back(count);
        }

        return result;
    }
};
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();

        // store the indexes containing '1'
        vector<int> indices;
        for(int i = 0; i < n; i++){
            if(boxes[i] == '1') indices.push_back(i);
        }

        vector<int> result(n, 0);
        // update the number of hops taken to reach all one at particular index
        for(int i = 0; i < n; i++){
            for(int j = 0; j < indices.size(); j++){
                result[i] += abs(indices[j] - i);
            }
        }

        return result;
    }
};
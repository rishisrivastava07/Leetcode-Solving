class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            int n = recipes.size();
            vector<string> result;
    
            // storing the supply present for making the recipe
            unordered_set<string> st(begin(supplies), end(supplies));
            vector<bool> cooked(n, false);
    
            int count = n;
            while(count--){
                for(int j = 0; j < n; j++){
                    if(cooked[j] == true){
                        continue;
                    }
    
                    bool canBeCooked= true;
                    for(int k = 0; k < ingredients[j].size(); k++){
                        if(!st.count(ingredients[j][k])){
                            canBeCooked = false;
                            break;
                        }
                    }
    
                    if(canBeCooked == true){
                        st.insert(recipes[j]);
                        result.push_back(recipes[j]);
                        cooked[j] = true;
                    }
                }
            }
    
            return result;
        }
    };
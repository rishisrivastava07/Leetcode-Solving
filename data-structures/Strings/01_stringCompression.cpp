#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();

        // index for assigning the values to char array itself and i is to iterate the array
        int index = 0;
        int i = 0;

        while(i < n){
            char curr_char = chars[i];
            int count = 0;

            // Count the duplicates
            while(i < n && chars[i] == curr_char){
                count++;
                i++;
            }

            // Assign the values to chars array
            chars[index++] = curr_char;
        
            // Check for the count > 1 and assign it
            if(count > 1){
                string count_str = to_string(count);
                for(char& ch : count_str){
                    chars[index++] = ch;
                }
            }
        }

        return index;
    }
};

int main(){
    // Driver code
    return 0;
}
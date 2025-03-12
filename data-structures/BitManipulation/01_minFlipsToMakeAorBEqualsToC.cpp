class Solution {
    public:
        int minFlips(int a, int b, int c) {
            int minFlips = 0;
            while(a != 0 || b != 0 || c != 0){
                int bit_a = a & 1;
                int bit_b = b & 1;
                int bit_c = c & 1;
    
                if(bit_c == 1){
                    // a = 1 or b = 1 or both equals to 1
                    if(bit_a == 0 && bit_b == 0) minFlips++; 
                } else {
                    // a and b must be unset i.e. 0
                    if((bit_a == 1 && bit_b == 0) || (bit_a == 0 && bit_b == 1)) minFlips++;
                    else if(bit_a == 1 && bit_b == 1) minFlips += 2;
                }
                a >>= 1;
                b >>= 1;
                c >>= 1;
            }
    
            return minFlips;
        }
    };
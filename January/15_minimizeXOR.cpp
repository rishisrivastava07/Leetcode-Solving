class Solution {
public:
    bool isSetBit(int &x, int bit){
        return x & (1 << bit);
    }

    bool setBit(int &x, int bit){
        return x |= (1 << bit);
    }

    bool unsetBit(int &x, int bit){
        return x &= ~(1 << bit);
    }

    // Approach - 01 : TC - O(log n) SC - O(1)
    int minimizeXor(int num1, int num2) {
        int x = num1;

        int requiredSetBits = __builtin_popcount(num2);
        int currentSetBits = __builtin_popcount(x);

        int bit = 0;
        if(currentSetBits < requiredSetBits){
            while(currentSetBits < requiredSetBits){
                if(!isSetBit(x, bit)){
                    setBit(x, bit);
                    currentSetBits++;
                }
                bit++;
            }
        } else {
            while(currentSetBits > requiredSetBits){
                if(isSetBit(x, bit)){
                    unsetBit(x, bit);
                    currentSetBits--;
                }
                bit++;
            }
        }

        return x;
    }

    // Approach - 02 : TC - O(1) SC - O(1)
    int minimizeXor(int num1, int num2) {
        int x = 0;

        int requiredSetBits = __builtin_popcount(num2);

        for(int bit = 31; bit >= 0 && requiredSetBits > 0; bit--){
            if(isSetBit(num1, bit)){
                setBit(x, bit);
                requiredSetBits--;
            }
        }

        for(int bit = 0; bit <= 31 && requiredSetBits > 0; bit++){
            if(!isSetBit(num1, bit)){
                setBit(x, bit);
                requiredSetBits--;
            }
        }

        return x;
    }
};
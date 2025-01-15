class Solution {
public:
    // Approach - 01 : TC - O(log n) SC - O(1)
    bool isSetBit(int &x, int bit){
        return x & (1 << bit);
    }

    bool setBit(int &x, int bit){
        return x |= (1 << bit);
    }

    bool unsetBit(int &x, int bit){
        return x &= ~(1 << bit);
    }

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
};
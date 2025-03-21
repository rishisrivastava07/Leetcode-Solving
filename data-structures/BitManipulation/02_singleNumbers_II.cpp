/**
 * Company Asked - OLA, Amazon, Google
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int result = 0;

        for (int k = 0; k <= 31; k++)
        {
            int temp = 1 << k;
            int count_1 = 0;

            for (int &num : nums)
            {
                if ((num & temp) != 0)
                    count_1 += 1;
            }

            if (count_1 % 3 == 1)
                result = result | temp;
        }

        return result;
    }
};

int main()
{
    // driver code
    return 0;
}
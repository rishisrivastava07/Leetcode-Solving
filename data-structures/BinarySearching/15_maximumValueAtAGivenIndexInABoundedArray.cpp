class Solution {
    #define LL long long

    LL getSum(LL index, LL count){
        return (count * index) - (count * (count+1)/2);
    }
public:
    int maxValue(int n, int index, int maxSum) {
        LL st = 1;
        LL en = maxSum;

        LL result = 0;
        LL mid;
        while(st <= en){
            mid = st + (en-st)/2;

            // Left Sum
            LL leftCount = min((LL)index, mid-1);
            LL leftSum =  getSum(mid, leftCount);
            leftSum += max((LL)0, index - (mid - 1));

            // Right Sum
            LL rightCount = min((LL)n-index-1, mid-1);
            LL rightSum =  getSum(mid, rightCount);
            rightSum += max((LL)0, n - index - 1 - (mid - 1));

            LL totalSum = rightSum + leftSum + mid;
            
            // Binary Search
            if(totalSum <= maxSum){
                result = max((LL) result, mid);
                st = mid + 1;
            }
            else en = mid - 1;
        }

        return result;
    }
};
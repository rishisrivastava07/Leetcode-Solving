class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st = 0;
        int en = arr.size()-1;

        while(st < en){
            int mid = st + (en - st)/2;

            if(arr[mid] < arr[mid+1]){
                // discard left side
                st = mid + 1;
            }
            else if(arr[mid] > arr[mid+1]){
                // discard right side
                en = mid;
            }
        }
        return en;
    }
};
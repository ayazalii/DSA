class Solution {
public:
    bool isPerfectSquare(int num) {
        int start=1;
        int end=num;
        while(start<=end){
            long long mid=start+(end-start)/2;
            long long square=mid*mid;

            if(square==num){
                return true;
            }
            if(square<num){
                start=mid+1;

            }
            else{
                end=mid-1;
            }
        }
        return false;
    }
};
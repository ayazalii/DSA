class Solution {
public:
bool isPossible(vector<int>& weights, int days, int mid) {
    int day = 1;
    int shipWeight = 0;

    for(int i = 0; i < weights.size(); i++) {

        if(weights[i] > mid)
            return false;

        if(shipWeight + weights[i] <= mid) {
            shipWeight += weights[i];
        }
        else {
            day++;
            shipWeight = weights[i];

            if(day > days)
                return false;
        }
    }

    return true;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int total=0;
        for(int i=0;i<weights.size();i++){
            total+=weights[i];
        }
        int s=1,e=total;
        int ans; //min capacity of ship
        while(s<=e){

            int mid=(s+e)/2;//assume atmost capacity of ship is mid
            
            if(isPossible(weights,days,mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};
class Solution {
public:
bool isPossible(vector<int>&position,int m,int mid){
    int ball=1;
    int pos=position[0];
    for(int i=1;i<position.size();i++){
        if(position[i]-pos >=mid){
            ball++;
            pos=position[i];
        }
        if(ball==m){
            return true;
        }
    }
    return false;
}
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();
        int s =1 , e = position[n-1] - position[0];
        int ans;
        while(s<=e){
            int mid=(s+e)/2; //atleast mid distance btwn two balls
            if(isPossible(position,m,mid)){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans;
    }
};
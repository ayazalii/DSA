class Solution {
public:
    int minOperations(auto& a) {
        int n=a.size();
        int asc=1,dsc=1;

        for(int i=1;i<n;i++){
            asc+=a[i]==(a[i-1]+1)%n;
            dsc+=a[i-1]==(a[i]+1)%n;

        }

        if(asc==n)
            return a.front() ? min(n-a.front(),a.front()+2):0;

            if(dsc==n)
            return min(n-a.back(),a.back())+1;

            return -1;
    }
};
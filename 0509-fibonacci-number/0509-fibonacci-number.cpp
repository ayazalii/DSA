class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1)  return n;

        long long a=0;
        long long b=1;

        for(int i=2;i<=n;i++){
            long long next=a+b;

            a=b;
             
            b=next;
        }
        return b;
    }
};
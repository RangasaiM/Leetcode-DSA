class Solution {
public:

    int mod = 1000000007;

    long long exp(long long x,long long n){
        long long ans=1;
        while(n>0){
            if(n%2==1){
                ans=((ans%mod)*(x%mod))%mod;
                n=n-1;
            }
            else{
                x=((x%mod)*(x%mod))%mod;
                n=n/2;
            }
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long ans=((exp(5,(n+1)/2)%mod)*(exp(4,n/2)%mod))%mod;
        return ans;
    }
};
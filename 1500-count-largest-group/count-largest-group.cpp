class Solution {
public:
    
    int sumOfDigits(int n){
        int sum=0;
        while(n>0){
            int temp=n%10;
            sum+=temp;
            n=n/10;
        }
        return sum;
    }

    int countLargestGroup(int n) {
        unordered_map<int,int> mp;
        int maxi=0;
        for(int i=1;i<=n;i++){
            int temp=sumOfDigits(i);
            mp[temp]++;
            maxi=max(maxi,mp[temp]);
        }
        int cnt=0;
        for(auto i:mp){
            if(i.second==maxi) cnt++;
        }
        return cnt;
    }
};
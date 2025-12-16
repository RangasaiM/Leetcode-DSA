class Solution {
public:
    string largestOddNumber(string num) {
        long long n=num.length()-1;
        int temp=num[n]-'0';
        string ans="";
        if(temp%2) return num;
        for(long long i=n;i>=0;i--){
            temp=num[i]-'0';
            if(temp%2) {
                ans=num.substr(0,i+1);
                break;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        long ans=0;
        int temp=1;
        int st=0;
        while(st<n && s[st]==' ') {
            st++;
        }
        if(st<n && s[st]=='-') {
            temp=-1;
            st++;
        }
        else if(st<n && s[st]=='+') {
            st++;
        }
        for(int i=st;i<n;i++){
            if(isdigit(s[i])){
                ans=(10*ans)+(s[i]-'0');
            }
            else return ans*temp;
            if(ans*temp>INT_MAX) return INT_MAX;
            if(ans*temp<INT_MIN) return INT_MIN;
        }
        return ans*temp;
    }
};
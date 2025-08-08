class Solution {
public:

    string invert(string s){
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='0') ans+='1';
            else ans+='0';
        }
        return ans;
    }

    string rev(string s){
        string ans="";
        for(int i=s.length()-1;i>=0;i--){
            ans+=s[i];
        }
        return ans;
    }

    string nthString(string str,int m,int n){
        if(m==n) return str;
        string nth=str+'1'+rev(invert(str));
        return nthString(nth,m+1,n);
    }

    char findKthBit(int n, int k) {
        string ans=nthString("0",1,n);
        cout<<ans;
        return ans[k-1];
    }
};
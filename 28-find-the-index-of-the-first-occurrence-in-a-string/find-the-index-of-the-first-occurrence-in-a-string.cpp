class Solution {
public:

    vector<int> Lps(string s){
        int n=s.length();
        vector<int> lps(n);
        lps[0]=0;
        int i=0;
        int j=1;

        while(j<n){
            if(s[i]==s[j]){
                lps[j]=i+1;
                i++;
                j++;
            }
            else{
                if(i==0){
                    lps[j]=0;
                    j++;
                }
                else{
                    i=lps[i-1];
                }
            }
        }
        return lps;
    }

    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();

        int i=0;
        int j=0;

        vector<int> lps;
        lps=Lps(needle);

        while(i<n){
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }
            else{
                if(j==0) i++;
                else{
                    j=lps[j-1];
                }
            }
            if(j==m) return i-j;
        }
        return -1;
        
    }
};
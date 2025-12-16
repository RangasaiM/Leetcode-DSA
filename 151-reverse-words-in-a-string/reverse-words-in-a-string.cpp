class Solution {
public:
    string reverseWords(string s) {
        int n=s.length()-1;
        string revStr="";
        string temp="";
        for(int i=n;i>=0;i--){
            if(s[i]!=' '){
                temp=s[i]+temp;
            }
            if(temp!="" && (i==0 || s[i]==' ')){
                if(revStr!="") revStr+=" ";
                revStr=(revStr+temp);
                temp="";
            }
        }
        return revStr;
    }
};
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s==goal) return true;
        if(s.length()!=goal.length()) return false;

        s=s+s;
        
        for(int i=0;i<s.length();i++){
            int j=0;
            while (j < goal.length() && s[i + j] == goal[j]) {
                j++;
            }
            if (j == goal.length()) return true;
        }
        return false;
    }
};
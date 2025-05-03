class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            if(tops[i]==bottoms[i]){
                mp[tops[i]]++;
            }
            else{
                mp[tops[i]]++;
                mp[bottoms[i]]++;
            }
        }
        int cnum=-1;
        for(auto i:mp){
            if(i.second>=n) cnum=i.first;
        }
        if(cnum==-1) return -1;
        int tcnt=0,bcnt=0;
        for(int i=0;i<n;i++){
            if(tops[i]==cnum) tcnt++;
            if(bottoms[i]==cnum) bcnt++;
        }
        return n-max(tcnt,bcnt);
    }
};
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& schedule) {
        int n=schedule.size();
        int cnt=0;
        sort(schedule.begin(),schedule.end());
        int st=INT_MAX;
        int end=INT_MIN;
        for(int i=0;i<n;i++){
            if(schedule[i][0]>=end){
                st=min(schedule[i][0],st);
                end=schedule[i][1];
            }
            else{
                end=min(end,schedule[i][1]);
                cnt++;
            }
        }
        return cnt;;
    }
};
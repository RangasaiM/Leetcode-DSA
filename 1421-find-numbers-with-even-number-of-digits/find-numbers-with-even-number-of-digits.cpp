class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt=0;
        for(int i:nums){
            string str=to_string(i);
            if(str.length()%2==0) cnt++;
        }
        return cnt;
    }
};
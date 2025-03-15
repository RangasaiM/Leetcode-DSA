class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_set<int> s;
        vector<int> dis;
        for(auto i:nums){
            s.insert(i);
        }
        for(int i=1;i<=nums.size();i++){
            if(s.find(i)==s.end()) dis.push_back(i);
        }
        return dis;
    }
};
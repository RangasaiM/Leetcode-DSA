class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        int n=arr.size();
        vector<int> temp={arr[0][0],arr[0][1]};
        for(int i=1;i<n;i++){
            int f=arr[i][0];
            int s=arr[i][1];
            if(temp[1]>=f){
                temp[1]=max(temp[1],s);
            }
            else{
                ans.push_back(temp);
                temp=arr[i];
            }
        }
        ans.push_back(temp);
        return ans;
    }
};
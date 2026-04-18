class Solution {
public:
    int trap(vector<int>& height) {
        int i=0;
        int j=height.size()-1;

        int lmax=0;
        int rmax=0;

        int ans=0;

        while(i<j){
            if(height[i]<=height[j]){
                if(lmax<height[i]){
                    lmax=height[i];
                }
                else{
                    ans+=lmax-height[i];
                }
                i++;
            }
            else{
                if(rmax<height[j]){
                    rmax=height[j];
                }
                else{
                    ans+=rmax-height[j];
                }
                j--;
            }
        }
        return ans;
    }
};
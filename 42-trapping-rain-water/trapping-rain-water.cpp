class Solution {
public:
    int trap(vector<int>& height) {
        int lmax,rmax,total=0;
        int r=height.size()-1;
        int l=0;

        while(l<r){
            if(height[l]<=height[r]){
                if(lmax>height[l]){
                    total+=lmax-height[l];
                }
                else{
                    lmax=max(lmax,height[l]);
                }
                l++;
            }
            else{
                if(rmax>height[r]){
                    total+=rmax-height[r];
                }
                else{
                    rmax=max(rmax,height[r]);
                }
                r--;
            }

        }
        return total;
    }
};
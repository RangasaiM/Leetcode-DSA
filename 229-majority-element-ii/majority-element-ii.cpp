class Solution {
public:

    vector<int> majorityElement(vector<int>& arr) 
    {
        int n=arr.size();
        int cnt1=0,cnt2=0;
        int ele1=0,ele2=0;
        for (int i=0;i<n;i++){
            if(cnt1==0 && ele2!=arr[i]){
                cnt1=1;
                ele1=arr[i];
            }
            else if(cnt2==0 && ele1!=arr[i]){
                cnt2=1;
                ele2=arr[i];
            }
            else if(ele1==arr[i]) cnt1++;
            else if(ele2==arr[i]) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        vector<int> ans;
        cnt1=0,cnt2=0;
        int f=0;
        for(int i=0;i<n;i++){
            if(ele1==arr[i]) cnt1++;
            else if(ele2==arr[i]) cnt2++;
            if((cnt1==0 &&cnt2==1) || (cnt1==1 && cnt2==0) && f==0) f=arr[i];
        }
        int mini=n/3;
        if(ele1!=f){
            swap(ele1,ele2);
            swap(cnt2,cnt1);
        }
        if(cnt1>mini) ans.push_back(ele1);
        if(cnt2>mini) ans.push_back(ele2);
        return ans;
    }
    
};
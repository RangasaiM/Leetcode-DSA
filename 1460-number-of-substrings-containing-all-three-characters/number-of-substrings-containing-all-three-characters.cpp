class Solution {
public:
bool isValid(int arr[]){
        for(int i=0;i<3;i++){
            if(arr[i]==0) return false;
        }
        return true;
    }
    int numberOfSubstrings(string s) {
        int n=s.size();
        int arr[3]={0,0,0};
        int ans=0;
        int i=0;
        int j=0;
        while(i<n){
            arr[s[i]-'a']++;
            while(isValid(arr)){
                ans+=n-(i);
                arr[s[j]-'a']--;
                j++;
            }
            i++;
        }
        return ans;
    }
};
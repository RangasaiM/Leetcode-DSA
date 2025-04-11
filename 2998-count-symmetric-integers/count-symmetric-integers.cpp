class Solution {
public:

    int count(string s){
        int cnt=0;
        for(int i=0;i<s.length();i++){
            int temp=s[i] - '0';
            cnt+=temp;
        }
        return cnt;
    }

    int countSymmetricIntegers(int low, int high) {
        int cnt=0;
        for(int i=low;i<=high;i++){
            string st=to_string(i);
            int k=st.length();
            if(k%2==0){
                string f=st.substr(0,k/2);
                string s=st.substr(k/2,k);
                if(count(f)==count(s)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
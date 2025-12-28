class Solution {
public:

    vector<int> lps(string s) {
    int n = s.length();
    vector<int> lps(n, 0);

    int i = 0;
    int j = 1; 

    while (j < n) {
        if (s[i] == s[j]) {
            lps[j] = i + 1;
            i++;
            j++;
        } else {
            if (i == 0) {
                lps[j] = 0;
                j++;
            } else {
                i = lps[i - 1];
            }
        }
    }
    return lps;
}


    string shortestPalindrome(string s) {
        int n=s.size();


        string rev=s;

        reverse(rev.begin(),rev.end());

        string newStr=s+"*"+rev;

        vector<int> Lps=lps(newStr);


        int maxlen=Lps[2*n];


        if(maxlen==n) return s;
        string revi=s.substr(maxlen);
        reverse(revi.begin(),revi.end());
        return revi+s;
    }
};
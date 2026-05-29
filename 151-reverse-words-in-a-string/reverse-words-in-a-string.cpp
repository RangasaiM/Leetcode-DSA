class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;

        int n=s.length();

        string word="";

        for(int i=0;i<n;i++){
            if(s[i]!=' '){
                word+=s[i];
            }

            if(s[i]==' ' && word!=""){
                words.push_back(word);
                word="";
            }

        }

        if(word!=""){
            words.push_back(word);
            word="";
        }

        reverse(words.begin(),words.end());

        for(int i=0;i<words.size()-1;i++){
            word+=words[i]+" ";
        }
        word+=words[words.size()-1];
        return word;

    }
};
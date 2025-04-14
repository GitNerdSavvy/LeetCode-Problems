class Solution {
public:
    bool detectCapitalUse(string word) {
        bool C=true,s=true;
        bool f=isupper(word[0]);
        for(int i=1;i<word.length();i++){
            if(isupper(word[i])){
                s=false;
            }else{
                C=false;
            }
        }
        return (f && C) || s;
    }
};
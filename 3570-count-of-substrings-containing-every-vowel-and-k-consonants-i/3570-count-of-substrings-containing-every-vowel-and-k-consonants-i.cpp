class Solution {
public:
    bool check(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
            return true;
        }
        return false;
    }
    int countOfSubstrings1(string word, int k) {
        int l=0,j=0,count=0,ans=0;
        unordered_map<char,int>ump;
        while(j<word.length()){
            if(!check(word[j])){
                count++;
            }else{
                ump[word[j]]++;
            }
            while(ump.size()>=5 && count>k){
                if(check(word[l])){
                    ump[word[l]]--;
                    if(ump[word[l]]==0){
                        ump.erase(word[l]);
                    }
                }else{
                    count--;
                }
                l++;
            }
            ans+=j-l+1;
            j++;
        }
        return ans;
    }
    int countOfSubstrings(string word, int k) {
        return countOfSubstrings1(word,k)-countOfSubstrings1(word,k-1);
    }
};
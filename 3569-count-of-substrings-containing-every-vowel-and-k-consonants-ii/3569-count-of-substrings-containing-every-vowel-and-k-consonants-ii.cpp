class Solution {
public:
    bool check(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
            return true;
        }
        return false;
    }
    long long res(string s,int k){
        long long l=0,r=0,count=0,ans=0;
        unordered_map<char,int>ump;
        while(r<s.length()){
            if(!check(s[r])){
                count++;
            }else{
                ump[s[r]]++;
            }
            while(ump.size()>=5 && count>k){
                if(check(s[l])){
                    ump[s[l]]--;
                    if(ump[s[l]]==0){
                        ump.erase(s[l]);
                    }
                }else{
                    count--;
                }
                l++;
            }
            ans+=r-l+1;
            r++;
        }
        return ans;
    }
    long long countOfSubstrings(string word, int k) {
        return res(word,k)-res(word,k-1);
    }
};
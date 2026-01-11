class Solution {
public:
    int residuePrefixes(string s) {
        int ans=0;
        set<char>st;
        for(int i=0;i<s.length();i++){
            char it=s[i];
            st.insert(it);
            if(st.size()==(i+1)%3){
                ans++;
            }
            if(st.size()>=3) return ans;
        }
        return ans;
    }
};
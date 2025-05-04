class Solution {
public:
    int balancedString(string s) {
        unordered_map<char,int>ump;
        int n=s.length();
        for(int i=0;i<s.length();i++){
            ump[s[i]]++;
        }
        int ans=INT_MAX,j=0,k=n/4;
        for(int i=0;i<n;i++){
            ump[s[i]]--;
            while(j<n && ump['Q'] <= k && ump['W'] <= k && ump['E'] <= k && ump['R'] <= k){
                ans=min(ans,i-j+1);
                ump[s[j++]]+=1;
            }
        }
        return ans;
    }
};
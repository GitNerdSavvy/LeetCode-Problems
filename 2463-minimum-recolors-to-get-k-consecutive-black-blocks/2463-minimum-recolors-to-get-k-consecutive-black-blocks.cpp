class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans=INT_MAX;
        int i=0;
        int j=0;
        int n=blocks.length();
        unordered_map<char,int>mp;
        while(j<n){
            mp[blocks[j]]++;
            if(j-i+1<k){
                j++;
            }else if(j-i+1==k){
                ans=min(ans,mp['W']);
                mp[blocks[i]]--;
                // if(mp[blocks[i]]==0){
                //     mp.erase(blocks[i]);
                // }
                i++;
                j++;
            }
        }
        return ans;
    }
};
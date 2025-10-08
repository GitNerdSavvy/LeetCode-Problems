class Solution {
public:
#define ll long long
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        vector<int> ans;
        int n = potions.size();
        sort(potions.begin(), potions.end());
        for (int i = 0; i < spells.size(); i++) {
           int l=0,h=n-1;
            int t=n;
           while(l<=h){
                int mid = l + (h - l) / 2;
                if(1ll*potions[mid]*spells[i]>=success){
                    t=mid;
                    h=mid-1;
                }else{
                    l=mid+1;
                }
           }
               ans.push_back(n-t);
                
        }
        return ans;
    }
};
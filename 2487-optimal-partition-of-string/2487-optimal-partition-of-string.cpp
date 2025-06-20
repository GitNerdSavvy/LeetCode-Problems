class Solution {
public:
    int partitionString(string s) {
        unordered_set<char>us;
        int ans=1;
        for(char i  : s){
            if(us.count(i)){
                ans++;
                us.clear();
            }
                us.insert(i);
            
        }
        return ans;
    }
};
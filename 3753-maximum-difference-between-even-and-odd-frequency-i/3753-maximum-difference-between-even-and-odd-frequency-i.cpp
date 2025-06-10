class Solution {
public:
    int maxDifference(string s) {
        int eve=INT_MAX;
        int odd=0;
        unordered_map<char,int>ump;
        for(char it:s){
            ump[it]++;
        }
        for(auto it:ump){
            if(it.second%2==0 && it.second < eve)eve=it.second;
            if(it.second%2==1 && it.second > odd)odd=it.second;
        }
        return odd-eve;
    }
};
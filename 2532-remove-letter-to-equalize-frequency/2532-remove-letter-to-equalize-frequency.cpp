class Solution {
public:
   map<char, int> mp;
    bool solve()
    {
        set<int>st;
        for(auto [a, b]:mp)
            if(b) st.insert(b);
        return st.size() == 1;
    }
    bool equalFrequency(string word) 
    {
        set<int>st(word.begin(), word.end());
        for(auto ch:word) mp[ch]++;

        for(auto ch:st)
        {
            mp[ch]--;
            if(solve()) return true;
            mp[ch]++;
        }
        return false;
    }
};
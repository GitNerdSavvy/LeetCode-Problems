class Solution {
public:
    
    vector<int> findAnagrams(string s, string p) {
       vector<int> ans;
    int m = s.length(), n = p.length();
    if(n > m) return ans;

    vector<int> phash(26, 0), shash(26, 0);
    for(int i = 0; i < n; i++) {
        phash[p[i] - 'a']++;
        shash[s[i] - 'a']++;
    }

    if(phash == shash) ans.push_back(0);

    for(int i = n; i < m; i++) {
        shash[s[i] - 'a']++;
        shash[s[i - n] - 'a']--;
        if(phash == shash) ans.push_back(i - n + 1);
    }

    return ans;
    }
};
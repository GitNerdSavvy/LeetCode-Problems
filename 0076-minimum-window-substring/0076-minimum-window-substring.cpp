class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty()){
            return "";
        }
       vector<int>ump(256,0);
        int i=0,j=0,minLen=INT_MAX,index=-1,cnt=0;
        for(int i=0;i<t.length();i++){
            ump[t[i]]++;
        }
        while(j<s.length()){
           if(ump[s[j]]>0){
            cnt++;
           }
           ump[s[j]]--;
           while(cnt==t.size()){
           if(j-i+1<minLen){
            minLen=j-i+1;
            index=i;
           }
            ump[s[i]]++;
            if(ump[s[i]]>0){
                cnt--;
            }
            i++;
           }
           j++;
        }
        return index==-1?"":s.substr(index,minLen);
    }
};
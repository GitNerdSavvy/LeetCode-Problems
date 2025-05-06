class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int l=0,h=0;
        while(l<n){
            char temp=chars[l];
            int count=0;
            while(l<n && chars[l]==temp){
                count++;
                l++;
            }
            chars[h]=temp;
            h++;
            if(count>1){
                string ans=to_string(count);
                for(auto it : ans){
                    chars[h]=it;
                    h++;
                }
            }
        }
        return h;
    }
};
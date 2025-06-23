class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>st;
        for(int i=0;i<num.length();i++){
            while(!st.empty() && st.top()>num[i] && k>0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }
        string res;
        while(!st.empty()){
            res+=(char)st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        size_t pos = res.find_first_not_of('0');
        res = (pos == std::string::npos) ? "0" : res.substr(pos);
        
        return res;
    }
};
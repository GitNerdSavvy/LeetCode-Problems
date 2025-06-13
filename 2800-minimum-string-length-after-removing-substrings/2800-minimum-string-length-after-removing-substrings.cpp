class Solution {
public:
    int minLength(string s) {
        stack<char>st;
        for(char ch : s){
            if(!st.empty()){
                if ((st.top() == 'A' && ch == 'B') || (st.top() == 'C' && ch == 'D')){
                    st.pop();
                }else{
                    st.push(ch);
                }
            }else{
                st.push(ch);
            }
        }
        return st.size();
    }
};
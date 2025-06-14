class Solution {
public:
    int eval(int a, int b, string c){
        if(c=="+") return a+b;
        if(c=="-") return a-b;
        if(c=="*") return a*b;
        return a/b;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(string &it : tokens){
            if(it=="+" || it=="-" || it=="*" || it=="/"){
                int a=st.top();
                st.pop();
                int b=st.top(); 
                st.pop();               
                st.push(eval(b,a,it));
            }else{
                st.push(stoi(it));
            }
        }
        return st.top();
    }
};
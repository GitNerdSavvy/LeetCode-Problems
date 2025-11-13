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
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/" ){
                int a =st.top();
                st.pop();
                int b= st.top();
                st.pop();
                string c = tokens[i];
                st.push(eval(b,a,c));
            }else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
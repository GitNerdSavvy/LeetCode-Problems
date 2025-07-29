class Solution {
public:
    int largestInteger(int num) {
       priority_queue<int>even; 
       priority_queue<int> odd;
    string s=to_string(num);
       for(auto it:s){
        if(it&1){
            odd.push(it);
        }else{
            even.push(it);
        }
       }
       for(int i=0;i<s.length();i++){
        if(s[i]&1){
            s[i]=odd.top();
            odd.pop();
        }else{
            s[i]=even.top();
            even.pop();
        }
       }
       return stoi(s);
    }
};
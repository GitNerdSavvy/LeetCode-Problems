class Solution {
public:
    bool isBalanced(string num) {
        int e=0,o=0;
        for(int i=0;i<num.length();i++){
            if(i&1){
                e+=num[i]-'0';
            }else{
                o+=num[i]-'0';
            }
        }
        return (e==o);
    }
};
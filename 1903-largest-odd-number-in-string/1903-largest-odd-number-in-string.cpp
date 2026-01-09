class Solution {
public:
    string largestOddNumber(string num) {
        if (num.back() % 2 == 1)
            return num;
        int i=num.size()-1;
        while(i>=0){
            if((num[i]-'0')&1){
                break;
            }
            i--;
        }
        return i>=0?num.substr(0,i+1):"";
    }
};
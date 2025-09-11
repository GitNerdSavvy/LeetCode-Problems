class Solution {
public:
    string winningPlayer(int x, int y) {
        if(min(x,y/4)%2){
            return "Alice";
        }else{
            return "Bob";
        }
    }
};
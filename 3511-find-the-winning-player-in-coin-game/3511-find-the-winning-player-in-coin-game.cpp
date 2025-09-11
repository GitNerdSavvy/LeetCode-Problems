class Solution {
public:
    string winningPlayer(int x, int y) {
        int cnt=0;
        while(x>0 && y>3){
            cnt++;
            x--;
            y-=4;
        }
        if(cnt%2){
            return "Alice";
        }else{
            return "Bob";
        }
    }
};
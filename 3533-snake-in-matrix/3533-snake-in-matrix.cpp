class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int m[n][n];
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                m[i][j]=c++;
                
            }
        }
        int a=0,b=0;
        for(int i=0;i<commands.size();i++){
            if(commands[i]=="RIGHT"){
                a++;
            }
           else if(commands[i]=="LEFT"){
                a--;
            }
           else if(commands[i]=="UP"){
                b--;
            }
            else if(commands[i]=="DOWN"){
                b++;
            }
            if (a < 0) a = 0;
            if (b < 0) b = 0;
            if (a >= n) a = n - 1;
            if (b >= n) b = n - 1;
            
        }
        return m[b][a];
    }
};
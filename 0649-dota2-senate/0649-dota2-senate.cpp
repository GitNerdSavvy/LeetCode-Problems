class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>q1;
        queue<int>q2;
        queue<int>q3;
        for(int i=0;i<senate.length();i++){
            q1.push(i);
            senate[i]=='R'?q2.push(i):q3.push(i);
        }

        while(q1.size()>1){
            if(senate[q1.front()]=='R'){
                if(q3.empty()) return "Radiant";
                int y=q3.front();
                senate[y]='X';
                q3.pop();
                int x=q2.front();
                q2.pop();
                q2.push(x);
                int z=q1.front();
                q1.pop();
                q1.push(z);
            }else if(senate[q1.front()]=='D'){
                if(q2.empty()) return "Dire";
                int y=q2.front();
                senate[y]='X';
                q2.pop();
                int x=q3.front();
                q3.pop();
                q3.push(x);
                int z=q1.front();
                q1.pop();
                q1.push(z);
            }else{
                q1.pop();
            }
        }
        string res=q2.empty()?"Dire":"Radiant";
        return res;
    }
};
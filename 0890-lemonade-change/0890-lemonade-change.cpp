class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f=0,t=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5) f++;
            if(bills[i]==10) t++;
            if(bills[i]==10){
                if(f==0) return false;
                
                f--;
            }else if(bills[i]==20){
               if(t==0){
                    if(f<3) return false;
                    f-=3;
               }else{
                    if(f==0) return false;
                    f--;
                    t--;
               }
            }
        }
        return true;
    }
};
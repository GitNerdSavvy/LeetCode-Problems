class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x=0;
        for(auto it:operations){
            if(it=="--X" or it=="X--") x--;
            else if(it=="++X" or it=="X++") x++;
        }
        return x;
    }
};
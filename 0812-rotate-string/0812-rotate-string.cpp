class Solution {
public:
    bool rotateString(string s, string goal) {
       int n=s.size();
       for(int i=0;i<n;i++){
        if(s==goal) return 1;
            goal=goal.back()+goal;
            goal.pop_back();

       } 
       return 0;
    }
};
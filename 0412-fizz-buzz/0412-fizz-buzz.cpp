class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string>ans;
        ans.push_back("1");
        for(int j=1;j<n;j++){
            int i=j+1;
            if(i%3==0 && i%5==0){
                ans.push_back("FizzBuzz");
            }else if(i%3==0){
                ans.push_back("Fizz");

            
            }else if(i%5==0){
                ans.push_back("Buzz");

            }else{
                string p=to_string(i);
                ans.push_back(p);
            }
        
    }
        return ans;
  }
};
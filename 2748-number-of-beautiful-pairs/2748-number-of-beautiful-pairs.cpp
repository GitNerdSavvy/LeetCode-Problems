class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(i!=j){
                    int first=(to_string(nums[i])[0]-'0');
                    int last=nums[j]%10;
                    if(__gcd(first,last)==1) cnt++;
                }
            }
        }
        return cnt;
    }
};
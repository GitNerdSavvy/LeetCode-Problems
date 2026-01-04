class Solution {
public:
// bool func(int num,int &curr){
//     int cnt=0;
//     for(int i=1;i<=num;i++){
//         if(num%i==0){
//             curr+=i;
//             cnt++;
//         }
//     }
//     return cnt==4;
// }
#define mx 100005
    vector<int> divi;
    vector<int> sum;
    void divs() {
        divi.assign(mx, 0);
        sum.assign(mx, 0);
        for (int i = 1; i <= 1e5; i++) {
            for (int j = i; j <= 1e5; j += i) {
                divi[j]++;
                sum[j] += i;
            }
        }
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        divs();
        for (auto it : nums) {
            int curr = 0;
            if (divi[it] == 4) {
                ans += sum[it];
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int>ans;
         int v[10] = {0};
    for (int d : digits) v[d]++;
    
        for(int i=100;i<1000;i+=2){
            int x = i;
            int cnt[10] = {0};
            cnt[x % 10]++; x /= 10;
            cnt[x % 10]++; x /= 10;
            cnt[x % 10]++;

        bool valid = true;
        for (int j = 0; j < 10; j++) {
            if (cnt[j] > v[j]) {
                valid = false;
                break;
            }
           
        }
        if (valid) ans.push_back(i);
      }
      return ans;
    }
};
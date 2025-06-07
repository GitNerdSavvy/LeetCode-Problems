class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      vector<int> temp = nums;
      sort(temp.begin(), temp.end(), greater<int>());
       return temp[k - 1];
    }
};
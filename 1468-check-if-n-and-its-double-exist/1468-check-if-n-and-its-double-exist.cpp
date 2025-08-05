class Solution {
public:
    bool check(vector<int>& arr, int m, int i) {
        int l = 0;
        int h = arr.size() - 1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (arr[mid] == m && mid != i)
                return true;
            arr[mid] < m ? l = mid + 1 : h = mid - 1;
        }
        return false;
    }
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++) {
            if (check(arr, 2 * arr[i], i))
                return true;
        }
        return false;
    }
};
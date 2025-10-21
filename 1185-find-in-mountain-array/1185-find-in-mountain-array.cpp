/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray& mountainArr) {
        int n = mountainArr.length();
        // vector<int> arr(n);
        // for (int i = 0; i < n; i++) {
        // arr[i] = mountainArr.get(i);
        // }

        int l = 0, h = n - 1;

        while (l < h) {
            int mid = l + (h - l) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                l = mid + 1;
            else
                h = mid;
        }
        int peak = l;

        l = 0;
        h = peak;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            int val = mountainArr.get(mid);
            if (val == target)
                return mid;
            if (val < target)
                l = mid + 1;
            else
                h = mid - 1;
        }

        l = peak + 1;
        h = n - 1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            int val = mountainArr.get(mid);
            if (val == target)
                return mid;
            if (val > target)
                l = mid + 1;
            else
                h = mid - 1;
        }

        return -1;
    }
};
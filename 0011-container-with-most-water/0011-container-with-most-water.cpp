class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0,h=n-1;
        int maxArea=0;
        while(l<h){
            int curr=min(height[l],height[h])*(h-l);
            maxArea=max(maxArea,curr);
            height[l]<height[h]?l++:h--;
        }
        return maxArea;
    }
};
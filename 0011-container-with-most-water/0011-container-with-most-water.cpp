class Solution {
public:
    int maxArea(vector<int>& height) {
       int maxwtr=0;
       int lp=0,rp=height.size()-1;
       while(lp<rp){
        int w=rp-lp;
        int ht=min(height[lp],height[rp]);
        int currwt=w*ht;
        maxwtr=max(maxwtr,currwt);
        height[lp]<height[rp]?lp++:rp--;
       }
       return maxwtr;
    }
};
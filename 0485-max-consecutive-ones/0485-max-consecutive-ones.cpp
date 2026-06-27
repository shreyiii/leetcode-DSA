class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n =nums.size();
        int c=0;
        int maxc=0;
        for(int i=0;i<n;i++){
            if (nums[i]==1){                
                c+=1;

            }else{
                maxc=max(maxc,c);
                c=0;
            }
        }
        return max(maxc,c);     
    }
};
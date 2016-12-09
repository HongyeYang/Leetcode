class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len=numbers.size();
        vector<int>res;
        for(int i=0;i<len-1;i++){
            int left=i+1,right=len-1;
            while(left<=right){
                int mid=(left+right)/2;
                if(numbers[mid]==target-numbers[i]){
                    res.push_back(i+1);
                    res.push_back(mid+1);
                    return res;
                }
                else if(numbers[mid]>target-numbers[i])right=mid-1;
                else left=mid+1;
            }
        }
        return res;
    }
};

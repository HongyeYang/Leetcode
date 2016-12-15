class Solution {
public:
vector<int>ori,arr;
    Solution(vector<int> nums) {
        ori=nums;
        arr=nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return ori;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int len=ori.size();
        for(int i=0;i<len;i++){
            swap(arr[i],arr[rand()%len]);
        }
        return arr;
    }
};

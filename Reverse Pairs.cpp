class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return merge_and_sort(nums.begin(),nums.end());
    }
    int merge_and_sort(vector<int>::iterator begin,vector<int>::iterator end){
        if(end-begin<2)return 0;
        auto mid=begin+(end-begin)/2;
        int count=merge_and_sort(begin,mid)+merge_and_sort(mid,end);
        for(auto i=begin,j=mid;i!=mid;i++){
            while(j!=end&&*i>2L**j)j++;
            count+=(j-mid);
        }
        inplace_merge(begin,mid,end);
        return count;
    }
};

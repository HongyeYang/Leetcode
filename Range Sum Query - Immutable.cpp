class NumArray {
public:
    vector<int>roc{0};
    NumArray(vector<int> &nums) {
        for(int c:nums)roc.push_back(roc.back()+c);
    }

    int sumRange(int i, int j) {
        return roc[j+1]-roc[i];
    }
};


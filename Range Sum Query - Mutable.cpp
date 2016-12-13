class NumArray {
private:
vector<int>c;
vector<int>e;
int lowbit(int pos){
    return pos&(-pos);
}
void add(int val,int pos){
    while(pos<c.size()){
        c[pos]+=val;
        pos+=lowbit(pos);
    }
    return;
}
int sum(int pos){
    int res=0;
    while(pos>0){
        res+=c[pos];
        pos-=lowbit(pos);
    }
    return res;
}
public:
    NumArray(vector<int> &nums) {
        c.resize(nums.size()+1,0);
        e=nums;
        for(int i=0;i<nums.size();i++){
            add(nums[i],i+1);
        }
    }

    void update(int i, int val) {
        int del=val-e[i];
        e[i]=val;
        add(del,i+1);
        return;
    }

    int sumRange(int i, int j) {
        return sum(j+1)-sum(i);
    }
};

class NumArray {
public:
    vector<int>p;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        p.resize(n);
        p[0] = nums[0];
        for(int i = 1;i<n;i++){
            p[i] = p[i-1]+nums[i];
        }

    }
    int sumRange(int left, int right) {
       if(left == 0) return p[right];
       return (p[right]-p[left-1]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
int singleNumber(vector<int>& nums) {
    int result = 0;
    for(int i = 0; i < nums.size(); i++){
        result = result ^ nums[i];
    }
    return result;
}

int hammingWeight(uint32_t n) {
    int result = 0;
    uint32_t one = 1;
    for(int i = 0; i < 32; i++){
        result += ((one << i) & n) > 0 ? 1 : 0;
    }
    return result;
}

bool isPowerOfTwo(int n) {
    if(n<=0)return false;
    return (n & (~(n-1))) == n;
}

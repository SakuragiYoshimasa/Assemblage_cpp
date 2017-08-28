int firstBadVersion(int n) {
    int lower = 1, upper = n, mid;
    while(lower < upper) {
        mid = lower + (upper - lower) / 2;
        if(!isBadVersion(mid)) lower = mid + 1;   /* Only one call to API */
        else upper = mid;
    }
    return lower;   /* Because there will alway be a bad version, return lower here */
}

int searchInsert(vector<int>& nums, int target) {
    int lower = 0, upper = nums.size(), mid;
    while(lower < upper) {
        mid = lower + (upper - lower) / 2;

        if(nums[mid] == target) return mid;
        if(nums[mid] < target) lower = mid + 1;   /* Only one call to API */
        else upper = mid;
    }
    return lower;
}

vector<int> searchRange(vector<int>& nums, int target) {

    if(nums.size() == 0) return *new vector<int>(2, -1);

    int lower = 0, upper = nums.size() - 1;
    int mid;
    while(lower < upper) {
        mid = lower + (upper - lower) / 2;

        if(nums[mid] == target) {
            lower = mid; break;
        }
        if(nums[mid] < target) lower = mid + 1;   /* Only one call to API */
        else upper = mid;
    }

    if(nums[lower] != target) return *new vector<int>(2, -1);

    deque<int> result;
    result.push_back(lower);

    cout << lower << endl;

    while(1){
        if(result.front() - 1 >= 0  && nums[result.front() - 1] == target) {
            result.push_front(result.front() - 1);
        }else{
            break;
        }
    }

    while(1){
        if(result.back() + 1 < nums.size()  && nums[result.back() + 1] == target) {
            result.push_back(result.back() + 1);
        }else{
            break;
        }
    }

    vector<int> vec_res;
    vec_res.push_back(result.front());
    vec_res.push_back(result.back());

    return vec_res;
}


bool isPerfectSquare(int num) {
    long long lower = 0, upper = num, mid;
    while(lower < upper) {
        cout << lower << "," << mid << ","<< upper << endl;
        mid = lower + (upper - lower) / 2;

        if(mid * mid == num) return true;
        if(mid * mid < num){
            lower = mid + 1;
        }else{
            upper = mid;
        }
    }
    cout << lower << "," << upper << endl;

    if(lower * lower == num) return true;


    return false;
}

TreeNode *sortedArrayToBST(vector<int> &num) {
    if(num.size() == 0) return NULL;
    if(num.size() == 1)
    {
        return new TreeNode(num[0]);
    }
    
    int middle = num.size()/2;
    TreeNode* root = new TreeNode(num[middle]);
    
    vector<int> leftInts(num.begin(), num.begin()+middle);
    vector<int> rightInts(num.begin()+middle+1, num.end());
    
    root->left = sortedArrayToBST(leftInts);
    root->right = sortedArrayToBST(rightInts);
    
    return root;
}

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1)
            return;
        auto iter = nums.end()-1;
        while(iter != nums.begin())
        {
            if(*iter<=*(iter-1))
                --iter;
            else
                break;
        }
        auto checkpoint = iter;
        if(iter != nums.begin())
            iter = iter - 1;
        auto iter2 = iter+1;
        while(iter2 != nums.end() && *iter2 > *iter )
        {
            ++iter2;
        }
        --iter2;

        swap(*iter,*iter2);
        reverse(checkpoint,nums.end());
        return;
    }
};
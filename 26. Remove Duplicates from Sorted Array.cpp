class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int totalLength = nums.size();
        int repeat = 0;
        if(totalLength == 0)
            return 0;
        for(auto elem = nums.begin()+1; elem!=nums.end();)
        {
            if(*elem == *(elem - 1))
            {
                repeat += 1;
                elem = nums.erase(elem);
            }
            else
            {
                elem++;
            }
        }
        return totalLength - repeat;
    }
};
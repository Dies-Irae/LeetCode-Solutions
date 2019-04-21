class Solution {
public:
int numDecodings(string s) {
	int ans = 1;
	int DecodingNums[2] = { 1,1 };
    
	if (s.size() == 0 or s[0] == '0')
		return 0;
    string tmp = "  ";

	for (auto iter = s.begin() + 1; iter != s.end(); iter++)
	{
		DecodingNums[0] = DecodingNums[1];
		DecodingNums[1] = ans;
		tmp[0] = *(iter - 1);
		tmp[1] = *iter;

		if (*iter == '0')
		{
			if (*(iter - 1) == '0' or *(iter - 1) > '2')
				return 0;
			ans = DecodingNums[0];
		}
		else if ("1" <tmp  && tmp < "27")
		{
			ans = DecodingNums[0] + DecodingNums[1];
		}
		else
		{
			ans = DecodingNums[1];
		}
	}
	return ans;
}
};
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> ans;
		if (words.size() == 0 || s.size() == 0)
		{
			return ans;
		}

		int wordSize = words[0].size();
		int windowSize = words.size() * words[0].size();
		if (windowSize > s.size())
			return ans;
		map<string, int> wordRemain;
		map<string, int> wordRemainCopy;
		auto frontPtr = s.begin(), rearPtr = frontPtr + windowSize - 1;
		for (auto iter = words.begin(); iter != words.end(); iter++)
		{
			if (wordRemain.find(*iter) == wordRemain.end())
				wordRemain[*iter] = 1;
			else
				wordRemain[*iter] += 1;
		}
		wordRemainCopy = wordRemain;
		while (rearPtr != s.end())
		{
			//cout<<"Sentence:" <<string(frontPtr, rearPtr+1)<< endl;
			for (auto wordPtr = frontPtr + wordSize-1; wordPtr <= rearPtr; wordPtr += wordSize)
			{
				string currentWord = string(wordPtr +1 - wordSize, wordPtr+1);
				//cout << "Word:" << currentWord << endl;
				if (wordRemain.find(currentWord) != wordRemain.end())
				{
					if (wordRemain[currentWord]>1)
						wordRemain[currentWord] -= 1;
					else
						wordRemain.erase(currentWord);
				}
				else
					break;
				if (wordRemain.size() == 0)
					ans.push_back(frontPtr - s.begin());
				if (wordPtr == rearPtr)
					break;
			}

			frontPtr += 1;
			rearPtr += 1;
			wordRemain = wordRemainCopy;
		}
		return ans;
        
    }
};
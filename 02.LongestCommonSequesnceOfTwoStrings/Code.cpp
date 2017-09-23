#include <iostream>
#include <string>
#include <vector>

using namespace std;

void PrintLonestCommonSequence(string iRefString, string iCompString)
{
	//Initialize and create dptable.
	vector<unsigned int> dpTable;
	for (unsigned int i = 0; i < iRefString.length(); i++) 
	{
		dpTable.push_back(0);
	}

	unsigned int lastIndex = 0;
	for (unsigned int i = 0; i < iCompString.length(); i++) 
	{
		char ch = iCompString[i];
		bool backTrackFlag = true;
		for (unsigned int j = lastIndex; j < iRefString.length(); j++)
		{
			if (ch == iRefString[j]) 
			{
				unsigned int maxSubStrCount = dpTable[lastIndex] + 1;
				if (maxSubStrCount > dpTable[j]) 
				{
					dpTable[j] = maxSubStrCount;
					lastIndex = j;
				}
				backTrackFlag = false;
				break;
			}
		}

		if (backTrackFlag) 
		{
			unsigned int tempLastIndex = lastIndex;
			if (tempLastIndex == iRefString.length())
				tempLastIndex--;

			while (tempLastIndex > 0) 
			{
				if (ch == iRefString[tempLastIndex])
				{
					for (int i = tempLastIndex; i >= 0; i--) 
					{
						if (dpTable[i] > 0) 
						{
							lastIndex = i;
							break;
						}
					}

					unsigned int maxSubStrCount = dpTable[lastIndex] + 1;
					if (maxSubStrCount > dpTable[tempLastIndex])
					{
						dpTable[tempLastIndex] = maxSubStrCount;
						lastIndex = tempLastIndex;
					}
				}
				tempLastIndex--;
			}
		}
	}

	vector<char> output;
	unsigned int lastMaxCount = 0;
	for (int i = iRefString.length() - 1; i >= 0; i--)
	{
		if ((dpTable[i] > 0) && ((lastMaxCount - 1) == dpTable[i] || lastMaxCount == 0))
		{
			lastMaxCount = dpTable[i];
			output.push_back(iRefString[i]);
		}
	}

	for (int i = output.size() - 1; i >= 0; i--)
	{
		cout << output[i];
	}
}

int main(void) 
{
	string s1, s2;
	cin >> s1 >> s2;

	PrintLonestCommonSequence(s1, s2);
	
	cout << endl;
	system("pause");
	return 0;
}

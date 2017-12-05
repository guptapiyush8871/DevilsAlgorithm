/*
Logic :
	if combination is possible
		dp[i] = dp[i-2] + dp[i-1]
	else
		dp[i] = dp[i-1]

	Handle the zero by checking combination of the next number with the number previous to the first zero.
	10001 : {11}, this case is being handled here.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsCombinationPossible(string iInputData, int iPrevIndex, int iCurrentIndex)
{
	if ('1' == iInputData[iPrevIndex])
		return true;

	else if ('2' == iInputData[iPrevIndex] && '6' - iInputData[iCurrentIndex] >= 0)
		return true;

	return false;
}

int PossibleDecryption(string iInputData)
{
	int dataLength = iInputData.length();
	vector<int> dpTable;

	int prevIndex = -1;
	for (int i = 0; i < dataLength; i++) 
	{
		if (-1 == prevIndex) 
		{
			dpTable.push_back(1);
			prevIndex = i;
		}
		else 
		{
			int combinationCount = 0;
			if (IsCombinationPossible(iInputData, prevIndex, i)) 
			{
				if ('0' == iInputData[prevIndex + 1] && (i - prevIndex) > 1)
					combinationCount = dpTable[prevIndex +1] + dpTable[prevIndex];
				else
					combinationCount = (prevIndex > 0 ? dpTable[prevIndex - 1] : 1) + dpTable[prevIndex];
			}
			else
				combinationCount = dpTable[prevIndex];
			
			dpTable.push_back(combinationCount);
			
			if ('0' != iInputData[i]) 
			{
				prevIndex = i;
			}
			else 
			{
				while ('0' == iInputData[i])
					i++;
				i--;
			}
		}
	}
		
	return dpTable.back();
}

int main(void) 
{
	string inputString;

	cin >> inputString;

	int possibleDecryption = PossibleDecryption(inputString);
		
	cout << possibleDecryption << endl;

	system("pause");
	return 0;
}

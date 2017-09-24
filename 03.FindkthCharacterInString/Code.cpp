#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

static vector<string> cache;

void InitCache(unsigned int iCacheSize)
{
	for (unsigned int i = 0; i <= iCacheSize; i++) 
	{
		cache.push_back("0");
	}
}

string ConvertIntoBinary(unsigned short int iNum) 
{
	if (0 == iNum)
		return "0";

	string binary = "";
	unsigned short int tempNum = iNum;
	int numBits = 0;
	while (iNum >= pow(2, numBits)) 
	{
		binary += to_string((tempNum & 0x1));
		tempNum >>= 1;
		numBits++;
	}

	return binary;
}

string XORString(string iString) 
{
	unsigned int strLength = iString.length();
	string xorString = "";
	for (unsigned int i = 0; i < strLength; i++)
	{
		if (iString[i] == '0')
			xorString += "1";
		else if (iString[i] == '1')
			xorString += "0";
	}
	return xorString;
}

unsigned short int ProbeCache(unsigned short int iIteration) 
{
	for (int i = iIteration; i > 0; i--) 
	{
		if (cache[i].length() != 1)
			return i;
	}
	return 0;
}

void GenerateNthItrationReplacement(unsigned short int iIteration, string& o0thReplaceString, string& o1stReplaceString, unsigned int& oReplaceStrLen) 
{
	if (cache[iIteration].length() == 1) 
	{
		unsigned short int tempItration = ProbeCache(iIteration);
		o0thReplaceString = cache[tempItration];
		tempItration++;
		while (tempItration <= iIteration)
		{
			o0thReplaceString += XORString(o0thReplaceString);
			cache[tempItration] = o0thReplaceString;
			tempItration++;
		}
	}

	o0thReplaceString = cache[iIteration];
	o1stReplaceString = XORString(o0thReplaceString);
	oReplaceStrLen = o0thReplaceString.length();
}

unsigned int CalculateReplacementIndex(unsigned int iKthChar, unsigned int iReplaceStrLen)
{
	int i = 1;
	while (iKthChar > iReplaceStrLen*i)
		i++;
	return i;
}

void PrintKthChar(unsigned short int iNum, unsigned int iKthChar, unsigned short int iIteration) 
{
	string binaryData = ConvertIntoBinary(iNum);
	string zeroStr = "";
	string firstStr = "";
	unsigned int len = 0;
	GenerateNthItrationReplacement(iIteration, zeroStr, firstStr, len);
	unsigned int replaceIndex = CalculateReplacementIndex(iKthChar, len);
	string finalString = "\0";
	for (unsigned int i = 0; i < replaceIndex; i++) 
	{
		if (binaryData[i] == '0') 
		{
			std::reverse(zeroStr.begin(), zeroStr.end());
			finalString += zeroStr;
		}
		else if (binaryData[i] == '1') 
		{
			std::reverse(firstStr.begin(), firstStr.end());
			finalString += firstStr;
		}
	}
	
	cout << finalString[iKthChar - 1];
}

int main(void) 
{
	unsigned short int T = 0;
	cin >> T;

	InitCache(10);

	while (T) 
	{
		unsigned short int m;
		cin >> m;
	
		unsigned int k = 0;
		cin >> k;
	
		unsigned short int n;
		cin >> n;

		PrintKthChar(m, k, n);
		cout << endl;

		T--;
	}

	system("pause");
	return 0;
}

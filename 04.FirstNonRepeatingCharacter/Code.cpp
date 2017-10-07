#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(void) 
{
	unsigned int T = 0;
	unsigned int N = 0;
	cin >> T;

	while (T) 
	{
		char inputChar;
		unsigned int alphabate[26] = { 0 };
		queue<char> stream;
		string output = "";
		cin >> N;
		
		for (unsigned int i = 0; i < N; i++) 
		{
			cin >> inputChar;
			alphabate[inputChar - 'a']++;

			if (alphabate[inputChar - 'a'] < 2) 
			{
				stream.push(inputChar);
				output = output + stream.front() + " ";
			}
			else 
			{
				while (!stream.empty() && alphabate[stream.front() - 'a'] > 1)
				{
					stream.pop();
				}

				if (stream.empty())
					output = output + "-1 ";
				else
					output = output + stream.front() + " ";
			}			
		}

		cout << output << endl;

		T--;
	}

	//system("pause");
	return 0;
}

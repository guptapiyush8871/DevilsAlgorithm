#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
Travel array from the back and push elements into the stack which satisfy the below condition :
arrayData[index] > stack.top();

Then Print the elements of stack. It contains the star elements. Here, top of stack contains the possible super star ekement.

For super star element, check for its duplication as well.
*/

void PrintStarAndSuperstarElem(vector<unsigned int> iData) 
{
	unsigned int size = iData.size();
	stack<unsigned int> st;
	st.push(iData[size - 1]);

	for (int i = size - 2; i >= 0; i--) 
	{
		if (iData[i] > st.top()) 
		{
			st.push(iData[i]);
		}
	}

	unsigned int superElem = st.top();
	while (!st.empty()) 
	{
		cout << st.top() << " ";
		st.pop();
	}
	
	unsigned int superElemCont = 0;
	for (int i = 0; i < size; i++) 
	{
		if (iData[i] == superElem) 
		{
			superElemCont++;
			if (superElemCont > 1)
				break;
		}
	}

	cout << endl;
	if (superElemCont == 1)
		cout << superElem;
	else
		cout << -1;
}

int main(void) 
{
	unsigned int T = 0;
	cin >> T;
		
	while (T) 
	{
		unsigned int N = 0;
		cin >> N;

		unsigned int inputData = 0;
		vector<unsigned int> data;
		for (unsigned int i = 0; i < N; i++) 
		{
			cin >> inputData;
			data.push_back(inputData);
		}
		PrintStarAndSuperstarElem(data);
		cout << endl;

		T--;
	}
	
	return 0;
}

/*
Logic :
	* If A knows B, then A can’t be celebrity. Discard A, and B may be celebrity.
	* If A doesn’t know B, then B can’t be celebrity. Discard B, and A may be celebrity.
	* Repeat above two steps till we left with only one person.
	* Ensure the remained person is celebrity. (Why do we need this step?)

Algorithm :
	1. Push all the celebrities into a stack.
	2. Pop off top two persons from the stack, discard one person based on return status of HaveAcquaintance(A, B).
	3. Push the remained person onto stack.
	4. Repeat step 2 and 3 until only one person remains in the stack.
	5. Check the remained person in stack doesn’t have acquaintance with anyone else.
*/

#include <iostream>
#include <stack>

using namespace std;

#define MATRIX_SIZE 4

//True, if person1 knows person2.
bool Knows(bool (*iMat)[MATRIX_SIZE], int iPerson1, int iPerson2)
{
	return iMat[iPerson1][iPerson2];
}

int FindCelebrity(bool (*iMat)[MATRIX_SIZE], int iNumPerson) 
{
	stack<int> celebStack;

	for (int i = 0; i < MATRIX_SIZE; i++) 
	{
		celebStack.push(i);
	}

	while (celebStack.size() > 1) 
	{
		int person1 = celebStack.top();
		celebStack.pop();

		int person2 = celebStack.top();
		celebStack.pop();
				
		if (Knows(iMat, person1, person2)) 
		{
			celebStack.push(person2);
		}
		else 
		{
			celebStack.push(person1);
		}
	}

	int celeb = celebStack.top();
	celebStack.pop();

	for (int i = 0; i < MATRIX_SIZE; i++) 
	{
		if (i != celeb && !(Knows(iMat, i, celeb) && !Knows(iMat, celeb, i)))
		{
			return -1;
		}
	}

	return celeb;
}

int main(void) 
{
	// Person with 2 is celebrity
	bool  person[MATRIX_SIZE][MATRIX_SIZE] = { { 0, 0, 1, 0 },
	{ 0, 0, 1, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 1, 0 } };

	int celeb = FindCelebrity(person, MATRIX_SIZE);

	if (-1 == celeb)
		cout << "Celebrity is not present." << endl;
	else
		cout << "Celebrity is : " << celeb << endl;
		
	system("pause");
	return 0;
}

#include <iostream>
#include "myfunctions.h"
#include <windows.h>

using namespace std;

int main()
{	
	srand(NULL);
	
	//declaration of array sizes
	const int SIZE = 200;
	const int arraySize = 25;
	int arr1Size = 0;
	int arr2Size = 0;
	int answerSize = 0;
	
	//declaration of the arrrays
	char userInput[SIZE];
	char response[SIZE];
	int opArray1[arraySize] = {};
	int opArray2[arraySize] = {};
	int answer[arraySize] = {};
	
	//declaration of required flags
	bool operand1Found = false;
	bool operand2Found = false;
	
	//function call to start Eliza
	ElizaController(userInput,response,opArray1,opArray2,answer,SIZE,arraySize,arr1Size,arr2Size,answerSize,operand1Found,operand2Found);

	return 0;
}
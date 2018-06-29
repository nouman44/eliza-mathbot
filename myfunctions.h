#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

//this function searches the operator in the input string from user
//then it returns the found operator as a char
//there a a total of 6 operators it can search for
char IdentifyOperator(char userInput[]);


//this function finds the operands for calculation in the input string from user
//it can only find the numeric operands in the input
void findOperands(char userInput[],int opArray1[],int opArray2[],int &arr1Size,int &arr2Size,char operatorType,bool &operand1Found,bool &operand2Found);


//this function finds the digits expressed in words
//then it returns the numeric value of the found digit
//it also changes the search index to last index of string digit
int convertDigit(char userInput[],int &digit,bool &digitFound,int &index);


//this function find the operands for calculation which are expressed in words
//it calls the convertDigit function to find the numeric digits and get their value
//it divides a single operand into seven sub-parts and then combines them to get a single value
//then it stores the integer values in arrays opArray1 and opArray2
void convertOperands(char userInput[],int opArray1[],int opArray2[],int &arr1Size,int &arr2Size,char operatorType,bool &operand1Found,bool &operand2Found);


//this function makes the arrays equal in size if they are not
//it adds a zero at the start of the array and pushes the rest of the items
//equal sized arrays are essential for logical operations
void equalizeArrays(int opArray1[],int opArray2[],int &arr1Size,int &arr2Size);


//this function takes two arrays as input and calculates the logical AND from their values
//it stores the answer in a separate answer array
void computeAND(int opArray1[],int opArray2[],int &arr1Size,int &arr2Size,int answer[],int &answerSize,bool &logical);


//this function takes two arrays as input and calculates the logical OR from their values
//it stores the answer in a separate answer array
void computeOR(int opArray1[],int opArray2[],int &arr1Size,int &arr2Size,int answer[],int &answerSize,bool &logical);


//this function takes two arrays as input and calculates the logical XOR from their values
//it stores the answer in a separate answer array
void computeXOR(int opArray1[],int opArray2[],int &arr1Size,int &arr2Size,int answer[],int &answerSize,bool &logical);


//this function takes a single array and calculates the logical NOT from its values
//it stores the answer in a separate answer array
void computeNOT(int opArray1[],int &arr1Size,int answer[],int &answerSize,bool &logical);


//this function takes a single array as input and calculates the binary value from it
//it stores the answer in a separate answer array
void convertToBinary(int opArray1[],int &arr1Size,int answer[],int &answerSize);


//this function takes a single array as input and calcultes the decimal value from it
//it stores the answer in a separate answer array
void convertToDecimal(int opArray1[],int &arr1Size,int answer[],int &answerSize,bool &logical);


//this function takes a input the arrays and their sizes
//it calls the required calculation function according to the operatorType
void functionCaller(char operatorType,int opArray1[],int opArray2[],int &arr1Size,int &arr2Size,int answer[],int &answerSize,bool &logical);


//this function generates the ouput from Eliza
//if all requirements are met, it generates a random response telling the answer
//if there is a wrong input it generates a random error message
//the repsonses are generated according to the type of calculation
void GenerateResponse(char operatorType,int opArray1[],int opArray2[],int arr1Size,int arr2Size,int answer[],int answerSize,bool operand1Found,bool operand2Found,bool logical);


//this function is the primary function called from the main function
//this function combines and synchronizes all the functions of Eliza
//it calls all the search and calculation functions to get the answer
//it then calls the GenerateResponse function to create an output
void ElizaController(char userInput[],char response[],int opArray1[],int opArray2[],int answer[],int SIZE,int arraySize,int arr1Size,int arr2Size,int answerSize,bool operand1Found,bool operand2Found);

#endif
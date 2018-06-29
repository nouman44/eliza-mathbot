#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

#include "myfunctions.h"


//this function searches the operator in the input string from user
//then it returns the found operator as a char
//there a a total of 6 operators it can search for
char IdentifyOperator(char userInput[])
{
	int i,j,index;
	char operatorType = NULL;
	bool operatorFound = false;
	bool matchFound = false;
	const int size = 10;
	
	//declaration of arrays
	char bit1[size] = "BIT";
	char bit2[size] = "bit";
	char binary1[size] = "BINARY";
	char binary2[size] = "binary";
	char decimal1[size] = "DECIMAL";
	char decimal2[size] = "decimal";
	
	//loop continues till end of string and until required operator is found
	for(i=1;userInput[i+1]!=NULL && !operatorFound;i++)
	{
		j = 0;
		
		if(userInput[i]=='&')
		{
			operatorType = '&';
			operatorFound = true;
		}
		
		if(userInput[i]=='|')
		{
			operatorType = '|';
			operatorFound = true;
		}
		
		if(userInput[i]=='^')
		{
			operatorType = '^';
			operatorFound = true;
		}
		
		if(userInput[i]=='!')
		{
			operatorType = '!';
			operatorFound = true;
		}
		
		if(userInput[i-1]==' ' && (userInput[i]=='A' || userInput[i]=='a'))
		{
			if(userInput[i+1]=='N' || userInput[i+1]=='n')
			{
				if((userInput[i+2]=='D' || userInput[i+2]=='d') && userInput[i+3]==' ')
				{
					operatorType = '&';
					operatorFound = true;
				}
			}
		}
		
		if(userInput[i-1]==' ' && (userInput[i]=='O' || userInput[i]=='o'))
		{
			if((userInput[i+1]=='R' || userInput[i+1]=='r') && userInput[i+2]==' ')
			{
				operatorType = '|';
				operatorFound = true;
			}
		}
		
		if(userInput[i-1]==' ' && (userInput[i]=='X' || userInput[i]=='x'))
		{
			if(userInput[i+1]=='O' || userInput[i+1]=='o')
			{
				if((userInput[i+2]=='R' || userInput[i+2]=='r') && userInput[i+3]==' ')
				{
					operatorType = '^';
					operatorFound = true;
				}
			}
		}
		
		if(userInput[i-1]==' ' && (userInput[i]=='N' || userInput[i]=='n'))
		{
			if(userInput[i+1]=='O' || userInput[i+1]=='o')
			{
				if((userInput[i+2]=='T' || userInput[i+2]=='t') && userInput[i+3]==' ')
				{
					operatorType = '!';
					operatorFound = true;
				}
			}
		}
		
		if(userInput[i-1]==' ' && (userInput[i]=='B' || userInput[i]=='b'))
		{
			if(userInput[i+1]=='I' || userInput[i+1]=='i')
			{
				if((userInput[i+2]=='T' || userInput[i+2]=='t') && userInput[i+3]==' ')
				{
					operatorType = 'B';
					operatorFound = true;
				}
			}
		}
		
		if(userInput[i]==binary1[j] || userInput[i]==binary2[j])
		{
			index = i;
			matchFound = true;
			
			for(j=0;binary1[j]!=NULL && matchFound;j++)
			{
				if(userInput[index]==binary1[j] || userInput[index]==binary2[j])
					index++;
				else
					matchFound = false;
			}
			
			if(matchFound)
			{
				operatorType = 'B';
				operatorFound = true;
			}
		}
		
		if(userInput[i]==decimal1[j] || userInput[i]==decimal2[j])
		{
			index = i;
			matchFound = true;
			
			for(j=0;decimal1[j]!=NULL && matchFound;j++)
			{
				if(userInput[index]==decimal1[j] || userInput[index]==decimal2[j])
					index++;
				else
					matchFound = false;
			}
			
			if(matchFound)
			{
				operatorType = 'D';
				operatorFound = true;
			}
		}
		
	}
	
	return operatorType;
}


//this function finds the operands for calculation in the input string from user
//it can only find the numeric operands in the input
void findOperands(char userInput[],int opArray1[],int opArray2[],int &arr1Size,int &arr2Size,char operatorType,bool &operand1Found,bool &operand2Found)
{
	int i = 0;
	int j = 0;
	int index;
	
	//loop continues until end of string and first operand is found
	//the position of index is updated according to end of first operand
	while(userInput[i]!=NULL && !operand1Found)
	{
		if(userInput[i]>47 && userInput[i]<58)
		{
			for(j=0;userInput[i]>47 && userInput[i]<58;j++)
			{
				opArray1[j] = userInput[i] - 48;
				arr1Size++; 
				i++;
			}
			index = i;
			operand1Found = true;
		}
		else
			i++;
	}
	
	//only executed if second operand is required for calculation
	if(operatorType=='&' || operatorType=='|' || operatorType=='^')
	{
		i = index;
		
		//loop continues until end of string and second operand is found
		//the position of index is updated according to end of second operand
		while(userInput[i]!=NULL && !operand2Found)
		{
			if(userInput[i]>47 && userInput[i]<58)
			{
				for(j=0;userInput[i]>47 && userInput[i]<58;j++)
				{
					opArray2[j] = userInput[i] - 48;
					arr2Size++; 
					i++;
				}
				operand2Found = true;
			}
			else
				i++;
		}
	}
}


//this function finds the digits expressed in words
//then it returns the numeric value of the found digit
//it also changes the search index to last index of string digit
int convertDigit(char userInput[],int &digit,bool &digitFound,int &index)
{
	const int size = 20;
	int j,marker;
	
	//declaration of char arrays to find the word digits
	char digit0[size] = "zero";
	char digit1[size] = "one";
	char digit2[size] = "two";
	char digit3[size] = "three";
	char digit4[size] = "four";
	char digit5[size] = "five";
	char digit6[size] = "six";
	char digit7[size] = "seven";
	char digit8[size] = "eight";
	char digit9[size] = "nine";
	char digit10[size] = "ten";
	char digit11[size] = "eleven";
	char digit12[size] = "twelve";
	char digit13[size] = "thirteen";
	char digit14[size] = "fourteen";
	char digit15[size] = "fifteen";
	char digit16[size] = "sixteen";
	char digit17[size] = "seventeen";
	char digit18[size] = "eighteen";
	char digit19[size] = "nineteen";
	char digit20[size] = "twenty";
	char digit30[size] = "thirty";
	char digit40[size] = "forty";
	char digit50[size] = "fifty";
	char digit60[size] = "sixty";
	char digit70[size] = "seventy";
	char digit80[size] = "eighty";
	char digit90[size] = "ninety";
	char digit100[size] = "hundred";
	char digit1000[size] = "thousand";
	
	
	//the words in strings are matched to the following cases and this continues until match is found
	//the postiton of index is updated according to end of text digit
	
	if(userInput[index]==digit0[0] && !digitFound)
	{
		marker = index;
		digitFound = true;
		
		for(j=0;digit0[j]!=NULL && digitFound;j++)
		{
			if(userInput[marker]==digit0[j])
				marker++;
			else
				digitFound = false;
		}
		
		if(digitFound)
		{
			digit = 0;
			index = marker;
		}
	}
	
	if(userInput[index]==digit1[0] && !digitFound)
	{
		marker = index;
		digitFound = true;
		
		for(j=0;digit1[j]!=NULL && digitFound;j++)
		{
			if(userInput[marker]==digit1[j])
				marker++;
			else
				digitFound = false;
		}
		
		if(digitFound)
		{
			digit = 1;
			index = marker;
		}
	}
	
	if(userInput[index]==digit2[0] && !digitFound)
	{
		marker = index;
		digitFound = true;
		
		for(j=0;digit2[j]!=NULL && digitFound;j++)
		{
			if(userInput[marker]==digit2[j])
				marker++;
			else
				digitFound = false;
		}
		
		if(digitFound)
		{
			digit = 2;
			index = marker;
		}
	}
	
	if(userInput[index]==digit3[0] && !digitFound)
	{
		marker = index;
		digitFound = true;
		
		for(j=0;digit3[j]!=NULL && digitFound;j++)
		{
			if(userInput[marker]==digit3[j])
				marker++;
			else
				digitFound = false;
		}
		
		if(digitFound)
		{
			digit = 3;
			index = marker;
		}
	}
	
	if(userInput[index]==digit14[0] && !digitFound)
	{
		marker = index;
		digitFound = true;
		
		for(j=0;digit14[j]!=NULL && digitFound;j++)
		{
			if(userInput[marker]==digit14[j])
				marker++;
			else
				digitFound = false;
		}
		
		if(digitFound)
		{
			digit = 14;
			index = marker;
		}
	}
	
	if(userInput[index]==digit4[0] && !digitFound)
	{
		marker = index;
		digitFound = true;
		
		for(j=0;digit4[j]!=NULL && digitFound;j++)
		{
			if(userInput[marker]==digit4[j])
				marker++;
			else
				digitFound = false;
		}
		
		if(digitFound)
		{
			digit = 4;
			index = marker;
		}
	}
	
	if(userInput[index]==digit5[0] && !digitFound)
	{
		marker = index;
		digitFound = true;
		
		for(j=0;digit5[j]!=NULL && digitFound;j++)
		{
			if(userInput[marker]==digit5[j])
				marker++;
			else
				digitFound = false;
		}
		
		if(digitFound)
		{
			digit = 5;
			index = marker;
		}
	}
	
	if(userInput[index]==digit16[0] && !digitFound)
	{
		marker = index;
		digitFound = true;
		
		for(j=0;digit16[j]!=NULL && digitFound;j++)
		{
			if(userInput[marker]==digit16[j])
				marker++;
			else
				digitFound = false;
		}
		
		if(digitFound)
		{
			digit = 16;
			index = marker;
		}
	}
	
	if(userInput[index]==digit60[0] && !digitFound)
	{
		marker = index;
		digitFound = true;
		
		for(j=0;digit60[j]!=NULL && digitFound;j++)
		{
			if(userInput[marker]==digit60[j])
				marker++;
			else
				digitFound = false;
		}
		
		if(digitFound)
		{
			digit = 60;
			index = marker;
		}
	}
	
	if(userInput[index]==digit6[0] && !digitFound)
	{
		marker = index;
		digitFound = true;
		
		for(j=0;digit6[j]!=NULL && digitFound;j++)
		{
			if(userInput[marker]==digit6[j])
				marker++;
			else
				digitFound = false;
		}
		
		if(digitFound)
		{
			digit = 6;
			index = marker;
		}
	}
	
	if(userInput[index]==digit17[0] && !digitFound)
	{
		marker = index;
		digitFound = true;
		
		for(j=0;digit17[j]!=NULL && digitFound;j++)
		{
			if(userInput[marker]==digit17[j])
				marker++;
			else
				digitFound = false;
		}
		
		if(digitFound)
		{
			digit = 17;
			index = marker;
		}
	}
	
	if(userInput[index]==digit70[0] && !digitFound)
	{
		marker = index;
		digitFound = true;
		
		for(j=0;digit70[j]!=NULL && digitFound;j++)
		{
			if(userInput[marker]==digit70[j])
				marker++;
			else
				digitFound = false;
		}
		
		if(digitFound)
		{
			digit = 70;
			index = marker;
		}
	}
	
	if(userInput[index]==digit7[0] && !digitFound)
	{
		marker = index;
		digitFound = true;
		
		for(j=0;digit7[j]!=NULL && digitFound;j++)
		{
			if(userInput[marker]==digit7[j])
				marker++;
			else
				digitFound = false;
		}
		
		if(digitFound)
		{
			digit = 7;
			index = marker;
		}
	}
	
	if(userInput[index]==digit18[0] && !digitFound)
	{
		marker = index;
		digitFound = true;
		
		for(j=0;digit18[j]!=NULL && digitFound;j++)
		{
			if(userInput[marker]==digit18[j])
				marker++;
			else
				digitFound = false;
		}
		
		if(digitFound)
		{
			digit = 18;
			index = marker;
		}
	}
	
	if(userInput[index]==digit80[0] && !digitFound)
	{
		marker = index;
		digitFound = true;
		
		for(j=0;digit80[j]!=NULL && digitFound;j++)
		{
			if(userInput[marker]==digit80[j])
				marker++;
			else
				digitFound = false;
		}
		
		if(digitFound)
		{
			digit = 80;
			index = marker;
		}
	}
	
	if(userInput[index]==digit8[0] && !digitFound)
	{
		marker = index;
		digitFound = true;
		
		for(j=0;digit8[j]!=NULL && digitFound;j++)
		{
			if(userInput[marker]==digit8[j])
				marker++;
			else
				digitFound = false;
		}
		
		if(digitFound)
		{
			digit = 8;
			index = marker;
		}
	}
	
	if(userInput[index]==digit19[0] && !digitFound)
	{
		marker = index;
		digitFound = true;
		
		for(j=0;digit19[j]!=NULL && digitFound;j++)
		{
			if(userInput[marker]==digit19[j])
				marker++;
			else
				digitFound = false;
		}
		
		if(digitFound)
		{
			digit = 19;
			index = marker;
		}
	}
	
	if(userInput[index]==digit90[0] && !digitFound)
	{
		marker = index;
		digitFound = true;
		
		for(j=0;digit90[j]!=NULL && digitFound;j++)
		{
			if(userInput[marker]==digit90[j])
				marker++;
			else
				digitFound = false;
		}
		
		if(digitFound)
		{
			digit = 90;
			index = marker;
		}
	}
	
	if(userInput[index]==digit9[0] && !digitFound)
	{
		marker = index;
		digitFound = true;
		
		for(j=0;digit9[j]!=NULL && digitFound;j++)
		{
			if(userInput[marker]==digit9[j])
				marker++;
			else
				digitFound = false;
		}
		
		if(digitFound)
		{
			digit = 9;
			index = marker;
		}
	}
	
	if(userInput[index]==digit10[0] && !digitFound)
	{
		marker = index;
		digitFound = true;
		
		for(j=0;digit10[j]!=NULL && digitFound;j++)
		{
			if(userInput[marker]==digit10[j])
				marker++;
			else
				digitFound = false;
		}
		
		if(digitFound)
		{
			digit = 10;
			index = marker;
		}
	}
	
	if(userInput[index]==digit11[0] && !digitFound)
	{
		marker = index;
		digitFound = true;
		
		for(j=0;digit11[j]!=NULL && digitFound;j++)
		{
			if(userInput[marker]==digit11[j])
				marker++;
			else
				digitFound = false;
		}
		
		if(digitFound)
		{
			digit = 11;
			index = marker;
		}
	}
	
	if(userInput[index]==digit12[0] && !digitFound)
	{
		marker = index;
		digitFound = true;
		
		for(j=0;digit12[j]!=NULL && digitFound;j++)
		{
			if(userInput[marker]==digit12[j])
				marker++;
			else
				digitFound = false;
		}
		
		if(digitFound)
		{
			digit = 12;
			index = marker;
		}
	}
	
	if(userInput[index]==digit13[0] && !digitFound)
	{
		marker = index;
		digitFound = true;
		
		for(j=0;digit13[j]!=NULL && digitFound;j++)
		{
			if(userInput[marker]==digit13[j])
				marker++;
			else
				digitFound = false;
		}
		
		if(digitFound)
		{
			digit = 13;
			index = marker;
		}
	}
	
	if(userInput[index]==digit15[0] && !digitFound)
	{
		marker = index;
		digitFound = true;
		
		for(j=0;digit15[j]!=NULL && digitFound;j++)
		{
			if(userInput[marker]==digit15[j])
				marker++;
			else
				digitFound = false;
		}
		
		if(digitFound)
		{
			digit = 15;
			index = marker;
		}
	}
	
	if(userInput[index]==digit20[0] && !digitFound)
	{
		marker = index;
		digitFound = true;
		
		for(j=0;digit20[j]!=NULL && digitFound;j++)
		{
			if(userInput[marker]==digit20[j])
				marker++;
			else
				digitFound = false;
		}
		
		if(digitFound)
		{
			digit = 20;
			index = marker;
		}
	}
	
	if(userInput[index]==digit30[0] && !digitFound)
	{
		marker = index;
		digitFound = true;
		
		for(j=0;digit30[j]!=NULL && digitFound;j++)
		{
			if(userInput[marker]==digit30[j])
				marker++;
			else
				digitFound = false;
		}
		
		if(digitFound)
		{
			digit = 30;
			index = marker;
		}
	}
	
	if(userInput[index]==digit40[0] && !digitFound)
	{
		marker = index;
		digitFound = true;
		
		for(j=0;digit40[j]!=NULL && digitFound;j++)
		{
			if(userInput[marker]==digit40[j])
				marker++;
			else
				digitFound = false;
		}
		
		if(digitFound)
		{
			digit = 40;
			index = marker;
		}
	}
	
	if(userInput[index]==digit50[0] && !digitFound)
	{
		marker = index;
		digitFound = true;
		
		for(j=0;digit50[j]!=NULL && digitFound;j++)
		{
			if(userInput[marker]==digit50[j])
				marker++;
			else
				digitFound = false;
		}
		
		if(digitFound)
		{
			digit = 50;
			index = marker;
		}
	}
	
	if(userInput[index]==digit100[0] && !digitFound)
	{
		marker = index;
		digitFound = true;
		
		for(j=0;digit100[j]!=NULL && digitFound;j++)
		{
			if(userInput[marker]==digit100[j])
				marker++;
			else
				digitFound = false;
		}
		
		if(digitFound)
		{
			digit = 100;
			index = marker;
		}
	}
	
	if(userInput[index]==digit1000[0] && !digitFound)
	{
		marker = index;
		digitFound = true;
		
		for(j=0;digit1000[j]!=NULL && digitFound;j++)
		{
			if(userInput[marker]==digit1000[j])
				marker++;
			else
				digitFound = false;
		}
		
		if(digitFound)
		{
			digit = 1000;
			index = marker;
		}
	}

}


//this function find the operands for calculation which are expressed in words
//it calls the convertDigit function to find the numeric digits and get their value
//it divides a single operand into seven sub-parts and then combines them to get a single value
//then it stores the integer values in arrays opArray1 and opArray2
void convertOperands(char userInput[],int opArray1[],int opArray2[],int &arr1Size,int &arr2Size,char operatorType,bool &operand1Found,bool &operand2Found)
{
	int i = 0;
	int j = 0;
	int index = 0;
	int operand1;
	int operand2;
	int n;
	int temp;
	int divider;
	int modulus;
	
	//declaration of sub-parts of first operand
	int firstOp1 = 0;
	int secondOp1 = 0;
	int thirdOp1 = 1;
	int fourthOp1 = 0;
	int fifthOp1 = 1;
	int sixthOp1 = 0;
	int seventhOp1 = 0;
	
	//declaration of sub-parts of second operand
	int firstOp2 = 0;
	int secondOp2 = 0;
	int thirdOp2 = 1;
	int fourthOp2 = 0;
	int fifthOp2 = 1;
	int sixthOp2 = 0;
	int seventhOp2 = 0;
	
	//declaration of flags for searching sub-parts of first operand
	bool firstOp1Found = false;
	bool secondOp1Found = false;
	bool thirdOp1Found = false;
	bool fourthOp1Found = false;
	bool fifthOp1Found = false;
	bool sixthOp1Found = false;
	bool seventhOp1Found = false;
	bool continueSearch = true;
	
	//declaration of flags for searching sub-parts of second operand
	bool firstOp2Found = false;
	bool secondOp2Found = false;
	bool thirdOp2Found = false;
	bool fourthOp2Found = false;
	bool fifthOp2Found = false;
	bool sixthOp2Found = false;
	bool seventhOp2Found = false;
	
	
	//loop continues until end of string and 'AND' is encountered and operand 1 is found
	while(userInput[i]!=NULL && continueSearch && !operand1Found)
	{
		//'AND' to separate the first operand from second operand
		if(userInput[i]=='A' && firstOp1Found)
		{
			if(userInput[i+1]=='N')
			{
				if(userInput[i+2]=='D')
				{
					continueSearch = false;
				}
			}
		}
		
		if(!firstOp1Found)
		{
			convertDigit(userInput,firstOp1,firstOp1Found,i);
			if(userInput[i]=='-' && !secondOp1Found)
			{
				i++;
				convertDigit(userInput,secondOp1,secondOp1Found,i);
			}
		}
		
		if(!thirdOp1Found && continueSearch)
			convertDigit(userInput,thirdOp1,thirdOp1Found,i);
		
		if(!fourthOp1Found && continueSearch)
			convertDigit(userInput,fourthOp1,fourthOp1Found,i);
		
		if(!fifthOp1Found && continueSearch)
			convertDigit(userInput,fifthOp1,fifthOp1Found,i);
		
		if(!sixthOp1Found && continueSearch)
		{
			convertDigit(userInput,sixthOp1,sixthOp1Found,i);
			if(userInput[i]=='-' && !seventhOp1Found)
			{
				i++;
				convertDigit(userInput,seventhOp1,seventhOp1Found,i);
			}
		}
		i++;
	}
	
	//calculation of first operand
	if(firstOp1Found)
		operand1 = ((firstOp1+secondOp1)*thirdOp1) + (fourthOp1*fifthOp1) + (sixthOp1+seventhOp1);
	
	//executed only if second operand is required
	if((operatorType=='&' || operatorType=='|' || operatorType=='^') && !operand2Found)
	{
		//loop continues until end of string
		while(userInput[i]!=NULL)
		{
			if(!firstOp2Found)
			{
				convertDigit(userInput,firstOp2,firstOp2Found,i);
				if(userInput[i]=='-' && !secondOp1Found)
				{
					i++;
					convertDigit(userInput,secondOp2,secondOp2Found,i);
				}
			}
			
			if(!thirdOp2Found)
				convertDigit(userInput,thirdOp2,thirdOp2Found,i);
			
			if(!fourthOp2Found)
				convertDigit(userInput,fourthOp2,fourthOp2Found,i);
			
			if(!fifthOp2Found)
				convertDigit(userInput,fifthOp2,fifthOp2Found,i);
			
			if(!sixthOp2Found)
			{
				convertDigit(userInput,sixthOp2,sixthOp2Found,i);
				if(userInput[i]=='-' && !seventhOp2Found)
				{
					i++;
					convertDigit(userInput,seventhOp2,seventhOp2Found,i);
				}
			}
			i++;
		}
		
		//calculation of second operand
		operand2 = ((firstOp2+secondOp2)*thirdOp2) + (fourthOp2*fifthOp2) + (sixthOp2+seventhOp2);
	}

	//code to transfer the int value of first operand to an int array
	if(firstOp1Found)
	{
		operand1Found = true;
		temp = operand1;
		n=0;
		divider = 1;
		modulus = 10;
		
		while(temp!=0)
		{
			temp = temp / 10;
			n++;
		}
		
		arr1Size = n;
		
		for(i=arr1Size-1;i>=0;i--)
		{
			opArray1[i] = operand1 % modulus;
			opArray1[i] = opArray1[i] / divider;
			
			modulus = modulus *10;
			divider = divider*10;
		}
	}
	
	//code to transfer the int value of second operand to an int array
	if(firstOp2Found)
	{
		operand2Found = true;
		temp = operand2;
		n=0;
		divider = 1;
		modulus = 10;
		
		while(temp!=0)
		{
			temp = temp / 10;
			n++;
		}
		
		arr2Size = n;
		
		for(i=arr2Size-1;i>=0;i--)
		{
			opArray2[i] = operand2 % modulus;
			opArray2[i] = opArray2[i] / divider;
			
			modulus = modulus *10;
			divider = divider*10;
		}
	}
}


//this function makes the arrays equal in size if they are not
//it adds a zero at the start of the array and pushes the rest of the items
//equal sized arrays are essential for logical operations
void equalizeArrays(int opArray1[],int opArray2[],int &arr1Size,int &arr2Size)
{
	int i;
	
	if(arr1Size<arr2Size)
	{
		while(arr1Size!=arr2Size)
		{
			for(i=arr1Size-1;i>=0;i--)
			{
				opArray1[i+1] = opArray1[i];
			}
			opArray1[0] = 0;
			arr1Size++;
		}
	}
	else if(arr1Size>arr2Size)
	{
		while(arr1Size!=arr2Size)
		{
			for(i=arr2Size-1;i>=0;i--)
			{
				opArray2[i+1] = opArray2[i];
			}
			opArray2[0] = 0;
			arr2Size++;
		}
	}
}


//this function takes two arrays as input and calculates the logical AND from their values
//it stores the answer in a separate answer array
void computeAND(int opArray1[],int opArray2[],int &arr1Size,int &arr2Size,int answer[],int &answerSize,bool &logical)
{
	int i;
	
	if(arr1Size!=arr2Size)
		equalizeArrays(opArray1,opArray2,arr1Size,arr2Size);
	
	for(i=0;i<arr1Size && logical;i++)
	{
		if(opArray1[i]==0 && opArray2[i]==0)
		{
			answer[i] = 0;
			answerSize++;
		}
		else if(opArray1[i]==0 && opArray2[i]==1)
		{
			answer[i] = 0;
			answerSize++;
		}
		else if(opArray1[i]==1 && opArray2[i]==0)
		{
			answer[i] = 0;
			answerSize++;
		}
		else if(opArray1[i]==1 && opArray2[i]==1)
		{
			answer[i] = 1;
			answerSize++;
		}
		else
			logical = false;
	}
}


//this function takes two arrays as input and calculates the logical OR from their values
//it stores the answer in a separate answer array
void computeOR(int opArray1[],int opArray2[],int &arr1Size,int &arr2Size,int answer[],int &answerSize,bool &logical)
{
	int i;
	
	if(arr1Size!=arr2Size)
		equalizeArrays(opArray1,opArray2,arr1Size,arr2Size);
	
	for(i=0;i<arr1Size && logical;i++)
	{
		if(opArray1[i]==0 && opArray2[i]==0)
		{
			answer[i] = 0;
			answerSize++;
		}
		else if(opArray1[i]==0 && opArray2[i]==1)
		{
			answer[i] = 1;
			answerSize++;
		}
		else if(opArray1[i]==1 && opArray2[i]==0)
		{
			answer[i] = 1;
			answerSize++;
		}
		else if(opArray1[i]==1 && opArray2[i]==1)
		{
			answer[i] = 1;
			answerSize++;
		}
		else
			logical = false;
	}
}


//this function takes two arrays as input and calculates the logical XOR from their values
//it stores the answer in a separate answer array
void computeXOR(int opArray1[],int opArray2[],int &arr1Size,int &arr2Size,int answer[],int &answerSize,bool &logical)
{
	int i;
	
	if(arr1Size!=arr2Size)
		equalizeArrays(opArray1,opArray2,arr1Size,arr2Size);
	
	for(i=0;i<arr1Size && logical;i++)
	{
		if(opArray1[i]==0 && opArray2[i]==0)
		{
			answer[i] = 0;
			answerSize++;
		}
		else if(opArray1[i]==0 && opArray2[i]==1)
		{
			answer[i] = 1;
			answerSize++;
		}
		else if(opArray1[i]==1 && opArray2[i]==0)
		{
			answer[i] = 1;
			answerSize++;
		}
		else if(opArray1[i]==1 && opArray2[i]==1)
		{
			answer[i] = 0;
			answerSize++;
		}
		else
			logical = false;
	}
}


//this function takes a single array and calculates the logical NOT from its values
//it stores the answer in a separate answer array
void computeNOT(int opArray1[],int &arr1Size,int answer[],int &answerSize,bool &logical)
{
	int i;
	
	for(i=0;i<arr1Size && logical;i++)
	{
		if(opArray1[i]==0)
		{
			answer[i] = 1;
			answerSize++;
		}
		else if(opArray1[i]==1)
		{
			answer[i] = 0;
			answerSize++;
		}
		else
			logical = false;
	}
}


//this function takes a single array as input and calculates the binary value from it
//it stores the answer in a separate answer array
void convertToBinary(int opArray1[],int &arr1Size,int answer[],int &answerSize)
{
	int multiplier = pow(10,(arr1Size-1));
	int dec = 0;
	int remainder;
	int i;
	int n = 2;
	int x = 0;
	
	for(i=0;i<arr1Size;i++)
	{
		dec = dec + (opArray1[i]*multiplier);
		multiplier = multiplier / 10;
	}
	
	while(n<=dec)
	{
		n = n * 2;
		x++;
	}
	
	for(i=x;i>=0;i--)
	{
		remainder = dec % 2;
		answer[i] = remainder;
		answerSize++;
		dec = dec / 2;
	}
}


//this function takes a single array as input and calcultes the decimal value from it
//it stores the answer in a separate answer array
void convertToDecimal(int opArray1[],int &arr1Size,int answer[],int &answerSize,bool &logical)
{
	int multiplier = pow(2,(arr1Size-1));;
	int dec = 0;
	int i;
	
	for(i=0;i<arr1Size && logical;i++)
	{
		if(opArray1[i]==0 || opArray1[i]==1)
		{
			dec = dec + (multiplier*opArray1[i]);
			multiplier = multiplier / 2;
		}
		else
			logical = false;
	}
	
	answer[0] = dec;
	answerSize++;
}


//this function takes a input the arrays and their sizes
//it calls the required calculation function according to the operatorType
void functionCaller(char operatorType,int opArray1[],int opArray2[],int &arr1Size,int &arr2Size,int answer[],int &answerSize,bool &logical)
{
	if(operatorType=='&')
		computeAND(opArray1,opArray2,arr1Size,arr2Size,answer,answerSize,logical);
	else if(operatorType=='|')
		computeOR(opArray1,opArray2,arr1Size,arr2Size,answer,answerSize,logical);
	else if(operatorType=='^')
		computeXOR(opArray1,opArray2,arr1Size,arr2Size,answer,answerSize,logical);
	else if(operatorType=='!')
		computeNOT(opArray1,arr1Size,answer,answerSize,logical);
	else if(operatorType=='B')
		convertToBinary(opArray1,arr1Size,answer,answerSize);
	else if(operatorType=='D')
		convertToDecimal(opArray1,arr1Size,answer,answerSize,logical);
}


//this function generates the ouput from Eliza
//if all requirements are met, it generates a random response telling the answer
//if there is a wrong input it generates a random error message
void GenerateResponse(char operatorType,int opArray1[],int opArray2[],int arr1Size,int arr2Size,int answer[],int answerSize,bool operand1Found,bool operand2Found,bool logical)
{
	//num is used as random number to generate a random response
	int num;
	
	int i;
	
	cout<< "ELIZA: ";
	
	//the repsonses are generated according to the type of calculation
	
	if(operatorType=='&')
	{
		//response for successful calculation
		if(operand1Found && operand2Found && logical)
		{
			num = rand() % 6;	
			
			if(num==0)
			{
				cout<<"The answer is ";
				for(i=0;i<answerSize;i++)
				{
					cout<<answer[i];
				}
			}
			else if(num==1)
			{
				cout<<"The logical AND is ";
				for(i=0;i<answerSize;i++)
				{
					cout<<answer[i];
				}
			}
			else if(num==2)
			{
				cout<<"The required result is ";
				for(i=0;i<answerSize;i++)
				{
					cout<<answer[i];
				}
			}
			else if(num==3)
			{
				for(i=0;i<answerSize;i++)
				{
					cout<<answer[i];
				}
			}
			else if(num==4)
			{
				cout<<"The calculated answer is ";
				for(i=0;i<answerSize;i++)
				{
					cout<<answer[i];
				}
			}
			else if(num==5)
			{
				for(i=0;i<answerSize;i++)
				{
					cout<<answer[i];
				}
				cout<<" is the logical AND";
			}
		}
		//response if the operands were not found
		else if(!operand1Found)
		{
			num = rand() % 3;
			
			if(num==0)
				cout<< "I was unable to find the operands for calculation. Re-enter the question.";
			else if(num==1)
				cout<< "There were no operands in your question. Enter the operands.";
			else if(num==2)
				cout<< "I need two operands to compute the logical AND Please enter them.";
		}
		//response if the second operand was not found
		else if(!operand2Found)
		{
			num = rand() % 3;
			
			if(num==0)
				cout<< "I was unable to find the second operand. Re-enter the question.";
			else if(num==1)
				cout<< "The required second operand is missing. Make sure it is present.";
			else if(num==2)
				cout<< "The calculation requires the second operand. Please enter it too.";
		}
		//response if the input was in values of 0 and 1
		else if(!logical)
		{
			num = rand() % 3;
			
			if(num==0)
				cout<< "Please make sure you only enter 0 and 1 for logical AND.";
			else if(num==1)
				cout<< "Error. Logical AND can only be calculated for 0 and 1.";
			else if(num==2)
				cout<< "I require 0 and 1 values to compute logical AND.";
		}
	}
	else if(operatorType=='|')
	{
		//response for successful calculation
		if(operand1Found && operand2Found && logical)
		{
			num = rand() % 6;	
			
			if(num==0)
			{
				cout<<"The answer is ";
				for(i=0;i<answerSize;i++)
				{
					cout<<answer[i];
				}
			}
			else if(num==1)
			{
				cout<<"The logical OR is ";
				for(i=0;i<answerSize;i++)
				{
					cout<<answer[i];
				}
			}
			else if(num==2)
			{
				cout<<"The required result is ";
				for(i=0;i<answerSize;i++)
				{
					cout<<answer[i];
				}
			}
			else if(num==3)
			{
				for(i=0;i<answerSize;i++)
				{
					cout<<answer[i];
				}
			}
			else if(num==4)
			{
				cout<<"The calculated answer is ";
				for(i=0;i<answerSize;i++)
				{
					cout<<answer[i];
				}
			}
			else if(num==5)
			{
				for(i=0;i<answerSize;i++)
				{
					cout<<answer[i];
				}
				cout<<" is the logical OR";
			}
		}
		//response if the operands were not found
		else if(!operand1Found)
		{
			num = rand() % 3;
			
			if(num==0)
				cout<< "I was unable to find the operands for calculation. Re-enter the question.";
			else if(num==1)
				cout<< "There were no operands in your question. Enter the operands.";
			else if(num==2)
				cout<< "I need two operands to compute the logical OR. Please enter them.";
		}
		//response if the second operand was not found
		else if(!operand2Found)
		{
			num = rand() % 3;
			
			if(num==0)
				cout<< "I was unable to find the second operand. Re-enter the question.";
			else if(num==1)
				cout<< "The required second operand is missing. Make sure it is present.";
			else if(num==2)
				cout<< "The calculation requires the second operand. Please enter it too.";
		}
		//response if the input was in values of 0 and 1
		else if(!logical)
		{
			num = rand() % 3;
			
			if(num==0)
				cout<< "Please make sure you only enter 0 and 1 for logical OR.";
			else if(num==1)
				cout<< "Error. Logical OR can only be calculated for 0 and 1.";
			else if(num==2)
				cout<< "I require 0 and 1 values to compute logical OR.";
		}
	}
	else if(operatorType=='^')
	{
		//response for successful calculation
		if(operand1Found && operand2Found && logical)
		{
			num = rand() % 6;	
			
			if(num==0)
			{
				cout<<"The answer is ";
				for(i=0;i<answerSize;i++)
				{
					cout<<answer[i];
				}
			}
			else if(num==1)
			{
				cout<<"The logical XOR is ";
				for(i=0;i<answerSize;i++)
				{
					cout<<answer[i];
				}
			}
			else if(num==2)
			{
				cout<<"The required result is ";
				for(i=0;i<answerSize;i++)
				{
					cout<<answer[i];
				}
			}
			else if(num==3)
			{
				for(i=0;i<answerSize;i++)
				{
					cout<<answer[i];
				}
			}
			else if(num==4)
			{
				cout<<"The calculated answer is ";
				for(i=0;i<answerSize;i++)
				{
					cout<<answer[i];
				}
			}
			else if(num==5)
			{
				for(i=0;i<answerSize;i++)
				{
					cout<<answer[i];
				}
				cout<<" is the logical XOR";
			}
		}
		//response if the second operand was not found
		else if(!operand1Found)
		{
			num = rand() % 3;
			
			if(num==0)
				cout<< "I was unable to find the operands for calculation. Re-enter the question.";
			else if(num==1)
				cout<< "There were no operands in your question. Enter the operands.";
			else if(num==2)
				cout<< "I need two operands to compute an answer. Please enter them.";
		}
		//response if the second operand was not found
		else if(!operand2Found)
		{
			num = rand() % 3;
			
			if(num==0)
				cout<< "I was unable to find the second operand. Re-enter the question.";
			else if(num==1)
				cout<< "The required second operand is missing. Make sure it is present.";
			else if(num==2)
				cout<< "The calculation requires the second operand. Please enter it too.";
		}
		//response if the input was in values of 0 and 1
		else if(!logical)
		{
			num = rand() % 3;
			
			if(num==0)
				cout<< "Please make sure you only enter 0 and 1 for logical XOR.";
			else if(num==1)
				cout<< "Error. Logical XOR can only be calculated for 0 and 1.";
			else if(num==2)
				cout<< "I require 0 and 1 values to compute logical XOR.";
		}
	}
	else if(operatorType=='!')
	{
		//response for successful calculation
		if(operand1Found && logical)
		{
			num = rand() % 6;	
			
			if(num==0)
			{
				cout<<"The answer is ";
				for(i=0;i<answerSize;i++)
				{
					cout<<answer[i];
				}
			}
			else if(num==1)
			{
				cout<<"The logical NOT is ";
				for(i=0;i<answerSize;i++)
				{
					cout<<answer[i];
				}
			}
			else if(num==2)
			{
				cout<<"The required result is ";
				for(i=0;i<answerSize;i++)
				{
					cout<<answer[i];
				}
			}
			else if(num==3)
			{
				for(i=0;i<answerSize;i++)
				{
					cout<<answer[i];
				}
			}
			else if(num==4)
			{
				cout<<"The computed answer is ";
				for(i=0;i<answerSize;i++)
				{
					cout<<answer[i];
				}
			}
			else if(num==5)
			{
				for(i=0;i<answerSize;i++)
				{
					cout<<answer[i];
				}
				cout<<" is the logical NOT";
			}
		}
		//response if the operand was not found
		else if(!operand1Found)
		{
			num = rand() % 3;
			
			if(num==0)
				cout<< "I was unable to find the operand. Re-enter the question.";
			else if(num==1)
				cout<< "There is no operand in your question. Enter the operand.";
			else if(num==2)
				cout<< "I need an operand to compute an answer. Please enter it.";
		}
		//response if the input was in values of 0 and 1
		else if(!logical)
		{
			num = rand() % 3;
			
			if(num==0)
				cout<< "Please make sure you only enter 0 and 1 for logical OR.";
			else if(num==1)
				cout<< "Error. Logical OR can only be calculated for 0 and 1.";
			else if(num==2)
				cout<< "I require 0 and 1 values to compute logical NOT.";
		}
	}
	else if(operatorType=='B')
	{
		//response for successful calculation
		if(operand1Found)
		{
			num = rand() % 6;	
			
			if(num==0)
			{
				cout<<"The binary value is ";
				for(i=0;i<answerSize;i++)
				{
					cout<<answer[i];
				}
			}
			else if(num==1)
			{
				cout<<"The bit representation is ";
				for(i=0;i<answerSize;i++)
				{
					cout<<answer[i];
				}
			}
			else if(num==2)
			{
				cout<<"The required result is ";
				for(i=0;i<answerSize;i++)
				{
					cout<<answer[i];
				}
			}
			else if(num==3)
			{
				for(i=0;i<answerSize;i++)
				{
					cout<<answer[i];
				}
			}
			else if(num==4)
			{
				cout<<"The computed binary value is ";
				for(i=0;i<answerSize;i++)
				{
					cout<<answer[i];
				}
			}
			else if(num==5)
			{
				for(i=0;i<answerSize;i++)
				{
					cout<<answer[i];
				}
				cout<<" is the value in bits";
			}
		}
		//response if the operand was not found
		else if(!operand1Found)
		{
			num = rand() % 3;
			
			if(num==0)
				cout<< "I was unable to find the decimal value. Re-enter the question.";
			else if(num==1)
				cout<< "There is no value in your question to convert to binary.";
			else if(num==2)
				cout<< "I need an operand to compute a binary value. Please enter it.";
		}
	}
	else if(operatorType=='D')
	{
		//response for successful calculation
		if(operand1Found && logical)
		{
			num = rand() % 6;	
			
			if(num==0)
			{
				cout<<"The decimal value is ";
				for(i=0;i<answerSize;i++)
				{
					cout<<answer[i];
				}
			}
			else if(num==1)
			{
				cout<<"The represenation in decimal is ";
				for(i=0;i<answerSize;i++)
				{
					cout<<answer[i];
				}
			}
			else if(num==2)
			{
				cout<<"The required result is ";
				for(i=0;i<answerSize;i++)
				{
					cout<<answer[i];
				}
			}
			else if(num==3)
			{
				for(i=0;i<answerSize;i++)
				{
					cout<<answer[i];
				}
			}
			else if(num==4)
			{
				cout<<"The computed decimal value is ";
				for(i=0;i<answerSize;i++)
				{
					cout<<answer[i];
				}
			}
			else if(num==5)
			{
				for(i=0;i<answerSize;i++)
				{
					cout<<answer[i];
				}
				cout<<" is the value in decimal";
			}
		}
		//response if the operand was not found
		else if(!operand1Found)
		{
			num = rand() % 3;
			
			if(num==0)
				cout<< "I was unable to find the binary value. Re-enter the question.";
			else if(num==1)
				cout<< "There is no value in your question to convert to decimal.";
			else if(num==2)
				cout<< "I need an operand to compute a decimal value. Please enter it.";
		}
		//response if the input was in values of 0 and 1
		else if(!logical)
		{
			num = rand() % 3;
			
			if(num==0)
				cout<< "Please make sure you only enter a binary number.";
			else if(num==1)
				cout<< "Error. Decimal value can only be calculated for a binary value.";
			else if(num==2)
				cout<< "I require 0 and 1 values to compute the decimal value.";
		}
	}
	//response if the question is not recognized and operator is not found
	else
	{
		num = rand() % 7;
		
		if(num==0)
			cout<< "Please enter a valid question.";
		else if(num==1)
			cout<< "I don't know what you're asking. Ask again.";
		else if(num==2)
			cout<< "The question is not valid. Try asking a valid one.";
		else if(num==3)
			cout<< "I can't understand your question. Try again.";
		else if(num==4)
			cout<< "You asked an incorrect question. Try again.";
		else if(num==5)
			cout<< "I was unable to understand what you're asking. Re-phrase it.";
		else if(num==6)
			cout<< "Please make your question clear and valid.";
	}
	
	cout<<endl;
}


//this function is the primary function called from the main function
//this function combines and synchronizes all the functions of Eliza
//it calls all the search and calculation functions to get the answer
//it then calls the GenerateResponse function to create an output
void ElizaController(char userInput[],char response[],int opArray1[],int opArray2[],int answer[],int SIZE,int arraySize,int arr1Size,int arr2Size,int answerSize,bool operand1Found,bool operand2Found)
{
	bool continueInput = true;
	char operatorType;
	bool logical = true;
	int i;
	
	cout<< "Hello! My name is Eliza. I will answer questions on logical operations and conversions. Whenever you want to stop, type 'end'."<<endl;
	
	//loop continues until 'end' is entered
	while(continueInput)
	{
		cout<<"USER: ";
		cin.getline(userInput,SIZE);
		
		
		for(i=(SIZE-1);i>0;i--)
		{
			userInput[i] = userInput[i-1];
		}
		
		userInput[0] = ' ';
		
		if((userInput[1]=='E' || userInput[1]=='e')  && (userInput[2]=='N' || userInput[2]=='n') && (userInput[3]=='D' || userInput[3]=='d'))
			continueInput = false;
		
		//code to execute search and calculation functions and then generate response
		if(continueInput)
		{
			operatorType = IdentifyOperator(userInput);
			
			findOperands(userInput,opArray1,opArray2,arr1Size,arr2Size,operatorType,operand1Found,operand2Found);
			
			//search for text operands only executed if any operand is not found
			if(!operand1Found || !operand2Found)
				convertOperands(userInput,opArray1,opArray2,arr1Size,arr2Size,operatorType,operand1Found,operand2Found);
			
			if(operand1Found)
				functionCaller(operatorType,opArray1,opArray2,arr1Size,arr2Size,answer,answerSize,logical);
			
			GenerateResponse(operatorType,opArray1,opArray2,arr1Size,arr2Size,answer,answerSize,operand1Found,operand2Found,logical);
		}
		
		//reinitializing the opArrays and answer array
		for(i=0;i<arraySize;i++)
		{
			opArray1[i] = 0;
			opArray2[i] = 0;
			answer[i] = 0;
		}
		 
		//reinitializing the userInput array
		for(i=0;i<SIZE;i++)
		{
			userInput[i] = 0;
		}
		
		//reinitializing the array sizes
		arr1Size = 0;
		arr2Size = 0;
		answerSize = 0;
		operatorType = 'N';
		
		//reinitializing the flags to default values
		operand1Found = false;
		operand2Found = false;
		logical = true;
	}
	
	cout<< "ELIZA: Goodbye.";
}

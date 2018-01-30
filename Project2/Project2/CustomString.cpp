#include "CustomString.h"
#include <iostream>
#include <string>
#include <sstream>
CustomString::CustomString()
{
}

CustomString::~CustomString()
{
}

void CustomString::PrintAllSubSet(int original[], int newArray[], int legth, int choiceToMake)
{
	if (choiceToMake == 0)
	{
		std::cout << "{ ";
		for (int i = 0; i < legth; i++)
		{
			if (newArray[i] != -1)
			{
				std::cout << newArray[i] << " ," ;
			}
		}
		std::cout << " } ";
		std::cout << std::endl;
	}
	else
	{
		newArray[choiceToMake -1] = original[choiceToMake -1];
		PrintAllSubSet(original, newArray, legth, choiceToMake - 1);
		newArray[choiceToMake -1] = -1;
		PrintAllSubSet(original, newArray, legth, choiceToMake - 1);

	}
}
void CustomString::PrintAllPermutation(int oringial[], int lenght, int level)
{
	if (lenght - 1 == level)
	{
		for (int i = 0; i < lenght; i++)
		{
			std::cout << oringial[i];
		}
		std::cout << std::endl;
	}
	else
	{
		for (int i = level; i < lenght; i++)
		{
			//choose
			int temp = oringial[i];//b
			oringial[i] = oringial[level];//2=>a
			oringial[level] = temp;//1=> b
			//exlpoer
			PrintAllPermutation(oringial, lenght, level + 1);

			//un-choose
			temp = oringial[i];//a
			oringial[i] = oringial[level];//2=>b
			oringial[level] = temp;//1=> a

		}
	}	

}

void CustomString::PrintAllPermutation(std::string prefix, std::string postFix)
{
	if (postFix.length() == 0)
	{
		std::cout << prefix << std::endl;
	}
	else
	{
		for (int i = 0; i < postFix.length(); ++i)
		{
			//choose
			char runnerChar = postFix[i];
			prefix += runnerChar;
			postFix.erase(i, 1);

			PrintAllPermutation(prefix, postFix);
			//unchoose
			postFix.insert(i, 1, runnerChar);
			prefix.erase(prefix.length() -1, 1);

		}
	}
}

void CustomString::DiceRoll(int NumberOfDice, std::string prefix)
{
	//std::cout << "( DiceRoll " << NumberOfDice << " , " << prefix << " ) " << std::endl;
	if (NumberOfDice == 0)
	{
		if (prefix.length() == 4)
		{
			std::cout << "break";
		}
			std::cout << prefix << std::endl;
	}
	else
	{

			for (int j = 1; j <= 6; j++)
			{
				std::stringstream stream;
				stream << prefix << j << " , ";

				DiceRoll(NumberOfDice - 1, stream.str());
			}
	}
}

bool CustomString::IsAnagrams(const char* string1, const char* string2)
{
	const static int SIZE_OF_ARRAY = 256;
	bool retVlaue = true;

	if (string1 == NULL && string2 == NULL) return true;
	if (string1 == NULL && string2 != NULL) return false;
	if (string1 != NULL && string2 == NULL) return false;

	bool retValue = false;
	int countChar[SIZE_OF_ARRAY] = { 0 };

	while(*string1 != '/0')
	{
		++countChar[*string1];
	}
	
	while (*string2 != '/0')
	{
		--countChar[*string2];
	}
	
	for (int i = 0; ((i < SIZE_OF_ARRAY) && (retVlaue)); i++)
	{
		if (countChar[i] != 0)
		{
			retVlaue = false;
		}
	}

	return retValue;
}

void CustomString::RemoveDuplicateWithoutAddtionalString(std::string& stringWithDuplicates)
{
	int j = 1;
	int i = 0;
	
	for (; j < stringWithDuplicates.length(); j++)
	{
		if (stringWithDuplicates[i] != stringWithDuplicates[j])
		{
			stringWithDuplicates[++i] = stringWithDuplicates[j];
		}
	}

	for (; i < stringWithDuplicates.length(); i++)
	{
		stringWithDuplicates[i] = '0';
	}
}
// -7, 1, 5, 2, -4, 3, 0
//                  ^
//                  ^
void CustomString::ReveseStringWithoutUsingTemp(std::string& string1)
{
	int frontCounter = 0;
	int backCounter = string1.length() - 1;
	while (frontCounter < backCounter)
	{
		string1[frontCounter] ^= string1[backCounter];
		string1[backCounter] ^= string1[frontCounter];
		string1[frontCounter] ^= string1[backCounter];

		frontCounter++;
		backCounter--;
	}
}
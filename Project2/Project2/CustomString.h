#include <iostream>

class CustomString
{
public:
	CustomString();
	~CustomString();
	bool IsAnagrams(const char* string1, const char* string2);
	void ReveseStringWithoutUsingTemp(std::string& string1);
	void RemoveDuplicateWithoutAddtionalString(std::string& stringWithDuplicates);
	void PrintAllPermutation(int oringial[], int lenght, int level);
	void PrintAllPermutation(std::string prefix, std::string postFix);
	void DiceRoll(int NumberOfDice, std::string prefix = "");
	void PrintAllSubSet(int original[], int newArray[], int legth, int choiceToMake);

private:

};

//https://www.geeksforgeeks.org/amazon-interview-experience-set-418-sde-2/
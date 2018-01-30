#include "BitwiseOperation.h"

BitwiseOperation::BitwiseOperation()
{

}
BitwiseOperation::~BitwiseOperation()
{

}
int BitwiseOperation::FindNumberOfOnes(int i)
{
	int numOfOnes = 0;

	while (i > 0)
	{
		numOfOnes += i & 1;
		i >>= 1;
	}
	return numOfOnes;
}
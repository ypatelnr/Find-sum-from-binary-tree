/************************************************************************/
/*!
*	\file	CoinSet.h
*
*	\brief help to determind minumum number of coin require to make exchange
*
*	\Version
*		-Y Patel 01/26/2018
*			Initial Version
*************************************************************************/
//physical dependencies
#include "CoinSet.h"

//stl dependencies
#include <iostream>
#include <vector>
#include <algorithm>
//
//int CoinSet::MinimumNumberOfCoin(int change, const std::vector<double> & coinSet)
//{
//	int* coinChangeArray = new int[change + 1];
//
//	coinChangeArray[0] = 0;
//	
//	for (int i = 1; i <= change; ++i)
//	{
//		coinChangeArray[i] = INT_MAX;
//	}
//
//	for (int i = 1; i <= change; i++)
//	{
//		for (int j = 0; j < coinSet.size(); ++j)
//		{
//			int currentCoin = coinSet[j];
//
//			if (i >= currentCoin)
//			{
//				int currentCoinCount = coinChangeArray[i - currentCoin] + 1;
//				if (currentCoinCount < coinChangeArray[i])
//				{
//					coinChangeArray[i] = currentCoinCount;
//				}
//			}
//		}
//	}
//}
int CoinSet::MinimumNumberOfCoin(int change, const std::vector<double> & coinSet)
{
	int** coinChangeMatrix = new int*[coinSet.size()];
	
	for (int i = 0; i < coinSet.size(); i++)
	{
		coinChangeMatrix[i] = new int[change];
	}

	for (int i = 0; i < change; ++i)
	{
		coinChangeMatrix[0][i] = coinSet[0] * (i + 1);
	}

	for (int i = 1; i < coinSet.size(); ++i)
	{
		int currentCoin = coinSet[i];

		for (int j = 0; j < change; ++j)
		{
			if (change < coinSet[i])
			{
				coinChangeMatrix[i][j] = coinChangeMatrix[i - 1][j];
			}
			else
			{
				int excludingCurrentChange = coinChangeMatrix[i - 1][j];
				int includingCurrentChange = coinChangeMatrix[i][j - currentCoin - 1] + 1;
				coinChangeMatrix[i][j] = std::min(excludingCurrentChange, includingCurrentChange);
			}
		}
	}

	return coinChangeMatrix[coinSet.size() - 1][change - 1];
}
CoinSet::CoinSet()
{
}

CoinSet::~CoinSet()
{
}
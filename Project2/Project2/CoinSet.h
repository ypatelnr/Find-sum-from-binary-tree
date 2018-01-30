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
#include <iostream>
#include <vector>

class CoinSet
{
public:

	CoinSet();
	~CoinSet();
	virtual int MinimumNumberOfCoin(int, const std::vector<double> &);
private:

	std::vector<double> setOfCoin;
};
#include "DecisionFunctions.hpp"

#include <cstdlib>



bool bTrend(std::vector<int> viHistory,int iMemory)
{
	int tolerance=60;
	int size=viHistory.size();
	if( size < iMemory ) {
		if( rand()%100 > 50 ) return true;
		else return false;
	}
	else {
		double trend=0;
		for(int i=iMemory;i>0;i--) trend=viHistory.at(size-i)/iMemory;
		if( trend > tolerance ) return false;
		else return true;
	}
}

bool bDiff(std::vector<int> viHistory, int iMemory)
{
	int tolerance=60;
	int size=viHistory.size();
	if( size < iMemory ) {
		if( rand()%100 > 50 ) return true;
		else return false;
	}
	else {
		if( viHistory.at(size-iMemory) > tolerance ) return true;
		else return false;
	}
}

bool bSame(std::vector<int> viHistory, int iMemory)
{
	int tolerance=60;
	int size=viHistory.size();
	if( size < iMemory ) {
		if( rand()%100 > 50 ) return true;
		else return false;
	}
	else {
		if( viHistory.at(size-iMemory) > tolerance ) return false;
		else return true;
	}
}

bool bSum(std::vector<int> viHistory,int iMemory)
{
	int tolerance=60;
	int size=viHistory.size();
	if( size < iMemory ) {
		if( rand()%100 > 50 ) return true;
		else return false;
	}
	else {
		if( viHistory.at(size-iMemory)+10 > tolerance ) return false;
		else return true;
	}
}

bool bPercent(std::vector<int> viHistory,int iMemory)
{
    iMemory=1;
	int tolerance=60;
	int size=viHistory.size();
	if( size < iMemory ) {
		if( rand()%100 > 50 ) return true;
		else return false;
	}
	else {
		if( 100-0.3*viHistory.at(size-iMemory) > tolerance ) return false;
		else return true;
	}
}


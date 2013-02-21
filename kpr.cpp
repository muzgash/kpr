#include "Customer.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;




bool bSame(vector<int> viHistory)
{
	int memory=3;
	int tolerance=60;
	int size=viHistory.size();
	if( size < memory ) {
		if( rand()%100 > 50 ) return true;
		else return false;
	}
	else {
		if( viHistory.at(size-memory) > tolerance ) return false;
		else return true;
	}
}

bool bDiff(vector<int> viHistory)
{
	int memory=3;
	int tolerance=60;
	int size=viHistory.size();
	if( size < memory ) {
		if( rand()%100 > 50 ) return true;
		else return false;
	}
	else {
		if( viHistory.at(size-memory) > tolerance ) return true;
		else return false;
	}
}

bool bTrend(vector<int> viHistory)
{
	int memory=3;
	int tolerance=60;
	int size=viHistory.size();
	if( size < memory ) {
		if( rand()%100 > 50 ) return true;
		else return false;
	}
	else {
		double trend=0;
		for(int i=memory;i>0;i--) trend=viHistory.at(size-i)/memory;
		if( trend > tolerance ) return false;
		else return true;
	}
}





int main(int argc, char **argv){

	srand(time(NULL));

    int iWeekend,iCustomer; //counters
	int iGoing=0; //number of going customers
    customer person[100];

	//Initial conditions
	for(iCustomer=0; iCustomer<100; iCustomer++ ) {
	int r=rand()%100;
		if( r < 33 )	person[iCustomer].setDecisionFunction(bSame);
		else if( r >= 33 && r < 66 ) person[iCustomer].setDecisionFunction(bDiff);
		else person[iCustomer].setDecisionFunction(bTrend);
	}

	
	    for( iWeekend=0; iWeekend<1; iWeekend++ ) { //number of weekends in a year
	        for( iCustomer=0; iCustomer<100; iCustomer++ ) {
			    person[iCustomer].decide();
				if( person[iCustomer].isGoing()==true ) iGoing++;
            }

			//The problem is here, the vector __viHistory is not changing but not error reported
			person[0].__viHistory.push_back(iGoing);
			cout<<iWeekend<<" "<<iGoing<<" "<<endl;
			iGoing=0;

		}

return 0;
}

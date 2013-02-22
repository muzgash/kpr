#include "Customer.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;




//DECISION FUNCTIONS

/*! \brief Looks iMemory steps behind in viHistory and if it's too crowded returns false.
 *
 *  \param vector<int> History.
 *  \param int Memory.
 *
 *  \returns bool Decision.
 */
bool bSame(vector<int> viHistory, int iMemory);

/*! \brief Looks iMemory steps behind in viHistory and if it's too crowded returns true.
 *
 *  \param vector<int> History.
 *  \param int Memory.
 *
 *  \returns bool Decision.
 */
bool bDiff(vector<int> viHistory, int iMemory);

/*! \brief Looks iMemory steps in viHistory and takes the mean value of them all, and if it's too crowded returns false.
 *
 *  \param vector<int> History.
 *  \param int Memory.
 *
 *  \returns bool Decision.
 */
bool bTrend(vector<int> viHistory,int iMemory);




int main(int argc, char **argv){

	srand(time(NULL)); //random timed seed

    int iWeekend,iCustomer; //counters
	int iGoing=0; //number of going customers
	int iRandom;
    customer person[100];

	//Initial conditions
	for(iCustomer=0; iCustomer<100; iCustomer++ ) {
	    //Sets with equal probability a decision function for each agent
		iRandom=rand()%100;
		if( iRandom < 33 )	person[iCustomer].setDecisionFunction(bSame);
		else if( iRandom >= 33 && iRandom < 66 ) person[iCustomer].setDecisionFunction(bDiff);
		else person[iCustomer].setDecisionFunction(bTrend);

		person[iCustomer].setMemory(rand()%10+1); //Sets the memory with an integer between 1 and 10
		person[iCustomer].setPayoff();
	}

	
	    for( iWeekend=0; iWeekend<105; iWeekend++ ) { //number of weekends in 2 years
			//Loop to calculate the decisions and sum up the customers each week
	        for( iCustomer=0; iCustomer<100; iCustomer++ ) {
			    person[iCustomer].decide();
				if( person[iCustomer].isGoing()==true ) iGoing++; //storing the number of people who does go
            }

			customer::__viHistory.push_back(iGoing);

			//Loop to update the payoffs and change the decision function if necessary
	        for( iCustomer=0; iCustomer<100; iCustomer++ ) {
				person[iCustomer].updatePayoff(60);
			}

			//Report of data
			cout<<iWeekend<<" "<<iGoing<<endl;

			iGoing=0;
		}

return 0;
}




bool bTrend(vector<int> viHistory,int iMemory)
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

bool bDiff(vector<int> viHistory, int iMemory)
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

bool bSame(vector<int> viHistory, int iMemory)
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


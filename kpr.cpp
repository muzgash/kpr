#include "Customer.hpp"
#include "DecisionFunctions.hpp"
#include "Plots.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>


using namespace std;

#define p(x) cout<<x<<endl


int main(int argc, char **argv){

	srand(time(NULL)); //random timed seed

    int iWeekend,iCustomer; //counters

	double iGoing=0; //number of going customers

	int iRandom;

	double *pfNumber = new double[400],*pfWeekends = new double[400];


	double *pfEmbeddedNum = new double[200], *pfEmbedded = new double[200], *pfEmbeddedTotal = new double[250];
    customer person[100];

    //Setup of the decision functions on the static array for the customer class 
	customer::__pfDecisionFunction[0]=bSame;
	customer::__pfDecisionFunction[1]=bDiff;
	customer::__pfDecisionFunction[2]=bTrend;
	customer::__pfDecisionFunction[3]=bSum;
	customer::__pfDecisionFunction[4]=bPercent;

	string sFilename("memory-learning-");
	char *numberFile = new char[2];

/*for(int i=1;i<50;i++){
string filename=sFilename;
	sprintf(numberFile,"%d",i);
	filename+=numberFile;
	filename+=".png";*/

	//Initial conditions
	for(iCustomer=0; iCustomer<100; iCustomer++ ) {
	    //Sets with equal probability a decision function for each agent
		iRandom=rand()%100;
		if( iRandom < 20 )	person[iCustomer].setDecisionFunctionIndex(0);
		else if( iRandom >= 20 && iRandom < 40 ) person[iCustomer].setDecisionFunctionIndex(1);
		else if( iRandom >= 40 && iRandom < 60 ) person[iCustomer].setDecisionFunctionIndex(2);
		else if( iRandom >= 60 && iRandom < 80 ) person[iCustomer].setDecisionFunctionIndex(3);
		else person[iCustomer].setDecisionFunctionIndex(4);
		person[iCustomer].setMemory(rand()%20+1); //Sets the memory with an integer between 1 and 10
		person[iCustomer].setPayoffSumHistory();
	}



//Loop for the same initial conditions
for(int i=1;i<=20;i++){
string filename=sFilename,recurrence_name="recurrence-plot-";
	sprintf(numberFile,"%d",i);
	filename+=numberFile;
	recurrence_name+=numberFile;
	filename+=".png";
	recurrence_name+=".png";

	
	for( iWeekend=0; iWeekend<450; iWeekend++ ) { //number of weekends
		//Loop to calculate the decisions and sum up the customers each week
		for( iCustomer=0; iCustomer<100; iCustomer++ ) {
			person[iCustomer].decide();
			if( person[iCustomer].isGoing()==true ) iGoing++; //storing the number of people who does go
		}

		customer::__viHistory.push_back(iGoing);

		//Loop to update the payoffs and change the decision function if necessary
		for( iCustomer=0; iCustomer<100; iCustomer++ ) {
			person[iCustomer].updatePayoff(60);
			person[iCustomer].checkPayoffs(iWeekend);
		}

		//Logging of number of assistants, dismissing the first 50 weeks
		if( iWeekend > 49 ){
			pfNumber[iWeekend-50]=iGoing/100;
			pfWeekends[iWeekend-50]=iWeekend;
		}


		
		//if(i==0) cout<<pay[0]<<" "<<pay[1]<<" "<<pay[2]<<" "<<pay[3]<<" "<<pay[4]<<" "<<person[0].getDecisionFunctionIndex()<<endl;

		iGoing=0;
	}

    //PLOTS
	RecurrencePlot(pfNumber,400,recurrence_name);
	TSPlot(pfWeekends, pfNumber, 300, filename);
	
	for( iCustomer=0; iCustomer<100; iCustomer++ ){
		person[iCustomer].setPayoffSumHistory();
	}
	customer::__viHistory.clear();
}	


	return 0;
}





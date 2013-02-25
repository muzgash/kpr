#include "Customer.hpp"
#include "DecisionFunctions.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

//MathGL inclusions
#include <mgl/mgl.h>
#include <mgl/mgl_zb.h>

using namespace std;




int main(int argc, char **argv){

	srand(time(NULL)); //random timed seed

    int iWeekend,iCustomer; //counters
	double iGoing=0; //number of going customers
	int iRandom;
	double *pfNumber = new double[105],*pfWeekends = new double[105];
    customer person[100];

	string sFilename("ranmemory-nolearning-");
	char *numberFile = new char[2];


/*for(int i=0;i<20;i++){
string filename=sFilename;
	sprintf(numberFile,"%d",i);
	filename+=numberFile;*/

	//Initial conditions
	for(iCustomer=0; iCustomer<100; iCustomer++ ) {
	    //Sets with equal probability a decision function for each agent
		iRandom=rand()%100;
		if( iRandom < 20 )	person[iCustomer].setDecisionFunction(bSame);
		else if( iRandom >= 20 && iRandom < 40 ) person[iCustomer].setDecisionFunction(bDiff);
		else if( iRandom >= 40 && iRandom < 60 ) person[iCustomer].setDecisionFunction(bSum);
		else if( iRandom >= 60 && iRandom < 80 ) person[iCustomer].setDecisionFunction(bPercent);
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

		//Logging of number of assistants 
		pfNumber[iWeekend]=iGoing/100;
		pfWeekends[iWeekend]=iWeekend;
		//cout<<iWeekend<<" "<<iGoing<<endl;

		iGoing=0;
	}

/*	//MathGL Plotting
	mglData number;
	mglData weekends;
	number.Set(pfNumber,105);
	weekends.Set(pfWeekends,105);
	mglGraphZB gr;

	gr.Alpha(false);
	gr.Light(true);
	gr.Transparent=false;

	gr.XRange(weekends,false,0);
	gr.YRange(number,false,0);

	gr.Title("","iC",8);
	gr.Label('x',"Weekends");
	gr.Label('y',"Number of people");
	gr.Axis();
	gr.Plot(weekends,number,"r-");
	gr.WritePNG(filename.c_str());
	
}*/

	return 0;
}





#include "Customer.hpp"

#include <cstdlib>
#include <iostream>

int* putBack(int number, int *array, int size)
{
	if( size == 1 ){
		array[0]=number;
	}
	else{
		int tmp=array[size-1];
		array[size-1]=number;
		for(int i=0;i<size-2;i++){
			array[i]=array[i+1];
		}
		array[size-2]=tmp;
	}
	return array;
}




customer::customer(){}

std::vector<int> customer::__viHistory;
bool (*customer::__pfDecisionFunction[5])(std::vector<int>,int);

void customer::decide(void)
{ 
    _bDecision=__pfDecisionFunction[_iDecisionFunctionIndex](__viHistory,_iMemory);
}

void customer::checkPayoffs(int time)
{
    //If the cycle of memory steps is not over.
	if( time%_iMemory != 0 || time < _iMemory ) return;
	else{
		int sum=0;
		//Sums over the payoffs
		for( int i=0; i<_iMemory; i++ ) sum+=_viPayoff.at(_viPayoff.size()-i-1);
		//If the sum of the payoffs is greater change the last sum on the history
		if( _piPayoffSumHistory[_iDecisionFunctionIndex] < sum || _piPayoffSumHistory[_iDecisionFunctionIndex]==10 ) _piPayoffSumHistory[_iDecisionFunctionIndex]=sum;
		//Seeks a better sum of payoffs on the history to change the decision function
		for( int i=0; i<5; i++ ) {
			if( _piPayoffSumHistory[i] > sum ) {
			    _iDecisionFunctionIndex=i;
				break;
			}
		}
		for( int i=0; i<5; i++ ) {
			if(_piPayoffSumHistory[i]==10 ){
				_iDecisionFunctionIndex=i;
				break;
			}
		}
	}
}

void customer::updatePayoff(int tolerance)
{
	if( __viHistory.back() > tolerance && _bDecision == true || __viHistory.back() < tolerance && _bDecision == false )
		_viPayoff.push_back(-1);
	else
		_viPayoff.push_back(1);
}




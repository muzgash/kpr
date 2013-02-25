#include "Customer.hpp"




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
bool (*customer::_pfDecisionFunction)(std::vector<int>,int);

void customer::decide(void)
{ 
    _bDecision=_pfDecisionFunction(__viHistory,_iMemory);
}

void customer::updatePayoff(int tolerance)
{
	if( __viHistory.back() > tolerance && _bDecision == true || __viHistory.back() < tolerance && _bDecision == false )
		_piPayoff=putBack(-1,_piPayoff,_iMemory);
	else
		_piPayoff=putBack(1,_piPayoff,_iMemory);
}




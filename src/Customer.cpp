#include "Customer.hpp"

customer::customer(){}

std::vector<int> customer::__viHistory;

void customer::decide(void)
{ 
    _bDecision=_pfDecisionFunction(__viHistory);
}

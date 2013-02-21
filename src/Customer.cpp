#include "Customer.hpp"

customer::customer(){}

void customer::decide(void)
{
     
    _bDecision=_pfDecisionFunction(__viHistory);
}

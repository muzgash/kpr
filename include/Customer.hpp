/*
*    KPR is free software: you can redistribute it and/or modify
*    it under the terms of the Lesser GNU General Public License 
*    as published by the Free Software Foundation, either version
*    3 of the License, or any later version.
*
*    KPR is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    Lesser GNU General Public License for more details.
*
*    You should have received a copy of the Lesser GNU General Public
*    License along with KPR.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <vector>

/*! \brief A class of customers of the bar «el farol»
 *  
 *  The customer wants to be at the bar if it is not too crowded
 *  to decide this it has some information:
 *    - The number of people that has gone to the bar in the past
 *    - Memory
 *    - A decision function
 *
 */
class customer{
  public:
    customer();

	//ACCESOR FUNCTIONS
	bool isGoing(void){return _bDecision;}
	int getMemory(void){return _iMemory;}
	std::vector<int> getPayoff(void){return _viPayoff;}
	int getDecisionFunctionIndex(void){return _iDecisionFunctionIndex;}
	int* getPayoffSumHistory(void){return _piPayoffSumHistory;}

	//MUTATOR FUNCTIONS
	
	/*! \brief A mutator function to initialize the payoff sum log.
	 *
	 *  \param void since the memory is stored in the class.
	 */
	void setPayoffSumHistory(void){for( int i=0;i<5;i++ ) _piPayoffSumHistory[i]=10;}

	/*! \brief A mutator function which sets the customer's memory length.
	 *  
	 *  \param int Memory length.
	 */
	void setMemory(int iMemory){_iMemory=iMemory;}

	/*! \brief A mutator function which changes the last decision taken
	 *
	 *  \param bool Decision.
	 */
	void setDecision(bool bDecision){_bDecision=bDecision;}
	
	/*! \brief A mutator function which changes the index for  decision function to be used.
	 *
	 *  \param bool Decision Function Index.
	 */
	void setDecisionFunctionIndex(int iDecisionFunctionIndex){_iDecisionFunctionIndex=iDecisionFunctionIndex;}

	/*! \brief An accesor function for the decision pointer to function.
	 *
	 *  \param void since everything it needs should be within the object.
	 *
	 *  The function calls the private member pointer to function that is
	 *  the function a customer has to decide if he's going or not.
	 *
	 *  \returns void the value is saved in _bDecision.
	 */
	void decide(void);




    /*! \brief Updates the payoff array.
	 *
	 *  The rules are:
	 *    - If the bar was crowded and the customer went he gets -1.
	 *    - If the bar was not crowded and the customer didn't go, he also gets -1.
	 *    - any other way he gets a +1.
	 *
	 *  \param int The max number of comfortable people the bar can allow.
	 *  
	 *  \returns void the value is stored in _viPayoff
	 */
	void updatePayoff(int tolerance);

	/*! \brief Checks payoffs vector to change the decision function if necesary
	 *
	 *  \param int time elpased time.
	 *
	 */
	void checkPayoffs(int time);




	//Must be public since it has to be instantiated outside the class for scope purposes
	/*! \var static std::vector<int>
	 *  History of the number of people that went to the bar
	 */
	static std::vector<int> __viHistory;

    /*! \var bool
	 *   Pointer to the decision function, every function needs the history and the memory
     */
	static bool (*__pfDecisionFunction[5])(std::vector<int>,int);




  private:
    /*! \var bool
	 *   Last decision taken by the customer, eventually it should be another vector
     */
    bool _bDecision;

	/*! \var int
	 *  Actual index of the decision function in the common decision function array
	 */
	int _iDecisionFunctionIndex;

	/*! \var int
	 *   Memory, it means how many steps in the history he uses to calculate his decision
	 */
	int _iMemory;

	/*! \var int*
	 *  Array of payoffs from previous vists.
	 */
	std::vector<int> _viPayoff;

	/*! \var std::vector<int>
	 *
	 */
	int _piPayoffSumHistory[5];

};


#endif

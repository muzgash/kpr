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
	bool isGoing(){return _bDecision;}

	//MUTATOR FUNCTIONS
	
	/*! \brief A mutator function wich changes de last decision taken
	 *
	 *   \param bool bDecision
	 */
	void setDecision(bool bDecision){_bDecision=bDecision;}
	
	/*! \brief A mutator function wich sets the decision function
	 *
	 *   \param bool *function(std::vector<int>)
	 */
	void setDecisionFunction(bool (*pfDecisionFunction)(std::vector<int>)){_pfDecisionFunction = pfDecisionFunction;}
	
	/*! \brief A mutator function wich sets the history vector
	 *
	 *   \param std::vector<int>
	 */
	void setHistory(std::vector<int> viHistory){__viHistory=viHistory;}

	/*! \brief An accesor function for the decision pointer to function.
	 *
	 *  \param void since everything it needs should be within the object.
	 *
	 *  The function calls the private member pointer to function that is
	 *  the function a customer has to decide if he's going or not.
	 *  \return the value is saved in _bDecision so this function returns void.
	 */
	void decide(void);

	//Must be public since it has to be instantiated outside the class for scope purposes
	/*! \var static std::vector<int>
	 *  History of the number of people that went to the restaurant
	 */
	static std::vector<int> __viHistory;




  private:
    /*! \var bool
	 *   Last decision taken by the customer, eventually it should be another vector
     */
    bool _bDecision;

    /*! \var bool
	 *   Pointer to the decision function, every function needs the history
     */
	bool (*_pfDecisionFunction)(std::vector<int>);

};


#endif

/*
 KPR es software libre: Usted lo puede redistribuir y modificar
 bajo los términos de la Licencia Pública General Reducida GNU
 (LGPL) como es publicado por La fundación de software libre
 (FSF), la versión 3 o cualquier versión posterior.
 
 KPR es distribuido en la espera de que será útil,
 pero SIN ALGUNA GARANTÍA; ni siquiera la garantía implícita de
 COMERCIALIZACIÓN o IDONEIDAD PARA UN PROPÓSITO
 PARTICULAR. Véase la Licencia Pública General Reducida GNU
 para más detalles.
 
 Usted debe haber recibido una copia de la Licencia Pública
 General Reducida GNU junto con KPR.
 Sino, vea <http://www.gnu.org/licenses/>.
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <vector>

class customer{
  public:
    customer();

	//ACCESOR FUNCTIONS
	bool isGoing(){return _bDecision;}

	//MUTATOR FUNCTIONS
	void setDecision(bool bDecision){_bDecision=bDecision;}
	void setDecisionFunction(bool (*pfDecisionFunction)(std::vector<int>)){_pfDecisionFunction = pfDecisionFunction;}
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
	static std::vector<int> __viHistory; /*!History of the number of people that went to the restaurant */


  private:
    bool _bDecision; /*!Last decision taken by the customer, eventually it should be another vector*/
	bool (*_pfDecisionFunction)(std::vector<int>); /*!Pointer to the decision function, every function needs the history*/

};


#endif

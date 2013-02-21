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

	bool isGoing(){return _bDecision;}
	void setDecision(bool bDecision){_bDecision=bDecision;}
	void setDecisionFunction(bool (*pfDecisionFunction)(std::vector<int>)){_pfDecisionFunction = pfDecisionFunction;}
	void setHistory(std::vector<int> viHistory){__viHistory=viHistory;}
	void decide(void);

	static std::vector<int> __viHistory;


  private:
    bool _bDecision;
	bool (*_pfDecisionFunction)(std::vector<int>);

};

std::vector<int> customer::__viHistory;

#endif

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
 General Reducida GNU junto con GDBase.
 Sino, vea <http://www.gnu.org/licenses/>.
 */

#ifndef AGENTS_H
#define AGENTS_H


class agents{
  public:
    agents();

	bool isGoing(){return _bDecision;}
	void setDecision(bool bDecision){_bDecision=bDecision;}
	void setDecisionFunction(void (*pfDecisionFunction)(int)){_pfDecisionFunction = pfDecisionFunction;}

  private:
    bool _bDecision;
	void (*_pfDecisionFunction)(int);

};


#endif

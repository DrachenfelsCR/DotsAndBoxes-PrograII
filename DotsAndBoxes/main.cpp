#include "puntoCompuesto.h"
#include "puntoSimple.h"
#include "interfaz.h"

int main()
{
    
   puntoCompuesto* puntoC = new puntoCompuesto(5,5);
   puntoSimple* supIzq = puntoC->buscar(2, 2);
   puntoSimple* supDerecha = puntoC->buscar(2, 3);
   puntoSimple* infIzq = puntoC->buscar(3, 2);
   puntoSimple* infDerecha = puntoC->buscar(3, 3);
  
   //------------
   supIzq->setDerecha(true);
   supIzq->setAbajo(true);
   //-------------
 
   infIzq->setDerecha(true);
   //---------------------
   supDerecha->setAbajo(true);
   supDerecha->setIzquierda(true);
   //---------------------
   
   infDerecha->setIzquierda(true);
   //-----------------------
    cout << puntoC->toString();
    cout << puntoC->conquistado(2,2);
   
    cin.get();
    return 0;
}
#include "puntoCompuesto.h"
#include "puntoSimple.h"
#include "interfaz.h"

int main()
{
   /*
   puntoCompuesto* puntoC = new puntoCompuesto(14,14);
   puntoSimple* supIzq = puntoC->buscar(0, 2);
   puntoSimple* supDerecha = puntoC->buscar(0, 2);
   puntoSimple* infIzq = puntoC->buscar(1, 2);
   puntoSimple* infDerecha = puntoC->buscar(1, 4);
   /////////////////////////////////////////////////////
   puntoSimple* supIzq1 = puntoC->buscar(0, 0);
   puntoSimple* supDerecha2 = puntoC->buscar(0, 1);
   puntoSimple* infIzq3 = puntoC->buscar(1, 0);
   puntoSimple* infDerecha4 = puntoC->buscar(1, 1);
   
  
   supDerecha2->setDerecha(true);
   infDerecha4->setDerecha(true);
   supDerecha->setAbajo(true);
   //-------------
   supIzq->setIzquierda(true);
   infIzq->setIzquierda(true);
   //------------
   supIzq1->setDerecha(true);
   supIzq1->setAbajo(true);

   //supIzq->setDerecha(true);
 //  supIzq->setAbajo(true);

   //-------------
   infIzq3->setDerecha(true);
  // infIzq->setDerecha(true);
   //---------------------
   supDerecha2->setAbajo(true);
   supDerecha2->setIzquierda(true);
   //supDerecha->setAbajo(true);
  // supDerecha->setIzquierda(true);
   //---------------------
   infDerecha4->setIzquierda(true);
  // infDerecha->setIzquierda(true);
   //-----------------------
    cout << puntoC->toString();
    */
   
    interfaz i;
    i.menuPrincipal();
    cin.get();
    return 0;
}
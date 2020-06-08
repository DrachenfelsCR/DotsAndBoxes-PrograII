#include "puntoCompuesto.h"
#include "puntoSimple.h"
#include "interfaz.h"

int main()
{
    
   puntoCompuesto* puntoC = new puntoCompuesto(5,5);
   puntoSimple* aiuda = puntoC->buscar(0, 1);
   puntoSimple* aiuda2 = puntoC->buscar(0, 0);

   puntoSimple* aiuda3 = puntoC->buscar(1, 1);
   puntoSimple* aiuda4 = puntoC->buscar(1, 0);
   puntoSimple* aiuda5 = puntoC->buscar(0, 2);

   
    aiuda->setIzquierda(true);
    aiuda2->setDerecha(true);
    aiuda->setAbajo(true);
    aiuda3->setIzquierda(true);
    aiuda4->setDerecha(true);
    aiuda5->setAbajo(true);
   
   

    cout << puntoC->toString();
    cout<<puntoC->conquistado(0,1);
   
    cin.get();
    return 0;
}
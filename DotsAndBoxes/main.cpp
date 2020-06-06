#include "puntoCompuesto.h"
#include "puntoSimple.h"

int main()
{
    puntoCompuesto* puntoC = new puntoCompuesto(5,5);
    puntoSimple* aiuda = puntoC->buscar(1, 3);
   puntoSimple* aiuda2 = puntoC->buscar(1, 2);
   // aiuda->setAbajo(true);
    aiuda->setIzquierda(true);
    aiuda->setAbajo(true);
   aiuda2->setDerecha(true);
    cout << puntoC->toString();
    cin.get();
    return 0;
}
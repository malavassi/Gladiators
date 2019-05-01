#include <iostream>
#include "LinkedList.h"
#include "Matriz.h"
#include "Backtracking.h"

using namespace std;

int main() {
    cout << "Hello, World!" << std::endl;

   Matriz *matriz = new Matriz();
   Backtracking algo;
   algo.encontrarRuta(matriz->matriz);
   cout << matriz->matriz.getElemento(6)->getData().getSize()<< endl;
   cout << matriz->matriz.getSize() << endl;

    return 0;
}
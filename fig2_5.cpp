#include <iostream>

int main () {
  int numero1;
  int numero2;
  int suma;

  std::cout << "Ingrese el primer entero:";
  std::cin >> numero1;

  std::cout << "Ingrese el segundo entero:";
  std::cin >> numero2;

  suma = numero1 + numero2;

  std::cout << "La suma de ambos enteros es: " << suma << std::endl;

  return 0;
}

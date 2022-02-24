#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <vector>
#include <string>
void creacionManual();
void creacionRandom();
void eliminarNodo(int);
void printMatrix(std::vector<std::vector<int>>);
void creacionArchivo();
void agregarNodo();
bool revisarConexion(std::vector<int> vec);
void ordenarNodos();
std::vector<int> revisarRuta(int);
int posminima(std::vector<int>);
std::vector<int> erasebynumber(std::vector<int> vec, int num);
#endif // FUNCTIONS_H

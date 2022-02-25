#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <vector>
#include <string>
#include <utility>
void creacionManual();
void creacionRandom();
void eliminarNodo(int);
void printMatrix(std::vector<std::vector<int>>);
void creacionArchivo();
void agregarNodo();
bool revisarConexion(std::vector<int> vec);
void ordenarNodos();
std::pair<std::vector<int>,std::vector<int>> revisarRuta(int);
int posminima(std::vector<int> pos,std::vector<int> cost);
std::vector<int> erasebynumber(std::vector<int> vec, int num);
bool cinvec(int, std::vector<int>);
int checkPlace(std::vector<int> vec,int vab);
void normalizarNodos();
void entregarCamino(int,int);
#endif // FUNCTIONS_H

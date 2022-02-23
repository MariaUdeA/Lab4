#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <sstream>
#include <string>
#include "functions.h"
using namespace std;
vector<vector<int>> nodes;
int nnodes;

int main()
{
    creacionManual();
    printNodes();
    agregarNodo();
    printNodes();
    nodes.clear();
    return 0;

}
void creacionRandom(){
    vector<int> vec;
    //Random
    srand(time(0));
    //cantidad de nodos random
    nnodes=rand()%5+1;
    for (int i=0;i<nnodes;i++){
        do{
        vec.clear();
        if (i>0){
             for(int k=0;k<nnodes;k++){
                if (k<i)
                       vec.push_back(nodes[k][i]);
                else if (i==k)
                        vec.push_back(0);
                else
                       vec.push_back(rand()%34);
                }
            }
        else{
        for (int j=0;j<nnodes;j++){
            if (i==j)
                vec.push_back(0);
            else
                vec.push_back(rand()%34);
            }
        }}
        while(revisarConexion(vec)==true);
        nodes.push_back(vec);

    }
}
void creacionManual(){
    vector<int> vec;
    //Ingresar manual
    //cantidad de nodos
    int placeholder;
    cout<<"Numero de nodos a ingresar: ";
    cin>>nnodes;
    for (int i=0;i<nnodes;i++){
            do{
            cout<<"Ingresando nodo "<<char(i+65)<<endl;
            vec.clear();
            if (i>0){
                 for(int k=0;k<nnodes;k++){
                    if (k<i)
                           vec.push_back(nodes[k][i]);
                    else if (i==k)
                            vec.push_back(0);
                    else{
                        cout<<"Ingrese el costo de la conexión con el nodo "<<char(k+65)<<" entre 0 y 25, si no hay conexion escriba 30: ";
                        cin>>placeholder;
                        vec.push_back(placeholder);}
                    }
                }
            else{
                for (int j=0;j<nnodes;j++){
                if (i==j)
                    vec.push_back(0);
                else {
                    cout<<"Ingrese el costo de la conexión con el nodo "<<char(j+65)<<" entre 0 y 25, si no hay conexion escriba 30: ";
                    cin>>placeholder;
                    vec.push_back(placeholder);
                }
                }
            }
        }
            while (revisarConexion(vec)==true);
            nodes.push_back(vec);
        }
}
void eliminarNodo(int numNodo){
    nodes.erase(next(nodes.begin(),numNodo));
    nnodes--;
    for (int i=0;i<nnodes;i++){
        nodes[i].erase(next(nodes[i].begin(),numNodo));
    }
}
void printNodes(){
    for (int i = 0; i < nnodes; i++) {
        cout<<char(i+65)<<" | ";
            for (int j = 0; j < nnodes; j++)
                if (nodes[i][j]>25)
                    cout<<"- | ";
                else
                    cout << nodes[i][j] << " | ";
            cout << endl;
        }
}
void creacionArchivo(){
    nnodes=0;
    vector <int>vec;
    string line;
    ifstream fin;
    int num=0;
    fin.open("matriz.txt");
    while (fin.good()){
        nnodes++;
        getline(fin,line,'\n');
        for (char i:line){
            if (i==','){
                vec.push_back(num);
                num=0;
        }
            else
                num=num*10+int(i-48);

        }
        vec.push_back(num);
        num=0;
        nodes.push_back(vec);
        vec.clear();
    }
    fin.close();

}
void agregarNodo(){
    int placeholder;
    nnodes++;
    vector<int> vec;
    cout<<"Creacion del nodo "<<char(nnodes-1+65)<<endl;
    do{
    vec.clear();
    cout<<"Recordar que los nodos deben ser conexos"<<endl;
    for (int j=0;j<nnodes;j++){
             if (j==nnodes-1)
                 vec.push_back(0);
             else {
                 cout<<"Ingrese el costo de la conexión con el nodo "<<char(j+65)<<" entre 0 y 25, si no hay conexion escriba 30: ";
                 cin>>placeholder;
                 vec.push_back(placeholder);
             }
             }
    }
    while(revisarConexion(vec)==true);
    nodes.push_back(vec);
    for (int i=0;i<nnodes-1;i++){
        nodes[i].push_back(vec[i]);
    }
    vec.clear();
}
bool revisarConexion(vector<int> vec){
    int check=0;
    for (int i:vec){
        if (i>25)
            check++;
    }
    if (check==nnodes-1)
        return true;
    else
        return false;
}

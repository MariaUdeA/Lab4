#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include "functions.h"
using namespace std;
vector<vector<int>> nodes;
vector<vector<int>> orden;
vector<vector<int>> rutas;
int nnodes;
int main()
{
    bool sesion=true;
    int opcion;
    char node1;
    char node2;
    cout<<"Elegir una creacion de los enrutadores: "<<endl<<"1. Manual"<<endl<<"2. Random"<<endl<<"3. Desde archivo"<<endl;
    cin>>opcion;
    (opcion==1)? creacionManual():(opcion==2)? creacionRandom():creacionArchivo();
    while (sesion){
        cout<<"Elija una accion: "<<endl<<"1. Ver tabla de topografia"<<endl<<"2. Ver tabla de enrutamiento"<<endl<<"3. Agregar nodo"<<endl<<"4. Eliminar nodo"<<endl<<"5. Ruta minima entre nodos"<<endl<<"6. Valor minimo entre nodos"<<endl<<"7. Salir de sesion"<<endl;
        cin>>opcion;
        switch(opcion){
        case 1: //Ver topografía
            printMatrix(nodes);
            break;
        case 2: //Ver Enrutamiento
            ordenarNodos();
            printMatrix(orden);
            break;
        case 3: //Agregar nodo
            agregarNodo();
            break;
        case 4: //Eliminar nodo
            if (nnodes<3)
                cout<<"No se trabaja con menos de dos nodos"<<endl;
            else{
                char eliminar;
               cout<<"Elegir nodo a retirar : (De A a "<<char(nnodes-1+65)<<")"<<endl;
               cin>>eliminar;
               eliminarNodo(int(eliminar-65));
            }
            break;
        case 5: //Ruta minima entre a y b
            ordenarNodos();
            cout<<"Ingrese los dos nodos entre A y "<<char(nnodes-1+65)<<endl;
            cin>>node1;
            cin>>node2;
            entregarCamino(int(node1-65),int(node2-65));
            break;
        case 6: //Costo minimo entre a y b
            ordenarNodos();
            cout<<"Ingrese los dos nodos entre A y "<<char(nnodes-1+65)<<endl;
            cin>>node1;
            cin>>node2;
            cout<<"El costo minimo es de "<<orden[int(node1-65)][int(node2-65)]<<endl;
            break;
        case 7: //Salir de sesion
            sesion=false;
            break;
        }

    }
    nodes.clear();
    orden.clear();
    return 0;

}
void creacionRandom(){
    vector<int> vec;
    //Random
    srand(time(0));
    //cantidad de nodos random
    nnodes=rand()%5+2;
    //nnodes=4;
    for (int i=0;i<nnodes;i++){
        vec.clear();
        if (i==nnodes-1){
            for(int k=0;k<nnodes;k++){
               if (k<i)
                      vec.push_back(nodes[k][i]);
               else if (i==k)
                       vec.push_back(0);
            }
            if (revisarConexion(vec)==true){
                i=i-2;
                nodes.pop_back();}
            else
                nodes.push_back(vec);
         }
        else{
        do{
        vec.clear();
        if (i>0){
             for(int k=0;k<nnodes;k++){
                if (k<i)
                       vec.push_back(nodes[k][i]);
                else if (i==k)
                        vec.push_back(0);
                else
                       vec.push_back(rand()%30-5);
                }
            }
        else{
        for (int j=0;j<nnodes;j++){
            if (i==j)
                vec.push_back(0);
            else
                vec.push_back(rand()%30-5);
            }
        }
        }
        while(revisarConexion(vec)==true);
        nodes.push_back(vec);
        }
    }
    normalizarNodos();
}
void creacionManual(){
    //int c=0;
    //int placeholder[10]={1,-1,1,-1,1,-1,1}; Pruebas
    vector<int> vec;
    //Ingresar manual
    //cantidad de nodos
    int placeholder;
    cout<<"Numero de nodos a ingresar: ";
    //cin>>nnodes;
    nnodes=4;
    for (int i=0;i<nnodes;i++){
        vec.clear();
        if (i==nnodes-1){
            for(int k=0;k<nnodes;k++){
               if (k<i)
                      vec.push_back(nodes[k][i]);
               else if (i==k)
                       vec.push_back(0);
            }
            if (revisarConexion(vec)==true){
                i=i-2;
                nodes.pop_back();
            }
            else
                nodes.push_back(vec);
         }
        else{
            do{
            vec.clear();
            cout<<"Ingresando nodo "<<char(i+65)<<endl;
            if (i>0){
                 for(int k=0;k<nnodes;k++){
                    if (k<i)
                           vec.push_back(nodes[k][i]);
                    else if (i==k)
                            vec.push_back(0);
                    else{
                        cout<<"Ingrese el costo de la conexión con el nodo "<<char(k+65)<<" entre 0 y 25, si no hay conexion escriba -1: ";
                        cin>>placeholder;
                        vec.push_back(placeholder);
                        //c++;
                    }
                    }
                }
            else{
                for (int j=0;j<nnodes;j++){
                if (i==j)
                    vec.push_back(0);
                else {
                    cout<<"Ingrese el costo de la conexión con el nodo "<<char(j+65)<<" entre 0 y 25, si no hay conexion escriba -1: ";
                    cin>>placeholder;
                    vec.push_back(placeholder);
                    //c++;
                }
                }
            }
        }
            while (revisarConexion(vec)==true);
            nodes.push_back(vec);
        }
        }
    normalizarNodos();
}
void eliminarNodo(int numNodo){
    nodes.erase(next(nodes.begin(),numNodo));
    nnodes--;
    for (int i=0;i<nnodes;i++){
        nodes[i].erase(next(nodes[i].begin(),numNodo));
    }
}
void printMatrix(vector<vector<int>>vec){
    for (int i = 0; i < nnodes; i++) {
        cout<<char(i+65)<<" | ";
            for (int j = 0; j < nnodes; j++)
                if (vec[i][j]==300)
                    cout<<"- | ";
                else
                    cout << vec[i][j] << " | ";
            cout << endl;
        }
    cout<<endl;

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
                 cout<<"Ingrese el costo de la conexión con el nodo "<<char(j+65)<<" entre 0 y 25, si no hay conexion escriba -1: ";
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
    normalizarNodos();
}
bool revisarConexion(vector<int> vec){
    int check=0;
    for (int i:vec){
        if (i<0)
            check++;
    }
    if (check==nnodes-1 && nnodes>1)
        return true;
    else
        return false;
}
void ordenarNodos(){//Creacion de tabla de enrutamiento
    pair<vector<int>,vector<int>> results;
    orden.clear();
    rutas.clear();
    for (int i=0;i<nnodes;i++){
        results=revisarRuta(i);
        orden.push_back(results.first);
        rutas.push_back(results.second);
    }
}
pair<vector<int>,vector<int>> revisarRuta(int nodoinicial){ //Costo mínimo ALGORITMO DE DIJKSTRA
    pair<vector<int>,vector<int>> results;
    //V es de 0 a nnodos
    vector<int> novistos; //Revisar si ya está visto
    vector<int> costmin; //costo minimo del nodo inicial a los otros
    vector<int> predecesor; //vertice predecesor
    for (int i=0;i<nnodes;i++)
        novistos.push_back(i);
    novistos.erase(next(novistos.begin(),nodoinicial));
    for (int i=0;i<nnodes;i++){
            costmin.push_back(nodes[nodoinicial][i]);
            predecesor.push_back(nodoinicial);
    }
    for (int i=posminima(novistos,costmin);novistos.size()>0;i=posminima(novistos,costmin)){
            novistos.erase(next(novistos.begin(),checkPlace(novistos,i)));
            //int size=novistos.size();
            for (int j:novistos){
                if (costmin[j]>costmin[i]+nodes[i][j]){
                    costmin[j]=costmin[i]+nodes[i][j];
                    predecesor[j]=i;
                }
            }
            if (novistos.size()==0)
                break;
    }
    results.first=costmin;
    results.second=predecesor;
    return results;
}
int posminima(vector<int> pos,vector<int> cost){
    int c=0;
    int min;
    while (true){
    min=200;
    int size=cost.size();
    for (int i=0; i<size;i++){
        if (cost[i]<min && cost[i]>=0){
            c=i;
            min=cost[i];
        }
    }
    if (!cinvec(c,pos))
       cost[c]=200;

    else
        break;
    }
    return c;
}
bool cinvec(int num, std::vector<int> vec){
    int size=vec.size();
    for (int i=0;i<size;i++){
        if (vec[i]==num){
            return true;
        }
    }
    return false;
}
int checkPlace(vector<int> vec,int vab){
    int size=vec.size();
    int c=0;
    for (int i=0;i<size;i++){
        if (vec[i]==vab)
            c=i;
    }
    return c;
}
void normalizarNodos(){
    for (int i=0;i<nnodes;i++){
        for (int j=0;j<nnodes;j++){
            if (nodes[i][j]<0){
                nodes[i][j]=300;
            }
        }
    }
}
void entregarCamino(int inicio, int final){
    int placeholder;
    int paso=inicio;
    int llegada=final;
    cout<<"Camino de "<<char(inicio+65)<<" a "<<char(final+65)<<':'<<endl;
    //cout<<char(paso+65)<<" ";
    if (rutas[paso][llegada]!=inicio){
        cout<<char(inicio+65)<<" ";
    }
    do{
        placeholder=llegada;
        llegada=rutas[paso][llegada];
        paso=placeholder;
        cout<<char(llegada+65)<<" ";}
    while (llegada!=final);
    //cout<<char(llegada+65)<<" "<<endl;
}

#include <iostream>
using namespace std;
#include <vector>
#include <stdlib.h>
#include <time.h>
int main()
{
    vector<vector<int>> nodes;
    vector<int> vec;
    /* Random
    srand(time(0));
    //cantidad de nodos random
    int nnodes=rand()%26+1;
    for (int i=0;i<nnodes;i++){
        vec.clear();
        if (i>0){
            int k=0;
             while(k<nnodes){
                if (k<i){
                if (nodes[k][i]<=25){
                           vec.push_back(nodes[k][i]);
                           k++;
                      }}
                else{
                 if (i==k){
                      vec.push_back(0);
                      k++;
                     }
                  else{
                       vec.push_back(rand()%34);
                       k++;
                     }
                }
                  }
              }
        else{
        for (int j=0;j<nnodes;j++){
            if (i==j){
                vec.push_back(0);
            }
            else{
                vec.push_back(rand()%34);
            }
            }
        }
        nodes.push_back(vec);
    }*/
    /* Ingresar manual
    //cantidad de nodos
    int nnodes;
    int placeholder;
    cout<<"Numero de nodos a ingresar: ";
    cin>>nnodes;
    for (int i=0;i<nnodes;i++){
        cout<<"Ingresando nodo "<<char(i+65)<<endl;
        vec.clear();
        if (i>0){
            int k=0;
             while(k<nnodes){
                if (k<i){
                if (nodes[k][i]<=25){
                           vec.push_back(nodes[k][i]);
                           k++;
                      }}
                else{
                 if (i==k){
                      vec.push_back(0);
                      k++;
                     }
                  else{
                     cout<<"Ingrese el costo de la conexión con el nodo "<<char(k+65)<<" entre 0 y 25, si no quiere ingresar conexion escriba 30";
                     cin>>placeholder;
                       vec.push_back(placeholder);
                       k++;
                     }
                }
                  }
              }
        else{
        for (int j=0;j<nnodes;j++){
            if (i==j){
                vec.push_back(0);
            }
            else{
                cout<<"Ingrese el costo de la conexión con el nodo "<<char(j+65)<<" entre 0 y 25, si no quiere ingresar conexion escriba 30";
                cin>>placeholder;
                vec.push_back(placeholder);
            }
            }
        }
        nodes.push_back(vec);
    }*/
    for (int i = 0; i < nnodes; i++) {
            for (int j = 0; j < nnodes; j++)
                cout << nodes[i][j] << " ";
            cout << endl;
        }
    nodes.clear();
    return 0;
}

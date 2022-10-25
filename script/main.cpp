#include <iostream>
#include <horse.h>
#include <nqueens.h>
#include <insertionsort.h>

using namespace std;

void swap1(double* xp, double* yp)
{
    double temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void swap2(int* xp,int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void tabla_del_mejor(double tiempos[],int n){
    cout << "P | Tiempo" << endl;
    cout << "--|-------" << endl;
    int posicion[n];
    for(int x = 0;x<n;x++)
        posicion[x]=x+1;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (tiempos[j] < tiempos[j + 1]){
                swap1(&tiempos[j],&tiempos[j + 1]);
                swap2(&posicion[j],&posicion[j + 1]);
            }
    n--;
    while(n>=0){
        cout << posicion[n] << "  | " << tiempos[n] << endl;
        n--;
    }

}
void printorder(double a,double b,double c){
    cout << "P | Tiempo" << endl;
    cout << "--|-------" << endl;
    if(a < b){
        if(a<c){
            cout << "X | " << a << endl;
            if(b<c){
                cout << "Y | " << b << endl;
                cout << "Z | " << c << endl;
            }else{
                cout << "Z | " << c << endl;
                cout << "Y | " << b << endl;
            }
        }else{
            cout << "Z | " << c << endl;
            cout << "X | " << a << endl;
            cout << "Y | " << b << endl;
        }
    }else{
        if(b<c){
            cout << "Y | " << b << endl;
            if(a<c){
                cout << "X | " << a << endl;
                cout << "Z | " << c << endl;
            }else{
                cout << "Z | " << c << endl;
                cout << "X | " << a << endl;
            }
        }else{
            cout << "Z | " << c << endl;
            cout << "Y | " << b << endl;
            cout << "X | " << a << endl;
        }
    }
}

int main()
{
    int arr[100];
    srand(time(0));
    for(int i = 0;i < 100;i++)
        arr[i]=(rand() % 100 + 1);
    double x = horse();
    double y = nqueens();
    double z = insertionSort(arr,100);

    double tabla[3] = {x,y,z};
    tabla_del_mejor(tabla,3);
    //printorder(x,y,z);

}

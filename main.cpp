#include "headers/headers_prob1.h"
#include "headers/headers_prob2.h"

using namespace std;


int main(){
    srand(time(0)); // Initialize random seed

    int n = 10000000;
    int rn = rand()% 9999999;
    
    //cout <<"El numero buscado random es: "<< rn << endl;
    // Generar el arreglo lineal
    vector<int> x = arreglo(n);
    //printArray(x,"lineal");
    cout <<"EL numero buscado es: " <<rn <<endl;
    int t = x[9450000];
    cout <<"EL numero buscado es: " <<t <<endl;
    clock_t start_time2 = clock();
    vector<int> gc = gapCoding(x);
    int m = int(log10(n)); //
    vector<int> sample = createSample(x, m);
   
    int f = binarySearchGapCoded(gc, sample, t);
    clock_t end_time2 = clock();
    double elapsed_time2 = double(end_time2 - start_time2) / CLOCKS_PER_SEC;
    // Generar el arreglo con distribución normal
    vector<int> dn = distribucion(n);
    //printArray(dn, "normal");

    // Realizar la búsqueda binaria en el arreglo lineal
    clock_t start_time = clock();
    int index = binarySearch(x, 0, n - 1, t);
    clock_t end_time = clock();
    double elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC;

    // Realizar la búsqueda binaria en el arreglo con distribución normal
    clock_t start_time1 = clock();
    int indey = binarySearch(dn, 0, n - 1, t);
    clock_t end_time1 = clock();
    double elapsed_time1 = double(end_time1 - start_time1) / CLOCKS_PER_SEC;

    cout << "Posicion x: " <<index <<"; posicion y : "<< indey << "; posicion z: " << f <<endl;

    cout << "Tiempo de búsqueda en arreglo lineal: " << fixed << setprecision(8) << elapsed_time << " segundos" << endl;
    cout << "Tiempo de búsqueda en arreglo con distribución normal: " << fixed << setprecision(8) << elapsed_time1 << " segundos" << endl;
    cout << "Tiempo de búsqueda en arreglo con gp: " << fixed << setprecision(8) << elapsed_time2 << " segundos" << endl;
    return 0;
}

#include "headers/headers_prob1.h"


int binarySearch(vector<int> v, int low, int high, int x)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (v[mid] == x)
            return mid;

        if (v[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }
    return -1;
}

vector<int> arreglo(int n){
    vector<int> x(n);
    int e = 16;
    x[0] = 1;
    for(int i = 1; i < n; i++)
        x[i] = x[i-1] + rand() % e + 1;
    return x;
}

void printArray(const vector<int>& A, string nombre) {
    cout <<"El arreglo: "<< nombre <<endl;
    for (const auto& element : A)
        cout << element << " ";
    cout << endl;
}

vector<int> distribucion(int n){
    vector<int> array(n);

    // Definir el generador de números aleatorios
    random_device rd;
    mt19937 gen(rd());

    // Definir la distribución normal
    double mean = 0.0;
    double stddev = 300000.0;
    normal_distribution<> d(mean, stddev);

    for (int i = 0; i < n; ++i) {
        array[i] = std::round(d(gen));  // Redondear el número generado a entero
    }
    sort(array.begin(), array.end());
    return array;
}
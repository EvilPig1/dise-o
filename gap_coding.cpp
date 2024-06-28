#include "headers/headers_prob2.h"

vector<int> gapCoding(const vector<int>& arr) { //x = [2 5 5 6 8 10 15 16 20 24]    x.size = 10
    vector<int> gc(arr.size());
    gc[0] = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        gc[i] = arr[i] - arr[i-1];    //gc = [2 3 0 1 2 2 5 1 4 4]
        //cout << gc[i] << " ";
    }
    //cout<<endl;
    return gc;
}

vector<int> createSample(const vector<int>& arr, int m) {   //x = [2 5 5 6 8 10 15 16 20 24 25 30 39 42 49 52]
    int n = arr.size();                                         // 1 2 3 4 5  6  7  8  9 10 11 12 13 14 15 16
    int b = n / m;  //16 / 4 = 4
    cout << "B es: " << b <<endl;
    vector<int> sample(m);
    for (int i = 0; i < m; ++i) {
        sample[i] = arr[i * b];  // sample = [2 8 20 39]
        //cout << sample[i] << " ";
    }
    //cout <<endl;
    return sample;
}

int binarySearchGapCoded(const vector<int>& gc, const vector<int>& sample, int x) {  // x es el valor que estamos buscando x = 42
    int m = sample.size(); //m = 4       //                       x = [2 5 5 6 8 10 15 16 20 24 25 30 39 42 49 52]    
    int n = gc.size(); // n = 16    // sample = [2 8 20 39]      gc = [2 3 0 1 2 2 5 1 4 4 1 5 9 3 7 3]
    int b = n / m;  //  b = 4                
    int low = 0, high = m - 1;  // low = 0 high = 3
    int mid;
 
    
    while (low <= high) {
        mid = low + (high - low) / 2;    // mid = 1     => mid = 2+(3-2)/2 = 2   => mid = 3
        if (sample[mid] == x) {
            return mid * b;  // lo multiplicamos por b y deberiamos encontrar la posicion dentro del arreglo original
        } 
        else if (sample[mid] < x) {
            low = mid + 1;  // low = 2  => low = 3
        } 
        else {
            high = mid - 1; // high = 2
        }
    }

    int i = mid *b+1;  //i = 39
    vector<int> final;
    final.push_back(sample[mid]); // final = [39]    x = 42

    if(x > sample[mid]){
        for (int j = 0; j < i; j++){    //
            final.push_back(final[j]+gc[i]);
            if(final[j+1]== x)
                return i;
            else if(final[j+1] > x)
                return -1;
            i++;
        }        
    }
    else if(x < sample[mid]){
        int k = 0;
        for(int j = i-1; j > 0; j--){
            final.push_back(final[k]-gc[j]);
            if(final[k+1]== x)
                return j-1;
            else if(final[k+1] < x)
                return -1;
            k++;
        }
    }
 }

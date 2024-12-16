#include <iostream>
#include <vector>
#include <random>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int>& vec, int low, int high) {
    int pivot = vec[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        
        if (vec[j] <= pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }

    swap(vec[i + 1], vec[high]);
    return i + 1;
}

void quickSort(vector<int>& vec, int low, int high) {
    if (low < high) {
        int p = partition(vec, low, high);

        quickSort(vec, low, p - 1);
        quickSort(vec, p + 1, high);
    }
}

void printVector(vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

void fillVector(vector<int>& vec) {
    srand(time(NULL));
    for (int i = 0; i < 1000000; i++) {
        vec.push_back(rand());
    }
}

void testQuickSort() {
    vector<int> vec = { 10, 7, 8, 9, 1, 5 };
    cout << "easy case\n basic vector: ";
    printVector(vec);
    quickSort(vec, 0, vec.size() - 1);
    cout << "sorted vector: ";
    printVector(vec);
    cout << "\n";

    vector<int> vec2;
    fillVector(vec2);
    cout << "hard case\n";
    quickSort(vec2, 0, vec2.size() - 1);
    cout << "1.000.000 vector sorted!";
    //printVector(vec2);
    cout << "\n";

}

int main() {
    testQuickSort();
    return 0;
}
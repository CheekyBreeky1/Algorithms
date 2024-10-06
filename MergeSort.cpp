#include <iostream>
#include <vector>

using namespace std;


void mergeSort(vector<int>& arr) {

    if (arr.size() <= 1) {
        return; 
    }

    int mid = arr.size() / 2;

    vector<int> leftArr(arr.begin(), arr.begin() + mid);
    vector<int> rightArr(arr.begin() + mid, arr.end());

    mergeSort(leftArr);
    mergeSort(rightArr);

    int leftIndex = 0, rightIndex = 0, arrIndex = 0;

    while (leftIndex < leftArr.size() and rightIndex < rightArr.size()) {
        if (leftArr[leftIndex] <= rightArr[rightIndex]) {
            arr[arrIndex++] = leftArr[leftIndex++];
        }
        else {
            arr[arrIndex++] = rightArr[rightIndex++];
        }
    }

    while (leftIndex < leftArr.size()) {
        arr[arrIndex++] = leftArr[leftIndex++];
    }

    while (rightIndex < rightArr.size()) {
        arr[arrIndex++] = rightArr[rightIndex++];
    }
}
void testMergeSort() {
    int size = 500;
    vector<int> arr(size); 
    srand(static_cast<unsigned>(time(0)));

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000;
    }

    cout << "arr before:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    mergeSort(arr);

    cout << "arr after:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

}

int main()
{
    testMergeSort();
}

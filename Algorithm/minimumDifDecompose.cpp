#include <iostream>
#include <vector>

using namespace std;

void sortArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void decomposeArray(int arr[], int n, vector<int> *arr1, vector<int> *arr2) {
    int sum1 = 0, sum2 = 0;
    for (int i =0;i < n;i++) {
        if (sum1 <= sum2) {
            sum1 += arr[i];
            arr1->push_back(arr[i]);
        } else {
            sum2 += arr[i];
            arr2->push_back(arr[i]);
        }
    }
    while (arr1->size() > n/2) {
        int item = (*arr1)[arr1->size() - 1];
        arr1->pop_back();
        sum1 -= item;
        sum2 += item;
        arr2->push_back(item);
    }
    while (arr2->size() > n/2) {
        int item = (*arr2)[arr2->size() - 1];
        arr2->pop_back();
        sum2 -= item;
        sum1 += item;
        arr1->push_back(item);
    }
}

void printArray(vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sortArray(arr, n);
    vector<int> arr1, arr2;
    decomposeArray(arr, n, &arr1, &arr2);
    printArray(arr1);
    printArray(arr2);
    return 0;
}
#include <iostream>

using namespace std;

void sortArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    cin >> n; // We assume that n is even.
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sortArray(arr, n);
    for (int i = 0; i < n / 2; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = n / 2; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
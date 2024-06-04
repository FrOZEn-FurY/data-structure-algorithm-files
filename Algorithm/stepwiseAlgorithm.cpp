#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    int target;
    cin >> target;
    int i = 0, j = m - 1;
    while (i < n and j >= 0) {
        if (arr[i][j] == target) {
            cout << i + 1 << " " << j + 1 << endl;
            return 0;
        }
        else if (arr[i][j] > target) {
            j--;
        }
        else {
            i++;
        }
    }
    cout << "-1 -1" << endl;
    return 0;
}
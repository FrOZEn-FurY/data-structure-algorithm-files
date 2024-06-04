#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, maxLength = 0;
    cin >> n;
    int arr[n];
    vector<int> dp[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i].push_back(arr[i]);
        dp[i].push_back(1);
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] and dp[j][0] < arr[i] and dp[j][1] + 1 > dp[i][1]) {
                dp[i][0] = max(dp[j][0], arr[i]);
                dp[i][1] = dp[j][1] + 1;
            }
        }
        maxLength = max(maxLength, dp[i][1]);
    }
    cout << maxLength << endl;
    return 0;
}
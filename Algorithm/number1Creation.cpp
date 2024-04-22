#include <iostream>
#include <vector>

using namespace std;

void getDigits(vector<int> &vec, int x)
{
    while (x)
    {
        vec.push_back(x % 10);
        x /= 10;
    }
}

int calculateOnes(vector<int> &vec)
{
    int ans = vec[vec.size() - 1] * vec.size(), lastDigit = vec[vec.size() - 1], digitCntr = vec.size() - 1;
    for (int i = vec.size() - 2;i >= 0;i--)
    {
        int dif = abs(lastDigit - vec[i]);
        ans += digitCntr * dif;
        lastDigit = vec[i];
        digitCntr--;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> digits;
    getDigits(digits, n);
    int totalDigits = calculateOnes(digits);
    cout << totalDigits << endl;
    return 0;
}
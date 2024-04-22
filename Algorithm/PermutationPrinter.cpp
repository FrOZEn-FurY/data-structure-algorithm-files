#include <iostream>
#include <vector>

using namespace std;

int mark[10];
vector<int> vec;
int markCntr = 0;

void permutationPrinter(int number)
{
    if (markCntr == number)
    {
        for (int i = 0; i < vec.size() - 1; i++)
            cout << vec[i] << " ";
        cout << vec[vec.size() - 1] << endl;
        return;
    }
    for (int i = 1; i <= number; i++)
    {
        if (mark[i] == 1)
            continue;
        mark[i] = 1;
        markCntr++;
        vec.push_back(i);
        permutationPrinter(number);
        mark[i] = 0;
        markCntr--;
        vec.pop_back();
    }
}

int main()
{
    int n;
    cin >> n;
    permutationPrinter(n);
    return 0;
}
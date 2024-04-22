#include <iostream>

using namespace std;

int costs[5][5], mark[5], order[5];
int Min = 10000000, minTemp = 0, ord = 0;

void minFinder(int node, int parent)
{
    ord++;
    mark[node] = ord;
    for (int i = 0; i < 5; i++)
        if (i != node and mark[i] == 0)
        {
            minTemp += costs[node][i];
            minFinder(i, node);
        }
    if (minTemp < Min and ord == 5)
    {
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                if (mark[k] == j + 1)
                    order[j] = k + 1;
        Min = minTemp + costs[node][0];
    }
    mark[node] = 0;
    minTemp -= costs[parent][node];
    ord--;
}

int main()
{
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (i < j)
            {
                cout << "Enter the cost of " << i + 1 << " to " << j + 1 << ": ";
                cin >> costs[i][j];
            }
            else if (i > j)
                costs[i][j] = costs[j][i];
    minFinder(0, -1);
    cout << "The minimum cost is : " << Min << endl
         << "And the order of nodes will be : " << endl;
    for (int i = 0; i < 5; i++)
        cout << order[i] << " ";
    cout << "1" << endl;
    return 0;
}

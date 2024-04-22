#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<int> *metroLines;
int *mark;
pair<int, int> *minimumRoute;

void findMinimumRouteInInterSections(int currentLine, vector<pair<int, int>>* metroStations) {
    mark[currentLine] = 1;
    for (int i = 0; i < metroLines[currentLine].size(); i++) {
        if (minimumRoute[metroLines[currentLine][i]].second == -1 ||
            minimumRoute[metroLines[currentLine][i]].second < minimumRoute[currentLine].second + 1) {
            minimumRoute[metroLines[currentLine][i]].second = minimumRoute[currentLine].second + 1;
            minimumRoute[metroLines[currentLine][i]].first = currentLine;
        }
    }
    for (int i = 0; i < metroLines[currentLine].size(); i++) {
        if (mark[metroLines[currentLine][i]] != 0) {
            findMinimumRouteInInterSections(metroLines[currentLine][i], metroStations);
        }
    }
}

void initializeMetroStations(int n, vector<pair<int, int>>* metroStations) {
    for (int i = 1; i <= n; i++) {
        int m;
        cin >> m;
        for (int j = 1; j <= m; j++) {
            int k;
            cin >> k;
            if (k != 0) {
                pair<int, int> intersection;
                intersection.first = j;
                intersection.second = k;
                metroStations[i].push_back(intersection);
                metroLines[i].push_back(k);
                metroLines[k].push_back(i);
            }
        }
    }
}

int calculateLeastTime(int startLine, int startStation, int desLine, int desStation, vector<pair<int, int>>* metroStations, int n) {
    for (int i = 1; i <= n; i++) {
        minimumRoute[i].second = -1;
    }
    minimumRoute[startLine].first = startLine;
    minimumRoute[startLine].second = 0;
    findMinimumRouteInInterSections(startLine, metroStations);
    int leastTime = minimumRoute[desLine].second * 2;
    int station = desStation, line = desLine;
    while (true) {
        if (line == startLine) {
            leastTime += abs(startStation - station);
            break;
        }
        for (int i = 0; i < metroStations[line].size(); i++) {
            if (metroStations[line][i].second == minimumRoute[line].first) {
                leastTime += abs(metroStations[line][i].first - station);
                int lastLine = line;
                line = minimumRoute[line].first;
                for (int j = 0; j < metroStations[line].size(); j++) {
                    if (metroStations[line][j].second == lastLine) {
                        station = metroStations[line][j].first;
                    }
                }
                break;
            }
        }
    }
    return leastTime;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> metroStations[n + 1];
    metroLines = new vector<int>[n + 1];
    mark = new int[n + 1];
    minimumRoute = new pair<int, int>[n + 1];
    initializeMetroStations(n, metroStations);
    int startLine, startStation, desLine, desStation;
    cin >> startLine >> startStation >> desLine >> desStation;
    int leastTime = calculateLeastTime(startLine, startStation, desLine, desStation, metroStations, n);
    cout << leastTime << endl;
    return 0;
}

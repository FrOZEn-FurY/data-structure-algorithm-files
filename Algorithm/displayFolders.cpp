#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long int findExactIndent(const string& sample, int target, int startPos) {
    if (startPos > sample.size() - 1)
        return string::npos;
    string spaces = "";
    for (int i = 0; i < target; i++)
        spaces += ' ';
    long long int index = sample.find(spaces, startPos);
    if (index == string::npos)
        return string::npos;
    else if ((index - 1 >= 0 and sample[index - 1] != ' ') and (index + target < sample.size() and sample[index + target] != ' '))
        return index;
    return findExactIndent(sample, target, index + target);
}

void processInput(int n, int d, vector<string>& files, string& output) {
    while (n--) {
        string name;
        int parent;
        cin >> name >> parent;
        files.push_back(name);
        if (parent == 0)
            output += "|__" + name + '\n';
        else {
            int indexOfParent = output.find(files[parent - 1]);
            if (indexOfParent == string::npos)
                continue;
            int indentCntr = 0, spaceChar = indexOfParent - 4;
            while (output[spaceChar] == ' ') {
                indentCntr++;
                spaceChar--;
            }
            if (indentCntr / 3 + 2 > d)
                continue;
            string spaces = "";
            for (int i = 0; i < indentCntr; i++)
                spaces += ' ';
            if (indentCntr == 0) {
                output += "   |__" + name + '\n';
                continue;
            }
            long long int indexToInsert = findExactIndent(output, indentCntr, indexOfParent);
            spaces += "   ";
            if (indexToInsert == string::npos)
                output += spaces + "|__" + name + '\n';
            else
                output.insert(indexToInsert, spaces + "|__" + name + "\n");
        }
    }
}

int main() {
    int n, d;
    cin >> n >> d;
    vector<string> files;
    string output = "";
    processInput(n, d, files, output);
    cout << output << endl;
    return 0;
}

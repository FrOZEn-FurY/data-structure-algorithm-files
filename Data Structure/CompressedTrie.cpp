#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Node
{
    /*
        We assume that all the data given are with the small letters.
    */
    friend class CompressedTrie;
    int wordCntr = 0;   // Determines how many words have been registered through this node.
    int flag;           // Determines wither from the current node to the root is a meaningful word or not.
    Node *children[26]; // Maximum number of children.
    char data;          // Stores the data of current node.
public:
    Node() // Default constructor
    {
        flag = 0;
        wordCntr = 0;
        data = '.';
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class CompressedTrie
{
    Node *roots[26]; // For all possible alphabets, also 0 means 'a' and 25 means 'z'
public:
    CompressedTrie() // Default constructor
    {
        for (int i = 0; i < 26; i++) // Values the roots with a to z
        {
            roots[i] = new Node;
            roots[i]->data = 97 + i;
        }
    }
    void insert(string word) // Inserts a word into the tree.
    {
        int parentIndex = word[0] - 97;
        Node **filler = this->roots;
        filler[parentIndex]->wordCntr++;
        for (int i = 1; i < word.size(); i++)
        {
            int index = word[i] - 97;
            if (filler[parentIndex]->children[index] == NULL)
                filler[parentIndex]->children[index] = new Node;
            filler[parentIndex]->children[index]->wordCntr++;
            filler[parentIndex]->children[index]->data = word[i];
            filler = filler[parentIndex]->children;
            parentIndex = index;
        }
        filler[parentIndex]->flag = 1;
    }
    void remove(string word) // Removes a word from the tree
    {
        if (!this->search(word))
        {
            cout << "Can not remove '" << word << "' from the trie." << endl;
            return;
        }
        int parentIndex = word[0] - 97;
        Node **filler = roots;
        filler[parentIndex]->wordCntr--;
        filler[parentIndex]->flag = 0;
        for (int i = 1; i < word.size(); i++)
        {
            int index = word[i] - 97;
            filler[parentIndex]->children[index]->wordCntr--;
            filler = filler[parentIndex]->children;
            parentIndex = index;
        }
        filler[parentIndex]->flag = 0;
        cout << "The word '" << word << "' got removed from the trie." << endl;
    }
    bool search(string target) // Searches for a prefix, or a complete word.
    {
        if (target.find("*") != string::npos and target.size() != 1)
        {
            int parentIndex = target[0] - 97, index = 1;
            Node **filler = roots;
            while (index < target.size() - 1 and filler[parentIndex] != NULL)
            {
                filler = filler[parentIndex]->children;
                parentIndex = target[index] - 97;
                index++;
            }
            vector<string> vec;
            this->searchInside(&vec, filler, parentIndex, target.substr(0, target.size() - 1));
            cout << "Words found with the prefix '" << target.substr(0, target.size() - 1) << "' are: " << endl;
            for (int i = 0; i < vec.size() - 1; i++)
                cout << vec[i] << " ";
            cout << vec[vec.size() - 1] << endl;
        }
        else if (target.find("*") != string::npos and target.size() == 1)
        {
            vector<string> vec;
            Node **filler = roots;
            for (int i = 0; i < 26; i++)
            {
                string temp = "";
                temp += filler[i]->data;
                this->searchInside(&vec, filler, i, temp);
            }
            cout << "With *, you requested the whole trie, and here it is: " << endl;
            for (int i = 0; i < vec.size() - 1; i++)
                cout << vec[i] << " ";
            cout << vec[vec.size() - 1] << endl;
        }
        else
        {
            int parentIndex = target[0] - 97, index = 1;
            Node **filler = roots;
            while (index < target.size() and filler[parentIndex] != NULL)
            {
                filler = filler[parentIndex]->children;
                parentIndex = target[index] - 97;
                index++;
            }
            if (filler[parentIndex] == NULL or filler[parentIndex]->flag == 0)
            {
                cout << "The word '" << target << "' is not in the compressed trie." << endl;
                return false;
            }
            else
                cout << "The word '" << target << "' found in the trie." << endl;
        }
        return true;
    }
    void searchInside(vector<string> *vec, Node **initialArray, int index, string prefix) // Searches inside the children of a node, and appends the found words in the vector.
    {
        bool checkChildren = false;
        for (int i = 0; i < 26; i++)
            if (initialArray[index]->children[i] != NULL)
                checkChildren = true;
        if (!checkChildren)
            return;
        for (int i = 0; i < 26; i++)
        {
            if (initialArray[index]->children[i] != NULL and initialArray[index]->children[i]->flag == 1)
                vec->push_back(prefix + initialArray[index]->children[i]->data);
            if (initialArray[index]->children[i] != NULL)
                searchInside(vec, initialArray[index]->children, i, prefix + initialArray[index]->children[i]->data);
        }
    }
};

int main() // Using the trie :)
{
    CompressedTrie ct;
    ct.insert("apple");
    ct.insert("app");
    ct.insert("ape");
    ct.insert("bat");
    ct.insert("big");
    ct.insert("automata");
    ct.insert("automation");
    ct.insert("automatic");
    ct.insert("automaton");
    ct.search("apple");
    ct.search("automat*");
    ct.search("ape");
    ct.remove("ape");
    ct.search("ape");
    ct.search("milk");
    ct.remove("milk");
    ct.search("ap*");
    ct.search("*");
    return 0;
}
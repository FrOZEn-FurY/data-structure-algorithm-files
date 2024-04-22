#include <iostream>

using namespace std;

class Linkedlist;
class Node
{
    friend void InsertionSort(Linkedlist *, int);
    friend class Linkedlist;
    int data;
    Node *link, *parent;

public:
    Node()
    {
        data = NULL;
        link = NULL;
        parent = NULL;
    }
    Node(int d)
    {
        data = d;
        link = NULL;
        parent = NULL;
    }
};

class Linkedlist
{
    Node *root;
    friend void InsertionSort(Linkedlist *, int);

public:
    Linkedlist()
    {
        root = NULL;
    }
    void push(int data)
    {
        if (root == NULL)
            root = new Node(data);
        else
        {
            Node *temp = root;
            while (temp->link != NULL)
                temp = temp->link;
            Node *node = new Node(data);
            temp->link = node;
            node->parent = temp;
        }
    }
    void print_elements()
    {
        Node *temp = root;
        while (temp->link != NULL)
        {
            cout << temp->data << " ";
            temp = temp->link;
        }
        cout << temp->data << endl;
    }
};

void InsertionSort(Linkedlist *l, int n)
{
    if (l->root->link == NULL or l->root->data == NULL)
        return;
    Node *temp = l->root;
    Node *temp2 = temp;
    for (int i = 2; i <= n; i++)
    {
        while (temp2->parent != NULL and temp2->data < temp2->parent->data)
        {
            int temp3 = temp2->data;
            temp2->data = temp2->parent->data;
            temp2->parent->data = temp3;
            temp2 = temp2->parent;
        }
        temp = temp->link;
        temp2 = temp;
    }
    while (temp2->parent != NULL and temp2->data < temp2->parent->data)
    {
        int temp3 = temp2->data;
        temp2->data = temp2->parent->data;
        temp2->parent->data = temp3;
        temp2 = temp2->parent;
    }
}

int main()
{
    Linkedlist l;
    int n;
    cout << "Enter the amount of numbers: ";
    cin >> n;
    cout << "Enter the numbers: " << endl;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        l.push(a);
    }
    cout << "Your list of numbers is : " << endl;
    l.print_elements();
    InsertionSort(&l, n);
    cout << "And your sorted list is :" << endl;
    l.print_elements();
    return 0;
}
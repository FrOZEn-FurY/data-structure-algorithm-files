#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *link;
    Node()
    {
        data = NULL;
        link = NULL;
    }
    Node(int d)
    {
        data = d;
        link = NULL;
    }
};

class LinkedList
{
    Node root;
    static int numberOfDisplays;
public:
    void push(int data)
    {
        if (root.data == NULL)
            root.data = data;
        else
        {
            Node *temp = &root;
            while (temp->link != NULL)
                temp = temp->link;
            Node *newNode = new Node(data);
            temp->link = newNode;
        }
    }
    int pop()
    {
        if (root.data == NULL)
            return -1;
        else
        {
            Node *tempDelete = &root, *tempBefore = &root;
            while (tempDelete->link != NULL)
            {
                tempBefore = tempDelete;
                tempDelete = tempDelete->link;
            }
            if (tempDelete->link == tempBefore->link)
            {
                int data = root.data;
                root.data = NULL;
                root.link = NULL;
                return data;
            }
            int data = tempDelete->data;
            tempBefore->link = tempDelete->link;
            return data;
        }
    }
    void display()
    {
        Node temp = root;
        cout << numberOfDisplays << " Times of display: " << endl;
        numberOfDisplays++;
        while (temp.link != NULL)
        {
            cout << temp.data << " ";
            temp = *(temp.link);
        }
        if (temp.data != NULL)
            cout << temp.data;
        cout << endl;
    }
};

int LinkedList::numberOfDisplays = 1;

int main()
{
    LinkedList l;
    l.display();
    l.push(1);
    l.push(2);
    l.push(3);
    l.display();
    l.pop();
    l.pop();
    l.display();
    return 0;
}
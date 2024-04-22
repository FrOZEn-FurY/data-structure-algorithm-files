#include <iostream>

using namespace std;

void swap(int *x, int *y) // Use this function to swap values.
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

class List;
class Element
{
    /*
        This is the class used for the elements of the list.
        each element has a value (data), a link to the next element and a parent pointer to its parent.
    */
    friend class List;
    int data;
    Element *link, *parent;

public:
    Element()
    {
        data = NULL;
        link = NULL;
        parent = NULL;
    }
    Element(int d)
    {
        data = d;
        link = NULL;
        parent = NULL;
    }
};

class List
{
    /*
        This is the class for the list.
        it uses Element class to make its datas.
    */
    Element *root;

public:
    List()
    {
        root = NULL;
    }
    void push(int data) // Adding a new element to the end of the list.
    {
        if (root == NULL)
            root = new Element(data);
        else
        {
            Element *temp = root;
            while (temp->link != NULL)
                temp = temp->link;
            Element *newNode = new Element(data);
            temp->link = newNode;
            newNode->parent = temp;
        }
    }
    void display() // Priting all the elements.
    {
        Element *temp = root;
        while (temp->link != NULL)
        {
            cout << temp->data << " ";
            temp = temp->link;
        }
        cout << temp->data << endl;
    }
    void InsertionSort() // A function to do the insertion sort on the list. We could use an outside function as well but this will make our life easier.
    {
        if (root == NULL or root->link == NULL) // Lists with the length of 0 or 1 can not be sorted.
            return;
        else
        {
            Element *temp = root->link; // Starting the sort from the second element all the way to the end.
            Element *tempSorter = temp;
            do // This while will traverse on the list and sorts it
            {
                while (tempSorter->parent != NULL and tempSorter->data < tempSorter->parent->data) // For each element, we must find its place in the list using insertion sort.
                {
                    swap(&(tempSorter->data), &(tempSorter->parent->data));
                    tempSorter = tempSorter->parent;
                }
                temp = temp->link;
                tempSorter = temp;
            } while (temp != NULL); // Note that the ordered list is on the left side of the list and the unordered one is on the right.
        }
    }
    /*
        We don't need pop, remove or any other known function for the list.
        This functions do the job for us.
    */
};

int main() // In the main, we just make a list and sort it to show the result.
{
    List l;
    l.push(3);
    l.push(4);
    l.push(2);
    l.push(3);
    l.push(10);
    l.push(1);
    l.push(5);
    l.push(20);
    l.push(16);
    cout << "The unsorted list: " << endl;
    l.display();
    l.InsertionSort();
    cout << "The sorted list: " << endl;
    l.display();
    return 0;
}
#include <iostream>

using namespace std;

class minHeap
{
    int maxSize, cntr = 1; // maxSize is for the size of the tree and cntr is for valuing the nodes. In fact cntr is the number of numbers added so far.
    int *tree;             // The array for the tree.
public:
    minHeap(int size) // We get the size in the initialaztion, and make an empty tree.
    {
        maxSize = size + 1;
        tree = new int[maxSize];
        for (int i = 0; i < maxSize; i++)
            tree[i] = -1;
    }
    void add(int data)
    {
        /*
            Simply adds a value to the array.
            After all the values added, for 1<=i<=n, [i/2] is the parent of the node, 2i is the left child and 2i + 1 is the right child.
            We also check for the minHeap conditions.
        */
        tree[cntr] = data;
        cntr++;
        int i = cntr - 1;
        while (tree[i] < tree[i / 2] and i >= 1) // We must assure that the added value is in the right place of the tree.
        {
            int temp = tree[i];
            tree[i] = tree[i / 2];
            tree[i / 2] = temp;
            i /= 2;
        }
    }
    int remove()
    {
        cntr--;
        int ret = tree[1];
        tree[1] = tree[cntr];
        tree[cntr] = -1;
        int i = 1;
        while (2 * i < cntr and tree[2 * i] != -1) // Checking to see if the value is in the right place. We don't check for 2i+1 < size becuase it will be checked in this condition aswell.
            if (tree[2 * i] < tree[2 * i + 1] and tree[i] > tree[2 * i])
            {
                int temp = tree[2 * i];
                tree[2 * i] = tree[i];
                tree[i] = temp;
                i *= 2;
            }
            else if (tree[2 * i + 1] != -1 and tree[2 * i + 1] <= tree[2 * i] and tree[i] > tree[2 * i + 1])
            {
                int temp = tree[2 * i + 1];
                tree[2 * i + 1] = tree[i];
                tree[i] = temp;
                i = 2 * i + 1;
            }
            else
                break;
        return ret;
    }
    /*
        Now we do the heap sort in the main using the remove function.
    */
};

int main()
{
    int n;
    cout << "Enter the number of numbers: ";
    cin >> n; // Getting the size
    minHeap heap(n);
    int array[n]; // Just for storing the numbers
    cout << "Enter your numbers :" << endl;
    for (int i = 0; i < n; i++) // Getting numbers
    {
        int a;
        cin >> a;
        array[i] = a;
        heap.add(a);
    }
    cout << "Your numbers are: " << endl;
    for (int i = 0; i < n; i++) // Displaying the numbers unsorted
        cout << array[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++) // Heap sort, this is ascending sortion and it uses the remove function of minHeap to sort the elements stored in the heap.
        array[i] = heap.remove();
    cout << "And this is when they are sorted: " << endl;
    for (int i = 0; i < n; i++) // Displaying the numbers sorted
        cout << array[i] << " ";
    cout << endl;
    return 0;
}
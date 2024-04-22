#include <iostream>

using namespace std;

class FenwickTree
{
    int *tree; // Stores the data of the tree.
    int maxSize, cntr; // Maximum size of the tree, and a cntr that shows the amount of numbers inserted into the tree.
    public:
        FenwickTree(int size)
        {
            maxSize = size;
            cntr = 0;
            tree = new int[maxSize + 1]; // 1 indexed
            for (int i = 1;i < maxSize + 1;i++)
                tree[i] = 0; 
        }
        void update(int data) // Inserts a new value to the tree, and update the tree with the coresponding value.
        {
            if (cntr == maxSize)
            {
                cout << "The Fenwick tree is full!" << endl;
                return;
            }
            cntr++;
            tree[cntr] += data;
            int index = cntr;
            while (index < maxSize + 1)
            {
                index = index + (index & (-index));
                tree[index] += data;
            }
        }
        int getSum(int index) // Returns the sum of first index elements.
        {
            if (index > maxSize)
            {
                cout << "Can't get sum of the first " << index << " values! Returning -1 instead." << endl;
                return -1;
            }
            int sum  = 0;
            while (index >= 1)
            {
                sum += tree[index];
                index = index - (index & (-index));
            }
            return sum;
        }
};

int main()
{
    FenwickTree ft(12);
    ft.update(2);
    ft.update(1);
    ft.update(1);
    ft.update(3);
    ft.update(2);
    ft.update(3);
    ft.update(4);
    ft.update(5);
    ft.update(6);
    ft.update(7);
    ft.update(8);
    ft.update(9);
    ft.update(15);
    cout << ft.getSum(8) << endl;
    cout << ft.getSum(12) << endl;
    cout << ft.getSum(4) << endl;
    cout << ft.getSum(7) << endl;
    cout << ft.getSum(3) << endl;
    cout << ft.getSum(11) << endl;
    cout << ft.getSum(16) << endl;
    return 0;
}
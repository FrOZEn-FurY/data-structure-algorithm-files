#include <iostream>
#include <algorithm>

using namespace std;

class Node // Class representing the node of the tree.
{
    friend class MinMaxHeap;
    int data; // The data the gets stored in the node
    int min;  // Minimum value in the subtree of the node.
    int max;  // Maximum value in the subtree of the node.
public:
    Node() // Default constructor.
    {
        data = -1;
        min = -1;
        max = -1;
    }
};

class MinMaxHeap // Class for the max-min heap data structure.
{
    int maxSize, cntr = 1; // Value maxSize is the number of values in the array, and cntr is number of values added.
    Node *tree;            // Array of nodes representing the tree.
    int minIndexFinder(int c1, int c2, int c3, int c4)
    {
        if (tree[c2].data != -1 and tree[c1].data < tree[c2].data)
        {
            if (tree[c3].data != -1 and tree[c1].data < tree[c3].data)
            {
                if (tree[c4].data != -1 and tree[c1].data < tree[c4].data)
                    return c1;
                else if (tree[c4].data != -1 and tree[c4].data <= tree[c1].data)
                    return c4;
            }
            else if (tree[c3].data != -1 and tree[c3].data <= tree[c1].data)
            {
                if (tree[c4].data != -1 and tree[c3].data < tree[c4].data)
                    return c3;
                else if (tree[c4].data != -1 and tree[c4].data <= tree[c3].data)
                    return c4;
            }
        }
        else if (tree[c2].data != -1 and tree[c2].data <= tree[c1].data)
        {
            if (tree[c3].data != -1 and tree[c2].data < tree[c3].data)
            {
                if (tree[c4].data != -1 and tree[c2].data < tree[c4].data)
                    return c2;
                else if (tree[c4].data != -1 and tree[c4].data <= tree[c2].data)
                    return c4;
            }
            else if (tree[c3].data != -1 and tree[c3].data <= tree[c2].data)
            {
                if (tree[c4].data != -1 and tree[c3].data < tree[c4].data)
                    return c3;
                else if (tree[c4].data != -1 and tree[c4].data <= tree[c3].data)
                    return c4;
            }
        }
        return c1; // We assume c1 the default value to return.
    }
    int maxIndexFinder(int c1, int c2, int c3, int c4)
    {
        if (tree[c2].data != -1 and tree[c1].data > tree[c2].data)
        {
            if (tree[c3].data != -1 and tree[c1].data > tree[c3].data)
            {
                if (tree[c4].data != -1 and tree[c1].data > tree[c4].data)
                    return c1;
                else if (tree[c4].data != -1 and tree[c4].data >= tree[c1].data)
                    return c4;
            }
            else if (tree[c3].data != -1 and tree[c3].data >= tree[c1].data)
            {
                if (tree[c4].data != -1 and tree[c3].data > tree[c4].data)
                    return c3;
                else if (tree[c4].data != -1 and tree[c4].data >= tree[c3].data)
                    return c4;
            }
        }
        else if (tree[c2].data != -1 and tree[c2].data >= tree[c1].data)
        {
            if (tree[c3].data != -1 and tree[c2].data > tree[c3].data)
            {
                if (tree[c4].data != -1 and tree[c2].data > tree[c4].data)
                    return c2;
                else if (tree[c4].data != -1 and tree[c4].data >= tree[c2].data)
                    return c4;
            }
            else if (tree[c3].data != -1 and tree[c3].data >= tree[c2].data)
            {
                if (tree[c4].data != -1 and tree[c3].data > tree[c4].data)
                    return c3;
                else if (tree[c4].data != -1 and tree[c4].data >= tree[c3].data)
                    return c4;
            }
        }
        return c1; // We assume c1 the default value to return.
    }
public:
    MinMaxHeap(int size) // Constructor that gets the size of the heap.
    {
        maxSize = size + 1;
        tree = new Node[maxSize];
    }
    void add(int value) // Adds a new value to the heap.
    {
        tree[cntr].data = value;
        tree[cntr].min = value;
        tree[cntr].max = value;
        if (cntr == 1)
        {
            cntr++;
            return;
        }
        int index = cntr;
        int parentIndex = index / 2;
        while (parentIndex >= 1)
        {
            int copy = parentIndex;
            int height = 0;
            while (copy > 1) // Getting the height of the parent.
            {
                copy /= 2;
                height++;
            }
            if (height % 2 == 0 and tree[index].data < tree[parentIndex].data) // Parent is in min level.
            {
                swap(tree[index].data, tree[parentIndex].data);
                if (index * 2 > cntr)
                {
                    tree[index].min = tree[index].data;
                    tree[index].max = tree[index].data;
                }
                int copyIndex = index;
                while (copyIndex >= parentIndex) // By each swap, we must update the max and min all the way to the updated node.
                {
                    if (tree[copyIndex].min < tree[copyIndex / 2].min)
                        tree[copyIndex / 2].min = tree[copyIndex].min;
                    if (tree[copyIndex].max > tree[copyIndex / 2].max)
                        tree[copyIndex / 2].max = tree[copyIndex].max;
                    copyIndex /= 2;
                }
                index = parentIndex;
            }
            else if (height % 2 == 1 and tree[index].data > tree[parentIndex].data) // Parent is in max level.
            {
                swap(tree[index].data, tree[parentIndex].data);
                if (index * 2 > cntr)
                {
                    tree[index].min = tree[index].data;
                    tree[index].max = tree[index].data;
                }
                int copyIndex = index;
                while (copyIndex >= parentIndex) // By each swap, we must update the max and min all the way to the updated node.
                {
                    if (tree[copyIndex].min < tree[copyIndex / 2].min)
                        tree[copyIndex / 2].min = tree[copyIndex].min;
                    if (tree[copyIndex].max > tree[copyIndex / 2].max)
                        tree[copyIndex / 2].max = tree[copyIndex].max;
                    copyIndex /= 2;
                }
                index = parentIndex;
            }
            if (tree[index].max > tree[parentIndex].max) // Updating the max up to the root.
                tree[parentIndex].max = tree[index].max;
            if (tree[index].min < tree[parentIndex].min) // Updating the min up to the root.
                tree[parentIndex].min = tree[index].min;
            parentIndex /= 2;
        }
        cntr++;
    }
    int findMaxByValue() // Returns the maximum value in the heap.
    {
        return tree[2].data > tree[3].data ? tree[2].data : tree[3].data;
    }
    int findMinByValue() // Returns the minimum value in the heap.
    {
        return tree[1].data;
    }
    int removeMin() // Removes the minimum value in the heap.
    {
        cntr--;
        int ret = tree[1].data;
        tree[1] = tree[cntr];
        tree[cntr].data = -1;
        tree[cntr].max = -1;
        tree[cntr].min = -1;
        int index = 1;
        int child1 = 4, child2 = 5, child3 = 6, child4 = 7;
        while (child1 < cntr)
        {
            int minIndex = minIndexFinder(child1, child2, child3, child4);
            if (tree[minIndex].data < tree[index].data)
            {
                swap(tree[index].data, tree[minIndex].data);
                tree[index].min = tree[index].data;
                if (tree[minIndex / 2].min > tree[minIndex].min)
                    tree[minIndex / 2].min = tree[minIndex].min; 
            }
            else
                break;
            index = minIndex;
            child1 = 4 * minIndex;
            child2 = 4 * minIndex + 1;
            child3 = 4 * minIndex + 2;
            child4 = 4 * minIndex + 3;
        }
        if (2 * index < cntr and tree[index].data > tree[2 * index].data)
            swap(tree[index].data, tree[2 * index].data);
        if (2 * index + 1 < cntr and tree[index].data > tree[2 * index + 1].data) // We don't care about the rotation of the leaves, as long as the conditions for min-max heap is met.
            swap(tree[index].data, tree[2 * index + 1].data);
        return ret;
    }
    int removeMax() // Removes the maximum value in the heap.
    {
        cntr--;
        int bigIndex = tree[2].data > tree[3].data ? 2 : 3;
        int ret = tree[bigIndex].data;
        tree[bigIndex] = tree[cntr];
        tree[cntr].data = -1;
        tree[cntr].max = -1;
        tree[cntr].min = -1;
        int child1 = 4 * bigIndex, child2 = 4 * bigIndex + 1, child3 = 4 * bigIndex + 2, child4 = 4 * bigIndex + 3;
        while (child1 < cntr)
        {
            int maxIndex = maxIndexFinder(child1, child2, child3, child4);
            if (tree[bigIndex].data < tree[maxIndex].data)
            {
                swap(tree[bigIndex].data, tree[maxIndex].data);
                tree[bigIndex].max = tree[bigIndex].data;
                if (tree[maxIndex / 2].max > tree[maxIndex].max)
                    tree[maxIndex / 2].max = tree[maxIndex].max; 
            }
            else
                break;
            bigIndex = maxIndex;
            child1 = 4 * maxIndex;
            child2 = 4 * maxIndex + 1;
            child3 = 4 * maxIndex + 2;
            child4 = 4 * maxIndex + 3;
        }
        if (2 * bigIndex < cntr and tree[bigIndex].data < tree[2 * bigIndex].data)
            swap(tree[bigIndex].data, tree[2 * bigIndex].data);
        if (2 * bigIndex + 1 < cntr and tree[bigIndex].data < tree[2 * bigIndex + 1].data) // We don't care about the rotation of the leaves, as long as the conditions for min-max heap is met.
            swap(tree[bigIndex].data, tree[2 * bigIndex + 1].data);
        return ret;
    }
    void showHeap()
    {
        for (int i = 1;i < cntr - 1;i++)
            cout << tree[i].data << " ";
        cout << tree[cntr - 1].data << endl;
    }
};

int main()
{
    MinMaxHeap heap(10);
    heap.add(5);
    heap.add(7);
    heap.add(12);
    heap.add(3);
    heap.add(2);
    heap.add(6);
    heap.add(9);
    heap.add(8);
    heap.add(1);
    heap.add(10);
    heap.showHeap();
    cout << "The max value is : " << heap.findMaxByValue() << endl;
    cout << "The min value is : " << heap.findMinByValue() << endl;
    int value = heap.removeMin();
    cout << value << " got removed." << endl;
    heap.showHeap();
    value = heap.removeMax();
    cout << value << " got removed." << endl;
    heap.showHeap();
    return 0;
}


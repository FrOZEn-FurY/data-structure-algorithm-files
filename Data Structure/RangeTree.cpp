#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Point // Class of a point in the 2-dimension.
{
    friend class Node;
    friend class RangeTree;
    int x, y;

public:
    Point() // Default constructor.
    {
        x = -1;
        y = -1;
    }
    void setX(int X) { x = X; } // Setter for value of X.
    void setY(int Y) { y = Y; } // Setter for value of Y.
    int retX() { return x; } // Getter of the value X.
    int retY() { return y; } // Getter of the value Y.
    bool operator==(const Point& p) // Overloading the == operator.
    {
        return this->x == p.x and this->y == p.y;
    }
};

class Node // Node of a tree.
{
    friend class RangeTree;
    Point *data;  // Each node has a 2D point.
    Node *left;  // Left child.
    Node *right; // Right child.

public:
    Node() // Default constructor.
    {
        left = NULL;
        right = NULL;
        data = new Point;
        data->x = -1;
        data->y = -1;
    }
};

class RangeTree // Class for the range tree.
{
    Node *root;
    int maxSize;
    static bool sortCondition(const Point& p1, const Point& p2) // This function determines how the array of pointers get sorted.
    {
        return p1.y < p2.y;
    }
    void insert(Node *&n ,Point p) // Inserts a new node into the tree.
    {
        if (n == NULL)
        {
            n = new Node;
            *(n->data) = p;
            return;
        }
        if (p.x < n->data->x)
            insert(n->left, p);
        else
            insert(n->right, p);
    }
    void rangeQuery(vector<Point> *vec, int x1, int x2, int y1, int y2, Node *start) // Returns the points that satisfy the range query asked.
    {
        if (start == NULL)
            return;
        if (start->data->x >= x1 and start->data->x <= x2)
            vec->push_back(*(start->data));
        rangeQuery(vec, x1, x2, y1, y2, start->left);
        rangeQuery(vec, x1, x2, y1, y2, start->right);
        for (int i = 0;i < vec->size();i++)
            if (!(((*vec)[i]).y >= y1 and ((*vec)[i]).y <= y2))
                vec->erase(remove(vec->begin(), vec->end(), (*vec)[i]), vec->end());
    }
    Node *construct(Point *points, int startIndex, int endIndex) // Constructs the tree with the given points.
    {
        if (startIndex > endIndex)
            return NULL;
        sort(points+startIndex, points+endIndex, sortCondition); // We sort the array of points by their Y axis, and then construct the tree using the x axis.
        int mid = (startIndex + endIndex) / 2;
        Node *temp = new Node;
        temp->left = construct(points, startIndex, mid - 1);
        temp->right = construct(points, mid + 1, endIndex);
        *(temp->data) = points[mid];
        return temp;
    }
public:
    RangeTree(Point *points, int size) // Constructor for making the tree.
    {
        maxSize = size;
        root = construct(points, 0, size);
    }
    void insert(Point p) // User usable function to insert a new node.
    {
        insert(root, p);
    }
    void rangeQuery(vector<Point> *vec, int x1, int x2, int y1, int y2) // User useable function to use the query set function.
    {
        rangeQuery(vec, x1, x2, y1, y2, root);
    }
};

int main() // Using the Range Tree data structure.
{
    Point points[5];
    points[0].setX(25);
    points[0].setY(2500);
    points[1].setX(45);
    points[1].setY(5000);
    points[2].setX(33);
    points[2].setY(4500);
    points[3].setX(31);
    points[3].setY(3000);
    points[4].setX(21);
    points[4].setY(7000);
    RangeTree rt(points, 5);
    vector<Point> result;
    rt.rangeQuery(&result, 25, 35, 3000, 5000);
    cout << "The employees in the given age range and salary range are: " << endl;
    for (int i = 0;i < result.size()-1;i++)
        cout << "(" << result[i].retX() << ", " << result[i].retY() << "), ";
    cout << "(" << result[result.size() - 1].retX() << ", " << result[result.size() - 1].retY() << ")" << endl;
    result.clear();
    Point p;
    p.setX(30);
    p.setY(4500);
    rt.insert(p);
    rt.rangeQuery(&result, 25, 35, 3000, 5000);
    cout << "The employees in the given age range and salary range are: " << endl;
    for (int i = 0;i < result.size()-1;i++)
        cout << "(" << result[i].retX() << ", " << result[i].retY() << "), ";
    cout << "(" << result[result.size() - 1].retX() << ", " << result[result.size() - 1].retY() << ")" << endl;
    return 0;
}
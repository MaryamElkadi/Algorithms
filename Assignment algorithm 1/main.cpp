
// A divide and conquer program in C++
// to find the smallest distance from a
// given set of points.

#include <bits/stdc++.h>
using namespace std;


class Point  //class to represent 2D points (array) used in functions
{
    public:
    int x, y;
};




int compareX(const void* a, const void* b) //sort array according to x coordinate
{
    Point *p1 = (Point *)a, *p2 = (Point *)b; //pointers
    return (p1->x - p2->x);
}


int compareY(const void* a, const void* b)  //sort array according to x coordinate
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->y - p2->y);  //pointers
}


float distenc(Point p1, Point p2)  //rule to find the distenc between two points
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                (p1.y - p2.y)*(p1.y - p2.y)
            );  //the rule in the question
}


float bruteForce(Point P[], int n)  //this method return the smallest distenc between any two points in the all arrays
{
    float min = FLT_MAX;  //and return it the smallest
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (distenc(P[i], P[j]) < min)
                min = distenc(P[i], P[j]);
    return min;
}


float min(float x, float y)  //fin min between two points
{
    if (x<y)
        return x;
    else
        return y;

}



float stripClosest(Point strip[], int size, float m)
{ //find and closest path in the vertical line in middle of points
    float min = m; // Initialize the minimum distance as m

    qsort(strip, size, sizeof(Point), compareY); //sorts the array




    for (int i = 0; i < size; ++i)  // between y coordinates is smaller than m.
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j) //and compare in all points
            if (distenc(strip[i],strip[j]) < min)
                min = distenc(strip[i], strip[j]); //the result of min

    return min;
}



float closestUtil(Point P[], int g) // g=size
//  find the smallest all points sorted according to x coordinate
{
    // If there are 2 or 3 points, then use brute force
    if (g <= 3)
        return bruteForce(P, g);

    // Find the middle point
    int mid =g/2;
    Point midPoint = P[mid];


    float dl = closestUtil(P, mid); //dl the array in the left (the smallest)

    float dr = closestUtil(P + mid, g - mid); //dr the array in the right(the smallest)

    // Find the smaller of two distances
    float d = min(dl, dr);

    Point strip[g];
    int j = 0;
    for (int i = 0; i < g; i++)
        if (abs(P[i].x - midPoint.x) <g)
            strip[j] = P[i], j++;


    return min(g, stripClosest(strip, j,g) );  // Find the closest points in strip.
}


float closest(Point P[], int g)
{ // The main function that finds the smallest distance

    qsort(P,g, sizeof(Point), compareX);

    // Use recursive function closestUtil()
    // to find the smallest distance
    return closestUtil(P, g);
}

//test case
int main()
{

   Point P[] = {{7, 4}, {45, 22}, {20, 10}, {9, 1}, {21, 9}, {4, 4}};
    int g = sizeof(P) / sizeof(P[0]);
    cout << "The smallest distance is " << closest(P, g);
    return 0;


}

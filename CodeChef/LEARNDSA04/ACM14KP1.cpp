// A divide and conquer sol. for 2 points modified for three points sourced from : https://www.geeksforgeeks.org/closest-pair-of-points-using-divide-and-conquer-algorithm/

#include <bits/stdc++.h> 
using namespace std; 

// A structure to represent a Point in 2D plane 
class Point 
{ 
	public: 
	    double x, y; 
}; 

/* Following two functions are needed for library function qsort(). 
Refer: http://www.cplusplus.com/reference/clibrary/cstdlib/qsort/ */

int compareX(const void* a, const void* b) 
{ 
	Point *p1 = (Point *)a, *p2 = (Point *)b; 
	return (p1->x - p2->x); 
} 

int compareY(const void* a, const void* b) 
{ 
	Point *p1 = (Point *)a, *p2 = (Point *)b; 
	return (p1->y - p2->y); 
} 

double dist(Point p1, Point p2) 
{ 
	return sqrt( (p1.x - p2.x)*(p1.x - p2.x) + 
				(p1.y - p2.y)*(p1.y - p2.y) 
			); 
} 

double bruteForce(Point P[], int n) 
{ 
	double min = DBL_MAX; 
    if(n < 3) 
        return DBL_MAX;
	else
        return dist(P[0], P[1]) + dist(P[1], P[2]) + dist(P[0], P[2]);
} 

double min(double x, double y) 
{ 
	return (x < y)? x : y; 
} 


double stripClosest(Point strip[], int size, double d) 
{ 
	double min = d; 

	qsort(strip, size, sizeof(Point), compareY); 

	for (int i = 0; i < size; ++i) 
		for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j) 
            for (int k = j+1; k < size && (strip[k].y - strip[j].y) < min; ++k){
                double temp = dist(strip[i],strip[j]) + dist(strip[j], strip[k]) + dist(strip[k], strip[i]); 
                if (temp < min) min = temp;
            }
	return min; 
} 

double closestUtil(Point P[], int n) 
{ 
	if (n <= 3) 
		return bruteForce(P, n); 

	int mid = n/2; 
	Point midPoint = P[mid]; 

	double dl = closestUtil(P, mid); 
	double dr = closestUtil(P + mid, n - mid); 

	double d = min(dl, dr); 

	Point strip[n]; 
	int j = 0; 
	for (int i = 0; i < n; i++) 
		if (abs(P[i].x - midPoint.x) < d) 
			strip[j] = P[i], j++; 

	return min(d, stripClosest(strip, j, d) ); 
} 

double closest(Point P[], int n) 
{ 
	qsort(P, n, sizeof(Point), compareX); 

	return closestUtil(P, n); 
} 

int main() 
{ 
    int t;
    cin >> t;
    int case_count = t;
    while(t--){
        int n;
        cin >> n;
        Point P[n];
        double x, y;
        for (int i = 0; i < n; ++i){
            cin >> P[i].x >> P[i].y;
            //cin >> x;
            //cin >> y;
            //P[i].x = x;
            //P[i].y = y;
        }
        cout << "Case " << case_count - t << ": " << setprecision(15) << closest(P, n); 
        cout << endl;
    }
	return 0; 
} 


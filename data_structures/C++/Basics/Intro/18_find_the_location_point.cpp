Q. Find the location point
time limit per test1 second
memory limit per test256 megabytes
You are given the coordinates of a point (X,Y)
 on a Cartesian plane. Your task is to determine the location of the point.

The possible locations are:

Origin — if X=0 and Y=0
X axis — if Y=0 and X≠0
Y axis — if X=0 and Y≠0
1st Quadrant — if X>0 and Y>0
2nd Quadrant — if X<0 and Y>0
3rd Quadrant — if X<0 and Y<0
4th Quadrant — if X>0 and Y<0
Input
A single line containing two integers X
 and Y
 (−109≤X,Y≤109)
.

Output
Print a single line indicating the location of the point.

Examples
Input
1 10
Output
1st Quadrant
Input
0 0
Output
Origin



#include <iostream>
using namespace std;
 
int main() {
    int X,Y;
    cin>>X>>Y;
    
if (X == 0 && Y == 0) {
        cout << "Origin";
    }
    else if (X > 0 && Y > 0) {
        cout << "1st Quadrant";
    }
    else if (X < 0 && Y > 0) {
        cout << "2nd Quadrant";
    }
    else if (X < 0 && Y < 0) {
        cout << "3rd Quadrant";
    }
    else if (X > 0 && Y < 0) {
        cout << "4th Quadrant";
    }else if(Y==0){
        cout << "X axis";
    } else{
         cout << "Y axis";
    }
 
    return 0;
}

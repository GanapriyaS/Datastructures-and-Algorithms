https://www.tutorialspoint.com/cplusplus/cpp_arrays.htm
https://www.geeksforgeeks.org/multidimensional-arrays-c-cpp/
https://www.geeksforgeeks.org/arrays-in-c-cpp/

#include <iostream>
using namespace std;

#include <iomanip>
using std::setw;

int main () {

int n[ 10 ]; // n is an array of 10 integers

// initialize elements of array n to 0  
 for ( int i = 0; i < 10; i++ ) {
n[ i ] = i + 100; // set element at location i to i + 100
}
cout << "Element" << setw( 13 ) << "Value" << endl;

// output each array element's value  
 for ( int j = 0; j < 10; j++ ) {
cout << setw( 7 )<< j << setw( 13 ) << n[ j ] << endl;
}

return 0;
}
This program makes use of setw() function to format the output. When the above code is compiled and executed, it produces the following result −

Element Value
0 100
1 101
2 102
3 103
4 104
5 105
6 106
7 107
8 108
9 109s

      int x[3][4] = {{0,1,2,3}, {4,5,6,7}, {8,9,10,11}};

     v  x[3][4] = {0, 1 ,2 ,3 ,4 , 5 , 6 , 7 , 8 , 9 , 10 , 11}


     int x[2][3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                 11, 12, 13, 14, 15, 16, 17, 18, 19,
                 20, 21, 22, 23};

Better Method:

int x[2][3][4] =
{
{ {0,1,2,3}, {4,5,6,7}, {8,9,10,11} },
{ {12,13,14,15}, {16,17,18,19}, {20,21,22,23} }
};

#include<iostream>
using namespace std;

int main()
{
// initializing the 3-dimensional array
int x[2][3][2] =
{
{ {0,1}, {2,3}, {4,5} },
{ {6,7}, {8,9}, {10,11} }
};

    // output each element's value
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            for (int k = 0; k < 2; ++k)
            {
                cout << "Element at x[" << i << "][" << j
                     << "][" << k << "] = " << x[i][j][k]
                     << endl;
            }
        }
    }
    return 0;

}

Pointer to an array
An array name is a constant pointer to the first element of the array. Therefore, in the declaration −

double balance[50];
balance is a pointer to &balance[0], which is the address of the first element of the array balance. Thus, the following program fragment assigns p the address of the first element of balance −

double \*p;
double balance[10];

p = balance;
It is legal to use array names as constant pointers, and vice versa. Therefore, \*(balance + 4) is a legitimate way of accessing the data at balance[4].

Once you store the address of first element in p, you can access array elements using _p, _(p+1), \*(p+2) and so on

#include <iostream>
using namespace std;

int main () {
// an array with 5 elements.
double balance[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
double \*p;

p = balance;

// output each array element's value
cout << "Array values using pointer " << endl;

for ( int i = 0; i < 5; i++ ) {
cout << "_(p + " << i << ") : ";
cout << _(p + i) << endl;
}
cout << "Array values using balance as address " << endl;

for ( int i = 0; i < 5; i++ ) {
cout << "_(balance + " << i << ") : ";
cout << _(balance + i) << endl;
}

return 0;
}v p is a pointer to double which means it can store address of a variable of double type. Once we have address in p, then \*p will give us value available at the address stored in p, as we have shown in the above example.s

C++ Passing Arrays to Functions

C++ does not allow to pass an entire array as an argument to a function. However, You can pass a pointer to an array by specifying the array's name without an index.

If you want to pass a single-dimension array as an argument in a function, you would have to declare function formal parameter in one of following three ways and all three declaration methods produce similar results because each tells the compiler that an integer pointer is going to be received.

Way-1
Formal parameters as a pointer as follows −

void myFunction(int \*param) {
.
.
.
}
Way-2
Formal parameters as a sized array as follows −

void myFunction(int param[10]) {
.
.
.
}
Way-3
Formal parameters as an unsized array as follows −

void myFunction(int param[]) {
.
.
.
}
Now, consider the following function, which will take an array as an argument along with another argument and based on the passed arguments, it will return average of the numbers passed through the array as follows −

double getAverage(int arr[], int size) {
int i, sum = 0;  
 double avg;

for (i = 0; i < size; ++i) {
sum += arr[i];
}
avg = double(sum) / size;

return avg;
}
Now, let us call the above function as follows −

#include <iostream>
using namespace std;

// function declaration:
double getAverage(int arr[], int size);

int main () {
// an int array with 5 elements.
int balance[5] = {1000, 2, 3, 17, 50};
double avg;

// pass pointer to the array as an argument.
avg = getAverage( balance, 5 ) ;

// output the returned value
cout << "Average value is: " << avg << endl;

return 0;
}

Return Array from Functions in C++
C++ does not allow to return an entire array as an argument to a function. However, you can return a pointer to an array by specifying the array's name without an index.

If you want to return a single-dimension array from a function, you would have to declare a function returning a pointer as in the following example −

int \* myFunction() {
.
.
.
}
Second point to remember is that C++ does not advocate to return the address of a local variable to outside of the function so you would have to define the local variable as static variable.

Now, consider the following function, which will generate 10 random numbers and return them using an array and call this function as follows −

Live Demo
#include <iostream>
#include <ctime>

using namespace std;

// function to generate and retrun random numbers.
int \* getRandom( ) {

static int r[10];

// set the seed
srand( (unsigned)time( NULL ) );

for (int i = 0; i < 10; ++i) {
r[i] = rand();
cout << r[i] << endl;
}

return r;
}

// main function to call above defined function.
int main () {

// a pointer to an int.
int \*p;

p = getRandom();

for ( int i = 0; i < 10; i++ ) {
cout << "_(p + " << i << ") : ";
cout << _(p + i) << endl;
}

return 0;
}
When the above code is compiled together and executed, it produces result something as follows −

624723190
1468735695
807113585
976495677
613357504
1377296355
1530315259
1778906708
1820354158
667126415
_(p + 0) : 624723190
_(p + 1) : 1468735695
_(p + 2) : 807113585
_(p + 3) : 976495677
_(p + 4) : 613357504
_(p + 5) : 1377296355
_(p + 6) : 1530315259
_(p + 7) : 1778906708
_(p + 8) : 1820354158
_(p + 9) : 667126415

Array
Basic Questions:

1.  Create an Array of size 10 of integers. Take input from the user for these
    10 elements and print the entire array after that.
2.  Check whether n is present in an array of size m or not.
    Input - n,m (Input number, size of array)

-     							Take	input	n	elements	for	the	array
  Output -> true/false
  [ Hint : - Create a dynamic array]

3.  Find the minimum and maximum element in an array.
    [ Solution: https://www.geeksforgeeks.org/program-find-minimum-maximum-element-array/]

Here in sample input : 5 is the size of array 4) Write a program to reverse the array.
[Hint: use indexes]
Here , 5 is the size of array and then elements of arrays are input 5) Write a program to sort the given array.
[Hint: use any sorting algorithm i.e. https://www.geeksforgeeks.org/sorting-algorithms/]
Here, 6 is the size of array and then the elements are input by the user 6) Find the Kth largest and Kth smallest number in an array.
Here , K = 3 , 9 is the size of array : 7) Given an number n. Find the number of occurrences of n in the array.
Here n = 3 in the sample input , 11 is size of array and occurrence of 3 is 6 times in the given array 8) Given an array which consists of only 0, 1 and 2. Sort the array without
using any sorting algorithm.
Here, 9 is the size of array input by the user followed by the elements input 9) Find the range of the array. Range means the difference between the
maximum and minimum element in the array.
here , 6 is the size of array followed by the input of elements
Here , Range = 91-(-3) = 94 10) Move all the negative elements to one side of the array.

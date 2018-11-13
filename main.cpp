//#include <GL/glut.h>
#include <iostream>

#include "matrix.h"

using namespace std;

int main(int argc, char *argv[]) {

    Matrix<int> a(1,2);
    Matrix<int> b(1,2);
    
	
    a.set(0,0,5);
    a.set(0,1,4);
    b=a;
    (a.transposed()).print();
    cout<<"---------"<<endl;
    b.print();
    cout<<"---------"<<endl;
    //(a*b).print();
   
    //system("PAUSE");
    return EXIT_SUCCESS; 
}
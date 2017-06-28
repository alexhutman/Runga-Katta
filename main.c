#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

double step = PI/400.0;
int numIterations = 100;

double x0 = 0.0;    //-|
                    // |-set both of these at the same time
double curX = 0.0;  //-|

double y0 = 0.0;    //-|
                    // |-set both of these at the same time
double curY = 0.0;  //-|

double tempK1 = 0.0;
double tempK2 = 0.0;
double tempK3 = 0.0;

int main()
{
    for(int i=0; i<numIterations; i++) {
        rungeKutta(curX,curY);
    }

    printf("f(%f) = %f", curX, curY);
    return 0;
}

double k1(double x_,double y_) {  //PUT MAIN EQUATION HERE
    tempK1 = cos(x_)+0*y_;
    return tempK1;
}

double k2(double x_,double y_) {
    tempK2 = k1(x_ + (step/2.0), y_ + (tempK1*step/2.0));
    return tempK2;
}

double k3(double x_,double y_) {
    tempK3 = k1(x_ + (step/2.0), y_ + (tempK2*step/2.0));
    return tempK3;
}

double k4(double x_,double y_) {
    return k1(x_ + step, y_ + step*tempK3);
}

double t4(double x_,double y_) {
    return (1.0/6.0)*(k1(x_, y_) + 2.0*k2(x_, y_) + 2.0*k3(x_, y_) + k4(x_, y_));
}

void rungeKutta(double x_, double y_) {
    curY = curY + step*t4(curX,curY);
    curX += step;
}

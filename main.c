#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265
#define x0 0.0
#define y0 0.0

double step = PI/400.0;  //Calculate these based on the (x,y) you are trying to calculate,
int numIterations = 100; //for this program will calculate f(x0 + step*numIterations)

double curX = x0;
double curY = y0;

double tempK1 = 0.0;
double tempK2 = 0.0;
double tempK3 = 0.0;

int main()
{
    for(int i=0; i<numIterations; i++) {
        rungeKutta(curX, curY);
    }

    printf("f(%f) = %f", curX, curY);
    return 0;
}

double k1(double x_, double y_) {
    tempK1 = cos(x_);       //PUT f'(x,y) HERE!
    return tempK1;
}

double k2(double x_, double y_) {
    tempK2 = k1(x_ + (step/2.0), y_ + (tempK1*step/2.0));
    return tempK2;
}

double k3(double x_, double y_) {
    tempK3 = k1(x_ + (step/2.0), y_ + (tempK2*step/2.0));
    return tempK3;
}

double k4(double x_, double y_) {
    return k1(x_ + step, y_ + step*tempK3);
}

double t4(double x_, double y_) {
    return (1.0/6.0)*(k1(x_, y_) + 2.0*k2(x_, y_) + 2.0*k3(x_, y_) + k4(x_, y_));
}

void rungeKutta(double x_, double y_) {
    curY = curY + step*t4(curX, curY);
    curX += step;
}

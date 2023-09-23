#ifndef GRAHAM_ALGORITHM_H
#define GRAHAM_ALGORITHM_H

// necessary libraries -------->
#include "./Point.h"
#include <stack>
#include <vector>
#include <cmath>

// macros declaration & definition -------->
#define PI 3.14159265359

// functions declaration -------->
int dividir(std::vector<Point>&, int, int);
void quicksort(std::vector<Point>&, int, int);
double obtener_angulo(double, double);
void Min_Y_Coord_Point(std::vector<Point>&); 
void Order_Angularly(std::vector<Point> &);
bool Is_Left(Point, Point, Point);
void Graham_Algorithm(std::vector<Point>&, std::stack<Point>&);

#endif // !GRAHAM_ALGORITHM_H

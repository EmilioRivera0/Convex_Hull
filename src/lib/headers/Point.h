#ifndef POINT_H
#define POINT_H

// necessary libraries -------->
#include <vector>
#include <stack>
#include <ctime>
#include <cstdlib>
#include <iostream>

// class declaration -------->
class Point
{
public:
	Point();
	Point(int, int, double);
	void set_angulo(double const);
	int get_x() const;
	int get_y() const;
	double get_angulo() const;
private:
	int x;
	int y;
	double angulo;
};

// functions declaration -------->
void generar_puntos_aleatorios(int, std::vector<Point>&);
void imprimir_puntos(std::vector<Point>);
void imprimir_poligono(std::stack<Point>);

#endif // !POINT_H

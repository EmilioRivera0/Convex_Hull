#pragma once

#include <vector>
using std::vector;

#include <stack>
using std::stack;

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

void generar_puntos_aleatorios(int, vector<Point>&);
void imprimir_puntos(vector<Point>);
void imprimir_poligono(stack<Point>);

#include "Point.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
using std::cout;
using std::endl;

Point::Point() {
	x = 0;
	y = 0;
	angulo = 0;
}

Point::Point(int xc, int yc, double ang) {
	x = xc;
	y = yc;
	angulo = ang;
}

void Point::set_angulo(double const ang) {
	angulo = ang;
}

int Point::get_x() const {
	return x;
}

int Point::get_y() const {
	return y;
}

double Point::get_angulo() const {
	return angulo;
}

void generar_puntos_aleatorios(int num_puntos, vector<Point> &puntos) {
	srand(time(NULL));
	for (int i = 0; i < num_puntos; i++)
		puntos.push_back(Point(rand() % 19 + (-9), rand() % 19 + (-9), 0));
}

void imprimir_puntos(vector<Point> puntos) {
	cout << "\n";
	for (int i = 0; i < puntos.size(); i++)
		cout << "Punto[" << i + 1 << "]: Coordenadas = (" << puntos[i].get_x() << "," << puntos[i].get_y() << ")" << endl;
	cout << "\n";
}

void imprimir_poligono(stack<Point> poligono) {
	int cont = 1;
	cout << "\n";
	while (!poligono.empty()) {
		cout << "Vertice " << cont << ": (" << poligono.top().get_x() << "," << poligono.top().get_y() << ")" << endl;
		poligono.pop();
		cont++;
	}
	cout << "\n";
}
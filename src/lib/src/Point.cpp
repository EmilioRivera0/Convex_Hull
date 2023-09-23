// necessary libraries -------->
#include "../headers/Point.h"

// class definition -------->
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

// functions definition -------->
void generar_puntos_aleatorios(int num_puntos, std::vector<Point> &puntos) {
	srand(time(NULL));
	for (int i = 0; i < num_puntos; i++)
		puntos.push_back(Point(rand() % 19 + (-9), rand() % 19 + (-9), 0));
}

void imprimir_puntos(std::vector<Point> puntos) {
	std::cout << "\n";
	for (int i = 0; i < puntos.size(); i++)
		std::cout << "Punto[" << i + 1 << "]: Coordenadas = (" << puntos[i].get_x() << "," << puntos[i].get_y() << ")" << std::endl;
	std::cout << "\n";
}

void imprimir_poligono(std::stack<Point> poligono) {
	int cont = 1;
	std::cout << "\n";
	while (!poligono.empty()) {
		std::cout << "Vertice " << cont << ": (" << poligono.top().get_x() << "," << poligono.top().get_y() << ")" << std::endl;
		poligono.pop();
		cont++;
	}
	std::cout << "\n";
}

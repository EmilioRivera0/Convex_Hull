#pragma once
#include <fstream>
using std::ofstream;
using std::endl;

#include <vector>
using std::vector;

#include <stack>
using std::stack;

#include "Point.h"

void guardar(vector<Point> puntos, stack<Point> poligono) {
	ofstream output;
	output.open("output", std::ofstream::trunc);
	output << puntos.size() << endl;
	for (size_t i = 0; i < puntos.size(); i++)
		output << puntos[i].get_x() << " " << puntos[i].get_y() << endl;
	while (!poligono.empty()) {
		output << poligono.top().get_x() << " " << poligono.top().get_y() << endl;
		poligono.pop();
	}
	output.close();
}
// necessary libraries -------->
#include "../headers/Output.h"

// functions definition -------->
void guardar(std::vector<Point> puntos, std::stack<Point> poligono) {
	std::ofstream output;
	output.open("output", std::ofstream::trunc);
	output << puntos.size() << std::endl;
	for (size_t i = 0; i < puntos.size(); i++)
		output << puntos[i].get_x() << " " << puntos[i].get_y() << std::endl;
	while (!poligono.empty()) {
		output << poligono.top().get_x() << " " << poligono.top().get_y() << std::endl;
		poligono.pop();
	}
	output.close();
}

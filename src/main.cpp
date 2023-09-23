// necessary libraries -------->
#include "lib/headers/Graham-Algorithm.h"
#include "lib/headers/Output.h"

// program execution -------->
int main()
{
    std::vector<Point> puntos;
    std::stack<Point> poligono;
    int num_puntos;
    std::cout << "Cantidad de puntos aleatorios a generar: ";
    std::cin >> num_puntos;
    generar_puntos_aleatorios(num_puntos, puntos);
    imprimir_puntos(puntos);
    Graham_Algorithm(puntos, poligono);
    imprimir_poligono(poligono);
    guardar(puntos, poligono);
    system("python Pintado_Convex_Hull.py");
}

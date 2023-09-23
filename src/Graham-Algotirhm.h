#pragma once

#include "Point.h"

#include <stack>
using std::stack;

#include <vector>
using std::vector;

#include <cmath>

#define PI 3.14159265359

//------------------------------------------------------------------------------------------
// el punto max es el indice del punto máximo en el vector
int dividir(vector<Point> &arr, int min, int max)
{
    Point pivote = arr[min];
    int centro = max + 1;
    Point temp;

    for (size_t i = max; i > min; i--)
    {
        if (arr[i].get_angulo() > pivote.get_angulo())
        {
            centro--;
            temp = arr[i];
            arr[i] = arr[centro];
            arr[centro] = temp;
        }
    }

    temp = arr[centro - 1];
    arr[centro - 1] = arr[min];
    arr[min] = temp;

    return (centro - 1);
}

void quicksort(vector<Point> &arr, int min, int max)
{
    if (min < max)
    {
        int centro = dividir(arr, min, max);

        quicksort(arr, centro + 1, max);
        quicksort(arr, min, centro - 1);
    }
}
//------------------------------------------------------------------------------------------

double obtener_angulo(double x, double y) {
    double angulo;
    //cuadrante 1
    if (x > 0 && y > 0)
        angulo = atan2(y, x);
    //cuadrante 2
    else if (x < 0 && y > 0)
        angulo = atan2(y, x);
    //cuadrante 3
    else if (x < 0 && y < 0)
        angulo = (2*PI) + (atan2(y, x));
    //cuadrante 4
    else if (x > 0 && y < 0)
        angulo = (2 * PI) + (atan2(y, x));
    //los dos puntos están sobre el eje-y
    else if (x == 0 && y > 0)
        angulo = (PI / 2);
    else if (x == 0 && y < 0)
        angulo = (PI * 1.5);
    //los dos puntos están sobre el eje-x
    else if (x > 0 && y == 0)
        angulo = 0.0001;
    else if (x < 0 && y == 0)
        angulo = PI;
    //caso donde los dos puntos tienen las mismas coordenadas
    else
        angulo = 0.0001;
    return angulo * (180 / PI);
}

void Min_Y_Coord_Point(vector<Point> &puntos) {
	Point min = puntos[0];
	int index = 0;
	for (size_t i = 1; i < puntos.size(); i++)
		if (min.get_y() > puntos[i].get_y()) {
			min = puntos[i];
			index = i;
		}
	puntos[index] = puntos[0];
	puntos[0] = min;
}

void Order_Angularly(vector<Point> &puntos) {
    double x = 0;
    double y = 0;
    //se obtiene la angularidad de cada punto respecto del punto mínimo
    for (size_t i = 1; i < puntos.size(); i++) {
        x = puntos[i].get_x() - puntos[0].get_x();
        y = puntos[i].get_y() - puntos[0].get_y();
        puntos[i].set_angulo(obtener_angulo(x, y));
    }
    //se ordenan los puntos en base a el ángulo de angularidad de menor a mayor
    quicksort(puntos, 1, puntos.size() - 1);
}

//Retorna true si el point_i genera un angulo mayor con stack_top a comparación del angulo formado por stack_top y temp
//Checa si el tercer punto pasado por parametro está a la izquierda de la línea formada por los primeros dos puntos pasados por parametro
bool Is_Left(Point stack_top, Point temp, Point point_i) {
    double ang_temp, ang_point_i;
    ang_temp = obtener_angulo((temp.get_x() - stack_top.get_x()), (temp.get_y() - stack_top.get_y()));
    ang_point_i = obtener_angulo((point_i.get_x() - stack_top.get_x()), (point_i.get_y() - stack_top.get_y()));
    if (ang_temp < ang_point_i)
        return true;
    else
        return false;
}

void Graham_Algorithm(vector<Point> &puntos, stack<Point> &poligono) {
    Point temp;
    //posiciona el punto con menor cardinalidad en la posición 0 del vector
    Min_Y_Coord_Point(puntos);
    Order_Angularly(puntos);
    poligono.push(puntos[0]);
    poligono.push(puntos[1]);
    poligono.push(puntos[2]);
    int cont = 3;
    while (cont < puntos.size()) {
        temp = poligono.top();
        poligono.pop();
        if (Is_Left(poligono.top(), temp, puntos[cont])) {
            poligono.push(temp);
            poligono.push(puntos[cont]);
            cont++;
        }

    }
}
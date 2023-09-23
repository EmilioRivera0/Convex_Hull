from graphics import *

#se define e inicializa la ventana que contendrá el convex hull
ventana = GraphWin('Convex Hull', 750, 750)
ventana.setCoords(-10,-10,10,10)
ventana.setBackground("white")

file = open("output", 'r')
num_puntos = int(file.readline())

for i in range(num_puntos):
    x, y = [int(x) for x in next(file).split()]
    print(x, y)
    p = Circle(Point(x , y), .05)
    p.setFill("black")
    p.draw(ventana)

x, y = [int(x) for x in next(file).split()]
xi = x
yi = y
for line in file:
    xn, yn = [int(x) for x in line.split()]
    linea = Line(Point(x,y), Point(xn, yn))
    linea.setOutline("black")
    linea.draw(ventana)
    x = xn
    y = yn

linea = Line(Point(x,y), Point(xi, yi))
linea.setOutline("black")
linea.draw(ventana)

#se espera algun input del usuario para cerrar la ventana y salir de la aplicación
ventana.getMouse()
ventana.close()
print('Bye...')

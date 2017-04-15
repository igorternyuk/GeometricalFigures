#include "parallelepiped.h"
#include <math.h>
#include <QMessageBox>

Parallelepiped::Parallelepiped(double edgeA, double edgeB, double edgeC, double density)
{
    this->edgeA = edgeA;
    this->edgeB = edgeB;
    this->edgeC = edgeC;
    this->density = density;
    calculateParameters();
}
void Parallelepiped::calculateParameters()
{
    if (edgeA < 0 || edgeB < 0 || edgeC < 0)
    {
        QMessageBox qmbx;
        qmbx.setText("Некорретные геометрические параметры!");
        qmbx.exec();
        return;
    }
    if (density <= 0)
    {
        QMessageBox qmbx;
        qmbx.setText("Некорретное значение плотности материалла паралелепипеда!");
        qmbx.exec();
        return;
    }
    volume = edgeA * edgeB * edgeC;
    surfaceArea = 2 * (edgeA * edgeB + edgeA * edgeC + edgeB * edgeC);
    mass = volume * density;
    inertiaMomentX = mass / 12 * (pow(edgeB, 2) + pow(edgeC, 2));
    inertiaMomentY = mass / 12 * (pow(edgeA, 2) + pow(edgeC, 2));
    inertiaMomentZ = mass / 12 * (pow(edgeB, 2) + pow(edgeC, 2));
    inertiaMomentD = mass / 6 * (pow(edgeA, 2) * pow(edgeB, 2) + pow(edgeA, 2) * pow(edgeC, 2) + pow(edgeB, 2) * pow(edgeC, 2)) /
                     (pow(edgeA, 2) + pow(edgeB, 2) + pow(edgeC, 2));

}
double Parallelepiped::getEdgeA()
{
    return edgeA;
}
double Parallelepiped::getEdgeB()
{
    return edgeB;
}
double Parallelepiped::getEdgeC()
{
    return edgeC;
}
double Parallelepiped::getVolume()
{
    return volume;
}
double Parallelepiped::getSurfaceArea()
{
    return surfaceArea;
}
double Parallelepiped::getMass()
{
    return mass;
}
double Parallelepiped::getInertiaMomentX()
{
    return inertiaMomentX;
}
double Parallelepiped::getInertiaMomentY()
{
    return inertiaMomentY;
}
double Parallelepiped::getInertiaMomentZ()
{
    return inertiaMomentZ;
}
double Parallelepiped::getInertiaMomentD()
{
    return inertiaMomentD;
}

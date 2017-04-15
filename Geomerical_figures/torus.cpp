#include "torus.h"
#include <math.h>
#include <QMessageBox>

Torus::Torus(double Radius, double radius, double density)
{
    this->Radius = Radius;
    this->crossSectionRadius = radius;
    this->density = density;
    calculateParameters();
}
void Torus::calculateParameters()
{
    if(Radius < 0 || crossSectionRadius < 0 || crossSectionRadius > Radius)
    {
        QMessageBox qmbx;
        qmbx.setText("Некорректные геометрические параметры!");
        qmbx.exec();
        return;
    }
    if(density <= 0)
    {
        QMessageBox qmbx;
        qmbx.setText("Некорректное значение плотности материала тора!");
        qmbx.exec();
        return;
    }
    volume = 2 * pow(M_PI, 2) * Radius * pow(crossSectionRadius, 2);
    surfaceArea = 4 * pow(M_PI, 2) * Radius * crossSectionRadius;
    mass = density * volume;
    inertiaMomentX = mass * (pow(Radius, 2) / 2 + 5 / 8 * pow(crossSectionRadius, 2));
    inertiaMomentY = inertiaMomentX;
    inertiaMomentZ = mass * (pow(Radius, 2) + 3 / 4 * pow(crossSectionRadius, 2));
}
double Torus::getRadius()
{
    return Radius;
}
double Torus::getCrossSectionRadius()
{
    return crossSectionRadius;
}
double Torus::getDensity()
{
    return density;
}
double Torus::getSurfaceArea()
{
    return surfaceArea;
}
double Torus::getVolume()
{
    return volume;
}
double Torus::getInertiaMomentX()
{
    return inertiaMomentX;
}
double Torus::getInertiaMomentY()
{
    return inertiaMomentY;
}
double Torus::getInertiaMomentZ()
{
    return inertiaMomentZ;
}
double Torus::getMass()
{
    return mass;
}

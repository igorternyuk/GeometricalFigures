#include "parallelogram.h"
#include <math.h>

Parallelogram::Parallelogram(double sideA, double sideB, double angleAlpha)
{
    if(sideA < 0 || sideB < 0 || angleAlpha <= 0 || angleAlpha >= M_PI)
    {
        angleBeta = 0;
        diagonal1 = 0;
        diagonal2 = 0;
        angleGamma = 0;
        angleDelta = 0;
        area = 0;
        perimeter = 0;
        heightA = 0;
        heightB = 0;
        inertiaMomentA = 0;
        inertiaMomentB = 0;
        inertiaMomentAgc = 0;
        inertiaMomentBgc = 0;
        return;
    }
    this->sideA = sideA;
    this->sideB = sideB;
    this->angleAlpha = angleAlpha;
    calculateParameters();
}
void Parallelogram::calculateParameters()
{
    angleBeta = M_PI - angleAlpha;
    diagonal2 = sqrt(sideA * sideA + sideB * sideB - 2 * sideA * sideB * cos(angleAlpha));
    diagonal1 = sqrt(sideA * sideA + sideB * sideB - 2 * sideA * sideB * cos(angleBeta));
    angleGamma = acos(((diagonal1 * diagonal1 / 4 + diagonal2 * diagonal2 / 4 - sideA * sideA) / (diagonal1 * diagonal2 / 2)));
    angleDelta = M_PI - angleGamma;
    area = sideA * sideB * sin(angleAlpha);
    perimeter = 2 * (sideA + sideB);
    heightA = sideB * sin(angleAlpha);
    heightB = sideA * sin(angleAlpha);
    inertiaMomentA = sideA * pow(heightB, 3) / 3;
    inertiaMomentB = sideB * pow(heightA, 3) / 3;
    inertiaMomentAgc = sideA * pow(heightB, 3) / 12;
    inertiaMomentBgc = sideB * pow(heightA, 3) / 12;
    double alpha1 = asin(0.5 * sin(angleGamma) * diagonal2 / sideA);
    gravityCenterX = 0.5 * diagonal1 * cos(alpha1);
    gravityCenterY = 0.5 * diagonal1 * sin(alpha1);
    //gravityCenterY = 180 * asin(0.5 * sin(angleGamma) * diagonal2 / sideA) / M_PI;
}
double Parallelogram::getSideA()
{
    return sideA;
}
double Parallelogram::getSideB()
{
    return sideB;
}
double Parallelogram::getAngleAlpha()
{
    return angleAlpha;
}
double Parallelogram::getAngleBeta()
{
    return angleBeta;
}
double Parallelogram::getAngleGamma()
{
    return angleGamma;
}
double Parallelogram::getAngleDelta()
{
    return angleDelta;
}
double Parallelogram::getDiagonal1()
{
    return diagonal1;
}
double Parallelogram::getDiagonal2()
{
    return diagonal2;
}
double Parallelogram::getArea()
{
    return area;
}
double Parallelogram::getPerimeter()
{
    return perimeter;
}
double Parallelogram::getInertiaMomentA()
{
    return inertiaMomentA;
}
double Parallelogram::getInertiaMomentB()
{
    return inertiaMomentB;
}
double Parallelogram::getInertiaMomentAgc()
{
    return inertiaMomentAgc;
}
double Parallelogram::getInertiaMomentBgc()
{
    return inertiaMomentBgc;
}
double Parallelogram::getHeightA()
{
    return heightA;
}
double Parallelogram::getHeightB()
{
    return heightB;
}
double Parallelogram::getGravityCenterX()
{
    return gravityCenterX;
}
double Parallelogram::getGravityCenterY()
{
    return gravityCenterY;
}

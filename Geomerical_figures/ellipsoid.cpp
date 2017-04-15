#include "ellipsoid.h"
#include <math.h>
#include <algorithm>
#include <QMessageBox>

Ellipsoid::Ellipsoid():semiaxisA(0), semiaxisB(0), semiaxisC(0),
    surfaceArea(0), volume(0), mass(0), excentricityAB(0), excentricityAC(0),
    excentricityBC(0), inertiaMomentX(0), inertiaMomentY(0), inertiaMomentZ(0)
{}
Ellipsoid::Ellipsoid(double semiaxisA, double semiaxisB, double semiaxisC, double density)
{
    if (semiaxisA <= 0 || semiaxisB <= 0 || semiaxisC <=0)
    {
        QMessageBox qmbx;
        qmbx.setText("Некорректные величины полуосей эллипсоида!");
        qmbx.exec();
        Ellipsoid();
        return;
    }
    if (density <= 0)
    {
        QMessageBox qmbx;
        qmbx.setText("Некорректное значение плотности материалла эллипсоида!");
        qmbx.exec();
        Ellipsoid();
        return;
    }
    this->semiaxisA = semiaxisA;
    this->semiaxisB = semiaxisB;
    this->semiaxisC = semiaxisC;
    this->density = density;
    this->calculateParameters();
}
void Ellipsoid::calculateParameters()
{
    volume = 4 * M_PI * semiaxisA * semiaxisB * semiaxisC / 3;
    mass = density * volume;
    if (semiaxisA == semiaxisB && semiaxisA == semiaxisC)
    {
        surfaceArea = 4 * M_PI * pow(semiaxisA, 2);
        excentricityAB = excentricityAC = excentricityBC = 0;

    } else if (semiaxisA != semiaxisB && semiaxisA != semiaxisC && semiaxisB != semiaxisC)
    {
        int p = 1.6075;
        surfaceArea = 4 * M_PI * pow(((pow(semiaxisA * semiaxisB,p) + pow(semiaxisA * semiaxisC,p) +
                      pow(semiaxisB * semiaxisC,p)) / 3), (1 / p));
        excentricityAB = semiaxisA > semiaxisB ? acos(semiaxisB / semiaxisA): acos(semiaxisA / semiaxisB);
        excentricityAC = semiaxisA > semiaxisC ? acos(semiaxisC / semiaxisA): acos(semiaxisA / semiaxisC);
        excentricityBC = semiaxisB > semiaxisC ? acos(semiaxisC / semiaxisB): acos(semiaxisB / semiaxisC);

    } else if ((semiaxisA == semiaxisC) && semiaxisA > semiaxisB)
    {
         surfaceArea = 4 * M_PI * semiaxisA * (semiaxisA + pow(semiaxisB, 2) / sqrt(pow(semiaxisA, 2) - pow(semiaxisB, 2)) *
                       log((semiaxisA + sqrt(pow(semiaxisA, 2) - pow(semiaxisB, 2)))/semiaxisB));
         excentricityAB = acos(semiaxisB / semiaxisA);
         excentricityBC = excentricityAB;
         excentricityAC = 0;

    }else if ((semiaxisA == semiaxisC) && semiaxisA < semiaxisB)
    {
        surfaceArea = 4 * M_PI * semiaxisA * (semiaxisA + pow(semiaxisB, 2) / sqrt(pow(semiaxisB, 2) - pow(semiaxisA, 2)) *
                      asin((sqrt(pow(semiaxisB, 2) - pow(semiaxisA, 2)))/semiaxisB));
        excentricityAB = acos(semiaxisA / semiaxisB);
        excentricityBC = excentricityAB;
        excentricityAC = 0;

    }else if (semiaxisA == semiaxisB && semiaxisA > semiaxisC)
    {
         surfaceArea = 4 * M_PI * semiaxisA * (semiaxisA + pow(semiaxisC, 2) / sqrt(pow(semiaxisA, 2) - pow(semiaxisC, 2)) *
                       log((semiaxisA + sqrt(pow(semiaxisA, 2) - pow(semiaxisC, 2)))/semiaxisC));
         excentricityAC = acos(semiaxisB / semiaxisA);
         excentricityBC = excentricityAC;
         excentricityAB = 0;

    }else if (semiaxisA == semiaxisB && semiaxisA < semiaxisC)
    {
        surfaceArea = 4 * M_PI * semiaxisA * (semiaxisA + pow(semiaxisC, 2) / sqrt(pow(semiaxisC, 2) - pow(semiaxisA, 2)) *
                      asin((sqrt(pow(semiaxisC, 2) - pow(semiaxisA, 2)))/semiaxisC));
        excentricityAC = acos(semiaxisA / semiaxisC);
        excentricityBC = excentricityAC;
        excentricityAB = 0;
    }else if (semiaxisB == semiaxisC && semiaxisA > semiaxisB)
    {
         surfaceArea = 4 * M_PI * semiaxisB * (semiaxisB + pow(semiaxisA, 2) / sqrt(pow(semiaxisA, 2) - pow(semiaxisB, 2)) *
                       log((semiaxisB + sqrt(pow(semiaxisA, 2) - pow(semiaxisB, 2)))/semiaxisB));
         excentricityAB = acos(semiaxisB / semiaxisA);
         excentricityAC = excentricityAB;
         excentricityBC = 0;

    }else if (semiaxisB == semiaxisC && semiaxisA < semiaxisB)
    {
        surfaceArea = 4 * M_PI * semiaxisB * (semiaxisB + pow(semiaxisA, 2) / sqrt(pow(semiaxisB, 2) - pow(semiaxisA, 2)) *
                      asin((sqrt(pow(semiaxisB, 2) - pow(semiaxisA, 2)))/semiaxisB));
        excentricityAB = acos(semiaxisA / semiaxisB);
        excentricityAC = excentricityAB;
        excentricityBC = 0;
    }

    inertiaMomentX = mass / 5 * (pow(semiaxisB, 2) + pow(semiaxisC, 2));
    inertiaMomentY = mass / 5 * (pow(semiaxisA, 2) + pow(semiaxisC, 2));
    inertiaMomentZ = mass / 5 * (pow(semiaxisA, 2) + pow(semiaxisB, 2));
}
double Ellipsoid::calcEllipsoidSegmentVolumeA(double Ha)
{
   return Ha > 0 ? M_PI * semiaxisB * semiaxisC / pow(semiaxisA, 2) / 3 * (pow(semiaxisA, 2) *
          (3 * Ha - semiaxisA) + pow(semiaxisA - Ha, 3)): 0;
}
double Ellipsoid::calcEllipsoidSegmentVolumeB(double Hb)
{
    return Hb > 0 ? M_PI * semiaxisA * semiaxisC / pow(semiaxisB, 2) / 3 * (pow(semiaxisB, 2) *
           (3 * Hb - semiaxisB) + pow(semiaxisB - Hb, 3)): 0;
}
double Ellipsoid::calcEllipsoidSegmentVolumeC(double Hc)
{
    return Hc > 0 ? M_PI * semiaxisA * semiaxisB / pow(semiaxisC, 2) / 3 * (pow(semiaxisC, 2) *
           (3 * Hc - semiaxisC) + pow(semiaxisC - Hc, 3)): 0;
}
double Ellipsoid::getSemiaxisA()
{
   return semiaxisA;
}
double Ellipsoid::getSemiaxisB()
{
   return semiaxisB;
}
double Ellipsoid::getSemiaxisC()
{
   return semiaxisC;
}
double Ellipsoid::getSurfaceArea()
{
   return surfaceArea;
}
double Ellipsoid::getVolume()
{
   return volume;
}
double Ellipsoid::getMass()
{
   return mass;
}
double Ellipsoid::getInertiaMomentX()
{
   return inertiaMomentX;
}
double Ellipsoid::getInertiaMomentY()
{
   return inertiaMomentY;
}
double Ellipsoid::getInertiaMomentZ()
{
   return inertiaMomentZ;
}
double Ellipsoid::getDensity()
{
    return density;
}
double Ellipsoid::getExcentricityAB()
{
    return excentricityAB;
}
double Ellipsoid::getExcentricityAC()
{
    return excentricityAC;
}
double Ellipsoid::getExcentricityBC()
{
    return excentricityBC;
}

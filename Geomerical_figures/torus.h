#ifndef TORUS_H
#define TORUS_H


class Torus
{
private:
    double Radius, crossSectionRadius, density,
           surfaceArea, volume, mass,
           inertiaMomentX, inertiaMomentY, inertiaMomentZ;
public:
    Torus(double, double, double);
private:
    void calculateParameters();
public:
    double getRadius();
    double getCrossSectionRadius();
    double getDensity();
    double getSurfaceArea();
    double getVolume();
    double getMass();
    double getInertiaMomentX();
    double getInertiaMomentY();
    double getInertiaMomentZ();
};

#endif // TORUS_H

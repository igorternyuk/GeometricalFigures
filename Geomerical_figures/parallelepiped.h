#ifndef PARALLELEPIPED_H
#define PARALLELEPIPED_H


class Parallelepiped
{
private:
    double edgeA, edgeB, edgeC, density,
    volume, surfaceArea, mass,
    inertiaMomentX, inertiaMomentY,
    inertiaMomentZ, inertiaMomentD;
public:
    Parallelepiped(double, double, double, double);
private:
    void calculateParameters();
public:
    double getEdgeA();
    double getEdgeB();
    double getEdgeC();
    double getVolume();
    double getSurfaceArea();
    double getMass();
    double getInertiaMomentX();
    double getInertiaMomentY();
    double getInertiaMomentZ();
    double getInertiaMomentD();
};

#endif // PARALLELEPIPED_H

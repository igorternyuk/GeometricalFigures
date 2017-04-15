#ifndef ELLIPSOID_H
#define ELLIPSOID_H

class Ellipsoid
{
private:
    double semiaxisA, semiaxisB, semiaxisC,
           surfaceArea, volume, mass, excentricityAB, excentricityAC,
           excentricityBC, inertiaMomentX, inertiaMomentY, inertiaMomentZ;
protected:
    double density;
public:
    Ellipsoid();
    Ellipsoid(double semiaxisA, double semiaxisB, double semiaxesC, double density);
private:
    void calculateParameters();
public:
    double calcEllipsoidSegmentVolumeA(double Ha);
    double calcEllipsoidSegmentVolumeB(double Hb);
    double calcEllipsoidSegmentVolumeC(double Hc);
    double getSemiaxisA();
    double getSemiaxisB();
    double getSemiaxisC();
    double getDensity();
    double getSurfaceArea();
    double getVolume();
    double getMass();
    double getExcentricityAB();
    double getExcentricityAC();
    double getExcentricityBC();
    double getInertiaMomentX();
    double getInertiaMomentY();
    double getInertiaMomentZ();
};

#endif // ELLIPSOID_H

#ifndef CYLINDER_H
#define CYLINDER_H
#include "ellipse.h"

class Cylinder
{
private:
    bool isNullCylinder;
    Ellipse *internalEllipse;
    Ellipse *externalEllipse;
    double height, volume, surfaceArea,
           inertiaMomentX, inertiaMomentY, inertiaMomentZ,
           density, mass;
public:
    Cylinder(double, double, double, double, double, double);
    Cylinder(double, double, double, double);
    ~Cylinder();
private:
    void calculateParameters();
public:
    double calcSegmentVolumeA_ByHeight(double segmentHeightA);
    double calcSegmentVolumeB_ByHeight(double segmentHeightA);
    double calcSectorVolumeA_ByHeight(double segmentHeightA);
    double calcSectorVolumeB_ByHeight(double segmentHeightB);
    double getVolume();
    double getSurfaceArea();
    double getInertiaMomentX();
    double getInertiaMomentY();
    double getInertiaMomentZ();
    double getMass();
    double getExternalSemimajorAxis();
    double getExternalSemiminorAxis();
    double getInternalSemimajorAxis();
    double getInternalSemiminorAxis();
    double getHeight();
    double getDensity();
};

#endif // CYLINDER_H

#ifndef CIRCLE_H
#define CIRCLE_H
#include "ellipse.h"

class Circle: public Ellipse
{
private:
    double Radius, radius, circleArcLength;
public:
    Circle(double Radius);
private:
    void calculateCircleParameters();
public:
    double calcCircleSectorArea(double angle);
    double calcCircleSegmentArea(double angle);
    double calcAnnulusArea(double radius);
    double calcAnnulusPerimeter(double radius);
    double calcAnnulusInertiaMomentX(double radius);
    double calcAnnulusPolarInertiaMoment(double radius);
    double calcAnnulusMomentOfResistanceX(double radius);
    double calcAnnulusPolarMomentOfResistance(double radius);
    double calcAnnulusSectorArea(double radius, double angle);
    double calcAnnulusSegmentArea(double radius, double angle);
    double getArcLength();
    double getExternalRadius();
};

#endif // CIRCLE_H

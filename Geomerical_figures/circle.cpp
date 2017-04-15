#include "circle.h"
#include <math.h>
#include <QMessageBox>

Circle::Circle(double Radius):Ellipse(Radius)
{
    if(Radius < 0) this->Radius = 0;
    else
      this->Radius = Radius;
    calculateCircleParameters();
}
void Circle::calculateCircleParameters()
{
    circleArcLength = 2 * M_PI * Radius;    
}
double Circle::calcCircleSectorArea(double angle)
{
    if(angle <= 0) return 0;
    if(angle >= 360) return getArea();
    return getArea() / 360 * angle;
}
double Circle::calcCircleSegmentArea(double angle)
{
    if(angle <= 0) return 0;
    if(angle >= 360) return getArea();
    return angle <= 180 ? calcCircleSectorArea(angle) - 0.5 * Radius * Radius * sin(angle / 180 * M_PI) :
                          calcCircleSectorArea(angle) + 0.5 * Radius * Radius * sin((360 - angle) / 180 * M_PI);
}
double Circle::calcAnnulusArea(double radius)
{
    if(radius < 0 || radius >= Radius) this->radius = 0;
    return Radius != 0 ? M_PI * (Radius * Radius - radius * radius) : 0;
}
double Circle::calcAnnulusPerimeter(double radius)
{
    if(radius < 0 || radius >= Radius) radius = 0;
    return Radius != 0 ? circleArcLength + 2 * M_PI * radius : 0;
}
double Circle::calcAnnulusInertiaMomentX(double radius)
{
    if(radius < 0 || radius >= Radius) radius = 0;
    return Radius != 0 ? getInertiaMomentX() - M_PI * pow(radius, 4) / 4 : 0;
}
double Circle::calcAnnulusPolarInertiaMoment(double radius)
{
    if(radius < 0 || radius >= Radius) radius = 0;
    return Radius != 0 ? getPolarInertiaMoment() - M_PI * pow(radius, 4) / 2: 0;
}
double Circle::calcAnnulusMomentOfResistanceX(double radius)
{
    if(radius < 0 || radius >= Radius) radius = 0;
    return Radius != 0 ? getMomentOfResistanseX() - M_PI * pow(radius, 3) / 4: 0;
}
double Circle::calcAnnulusPolarMomentOfResistance(double radius)
{
    if(radius < 0 || radius >= Radius) radius = 0;
    return Radius != 0 ? getPolarMomentOfResistance() - M_PI * pow(radius, 3) / 2 : 0;
}
double Circle::calcAnnulusSectorArea(double radius, double angle)
{
    if(Radius != 0)
    {
    if(radius < 0 || radius >= Radius) radius = 0;
    if(angle <= 0) return 0;
    if(angle >= 360) return calcAnnulusArea(radius);
    if(radius < 0 || radius >= Radius) radius = 0;
    return (getArea() - M_PI * radius * radius) / 360 * angle;
    }else return  0;
}
double Circle::calcAnnulusSegmentArea(double radius, double angle)
{
    if(Radius != 0)
    {
    if(radius < 0 || radius >= Radius) radius = 0;
    if(angle <= 0) return 0;
    angle = angle / 180 * M_PI;
    if(angle >= 2 * M_PI) return calcAnnulusArea(radius);
    double annulusSegmentArea = 0;
    if(angle <= 2 * acos(radius / Radius))
       annulusSegmentArea = calcCircleSegmentArea(angle / M_PI * 180);
    else if(angle > 2 * acos(radius / Radius) && angle <= M_PI)
    {
       double beta = 2 * acos(Radius * cos(angle / 2) / radius);
       annulusSegmentArea = calcCircleSectorArea(angle / M_PI * 180) - 0.5 * pow(Radius, 2) * sin(angle) -
                           (M_PI * pow(radius, 2) / 2 / M_PI * beta - 0.5 * pow(radius, 2) * sin(beta));
    }
    else if(angle > M_PI && angle <= 2 * (M_PI - acos(radius / Radius)))
    {
        double angle2 = 2 * M_PI - angle;
        double beta2 = 2 * acos(Radius * cos(angle2 / 2) / radius);
        double circleSegmentArea2 = calcCircleSectorArea(angle2 / M_PI * 180) - 0.5 * pow(Radius, 2) * sin(angle2) -
                            (M_PI * pow(radius, 2) / 2 / M_PI * beta2 - 0.5 * pow(radius, 2) * sin(beta2));
       annulusSegmentArea = calcAnnulusArea(radius) - circleSegmentArea2;
    }else
       annulusSegmentArea = calcCircleSegmentArea(angle / M_PI * 180) - M_PI * pow(radius, 2);
    return annulusSegmentArea;
    }return 0;
}
double Circle::getArcLength()
{
    return circleArcLength;
}
double Circle::getExternalRadius()
{
    return Radius;
}



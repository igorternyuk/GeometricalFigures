#ifndef ELLIPSE_H
#define ELLIPSE_H

class Ellipse
{
private:
    bool   isNullSemiaxises;
    double semimajorAxis, semiminorAxis, focusDistanse,
           excentricity, focusParameterP, distanseBetweenFocuses,
           area, perimeter, inertiaMomentX,
           inertiaMomentY, polarInertiaMoment, momentOfResistanseX,
           momentOfResistanseY, polarMomentOfResistanse;
public:
    Ellipse(double);
    Ellipse(double, double);
private:
    void calculateParameters();
public:
    double ellipseArcLengthFunction(double);
    double calcEllipseArcLength(double fi1, double fi2, double);
    double calcAnnulusArea(double, double);
    double calcAreaOfSectorA_byHeight(double height);
    double calcAreaOfSectorB_byHeight(double height);
    double calcAreaOfSegmentA_byHeight(double height);
    double calcAreaOfSegmentB_byHeight(double height);
    double calcPerimeterOfSectorA_byHeight(double height, double eps);
    double calcPerimeterOfSectorB_byHeight(double height, double eps);
    double calcPerimeterOfSegmentA_byHeight(double height, double eps);
    double calcPerimeterOfSegmentB_byHeight(double height, double eps);
    double calcAreaOfSectorA_byAngle(double angle);
    double calcAreaOfSectorB_byAngle(double angle);
    double calcAreaOfSegmentA_byAngle(double angle);
    double calcAreaOfSegmentB_byAngle(double angle);
    double calcPerimeterOfSectorA_byAngle(double angle, double eps);
    double calcPerimeterOfSectorB_byAngle(double angle, double eps);
    double calcPerimeterOfSegmentA_byAngle(double angle, double eps);
    double calcPerimeterOfSegmentB_byAngle(double angle, double eps);
    double getArea();
    double getSemimajorAxis();
    double getSemiminorAxis();
    double getPerimeter();
    double getExcentricity();
    double getFocusDistanse();
    double getInertiaMomentX();
    double getInertiaMomentY();
    double getMomentOfResistanseX();
    double getMomentOfResistanseY();
    double getPolarInertiaMoment();
    double getPolarMomentOfResistance();
    double getFocusParameterP();
    double getDistanseBetweenFocuses();
};

#endif // ELLIPSE_H

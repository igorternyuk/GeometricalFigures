#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <vector>
#include <string>
using namespace std;

class Triangle
{
private:
    double
    sideA, sideB, sideC,
    alpha, beta, gamma,
    heightA, heightB, heightC,
    medianaA, medianaB, medianaC,
    bisectorA, bisectorB, bisectorC,
    area, perimeter, Radius, radius,
    inertiaMomentA, inertiaMomentB,
    inertiaMomentC, inertiaMomentAgc,
    inertiaMomentBgc, inertiaMomentCgc;
    double gravityCenterCoord[3];
    double Xgc, Ygc;

public:
    Triangle(const string , const string , const string , double, double, double);
    Triangle(char , double, double, double, double);
    Triangle(double *vertexCoord);
private:
    void  calculateParameters();
   //void  calculateSidesByCoordinates(vector<double>);
    bool  checkTriangleSide(const double&);
    bool  checkTriangleSides2(const double&, const double&);
    bool  checkTriangleAngle(const double&);
    bool  checkTriangleAngles2(const double&, const double&);
    bool  checkTriangleAngles3(const double&, const double&, const double&);
    void  sendInputDataErrorMessage();

public:
    double getSideA();
    double getSideB();
    double getSideC();
    double getAngleAlpha();
    double getAngleBeta();
    double getAngleGamma();
    double getArea();
    double getPerimeter();
    double getExternalRadius();
    double getInternalRadius();
    double getHeightA();
    double getHeightB();
    double getHeightC();
    double getMedianaA();
    double getMedianaB();
    double getMedianaC();
    double getBisectorA();
    double getBisectorB();
    double getBisectorC();
    double getInertiaMomentA();
    double getInertiaMomentB();
    double getInertiaMomentC();
    double getInertiaMomentAgc();
    double getInertiaMomentBgc();
    double getInertiaMomentCgc();
    double getGravityCenterCoordX();
    double getGravityCenterCoordY();
    double getGravityCenterCoordZ();
    double getGravityCenterX();
    double getGravityCenterY();
    void   sendErrorMessage(const char* str);
    bool   inputCorrectness() const;
};

#endif // TRIANGLE_H

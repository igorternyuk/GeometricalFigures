#ifndef TRAPEZIUM_H
#define TRAPEZIUM_H


class Trapezium
{
private:
    double sideA, sideB, sideC, sideD, height,
           angleAlpha, angleBeta, angleGamma, angleDelta,
           diagonal1, diagonal2, area, perimeter, inertiaMomentA,
           inertiaMomentXgc, inertiaMomentYgc, gravityCenterX, gravityCenterY;
public:
    Trapezium(bool, double, double, double, double);
private:
    void calculateParameters(bool);
public:
    double getSideA();
    double getSideB();
    double getSideC();
    double getSideD();
    double getHeight();
    double getAngleAlpha();
    double getAngleBeta();
    double getAngleGamma();
    double getAngleDelta();
    double getDiagonal1();
    double getDiagonal2();
    double getArea();
    double getPerimeter();
    double getInertiaMomentA();
    double getInertiaMomentXgc();
    double getInertiaMomentYgc();
    double getGravityCenterX();
    double getGravityCenterY();
};

#endif // TRAPEZIUM_H

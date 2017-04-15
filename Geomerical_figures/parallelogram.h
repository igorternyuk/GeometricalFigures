#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

class Parallelogram
{
private:
    double sideA, sideB, heightA, heightB,
           angleAlpha, angleBeta, angleGamma, angleDelta,
           diagonal1, diagonal2, area, perimeter, inertiaMomentA,
           inertiaMomentB, inertiaMomentAgc, inertiaMomentBgc,
           gravityCenterX, gravityCenterY;
public:
    Parallelogram(double sideA, double sideB, double angleAlpha);
private:
    void calculateParameters();
public:
    double getSideA();
    double getSideB();
    double getAngleAlpha();
    double getAngleBeta();
    double getAngleGamma();
    double getAngleDelta();
    double getDiagonal1();
    double getDiagonal2();
    double getHeightA();
    double getHeightB();
    double getArea();
    double getPerimeter();
    double getInertiaMomentA();
    double getInertiaMomentB();
    double getInertiaMomentAgc();
    double getInertiaMomentBgc();
    double getGravityCenterX();
    double getGravityCenterY();
};

#endif // PARALLELOGRAM_H

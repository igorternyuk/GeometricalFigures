#ifndef BALL_H
#define BALL_H
#include "ellipsoid.h"


class Ball: public Ellipsoid
{
private:
    double Radius;
public:
    Ball(double, double);
private:
public:
    double calcBallSegementArea(double);
    double calcBallSegmentVolume(double);
    double calcBallSegmentMass(double, double);
    double calcBallSectorArea(double);
    double calcBallSectorVolume(double);
    double calcBallSectorMass(double, double);
    double calcSphericalLayerArea(char, double, double);
    double calcSphericalLayerVolume(char, double, double);
    double calcSphericalLayerMass(char, double, double, double);
    double getRadius();
};

#endif // BALL_H

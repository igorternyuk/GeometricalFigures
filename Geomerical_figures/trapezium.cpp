#include "trapezium.h"
#include <math.h>
#include <QMessageBox>

Trapezium::Trapezium(bool calcByFourSides, double sideA,
                     double sideB, double geomPar1, double geomPar2)
{
    this->sideA = sideA;
    this->sideB = sideB;
    if(calcByFourSides)
    {
        this->sideC = geomPar1;
        this->sideD = geomPar2;
        calculateParameters(true);
    }else
    {
        height = geomPar1;
        angleAlpha = geomPar2;
        calculateParameters(false);
    }
}
void  Trapezium::calculateParameters(bool flag)
{
    if(this->sideA <= 0 || this->sideB <= 0)
    {
        QMessageBox q;
        q.setText("Длины оснований трапеции должны быть положительными!");
        q.exec();
        return;
    }
    if(flag)
    {
       if(this->sideC <= 0 || this->sideD <= 0)
       {
           QMessageBox q;
           q.setText("Длины боковых сторон трапеции должны быть положительными!");
           q.exec();
           return;
       }
       if(sideA >= sideB + sideC + sideD ||
          sideC >= sideA + sideD ||
          sideD >= sideA + sideC ||
          sideB >= sideA + sideC + sideD)
          {
           QMessageBox q;
           q.setText("Некорректное сочетание входных параметров!");
           q.exec();
           return;
          }
       double C1 = (sideA * sideA + sideC * sideC - sideD * sideD - sideB * sideB) / 2;
       double C2 = (sideB * sideB + sideC * sideC - sideA * sideA - sideD * sideD) / 2;
       angleAlpha = acos((C1 / (sideB * sideD) + C2 / (sideA * sideD)) / (sideA * sideC / (sideB * sideD) - sideB * sideC / (sideA * sideD)));
       angleBeta = acos((C1 / (sideA * sideC) + C2 / (sideB * sideC)) / (sideB * sideD / (sideA * sideC) - sideA * sideD / (sideB * sideC)));
       height = sideC * sin(angleAlpha);
    }else
    {
        if(height <= 0)
        {
            QMessageBox q;
            q.setText("Высота трапеции должна быть положытельной!");
            q.exec();
            return;
        }
        if(angleAlpha <= 0 || angleAlpha >= M_PI)
        {
            QMessageBox q;
            q.setText("Угол α должен быть больше 0 и меньше 180 градусов!");
            q.exec();
            return;
        }
        sideC = height / sin(angleAlpha);
        sideD = sqrt (pow((sideA - sideB - sideC * cos(angleAlpha)), 2) + height * height);
        angleBeta = asin(height / sideD);
    }
    diagonal1 = sqrt(sideA * sideA + sideC * sideC - 2 * sideA * sideC * cos(angleAlpha));
    diagonal2 = sqrt(sideA * sideA + sideD * sideD - 2 * sideA * sideD * cos(angleBeta));
    angleGamma = acos(height / diagonal1) + acos(height / diagonal2);
    angleDelta = M_PI - angleGamma;
    perimeter = sideA + sideB + sideC + sideD;
    area = 0.5 * (sideA + sideB) * height;
    double cathetus1 = sideC * cos(angleAlpha);
    double cathetus2 = sideD * cos(angleBeta);
    double triangleArea1 = 0.5 * cathetus1 * height;
    double triangleArea2 = 0.5 * cathetus2 * height;
    double rectangleArea = sideB * height;
    gravityCenterX = (triangleArea1 * 2 * cathetus1 / 3 +
                      rectangleArea * (0.5 * sideB + cathetus1) +
                      triangleArea2 * (cathetus1 + sideB + cathetus2 / 3)) / area;
    gravityCenterY = (triangleArea1 / 3 + rectangleArea / 2 + triangleArea2 / 3) * height / area;
    inertiaMomentA = (cathetus1 * pow(height, 3) / 12 + sideB  * pow(height, 3) / 3 +
                      cathetus2 * pow(height, 3) / 12);
    inertiaMomentXgc = inertiaMomentA - area * pow(gravityCenterY , 2);
    //inertiaMomentXgc = cathetus1;
    double deltaX = gravityCenterX - cathetus1 - 0.5 * sideB;
    inertiaMomentYgc = height * pow(cathetus1, 3) / 36 + pow(gravityCenterX - 2 * cathetus1 / 3, 2) * triangleArea1 +
                height * pow(sideB, 3) / 12 + pow(deltaX, 2) * rectangleArea +
                height * pow(cathetus2, 3) / 36 + pow(sideA - gravityCenterX - 2 * cathetus2 / 3, 2) * triangleArea2;
}
double Trapezium::getSideA()
{
    return sideA;
}
double Trapezium::getSideB()
{
    return sideB;
}
double Trapezium::getSideC()
{
    return sideC;
}
double Trapezium::getSideD()
{
    return sideD;
}
double Trapezium::getHeight()
{
    return height;
}
double Trapezium::getAngleAlpha()
{
    return angleAlpha;
}
double Trapezium::getAngleBeta()
{
    return angleBeta;
}
double Trapezium::getAngleGamma()
{
    return angleGamma;
}
double Trapezium::getAngleDelta()
{
    return angleDelta;
}
double Trapezium::getDiagonal1()
{
    return diagonal1;
}
double Trapezium::getDiagonal2()
{
    return diagonal2;
}
double Trapezium::getArea()
{
    return area;
}
double Trapezium::getPerimeter()
{
    return perimeter;
}
double Trapezium::getInertiaMomentA()
{
    return inertiaMomentA;
}
double Trapezium::getInertiaMomentXgc()
{
    return inertiaMomentXgc;
}
double Trapezium::getInertiaMomentYgc()
{
    return inertiaMomentYgc;
}
double Trapezium::getGravityCenterX()
{
    return gravityCenterX;
}
double Trapezium::getGravityCenterY()
{
    return gravityCenterY;
}


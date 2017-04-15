#include "triangle.h"
#include <math.h>
#include <string>
#include <QMessageBox>

Triangle::Triangle(const string par1, const string par2, const string par3,
                   double geomPar1, double geomPar2, double geomPar3)
{
    if (par1 == "a" && par2 == "b" && par3 == "c")
    {
        if ((geomPar1 <= 0) || (geomPar2 <= 0) || (geomPar3 <= 0))
         {
            QMessageBox q;
            q.setText("Задайте положительные значения длин сторон!");
            q.exec();
            return;
         }
        if ((geomPar1 + geomPar2 <= geomPar3) || (geomPar1 + geomPar3 <= geomPar2) || (geomPar2 + geomPar3 <= geomPar1))
         {
            QMessageBox q;
            q.setText("Сумма любих двух сторон треугольника не может быть меньшне третьей стороны!");
            q.exec();
            return;
         }
        sideA = geomPar1;
        sideB = geomPar2;
        sideC = geomPar3;
        gamma = acos((sideA * sideA + sideB * sideB - sideC * sideC) /(2 * sideA * sideB));
        beta =  asin((sin(gamma) * sideB) / sideC);
        alpha = M_PI - beta - gamma;
    }else if(par1 == "a" && par2 == "b" && par3 == "alpha")
    {
        sideA = geomPar1;
        sideB = geomPar2;
        alpha = geomPar3;
        if (checkTriangleSides2(geomPar1, geomPar2) && checkTriangleAngle(geomPar3))
        {
            if((sin(geomPar3) * geomPar2 / geomPar1) > 1)
            {
                QMessageBox q;
                q.setText("Невозможное сочетание входных параметров!");
                q.exec();
                return;
            }
            beta = asin((sin(alpha) * sideB) / sideA);
            gamma = M_PI - alpha - beta;
            sideC = sideA * sin(gamma) / sin(alpha);
        }
    } else if(par1 == "a" && par2 == "b" && par3 == "beta")
    {
        sideA = geomPar1;
        sideB = geomPar2;
        beta = geomPar3;
        if (checkTriangleSides2(sideA,sideB) && checkTriangleAngle(beta))
        {
            if((sin(beta) * sideA / sideB) > 1)
            {
                QMessageBox q;
                q.setText("Невозможное сочетание входных параметров!");
                q.exec();
                return;
            }
            alpha = asin(sin(beta) * sideA / sideB);
            gamma = M_PI - alpha - beta;
            sideC = sideA * sin(gamma) / sin(alpha);
        }
    }else if(par1 == "a" && par2 == "b" && par3 == "gamma")
        {
            sideA = geomPar1;
            sideB = geomPar2;
            gamma = geomPar3;
            if (checkTriangleSides2(sideA, sideB) && checkTriangleAngle(gamma))
            {
                sideC = sqrt(sideA * sideA + sideB * sideB - 2 * sideA * sideB * cos(gamma));
                if((sin(gamma) * sideA / sideC) > 1)
                {
                    QMessageBox q;
                    q.setText("Невозможное сочетание входных параметров!");
                    q.exec();
                    return;
                }
                alpha = asin(sin(gamma) * sideA / sideC);
                beta = M_PI - alpha - gamma;
            }
    }else if(par1 == "a" && par2 == "c" && par3 == "alpha")
           {
            sideA = geomPar1;
            sideC = geomPar2;
            alpha = geomPar3;
            if(checkTriangleSides2(sideA,sideC) && checkTriangleAngle(alpha))
            {
                if((sin(alpha) * sideC / sideA) > 1)
                {
                    QMessageBox q;
                    q.setText("Невозможное сочетание входных параметров!");
                    q.exec();
                    return;
                }
                gamma = asin(sin(alpha) * sideC / sideA);
                beta = M_PI - alpha - gamma;
                sideB = sin(beta)* sideA / sin(alpha);
            }
    }else if(par1 == "a" && par2 == "c" && par3 == "beta")
            {
              sideA = geomPar1;
              sideC = geomPar2;
              beta = geomPar3;
              if (checkTriangleSides2(sideA, sideC) && checkTriangleAngle(beta))
              {
                  sideB = sqrt(sideA * sideA + sideC * sideC - 2 * sideA * sideC * cos(beta));
                  if((sin(beta) * sideC / sideB) > 1)
                    {
                      QMessageBox q;
                      q.setText("Невозможное сочетание входных параметров!");
                      q.exec();
                      return;
                    }
               gamma = asin(sin(beta) * sideC / sideB);
               alpha = M_PI - beta - gamma;
              }
    }else if(par1 == "a" && par2 == "c" && par3 == "gamma")
    {
        sideA = geomPar1;
        sideC = geomPar2;
        gamma = geomPar3;
        if (checkTriangleSides2(sideA,  sideC) && checkTriangleAngle(gamma))
        {
            if((sin(gamma) * sideA / sideC) > 1)
            {
                QMessageBox q;
                q.setText("Невозможное сочетание входных параметров!");
                q.exec();
                return;
            }
            alpha = asin(sin(gamma) * sideA / sideC);
            beta = M_PI - alpha - gamma;
            sideB = sin(beta) * sideA / sin(alpha);
        }
    }else if(par1 == "b" && par2 == "c" && par3 == "alpha")
    {
        this->sideB = geomPar1;
        this->sideC = geomPar2;
        this->alpha = geomPar3;
        if (checkTriangleSides2(sideB, sideC) && checkTriangleAngle(alpha))
        {
            sideA = sqrt(sideB * sideB + sideC * sideC - 2 * sideB * sideC * cos(alpha));
            if((sin(alpha) * sideC / sideA) > 1)
            {
                QMessageBox q;
                q.setText("Невозможное сочетание входных параметров!");
                q.exec();
                return;
            }
            gamma = asin(sin(alpha) * sideC / sideA);
            beta = M_PI - alpha - gamma;
        }
    }else if(par1 == "b" && par2 == "c" && par3 == "beta")
    {
        sideB = geomPar1;
        sideC = geomPar2;
        beta = geomPar3;
        if (checkTriangleSides2(sideB, sideC) && checkTriangleAngle(beta))
        {
            if((sin(beta) * sideC / sideB) > 1)
            {
                QMessageBox q;
                q.setText("Невозможное сочетание входных параметров!");
                q.exec();
                return;
            }
            gamma = asin(sin(beta) * sideC / sideB);
            alpha = M_PI - beta - gamma;
            sideA = sin(alpha) * sideB / sin(beta);
        }

    }else if(par1 == "b" && par2 == "c" && par3 == "gamma")
    {
        sideB = geomPar1;
        sideC = geomPar2;
        gamma = geomPar3;
        if (checkTriangleSides2(sideB,sideC) && checkTriangleAngle(gamma))
        {
            if((sin(gamma) * sideB / sideC) > 1)
            {
                QMessageBox q;
                q.setText("Невозможное сочетание входных параметров!");
                q.exec();
                return;
            }
            beta = asin(sin(gamma) * sideB / sideC);
            alpha = M_PI - beta - gamma;
        }
    }else if(par1 == "a" && par2 == "alpha" && par3 == "beta")
    {
        sideA = geomPar1;
        alpha = geomPar2;
        beta = geomPar3;
        if (checkTriangleSide(sideA) && checkTriangleAngles2(alpha, beta))
        {
            sideB = sin(beta) * sideA / sin(alpha);
            gamma = M_PI - beta - alpha;
            sideC = sin(gamma) * sideB / sin(beta);
        }
    }else if(par1 == "b" && par2 == "alpha" && par3 == "beta")
    {
        sideB = geomPar1;
        alpha = geomPar2;
        beta = geomPar3;
        if (checkTriangleSide(sideB) && checkTriangleAngles2(alpha, beta))
        {
            sideA = sin(alpha) * sideB / sin(beta);
            gamma = M_PI - beta - alpha;
            sideC = sin(gamma) * sideB / sin(beta);
         }

    }else if(par1 == "c" && par2 == "alpha" && par3 == "beta")
    {
        sideC = geomPar1;
        alpha = geomPar2;
        beta = geomPar3;
        if (checkTriangleSide(sideC) && checkTriangleAngles2(alpha, beta))
        {
            gamma = M_PI - beta - alpha;
            sideA = sin(alpha) * sideC / sin(gamma);
            sideB = sin(beta) * sideC / sin(gamma);
        }

    }else if(par1 == "a" && par2 == "alpha" && par3 == "gamma")
    {
        sideA = geomPar1;
        alpha = geomPar2;
        gamma = geomPar3;
        if (checkTriangleSide(sideA) && checkTriangleAngles2(alpha, gamma))
        {
            sideC = sin(gamma) * sideA / sin(alpha);
            beta = M_PI - alpha - gamma;
            sideB = sin(beta) * sideA / sin(alpha);
        }
    }else if(par1 == "b" && par2 == "alpha" && par3 == "gamma")
    {
        sideB = geomPar1;
        alpha = geomPar2;
        gamma = geomPar3;
        if (checkTriangleSide(sideB) && checkTriangleAngles2(alpha, gamma))
        {
            beta = M_PI - alpha - gamma;
            sideC = sin(gamma) * sideB / sin(beta);
            sideA = sin(alpha) * sideB / sin(beta);
        }
    }else if(par1 == "c" && par2 == "alpha" && par3 == "gamma")
    {
        sideC = geomPar1;
        alpha = geomPar2;
        gamma = geomPar3;
        if (checkTriangleSide(sideC) && checkTriangleAngles2(alpha, gamma))
        {
            beta = M_PI - alpha - gamma;
            sideB = sin(beta) * sideC / sin(gamma);
            sideA = sin(alpha) * sideB / sin(beta);
        }

    }else if(par1 == "a" && par2 == "beta" && par3 == "gamma")
    {
        sideA = geomPar1;
        beta = geomPar2;
        gamma = geomPar3;
        if (checkTriangleSide(sideA) && checkTriangleAngles2(beta, gamma))
        {
            alpha = M_PI - beta - gamma;
            sideB = sin(beta) * sideA / sin(alpha);
            sideC = sin(gamma) * sideB / sin(beta);
        }

    }else if(par1 == "b" && par2 == "beta" && par3 == "gamma")
    {
        sideB = geomPar1;
        beta = geomPar2;
        gamma = geomPar3;
        if (checkTriangleSide(sideB) && checkTriangleAngles2(beta, gamma))
        {
            alpha = M_PI - beta - gamma;
            sideC = sin(gamma) * sideB / sin(beta);
            sideA = sin(alpha) * sideB / sin(beta);
        }
    }else if(par1 == "c" && par2 == "beta" && par3 == "gamma")
    {
        sideC = geomPar1;
        beta = geomPar2;
        gamma = geomPar3;
        if (checkTriangleSide(sideC) && checkTriangleAngles2(beta, gamma))
        {
            alpha = M_PI - beta - gamma;
            sideA = sin(alpha) * sideC / sin(gamma);
            sideB = sin(beta) * sideC / sin(gamma);
        }
    }else
    {
        sideA = 3;
        sideB = 4;
        sideC = 5;
        alpha = atan(sideA / sideB);
        beta = M_PI / 2 - alpha;
        gamma = M_PI / 2;
        calculateParameters();
        gravityCenterCoord[0] = 2 / 3 * medianaA * cos(alpha / 2);
        gravityCenterCoord[1] = 2 / 3 * medianaA * sin(alpha / 2);
        gravityCenterCoord[2] = 0;
    }
    calculateParameters();
    gravityCenterCoord[0] = 2 / 3 * medianaA * cos(alpha / 2);
    gravityCenterCoord[1] = 2 / 3 * medianaA * sin(alpha / 2);
    gravityCenterCoord[2] = 0;
}
Triangle::Triangle(char knownSide, double side, double alpha, double beta, double gamma)
{
    switch (knownSide) {
    case 'a':
        sideA = side;
        this->alpha = alpha;
        this->beta = beta;
        this->gamma = gamma;
        if (checkTriangleSide(sideA) && checkTriangleAngles3(this->alpha, this->beta, this->gamma))
        {
            sideB = sin(this->beta) * sideA / sin(this->alpha);
            sideC = sin(this->gamma) * sideA / sin(this->alpha);
        }
        break;
    case 'b':
        sideB = side;
        this->alpha = alpha;
        this->beta = beta;
        this->gamma = gamma;
        if (checkTriangleSide(sideB) && checkTriangleAngles3(this->alpha, this->beta, this->gamma))
        {
            sideA = sin(this->alpha) * sideB / sin(this->beta);
            sideC = sin(this->gamma) * sideB / sin(this->beta);
        }
        break;
    case 'c':
        sideC = side;
        this->alpha = alpha;
        this->beta = beta;
        this->gamma = gamma;
        if (checkTriangleSide(sideC) && checkTriangleAngles3(this->alpha, this->beta, this->gamma))
        {
            sideA = sin(this->alpha) * sideC / sin(this->gamma);
            sideB = sin(this->beta) * sideC / sin(this->gamma);
        }
        break;
    default: break;
    }
    calculateParameters();
    gravityCenterCoord[0] = 2 / 3 * medianaA * cos(alpha / 2);
    gravityCenterCoord[1] = 2 / 3 * medianaA * sin(alpha / 2);
    gravityCenterCoord[2] = 0;
}
Triangle::Triangle(double* vertexCoord)
{
    sideA = sqrt(pow((vertexCoord[3] - vertexCoord[6]), 2) +
            pow((vertexCoord[4] - vertexCoord[7]), 2) +
            pow((vertexCoord[5] - vertexCoord[8]), 2));
    sideB = sqrt(pow((vertexCoord[0] - vertexCoord[6]), 2) +
            pow((vertexCoord[1] - vertexCoord[7]), 2) +
            pow((vertexCoord[2] - vertexCoord[8]), 2));
    sideC = sqrt(pow((vertexCoord[0] - vertexCoord[3]), 2) +
            pow((vertexCoord[1] - vertexCoord[4]), 2) +
            pow((vertexCoord[2] - vertexCoord[5]), 2));
    gamma = acos((sideA * sideA + sideB * sideB - sideC * sideC) /(2 * sideA * sideB));
    beta =  asin((sin(gamma) * sideB) / sideC);
    alpha = M_PI - beta - gamma;
    double Xmb = (vertexCoord[3] + vertexCoord[6]) / 2;
    double Ymb = (vertexCoord[4] + vertexCoord[7]) / 2;
    double Zmb = (vertexCoord[5] + vertexCoord[8]) / 2;
    double lambda = 2;
    gravityCenterCoord[0] = (vertexCoord[0] + lambda * Xmb)/(1 + lambda);
    gravityCenterCoord[1] = (vertexCoord[1] + lambda * Ymb)/(1 + lambda);
    gravityCenterCoord[2] = (vertexCoord[2] + lambda * Zmb)/(1 + lambda);
    this->calculateParameters();
}

void  Triangle::calculateParameters()
{
    perimeter = sideA + sideB + sideC;
    area = 0.5 * sideA * sideB * sin(gamma);
    Radius = sideA * sideB * sideC / 4 / area;
    radius = 2 * area / perimeter;
    heightA = sideB * sin(gamma);
    heightB  = sideC * sin(alpha);
    heightC = sideA * sin(beta);
    medianaA = sqrt((sideA * sideA / 4) + sideC * sideC - sideA * sideC * cos(beta));
    medianaB = sqrt((sideB * sideB / 4) + sideA * sideA - sideB * sideA * cos(gamma));
    medianaC = sqrt((sideC * sideC / 4) + sideB * sideB - sideC * sideB * cos(alpha));
    bisectorA = sideC * sin(beta) / sin(0.5 * alpha + beta);
    bisectorB = sideA * sin(beta) / sin(0.5 * beta + gamma);
    bisectorC = sideA * sin(gamma) / sin(0.5 * gamma + beta);
    inertiaMomentA = sideA * pow(heightA, 3) / 12;
    inertiaMomentB = sideA * pow(heightB, 3) / 12;
    inertiaMomentC = sideA * pow(heightC, 3) / 12;
    inertiaMomentAgc = sideA * pow(heightA, 3) / 12;
    inertiaMomentBgc = sideA * pow(heightB, 3) / 12;
    inertiaMomentCgc = sideA * pow(heightC, 3) / 12;
    Xgc = (sideB * cos(gamma) + sideA) / 3;
    Ygc = sideB * sin(gamma) / 3;
}
double Triangle::getSideA()
{
    return sideA;
}
double Triangle::getSideB()
{
    return sideB;
}
double Triangle::getSideC()
{
    return sideC;
}
double Triangle::getAngleAlpha()
{
    return alpha;
}
double Triangle::getAngleBeta()
{
    return beta;
}
double Triangle::getAngleGamma()
{
    return gamma;
}
double Triangle::getArea()
{
    return area;
}
double Triangle::getPerimeter()
{
    return perimeter;
}
double Triangle::getExternalRadius()
{
    return Radius;
}
double Triangle::getInternalRadius()
{
    return radius;
}
double Triangle::getHeightA()
{
    return heightA;
}
double Triangle::getHeightB()
{
    return heightB;
}
double Triangle::getHeightC()
{
    return heightC;
}
double Triangle::getMedianaA()
{
    return medianaA;
}
double Triangle::getMedianaB()
{
    return medianaB;
}
double Triangle::getMedianaC()
{
    return medianaC;
}
double Triangle::getBisectorA()
{
    return bisectorA;
}
double Triangle::getBisectorB()
{
    return bisectorB;
}
double Triangle::getBisectorC()
{
    return bisectorC;
}
double Triangle::getInertiaMomentA()
{
    return inertiaMomentA;
}
double Triangle::getInertiaMomentB()
{
    return inertiaMomentB;
}
double Triangle::getInertiaMomentC()
{
    return inertiaMomentC;
}
double Triangle::getInertiaMomentAgc()
{
    return inertiaMomentAgc;
}
double Triangle::getInertiaMomentBgc()
{
    return inertiaMomentBgc;
}
double Triangle::getInertiaMomentCgc()
{
    return inertiaMomentCgc;
}
double Triangle::getGravityCenterCoordX()
{
    return gravityCenterCoord[0];
}
double Triangle::getGravityCenterCoordY()
{
    return gravityCenterCoord[1];
}
double Triangle::getGravityCenterCoordZ()
{
    return gravityCenterCoord[2];
}
double Triangle::getGravityCenterX()
{
    return Xgc;
}
double Triangle::getGravityCenterY()
{
    return Ygc;
}
bool Triangle::checkTriangleSide(const double &side)
{
    bool res = side > 0;
    if (!res)
    {
      QMessageBox mbox;
      mbox.setText("Длина сторон не может быть отрицательной!");
      mbox.exec();
      return false;
    }
    return res;
}
bool Triangle::checkTriangleSides2(const double &side1, const double &side2)
{
    bool res = side1 > 0 && side2 > 0;
    if (!res)
    {
      QMessageBox mbox;
      mbox.setText("Длина сторон не может быть отрицательной!");
      mbox.exec();
      return false;
    }
    return res;
}
bool Triangle::checkTriangleAngle(const double &angle1)
{
    bool res = angle1 > 0 && angle1 < M_PI;
    if (!res)
    {
    QMessageBox mbox;
    mbox.setText("Величины углов в треугольнике должны быть от 0 до 180 градусов!");
    mbox.exec();
    return false;
    }
    return res;
}
bool Triangle::checkTriangleAngles2(const double &angle1, const double &angle2)
{
    bool res = angle1 > 0 && angle1 < M_PI && angle2 > 0 && angle2 < M_PI && angle1 + angle2 < M_PI;
    if (!res)
    {
        QMessageBox mbox;
        mbox.setText("Сумма углов в треугольнике не должна превышать 180 градусов!");
        mbox.exec();
        return false;
    }
    return res;
}
bool Triangle::checkTriangleAngles3(const double &angle1, const double &angle2, const double &angle3)
{
    bool res = (angle1 > 0 && angle1 < M_PI && angle2 > 0 &&
                angle2 < M_PI && angle1 + angle2 < M_PI &&
                angle3 > 0 && angle3 < M_PI && angle2 + angle3 < M_PI &&
                angle1 + angle3 < M_PI && angle1 && angle2 + angle3 < M_PI);
    if (!res)
    {
        QMessageBox mbox;
        mbox.setText("Сумма углов в треугольнике не должна превышать 180 градусов!");
        mbox.exec();
    }
       return res;
}
void Triangle::sendInputDataErrorMessage()
{
    QMessageBox mbox;
    mbox.setText("Невозможное сочетание входных параметров!");
    mbox.exec();
    return;
}
void Triangle::sendErrorMessage(const char* str)
{
    QMessageBox mbox;
    mbox.setText(str);
    mbox.exec();
}

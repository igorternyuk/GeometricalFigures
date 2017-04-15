#include "ellipse.h"
#include <math.h>
#include <QMessageBox>
Ellipse::Ellipse(double semimajorAxis, double semiminorAxis)
{
    this->semimajorAxis = semimajorAxis;
    this->semiminorAxis = semiminorAxis;
    calculateParameters();
}
Ellipse::Ellipse(double radius)
{
    semimajorAxis = radius;
    semiminorAxis = radius;
    calculateParameters();
}
void Ellipse::calculateParameters()
{
    if (semimajorAxis <= 0 || semiminorAxis <= 0)
    {
        semimajorAxis = 0;
        semiminorAxis = 0;
        focusDistanse = 0;
        excentricity = 0;
        focusParameterP = 0;
        distanseBetweenFocuses = 0;
        area = 0;
        perimeter = 0;
        inertiaMomentX = 0;
        inertiaMomentY = 0;
        polarInertiaMoment = 0;
        momentOfResistanseX = 0;
        momentOfResistanseY = 0;
        polarMomentOfResistanse = 0;
        isNullSemiaxises = true;
        return;
    }
    isNullSemiaxises =false;
    focusDistanse = sqrt(semimajorAxis * semimajorAxis - semiminorAxis * semiminorAxis);
    excentricity = focusDistanse / semimajorAxis;
    focusParameterP = semiminorAxis * semiminorAxis / semimajorAxis;
    distanseBetweenFocuses = 2 * focusDistanse;
    area = M_PI * semimajorAxis * semiminorAxis;
    double x = log(2) / log(M_PI / 2);
    perimeter = 4 * pow((pow(semimajorAxis, x) + pow(semiminorAxis, x)), (1 / x));
    inertiaMomentX = M_PI * semimajorAxis * pow(semiminorAxis, 3) / 4;
    inertiaMomentY = M_PI * semiminorAxis * pow(semimajorAxis, 3) / 4;
    polarInertiaMoment = inertiaMomentX + inertiaMomentY;
    momentOfResistanseX = 2 * inertiaMomentX / semiminorAxis;
    momentOfResistanseY = 2 * inertiaMomentY / semimajorAxis;
    polarMomentOfResistanse = 2 * polarInertiaMoment / semimajorAxis;
}
double Ellipse::ellipseArcLengthFunction(double angle)
{
    return !isNullSemiaxises ? sqrt(pow(semimajorAxis  * sin(angle), 2) + pow(semiminorAxis  * cos(angle), 2)) : 0;
}
double Ellipse::calcEllipseArcLength(double fi1, double fi2, double eps)
{
    if(!isNullSemiaxises)
    {
    double h, Icurrent;
    double Iprev = 0;
    int n = 6;
    bool flag = false;
    double t1, t2;
    if (fi1 <= M_PI / 2)
       t1 = atan(semimajorAxis / semiminorAxis * tan(fi1));
    else if(fi1 <= M_PI)
       t1 = M_PI + atan(semimajorAxis / semiminorAxis * tan(fi1));
    else if(fi1 <= 3 * M_PI / 2)
       t1 = M_PI + atan(semimajorAxis / semiminorAxis * tan(fi1));
    else if(fi1 <= 2 * M_PI)
       t1 = 2 * M_PI + atan(semimajorAxis / semiminorAxis * tan(fi1));
    else
       t1 = 2 * M_PI;
    if (fi2 <= M_PI / 2)
       t2 = atan(semimajorAxis / semiminorAxis * tan(fi2));
    else if(fi2 <= M_PI)
       t2 = M_PI + atan(semimajorAxis / semiminorAxis * tan(fi2));
    else if(fi2 <= 3 * M_PI / 2)
       t2 = M_PI + atan(semimajorAxis / semiminorAxis * tan(fi2));
    else if(fi2 <= 2 * M_PI)
       t2 = 2 * M_PI + atan(semimajorAxis / semiminorAxis * tan(fi2));
    else
       t2 = 2 * M_PI;
    do
    {
        Icurrent = 0;
        n *= 2;
        h = (t2 - t1) / n;
        for(int k = 1; k < n; k += 2)
        {
            Icurrent += ellipseArcLengthFunction(t1 + (k - 1) * h);
            Icurrent += 4 * ellipseArcLengthFunction(t1 + k * h);
            Icurrent += ellipseArcLengthFunction(t1 + (k + 1) * h);
        }
        Icurrent = Icurrent * h / 3;
        flag = fabs(Iprev - Icurrent) < fabs(eps) ? true: false;
        Iprev = Icurrent;
    }while (!flag);
    return Icurrent;
    }else return 0;
}
double Ellipse::calcAnnulusArea(double a, double b)
{
    if(!isNullSemiaxises)
    {
       if(a < semimajorAxis && b < semiminorAxis)
       return getArea() - M_PI * a * b;
       else return 0;
    }else return 0;
}
double Ellipse::calcAreaOfSectorA_byHeight(double segmentHeight)
{
    if(!isNullSemiaxises)
    {
    if(segmentHeight <= 0)
        return 0;
    if(segmentHeight >= 2 * semimajorAxis)
        return getArea();
    return (segmentHeight <= semimajorAxis) ? semimajorAxis * semiminorAxis * acos((semimajorAxis - segmentHeight) / semimajorAxis) :
           getArea() - semimajorAxis * semiminorAxis * acos((segmentHeight - semimajorAxis) / semimajorAxis);
    }else return 0;
}
double Ellipse::calcAreaOfSectorB_byHeight(double segmentHeight)
{
    if(!isNullSemiaxises)
    {
    if(segmentHeight <= 0)
        return 0;
    if(segmentHeight >= 2 * semiminorAxis)
        return getArea();
    return (segmentHeight <= semiminorAxis) ? semimajorAxis * semiminorAxis * acos((semiminorAxis - segmentHeight) / semiminorAxis) :
           getArea() - semimajorAxis * semiminorAxis * acos((segmentHeight - semiminorAxis) / semiminorAxis);
    }else return 0;
}
double Ellipse::calcAreaOfSegmentA_byHeight(double segmentHeight)
{
    if(!isNullSemiaxises)
    {
    if(segmentHeight <= 0)
        return 0;
    if(segmentHeight >= 2 * semimajorAxis)
        return getArea();
    double x0 = semimajorAxis - segmentHeight;
    double y0 = semiminorAxis / semimajorAxis * sqrt(pow(semimajorAxis, 2) - x0 * x0);
    return calcAreaOfSectorA_byHeight(segmentHeight) - x0 * y0;
    }else return 0;
}
double Ellipse::calcAreaOfSegmentB_byHeight(double segmentHeight)
{
    if(!isNullSemiaxises)
    {
    if(segmentHeight <= 0)
        return 0;
    if(segmentHeight >= 2 * semiminorAxis)
        return getArea();
    double y0 = semiminorAxis - segmentHeight;
    double x0 = semimajorAxis / semiminorAxis * sqrt(pow(semiminorAxis, 2) - y0 * y0);
    return calcAreaOfSectorB_byHeight(segmentHeight) - x0 * y0;
    } else return 0;
}
double Ellipse::calcPerimeterOfSectorA_byHeight(double segmentHeight, double eps)
{
    if(!isNullSemiaxises)
    {
    if(segmentHeight <= 0)
        return 0;
    if(segmentHeight >= 2 * semimajorAxis)
        return getPerimeter();
    double x0 = semimajorAxis - segmentHeight;
    double y0 = semiminorAxis / semimajorAxis * sqrt(pow(semimajorAxis, 2) - x0 * x0);
    double t2 = atan(fabs(y0 * semimajorAxis / x0 / semiminorAxis));
    double t1 = 0;
    double arcLength = 2 * calcEllipseArcLength(t1, t2, eps);
    return (segmentHeight <= semimajorAxis) ? arcLength + 2 * sqrt(x0 * x0 + y0 * y0):
              getPerimeter() - arcLength + 2 * sqrt(x0 * x0 + y0 * y0);
    } else return 0;
}
double Ellipse::calcPerimeterOfSectorB_byHeight(double segmentHeight, double eps)
{
    if(!isNullSemiaxises)
    {
    if(segmentHeight <= 0)
       return 0;
    if(segmentHeight >= 2 * semiminorAxis)
        return getPerimeter();
       double y0 = semiminorAxis - segmentHeight;
       double x0 = semimajorAxis / semiminorAxis * sqrt(semimajorAxis * semimajorAxis - y0 * y0);
       double t1 = atan(fabs(y0 * semimajorAxis / x0 / semiminorAxis));
       double t2 = M_PI / 2;
       double arcLength = 2 * calcEllipseArcLength(t1, t2, eps);
       return (segmentHeight <= semiminorAxis) ? arcLength + 2 * sqrt(x0 * x0 + y0 * y0):
              getPerimeter() - arcLength + 2 * sqrt(x0 * x0 + y0 * y0);
    } else return 0;
}
double Ellipse::calcPerimeterOfSegmentA_byHeight(double segmentHeight, double eps)
{
    if(!isNullSemiaxises)
    {
    if(segmentHeight <= 0)
        return 0;
    if(segmentHeight >= 2 * semimajorAxis)
        return getPerimeter();
    double x0 = semimajorAxis - segmentHeight;
    double y0 = semiminorAxis / semimajorAxis * sqrt(pow(semimajorAxis, 2) - x0 * x0);
    double t2 = atan(fabs(y0 * semimajorAxis / x0 / semiminorAxis));
    double t1 = 0;
    double arcLength = 2 * calcEllipseArcLength(t1, t2, eps);
    return (segmentHeight <= semimajorAxis) ? arcLength + 2 * y0:
              getPerimeter() - arcLength + 2 * y0;
    } else return 0;
}
double Ellipse::calcPerimeterOfSegmentB_byHeight(double segmentHeight, double eps)
{
    if(!isNullSemiaxises)
    {
    if(segmentHeight <= 0)
       return 0;
    if(segmentHeight >= 2 * semiminorAxis)
        return getPerimeter();
       double y0 = semiminorAxis - segmentHeight;
       double x0 = semimajorAxis / semiminorAxis * sqrt(semimajorAxis * semimajorAxis - y0 * y0);
       double t1 = atan(fabs(y0 * semimajorAxis / x0 / semiminorAxis));
       double t2 = M_PI / 2;
       double arcLength = 2 * calcEllipseArcLength(t1, t2, eps);
       return (segmentHeight <= semiminorAxis) ? arcLength + 2 * x0:
              getPerimeter() - arcLength + 2 * x0;
    } else return 0;
}
double Ellipse::calcAreaOfSectorA_byAngle(double angle)
{
    if(!isNullSemiaxises)
    {
    bool flag = false;
    if(angle <= 0)
        return 0;
    if(angle >= 2 * M_PI)
        return getArea();
    if(angle == M_PI)
        return getArea() / 2;
    if(angle > M_PI)
      {
         angle = 2 * M_PI - angle;
         flag = true;
      }
    double segmentHeight = semimajorAxis - 1 / sqrt(1 / pow(semimajorAxis, 2) + pow(tan(angle/2) / semiminorAxis, 2));
    double area = semimajorAxis * semiminorAxis * acos((semimajorAxis - segmentHeight) / semimajorAxis);
    return !flag ? area : getArea() - area;
    } else return 0;
}
double Ellipse::calcAreaOfSectorB_byAngle(double angle)
{
    if(!isNullSemiaxises)
    {
    bool flag = false;
    if(angle <= 0)
        return 0;
    if(angle >= 2 * M_PI)
        return getArea();
    if(angle == M_PI)
        return getArea() / 2;
    if(angle > M_PI)
      {
        angle = 2 * M_PI - angle;
        flag = true;
      }
    double segmentHeight = semiminorAxis - 1 / sqrt(1 / pow(semimajorAxis / tan(angle / 2), 2) + pow(1 / semiminorAxis, 2));
    double area = semimajorAxis * semiminorAxis * acos((semiminorAxis - segmentHeight) / semiminorAxis);
    return !flag ? area : getArea() - area;
    }else return 0;
}
double Ellipse::calcAreaOfSegmentA_byAngle(double angle)
{
    if(!isNullSemiaxises)
    {
    bool flag = false;
    if(angle <= 0)
        return 0;
    if(angle >= 2 * M_PI)
        return getArea();
    if(angle == M_PI)
        return getArea() / 2;
    if(angle > M_PI)
         flag = true;
   double x0 = 1 / sqrt(1 / pow(semimajorAxis, 2) + pow(tan(angle / 2) / semiminorAxis, 2));
   double y0 = semiminorAxis / semimajorAxis * sqrt(pow(semimajorAxis, 2) - x0 * x0);
   return !flag ? calcAreaOfSectorA_byAngle(angle) - fabs(x0 * y0):
                  calcAreaOfSectorA_byAngle(angle) + fabs(x0 * y0);
    }else return 0;
}
double Ellipse::calcAreaOfSegmentB_byAngle(double angle)
{
    if(!isNullSemiaxises)
    {
    bool flag = false;
    if(angle <= 0)
        return 0;
    if(angle >= 2 * M_PI)
        return getArea();
    if(angle == M_PI)
        return getArea() / 2;
    if(angle > M_PI)
         flag = true;
   double y0 = 1 / sqrt(1 / pow(semimajorAxis / tan(angle / 2), 2) + 1 / pow(semiminorAxis, 2));
   double x0 = semimajorAxis / semiminorAxis * sqrt(pow(semiminorAxis, 2) - y0 * y0);
   return !flag ? calcAreaOfSectorB_byAngle(angle) - fabs(x0 * y0) :
                  calcAreaOfSectorB_byAngle(angle) + fabs(x0 * y0);
    }else return 0;
}
double Ellipse::calcPerimeterOfSectorA_byAngle(double angle, double eps)
{
    if(!isNullSemiaxises)
    {
    bool flag = false;
    if(angle <= 0)
        return 0;
    if(angle >= 2 * M_PI)
        return getPerimeter();
    if(angle == M_PI)
        return getPerimeter() / 2 + 2 * semiminorAxis;
    if(angle > M_PI)
      {
         angle = 2 * M_PI - angle;
         flag = true;
      }
    double x0 = 1 / sqrt(1 / pow(semimajorAxis, 2) + pow(tan(angle / 2) / semiminorAxis, 2));
    double arcLength = 2 * calcEllipseArcLength(0, angle / 2, eps);
    return !flag ? arcLength + 2 * x0 / cos(angle / 2) :
           getPerimeter() - arcLength + 2 * x0 / cos(angle / 2);
    }else return 0;
}
double Ellipse::calcPerimeterOfSectorB_byAngle(double angle, double eps)
{
    if(!isNullSemiaxises)
    {
    bool flag = false;
    if(angle <= 0)
        return 0;
    if(angle >= 2 * M_PI)
        return getPerimeter();
    if(angle == M_PI)
        return getPerimeter() / 2  + 2 * semimajorAxis;;
    if(angle > M_PI)
      {
         angle = 2 * M_PI - angle;
         flag = true;
      }
    double y0 = 1 / sqrt(1 / pow(semimajorAxis / tan(angle / 2), 2) + 1 / pow(semiminorAxis, 2));
    double arcLength = 2 * calcEllipseArcLength((M_PI - angle) / 2, M_PI / 2, eps);
    return !flag ? arcLength + 2 * y0 / sin(angle / 2) :
           getPerimeter() - arcLength + 2 * y0 / cos(angle / 2);
    } else return 0;
}
double Ellipse::calcPerimeterOfSegmentA_byAngle(double angle, double eps)
{
    if(!isNullSemiaxises)
    {
    bool flag = false;
    if(angle <= 0)
        return 0;
    if(angle >= 2 * M_PI)
        return getPerimeter();
    if(angle == M_PI)
        return getPerimeter() / 2  + 2 * semimajorAxis;;
    if(angle > M_PI)
      {
         angle = 2 * M_PI - angle;
         flag = true;
      }
    double y0 = 1 / sqrt(1 / pow(semimajorAxis * tan(angle / 2), 2) + 1 / pow(semiminorAxis, 2));
    double arcLength = 2 * calcEllipseArcLength(0, angle / 2, eps);
    return !flag ? arcLength + 2 * y0 :
           getPerimeter() - arcLength + 2 * y0;
    }else return 0;
}
double Ellipse::calcPerimeterOfSegmentB_byAngle(double angle, double eps)
{
    if(!isNullSemiaxises)
    {
    bool flag = false;

    if(angle <= 0)
        return 0;
    if(angle >= 2 * M_PI)
        return getPerimeter();
    if(angle == M_PI)
        return getPerimeter() / 2  + 2 * semiminorAxis;;
    if(angle > M_PI)
      {
         angle = 2 * M_PI - angle;
         flag = true;
      }
    double x0 = 1 / sqrt(1 / pow(semimajorAxis, 2) + pow(1 / tan(angle / 2) / semiminorAxis, 2));
    double arcLength = 2 * calcEllipseArcLength((M_PI - angle) / 2, M_PI / 2, eps);
    return !flag ? arcLength + 2 * x0 :
           getPerimeter() - arcLength + 2 * x0;
    } else return 0;
}
double Ellipse::getArea()
{
    return area;
}
double Ellipse::getPerimeter()
{
    return perimeter;
}
double Ellipse::getInertiaMomentX()
{
    return inertiaMomentX;
}
double Ellipse::getInertiaMomentY()
{
    return inertiaMomentY;
}
double Ellipse::getMomentOfResistanseX()
{
    return momentOfResistanseX;
}
double Ellipse::getMomentOfResistanseY()
{
    return momentOfResistanseY;
}
double Ellipse::getExcentricity()
{
    return excentricity;
}
double Ellipse::getFocusDistanse()
{
    return focusDistanse;
}
double Ellipse::getPolarInertiaMoment()
{
    return polarInertiaMoment;
}
double Ellipse::getPolarMomentOfResistance()
{
    return polarMomentOfResistanse;
}
double Ellipse::getFocusParameterP()
{
    return focusParameterP;
}
double Ellipse::getDistanseBetweenFocuses()
{
    return distanseBetweenFocuses;
}
double Ellipse::getSemimajorAxis()
{
    return semimajorAxis;
}
double Ellipse::getSemiminorAxis()
{
    return semiminorAxis;
}


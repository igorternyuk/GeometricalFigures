#include "cylinder.h"
#include "ellipse.h"
#include <math.h>
#include <QMessageBox>
Cylinder::Cylinder(double externalSemimajorAxis, double externalSemiminorAxis,
                   double internalSemimajorAxis, double internalSemiminorAxis,
                   double height, double density)
{
    if (externalSemimajorAxis <= 0 || externalSemiminorAxis <= 0 ||
        internalSemimajorAxis < 0 || internalSemiminorAxis < 0 ||
        externalSemimajorAxis <= internalSemimajorAxis ||
        externalSemimajorAxis <= internalSemiminorAxis ||
        externalSemiminorAxis <= internalSemimajorAxis ||
        externalSemiminorAxis <= internalSemiminorAxis ||
        height <= 0 || density <= 0)
         {
           internalEllipse = NULL;
           externalEllipse = NULL;
           this->height = 0;
           volume = 0;
           surfaceArea = 0;
           inertiaMomentX = 0;
           inertiaMomentY = 0;
           inertiaMomentZ = 0;
           this->density = 0;
           mass = 0;
           isNullCylinder = true;
         }
  internalEllipse = new Ellipse(internalSemimajorAxis, internalSemiminorAxis);
  externalEllipse = new Ellipse(externalSemimajorAxis, externalSemiminorAxis);
  this->height = height;
  this->density = density;
  isNullCylinder = false;
  this->calculateParameters();
}
Cylinder::Cylinder(double externalSemimajorAxis, double externalSemiminorAxis,
                   double height, double density): Cylinder(externalSemimajorAxis,externalSemiminorAxis,
                                                           0, 0, height, density)
{}
Cylinder::~Cylinder()
{
    if(internalEllipse != NULL)
        delete internalEllipse;
    if(externalEllipse != NULL)
        delete externalEllipse;
}

void Cylinder::calculateParameters()
{
    double externalSemimajorAxis = externalEllipse->getSemimajorAxis();
    double externalSemiminorAxis = externalEllipse->getSemiminorAxis();
    double internalSemimajorAxis = internalEllipse->getSemimajorAxis();
    double internalSemiminorAxis = internalEllipse->getSemiminorAxis();
    double l = 0, L = 0;
    double x = log(2) / log(M_PI / 2);
    volume = M_PI * height * (externalSemimajorAxis * externalSemiminorAxis -
                              internalSemimajorAxis * internalSemiminorAxis);
    mass = density * volume;
    if (externalSemimajorAxis == internalSemimajorAxis)
        L = 2 * M_PI * externalSemimajorAxis;
    else
        L = 4 * pow((pow(externalSemimajorAxis, x) + pow(externalSemiminorAxis, x)), (1 / x));
    if (internalSemimajorAxis == internalSemiminorAxis)
       l = 2 * M_PI * internalSemimajorAxis;
    else
       l = 4 * pow((pow(internalSemimajorAxis, x) + pow(internalSemiminorAxis, x)), (1 / x));
    surfaceArea = (L + l) * height + 2 * M_PI *
                  (externalSemimajorAxis * externalSemiminorAxis -
                   internalSemimajorAxis * internalSemiminorAxis);
    inertiaMomentX = M_PI * height / 12 * (externalSemimajorAxis * externalSemiminorAxis *
                           (3 * externalSemimajorAxis * externalSemimajorAxis + height * height) -
                           internalSemimajorAxis *  internalSemiminorAxis *
                           (3 * internalSemimajorAxis * internalSemimajorAxis + height * height));
    inertiaMomentY = M_PI * height / 12 * (externalSemimajorAxis * externalSemiminorAxis *
                     (3 * externalSemiminorAxis * externalSemiminorAxis + height * height) -
                     internalSemimajorAxis *  internalSemiminorAxis *
                     (3 * internalSemiminorAxis * internalSemiminorAxis + height * height));
    inertiaMomentZ = M_PI * height / 2 * (pow(externalSemimajorAxis, 3) * externalSemiminorAxis -
                                                pow(internalSemimajorAxis, 3) * internalSemiminorAxis);
}
double Cylinder::calcSegmentVolumeA_ByHeight(double segmentHeightA)
{
    if(!isNullCylinder)
    {
    if(segmentHeightA < 0)
        return 0;
    if(segmentHeightA > 2 * externalEllipse->getSemimajorAxis())
        return getVolume();
    if(segmentHeightA < externalEllipse->getSemimajorAxis() - internalEllipse->getSemimajorAxis())
        return externalEllipse->calcAreaOfSegmentA_byHeight(segmentHeightA);
    else
    {
        double h = segmentHeightA - (externalEllipse->getSemimajorAxis() - internalEllipse->getSemimajorAxis());
        return (externalEllipse->calcAreaOfSegmentA_byHeight(segmentHeightA) -
            internalEllipse->calcAreaOfSegmentA_byHeight(h)) * height;
    }
    }else return 0;
}
double Cylinder::calcSegmentVolumeB_ByHeight(double segmentHeightB)
{
    if(!isNullCylinder)
    {
    if(segmentHeightB < 0)
        return 0;
    if(segmentHeightB > 2 * externalEllipse->getSemiminorAxis())
        return getVolume();
    if(segmentHeightB < externalEllipse->getSemiminorAxis() - internalEllipse->getSemiminorAxis())
        return externalEllipse->calcAreaOfSegmentB_byHeight(segmentHeightB);
    else
    {
        double h = segmentHeightB - (externalEllipse->getSemiminorAxis() - internalEllipse->getSemiminorAxis());
        return (externalEllipse->calcAreaOfSegmentB_byHeight(segmentHeightB) -
            internalEllipse->calcAreaOfSegmentB_byHeight(h)) * height;
    }
    }
    else return 0;
}
double Cylinder::calcSectorVolumeA_ByHeight(double segmentHeightA)
{
    if(!isNullCylinder)
    {
    if(segmentHeightA < 0)
        return 0;
    if(segmentHeightA > 2 * externalEllipse->getSemimajorAxis())
        return getVolume();
    if(segmentHeightA < externalEllipse->getSemimajorAxis() - internalEllipse->getSemimajorAxis())
        return externalEllipse->calcAreaOfSectorA_byHeight(segmentHeightA);
    else
    {
        double h = segmentHeightA - (externalEllipse->getSemimajorAxis() - internalEllipse->getSemimajorAxis());
        return (externalEllipse->calcAreaOfSectorA_byHeight(segmentHeightA) -
            internalEllipse->calcAreaOfSectorA_byHeight(h)) * height;
    }
    }else return 0;
}
double Cylinder::calcSectorVolumeB_ByHeight(double segmentHeightB)
{
    if(!isNullCylinder)
    {
    if(segmentHeightB < 0)
        return 0;
    if(segmentHeightB > 2 * externalEllipse->getSemiminorAxis())
        return getVolume();
    if(segmentHeightB < externalEllipse->getSemiminorAxis() - internalEllipse->getSemiminorAxis())
        return externalEllipse->calcAreaOfSectorB_byHeight(segmentHeightB);
    else
    {
        double h = segmentHeightB - (externalEllipse->getSemiminorAxis() - internalEllipse->getSemiminorAxis());
        return (externalEllipse->calcAreaOfSectorB_byHeight(segmentHeightB) -
            internalEllipse->calcAreaOfSectorB_byHeight(h)) * height;
    }
    }else return 0;
}
double Cylinder::getVolume()
{
    return volume;
}
double Cylinder::getSurfaceArea()
{
    return surfaceArea;
}
double Cylinder::getInertiaMomentX()
{
    return inertiaMomentX;
}
double Cylinder::getInertiaMomentY()
{
    return inertiaMomentY;
}
double Cylinder::getInertiaMomentZ()
{
    return inertiaMomentZ;
}
double Cylinder::getMass()
{
    return mass;
}
double Cylinder::getExternalSemimajorAxis()
{
    return externalEllipse != NULL ? externalEllipse->getSemimajorAxis() : 0;
}
double Cylinder::getExternalSemiminorAxis()
{
    return externalEllipse != NULL ? externalEllipse->getSemiminorAxis() : 0;
}
double Cylinder::getInternalSemimajorAxis()
{
    return internalEllipse != NULL ? internalEllipse->getSemimajorAxis() : 0;
}
double Cylinder::getInternalSemiminorAxis()
{
    return internalEllipse != NULL ? internalEllipse->getSemiminorAxis() : 0;
}
double Cylinder::getHeight()
{
    return height;
}
double Cylinder::getDensity()
{
    return density;
}


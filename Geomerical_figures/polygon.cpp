#include "polygon.h"
#include <math.h>
Polygon::Polygon(char type, const int &numberOfEdges, const double &geometryParameter)
{
    if(geometryParameter <= 0)
    {
        perimeter = 0;
        area = 0;
        sumOfInternalAngles = 0;
        sectorArea = 0;
        segmentArea = 0;
        inertiaMomemtZ = 0;
        return;
    }
    this->numberOfEdges = numberOfEdges;
    centralAngle = 2 * M_PI / numberOfEdges;
    switch (type)
    {
      case 'R': externalRadius = geometryParameter;
                edge = 2 * externalRadius * sin(0.5 * centralAngle);
                internalRadius = externalRadius * cos(0.5 * centralAngle);
                break;
      case 'r':
                internalRadius = geometryParameter;
                externalRadius = internalRadius / cos(0.5 * centralAngle);
                edge = 2 * externalRadius * sin(0.5 * centralAngle);
                break;
      case 'a':
      default:  edge = geometryParameter;
                externalRadius =  0.5 * edge / sin(0.5 * centralAngle);
                internalRadius = 0.5 * edge / tan(0.5 * centralAngle);
                break;
    }
    calculateParameters();
}
void Polygon::calculateParameters()
{
    perimeter = numberOfEdges * edge;
    area = 0.5 * pow(externalRadius, 2) * sin(centralAngle) * numberOfEdges;
    sumOfInternalAngles = (M_PI - centralAngle) * numberOfEdges;
    sectorArea = pow(externalRadius, 2) * centralAngle / 2;
    segmentArea = sectorArea - 0.5 * pow(externalRadius, 2) * sin(centralAngle);
    inertiaMomemtZ = numberOfEdges * (edge * pow(internalRadius, 3) / 36 +
                     0.5 * pow(externalRadius, 2) * sin(centralAngle) * pow(2 * internalRadius / 3, 2));
}
int Polygon::getNumberOfEdges()
{
    return numberOfEdges;
}
double Polygon::getEdge()
{
    return edge;
}
double Polygon::getExternalRadius()
{
    return externalRadius;
}
double Polygon::getInternalRadius()
{
    return internalRadius;
}
double Polygon::getArea()
{
    return area;
}
double Polygon::getPerimeter()
{
    return perimeter;
}
double Polygon::getCentralAngle()
{
    return centralAngle;
}
double Polygon::getSumOfInternalAngles()
{
    return sumOfInternalAngles;
}
double Polygon::getSegmentArea()
{
    return segmentArea;
}
double Polygon::getSectorArea()
{
    return sectorArea;
}
double Polygon::getInternalMomentZ()
{
   return inertiaMomemtZ;
}

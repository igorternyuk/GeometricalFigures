#include "cone.h"
#include <math.h>
#include <QMessageBox>

Cone::Cone(double bottomBaseRadius, double topBaseRadius, double height, double density)
{
    if (bottomBaseRadius <= 0 || topBaseRadius < 0 || height <= 0 ||
        density <= 0 || bottomBaseRadius <= topBaseRadius)
      {
        volume = 0;
        mass = 0;
        generatorAngle =  0;
        bottomBaseArea = 0;
        topBaseArea = 0;
        conicalSurfaceArea = 0;
        fullSurfaceArea = 0;
        generatorLength = 0;
        gravityCenterHeight = 0;
        inertiaMomentX = 0;
        inertiaMomentY = 0;
        inertiaMomentZ = 0;
        inertiaMomentXgc = 0;
        inertiaMomentYgc = 0;
        inertiaMomentZgc = 0;
        return;
      }
    this->bottomBaseRadius = bottomBaseRadius;
    this->topBaseRadius = topBaseRadius;
    this->height = height;
    this->density = density;
    calculateParameters();
}
Cone::Cone(double bottomBaseRadius, double height, double density): Cone(bottomBaseRadius, 0, height, density)
{}
double Cone::calculateUncuttedConeVolume(double radius, double height)
{
    return M_PI * pow(radius, 2) * height / 3;
}
double Cone::calculateUncuttedConeConicalSurfaceArea(double radius, double height)
{
    return M_PI * radius * pow(radius, 2) * height;
}
double Cone::calculateUncuttedConeInertiaMomentX(double mass, double radius, double height)
{
    return 3 * mass * (pow(radius, 2) / 4 + pow(height, 2)) / 5;
}
double Cone::calculateUncuttedConeInertiaMomentZ(double mass, double radius)
{
    return  3 * mass * pow(radius, 2) / 10;
}
void Cone::calculateParameters()
{
    volume = M_PI * height * (pow(bottomBaseRadius, 2) + bottomBaseRadius * topBaseRadius + pow(topBaseRadius, 2)) / 3;
    mass = volume * density;
    generatorAngle =  atan(height / (bottomBaseRadius - topBaseRadius));
    bottomBaseArea = M_PI * pow(bottomBaseRadius, 2);
    topBaseArea = M_PI * pow(topBaseRadius, 2);
    conicalSurfaceArea = M_PI * (pow(bottomBaseRadius, 2)- pow(topBaseRadius, 2)) / cos(generatorAngle);
    fullSurfaceArea = conicalSurfaceArea + bottomBaseArea + topBaseArea;
    generatorLength = (bottomBaseRadius - topBaseRadius)  / cos(generatorAngle);
    gravityCenterHeight = 0.25 * height * (pow(bottomBaseRadius, 2) + 2 * bottomBaseRadius * topBaseRadius + 3 * pow(topBaseRadius, 2)) /
                          (pow(bottomBaseRadius, 2) + bottomBaseRadius * topBaseRadius + pow(topBaseRadius, 2));

    double fullHeight = bottomBaseRadius  * tan(generatorAngle);
    double deltaHeight = fullHeight - height;
    double fullMass = density * calculateUncuttedConeVolume(bottomBaseRadius, fullHeight);
    double deltaMass = density * calculateUncuttedConeVolume(topBaseRadius, deltaHeight);
    double tmp = calculateUncuttedConeInertiaMomentX(fullMass, bottomBaseRadius, fullHeight) -
            calculateUncuttedConeInertiaMomentX(deltaMass, topBaseRadius, deltaHeight);
    inertiaMomentXgc = tmp - mass * pow(fullHeight - gravityCenterHeight, 2);
    inertiaMomentYgc = inertiaMomentXgc;
    inertiaMomentX = inertiaMomentXgc + mass * pow(gravityCenterHeight, 2);
    inertiaMomentY = inertiaMomentX;
    inertiaMomentZ = calculateUncuttedConeInertiaMomentZ(fullMass, bottomBaseRadius) -
                     calculateUncuttedConeInertiaMomentZ(deltaMass, topBaseRadius);
    inertiaMomentZgc = inertiaMomentZ;
}
double Cone::getBottomBaseRadius()
{
    return bottomBaseRadius;
}
double Cone::getTopBaseRadius()
{
    return topBaseRadius;
}
double Cone::getHeight()
{
    return height;
}
double Cone::getVolume()
{
    return volume;
}
double Cone::getFullSurfaceArea()
{
    return fullSurfaceArea;
}
double Cone::getConicalSurfaceArea()
{
    return conicalSurfaceArea;
}
double Cone::getTopBaseArea()
{
    return topBaseArea;
}
double Cone::getBottomBaseArea()
{
    return bottomBaseArea;
}
double Cone::getGeneratorAngel()
{
    return generatorAngle;
}
double Cone::getMass()
{
    return mass;
}
double Cone::getInertiaMomentX()
{
    return inertiaMomentX;
}
double Cone::getInertiaMomentY()
{
    return inertiaMomentY;
}
double Cone::getInertiaMomentZ()
{
    return inertiaMomentZ;
}
double Cone::getInertiaMomentXgc()
{
    return inertiaMomentXgc;
}
double Cone::getInertiaMomentYgc()
{
    return inertiaMomentYgc;
}
double Cone::getInertiaMomentZgc()
{
    return inertiaMomentZgc;
}
double Cone::getGeneratorLength()
{
    return generatorLength;
}
double Cone::getGravityCenterheight()
{
    return gravityCenterHeight;
}

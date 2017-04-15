#ifndef CONE_H
#define CONE_H

class Cone
{
private:
    double bottomBaseRadius, topBaseRadius, height, density,
           volume, conicalSurfaceArea, fullSurfaceArea, generatorLength,
           topBaseArea, bottomBaseArea, generatorAngle, mass, inertiaMomentX,
           inertiaMomentY, inertiaMomentZ, inertiaMomentXgc,
           inertiaMomentYgc, inertiaMomentZgc, gravityCenterHeight;
public:
    Cone(double, double, double);
    Cone(double, double, double,double);
private:
    double calculateUncuttedConeVolume(double, double);
    double calculateUncuttedConeConicalSurfaceArea(double, double);
    double calculateUncuttedConeInertiaMomentX(double, double, double);
    double calculateUncuttedConeInertiaMomentZ(double, double);
    void calculateParameters();
public:
    double getBottomBaseRadius();
    double getTopBaseRadius();
    double getHeight();
    double getVolume();
    double getGeneratorLength();
    double getFullSurfaceArea();
    double getConicalSurfaceArea();
    double getTopBaseArea();
    double getBottomBaseArea();
    double getGeneratorAngel();
    double getMass();
    double getInertiaMomentX();
    double getInertiaMomentY();
    double getInertiaMomentZ();
    double getInertiaMomentXgc();
    double getInertiaMomentYgc();
    double getInertiaMomentZgc();
    double getGravityCenterheight();

};

#endif // CONE_H

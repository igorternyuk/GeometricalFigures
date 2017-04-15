#ifndef POLYGON_H
#define POLYGON_H


class Polygon
{
    int numberOfEdges;
    double edge, externalRadius, internalRadius, inertiaMomemtZ,
           area, perimeter, centralAngle, sumOfInternalAngles,
           segmentArea, sectorArea;
public:
    Polygon();
    Polygon(char type, const int &numberOfEdges, const double &geometryParameter);
private:
    void   calculateParameters();
public:
    void   recalculateParameters(char);
    int    getNumberOfEdges();
    void   setEdge(double);
    double getEdge();
    void   setExternalRadius(double);
    double getExternalRadius();
    void   setInternalRadius(double);
    double getInternalRadius();
    double getInternalMomentZ();
    double getArea();
    double getPerimeter();
    double getCentralAngle();
    double getSumOfInternalAngles();
    double getSegmentArea();
    double getSectorArea();
};

#endif // POLYGON_H

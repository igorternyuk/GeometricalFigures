#ifndef PYRAMID_H
#define PYRAMID_H
#include "polygon.h"
#include "triangle.h"

class Pyramid
{
private:
    bool isInputDataCorrect;
    double volume, surfaceArea, mass, density, height;
    Polygon *topBasePolygon;
    Polygon *bottomBasePolygon;
    Triangle *pyramidFaceABC, *pyramidFaceABD,
             *pyramidFaceBCD, *pyramidFaceACD;
public:
    Pyramid(char var, double bottomBaseGeomPar, char var2, double topBaseGeomPar, int numberOfPolygonBaseSides, double height, double density);
    Pyramid(double * vertexCoord, double density);
    ~Pyramid();
private:
    void   calculatePolygonBasedPyramidParameters(Polygon* , const double&);
    void   calculatePolygonBasedTruncatedPyramidParameters(Polygon* , Polygon* , const double &);
    void   calculateTriangularPyramidParameters(double * vertexCoord);
    void   resetData();
public:
    double getSurfaceArea() const;
    double getVolume() const;
    double getMass() const;
    double getDensity() const;
    double getHeight() const;
    double getBottomBasePolygonExternalRadius() const;
    double getBottomBasePolygonInternalRadius() const;
    double getBottomBasePolygonEdge() const;
    double getTopBasePolygonExternalRadius() const;
    double getTopBasePolygonInternalRadius() const;
    double getTopBasePolygonEdge() const;
    bool    inputCorrectness() const;
};

#endif // PYRAMID_H

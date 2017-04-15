#include "pyramid.h"
#include <math.h>
#include "triangle.h"
#include <QMessageBox>
using namespace std;
Pyramid::Pyramid(char var1, double bottomBaseGeomPar, char var2, double topBaseGeomPar,
                 int numberOfPolygonBaseSides, double height, double density)
{
    if (bottomBaseGeomPar <= 0)
    {
        QMessageBox q;
        q.setText("Некорректное значение геометического параметра нижнего основания пирамиды!");
        q.exec();
        resetData();
        return;
    }
    if (height <= 0)
    {
        QMessageBox q;
        q.setText("Некорректное значение высоты пирамиды!");
        q.exec();
        resetData();
        return;
    }
    this->height = height;
    if (density <= 0)
    {
        QMessageBox q;
        q.setText("Некорректное плотности материала пирамиды!");
        q.exec();
        resetData();
        return;
    }
    this->density = density;
    isInputDataCorrect = true;
    bottomBasePolygon = new Polygon(var1, numberOfPolygonBaseSides, bottomBaseGeomPar);
           if(topBaseGeomPar <= 0)
              {
                 topBasePolygon = NULL;
                 calculatePolygonBasedPyramidParameters(bottomBasePolygon, height);
              }
           else
              {
                 topBasePolygon = new Polygon(var2, numberOfPolygonBaseSides, topBaseGeomPar);
                 calculatePolygonBasedTruncatedPyramidParameters(bottomBasePolygon, topBasePolygon, this->height);
              }
    pyramidFaceABC = NULL;
    pyramidFaceABD = NULL;
    pyramidFaceBCD = NULL;
    pyramidFaceACD = NULL;
}
Pyramid::Pyramid(double *vertexCoord, double density)
{
    if (density <= 0)
    {
        QMessageBox q;
        q.setText("Некорректное плотности материала пирамиды!");
        q.exec();
        resetData();
        return;
    }
    this->density = density;
    if(vertexCoord != NULL)
    {
       calculateTriangularPyramidParameters(vertexCoord);
       bottomBasePolygon = NULL;
       topBasePolygon = NULL;
       isInputDataCorrect = true;
    }
    else
    {
        resetData();
        return;
    }
}
Pyramid::~Pyramid()
{
    if(bottomBasePolygon != NULL)
    delete bottomBasePolygon;
    if(topBasePolygon != NULL)
    delete topBasePolygon;
    if(pyramidFaceABC != NULL)
    delete pyramidFaceABC;
    if(pyramidFaceABD != NULL)
    delete pyramidFaceABD;
    if(pyramidFaceBCD != NULL)
    delete pyramidFaceBCD;
    if(pyramidFaceACD != NULL)
    delete pyramidFaceACD;
}
void Pyramid::calculatePolygonBasedPyramidParameters(Polygon *polygon, const double &height)
{
    if(polygon != NULL)
    {
    volume = polygon->getArea() * height / 3;
    mass = volume * density;
    double pyramidEdge = sqrt(pow(polygon->getExternalRadius(), 2) + pow(height, 2));
    Triangle pyramidFace("a", "b", "c", polygon->getEdge(), pyramidEdge, pyramidEdge);
    double pyramidFaceArea = pyramidFace.getArea();
    surfaceArea = polygon->getArea() + polygon->getNumberOfEdges() * pyramidFaceArea;
    }else
    {
      volume = 0;
      surfaceArea = 0;
      mass = 0;
      return;
    }
}
void Pyramid::calculatePolygonBasedTruncatedPyramidParameters(Polygon *bottom, Polygon *top, const double &height)
{
    if(top != NULL && bottom != NULL)
    {
      double R1 = bottom->getExternalRadius();
      double R2 = top->getExternalRadius();
      if(R1 == R2)
      {
          volume = bottom->getArea() * height;
          surfaceArea = 2 * bottom->getArea() + bottom->getEdge() *
                        height * bottom->getNumberOfEdges();
          mass = volume * density;
          return;
      }
      double angle = R1 > R2 ? atan(height / (R1 - R2)): atan(height / (R2 - R1));
      double fullHeight = std::max(R1, R2) * tan(angle);
      double V1, V2, S1, S2;
      if(R1 > R2)
      {
          V1 = bottom->getArea() * fullHeight / 3;
          V2 = top->getArea() * (height - fullHeight) / 3;
          volume = V1 - V2;
          double L1 = sqrt(pow(bottom->getExternalRadius(),2) + pow(fullHeight,2));
          Triangle pyramidFace1("a", "b", "c", bottom->getEdge(), L1, L1);
          S1 = pyramidFace1.getArea() * bottom->getNumberOfEdges();
          double b2 = sqrt(pow(top->getExternalRadius(),2) + pow((height - fullHeight), 2));
          Triangle pyramidFace2("a", "b", "c", top->getEdge(), b2, b2);
          S2 = pyramidFace2.getArea() * top->getNumberOfEdges();
      }
      else
      {
          V1 = top->getArea() * fullHeight / 3;
          V2 = bottom->getArea() * (height - fullHeight) / 3;
          volume = V1 - V2;
          double L1 = sqrt(pow(top->getExternalRadius(),2) + pow(fullHeight,2));
          Triangle pyramidFace1("a", "b", "c", top->getEdge(), L1, L1);
          S1 = pyramidFace1.getArea() * top->getNumberOfEdges();
          double L2 = sqrt(pow(top->getExternalRadius(),2) + pow((height - fullHeight), 2));
          Triangle pyramidFace2("a", "b", "c", bottom->getEdge(), L2, L2);
          S2 = pyramidFace2.getArea() * bottom->getNumberOfEdges();
      }
      surfaceArea = S1 - S2 + bottom->getArea() + top->getArea();
      mass = volume * density;
    }else
    {
        volume = 0;
        surfaceArea = 0;
        mass = 0;
        return;
    }
}
void Pyramid::calculateTriangularPyramidParameters(double * vertexCoord)
{
    double Xa = 0, Ya = 0, Za = 0, Xb = 0, Yb = 0, Zb = 0, Xc = 0,
           Yc = 0, Zc = 0, Xd = 0, Yd = 0, Zd = 0;
    if(vertexCoord != NULL)
    {
    Xa = vertexCoord[0];
    Ya = vertexCoord[1];
    Za = vertexCoord[2];
    Xb = vertexCoord[3];
    Yb = vertexCoord[4];
    Zb = vertexCoord[5];
    Xc = vertexCoord[6];
    Yc = vertexCoord[7];
    Zc = vertexCoord[8];
    Xd = vertexCoord[9];
    Yd = vertexCoord[10];
    Zd = vertexCoord[11];
    }else
    {
        surfaceArea = 0;
        volume = 0;
        mass = 0;
        return;
    }
    double Xab = Xa - Xb;
    double Yab = Ya - Yb;
    double Zab = Za - Zb;
    double Xad = Xa - Xd;
    double Yad = Ya - Yd;
    double Zad = Za - Zd;
    double Xac = Xa - Xc;
    double Yac = Ya - Yc;
    double Zac = Za - Zc;
    double Xbd = Xb - Xd;
    double Ybd = Yb - Yd;
    double Zbd = Zb - Zd;
    double Xbc = Xb - Xc;
    double Ybc = Yb - Yc;
    double Zbc = Zb - Zc;
    double Xcd = Xc - Xd;
    double Ycd = Yc - Yd;
    double Zcd = Zc - Zd;

    if(Xab * (Yac * Zad - Yad * Zac) - Yab * (Xac * Zad - Xad * Zac) +
       Zab * (Xac * Yad - Xad * Yac) == 0)
    {
        QMessageBox q;
        q.setText("Вершины пирамиды не должны лежать в одной плоскости!");
        q.exec();
        surfaceArea = 0;
        volume = 0;
        mass = 0;
        return;
        return;
    }
    double det1 = Yab * Zac - Yac * Zab;
    double det2 = Xac * Zab - Xab * Zac;
    double det3 = Xab * Yac - Xac * Yab;
    double planeEquationCoefA = -det1;
    double planeEquationCoefB = -det2;
    double planeEquationCoefC = -det3;
    double planeEquationCoefD = Xa * det1 + Ya * det2 + Za * det3;
    double height = fabs(planeEquationCoefA * Xd + planeEquationCoefB * Yd +
                         planeEquationCoefC * Zd + planeEquationCoefD) /
                    sqrt(pow(planeEquationCoefA, 2) + pow(planeEquationCoefB, 2)
                         + pow(planeEquationCoefC, 2));
    double pyramidEdgeAB = sqrt(Xab * Xab + Yab * Yab + Zab * Zab);
    double pyramidEdgeAD = sqrt(Xad * Xad + Yad * Yad + Zad * Zad);
    double pyramidEdgeAC = sqrt(Xac * Xac + Yac * Yac + Zac * Zac);
    double pyramidEdgeBD = sqrt(Xbd * Xbd + Ybd * Ybd + Zbd * Zbd);
    double pyramidEdgeBC = sqrt(Xbc * Xbc + Ybc * Ybc + Zbc * Zbc);
    double pyramidEdgeCD = sqrt(Xcd * Xcd + Ycd * Ycd + Zcd * Zcd);
    pyramidFaceABC = new Triangle("a", "b", "c", pyramidEdgeAB, pyramidEdgeAC, pyramidEdgeBC);
    pyramidFaceABD = new Triangle("a", "b", "c", pyramidEdgeAB, pyramidEdgeAD, pyramidEdgeBD);
    pyramidFaceBCD = new Triangle("a", "b", "c", pyramidEdgeBC, pyramidEdgeBD, pyramidEdgeCD);
    pyramidFaceACD = new Triangle("a", "b", "c", pyramidEdgeAD, pyramidEdgeAC, pyramidEdgeCD);
    surfaceArea = pyramidFaceABC->getArea() + pyramidFaceABD->getArea() +
                  pyramidFaceBCD->getArea() + pyramidFaceACD->getArea();
    volume = pyramidFaceABC->getArea() * height / 3;
    mass = volume * density;
  }
double Pyramid::getSurfaceArea() const
{
    return surfaceArea;
}
double Pyramid::getVolume() const
{
    return volume;
}
double Pyramid::getMass() const
{
    return mass;
}
double Pyramid::getBottomBasePolygonExternalRadius() const
{
    if(bottomBasePolygon != NULL)
        return bottomBasePolygon->getExternalRadius();
    else return 0;
}
double Pyramid::getBottomBasePolygonInternalRadius() const
{
    if(bottomBasePolygon != NULL)
        return bottomBasePolygon->getInternalRadius();
    else return 0;
}
double Pyramid::getBottomBasePolygonEdge() const
{
    if(bottomBasePolygon != NULL)
        return bottomBasePolygon->getEdge();
    else return 0;
}
double Pyramid::getTopBasePolygonExternalRadius() const
{
    if(topBasePolygon != NULL)
        return topBasePolygon->getExternalRadius();
    else return 0;
}
double Pyramid::getTopBasePolygonInternalRadius() const
{
    if(topBasePolygon != NULL)
        return topBasePolygon->getInternalRadius();
    else return 0;
}
double Pyramid::getTopBasePolygonEdge() const
{
    if(topBasePolygon != NULL)
        return topBasePolygon->getEdge();
    else return 0;
}
double Pyramid::getDensity() const
{
    return density;
}
double Pyramid::getHeight() const
{
    return height;
}
bool Pyramid::inputCorrectness() const
{
    return isInputDataCorrect;
}
void Pyramid::resetData()
{
    volume = 0;
    surfaceArea = 0;
    mass = 0;
    density = 0;
    height = 0;
    topBasePolygon = NULL;
    bottomBasePolygon = NULL;
    pyramidFaceABC = NULL;
    pyramidFaceABD = NULL;
    pyramidFaceBCD = NULL;
    pyramidFaceACD = NULL;
    isInputDataCorrect = false;
}

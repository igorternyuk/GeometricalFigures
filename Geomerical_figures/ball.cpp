#include "ball.h"
#include <math.h>
#include <QMessageBox>
Ball::Ball(double Radius, double density): Ellipsoid(Radius, Radius, Radius, density)
{
   this->Radius = Radius;
}
double Ball::calcBallSegementArea(double segmentHeight)
{
    if(Radius > 0)
    {
    double ballSegmentArea = 0;
    if(segmentHeight <= 0) return 0;
    if(segmentHeight >= 2 * Radius) return getSurfaceArea();
    if(segmentHeight <= Radius)
      {
        double r = sqrt(pow(Radius, 2) - pow((Radius - segmentHeight), 2));
        ballSegmentArea = 2 * M_PI * Radius * segmentHeight + M_PI * r * r;
      }
    else
      {
        double H2 = 2 * Radius - segmentHeight;
        double r2 = sqrt(pow(Radius, 2) - pow((Radius - H2), 2));
        ballSegmentArea = getSurfaceArea() -  2 * M_PI * Radius * H2 + M_PI * r2 * r2;
      }
    return ballSegmentArea;
    }else return 0;
}
double Ball::calcBallSegmentVolume(double segmentHeight)
{
    if(Radius > 0)
    {
    double ballSegmentVolume = 0;
    if(segmentHeight <= 0) return 0;
    if(segmentHeight >= 2 * Radius) return getVolume();
    if(segmentHeight <= Radius)
        ballSegmentVolume = M_PI * pow(segmentHeight, 2) * (Radius - (segmentHeight / 3));
      else
      {
        double H2 = 2 * Radius - segmentHeight;
        ballSegmentVolume = this->getVolume() - M_PI * pow(H2, 2) * (Radius - (H2 / 3));
      }
    return ballSegmentVolume;
    }else return 0;
}
double Ball::calcBallSegmentMass(double segmentHeight, double density)
{
    return (density > 0) ? calcBallSegmentVolume(segmentHeight) * density: 0;
}
double Ball::calcBallSectorArea(double segmentHeight)
{
    if(Radius > 0)
    {
    double ballSectorArea = 0;
    if(segmentHeight <= 0) return 0;
    if(segmentHeight >= 2 * Radius) return getSurfaceArea();
    if(segmentHeight <= Radius)
      {
        double r = sqrt(pow(Radius, 2) - pow((Radius - segmentHeight), 2));
        ballSectorArea = M_PI * Radius * (2 * segmentHeight + r);
      }
    else
      {
        double H2 = 2 * Radius - segmentHeight;
        double r2 = sqrt(pow(Radius, 2) - pow((Radius - H2), 2));
        ballSectorArea = this->getSurfaceArea() -  2 * M_PI * Radius * H2 + M_PI * Radius * r2;
      }
    return ballSectorArea;
    }else return 0;
}
double Ball::calcBallSectorVolume(double segmentHeight)
{
    double ballSectorVolume = 0;
    if(segmentHeight <= 0) return 0;
    if(segmentHeight >= 2 * Radius) return getSurfaceArea();
    if(segmentHeight <= Radius)
      {
        ballSectorVolume = 2 * M_PI / 3 * Radius * Radius * segmentHeight;
      }
    else
      {
        double H2 = 2 * Radius - segmentHeight;
        ballSectorVolume = getVolume() - 2 * M_PI / 3 * Radius * Radius * H2;
      }
    return ballSectorVolume;
}
double Ball::calcBallSectorMass(double segmentHeight, double density)
{
    return (density > 0) ? calcBallSectorVolume(segmentHeight) * density : 0;
}
double Ball::calcSphericalLayerArea(char par, double geomPar, double sphericalLayerHeight)
{
    if(Radius > 0)
    {
    double sphericalLayerArea = 0;
    if(sphericalLayerHeight <= 0 || geomPar <= 0) return 0;
    if(sphericalLayerHeight >= 2 * Radius) return getSurfaceArea();
    double H1, radius;
    if(par == 'h')
    {
       H1 = (geomPar < 2 * Radius) ? geomPar : 2 * Radius;
       radius = sqrt(pow(Radius, 2) - pow(Radius - H1, 2));
    }else
    {
       radius = (geomPar < Radius) ? geomPar : Radius;
       H1 = Radius - sqrt(Radius * Radius - radius * radius);
    }
    double H2 = H1 + sphericalLayerHeight;
      if (H2 <= Radius)
        {
          double r2 = sqrt(pow(Radius, 2) - pow((Radius - H2), 2));
          sphericalLayerArea = 2 * M_PI * Radius * sphericalLayerHeight + M_PI * radius * radius + M_PI * r2 * r2;
        }else
        {
          double H3 = (H2 < 2 * Radius) ? 2 * Radius - H2 : 0;
          double r3 = (H2 < 2 * Radius) ? sqrt(pow(Radius, 2) - pow((Radius - H3), 2)) : 0;
          sphericalLayerArea = 2 * M_PI * Radius * sphericalLayerHeight + M_PI * radius * radius + M_PI * r3 * r3;
        }
    return sphericalLayerArea;
    }else return 0;
}
double Ball::calcSphericalLayerVolume(char par, double geomPar, double sphericalLayerHeight)
{
    if(Radius > 0)
    {
    double sphericalLayerVolume = 0;
    if(sphericalLayerHeight <= 0 || geomPar <= 0) return 0;
    if(sphericalLayerHeight >= 2 * Radius) return getVolume();
    double H1, radius;
    if(par == 'h')
    {
       H1 = (geomPar < 2 * Radius) ? geomPar : 2 * Radius;
       radius = sqrt(pow(Radius, 2) - pow(Radius - H1, 2));
    }else
    {
       radius = (geomPar < Radius) ? geomPar : Radius;
       H1 = Radius - sqrt(Radius * Radius - radius * radius);
    }
    double H2 = H1 + sphericalLayerHeight;
      if (H2 <= Radius)
        {
          sphericalLayerVolume = M_PI *(H2 * H2 * (Radius - (1 / 3) * H2) - H1 * H1 * (Radius - (1 / 3) * H1));
        }else
        {
          double H3 = (H2 < 2 * Radius) ? 2 * Radius - H2 : 0;
          sphericalLayerVolume = getVolume() - M_PI * (pow(H1, 2) * (Radius - (H1 / 3)) + pow(H3, 2) * (Radius - (H3 / 3)));
        }
    return sphericalLayerVolume;
    } else return 0;
}
double Ball::calcSphericalLayerMass(char par, double geomPar, double height, double density)
{
    return (density > 0) ? calcSphericalLayerVolume(par, geomPar, height) : 0;
}
double Ball::getRadius()
{
    return Radius > 0 ? Radius : 0;
}


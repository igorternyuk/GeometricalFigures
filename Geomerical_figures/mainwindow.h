#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "polygon.h"
#include "trapezium.h"
#include "triangle.h"
#include "pyramid.h"
#include <QString>
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void on_pushButtonTriangleCalculation_clicked();
    void on_pushButtonTriangleByCoordinates_clicked();
    void on_pushButtonParallelogram_clicked();
    void on_pushButtonTrap_clicked();
    void on_pushButtonPolygon_clicked();
    void on_pushButtonCircle_clicked();
    void on_pushButtonCylinder_clicked();
    void on_pushButtonEllipse_clicked();
    void on_pushButtonEllipsoid_clicked();
    void on_pushButtonBall_clicked();
    void on_pushButtonTorus_clicked();
    void on_pushButtonCone_clicked();
    void on_pushButtonParallelepiped_clicked();
    void on_pushButtonPyramid_clicked();

private:
    Ui::MainWindow *ui;
    void polygonShowData (Polygon &plgn);
    void trapeziumShowData(Trapezium &trp);
    void pyramidShowData(bool isPiramidTriangular, Pyramid &pyramid);
    void triangleShowData(Triangle &triangle);
    void sendInputDataErrorMessage();
    void sendErrorMessage(const QString &str);
};

#endif // MAINWINDOW_H

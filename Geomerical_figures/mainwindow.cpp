#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <QValidator>
#include <QMessageBox>
#include <QDesktopWidget>
#include <QDebug>
#include "trianglebycoordinates.h"
#include "cylinder.h"
#include "ellipse.h"
#include "ellipsoid.h"
#include "circle.h"
#include "ball.h"
#include "torus.h"
#include "cone.h"
#include "parallelepiped.h"
#include "polygon.h"
#include "parallelogram.h"
#include "trapezium.h"
#include "triangle.h"
#include "pyramid.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QLocale locale(QLocale::English);
    QValidator *doubler = new QDoubleValidator(0);
    doubler->setLocale(locale);
    ui->lineEditCylinderA->setValidator(doubler);
    ui->lineEditCylinderB->setValidator(doubler);
    ui->lineEditCylinder_a->setValidator(doubler);
    ui->lineEditCylinder_a->setValidator(doubler);
    ui->lineEditCylinderH->setValidator(doubler);
    ui->lineEditCylinderRo->setValidator(doubler);
    ui->lineEditPyramidPolygonA->setValidator(doubler);
    ui->lineEditPyramidPolygonR->setValidator(doubler);
    ui->lineEditPyramidPolygon_r->setValidator(doubler);
    ui->lineEditPyramidPolygonH->setValidator(doubler);
    ui->lineEditPyramidPolygonDensity->setValidator(doubler);
    ui->lineEditPyramidXa->setValidator(doubler);
    ui->lineEditPyramidYa->setValidator(doubler);
    ui->lineEditPyramidZa->setValidator(doubler);
    ui->lineEditPyramidXb->setValidator(doubler);
    ui->lineEditPyramidYb->setValidator(doubler);
    ui->lineEditPyramidZb->setValidator(doubler);
    ui->lineEditPyramidXc->setValidator(doubler);
    ui->lineEditPyramidYc->setValidator(doubler);
    ui->lineEditPyramidZc->setValidator(doubler);
    ui->lineEditPyramidXd->setValidator(doubler);
    ui->lineEditPyramidYd->setValidator(doubler);
    ui->lineEditPyramidZd->setValidator(doubler);
    ui->lineEditPyramid3Density->setValidator(doubler);
    ui->lineEditCuboidA->setValidator(doubler);
    ui->lineEditCuboidB->setValidator(doubler);
    ui->lineEditCuboidC->setValidator(doubler);
    ui->lineEditCuboidDensity->setValidator(doubler);
    ui->lineEditTorusR->setValidator(doubler);
    ui->lineEditTorus_r->setValidator(doubler);
    ui->lineEditTorusDensity->setValidator(doubler);
    ui->lineEditConeR->setValidator(doubler);
    ui->lineEditCone_r->setValidator(doubler);
    ui->lineEditConeH->setValidator(doubler);
    ui->lineEditConeDensity->setValidator(doubler);
    ui->lineEditBallDensity->setValidator(doubler);
    ui->lineEditBallLayerH->setValidator(doubler);
    ui->lineEditBallSegmentH->setValidator(doubler);
    ui->lineEditBallR->setValidator(doubler);
    ui->lineEditBall_r->setValidator(doubler);
    ui->lineEditEllipseA->setValidator(doubler);
    ui->lineEditEllipseB->setValidator(doubler);
    ui->lineEditEllipseHa->setValidator(doubler);
    ui->lineEditEllipseHb->setValidator(doubler);
    ui->lineEditPolygonA->setValidator(doubler);
    ui->lineEditPolygonR->setValidator(doubler);
    ui->lineEditPolygon_r->setValidator(doubler);
    ui->lineEditCircleR->setValidator(doubler);
    ui->lineEditCircleD->setValidator(doubler);
    ui->lineEditCircleAlpha->setValidator(doubler);
    ui->lineEditCircleInternalRadius->setValidator(doubler);
    ui->lineEditCircleInternalDiameter->setValidator(doubler);
    ui->lineEditTrapA->setValidator(doubler);
    ui->lineEditTrapB->setValidator(doubler);
    ui->lineEditTrapC->setValidator(doubler);
    ui->lineEditTrapD->setValidator(doubler);
    ui->lineEditTrapAlpha->setValidator(doubler);
    ui->lineEditParallA->setValidator(doubler);
    ui->lineEditParallB->setValidator(doubler);
    ui->lineEditParallAlpha->setValidator(doubler);
    ui->lineEditParallBeta->setValidator(doubler);
    ui->lineEditTriangleA->setValidator(doubler);
    ui->lineEditTriangleB->setValidator(doubler);
    ui->lineEditTriangleC->setValidator(doubler);
    ui->lineEditTriangleAlpha->setValidator(doubler);
    ui->lineEditTriangleBeta->setValidator(doubler);
    ui->lineEditTriangleGamma->setValidator(doubler);    
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::sendErrorMessage(const QString &str)
{
    QMessageBox q;
    q.setText(str);
    q.exec();
}
void MainWindow::triangleShowData(Triangle &triangle)
{
    ui->lineEditTriangleAlpha->setText(QString::number(180 * triangle.getAngleAlpha() / M_PI));
    ui->lineEditTriangleBeta->setText(QString::number(180 * triangle.getAngleBeta() / M_PI));
    ui->lineEditTriangleGamma->setText(QString::number(180 * triangle.getAngleGamma() / M_PI));
    ui->lineEditTriangleA->setText(QString::number(triangle.getSideA()));
    ui->lineEditTriangleB->setText(QString::number(triangle.getSideB()));
    ui->lineEditTriangleC->setText(QString::number(triangle.getSideC()));
    ui->lineEditTriangleP->setText(QString::number(triangle.getPerimeter()));
    ui->lineEditTriangleS->setText(QString::number(triangle.getArea()));
    ui->lineEditTriangleR->setText(QString::number(triangle.getExternalRadius()));
    ui->lineEditTriangle_r->setText(QString::number(triangle.getInternalRadius()));
    ui->lineEditTriangleMa->setText(QString::number(triangle.getMedianaA()));
    ui->lineEditTriangleMb->setText(QString::number(triangle.getMedianaB()));
    ui->lineEditTriangleMc->setText(QString::number(triangle.getMedianaC()));
    ui->lineEditTriangleBa->setText(QString::number(triangle.getBisectorA()));
    ui->lineEditTriangleBb->setText(QString::number(triangle.getBisectorB()));
    ui->lineEditTriangleBc->setText(QString::number(triangle.getBisectorC()));
    ui->lineEditTriangleHeightA->setText(QString::number(triangle.getHeightA()));
    ui->lineEditTriangleHeightB->setText(QString::number(triangle.getHeightB()));
    ui->lineEditTriangleHeightC->setText(QString::number(triangle.getHeightC()));
    ui->lineEditTriangleIa->setText(QString::number(triangle.getInertiaMomentA()));
    ui->lineEditTriangleIb->setText(QString::number(triangle.getInertiaMomentB()));
    ui->lineEditTriangleIc->setText(QString::number(triangle.getInertiaMomentC()));
    ui->lineEditTriangleIac->setText(QString::number(triangle.getInertiaMomentAgc()));
    ui->lineEditTriangleIbc->setText(QString::number(triangle.getInertiaMomentBgc()));
    ui->lineEditTriangleIcc->setText(QString::number(triangle.getInertiaMomentCgc()));
    ui->lineEditTriangleXgc->setText(QString::number(triangle.getGravityCenterX()));
    ui->lineEditTriangleYgc->setText(QString::number(triangle.getGravityCenterY()));
}
void MainWindow::pyramidShowData(bool isPiramidTriangular, Pyramid &pyramid)
{
    if(isPiramidTriangular)
    {
       ui->lineEditPyramidS3->setText(QString::number(pyramid.getSurfaceArea()));
       ui->lineEditPyramidV3->setText(QString::number(pyramid.getVolume()));
       ui->lineEditPyramidMassa3->setText(QString::number(pyramid.getMass()));
    }else
    {
        qDebug()<< pyramid.inputCorrectness();
       if(pyramid.inputCorrectness())
        {
          ui->lineEditPyramidPolygonA->setText(QString::number(pyramid.getBottomBasePolygonEdge()));
          ui->lineEditPyramidPolygonR->setText(QString::number(pyramid.getBottomBasePolygonExternalRadius()));
          ui->lineEditPyramidPolygon_r->setText(QString::number(pyramid.getBottomBasePolygonInternalRadius()));
          ui->lineEditPyramidPolygonA_2->setText(QString::number(pyramid.getTopBasePolygonEdge()));
          ui->lineEditPyramidPolygonR_2->setText(QString::number(pyramid.getTopBasePolygonExternalRadius()));
          ui->lineEditPyramidPolygon_r_2->setText(QString::number(pyramid.getTopBasePolygonInternalRadius()));
          ui->lineEditPyramidPolygonH->setText(QString::number(pyramid.getHeight()));
          ui->lineEditPyramidPolygonDensity->setText(QString::number(pyramid.getDensity()));
          ui->lineEditPyramidS->setText(QString::number(pyramid.getSurfaceArea()));
          ui->lineEditPyramidV->setText(QString::number(pyramid.getVolume()));
          ui->lineEditPyramidMassa->setText(QString::number(pyramid.getMass()));
        }else
       {
           //qDebug()<< pyramid.inputCorrectness();
           ui->lineEditPyramidS->setText("######");
           ui->lineEditPyramidV->setText("######");
           ui->lineEditPyramidMassa->setText("######");
       }
    }
}
void MainWindow::on_pushButtonTriangleCalculation_clicked()
{
    double a = 0, b = 0, c = 0, alpha = 0, beta = 0, gamma = 0;

    if (ui->checkBoxTriangleA->checkState() && ui->checkBoxTriangleB->checkState() &&
        ui->checkBoxTriangleC->checkState() && !(ui->checkBoxTriangleAlpha->checkState()) &&
        !(ui->checkBoxTriangleBeta->checkState()) && !(ui->checkBoxTriangleGamma->checkState()))
    {
        a = ui->lineEditTriangleA->text().toDouble();
        b = ui->lineEditTriangleB->text().toDouble();
        c = ui->lineEditTriangleC->text().toDouble();
        Triangle triangle("a", "b", "c", a, b, c);
        triangleShowData(triangle);
    } else if(ui->checkBoxTriangleA->checkState() && ui->checkBoxTriangleB->checkState() &&
              !(ui->checkBoxTriangleC->checkState()) && ui->checkBoxTriangleAlpha->checkState() &&
              !(ui->checkBoxTriangleBeta->checkState()) && !(ui->checkBoxTriangleGamma->checkState()))
    {
        a = ui->lineEditTriangleA->text().toDouble();
        b = ui->lineEditTriangleB->text().toDouble();
        alpha = ui->lineEditTriangleAlpha->text().toDouble();
        alpha = alpha / 180 * M_PI;
        Triangle triangle("a", "b", "alpha", a, b, alpha);
        triangleShowData(triangle);

    } else if(ui->checkBoxTriangleA->checkState() && ui->checkBoxTriangleB->checkState() &&
              !(ui->checkBoxTriangleC->checkState()) && !(ui->checkBoxTriangleAlpha->checkState()) &&
              ui->checkBoxTriangleBeta->checkState() && !(ui->checkBoxTriangleGamma->checkState()))
    {
        a = ui->lineEditTriangleA->text().toDouble();
        b = ui->lineEditTriangleB->text().toDouble();
        beta = ui->lineEditTriangleBeta->text().toDouble();
        beta = beta / 180 * M_PI;
        Triangle triangle("a", "b", "beta", a, b, beta);
        triangleShowData(triangle);
    } else if(ui->checkBoxTriangleA->checkState() && ui->checkBoxTriangleB->checkState() &&
              !(ui->checkBoxTriangleC->checkState()) && !(ui->checkBoxTriangleAlpha->checkState()) &&
              !(ui->checkBoxTriangleBeta->checkState()) && ui->checkBoxTriangleGamma->checkState())
    {
        a = ui->lineEditTriangleA->text().toDouble();
        b = ui->lineEditTriangleB->text().toDouble();
        gamma = ui->lineEditTriangleGamma->text().toDouble();
        gamma = gamma / 180 * M_PI;
        Triangle triangle("a", "b", "gamma", a, b, gamma);
        triangleShowData(triangle);

    } else if(ui->checkBoxTriangleA->checkState() && !(ui->checkBoxTriangleB->checkState()) &&
              ui->checkBoxTriangleC->checkState() && ui->checkBoxTriangleAlpha->checkState() &&
              !(ui->checkBoxTriangleBeta->checkState()) && !(ui->checkBoxTriangleGamma->checkState()))
    {

        a = ui->lineEditTriangleA->text().toDouble();
        c = ui->lineEditTriangleC->text().toDouble();
        alpha = ui->lineEditTriangleAlpha->text().toDouble();
        alpha = alpha / 180 * M_PI;
        Triangle triangle("a", "c", "alpha", a, c, alpha);
        triangleShowData(triangle);

    } else if(ui->checkBoxTriangleA->checkState() && !(ui->checkBoxTriangleB->checkState()) &&
              ui->checkBoxTriangleC->checkState() && !(ui->checkBoxTriangleAlpha->checkState()) &&
              ui->checkBoxTriangleBeta->checkState() && !(ui->checkBoxTriangleGamma->checkState()))
    {

        a = ui->lineEditTriangleA->text().toDouble();
        c = ui->lineEditTriangleC->text().toDouble();
        beta = ui->lineEditTriangleBeta->text().toDouble();
        beta = beta / 180 * M_PI;
        Triangle triangle("a", "c", "beta", a, c, beta);
        triangleShowData(triangle);

    } else if(ui->checkBoxTriangleA->checkState() && !(ui->checkBoxTriangleB->checkState()) &&
              ui->checkBoxTriangleC->checkState() && !(ui->checkBoxTriangleAlpha->checkState()) &&
              !(ui->checkBoxTriangleBeta->checkState()) && ui->checkBoxTriangleGamma->checkState())
    {

        a = ui->lineEditTriangleA->text().toDouble();
        c = ui->lineEditTriangleC->text().toDouble();
        gamma = ui->lineEditTriangleGamma->text().toDouble();
        gamma = gamma / 180 * M_PI;
        Triangle triangle("a", "c", "gamma", a, c, gamma);
        triangleShowData(triangle);
    } else if(!(ui->checkBoxTriangleA->checkState()) && ui->checkBoxTriangleB->checkState() &&
              ui->checkBoxTriangleC->checkState() && ui->checkBoxTriangleAlpha->checkState() &&
              !(ui->checkBoxTriangleBeta->checkState()) && !(ui->checkBoxTriangleGamma->checkState()))
    {
        b = ui->lineEditTriangleB->text().toDouble();
        c = ui->lineEditTriangleC->text().toDouble();
        alpha = ui->lineEditTriangleAlpha->text().toDouble();
        alpha = alpha / 180 * M_PI;
        Triangle triangle("b", "c", "alpha", b, c, alpha);
        triangleShowData(triangle);
    } else if(!(ui->checkBoxTriangleA->checkState()) && ui->checkBoxTriangleB->checkState() &&
               ui->checkBoxTriangleC->checkState() && !(ui->checkBoxTriangleAlpha->checkState()) &&
               ui->checkBoxTriangleBeta->checkState() && !(ui->checkBoxTriangleGamma->checkState()))
    {
        b = ui->lineEditTriangleB->text().toDouble();
        c = ui->lineEditTriangleC->text().toDouble();
        beta = ui->lineEditTriangleBeta->text().toDouble();
        beta = beta / 180 * M_PI;
        Triangle triangle("b", "c", "beta", b, c, beta);
        triangleShowData(triangle);
    } else if(!(ui->checkBoxTriangleA->checkState()) && ui->checkBoxTriangleB->checkState() &&
              ui->checkBoxTriangleC->checkState() && !(ui->checkBoxTriangleAlpha->checkState()) &&
              !(ui->checkBoxTriangleBeta->checkState()) && ui->checkBoxTriangleGamma->checkState())
    {
        b = ui->lineEditTriangleB->text().toDouble();
        c = ui->lineEditTriangleC->text().toDouble();
        gamma = ui->lineEditTriangleGamma->text().toDouble();
        gamma = gamma / 180 * M_PI;
        Triangle triangle("b", "c", "gamma", b, c, gamma);
        triangleShowData(triangle);
    } else if(ui->checkBoxTriangleA->checkState() && !(ui->checkBoxTriangleB->checkState()) &&
              !(ui->checkBoxTriangleC->checkState()) && ui->checkBoxTriangleAlpha->checkState() &&
              ui->checkBoxTriangleBeta->checkState() && !(ui->checkBoxTriangleGamma->checkState()))
    {
        a = ui->lineEditTriangleA->text().toDouble();
        alpha = ui->lineEditTriangleAlpha->text().toDouble();
        beta = ui->lineEditTriangleBeta->text().toDouble();
        alpha = alpha / 180 * M_PI;
        beta = beta / 180 * M_PI;
        Triangle triangle("a", "alpha", "beta", a, alpha, beta);
        triangleShowData(triangle);
    } else if(!(ui->checkBoxTriangleA->checkState()) && ui->checkBoxTriangleB->checkState() &&
              !(ui->checkBoxTriangleC->checkState()) && ui->checkBoxTriangleAlpha->checkState() &&
              ui->checkBoxTriangleBeta->checkState() && !(ui->checkBoxTriangleGamma->checkState()))
    {
        b = ui->lineEditTriangleB->text().toDouble();
        alpha = ui->lineEditTriangleAlpha->text().toDouble();
        beta = ui->lineEditTriangleBeta->text().toDouble();
        alpha = alpha / 180 * M_PI;
        beta = beta / 180 * M_PI;
        Triangle triangle("b", "alpha", "beta", b, alpha, beta);
        triangleShowData(triangle);
    } else if(!(ui->checkBoxTriangleA->checkState()) && !(ui->checkBoxTriangleB->checkState()) &&
              ui->checkBoxTriangleC->checkState() && ui->checkBoxTriangleAlpha->checkState() &&
              ui->checkBoxTriangleBeta->checkState() && !(ui->checkBoxTriangleGamma->checkState()))
        {
        c = ui->lineEditTriangleC->text().toDouble();
        alpha = ui->lineEditTriangleAlpha->text().toDouble();
        beta = ui->lineEditTriangleBeta->text().toDouble();
        alpha = alpha / 180 * M_PI;
        beta = beta / 180 * M_PI;
        Triangle triangle("c", "alpha", "beta", c, alpha, beta);
        triangleShowData(triangle);
    } else if(ui->checkBoxTriangleA->checkState() && !(ui->checkBoxTriangleB->checkState()) &&
              !(ui->checkBoxTriangleC->checkState()) && ui->checkBoxTriangleAlpha->checkState() &&
              !(ui->checkBoxTriangleBeta->checkState()) && ui->checkBoxTriangleGamma->checkState())
    {
        a = ui->lineEditTriangleA->text().toDouble();
        alpha= ui->lineEditTriangleAlpha->text().toDouble();
        gamma = ui->lineEditTriangleGamma->text().toDouble();
        alpha = alpha / 180 * M_PI;
        gamma = gamma / 180 * M_PI;
        Triangle triangle("a", "alpha", "gamma", a, alpha, gamma);
        triangleShowData(triangle);
    } else if(!(ui->checkBoxTriangleA->checkState()) && ui->checkBoxTriangleB->checkState() &&
              !(ui->checkBoxTriangleC->checkState()) && ui->checkBoxTriangleAlpha->checkState() &&
              !(ui->checkBoxTriangleBeta->checkState()) && ui->checkBoxTriangleGamma->checkState())
    {
        b = ui->lineEditTriangleB->text().toDouble();
        alpha= ui->lineEditTriangleAlpha->text().toDouble();
        gamma = ui->lineEditTriangleGamma->text().toDouble();
        alpha = alpha / 180 * M_PI;
        gamma = gamma / 180 * M_PI;
        Triangle triangle("b", "alpha", "gamma", b, alpha, gamma);
        triangleShowData(triangle);
    } else if(!(ui->checkBoxTriangleA->checkState()) && !(ui->checkBoxTriangleB->checkState()) &&
              ui->checkBoxTriangleC->checkState() && ui->checkBoxTriangleAlpha->checkState() &&
              !(ui->checkBoxTriangleBeta->checkState()) && ui->checkBoxTriangleGamma->checkState())
    {
        c = ui->lineEditTriangleC->text().toDouble();
        alpha= ui->lineEditTriangleAlpha->text().toDouble();
        gamma = ui->lineEditTriangleGamma->text().toDouble();
        alpha = alpha / 180 * M_PI;
        gamma = gamma / 180 * M_PI;
        Triangle triangle("c", "alpha", "gamma", c, alpha, gamma);
        triangleShowData(triangle);
    } else if(ui->checkBoxTriangleA->checkState() && !(ui->checkBoxTriangleB->checkState()) &&
              !(ui->checkBoxTriangleC->checkState()) && !(ui->checkBoxTriangleAlpha->checkState()) &&
              ui->checkBoxTriangleBeta->checkState() && ui->checkBoxTriangleGamma->checkState())
    {
        a = ui->lineEditTriangleA->text().toDouble();
        beta= ui->lineEditTriangleBeta->text().toDouble();
        gamma = ui->lineEditTriangleGamma->text().toDouble();
        beta = beta / 180 * M_PI;
        gamma = gamma / 180 * M_PI;
        Triangle triangle("a", "beta", "gamma", a, beta, gamma);
        triangleShowData(triangle);
    } else if(!(ui->checkBoxTriangleA->checkState()) && ui->checkBoxTriangleB->checkState() &&
              !(ui->checkBoxTriangleC->checkState()) && !(ui->checkBoxTriangleAlpha->checkState()) &&
              ui->checkBoxTriangleBeta->checkState() && ui->checkBoxTriangleGamma->checkState())
    {
        b = ui->lineEditTriangleB->text().toDouble();
        beta= ui->lineEditTriangleBeta->text().toDouble();
        gamma = ui->lineEditTriangleGamma->text().toDouble();
        beta = beta / 180 * M_PI;
        gamma = gamma / 180 * M_PI;
        Triangle triangle("b", "beta", "gamma", b, beta, gamma);
        triangleShowData(triangle);
    } else if(!(ui->checkBoxTriangleA->checkState()) && !(ui->checkBoxTriangleB->checkState()) &&
              ui->checkBoxTriangleC->checkState() && !(ui->checkBoxTriangleAlpha->checkState()) &&
              ui->checkBoxTriangleBeta->checkState() && ui->checkBoxTriangleGamma->checkState())
    {
        c = ui->lineEditTriangleC->text().toDouble();
        beta= ui->lineEditTriangleBeta->text().toDouble();
        gamma = ui->lineEditTriangleGamma->text().toDouble();
        beta = beta / 180 * M_PI;
        gamma = gamma / 180 * M_PI;
        Triangle triangle("c", "beta", "gamma", c, beta, gamma);
        triangleShowData(triangle);
    } else if(ui->checkBoxTriangleA->checkState() && !(ui->checkBoxTriangleB->checkState()) &&
             !(ui->checkBoxTriangleC->checkState()) && ui->checkBoxTriangleAlpha->checkState() &&
              ui->checkBoxTriangleBeta->checkState() && ui->checkBoxTriangleGamma->checkState())
    {
        a = ui->lineEditTriangleA->text().toDouble();
        alpha= ui->lineEditTriangleAlpha->text().toDouble();
        beta= ui->lineEditTriangleBeta->text().toDouble();
        gamma = ui->lineEditTriangleGamma->text().toDouble();
        alpha = alpha / 180 * M_PI;
        beta = beta / 180 * M_PI;
        gamma = gamma / 180 * M_PI;
        Triangle triangle('a', a, alpha, beta, gamma);
        triangleShowData(triangle);
    } else if(!(ui->checkBoxTriangleA->checkState()) && ui->checkBoxTriangleB->checkState() &&
              !(ui->checkBoxTriangleC->checkState()) && ui->checkBoxTriangleAlpha->checkState() &&
               ui->checkBoxTriangleBeta->checkState() && ui->checkBoxTriangleGamma->checkState())
    {
        b = ui->lineEditTriangleB->text().toDouble();
        alpha= ui->lineEditTriangleAlpha->text().toDouble();
        beta= ui->lineEditTriangleBeta->text().toDouble();
        gamma = ui->lineEditTriangleGamma->text().toDouble();
        alpha = alpha / 180 * M_PI;
        beta = beta / 180 * M_PI;
        gamma = gamma / 180 * M_PI;
        Triangle triangle('b', b, alpha, beta, gamma);
        triangleShowData(triangle);
    } else if(!(ui->checkBoxTriangleA->checkState()) && !(ui->checkBoxTriangleB->checkState()) &&
              ui->checkBoxTriangleC->checkState() && ui->checkBoxTriangleAlpha->checkState() &&
               ui->checkBoxTriangleBeta->checkState() && ui->checkBoxTriangleGamma->checkState())
    {
        c = ui->lineEditTriangleC->text().toDouble();
        alpha= ui->lineEditTriangleAlpha->text().toDouble();
        beta= ui->lineEditTriangleBeta->text().toDouble();
        gamma = ui->lineEditTriangleGamma->text().toDouble();
        alpha = alpha / 180 * M_PI;
        beta = beta / 180 * M_PI;
        gamma = gamma / 180 * M_PI;
        Triangle triangle('c', c, alpha, beta, gamma);
        triangleShowData(triangle);
    } else if((!(ui->checkBoxTriangleA->checkState()) && ui->checkBoxTriangleB->checkState() &&
              ui->checkBoxTriangleC->checkState() && ui->checkBoxTriangleAlpha->checkState() &&
               ui->checkBoxTriangleBeta->checkState() && ui->checkBoxTriangleGamma->checkState()) ||
              (ui->checkBoxTriangleA->checkState() && !(ui->checkBoxTriangleB->checkState()) &&
               ui->checkBoxTriangleC->checkState() && ui->checkBoxTriangleAlpha->checkState() &&
                ui->checkBoxTriangleBeta->checkState() && ui->checkBoxTriangleGamma->checkState()) ||
              (ui->checkBoxTriangleA->checkState() && ui->checkBoxTriangleB->checkState() &&
               !(ui->checkBoxTriangleC->checkState()) && ui->checkBoxTriangleAlpha->checkState() &&
                ui->checkBoxTriangleBeta->checkState() && ui->checkBoxTriangleGamma->checkState()) ||
              (ui->checkBoxTriangleA->checkState() && ui->checkBoxTriangleB->checkState() &&
               ui->checkBoxTriangleC->checkState() && !(ui->checkBoxTriangleAlpha->checkState()) &&
                ui->checkBoxTriangleBeta->checkState() && ui->checkBoxTriangleGamma->checkState()) ||
              (ui->checkBoxTriangleA->checkState() && ui->checkBoxTriangleB->checkState() &&
               ui->checkBoxTriangleC->checkState() && ui->checkBoxTriangleAlpha->checkState() &&
                !(ui->checkBoxTriangleBeta->checkState()) && ui->checkBoxTriangleGamma->checkState()) ||
              (ui->checkBoxTriangleA->checkState() && ui->checkBoxTriangleB->checkState() &&
               ui->checkBoxTriangleC->checkState() && ui->checkBoxTriangleAlpha->checkState() &&
                ui->checkBoxTriangleBeta->checkState() && !(ui->checkBoxTriangleGamma->checkState())) ||
              (ui->checkBoxTriangleA->checkState() && ui->checkBoxTriangleB->checkState() &&
               ui->checkBoxTriangleC->checkState() && ui->checkBoxTriangleAlpha->checkState() &&
                ui->checkBoxTriangleBeta->checkState() && ui->checkBoxTriangleGamma->checkState()))
    {
        QMessageBox q;
        q.setText("Установлено слишком много исходных данных!");
        q.exec();
        return;
    } else
    {
        QMessageBox q;
        q.setText("Установлено слишком мало исходных данных!");
        q.exec();
        return;
    }
}
void MainWindow::on_pushButtonTriangleByCoordinates_clicked()
{
    triangleByCoordinates *tr = new triangleByCoordinates();
    QRect myScreenGeometry = QApplication::desktop()->geometry() ;
    int x = (myScreenGeometry.width() - tr->width()) / 2;
    int y = (myScreenGeometry.height() - tr->height()) / 2;
    tr->move(x, y);
    tr->show();
}
void MainWindow::on_pushButtonParallelogram_clicked()
{
    if(ui->lineEditParallA->text() == "" ||
       ui->lineEditParallB->text() == "" ||
       ui->lineEditParallAlpha->text() == "")
    {
        QMessageBox q;
        q.setText("Не указаны необходимые исходные данные!");
        q.exec();
        return;
    }
    double a = ui->lineEditParallA->text().toDouble();
    double b = ui->lineEditParallB->text().toDouble();
    double alpha = ui->lineEditParallAlpha->text().toDouble();
    alpha = alpha * M_PI / 180;
    Parallelogram prlgrm(a, b, alpha);
    ui->lineEditParallBeta->setText(QString::number(180 * prlgrm.getAngleBeta() / M_PI));
    ui->lineEditParallS->setText(QString::number(prlgrm.getArea()));
    ui->lineEditParallP->setText(QString::number(prlgrm.getPerimeter()));
    ui->lineEditParallD1->setText(QString::number(prlgrm.getDiagonal1()));
    ui->lineEditParallD2->setText(QString::number(prlgrm.getDiagonal2()));
    ui->lineEditParallDelta->setText(QString::number(180 * prlgrm.getAngleDelta() / M_PI));
    ui->lineEditParallGamma->setText(QString::number(180 * prlgrm.getAngleGamma() / M_PI));
    ui->lineEditParallHeightA->setText(QString::number(prlgrm.getHeightA()));
    ui->lineEditParallHeightB->setText(QString::number(prlgrm.getHeightB()));
    ui->lineEditParallIa->setText(QString::number(prlgrm.getInertiaMomentA()));
    ui->lineEditParallIb->setText(QString::number(prlgrm.getInertiaMomentB()));
    ui->lineEditParallIac->setText(QString::number(prlgrm.getInertiaMomentAgc()));
    ui->lineEditParallIbc->setText(QString::number(prlgrm.getInertiaMomentBgc()));
    ui->lineEditParallelogramXgc->setText(QString::number(prlgrm.getGravityCenterX()));
    ui->lineEditParallelogramYgc->setText(QString::number(prlgrm.getGravityCenterY()));
}
void MainWindow::on_pushButtonTrap_clicked()
{
    double c = 0, d = 0, alpha = 0, h = 0;
    if(ui->lineEditTrapA->text() == "" ||
       ui->lineEditTrapB->text() == "")
    {
        QMessageBox q;
        q.setText("Не указны необходимые исходные данные!");
        q.exec();
        return;
    }
    double a = ui->lineEditTrapA->text().toDouble();
    double b = ui->lineEditTrapB->text().toDouble();
    if(ui->radioButtonFourSide->isChecked())
    {
        if(ui->lineEditTrapC->text() == "" || ui->lineEditTrapD->text() == "")
        {
            sendErrorMessage("Не указны необходимые исходные данные!");
            return;
        }
        c = ui->lineEditTrapC->text().toDouble();
        d = ui->lineEditTrapD->text().toDouble();
        Trapezium trp(true, a, b, c, d);
        trapeziumShowData(trp);

    }else
    {
        if(ui->lineEditTrapAlpha->text() == "" ||
           ui->lineEditTrapH->text() == "")
        {
            sendErrorMessage("Не указны необходимые исходные данные!");
            return;
        }
        alpha = ui->lineEditTrapAlpha->text().toDouble();
        alpha = alpha * M_PI / 180;
        h = ui->lineEditTrapH->text().toDouble();
        Trapezium trp(false, a, b, h, alpha);
        trapeziumShowData(trp);
    } 
}
void MainWindow::trapeziumShowData(Trapezium &trp)
{
    ui->lineEditTrapA->setText(QString::number(trp.getSideA()));
    ui->lineEditTrapB->setText(QString::number(trp.getSideB()));
    ui->lineEditTrapC->setText(QString::number(trp.getSideC()));
    ui->lineEditTrapD->setText(QString::number(trp.getSideD()));
    ui->lineEditTrapH->setText(QString::number(trp.getHeight()));
    ui->lineEditTrapAlpha->setText(QString::number(180 * trp.getAngleAlpha() / M_PI));
    ui->lineEditTrapBeta->setText(QString::number(180 * trp.getAngleBeta() / M_PI));
    ui->lineEditTrapGamma->setText(QString::number(180 * trp.getAngleGamma() / M_PI));
    ui->lineEditTrapDelta->setText(QString::number(180 * trp.getAngleDelta() / M_PI));
    ui->lineEditTrapD1->setText(QString::number(trp.getDiagonal1()));
    ui->lineEditTrapD2->setText(QString::number(trp.getDiagonal2()));
    ui->lineEditTrapS->setText(QString::number(trp.getArea()));
    ui->lineEditTrapP->setText(QString::number(trp.getPerimeter()));
    ui->lineEditTrapIa->setText(QString::number(trp.getInertiaMomentA()));
    ui->lineEditTrapXgc->setText(QString::number(trp.getGravityCenterX()));
    ui->lineEditTrapYgc->setText(QString::number(trp.getGravityCenterY()));
    ui->lineEditTrapIxgc->setText(QString::number(trp.getInertiaMomentXgc()));
    ui->lineEditTrapIygc->setText(QString::number(trp.getInertiaMomentYgc()));
}
void MainWindow::on_pushButtonPolygon_clicked()
{
    int numberOfPolygonEdges = ui->spinBoxPolygon->value();
    if(ui->radioButtonPolygonSide->isChecked())
    {
       if(ui->lineEditPolygonA->text() == "")
        {
           sendErrorMessage("Не указана величина стороны многоугольника!");
           return;
        }
        double a = ui->lineEditPolygonA->text().toDouble();
        Polygon polygon('a', numberOfPolygonEdges, a);
        polygonShowData(polygon);

    }else if(ui->radioButtonPolygonR->isChecked())
    {
       if(ui->lineEditPolygonR->text() == "")
        {
           sendErrorMessage("Не указана величина радиуса окружности описанной вокруг многоугольника!");
           return;
        }
        double R = ui->lineEditPolygonR->text().toDouble();
        Polygon polygon('R', numberOfPolygonEdges, R);
        polygonShowData(polygon);

    }else if(ui->radioButtonPolygon_r->isChecked())
    {
       if(ui->lineEditPolygon_r->text() == "")
        {
           sendErrorMessage("Не указана величина радиуса окружности вписанной в многоугольник!");
           return;
        }
        double r = ui->lineEditPolygon_r->text().toDouble();
        Polygon polygon('r', numberOfPolygonEdges, r);
        polygonShowData(polygon);
    }  
}
void MainWindow::polygonShowData(Polygon &plgn)
{
    ui->lineEditPolygonA->setText(QString::number(plgn.getEdge()));
    ui->lineEditPolygonR->setText(QString::number(plgn.getExternalRadius()));
    ui->lineEditPolygon_r->setText(QString::number(plgn.getInternalRadius()));
    ui->lineEditPolygonAlpha->setText(QString::number(180 * plgn.getCentralAngle() / M_PI));
    ui->lineEditPolygonS->setText(QString::number(plgn.getArea()));
    ui->lineEditPolygonP->setText(QString::number(plgn.getPerimeter()));
    ui->lineEditPolygonSumAlpha->setText(QString::number(180 * plgn.getSumOfInternalAngles() / M_PI));
    ui->lineEditPolygonSectorArea->setText(QString::number(plgn.getSectorArea()));
    ui->lineEditPolygonSegmentArea->setText(QString::number(plgn.getSegmentArea()));
    ui->lineEditPolygonIz->setText(QString::number(plgn.getInternalMomentZ()));
}
void MainWindow::on_pushButtonCircle_clicked()
{
    double circleRadius = 0, circleInternalRadius = 0;
    if (ui->radioButtonCircleR->isChecked())
    {
        if(ui->lineEditCircleR->text() == "")
        {
            sendErrorMessage("Не задано значение радиуса окружности!");
            return;
        }
        circleRadius = ui->lineEditCircleR->text().toDouble();
        if(ui->lineEditCircleInternalRadius->text() == "")
        {
            sendErrorMessage("Не задано значение внутреннего радиуса кольца!");
            return;
        }
        circleInternalRadius = ui->lineEditCircleInternalRadius->text().toDouble();
    }
    if (ui->radioButtonCircleD->isChecked())
    {
        if(ui->lineEditCircleD->text() == "")
        {
            sendErrorMessage("Не задано значение диаметра окружности!");
            return;
        }
        double circleDiameter = ui->lineEditCircleD->text().toDouble();
        if(circleDiameter < 0)
        {
            sendErrorMessage("Диаметр окружности не может быть отрицательным!");
            return;
        }
         circleRadius = 0.5 * circleDiameter;
         if(ui->lineEditCircleInternalDiameter->text() == "")
         {
             sendErrorMessage("Не задано значение внутреннего диаметра кольца!");
             return;
         }
         double circleInternalDiameter = ui->lineEditCircleInternalDiameter->text().toDouble();
         circleInternalRadius = 0.5 * circleInternalDiameter;
     }

     if(ui->lineEditCircleAlpha->text() == "")
     {
         sendErrorMessage("Не задано значение угла сектора!");
         return;
     }
     double circleSectorAngle = ui->lineEditCircleAlpha->text().toDouble();
     Circle circle(circleRadius);
     ui->lineEditCircleR->setText(QString::number(circleRadius));
     ui->lineEditCircleD->setText(QString::number(2 * circleRadius));
     ui->lineEditCircleAlpha->setText(QString::number(circleSectorAngle));
     ui->lineEditCircleInternalRadius->setText(QString::number(circleInternalRadius));
     ui->lineEditCircleInternalDiameter->setText(QString::number(2 * circleInternalRadius));
     ui->lineEditCircleS->setText(QString::number(circle.getArea()));
     ui->lineEditCircleL->setText(QString::number(circle.getArcLength()));
     ui->lineEditCircleSector->setText(QString::number(circle.calcCircleSectorArea(circleSectorAngle)));
     ui->lineEditCircleSegment->setText(QString::number(circle.calcCircleSegmentArea(circleSectorAngle)));
     ui->lineEditCircleIx->setText(QString::number(circle.getInertiaMomentX()));
     ui->lineEditCircleIp->setText(QString::number(circle.getPolarInertiaMoment()));
     ui->lineEditCircleWx->setText(QString::number(circle.getMomentOfResistanseX()));
     ui->lineEditCircleWp->setText(QString::number(circle.getPolarMomentOfResistance()));
     ui->lineEditAnnulusS->setText(QString::number(circle.calcAnnulusArea(circleInternalRadius)));
     ui->lineEditAnnulusP->setText(QString::number(circle.calcAnnulusPerimeter(circleInternalRadius)));
     ui->lineEditAnnulusIx->setText(QString::number(circle.calcAnnulusInertiaMomentX(circleInternalRadius)));
     ui->lineEditAnnulusIp->setText(QString::number(circle.calcAnnulusPolarInertiaMoment(circleInternalRadius)));
     ui->lineEditAnnulusWx->setText(QString::number(circle.calcAnnulusMomentOfResistanceX(circleInternalRadius)));
     ui->lineEditAnnulusWp->setText(QString::number(circle.calcAnnulusPolarMomentOfResistance(circleInternalRadius)));
     ui->lineEditAnnulusSectorArea->setText(QString::number(circle.calcAnnulusSectorArea(circleInternalRadius, circleSectorAngle)));
     ui->lineEditAnnulusSegmentArea->setText(QString::number(circle.calcAnnulusSegmentArea(circleInternalRadius, circleSectorAngle)));
}
void MainWindow::on_pushButtonCylinder_clicked()
{
        if(ui->lineEditCylinderA->text() == "")
        {
            sendErrorMessage("Не задано значение большой полуоси эллипса!");
            return;
        }
        double A = ui->lineEditCylinderA->text().toDouble();
        if(ui->lineEditCylinderB->text() == "")
        {
            sendErrorMessage("Не задано значение малой полуоси эллипса!");
            return;
        }
           double B = ui->lineEditCylinderB->text().toDouble();
        if(ui->lineEditCylinder_a->text() == "")
        {
            sendErrorMessage("Не задано значение большой полуоси внутреннего эллипса!");
            return;
        }
           double a = ui->lineEditCylinder_a->text().toDouble();
        if(ui->lineEditCylinder_b->text() == "")
        {
                sendErrorMessage("Не задано значение малой внутреннего эллипса!");
                return;
        }
           double b = ui->lineEditCylinder_b->text().toDouble();

        if(ui->lineEditCylinderH->text() == "")
        {
            sendErrorMessage("Не задано значение высоты цилиндра!");
            return;
        }
        double H = ui->lineEditCylinderH->text().toDouble();

        if(ui->lineEditCylinderRo->text() == "")
        {
            sendErrorMessage("Не задано значение плотности материала цилиндра!");
            return;
        }

        double ro = ui->lineEditCylinderRo->text().toDouble();

    Cylinder cylinder(A, B, a, b, H, ro);
    ui->lineEditCylinderS->setText(QString::number(cylinder.getSurfaceArea()));
    ui->lineEditCylinderV->setText(QString::number(cylinder.getVolume()));
    ui->lineEditCylinderM->setText(QString::number(cylinder.getMass()));
    ui->lineEditCylinderIx->setText(QString::number(cylinder.getInertiaMomentX()));
    ui->lineEditCylinderIy->setText(QString::number(cylinder.getInertiaMomentY()));
    ui->lineEditCylinderIz->setText(QString::number(cylinder.getInertiaMomentZ()));
    double Ha = ui->lineEditCylinderHa->text().toDouble();
    double Hb = ui->lineEditCylinderHb->text().toDouble();
    ui->lineEditCylinderSectorVa->setText(QString::number(cylinder.calcSectorVolumeA_ByHeight(Ha)));
    ui->lineEditCylinderSectorVb->setText(QString::number(cylinder.calcSectorVolumeB_ByHeight(Hb)));
    ui->lineEditCylinderSegmentVa->setText(QString::number(cylinder.calcSegmentVolumeA_ByHeight(Ha)));
    ui->lineEditCylinderSegmentVb->setText(QString::number(cylinder.calcSegmentVolumeB_ByHeight(Hb)));
}
void MainWindow::on_pushButtonEllipse_clicked()
{
    if(ui->lineEditEllipseA->text() == "")
    {
        sendErrorMessage("Не задано значение большой полуоси эллипса!");
        return;
    }
    double A = ui->lineEditEllipseA->text().toDouble();
    if(ui->lineEditEllipseB->text() == "")
    {
        sendErrorMessage("Не задано значение малой полуоси эллипса!");
        return;
    }
       double B = ui->lineEditEllipseB->text().toDouble();
    if(ui->lineEditEllipseHa->text() == "")
    {
        sendErrorMessage("Не задан параметр для расчета параметров сектора и сегмента, симметричных относительно большой полуоси эллипса!");
        return;
    }
    if(ui->lineEditEllipseHb->text() == "")
    {
            sendErrorMessage("Не задан параметр для расчета параметров сектора и сегмента, симметричных относительно малой полуоси эллипса!");
            return;
    }

    double eps = ui->lineEditEllipseCalcErr->text().toDouble();
    double fi1 = ui->doubleSpinBoxEllipseFi1->value();
    double fi2 = ui->doubleSpinBoxEllipseFi2->value();

Ellipse ellipse(A, B);
ui->lineEditEllipseArcLength->setText(QString::number(ellipse.calcEllipseArcLength(M_PI * fi1 / 180, M_PI * fi2 / 180, eps), 'f' , 10));
ui->lineEditEllipseS->setText(QString::number(ellipse.getArea()));
ui->lineEditEllipseP->setText(QString::number(ellipse.getPerimeter()));
ui->lineEditEllipseC->setText(QString::number(ellipse.getFocusDistanse()));
ui->lineEditEllipseEpsilon->setText(QString::number(ellipse.getExcentricity()));
ui->lineEditEllipseIx->setText(QString::number(ellipse.getInertiaMomentX()));
ui->lineEditEllipseIy->setText(QString::number(ellipse.getInertiaMomentY()));
ui->lineEditEllipseWx->setText(QString::number(ellipse.getMomentOfResistanseX()));
ui->lineEditEllipseWy->setText(QString::number(ellipse.getMomentOfResistanseY()));
ui->lineEditEllipseIp->setText(QString::number(ellipse.getPolarInertiaMoment()));
ui->lineEditEllipseWp->setText(QString::number(ellipse.getPolarMomentOfResistance()));
ui->lineEditEllipseF->setText(QString::number(ellipse.getDistanseBetweenFocuses()));
ui->lineEditEllipse_p->setText(QString::number(ellipse.getFocusParameterP()));

if(ui->comboBoxEllipseA->currentIndex() == 0)
{
    double Ha = ui->lineEditEllipseHa->text().toDouble();
    ui->lineEditEllipseSectorA->setText(QString::number(ellipse.calcAreaOfSectorA_byHeight(Ha)));
    ui->lineEditEllipseSegmentA->setText(QString::number(ellipse.calcAreaOfSegmentA_byHeight(Ha)));
    ui->lineEditEllipseSectorPerimeterA->setText(QString::number(ellipse.calcPerimeterOfSectorA_byHeight(Ha, eps)));
    ui->lineEditEllipseSegmentPerimeterA->setText(QString::number(ellipse.calcPerimeterOfSegmentA_byHeight(Ha, eps)));
}
else
{
    double alpha = ui->lineEditEllipseHa->text().toDouble();
    alpha = alpha / 180 * M_PI;
    ui->lineEditEllipseSectorA->setText(QString::number(ellipse.calcAreaOfSectorA_byAngle(alpha)));
    ui->lineEditEllipseSegmentA->setText(QString::number(ellipse.calcAreaOfSegmentA_byAngle(alpha)));
    ui->lineEditEllipseSectorPerimeterA->setText(QString::number(ellipse.calcPerimeterOfSectorA_byAngle(alpha, eps)));
    ui->lineEditEllipseSegmentPerimeterA->setText(QString::number(ellipse.calcPerimeterOfSegmentA_byAngle(alpha, eps)));
}
if(ui->comboBoxEllipseB->currentIndex() == 0)
{
    double Hb = ui->lineEditEllipseHb->text().toDouble();
    ui->lineEditEllipseSectorB->setText(QString::number(ellipse.calcAreaOfSectorB_byHeight(Hb)));
    ui->lineEditEllipseSegmentB->setText(QString::number(ellipse.calcAreaOfSegmentB_byHeight(Hb)));
    ui->lineEditEllipseSectorPerimeterB->setText(QString::number(ellipse.calcPerimeterOfSectorB_byHeight(Hb, eps)));
    ui->lineEditEllipseSegmentPerimeterB->setText(QString::number(ellipse.calcPerimeterOfSegmentB_byHeight(Hb, eps)));
}
else
{
    double beta = ui->lineEditEllipseHb->text().toDouble();
    beta = beta / 180 * M_PI;
    ui->lineEditEllipseSectorB->setText(QString::number(ellipse.calcAreaOfSectorB_byAngle(beta)));
    ui->lineEditEllipseSegmentB->setText(QString::number(ellipse.calcAreaOfSegmentB_byAngle(beta)));
    ui->lineEditEllipseSectorPerimeterB->setText(QString::number(ellipse.calcPerimeterOfSectorB_byAngle(beta, eps)));
    ui->lineEditEllipseSegmentPerimeterB->setText(QString::number(ellipse.calcPerimeterOfSegmentB_byAngle(beta, eps)));
}
}
void MainWindow::on_pushButtonEllipsoid_clicked()
{
    if(ui->lineEditEllipsoidA->text() == "" ||
       ui->lineEditEllipsoidB->text() == "" ||
       ui->lineEditEllipsoidC->text() == "")
    {
        sendErrorMessage("Не заданы значения полуосей эллипсоида!");
        return;
    }
    double a = ui->lineEditEllipsoidA->text().toDouble();
    double b = ui->lineEditEllipsoidB->text().toDouble();
    double c = ui->lineEditEllipsoidC->text().toDouble();
    if(ui->lineEditEllipsoidRo->text() == "")
    {
            sendErrorMessage("Не задана плотность материала эллипсоида!");
            return;
    }
       double ro = ui->lineEditEllipsoidRo->text().toDouble();
       if(ui->lineEditEllipsoidHa->text() == "" ||
          ui->lineEditEllipsoidHb->text() == "" ||
          ui->lineEditEllipsoidHc->text() == "")
       {
               sendErrorMessage("Не заданы высоты сегментов эллипсоида!");
               return;
       }
       double Ha = ui->lineEditEllipsoidHa->text().toDouble();
       double Hb = ui->lineEditEllipsoidHb->text().toDouble();
       double Hc = ui->lineEditEllipsoidHc->text().toDouble();

Ellipsoid ellipsoid(a, b, c, ro);
ui->lineEditEllipsoidA->setText(QString::number(ellipsoid.getSemiaxisA()));
ui->lineEditEllipsoidB->setText(QString::number(ellipsoid.getSemiaxisB()));
ui->lineEditEllipsoidC->setText(QString::number(ellipsoid.getSemiaxisC()));
ui->lineEditEllipsoidV->setText(QString::number(ellipsoid.getVolume()));
ui->lineEditEllipsoidS->setText(QString::number(ellipsoid.getSurfaceArea()));
ui->lineEditEllipsoidRo->setText(QString::number(ellipsoid.getDensity()));
ui->lineEditEllipsoidMassa->setText(QString::number(ellipsoid.getMass()));
ui->lineEditEllipsoidIx->setText(QString::number(ellipsoid.getInertiaMomentX()));
ui->lineEditEllipsoidIy->setText(QString::number(ellipsoid.getInertiaMomentY()));
ui->lineEditEllipsoidIz->setText(QString::number(ellipsoid.getInertiaMomentZ()));
ui->lineEditEllipsoidEpsilonAB->setText(QString::number(ellipsoid.getExcentricityAB()));
ui->lineEditEllipsoidEpsilonAC->setText(QString::number(ellipsoid.getExcentricityAC()));
ui->lineEditEllipsoidEpsilonBC->setText(QString::number(ellipsoid.getExcentricityBC()));
ui->lineEditEllipsoidVa->setText(QString::number(ellipsoid.calcEllipsoidSegmentVolumeA(Ha)));
ui->lineEditEllipsoidVb->setText(QString::number(ellipsoid.calcEllipsoidSegmentVolumeB(Hb)));
ui->lineEditEllipsoidVc->setText(QString::number(ellipsoid.calcEllipsoidSegmentVolumeC(Hc)));
}
void MainWindow::on_pushButtonBall_clicked()
{
    if(ui->lineEditBallR->text() == "")
    {
        sendErrorMessage("Не задан радиус шара!");
        return;
    }
    double R = ui->lineEditBallR->text().toDouble();
    if (ui->lineEditBallSegmentH->text() == "")
    {
        sendErrorMessage("Не задана высота шарового сегмента");
        return;
    }
    double segmentH = ui->lineEditBallSegmentH->text().toDouble();
    if (ui->lineEditBallLayerH->text() == "")
    {
        sendErrorMessage("Не задана высота шарового слоя");
        return;
    }
    double layerH = ui->lineEditBallLayerH->text().toDouble();
    if (ui->lineEditBallDensity->text() == "")
    {
        sendErrorMessage("Не задана плотность материала шара!");
        return;
    }
    double ro = ui->lineEditBallDensity->text().toDouble();
    Ball ball(R, ro);
    ui->lineEditBallR->setText(QString::number(R));
    ui->lineEditBallSegmentH->setText(QString::number(segmentH));
    ui->lineEditBallLayerH->setText(QString::number(layerH));
    ui->lineEditBallDensity->setText(QString::number(ro));
    ui->lineEditBallS->setText(QString::number(ball.getSurfaceArea()));
    ui->lineEditBallV->setText(QString::number(ball.getVolume()));
    ui->lineEditBallMass->setText(QString::number(ball.getMass()));
    ui->lineEditBallIx->setText(QString::number(ball.getInertiaMomentX()));
    ui->lineEditBallIy->setText(QString::number(ball.getInertiaMomentY()));
    ui->lineEditBallIz->setText(QString::number(ball.getInertiaMomentZ()));
    ui->lineEditBallSectorS->setText(QString::number(ball.calcBallSectorArea(segmentH)));
    ui->lineEditBallSectorV->setText(QString::number(ball.calcBallSectorVolume(segmentH)));
    ui->lineEditBallSectorMass->setText(QString::number(ball.calcBallSectorMass(segmentH, ro)));
    ui->lineEditBallSegmentS->setText(QString::number(ball.calcBallSegementArea(segmentH)));
    ui->lineEditBallSegmentV->setText(QString::number(ball.calcBallSegmentVolume(segmentH)));
    ui->lineEditBallSegmentMass->setText(QString::number(ball.calcBallSegmentMass(segmentH, ro)));
    if(ui->radioButtonBall_h->isChecked())
    {
        if (ui->lineEditBall_h->text() == "")
        {
            sendErrorMessage("Не задана высота сегмента, соответсвующая началу шаровго слоя!");
            return;
        }
        double h = ui->lineEditBall_h->text().toDouble();
        ui->lineEditSphericalLayerS->setText(QString::number(ball.calcSphericalLayerArea('h', h, layerH)));
        ui->lineEditSphericalLayerV->setText(QString::number(ball.calcSphericalLayerVolume('h', h, layerH)));
        ui->lineEditSphericalLayerMass->setText(QString::number(ball.calcSphericalLayerMass('h', h, layerH, ro)));
    }
    else
    {
        if (ui->lineEditBall_r->text() == "")
        {
            sendErrorMessage("Не задан верхний радиус шарового слоя!");
            return;
        }
        double r = ui->lineEditBall_r->text().toDouble();
        ui->lineEditSphericalLayerS->setText(QString::number(ball.calcSphericalLayerArea('r', r, layerH)));
        ui->lineEditSphericalLayerV->setText(QString::number(ball.calcSphericalLayerVolume('r', r, layerH)));
        ui->lineEditSphericalLayerMass->setText(QString::number(ball.calcSphericalLayerMass('r', r, layerH, ro)));
    }
}
void MainWindow::on_pushButtonTorus_clicked()
{
    if(ui->lineEditTorusR->text() == "")
    {
        sendErrorMessage("Не задан радиус тора!");
        return;
    }
    double R = ui->lineEditTorusR->text().toDouble();
    if (ui->lineEditTorus_r->text() == "")
    {
        sendErrorMessage("Не задан радиус поперечного сечения тора!");
        return;
    }
    double r = ui->lineEditTorus_r->text().toDouble();
    if (ui->lineEditTorusDensity->text() == "")
    {
        sendErrorMessage("Не задана плотность материал тора!");
        return;
    }
    double ro = ui->lineEditTorusDensity->text().toDouble();
    Torus tor(R, r, ro);
    ui->lineEditTorusR->setText(QString::number(tor.getRadius()));
    ui->lineEditTorus_r->setText(QString::number(tor.getCrossSectionRadius()));
    ui->lineEditTorusDensity->setText(QString::number(tor.getDensity()));
    ui->lineEditTorusMass->setText(QString::number(tor.getMass()));
    ui->lineEditTorusS->setText(QString::number(tor.getSurfaceArea()));
    ui->lineEditTorusV->setText(QString::number(tor.getVolume()));
    ui->lineEditTorusIx->setText(QString::number(tor.getInertiaMomentX()));
    ui->lineEditTorusIy->setText(QString::number(tor.getInertiaMomentY()));
    ui->lineEditTorusIz->setText(QString::number(tor.getInertiaMomentZ()));
}
void MainWindow::on_pushButtonCone_clicked()
{
    if(ui->lineEditConeR->text() == "")
    {
        sendErrorMessage("Не задан радиус нижнего основания конуса!");
        return;
    }
    double R = ui->lineEditConeR->text().toDouble();
    if (ui->lineEditCone_r->text() == "")
    {
        sendErrorMessage("Не задан радиус верхнего основания конуса!");
        return;
    }
    double r = ui->lineEditCone_r->text().toDouble();
    if (ui->lineEditConeH->text() == "")
    {
        sendErrorMessage("Не задана высота конуса!");
        return;
    }
    double h = ui->lineEditConeH->text().toDouble();
    if (ui->lineEditConeDensity->text() == "")
    {
        sendErrorMessage("Не задана плотность материала конуса!");
        return;
    }
    double ro = ui->lineEditConeDensity->text().toDouble();
    Cone cone(R, r, h, ro);
     ui->lineEditConeSBottomBase->setText(QString::number(cone.getBottomBaseArea()));
     ui->lineEditConeSTopBase->setText(QString::number(cone.getTopBaseArea()));
     ui->lineEditConeSConical->setText(QString::number(cone.getConicalSurfaceArea()));
     ui->lineEditConeSFull->setText(QString::number(cone.getFullSurfaceArea()));
     ui->lineEditConeV->setText(QString::number(cone.getVolume()));
     ui->lineEditConeMass->setText(QString::number(cone.getMass()));
     ui->lineEditConeIx->setText(QString::number(cone.getInertiaMomentX()));
     ui->lineEditConeIy->setText(QString::number(cone.getInertiaMomentY()));
     ui->lineEditConeIz->setText(QString::number(cone.getInertiaMomentZ()));
     ui->lineEditConeIxgc->setText(QString::number(cone.getInertiaMomentXgc()));
     ui->lineEditConeIygc->setText(QString::number(cone.getInertiaMomentYgc()));
     ui->lineEditConeIzgc->setText(QString::number(cone.getInertiaMomentZgc()));
     ui->lineEditConeGeneratorLenth->setText(QString::number(cone.getGeneratorLength()));
     ui->lineEditConeAlpha->setText(QString::number(180 * cone.getGeneratorAngel() / M_PI));
     ui->lineEditConeHgc->setText(QString::number(cone.getGravityCenterheight()));
}
void MainWindow::on_pushButtonParallelepiped_clicked()
{
    if(ui->lineEditCuboidA->text() == "" ||
       ui->lineEditCuboidB->text() == "" ||
       ui->lineEditCuboidC->text() == "")
    {
        sendErrorMessage("Заданы не все ребра параллелепипеда!");
        return;
    }
    double a = ui->lineEditCuboidA->text().toDouble();
    double b = ui->lineEditCuboidB->text().toDouble();
    double c = ui->lineEditCuboidC->text().toDouble();
    if (ui->lineEditCuboidDensity->text() == "")
    {
        sendErrorMessage("Не задана плотность материалла параллелепипеда!");
        return;
    }
    double ro = ui->lineEditCuboidDensity->text().toDouble();
    Parallelepiped par(a, b, c, ro);
    ui->lineEditCuboidV->setText(QString::number(par.getVolume()));
    ui->lineEditCuboidS->setText(QString::number(par.getSurfaceArea()));
    ui->lineEditCuboidMass->setText(QString::number(par.getMass()));
    ui->lineEditCuboidIx->setText(QString::number(par.getInertiaMomentX()));
    ui->lineEditCuboidIy->setText(QString::number(par.getInertiaMomentY()));
    ui->lineEditCuboidIz->setText(QString::number(par.getInertiaMomentZ()));
    ui->lineEditCuboidId->setText(QString::number(par.getInertiaMomentD()));
}
void MainWindow::on_pushButtonPyramid_clicked()
{
    if(ui->lineEditPyramidPolygonA->text() == "" ||
       ui->lineEditPyramidPolygonR->text() == "" ||
       ui->lineEditPyramidPolygon_r->text() == "" ||
       ui->lineEditPyramidPolygonA_2->text() == "" ||
       ui->lineEditPyramidPolygonR_2->text() == "" ||
       ui->lineEditPyramidPolygon_r_2->text() == "" ||
       ui->lineEditPyramidPolygonH->text() == "" ||
       ui->lineEditPyramidPolygonDensity->text() == "")
    {
        sendErrorMessage("Не заданы необходимые исходные данные!");
        return;
    }

    if(ui->checkBoxPyramidPolygon->checkState())
    {
        double h = ui->lineEditPyramidPolygonH->text().toDouble();
        double ro = ui->lineEditPyramidPolygonDensity->text().toDouble();
        int N = ui->spinBoxPyramidN->value();
        if(ui->comboBoxPyramid1->currentIndex() == 0)
         {
           double a = ui->lineEditPyramidPolygonA->text().toDouble();
           switch (ui->comboBoxPyramid2->currentIndex()) {
           case 0: {double a2 = ui->lineEditPyramidPolygonA_2->text().toDouble();
                   Pyramid pyramid1('a', a, 'a', a2, N, h, ro);
                   pyramidShowData(false, pyramid1);}
                   break;
           case 1: {double R2 = ui->lineEditPyramidPolygonR_2->text().toDouble();
                   Pyramid pyramid2('a', a, 'R', R2, N, h, ro);
                   pyramidShowData(false, pyramid2);}
                   break;
           case 2: {double r2 = ui->lineEditPyramidPolygon_r_2->text().toDouble();
                   Pyramid pyramid3('a', a, 'r', r2, N, h, ro);
                   pyramidShowData(false, pyramid3);}
                   break;
           }
         } else if(ui->comboBoxPyramid1->currentIndex() == 1)
         {
           double R = ui->lineEditPyramidPolygonR->text().toDouble();
           switch (ui->comboBoxPyramid2->currentIndex()) {
           case 0: {double a2 = ui->lineEditPyramidPolygonA_2->text().toDouble();
                   Pyramid pyramid1('R', R, 'a', a2, N, h, ro);
                   pyramidShowData(false, pyramid1);}
                   break;
           case 1: {double R2 = ui->lineEditPyramidPolygonR_2->text().toDouble();
                   Pyramid pyramid2('R', R, 'R', R2, N, h, ro);
                   pyramidShowData(false, pyramid2);}
                   break;
           case 2: {double r2 = ui->lineEditPyramidPolygon_r_2->text().toDouble();
                   Pyramid pyramid3('R', R, 'r', r2, N, h, ro);
                   pyramidShowData(false, pyramid3);}
                   break;
           }
         }else if(ui->comboBoxPyramid1->currentIndex() == 2)
         {
           double r = ui->lineEditPyramidPolygon_r->text().toDouble();
           switch (ui->comboBoxPyramid2->currentIndex()) {
           case 0: {double a2 = ui->lineEditPyramidPolygonA_2->text().toDouble();
                   Pyramid pyramid1('r', r, 'a', a2, N, h, ro);
                   pyramidShowData(false, pyramid1);}
                   break;
           case 1: {double R2 = ui->lineEditPyramidPolygonR_2->text().toDouble();
                   Pyramid pyramid2('r', r, 'R', R2, N, h, ro);
                   pyramidShowData(false, pyramid2);}
                   break;
           case 2: {double r2 = ui->lineEditPyramidPolygon_r_2->text().toDouble();
                   Pyramid pyramid3('r', r, 'r', r2, N, h, ro);
                   pyramidShowData(false, pyramid3);}
                   break;
           }
        }
    }
     if(ui->checkBoxPyramidTriangular->checkState())
    {
       if(ui->lineEditPyramidXa->text() == "" ||
          ui->lineEditPyramidYa->text() == "" ||
          ui->lineEditPyramidZa->text() == "" ||
          ui->lineEditPyramidXb->text() == "" ||
          ui->lineEditPyramidYb->text() == "" ||
          ui->lineEditPyramidZb->text() == "" ||
          ui->lineEditPyramidXc->text() == "" ||
          ui->lineEditPyramidYc->text() == "" ||
          ui->lineEditPyramidXd->text() == "" ||
          ui->lineEditPyramidYd->text() == "" ||
          ui->lineEditPyramidZd->text() == "")
       {
           sendErrorMessage("Не заданы необходимые исходные данные!");
           return;
       }
       double ro3 = ui->lineEditPyramid3Density->text().toDouble();
       double vertexCoord[12];
       vertexCoord[0] = ui->lineEditPyramidXa->text().toDouble();
       vertexCoord[1] = ui->lineEditPyramidYa->text().toDouble();
       vertexCoord[2] = ui->lineEditPyramidZa->text().toDouble();
       vertexCoord[3] = ui->lineEditPyramidXb->text().toDouble();
       vertexCoord[4] = ui->lineEditPyramidYb->text().toDouble();
       vertexCoord[5] = ui->lineEditPyramidZb->text().toDouble();
       vertexCoord[6] = ui->lineEditPyramidXc->text().toDouble();
       vertexCoord[7] = ui->lineEditPyramidYc->text().toDouble();
       vertexCoord[8] = ui->lineEditPyramidZc->text().toDouble();
       vertexCoord[9] = ui->lineEditPyramidXd->text().toDouble();
       vertexCoord[10] = ui->lineEditPyramidYd->text().toDouble();
       vertexCoord[11] = ui->lineEditPyramidZd->text().toDouble();
       Pyramid pyramid(vertexCoord, ro3);
       pyramidShowData(true, pyramid);
    }
}

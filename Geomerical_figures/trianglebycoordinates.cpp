#include "trianglebycoordinates.h"
#include "ui_trianglebycoordinates.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QValidator>
#include <QMessageBox>
#include <vector>
#include <math.h>
#include "trianglebycoordinates.h"
#include "triangle.h"
using namespace std;

triangleByCoordinates::triangleByCoordinates(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::triangleByCoordinates)
{
    ui->setupUi(this);
    QLocale locale(QLocale::English);
    QValidator *doubler = new QDoubleValidator(0);
    doubler->setLocale(locale);
    ui->lineEditTriangleXa->setValidator(doubler);
    ui->lineEditTriangleYa->setValidator(doubler);
    ui->lineEditTriangleZa->setValidator(doubler);
    ui->lineEditTriangleXb->setValidator(doubler);
    ui->lineEditTriangleYb->setValidator(doubler);
    ui->lineEditTriangleZb->setValidator(doubler);
    ui->lineEditTriangleXc->setValidator(doubler);
    ui->lineEditTriangleYc->setValidator(doubler);
    ui->lineEditTriangleZc->setValidator(doubler);
}

triangleByCoordinates::~triangleByCoordinates()
{
    delete ui;
}
void triangleByCoordinates::showResults(Triangle *pTrian)
{
    ui->listWidget->clear();
    ui->listWidget->addItem("Стороны треугольника:");
    ui->listWidget->addItem("a = " + QString::number(pTrian->getSideA()));
    ui->listWidget->addItem("b = " + QString::number(pTrian->getSideB()));
    ui->listWidget->addItem("c = " + QString::number(pTrian->getSideC()));
    ui->listWidget->addItem("Углы треугольника:");
    ui->listWidget->addItem("α = " + QString::number(180 * pTrian->getAngleAlpha() / M_PI));
    ui->listWidget->addItem("β = " + QString::number(180 * pTrian->getAngleBeta() / M_PI));
    ui->listWidget->addItem("γ = " + QString::number(180 * pTrian->getAngleGamma() / M_PI));
    ui->listWidget->addItem("Площадь треугольника:");
    ui->listWidget->addItem("S = " + QString::number(pTrian->getArea()));
    ui->listWidget->addItem("Периметр треугольника:");
    ui->listWidget->addItem("P = " + QString::number(pTrian->getPerimeter()));
    ui->listWidget->addItem("Высоты треугольника:");
    ui->listWidget->addItem("Ha = " + QString::number(pTrian->getHeightA()));
    ui->listWidget->addItem("Hb = " + QString::number(pTrian->getHeightB()));
    ui->listWidget->addItem("Hc = " + QString::number(pTrian->getHeightC()));
    ui->listWidget->addItem("Биссектрисы треугольника:");
    ui->listWidget->addItem("Ba = " + QString::number(pTrian->getBisectorA()));
    ui->listWidget->addItem("Bb = " + QString::number(pTrian->getBisectorB()));
    ui->listWidget->addItem("Bc = " + QString::number(pTrian->getBisectorC()));
    ui->listWidget->addItem("Медианы треугольника:");
    ui->listWidget->addItem("Ma = " + QString::number(pTrian->getMedianaA()));
    ui->listWidget->addItem("Mb = " + QString::number(pTrian->getMedianaB()));
    ui->listWidget->addItem("Mc = " + QString::number(pTrian->getMedianaC()));
    ui->listWidget->addItem("Моменты инерции треугольника:");
    ui->listWidget->addItem("Если ось совпадает со стороной а:");
    ui->listWidget->addItem("Ia = " + QString::number(pTrian->getInertiaMomentA()));
    ui->listWidget->addItem("Если ось проходит через ц.т. и параллельна стороне а:");
    ui->listWidget->addItem("Ia = " + QString::number(pTrian->getInertiaMomentAgc()));
    ui->listWidget->addItem("Если ось совпадает со стороной b:");
    ui->listWidget->addItem("Ia = " + QString::number(pTrian->getInertiaMomentB()));
    ui->listWidget->addItem("Если ось проходит через ц.т. и параллельна стороне b:");
    ui->listWidget->addItem("Ib = " + QString::number(pTrian->getInertiaMomentBgc()));
    ui->listWidget->addItem("Если ось совпадает со стороной c:");
    ui->listWidget->addItem("Ia = " + QString::number(pTrian->getInertiaMomentC()));
    ui->listWidget->addItem("Если ось проходит через ц.т. и параллельна стороне c:");
    ui->listWidget->addItem("Ic = " + QString::number(pTrian->getInertiaMomentCgc()));
    ui->listWidget->addItem("Координаты центра тяжести треугольника:");
    ui->listWidget->addItem("Xc = " + QString::number(pTrian->getGravityCenterCoordX()));
    ui->listWidget->addItem("Yc = " + QString::number(pTrian->getGravityCenterCoordY()));
    ui->listWidget->addItem("Zc = " + QString::number(pTrian->getGravityCenterCoordZ()));
}
void triangleByCoordinates::on_pushButtonTriangleByCoordinates_clicked()
{
    double Xa = ui->lineEditTriangleXa->text().toDouble();
    double Ya = ui->lineEditTriangleYa->text().toDouble();
    double Za = ui->lineEditTriangleZa->text().toDouble();
    double Xb = ui->lineEditTriangleXb->text().toDouble();
    double Yb = ui->lineEditTriangleYb->text().toDouble();
    double Zb = ui->lineEditTriangleZb->text().toDouble();
    double Xc = ui->lineEditTriangleXc->text().toDouble();
    double Yc = ui->lineEditTriangleYc->text().toDouble();
    double Zc = ui->lineEditTriangleZc->text().toDouble();
    double t = (Xc - Xa) / (Xb - Xa);
    if(((Yc - Ya) / (Yb - Ya) == t) && ((Zc - Za) / (Zb - Za) == t))
        {
           QMessageBox mbox;
           mbox.setText("Точки с введенными координатами лежат на одной прямой!");
           mbox.exec();
           return;
        }
    double vertexCoord[9];
    vertexCoord[0] =Xa;
    vertexCoord[1] =Ya;
    vertexCoord[2] =Za;
    vertexCoord[3] =Xb;
    vertexCoord[4] =Yb;
    vertexCoord[5] =Zb;
    vertexCoord[6] =Xc;
    vertexCoord[7] =Yc;
    vertexCoord[8] =Zc;
    Triangle *pTrian = new Triangle(vertexCoord);
    showResults(pTrian);
    delete pTrian;
}

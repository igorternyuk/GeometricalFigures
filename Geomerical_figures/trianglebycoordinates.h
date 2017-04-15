#ifndef TRIANGLEBYCOORDINATES_H
#define TRIANGLEBYCOORDINATES_H

#include <QWidget>
#include <vector>
#include "triangle.h"
using namespace std;

namespace Ui {
class triangleByCoordinates;
}

class triangleByCoordinates : public QWidget
{
    Q_OBJECT

public:
    explicit triangleByCoordinates(QWidget *parent = 0);
    ~triangleByCoordinates();

private slots:

    void on_pushButtonTriangleByCoordinates_clicked();

private:
    Ui::triangleByCoordinates *ui;
    void calculateParameters(double*array);
    void showResults(Triangle *pTrian);
};

#endif // TRIANGLEBYCOORDINATES_H

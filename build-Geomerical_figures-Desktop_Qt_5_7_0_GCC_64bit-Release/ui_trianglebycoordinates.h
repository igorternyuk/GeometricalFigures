/********************************************************************************
** Form generated from reading UI file 'trianglebycoordinates.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRIANGLEBYCOORDINATES_H
#define UI_TRIANGLEBYCOORDINATES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_triangleByCoordinates
{
public:
    QPushButton *pushButtonTriangleByCoordinates;
    QListWidget *listWidget;
    QLabel *label_7;
    QGroupBox *groupBox;
    QLineEdit *lineEditTriangleZc;
    QLineEdit *lineEditTriangleYc;
    QLabel *label_6;
    QLineEdit *lineEditTriangleXc;
    QLineEdit *lineEditTriangleZb;
    QLineEdit *lineEditTriangleXb;
    QLabel *label_5;
    QLineEdit *lineEditTriangleYb;
    QLabel *label;
    QLineEdit *lineEditTriangleXa;
    QLineEdit *lineEditTriangleZa;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEditTriangleYa;
    QLabel *label_4;

    void setupUi(QWidget *triangleByCoordinates)
    {
        if (triangleByCoordinates->objectName().isEmpty())
            triangleByCoordinates->setObjectName(QStringLiteral("triangleByCoordinates"));
        triangleByCoordinates->resize(430, 472);
        pushButtonTriangleByCoordinates = new QPushButton(triangleByCoordinates);
        pushButtonTriangleByCoordinates->setObjectName(QStringLiteral("pushButtonTriangleByCoordinates"));
        pushButtonTriangleByCoordinates->setGeometry(QRect(90, 440, 241, 23));
        QFont font;
        font.setPointSize(12);
        pushButtonTriangleByCoordinates->setFont(font);
        listWidget = new QListWidget(triangleByCoordinates);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 220, 411, 211));
        listWidget->setFont(font);
        listWidget->setContextMenuPolicy(Qt::ActionsContextMenu);
        label_7 = new QLabel(triangleByCoordinates);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(130, 190, 171, 21));
        groupBox = new QGroupBox(triangleByCoordinates);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 411, 181));
        groupBox->setFont(font);
        groupBox->setAlignment(Qt::AlignCenter);
        lineEditTriangleZc = new QLineEdit(groupBox);
        lineEditTriangleZc->setObjectName(QStringLiteral("lineEditTriangleZc"));
        lineEditTriangleZc->setGeometry(QRect(290, 140, 113, 23));
        lineEditTriangleYc = new QLineEdit(groupBox);
        lineEditTriangleYc->setObjectName(QStringLiteral("lineEditTriangleYc"));
        lineEditTriangleYc->setGeometry(QRect(290, 100, 113, 23));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(340, 30, 20, 21));
        lineEditTriangleXc = new QLineEdit(groupBox);
        lineEditTriangleXc->setObjectName(QStringLiteral("lineEditTriangleXc"));
        lineEditTriangleXc->setGeometry(QRect(290, 60, 113, 23));
        lineEditTriangleZb = new QLineEdit(groupBox);
        lineEditTriangleZb->setObjectName(QStringLiteral("lineEditTriangleZb"));
        lineEditTriangleZb->setGeometry(QRect(160, 140, 113, 23));
        lineEditTriangleXb = new QLineEdit(groupBox);
        lineEditTriangleXb->setObjectName(QStringLiteral("lineEditTriangleXb"));
        lineEditTriangleXb->setGeometry(QRect(160, 60, 113, 23));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(210, 30, 20, 21));
        lineEditTriangleYb = new QLineEdit(groupBox);
        lineEditTriangleYb->setObjectName(QStringLiteral("lineEditTriangleYb"));
        lineEditTriangleYb->setGeometry(QRect(160, 100, 113, 23));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 60, 20, 21));
        lineEditTriangleXa = new QLineEdit(groupBox);
        lineEditTriangleXa->setObjectName(QStringLiteral("lineEditTriangleXa"));
        lineEditTriangleXa->setGeometry(QRect(30, 60, 113, 23));
        lineEditTriangleZa = new QLineEdit(groupBox);
        lineEditTriangleZa->setObjectName(QStringLiteral("lineEditTriangleZa"));
        lineEditTriangleZa->setGeometry(QRect(30, 140, 113, 23));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 100, 20, 21));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 140, 20, 21));
        lineEditTriangleYa = new QLineEdit(groupBox);
        lineEditTriangleYa->setObjectName(QStringLiteral("lineEditTriangleYa"));
        lineEditTriangleYa->setGeometry(QRect(30, 100, 113, 23));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(70, 30, 20, 21));

        retranslateUi(triangleByCoordinates);

        QMetaObject::connectSlotsByName(triangleByCoordinates);
    } // setupUi

    void retranslateUi(QWidget *triangleByCoordinates)
    {
        triangleByCoordinates->setWindowTitle(QApplication::translate("triangleByCoordinates", "\320\240\320\260\321\201\321\207\320\265\321\202 \320\277\320\276 \320\272\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\320\260\320\274 \320\262\320\265\321\200\321\210\320\270\320\275", 0));
        pushButtonTriangleByCoordinates->setText(QApplication::translate("triangleByCoordinates", "\320\240\320\260\321\201\321\207\320\265\321\202", 0));
        label_7->setText(QApplication::translate("triangleByCoordinates", "<html><head/><body><p><span style=\" font-size:12pt;\">\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\321\213 \321\200\320\260\321\201\321\207\320\265\321\202\320\260</span></p></body></html>", 0));
        groupBox->setTitle(QApplication::translate("triangleByCoordinates", "\320\232\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213 \320\262\320\265\321\200\321\210\320\270\320\275 \321\202\321\200\320\265\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272\320\260", 0));
        label_6->setText(QApplication::translate("triangleByCoordinates", "<html><head/><body><p><span style=\" font-size:14pt;\">C</span></p></body></html>", 0));
        label_5->setText(QApplication::translate("triangleByCoordinates", "<html><head/><body><p><span style=\" font-size:14pt;\">B</span></p></body></html>", 0));
        label->setText(QApplication::translate("triangleByCoordinates", "<html><head/><body><p><span style=\" font-size:14pt;\">X</span></p></body></html>", 0));
        label_2->setText(QApplication::translate("triangleByCoordinates", "<html><head/><body><p><span style=\" font-size:14pt;\">Y</span></p></body></html>", 0));
        label_3->setText(QApplication::translate("triangleByCoordinates", "<html><head/><body><p><span style=\" font-size:14pt;\">Z</span></p></body></html>", 0));
        label_4->setText(QApplication::translate("triangleByCoordinates", "<html><head/><body><p><span style=\" font-size:14pt;\">A</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class triangleByCoordinates: public Ui_triangleByCoordinates {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIANGLEBYCOORDINATES_H

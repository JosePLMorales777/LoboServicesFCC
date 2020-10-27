/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *Inicio;
    QGroupBox *groupBox;
    QFrame *frame_9;
    QLabel *logo;
    QFrame *frame_8;
    QLabel *label_2;
    QGroupBox *groupBox_14;
    QLineEdit *contra;
    QLineEdit *matricula;
    QPushButton *ingresar;
    QLabel *lb_iniciarSesion_2;
    QWidget *Alumno;
    QFrame *frame_11;
    QPushButton *mapa;
    QPushButton *materias;
    QPushButton *graficas;
    QPushButton *perfil;
    QPushButton *cerrar_sesion;
    QFrame *frame_12;
    QStackedWidget *stackAlumno;
    QWidget *Mapa;
    QGroupBox *groupBox_2;
    QLabel *mapaGRAFICO;
    QPushButton *mater2;
    QPushButton *mater22;
    QPushButton *mater17;
    QPushButton *mater10;
    QPushButton *mater4;
    QPushButton *mater5;
    QPushButton *mater11;
    QPushButton *mater7;
    QPushButton *mater1;
    QPushButton *mater8;
    QPushButton *mater14;
    QPushButton *mater13;
    QPushButton *mater19;
    QPushButton *mater18;
    QPushButton *mater12;
    QPushButton *mater6;
    QPushButton *mater9;
    QPushButton *mater3;
    QPushButton *mater26;
    QPushButton *mater27;
    QPushButton *mater21;
    QPushButton *mater20;
    QPushButton *mater32;
    QPushButton *mater16;
    QPushButton *mater25;
    QPushButton *mater15;
    QPushButton *mater37;
    QPushButton *mater41;
    QPushButton *mater29;
    QPushButton *mater42;
    QPushButton *mater23;
    QPushButton *mater28;
    QPushButton *mater24;
    QPushButton *mater40;
    QPushButton *mater35;
    QPushButton *mater30;
    QPushButton *mater31;
    QPushButton *mater36;
    QPushButton *mater43;
    QPushButton *mater47;
    QPushButton *pushButton_41;
    QPushButton *mater46;
    QPushButton *mater49;
    QPushButton *mater48;
    QPushButton *mater33;
    QPushButton *mater38;
    QPushButton *mater34;
    QPushButton *mater39;
    QPushButton *mater44;
    QPushButton *mater45;
    QWidget *Materias;
    QGroupBox *groupBox_18;
    QLabel *label_7;
    QTableView *tablaMaterias;
    QLabel *label_8;
    QLineEdit *materiaEdit1;
    QLabel *label_9;
    QLineEdit *materiaEdit2;
    QLineEdit *materiaEdit3;
    QLineEdit *materiaEdit4;
    QLineEdit *materiaEdit5;
    QLineEdit *materiaEdit6;
    QPushButton *inscribitButton;
    QWidget *Graficas;
    QGroupBox *groupBox_17;
    QWidget *Perfil;
    QGroupBox *groupBox_16;
    QWidget *Maestro;
    QFrame *frame;
    QPushButton *estudiantes;
    QPushButton *materias_2;
    QPushButton *graficas_2;
    QPushButton *perfil_2;
    QPushButton *cerrar_sesion_2;
    QFrame *frame_13;
    QStackedWidget *stackProfesor;
    QWidget *Estudiantes;
    QGroupBox *groupBox_3;
    QTableView *Alumnos;
    QLabel *label;
    QLineEdit *Buscar;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *Materias_2;
    QGroupBox *groupBox_4;
    QWidget *Graficas_2;
    QGroupBox *groupBox_5;
    QComboBox *semestre;
    QLabel *label_5;
    QPushButton *buscar;
    QFrame *horizontalFrame;
    QHBoxLayout *horizontalLayout;
    QWidget *Perfil_2;
    QGroupBox *groupBox_6;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QGroupBox *groupBox_7;
    QLineEdit *resetpassNE;
    QLineEdit *resetpassNC;
    QLineEdit *resetpassNCR;
    QLabel *label_13;
    QLabel *label_14;
    QGroupBox *groupBox_8;
    QLineEdit *nombreusuariobuscm;
    QPushButton *cambiarpass;
    QPushButton *searchmat;
    QTableView *tablaMatriculas;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1103, 643);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 1702, 1002));
        Inicio = new QWidget();
        Inicio->setObjectName(QString::fromUtf8("Inicio"));
        groupBox = new QGroupBox(Inicio);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 1700, 1022));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(49, 51, 64);"));
        frame_9 = new QFrame(groupBox);
        frame_9->setObjectName(QString::fromUtf8("frame_9"));
        frame_9->setGeometry(QRect(13, 13, 547, 612));
        frame_9->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	 background-color: rgb(145, 196, 107);\n"
"	font: 12pt \"Arial\";\n"
"}\n"
""));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        logo = new QLabel(frame_9);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setGeometry(QRect(39, 91, 404, 378));
        logo->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        frame_8 = new QFrame(groupBox);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setGeometry(QRect(572, 13, 511, 611));
        frame_8->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background-color: rgb(255, 255, 255);\n"
"	font: 20pt \"Arial\";\n"
"\n"
"}\n"
""));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame_8);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(130, 20, 222, 196));
        label_2->setStyleSheet(QString::fromUtf8("\n"
"border-image: url(:/Imagenes/Alumno/user.png);"));
        groupBox_14 = new QGroupBox(frame_8);
        groupBox_14->setObjectName(QString::fromUtf8("groupBox_14"));
        groupBox_14->setGeometry(QRect(39, 280, 622, 421));
        groupBox_14->setStyleSheet(QString::fromUtf8("*{\n"
"background-color: transparent;\n"
"border: none;\n"
"}\n"
"\n"
"QGroupBox{\n"
"background-color: rgba(255, 255, 255, 0.8);\n"
"border-radius: 3px;\n"
"\n"
"}\n"
"\n"
"QLineEdit{\n"
"color: rgb(49, 51, 64);\n"
"border-bottom: 2px solid rgb(49, 51, 64);\n"
"border-color: rgb(49, 51, 64);\n"
"font-size:18px;\n"
"padding-left: 6px;\n"
"}\n"
"\n"
"QPushButton{\n"
"color: white;\n"
"background-color: rgb(49, 51, 64);\n"
"font-size:18px;\n"
"border: 1px solid rgb(49, 51, 64);\n"
"border-radius: 10px; \n"
"padding: 2px 4px;\n"
"}\n"
"\n"
"\n"
""));
        contra = new QLineEdit(groupBox_14);
        contra->setObjectName(QString::fromUtf8("contra"));
        contra->setGeometry(QRect(52, 70, 326, 35));
        contra->setStyleSheet(QString::fromUtf8(""));
        contra->setEchoMode(QLineEdit::Password);
        matricula = new QLineEdit(groupBox_14);
        matricula->setObjectName(QString::fromUtf8("matricula"));
        matricula->setGeometry(QRect(52, 13, 326, 35));
        QFont font;
        matricula->setFont(font);
        matricula->setStyleSheet(QString::fromUtf8(""));
        ingresar = new QPushButton(groupBox_14);
        ingresar->setObjectName(QString::fromUtf8("ingresar"));
        ingresar->setGeometry(QRect(117, 143, 195, 35));
        ingresar->setMinimumSize(QSize(150, 27));
        ingresar->setMaximumSize(QSize(300, 54));
        ingresar->setStyleSheet(QString::fromUtf8(""));
        lb_iniciarSesion_2 = new QLabel(frame_8);
        lb_iniciarSesion_2->setObjectName(QString::fromUtf8("lb_iniciarSesion_2"));
        lb_iniciarSesion_2->setGeometry(QRect(52, 210, 378, 65));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(20);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        lb_iniciarSesion_2->setFont(font1);
        lb_iniciarSesion_2->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        lb_iniciarSesion_2->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(Inicio);
        Alumno = new QWidget();
        Alumno->setObjectName(QString::fromUtf8("Alumno"));
        frame_11 = new QFrame(Alumno);
        frame_11->setObjectName(QString::fromUtf8("frame_11"));
        frame_11->setGeometry(QRect(0, 0, 235, 651));
        frame_11->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: rgb(49, 51, 64);\n"
"}\n"
"\n"
"QPushButton{\n"
"	background-color: rgb(49, 51, 64);\n"
"	border: none;\n"
"	color: rgb(153, 153, 161);\n"
"\n"
"}"));
        frame_11->setFrameShape(QFrame::StyledPanel);
        frame_11->setFrameShadow(QFrame::Raised);
        mapa = new QPushButton(frame_11);
        mapa->setObjectName(QString::fromUtf8("mapa"));
        mapa->setGeometry(QRect(26, 52, 124, 40));
        mapa->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 15pt \"Arial\";\n"
"background-image: url(:/Imagenes/Alumno/Mapa32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}\n"
"QPushButton:hover{\n"
"	\n"
"	font: 15pt \"Arial\";\n"
"	color: #ffffff;\n"
"	background-image: url(:/Imagenes/Alumno/Mapa_Hover_32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	\n"
"	font: 15pt \"Arial\";\n"
"	color:  rgb(145, 196, 107);\n"
"	background-image: url(:/Imagenes/Alumno/Mapa_Pressed_32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}"));
        mapa->setIconSize(QSize(40, 40));
        materias = new QPushButton(frame_11);
        materias->setObjectName(QString::fromUtf8("materias"));
        materias->setGeometry(QRect(26, 143, 151, 40));
        materias->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 15pt \"Arial\";\n"
"background-image: url(:/Imagenes/Profesor/Materias32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	\n"
"	font: 15pt \"Arial\";\n"
"	color: #ffffff;\n"
"	background-image: url(:/Imagenes/Profesor/Materias_Hover_32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"	\n"
"	font: 15pt \"Arial\";\n"
"	color:  rgb(145, 196, 107);\n"
"	background-image: url(:/Imagenes/Profesor/Materias_Pressed_32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}"));
        graficas = new QPushButton(frame_11);
        graficas->setObjectName(QString::fromUtf8("graficas"));
        graficas->setGeometry(QRect(26, 247, 151, 40));
        graficas->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 15pt \"Arial\";\n"
"background-image: url(:/Imagenes/Profesor/Graficas32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}\n"
"QPushButton:hover{\n"
"	\n"
"	font: 15pt \"Arial\";\n"
"	color: #ffffff;\n"
"	background-image: url(:/Imagenes/Profesor/Graficas_Hover_32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"}\n"
"QPushButton:pressed{\n"
"	\n"
"	font: 15pt \"Arial\";\n"
"	color:  rgb(145, 196, 107);\n"
"	background-image: url(:/Imagenes/Profesor/Graficas_Pressed_32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}"));
        perfil = new QPushButton(frame_11);
        perfil->setObjectName(QString::fromUtf8("perfil"));
        perfil->setGeometry(QRect(26, 351, 111, 40));
        perfil->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 15pt \"Arial\";\n"
"background-image: url(:/Imagenes/Profesor/Perfil32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}\n"
"QPushButton:hover{\n"
"	\n"
"	font: 15pt \"Arial\";\n"
"	color: #ffffff;\n"
"	background-image: url(:/Imagenes/Profesor/Perfil_Hover_32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"}\n"
"QPushButton:pressed{\n"
"	\n"
"	font: 15pt \"Arial\";\n"
"	color:  rgb(145, 196, 107);\n"
"	background-image: url(:/Imagenes/Profesor/Perfil_Pressed_32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}"));
        cerrar_sesion = new QPushButton(frame_11);
        cerrar_sesion->setObjectName(QString::fromUtf8("cerrar_sesion"));
        cerrar_sesion->setGeometry(QRect(26, 527, 208, 40));
        cerrar_sesion->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 15pt \"Arial\";\n"
"background-image: url(:/Imagenes/Profesor/CerrarSesion32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"}\n"
"QPushButton:hover{\n"
"	\n"
"	font: 15pt \"Arial\";\n"
"	color: #ffffff;\n"
"	background-image: url(:/Imagenes/Profesor/CerrarSesion_Hover_32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"	\n"
"	font: 15pt \"Arial\";\n"
"	color:  rgb(145, 196, 107);\n"
"	background-image: url(:/Imagenes/Profesor/CerrarSesion_Pressed_32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}"));
        frame_12 = new QFrame(Alumno);
        frame_12->setObjectName(QString::fromUtf8("frame_12"));
        frame_12->setGeometry(QRect(234, 0, 871, 651));
        frame_12->setStyleSheet(QString::fromUtf8(" background-color: rgb(145, 196, 107);"));
        frame_12->setFrameShape(QFrame::StyledPanel);
        frame_12->setFrameShadow(QFrame::Raised);
        stackAlumno = new QStackedWidget(frame_12);
        stackAlumno->setObjectName(QString::fromUtf8("stackAlumno"));
        stackAlumno->setGeometry(QRect(13, 13, 846, 612));
        stackAlumno->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        Mapa = new QWidget();
        Mapa->setObjectName(QString::fromUtf8("Mapa"));
        groupBox_2 = new QGroupBox(Mapa);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 5, 858, 611));
        groupBox_2->setStyleSheet(QString::fromUtf8(""));
        mapaGRAFICO = new QLabel(groupBox_2);
        mapaGRAFICO->setObjectName(QString::fromUtf8("mapaGRAFICO"));
        mapaGRAFICO->setGeometry(QRect(0, 0, 836, 618));
        mapaGRAFICO->setStyleSheet(QString::fromUtf8("border-image: url(:/Imagenes/Alumno/Mapa_ICC.jpg);"));
        mater2 = new QPushButton(groupBox_2);
        mater2->setObjectName(QString::fromUtf8("mater2"));
        mater2->setGeometry(QRect(136, 136, 33, 33));
        mater2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater22 = new QPushButton(groupBox_2);
        mater22->setObjectName(QString::fromUtf8("mater22"));
        mater22->setGeometry(QRect(351, 487, 33, 33));
        mater22->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater17 = new QPushButton(groupBox_2);
        mater17->setObjectName(QString::fromUtf8("mater17"));
        mater17->setGeometry(QRect(279, 487, 33, 33));
        mater17->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater10 = new QPushButton(groupBox_2);
        mater10->setObjectName(QString::fromUtf8("mater10"));
        mater10->setGeometry(QRect(208, 487, 33, 33));
        mater10->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater4 = new QPushButton(groupBox_2);
        mater4->setObjectName(QString::fromUtf8("mater4"));
        mater4->setGeometry(QRect(136, 487, 33, 33));
        mater4->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater5 = new QPushButton(groupBox_2);
        mater5->setObjectName(QString::fromUtf8("mater5"));
        mater5->setGeometry(QRect(136, 546, 33, 33));
        mater5->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater11 = new QPushButton(groupBox_2);
        mater11->setObjectName(QString::fromUtf8("mater11"));
        mater11->setGeometry(QRect(208, 546, 33, 33));
        mater11->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater7 = new QPushButton(groupBox_2);
        mater7->setObjectName(QString::fromUtf8("mater7"));
        mater7->setGeometry(QRect(208, 136, 33, 33));
        mater7->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater1 = new QPushButton(groupBox_2);
        mater1->setObjectName(QString::fromUtf8("mater1"));
        mater1->setGeometry(QRect(136, 71, 33, 33));
        mater1->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater8 = new QPushButton(groupBox_2);
        mater8->setObjectName(QString::fromUtf8("mater8"));
        mater8->setGeometry(QRect(208, 189, 33, 33));
        mater8->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater14 = new QPushButton(groupBox_2);
        mater14->setObjectName(QString::fromUtf8("mater14"));
        mater14->setGeometry(QRect(279, 189, 33, 33));
        mater14->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater13 = new QPushButton(groupBox_2);
        mater13->setObjectName(QString::fromUtf8("mater13"));
        mater13->setGeometry(QRect(279, 136, 33, 33));
        mater13->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater19 = new QPushButton(groupBox_2);
        mater19->setObjectName(QString::fromUtf8("mater19"));
        mater19->setGeometry(QRect(351, 136, 33, 33));
        mater19->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater18 = new QPushButton(groupBox_2);
        mater18->setObjectName(QString::fromUtf8("mater18"));
        mater18->setGeometry(QRect(351, 71, 33, 33));
        mater18->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater12 = new QPushButton(groupBox_2);
        mater12->setObjectName(QString::fromUtf8("mater12"));
        mater12->setGeometry(QRect(279, 71, 33, 33));
        mater12->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater6 = new QPushButton(groupBox_2);
        mater6->setObjectName(QString::fromUtf8("mater6"));
        mater6->setGeometry(QRect(208, 71, 33, 33));
        mater6->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater9 = new QPushButton(groupBox_2);
        mater9->setObjectName(QString::fromUtf8("mater9"));
        mater9->setGeometry(QRect(208, 247, 33, 33));
        mater9->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater3 = new QPushButton(groupBox_2);
        mater3->setObjectName(QString::fromUtf8("mater3"));
        mater3->setGeometry(QRect(136, 247, 33, 33));
        mater3->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater26 = new QPushButton(groupBox_2);
        mater26->setObjectName(QString::fromUtf8("mater26"));
        mater26->setGeometry(QRect(448, 305, 33, 33));
        mater26->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater27 = new QPushButton(groupBox_2);
        mater27->setObjectName(QString::fromUtf8("mater27"));
        mater27->setGeometry(QRect(448, 370, 33, 33));
        mater27->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater21 = new QPushButton(groupBox_2);
        mater21->setObjectName(QString::fromUtf8("mater21"));
        mater21->setGeometry(QRect(351, 312, 33, 33));
        mater21->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater20 = new QPushButton(groupBox_2);
        mater20->setObjectName(QString::fromUtf8("mater20"));
        mater20->setGeometry(QRect(351, 247, 33, 33));
        mater20->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater32 = new QPushButton(groupBox_2);
        mater32->setObjectName(QString::fromUtf8("mater32"));
        mater32->setGeometry(QRect(520, 305, 33, 33));
        mater32->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater16 = new QPushButton(groupBox_2);
        mater16->setObjectName(QString::fromUtf8("mater16"));
        mater16->setGeometry(QRect(279, 312, 33, 33));
        mater16->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater25 = new QPushButton(groupBox_2);
        mater25->setObjectName(QString::fromUtf8("mater25"));
        mater25->setGeometry(QRect(448, 247, 33, 33));
        mater25->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater15 = new QPushButton(groupBox_2);
        mater15->setObjectName(QString::fromUtf8("mater15"));
        mater15->setGeometry(QRect(279, 247, 33, 33));
        mater15->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater37 = new QPushButton(groupBox_2);
        mater37->setObjectName(QString::fromUtf8("mater37"));
        mater37->setGeometry(QRect(591, 370, 33, 33));
        mater37->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater41 = new QPushButton(groupBox_2);
        mater41->setObjectName(QString::fromUtf8("mater41"));
        mater41->setGeometry(QRect(667, 305, 33, 33));
        mater41->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater29 = new QPushButton(groupBox_2);
        mater29->setObjectName(QString::fromUtf8("mater29"));
        mater29->setGeometry(QRect(520, 130, 33, 33));
        mater29->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater42 = new QPushButton(groupBox_2);
        mater42->setObjectName(QString::fromUtf8("mater42"));
        mater42->setGeometry(QRect(667, 370, 33, 33));
        mater42->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater23 = new QPushButton(groupBox_2);
        mater23->setObjectName(QString::fromUtf8("mater23"));
        mater23->setGeometry(QRect(448, 71, 33, 33));
        mater23->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater28 = new QPushButton(groupBox_2);
        mater28->setObjectName(QString::fromUtf8("mater28"));
        mater28->setGeometry(QRect(520, 71, 33, 33));
        mater28->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater24 = new QPushButton(groupBox_2);
        mater24->setObjectName(QString::fromUtf8("mater24"));
        mater24->setGeometry(QRect(448, 130, 33, 33));
        mater24->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater40 = new QPushButton(groupBox_2);
        mater40->setObjectName(QString::fromUtf8("mater40"));
        mater40->setGeometry(QRect(667, 247, 33, 33));
        mater40->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater35 = new QPushButton(groupBox_2);
        mater35->setObjectName(QString::fromUtf8("mater35"));
        mater35->setGeometry(QRect(591, 188, 33, 33));
        mater35->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater30 = new QPushButton(groupBox_2);
        mater30->setObjectName(QString::fromUtf8("mater30"));
        mater30->setGeometry(QRect(520, 188, 33, 33));
        mater30->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater31 = new QPushButton(groupBox_2);
        mater31->setObjectName(QString::fromUtf8("mater31"));
        mater31->setGeometry(QRect(520, 247, 33, 33));
        mater31->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater36 = new QPushButton(groupBox_2);
        mater36->setObjectName(QString::fromUtf8("mater36"));
        mater36->setGeometry(QRect(591, 305, 33, 33));
        mater36->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater43 = new QPushButton(groupBox_2);
        mater43->setObjectName(QString::fromUtf8("mater43"));
        mater43->setGeometry(QRect(667, 435, 33, 33));
        mater43->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater47 = new QPushButton(groupBox_2);
        mater47->setObjectName(QString::fromUtf8("mater47"));
        mater47->setGeometry(QRect(739, 435, 33, 33));
        mater47->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        pushButton_41 = new QPushButton(groupBox_2);
        pushButton_41->setObjectName(QString::fromUtf8("pushButton_41"));
        pushButton_41->setGeometry(QRect(812, 435, 33, 33));
        pushButton_41->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater46 = new QPushButton(groupBox_2);
        mater46->setObjectName(QString::fromUtf8("mater46"));
        mater46->setGeometry(QRect(740, 305, 33, 33));
        mater46->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater49 = new QPushButton(groupBox_2);
        mater49->setObjectName(QString::fromUtf8("mater49"));
        mater49->setGeometry(QRect(812, 305, 33, 33));
        mater49->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater48 = new QPushButton(groupBox_2);
        mater48->setObjectName(QString::fromUtf8("mater48"));
        mater48->setGeometry(QRect(812, 247, 33, 33));
        mater48->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater33 = new QPushButton(groupBox_2);
        mater33->setObjectName(QString::fromUtf8("mater33"));
        mater33->setGeometry(QRect(591, 71, 33, 33));
        mater33->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater38 = new QPushButton(groupBox_2);
        mater38->setObjectName(QString::fromUtf8("mater38"));
        mater38->setGeometry(QRect(667, 71, 33, 33));
        mater38->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater34 = new QPushButton(groupBox_2);
        mater34->setObjectName(QString::fromUtf8("mater34"));
        mater34->setGeometry(QRect(591, 130, 33, 33));
        mater34->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater39 = new QPushButton(groupBox_2);
        mater39->setObjectName(QString::fromUtf8("mater39"));
        mater39->setGeometry(QRect(667, 130, 33, 33));
        mater39->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater44 = new QPushButton(groupBox_2);
        mater44->setObjectName(QString::fromUtf8("mater44"));
        mater44->setGeometry(QRect(741, 130, 33, 33));
        mater44->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        mater45 = new QPushButton(groupBox_2);
        mater45->setObjectName(QString::fromUtf8("mater45"));
        mater45->setGeometry(QRect(741, 188, 33, 33));
        mater45->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/Imagenes/Alumno/candadoF.png);\n"
"}\n"
""));
        stackAlumno->addWidget(Mapa);
        Materias = new QWidget();
        Materias->setObjectName(QString::fromUtf8("Materias"));
        groupBox_18 = new QGroupBox(Materias);
        groupBox_18->setObjectName(QString::fromUtf8("groupBox_18"));
        groupBox_18->setGeometry(QRect(0, 0, 1311, 951));
        groupBox_18->setStyleSheet(QString::fromUtf8(""));
        label_7 = new QLabel(groupBox_18);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(0, 0, 852, 124));
        label_7->setStyleSheet(QString::fromUtf8("border-image: url(:/Imagenes/Profesor/barra.png);"));
        tablaMaterias = new QTableView(groupBox_18);
        tablaMaterias->setObjectName(QString::fromUtf8("tablaMaterias"));
        tablaMaterias->setGeometry(QRect(26, 140, 793, 254));
        tablaMaterias->setStyleSheet(QString::fromUtf8("QTableView {\n"
"\n"
"border-radius: 30px;\n"
"font: 13pt;\n"
"background: rgba(224, 222, 225, 120);\n"
"selection-background-color: rgba(143, 141, 161, 204);\n"
"selection-color: rgb(243, 241, 244);\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"font: 13pt;\n"
"height: 30px;\n"
"background: rgb(240, 238, 241);\n"
"border-radius: 20px;\n"
"}\n"
""));
        label_8 = new QLabel(groupBox_18);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(175, 45, 501, 40));
        QFont font2;
        font2.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font2.setPointSize(20);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(10);
        label_8->setFont(font2);
        label_8->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color:white;\n"
"font: 80 20pt \"MS Shell Dlg 2\";"));
        materiaEdit1 = new QLineEdit(groupBox_18);
        materiaEdit1->setObjectName(QString::fromUtf8("materiaEdit1"));
        materiaEdit1->setGeometry(QRect(30, 465, 92, 40));
        materiaEdit1->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"background: rgba(224, 222, 225, 120);\n"
"border-radius: 12px;\n"
"color: black;\n"
"font-size: 19px;\n"
"padding-left: 35px;\n"
"}\n"
""));
        label_9 = new QLabel(groupBox_18);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(162, 406, 521, 40));
        QFont font3;
        font3.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font3.setPointSize(15);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(10);
        label_9->setFont(font3);
        label_9->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color:black;\n"
"font: 80 15pt \"MS Shell Dlg 2\";"));
        materiaEdit2 = new QLineEdit(groupBox_18);
        materiaEdit2->setObjectName(QString::fromUtf8("materiaEdit2"));
        materiaEdit2->setGeometry(QRect(160, 465, 92, 40));
        materiaEdit2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"background: rgba(224, 222, 225, 120);\n"
"border-radius: 12px;\n"
"color: black;\n"
"font-size: 19px;\n"
"padding-left: 35px;\n"
"}\n"
""));
        materiaEdit3 = new QLineEdit(groupBox_18);
        materiaEdit3->setObjectName(QString::fromUtf8("materiaEdit3"));
        materiaEdit3->setGeometry(QRect(312, 465, 92, 40));
        materiaEdit3->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"background: rgba(224, 222, 225, 120);\n"
"border-radius: 12px;\n"
"color: black;\n"
"font-size: 19px;\n"
"padding-left: 35px;\n"
"}\n"
""));
        materiaEdit4 = new QLineEdit(groupBox_18);
        materiaEdit4->setObjectName(QString::fromUtf8("materiaEdit4"));
        materiaEdit4->setGeometry(QRect(448, 465, 92, 40));
        materiaEdit4->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"background: rgba(224, 222, 225, 120);\n"
"border-radius: 12px;\n"
"color: black;\n"
"font-size: 19px;\n"
"padding-left: 35px;\n"
"}\n"
""));
        materiaEdit5 = new QLineEdit(groupBox_18);
        materiaEdit5->setObjectName(QString::fromUtf8("materiaEdit5"));
        materiaEdit5->setGeometry(QRect(591, 465, 92, 40));
        materiaEdit5->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"background: rgba(224, 222, 225, 120);\n"
"border-radius: 12px;\n"
"color: black;\n"
"font-size: 19px;\n"
"padding-left: 35px;\n"
"}\n"
""));
        materiaEdit6 = new QLineEdit(groupBox_18);
        materiaEdit6->setObjectName(QString::fromUtf8("materiaEdit6"));
        materiaEdit6->setGeometry(QRect(728, 465, 92, 40));
        materiaEdit6->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"background: rgba(224, 222, 225, 120);\n"
"border-radius: 12px;\n"
"color: black;\n"
"font-size: 19px;\n"
"padding-left: 35px;\n"
"}\n"
""));
        inscribitButton = new QPushButton(groupBox_18);
        inscribitButton->setObjectName(QString::fromUtf8("inscribitButton"));
        inscribitButton->setGeometry(QRect(344, 530, 157, 40));
        QFont font4;
        font4.setBold(true);
        font4.setWeight(75);
        inscribitButton->setFont(font4);
        inscribitButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color: white;\n"
"background-color: rgb(49, 51, 64);\n"
"font-size:18px;\n"
"border: 1px solid rgb(49, 51, 64);\n"
"border-radius: 10px; \n"
"padding: 2px 4px;\n"
"}"));
        stackAlumno->addWidget(Materias);
        Graficas = new QWidget();
        Graficas->setObjectName(QString::fromUtf8("Graficas"));
        groupBox_17 = new QGroupBox(Graficas);
        groupBox_17->setObjectName(QString::fromUtf8("groupBox_17"));
        groupBox_17->setGeometry(QRect(0, 0, 851, 621));
        groupBox_17->setStyleSheet(QString::fromUtf8(""));
        stackAlumno->addWidget(Graficas);
        Perfil = new QWidget();
        Perfil->setObjectName(QString::fromUtf8("Perfil"));
        groupBox_16 = new QGroupBox(Perfil);
        groupBox_16->setObjectName(QString::fromUtf8("groupBox_16"));
        groupBox_16->setGeometry(QRect(0, 0, 851, 641));
        groupBox_16->setStyleSheet(QString::fromUtf8(""));
        stackAlumno->addWidget(Perfil);
        stackedWidget->addWidget(Alumno);
        Maestro = new QWidget();
        Maestro->setObjectName(QString::fromUtf8("Maestro"));
        frame = new QFrame(Maestro);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 222, 651));
        frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #313340;\n"
"}\n"
"\n"
"QPushButton{\n"
"	background-color: rgb(49, 51, 64);\n"
"	border: none;\n"
"	color: rgb(153, 153, 161);\n"
"\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        estudiantes = new QPushButton(frame);
        estudiantes->setObjectName(QString::fromUtf8("estudiantes"));
        estudiantes->setGeometry(QRect(20, 39, 171, 61));
        estudiantes->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 13pt \"Arial\";\n"
"background-image: url(:/Imagenes/Profesor/Estudiantes32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}\n"
"QPushButton:hover{\n"
"	\n"
"	font: 13pt \"Arial\";\n"
"	color: #ffffff;\n"
"	background-image: url(:/Imagenes/Profesor/Estudiantes_Hover_32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	\n"
"	font: 13pt \"Arial\";\n"
"	color:  rgb(145, 196, 107);\n"
"	background-image: url(:/Imagenes/Profesor/Estudiantes_Pressed_32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}"));
        materias_2 = new QPushButton(frame);
        materias_2->setObjectName(QString::fromUtf8("materias_2"));
        materias_2->setGeometry(QRect(20, 240, 171, 91));
        materias_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 13pt \"Arial\";\n"
"background-image: url(:/Imagenes/Profesor/Graficas32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}\n"
"QPushButton:hover{\n"
"	\n"
"	font: 13pt \"Arial\";\n"
"	color: #ffffff;\n"
"	background-image: url(:/Imagenes/Profesor/Graficas_Hover_32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"	\n"
"	font: 13pt \"Arial\";\n"
"	color:  rgb(145, 196, 107);\n"
"	background-image: url(:/Imagenes/Profesor/Graficas_Pressed_32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}"));
        graficas_2 = new QPushButton(frame);
        graficas_2->setObjectName(QString::fromUtf8("graficas_2"));
        graficas_2->setGeometry(QRect(20, 140, 171, 71));
        graficas_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 13pt \"Arial\";\n"
"background-image: url(:/Imagenes/Profesor/Materias32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}\n"
"QPushButton:hover{\n"
"	\n"
"	font: 13pt \"Arial\";\n"
"	color: #ffffff;\n"
"    background-image: url(:/Imagenes/Profesor/Materias_Hover_32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"}\n"
"QPushButton:pressed{\n"
"	\n"
"	font: 13pt \"Arial\";\n"
"	color:  rgb(145, 196, 107);\n"
"	background-image: url(:/Imagenes/Profesor/Materias_Pressed_32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}"));
        perfil_2 = new QPushButton(frame);
        perfil_2->setObjectName(QString::fromUtf8("perfil_2"));
        perfil_2->setGeometry(QRect(20, 360, 171, 81));
        perfil_2->setAutoFillBackground(false);
        perfil_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 13pt \"Arial\";\n"
"background-image: url(:/Imagenes/Profesor/Perfil32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}\n"
"QPushButton:hover{\n"
"	\n"
"	font: 13pt \"Arial\";\n"
"	color: #ffffff;\n"
"	background-image: url(:/Imagenes/Profesor/Perfil_Hover_32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"}\n"
"QPushButton:pressed{\n"
"	\n"
"	font: 13pt \"Arial\";\n"
"	color:  rgb(145, 196, 107);\n"
"	background-image: url(:/Imagenes/Profesor/Perfil_Pressed_32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}"));
        cerrar_sesion_2 = new QPushButton(frame);
        cerrar_sesion_2->setObjectName(QString::fromUtf8("cerrar_sesion_2"));
        cerrar_sesion_2->setGeometry(QRect(26, 572, 191, 40));
        cerrar_sesion_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 15pt \"Arial\";\n"
"background-image: url(:/Imagenes/Profesor/CerrarSesion32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"}\n"
"QPushButton:hover{\n"
"	\n"
"	font: 15pt \"Arial\";\n"
"	color: #ffffff;\n"
"	background-image: url(:/Imagenes/Profesor/CerrarSesion_Hover_32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"	\n"
"	font: 15pt \"Arial\";\n"
"	color:  rgb(145, 196, 107);\n"
"	background-image: url(:/Imagenes/Profesor/CerrarSesion_Pressed_32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}"));
        frame_13 = new QFrame(Maestro);
        frame_13->setObjectName(QString::fromUtf8("frame_13"));
        frame_13->setGeometry(QRect(221, 0, 898, 651));
        frame_13->setStyleSheet(QString::fromUtf8(" background-color: rgb(145, 196, 107);"));
        frame_13->setFrameShape(QFrame::StyledPanel);
        frame_13->setFrameShadow(QFrame::Raised);
        stackProfesor = new QStackedWidget(frame_13);
        stackProfesor->setObjectName(QString::fromUtf8("stackProfesor"));
        stackProfesor->setGeometry(QRect(13, 13, 851, 612));
        stackProfesor->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        Estudiantes = new QWidget();
        Estudiantes->setObjectName(QString::fromUtf8("Estudiantes"));
        groupBox_3 = new QGroupBox(Estudiantes);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(0, 0, 859, 612));
        QFont font5;
        font5.setPointSize(16);
        groupBox_3->setFont(font5);
        Alumnos = new QTableView(groupBox_3);
        Alumnos->setObjectName(QString::fromUtf8("Alumnos"));
        Alumnos->setGeometry(QRect(37, 162, 781, 430));
        QFont font6;
        font6.setPointSize(14);
        Alumnos->setFont(font6);
        Alumnos->setStyleSheet(QString::fromUtf8("QTableView {\n"
"\n"
"border-radius: 30px;\n"
"background: rgba(224, 222, 225, 120);\n"
"selection-background-color: rgba(143, 141, 161, 204);\n"
"selection-color: rgb(243, 241, 244);\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"font: 13pt;\n"
"height: 30px;\n"
"background: rgb(240, 238, 241);\n"
"border-radius: 20px;\n"
"}\n"
""));
        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 865, 143));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/Imagenes/Profesor/barra.png);"));
        Buscar = new QLineEdit(groupBox_3);
        Buscar->setObjectName(QString::fromUtf8("Buscar"));
        Buscar->setGeometry(QRect(409, 71, 235, 40));
        Buscar->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"background: rgba(255, 255, 255, 150);\n"
"border-radius: 15px;\n"
"color: black;\n"
"font-size: 19px;\n"
"}\n"
""));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(669, 71, 40, 40));
        label_3->setStyleSheet(QString::fromUtf8("border-image: url(:/Imagenes/Profesor/buscar.png);\n"
"background-color: transparent;"));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(123, 71, 287, 40));
        label_4->setFont(font2);
        label_4->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color:white;\n"
"font: 80 20pt \"MS Shell Dlg 2\";"));
        stackProfesor->addWidget(Estudiantes);
        Materias_2 = new QWidget();
        Materias_2->setObjectName(QString::fromUtf8("Materias_2"));
        groupBox_4 = new QGroupBox(Materias_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(0, 0, 611, 471));
        stackProfesor->addWidget(Materias_2);
        Graficas_2 = new QWidget();
        Graficas_2->setObjectName(QString::fromUtf8("Graficas_2"));
        groupBox_5 = new QGroupBox(Graficas_2);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(0, 0, 861, 621));
        semestre = new QComboBox(groupBox_5);
        semestre->addItem(QString());
        semestre->addItem(QString());
        semestre->addItem(QString());
        semestre->addItem(QString());
        semestre->addItem(QString());
        semestre->addItem(QString());
        semestre->addItem(QString());
        semestre->addItem(QString());
        semestre->addItem(QString());
        semestre->addItem(QString());
        semestre->setObjectName(QString::fromUtf8("semestre"));
        semestre->setGeometry(QRect(170, 40, 251, 41));
        semestre->setFont(font5);
        label_5 = new QLabel(groupBox_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 40, 141, 41));
        label_5->setStyleSheet(QString::fromUtf8("font: 75 22pt \"Arial\";"));
        buscar = new QPushButton(groupBox_5);
        buscar->setObjectName(QString::fromUtf8("buscar"));
        buscar->setGeometry(QRect(440, 40, 141, 41));
        QFont font7;
        font7.setPointSize(18);
        buscar->setFont(font7);
        horizontalFrame = new QFrame(groupBox_5);
        horizontalFrame->setObjectName(QString::fromUtf8("horizontalFrame"));
        horizontalFrame->setGeometry(QRect(30, 120, 791, 441));
        horizontalLayout = new QHBoxLayout(horizontalFrame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        stackProfesor->addWidget(Graficas_2);
        Perfil_2 = new QWidget();
        Perfil_2->setObjectName(QString::fromUtf8("Perfil_2"));
        groupBox_6 = new QGroupBox(Perfil_2);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(0, 0, 851, 621));
        label_10 = new QLabel(groupBox_6);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(0, 0, 852, 124));
        label_10->setStyleSheet(QString::fromUtf8("border-image: url(:/Imagenes/Profesor/barra.png);"));
        label_11 = new QLabel(groupBox_6);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(41, 140, 241, 61));
        QFont font8;
        font8.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font8.setPointSize(14);
        font8.setBold(false);
        font8.setItalic(false);
        font8.setWeight(10);
        label_11->setFont(font8);
        label_11->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color:black;\n"
"font: 80 14pt \"MS Shell Dlg 2\";"));
        label_12 = new QLabel(groupBox_6);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(90, 45, 681, 40));
        label_12->setFont(font2);
        label_12->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color:white;\n"
"font: 80 20pt \"MS Shell Dlg 2\";"));
        groupBox_7 = new QGroupBox(groupBox_6);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(30, 220, 331, 211));
        groupBox_7->setStyleSheet(QString::fromUtf8("*{\n"
"background-color: transparent;\n"
"border: none;\n"
"}\n"
"\n"
"QGroupBox{\n"
"background-color: rgba(255, 255, 255, 0.8);\n"
"border-radius: 3px;\n"
"\n"
"}\n"
"\n"
"QLineEdit{\n"
"color: rgb(49, 51, 64);\n"
"border-bottom: 2px solid rgb(49, 51, 64);\n"
"border-color: rgb(49, 51, 64);\n"
"font-size:18px;\n"
"padding-left: 6px;\n"
"}"));
        resetpassNE = new QLineEdit(groupBox_7);
        resetpassNE->setObjectName(QString::fromUtf8("resetpassNE"));
        resetpassNE->setGeometry(QRect(10, 30, 301, 31));
        resetpassNE->setStyleSheet(QString::fromUtf8(""));
        resetpassNC = new QLineEdit(groupBox_7);
        resetpassNC->setObjectName(QString::fromUtf8("resetpassNC"));
        resetpassNC->setGeometry(QRect(10, 110, 301, 31));
        resetpassNC->setStyleSheet(QString::fromUtf8(""));
        resetpassNC->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText|Qt::ImhSensitiveData);
        resetpassNC->setEchoMode(QLineEdit::Password);
        resetpassNCR = new QLineEdit(groupBox_7);
        resetpassNCR->setObjectName(QString::fromUtf8("resetpassNCR"));
        resetpassNCR->setGeometry(QRect(10, 170, 301, 31));
        resetpassNCR->setStyleSheet(QString::fromUtf8(""));
        resetpassNCR->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText|Qt::ImhSensitiveData);
        resetpassNCR->setEchoMode(QLineEdit::Password);
        label_13 = new QLabel(groupBox_6);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(403, 140, 431, 61));
        label_13->setFont(font8);
        label_13->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color:black;\n"
"font: 80 14pt \"MS Shell Dlg 2\";"));
        label_14 = new QLabel(groupBox_6);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(370, 140, 5, 451));
        label_14->setStyleSheet(QString::fromUtf8("background-color: rgb(49, 51, 64);"));
        groupBox_8 = new QGroupBox(groupBox_6);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(400, 460, 421, 61));
        groupBox_8->setStyleSheet(QString::fromUtf8("*{\n"
"background-color: transparent;\n"
"border: none;\n"
"}\n"
"\n"
"QGroupBox{\n"
"background-color: rgba(255, 255, 255, 0.8);\n"
"border-radius: 3px;\n"
"\n"
"}\n"
"\n"
"QLineEdit{\n"
"color: rgb(49, 51, 64);\n"
"border-bottom: 2px solid rgb(49, 51, 64);\n"
"border-color: rgb(49, 51, 64);\n"
"font-size:18px;\n"
"padding-left: 6px;\n"
"}"));
        nombreusuariobuscm = new QLineEdit(groupBox_8);
        nombreusuariobuscm->setObjectName(QString::fromUtf8("nombreusuariobuscm"));
        nombreusuariobuscm->setGeometry(QRect(10, 10, 401, 31));
        nombreusuariobuscm->setStyleSheet(QString::fromUtf8(""));
        cambiarpass = new QPushButton(groupBox_6);
        cambiarpass->setObjectName(QString::fromUtf8("cambiarpass"));
        cambiarpass->setGeometry(QRect(101, 480, 181, 31));
        cambiarpass->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: rgb(49, 51, 64);\n"
"font-size:18px;\n"
"border: 1px solid rgb(49, 51, 64);\n"
"border-radius: 10px; \n"
"padding: 2px 4px;\n"
""));
        searchmat = new QPushButton(groupBox_6);
        searchmat->setObjectName(QString::fromUtf8("searchmat"));
        searchmat->setGeometry(QRect(536, 525, 151, 31));
        searchmat->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: rgb(49, 51, 64);\n"
"font-size:18px;\n"
"border: 1px solid rgb(49, 51, 64);\n"
"border-radius: 10px; \n"
"padding: 2px 4px;\n"
""));
        tablaMatriculas = new QTableView(groupBox_6);
        tablaMatriculas->setObjectName(QString::fromUtf8("tablaMatriculas"));
        tablaMatriculas->setGeometry(QRect(400, 211, 431, 241));
        tablaMatriculas->setStyleSheet(QString::fromUtf8("QTableView {\n"
"\n"
"border-radius: 30px;\n"
"font: 9pt;\n"
"background: rgba(224, 222, 225, 120);\n"
"selection-background-color: rgba(143, 141, 161, 204);\n"
"selection-color: rgb(243, 241, 244);\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"font: 9pt;\n"
"height: 30px;\n"
"background: rgb(240, 238, 241);\n"
"border-radius: 20px;\n"
"}\n"
""));
        stackProfesor->addWidget(Perfil_2);
        stackedWidget->addWidget(Maestro);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        logo->setText(QString());
        label_2->setText(QString());
        groupBox_14->setTitle(QString());
        contra->setPlaceholderText(QCoreApplication::translate("MainWindow", "Contrase\303\261a", nullptr));
        matricula->setText(QString());
        matricula->setPlaceholderText(QCoreApplication::translate("MainWindow", "Matricula", nullptr));
        ingresar->setText(QCoreApplication::translate("MainWindow", "Ingresar", nullptr));
        lb_iniciarSesion_2->setText(QCoreApplication::translate("MainWindow", "Iniciar sesi\303\263n", nullptr));
        mapa->setText(QCoreApplication::translate("MainWindow", "Mapa", nullptr));
        materias->setText(QCoreApplication::translate("MainWindow", "Materias", nullptr));
        graficas->setText(QCoreApplication::translate("MainWindow", "Gr\303\241ficas", nullptr));
        perfil->setText(QCoreApplication::translate("MainWindow", "Perfil", nullptr));
        cerrar_sesion->setText(QCoreApplication::translate("MainWindow", "Cerrar Sesi\303\263n", nullptr));
        groupBox_2->setTitle(QString());
        mapaGRAFICO->setText(QString());
        mater2->setText(QString());
        mater22->setText(QString());
        mater17->setText(QString());
        mater10->setText(QString());
        mater4->setText(QString());
        mater5->setText(QString());
        mater11->setText(QString());
        mater7->setText(QString());
        mater1->setText(QString());
        mater8->setText(QString());
        mater14->setText(QString());
        mater13->setText(QString());
        mater19->setText(QString());
        mater18->setText(QString());
        mater12->setText(QString());
        mater6->setText(QString());
        mater9->setText(QString());
        mater3->setText(QString());
        mater26->setText(QString());
        mater27->setText(QString());
        mater21->setText(QString());
        mater20->setText(QString());
        mater32->setText(QString());
        mater16->setText(QString());
        mater25->setText(QString());
        mater15->setText(QString());
        mater37->setText(QString());
        mater41->setText(QString());
        mater29->setText(QString());
        mater42->setText(QString());
        mater23->setText(QString());
        mater28->setText(QString());
        mater24->setText(QString());
        mater40->setText(QString());
        mater35->setText(QString());
        mater30->setText(QString());
        mater31->setText(QString());
        mater36->setText(QString());
        mater43->setText(QString());
        mater47->setText(QString());
        pushButton_41->setText(QString());
        mater46->setText(QString());
        mater49->setText(QString());
        mater48->setText(QString());
        mater33->setText(QString());
        mater38->setText(QString());
        mater34->setText(QString());
        mater39->setText(QString());
        mater44->setText(QString());
        mater45->setText(QString());
        groupBox_18->setTitle(QString());
        label_7->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "Seleccionar materias para cursar", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Inserte el id de las materias que va inscribir:", nullptr));
        inscribitButton->setText(QCoreApplication::translate("MainWindow", "INSCRIBIR", nullptr));
        groupBox_17->setTitle(QString());
        groupBox_16->setTitle(QString());
        estudiantes->setText(QCoreApplication::translate("MainWindow", "Lista de\n"
"estudiantes", nullptr));
        materias_2->setText(QCoreApplication::translate("MainWindow", "Agrupar\n"
"estudiantes\n"
"y ver gr\303\241ficas", nullptr));
        graficas_2->setText(QCoreApplication::translate("MainWindow", "Ocupaci\303\263n\n"
"de Materias", nullptr));
        perfil_2->setText(QCoreApplication::translate("MainWindow", "Recuperar\n"
"acceso de\n"
"estudiantes", nullptr));
        cerrar_sesion_2->setText(QCoreApplication::translate("MainWindow", "Cerrar Sesi\303\263n", nullptr));
        groupBox_3->setTitle(QString());
        label->setText(QString());
        label_3->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "Buscar Alumnos:", nullptr));
        groupBox_4->setTitle(QString());
        groupBox_5->setTitle(QString());
        semestre->setItemText(0, QCoreApplication::translate("MainWindow", "1er Semestre", nullptr));
        semestre->setItemText(1, QCoreApplication::translate("MainWindow", "2do Semestre", nullptr));
        semestre->setItemText(2, QCoreApplication::translate("MainWindow", "3er Semestre", nullptr));
        semestre->setItemText(3, QCoreApplication::translate("MainWindow", "4to Semestre", nullptr));
        semestre->setItemText(4, QCoreApplication::translate("MainWindow", "5to Semestre", nullptr));
        semestre->setItemText(5, QCoreApplication::translate("MainWindow", "6to Semestre", nullptr));
        semestre->setItemText(6, QCoreApplication::translate("MainWindow", "7mo Semestre", nullptr));
        semestre->setItemText(7, QCoreApplication::translate("MainWindow", "8vo Semestre", nullptr));
        semestre->setItemText(8, QCoreApplication::translate("MainWindow", "9no Semestre", nullptr));
        semestre->setItemText(9, QCoreApplication::translate("MainWindow", "10mo Semestre", nullptr));

        label_5->setText(QCoreApplication::translate("MainWindow", "Materia:", nullptr));
        buscar->setText(QCoreApplication::translate("MainWindow", "Buscar", nullptr));
        groupBox_6->setTitle(QString());
        label_10->setText(QString());
        label_11->setText(QCoreApplication::translate("MainWindow", "Cambiar contrase\303\261a del\n"
"estudiante:", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Recuperar acceso de los estudiantes al sistema", nullptr));
        groupBox_7->setTitle(QString());
        resetpassNE->setText(QString());
        resetpassNE->setPlaceholderText(QCoreApplication::translate("MainWindow", "Matr\303\255cula del usuario", nullptr));
        resetpassNC->setText(QString());
        resetpassNC->setPlaceholderText(QCoreApplication::translate("MainWindow", "Nueva contrase\303\261a", nullptr));
        resetpassNCR->setText(QString());
        resetpassNCR->setPlaceholderText(QCoreApplication::translate("MainWindow", "Repetir nueva contrase\303\261a", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Consultar matr\303\255cula por nombre de\n"
"usuario:", nullptr));
        label_14->setText(QString());
        groupBox_8->setTitle(QString());
        nombreusuariobuscm->setText(QString());
        nombreusuariobuscm->setPlaceholderText(QCoreApplication::translate("MainWindow", "Inserte nombre del usuario", nullptr));
        cambiarpass->setText(QCoreApplication::translate("MainWindow", "Cambiar contrase\303\261a", nullptr));
        searchmat->setText(QCoreApplication::translate("MainWindow", "Buscar matricula", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

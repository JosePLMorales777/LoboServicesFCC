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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
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
    QWidget *Materias;
    QGroupBox *groupBox_18;
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
    QComboBox *comboBox;
    QLabel *label_5;
    QPushButton *buscar;
    QLabel *label_6;
    QProgressBar *progressBar;
    QProgressBar *progressBar_2;
    QProgressBar *progressBar_3;
    QWidget *Perfil_2;
    QGroupBox *groupBox_6;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1698, 990);
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
        frame_9->setGeometry(QRect(20, 20, 842, 942));
        frame_9->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	 background-color: rgb(145, 196, 107);\n"
"	font: 12pt \"Arial\";\n"
"}\n"
""));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        logo = new QLabel(frame_9);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setGeometry(QRect(60, 140, 622, 582));
        logo->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        frame_8 = new QFrame(groupBox);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setGeometry(QRect(880, 20, 802, 942));
        frame_8->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background-color: rgb(255, 255, 255);\n"
"	font: 32pt \"Arial\";\n"
"\n"
"}\n"
""));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame_8);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(200, 40, 342, 302));
        label_2->setStyleSheet(QString::fromUtf8("\n"
"border-image: url(:/Imagenes/Alumno/user.png);"));
        groupBox_14 = new QGroupBox(frame_8);
        groupBox_14->setObjectName(QString::fromUtf8("groupBox_14"));
        groupBox_14->setGeometry(QRect(60, 460, 622, 402));
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
"font-size:28px;\n"
"padding-left: 6px;\n"
"}\n"
"\n"
"QPushButton{\n"
"color: white;\n"
"background-color: rgb(49, 51, 64);\n"
"font-size:28px;\n"
"border: 1px solid rgb(49, 51, 64);\n"
"border-radius: 10px; \n"
"padding: 2px 4px;\n"
"}\n"
"\n"
"\n"
""));
        contra = new QLineEdit(groupBox_14);
        contra->setObjectName(QString::fromUtf8("contra"));
        contra->setGeometry(QRect(80, 120, 502, 54));
        contra->setStyleSheet(QString::fromUtf8(""));
        contra->setEchoMode(QLineEdit::Password);
        matricula = new QLineEdit(groupBox_14);
        matricula->setObjectName(QString::fromUtf8("matricula"));
        matricula->setGeometry(QRect(80, 20, 502, 54));
        matricula->setStyleSheet(QString::fromUtf8(""));
        ingresar = new QPushButton(groupBox_14);
        ingresar->setObjectName(QString::fromUtf8("ingresar"));
        ingresar->setGeometry(QRect(180, 220, 300, 54));
        ingresar->setMinimumSize(QSize(150, 27));
        ingresar->setMaximumSize(QSize(300, 54));
        ingresar->setStyleSheet(QString::fromUtf8(""));
        lb_iniciarSesion_2 = new QLabel(frame_8);
        lb_iniciarSesion_2->setObjectName(QString::fromUtf8("lb_iniciarSesion_2"));
        lb_iniciarSesion_2->setGeometry(QRect(80, 340, 582, 100));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(32);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        lb_iniciarSesion_2->setFont(font);
        lb_iniciarSesion_2->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        lb_iniciarSesion_2->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(Inicio);
        Alumno = new QWidget();
        Alumno->setObjectName(QString::fromUtf8("Alumno"));
        frame_11 = new QFrame(Alumno);
        frame_11->setObjectName(QString::fromUtf8("frame_11"));
        frame_11->setGeometry(QRect(0, 0, 362, 1002));
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
        mapa->setGeometry(QRect(40, 80, 191, 62));
        mapa->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 24pt \"Arial\";\n"
"background-image: url(:/Imagenes/Alumno/Mapa32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}\n"
"QPushButton:hover{\n"
"	\n"
"	font: 24pt \"Arial\";\n"
"	color: #ffffff;\n"
"	background-image: url(:/Imagenes/Alumno/Mapa_Hover_32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	\n"
"	font: 24pt \"Arial\";\n"
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
        materias->setGeometry(QRect(40, 220, 241, 62));
        materias->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 24pt \"Arial\";\n"
"background-image: url(:/Imagenes/Profesor/Materias32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	\n"
"	font: 24pt \"Arial\";\n"
"	color: #ffffff;\n"
"	background-image: url(:/Imagenes/Profesor/Materias_Hover_32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"	\n"
"	font: 24pt \"Arial\";\n"
"	color:  rgb(145, 196, 107);\n"
"	background-image: url(:/Imagenes/Profesor/Materias_Pressed_32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}"));
        graficas = new QPushButton(frame_11);
        graficas->setObjectName(QString::fromUtf8("graficas"));
        graficas->setGeometry(QRect(40, 380, 231, 62));
        graficas->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 24pt \"Arial\";\n"
"background-image: url(:/Imagenes/Profesor/Graficas32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}\n"
"QPushButton:hover{\n"
"	\n"
"	font: 24pt \"Arial\";\n"
"	color: #ffffff;\n"
"	background-image: url(:/Imagenes/Profesor/Graficas_Hover_32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"}\n"
"QPushButton:pressed{\n"
"	\n"
"	font: 24pt \"Arial\";\n"
"	color:  rgb(145, 196, 107);\n"
"	background-image: url(:/Imagenes/Profesor/Graficas_Pressed_32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}"));
        perfil = new QPushButton(frame_11);
        perfil->setObjectName(QString::fromUtf8("perfil"));
        perfil->setGeometry(QRect(40, 540, 181, 62));
        perfil->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 24pt \"Arial\";\n"
"background-image: url(:/Imagenes/Profesor/Perfil32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}\n"
"QPushButton:hover{\n"
"	\n"
"	font: 24pt \"Arial\";\n"
"	color: #ffffff;\n"
"	background-image: url(:/Imagenes/Profesor/Perfil_Hover_32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"}\n"
"QPushButton:pressed{\n"
"	\n"
"	font: 24pt \"Arial\";\n"
"	color:  rgb(145, 196, 107);\n"
"	background-image: url(:/Imagenes/Profesor/Perfil_Pressed_32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}"));
        cerrar_sesion = new QPushButton(frame_11);
        cerrar_sesion->setObjectName(QString::fromUtf8("cerrar_sesion"));
        cerrar_sesion->setGeometry(QRect(40, 880, 321, 62));
        cerrar_sesion->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 24pt \"Arial\";\n"
"background-image: url(:/Imagenes/Profesor/CerrarSesion32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"}\n"
"QPushButton:hover{\n"
"	\n"
"	font: 24pt \"Arial\";\n"
"	color: #ffffff;\n"
"	background-image: url(:/Imagenes/Profesor/CerrarSesion_Hover_32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"	\n"
"	font: 24pt \"Arial\";\n"
"	color:  rgb(145, 196, 107);\n"
"	background-image: url(:/Imagenes/Profesor/CerrarSesion_Pressed_32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}"));
        frame_12 = new QFrame(Alumno);
        frame_12->setObjectName(QString::fromUtf8("frame_12"));
        frame_12->setGeometry(QRect(360, 0, 1342, 1002));
        frame_12->setStyleSheet(QString::fromUtf8(" background-color: rgb(145, 196, 107);"));
        frame_12->setFrameShape(QFrame::StyledPanel);
        frame_12->setFrameShadow(QFrame::Raised);
        stackAlumno = new QStackedWidget(frame_12);
        stackAlumno->setObjectName(QString::fromUtf8("stackAlumno"));
        stackAlumno->setGeometry(QRect(20, 20, 1302, 942));
        stackAlumno->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        Mapa = new QWidget();
        Mapa->setObjectName(QString::fromUtf8("Mapa"));
        groupBox_2 = new QGroupBox(Mapa);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 10, 1291, 951));
        groupBox_2->setStyleSheet(QString::fromUtf8("border-image: url(:/Imagenes/Alumno/Mapa_ICC.jpg);"));
        stackAlumno->addWidget(Mapa);
        Materias = new QWidget();
        Materias->setObjectName(QString::fromUtf8("Materias"));
        groupBox_18 = new QGroupBox(Materias);
        groupBox_18->setObjectName(QString::fromUtf8("groupBox_18"));
        groupBox_18->setGeometry(QRect(0, 0, 601, 471));
        groupBox_18->setStyleSheet(QString::fromUtf8(""));
        stackAlumno->addWidget(Materias);
        Graficas = new QWidget();
        Graficas->setObjectName(QString::fromUtf8("Graficas"));
        groupBox_17 = new QGroupBox(Graficas);
        groupBox_17->setObjectName(QString::fromUtf8("groupBox_17"));
        groupBox_17->setGeometry(QRect(0, 0, 601, 471));
        groupBox_17->setStyleSheet(QString::fromUtf8(""));
        stackAlumno->addWidget(Graficas);
        Perfil = new QWidget();
        Perfil->setObjectName(QString::fromUtf8("Perfil"));
        groupBox_16 = new QGroupBox(Perfil);
        groupBox_16->setObjectName(QString::fromUtf8("groupBox_16"));
        groupBox_16->setGeometry(QRect(0, 0, 801, 641));
        groupBox_16->setStyleSheet(QString::fromUtf8(""));
        stackAlumno->addWidget(Perfil);
        stackedWidget->addWidget(Alumno);
        Maestro = new QWidget();
        Maestro->setObjectName(QString::fromUtf8("Maestro"));
        frame = new QFrame(Maestro);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 342, 1002));
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
        estudiantes->setGeometry(QRect(20, 60, 281, 62));
        estudiantes->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 24pt \"Arial\";\n"
"background-image: url(:/Imagenes/Profesor/Estudiantes32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}\n"
"QPushButton:hover{\n"
"	\n"
"	font: 24pt \"Arial\";\n"
"	color: #ffffff;\n"
"	background-image: url(:/Imagenes/Profesor/Estudiantes_Hover_32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	\n"
"	font: 24pt \"Arial\";\n"
"	color:  rgb(145, 196, 107);\n"
"	background-image: url(:/Imagenes/Profesor/Estudiantes_Pressed_32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}"));
        materias_2 = new QPushButton(frame);
        materias_2->setObjectName(QString::fromUtf8("materias_2"));
        materias_2->setGeometry(QRect(20, 200, 231, 31));
        materias_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 24pt \"Arial\";\n"
"background-image: url(:/Imagenes/Profesor/Materias32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}\n"
"QPushButton:hover{\n"
"	\n"
"	font: 24pt \"Arial\";\n"
"	color: #ffffff;\n"
"	background-image: url(:/Imagenes/Profesor/Materias_Hover_32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"	\n"
"	font: 24pt \"Arial\";\n"
"	color:  rgb(145, 196, 107);\n"
"	background-image: url(:/Imagenes/Profesor/Materias_Pressed_32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}"));
        graficas_2 = new QPushButton(frame);
        graficas_2->setObjectName(QString::fromUtf8("graficas_2"));
        graficas_2->setGeometry(QRect(20, 340, 221, 31));
        graficas_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 24pt \"Arial\";\n"
"background-image: url(:/Imagenes/Profesor/Graficas32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}\n"
"QPushButton:hover{\n"
"	\n"
"	font: 24pt \"Arial\";\n"
"	color: #ffffff;\n"
"	background-image: url(:/Imagenes/Profesor/Graficas_Hover_32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"}\n"
"QPushButton:pressed{\n"
"	\n"
"	font: 24pt \"Arial\";\n"
"	color:  rgb(145, 196, 107);\n"
"	background-image: url(:/Imagenes/Profesor/Graficas_Pressed_32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}"));
        perfil_2 = new QPushButton(frame);
        perfil_2->setObjectName(QString::fromUtf8("perfil_2"));
        perfil_2->setGeometry(QRect(20, 460, 171, 31));
        perfil_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 24pt \"Arial\";\n"
"background-image: url(:/Imagenes/Profesor/Perfil32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}\n"
"QPushButton:hover{\n"
"	\n"
"	font: 24pt \"Arial\";\n"
"	color: #ffffff;\n"
"	background-image: url(:/Imagenes/Profesor/Perfil_Hover_32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"}\n"
"QPushButton:pressed{\n"
"	\n"
"	font: 24pt \"Arial\";\n"
"	color:  rgb(145, 196, 107);\n"
"	background-image: url(:/Imagenes/Profesor/Perfil_Pressed_32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}"));
        cerrar_sesion_2 = new QPushButton(frame);
        cerrar_sesion_2->setObjectName(QString::fromUtf8("cerrar_sesion_2"));
        cerrar_sesion_2->setGeometry(QRect(40, 880, 301, 62));
        cerrar_sesion_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 24pt \"Arial\";\n"
"background-image: url(:/Imagenes/Profesor/CerrarSesion32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"}\n"
"QPushButton:hover{\n"
"	\n"
"	font: 24pt \"Arial\";\n"
"	color: #ffffff;\n"
"	background-image: url(:/Imagenes/Profesor/CerrarSesion_Hover_32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"	\n"
"	font: 24pt \"Arial\";\n"
"	color:  rgb(145, 196, 107);\n"
"	background-image: url(:/Imagenes/Profesor/CerrarSesion_Pressed_32.png);\n"
"background-repeat: no-repeat;\n"
"padding-left: 30px;\n"
"background-position:center left;\n"
"\n"
"}"));
        frame_13 = new QFrame(Maestro);
        frame_13->setObjectName(QString::fromUtf8("frame_13"));
        frame_13->setGeometry(QRect(340, 0, 1382, 1002));
        frame_13->setStyleSheet(QString::fromUtf8(" background-color: rgb(145, 196, 107);"));
        frame_13->setFrameShape(QFrame::StyledPanel);
        frame_13->setFrameShadow(QFrame::Raised);
        stackProfesor = new QStackedWidget(frame_13);
        stackProfesor->setObjectName(QString::fromUtf8("stackProfesor"));
        stackProfesor->setGeometry(QRect(20, 20, 1322, 942));
        stackProfesor->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        Estudiantes = new QWidget();
        Estudiantes->setObjectName(QString::fromUtf8("Estudiantes"));
        groupBox_3 = new QGroupBox(Estudiantes);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(0, 0, 1322, 942));
        QFont font1;
        font1.setPointSize(16);
        groupBox_3->setFont(font1);
        Alumnos = new QTableView(groupBox_3);
        Alumnos->setObjectName(QString::fromUtf8("Alumnos"));
        Alumnos->setGeometry(QRect(42, 250, 1262, 662));
        QFont font2;
        font2.setPointSize(14);
        Alumnos->setFont(font2);
        Alumnos->setStyleSheet(QString::fromUtf8("QTableView {\n"
"\n"
"border-radius: 30px;\n"
"background: rgba(224, 222, 225, 120);\n"
"selection-background-color: rgba(143, 141, 161, 204);\n"
"selection-color: rgb(243, 241, 244);\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"font: 14pt;\n"
"height: 30px;\n"
"background: rgb(240, 238, 241);\n"
"border-radius: 20px;\n"
"}\n"
""));
        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 1331, 221));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/Imagenes/Profesor/barra.png);"));
        Buscar = new QLineEdit(groupBox_3);
        Buscar->setObjectName(QString::fromUtf8("Buscar"));
        Buscar->setGeometry(QRect(630, 110, 362, 62));
        Buscar->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"background: rgba(255, 255, 255, 150);\n"
"border-radius: 15px;\n"
"color: black;\n"
"font-size: 30px;\n"
"}\n"
""));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(1030, 100, 101, 82));
        label_3->setStyleSheet(QString::fromUtf8("border-image: url(:/Imagenes/Profesor/buscar.png);\n"
"background-color: transparent;"));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(190, 110, 422, 62));
        QFont font3;
        font3.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font3.setPointSize(32);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(10);
        label_4->setFont(font3);
        label_4->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color:white;\n"
"font: 80 32pt \"MS Shell Dlg 2\";"));
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
        groupBox_5->setGeometry(QRect(0, 0, 611, 471));
        comboBox = new QComboBox(groupBox_5);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(100, 20, 121, 22));
        label_5 = new QLabel(groupBox_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 20, 71, 16));
        label_5->setStyleSheet(QString::fromUtf8("font: 75 14pt \"Arial\";"));
        buscar = new QPushButton(groupBox_5);
        buscar->setObjectName(QString::fromUtf8("buscar"));
        buscar->setGeometry(QRect(250, 20, 75, 23));
        label_6 = new QLabel(groupBox_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 190, 281, 261));
        label_6->setStyleSheet(QString::fromUtf8("border-image: url(:/Imagenes/Profesor/grafica.png);"));
        progressBar = new QProgressBar(groupBox_5);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(90, 200, 31, 241));
        progressBar->setStyleSheet(QString::fromUtf8("QProgressBar{\n"
"	border: 2px solid black;\n"
"	border-radius: 5px;\n"
"	background-color: transparent;\n"
"\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"	background-color: rgb(145, 196, 107);\n"
"}"));
        progressBar->setValue(24);
        progressBar->setOrientation(Qt::Vertical);
        progressBar_2 = new QProgressBar(groupBox_5);
        progressBar_2->setObjectName(QString::fromUtf8("progressBar_2"));
        progressBar_2->setGeometry(QRect(140, 200, 31, 241));
        progressBar_2->setStyleSheet(QString::fromUtf8("QProgressBar{\n"
"	border: 2px solid black;\n"
"	border-radius: 5px;\n"
"	background-color: transparent;\n"
"\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"	background-color: rgb(186, 186, 186)\n"
"}"));
        progressBar_2->setValue(24);
        progressBar_2->setOrientation(Qt::Vertical);
        progressBar_3 = new QProgressBar(groupBox_5);
        progressBar_3->setObjectName(QString::fromUtf8("progressBar_3"));
        progressBar_3->setGeometry(QRect(190, 200, 31, 241));
        progressBar_3->setStyleSheet(QString::fromUtf8("QProgressBar{\n"
"	border: 2px solid black;\n"
"	border-radius: 5px;\n"
"	background-color: transparent;\n"
"\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"	background-color: rgb(145, 196, 107);\n"
"}"));
        progressBar_3->setValue(24);
        progressBar_3->setOrientation(Qt::Vertical);
        stackProfesor->addWidget(Graficas_2);
        Perfil_2 = new QWidget();
        Perfil_2->setObjectName(QString::fromUtf8("Perfil_2"));
        groupBox_6 = new QGroupBox(Perfil_2);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(0, 0, 611, 471));
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
        groupBox_18->setTitle(QString());
        groupBox_17->setTitle(QString());
        groupBox_16->setTitle(QString());
        estudiantes->setText(QCoreApplication::translate("MainWindow", "Estudiantes", nullptr));
        materias_2->setText(QCoreApplication::translate("MainWindow", "Materias", nullptr));
        graficas_2->setText(QCoreApplication::translate("MainWindow", "Gr\303\241ficas", nullptr));
        perfil_2->setText(QCoreApplication::translate("MainWindow", "Perfil", nullptr));
        cerrar_sesion_2->setText(QCoreApplication::translate("MainWindow", "Cerrar Sesi\303\263n", nullptr));
        groupBox_3->setTitle(QString());
        label->setText(QString());
        label_3->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "Buscar Alumnos:", nullptr));
        groupBox_4->setTitle(QString());
        groupBox_5->setTitle(QString());
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Matematicas", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Algebra Superior", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Metodologia de la programacion", nullptr));

        label_5->setText(QCoreApplication::translate("MainWindow", "Materia:", nullptr));
        buscar->setText(QCoreApplication::translate("MainWindow", "Buscar", nullptr));
        label_6->setText(QString());
        progressBar->setFormat(QString());
        progressBar_2->setFormat(QString());
        progressBar_3->setFormat(QString());
        groupBox_6->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

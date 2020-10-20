#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QTableWidgetItem>
#include<QtCore>
#include<QtGui>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QSqlQueryModel *query;

    void AgregarDatos();

    QStringList ObtenerDatos();

    void Limpiar();

private slots:

    void Movie();

    void BaseDatos();

    void CargarDatosAlumo();

    void BuscarAlumno();

    void on_ingresar_clicked();

    void on_mapa_clicked();

    void on_materias_clicked();

    void on_graficas_clicked();

    void on_perfil_clicked();

    void on_cerrar_sesion_clicked();

    void on_estudiantes_clicked();

    void on_materias_2_clicked();

    void on_graficas_2_clicked();

    void on_perfil_2_clicked();

    void on_cerrar_sesion_2_clicked();

private:
    QString matricula, pass;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

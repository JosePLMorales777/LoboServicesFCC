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
#include <QVBoxLayout>
#include <QScrollArea>
#include <QList>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <cstdlib>
#include <QTimer>

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
    int nFoto;
    QTimer* timer;

    void AgregarDatos();

    QStringList ObtenerDatos();

    void Limpiar();

    void AgregarDatos2();

    QStringList ObtenerDatos2();

    void Limpiar2();

private slots:

    void Movie();

    void BaseDatos();

    void CargarMateriasAlumo();

    void BuscarAlumno();

     void BuscarAlumno2();

    void CargarTablaMaterias();

    void IndicarMaterias();

    void AnadirGrupo();

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

    void on_pushButton_clicked();

    void on_inscribitButton_clicked();

    void on_mater1_clicked();

    void on_cambiarpass_clicked();

    void tablaAlumnxGrup();

    void graficas();

    void on_semestre_currentIndexChanged(int index);

    void botones(QString matMateria);

    void botonesinfo(QPushButton *botn);

    void on_mater2_clicked();

    void on_mater3_clicked();

    void on_mater4_clicked();

    void on_mater5_clicked();

    void on_mater6_clicked();

    void on_mater7_clicked();

    void on_mater8_clicked();

    void on_mater9_clicked();

    void on_mater10_clicked();

    void on_mater11_clicked();

    void on_mater12_clicked();

    void on_mater13_clicked();

    void on_mater14_clicked();

    void on_mater15_clicked();

    void on_mater43_clicked();

    void on_mater16_clicked();

    void on_mater17_clicked();

    void on_mater18_clicked();

    void on_mater19_clicked();

    void on_mater20_clicked();

    void on_mater21_clicked();

    void on_mater22_clicked();

    void on_mater23_clicked();

    void on_mater24_clicked();

    void on_mater25_clicked();

    void on_mater26_clicked();

    void on_mater27_clicked();

    void on_mater28_clicked();

    void on_mater29_clicked();

    void on_mater30_clicked();

    void on_mater31_clicked();

    void on_mater32_clicked();

    void on_mater33_clicked();

    void on_mater34_clicked();

    void on_mater35_clicked();

    void on_mater36_clicked();

    void on_mater37_clicked();

    void on_mater38_clicked();

    void on_mater39_clicked();

    void on_mater40_clicked();

    void on_mater41_clicked();

    void on_mater42_clicked();

    void on_mater44_clicked();

    void on_mater45_clicked();

    void on_mater46_clicked();

    void on_mater47_clicked();

    void on_mater48_clicked();

    void on_mater49_clicked();

    void on_mater50_clicked();

    void on_grupo_currentIndexChanged(int index);

private:
    QString matricula, pass;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

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

    void CargarMateriasAlumo();

    void BuscarAlumno();

    void CargarTablaMaterias();

    void IndicarMaterias();

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

    void on_pushButton_2_clicked();

    void limpiartabmatnom();

    void on_searchmat_clicked();

    void graficas();

    void on_semestre_currentIndexChanged(int index);

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

private:
    QString matricula, pass;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

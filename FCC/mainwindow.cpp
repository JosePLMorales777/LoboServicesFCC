#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    BaseDatos();
    Movie();
    BuscarAlumno();
    connect(ui->Buscar, SIGNAL(textChanged(QString)),this, SLOT(BuscarAlumno()));
    AgregarDatos();
    Limpiar();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Movie(){
    QMovie * movie = new QMovie();
    movie->setFileName(":/Imagenes/Alumno/logo.gif");
    movie->start();
    ui->logo->setMovie(movie);
    ui->logo->setScaledContents(true);
    ui->logo->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
}

void MainWindow::BaseDatos(){
    QSqlDatabase db;

    if(QSqlDatabase::contains("qt_sql_default_connection")) { db = QSqlDatabase::database("qt_sql_default_connection"); }
    else { db = QSqlDatabase::addDatabase("QMYSQL"); }
    db.setHostName("localhost");
    db.setPort(3306);
    db.setDatabaseName("carrerasicc");
    db.setUserName("root");
    db.setPassword("");
    if(!db.open()){ qDebug()<<"Error "; }
    else{
        query = new QSqlQueryModel();
        query->setQuery("select matricula as Matricula, Nombre from estudiante order by Nombre ASC; ");
    }
}

void MainWindow::CargarMateriasAlumo(){
    int contCM = 1;

    /*aqui se cargan las materias de primer semestre*/
    while (contCM <= 5) {
        QString idMater = QString::number(contCM);
        QString insertMAT1 = "INSERT INTO infomateria(matricula,idMateria,cursada,encurso,disponible,ninguno) VALUES ('" + matricula + "','" + idMater + "',0,1,0,0)";

        QSqlQuery insertMateria1;
        insertMateria1.exec(insertMAT1);
        insertMateria1.next();

        contCM = contCM + 1;
    }

    /*aqui las de segundo semestre*/
    while (contCM <= 73) {
        QString idMater2 = QString::number(contCM);
        QString insertMAT2 = "INSERT INTO infomateria(matricula,idMateria,cursada,encurso,disponible,ninguno) VALUES ('" + matricula + "','" + idMater2 + "',0,0,0,1)";

        QSqlQuery insertMateria2;
        insertMateria2.exec(insertMAT2);
        insertMateria2.next();

        contCM = contCM + 1;
    }
}

void MainWindow::AgregarDatos(){
    ui->Alumnos->verticalHeader()->setVisible(false);   //hide header
    ui->Alumnos->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->Alumnos->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->Alumnos->setModel(query);
}

QStringList MainWindow::ObtenerDatos(){
    QStringList rowData;
    int row = ui->Alumnos->currentIndex().row();
    QAbstractItemModel *model = ui->Alumnos->model();

    if(row != -1){
        rowData << model->index(row, 0).data().toString();
        rowData << model->index(row, 1).data().toString();
    }
    return rowData;
}

void MainWindow::BuscarAlumno(){

    QSqlQueryModel *model = new QSqlQueryModel;
    QString search, data;
    search = ui->Buscar->text();
    data = "select matricula as Matricula, Nombre as Nombre from estudiante where Nombre LIKE '%"+search+"%'";
    model->setQuery(data);
    ui->Alumnos->setModel(model);

}

void MainWindow::Limpiar(){
    QAbstractItemModel *model = ui->Alumnos->model();
    int rowCount = model->rowCount();
    for(int r = rowCount - 1; r >= 0; r--) {
        model->removeRow(r);
    }
    AgregarDatos();
}

//---------------------Interfaz inicio de sesion-------------------

void MainWindow::on_ingresar_clicked(){

    QString mat = ui->matricula->text();
    QString pa =ui->contra->text();

    qDebug()<< mat;
    qDebug()<< pa;

    if(mat.isEmpty() || pa.isEmpty()){
        QMessageBox::about(this, "Error", "Ha olvidado ingresar alguno de los datos");
        return;
    }

    /*Primero verificar si es un alumno*/

    QString consultA = "SELECT matricula,contrasena FROM estudiante WHERE matricula =" + mat;

    QSqlQuery consultAl;
    consultAl.exec(consultA);
    consultAl.next();

    QString resultCAl = consultAl.value("matricula").toString();
    QString resultCAL2 = consultAl.value("contrasena").toString();
    qDebug()<< "Matricula a: " << resultCAl;
    qDebug()<< "Contrasena a: " << resultCAL2;

    if(mat == resultCAl && pa == resultCAL2){
        ui->stackedWidget->setCurrentIndex(1);

        matricula = mat;
        qDebug()<< "Matricula autenticada: " << matricula;

        /*Cargar las materias si es necesario*/
        QString verifmaterias = "SELECT matricula FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 1";

        QSqlQuery verMaterias;
        verMaterias.exec(verifmaterias);
        verMaterias.next();

        QString verMat = verMaterias.value("matricula").toString();
        qDebug() << verMat;

        if(verMat.isEmpty()){
            qDebug() << "Está vacío";
            CargarMateriasAlumo();
        }
        /**/

        ui->matricula->clear();
        ui->contra->clear();

        return;
    }else{
        /*Ahora verificar si no es un maestro*/

        QString consultP = "SELECT matricula,contrasena FROM maestro WHERE matricula =" + mat;

        QSqlQuery consultPr;
        consultPr.exec(consultP);
        consultPr.next();

        QString resultCPR = consultPr.value("matricula").toString();
        QString resultCPR2 = consultPr.value("contrasena").toString();
        qDebug()<< "Matricula p: " << resultCPR;
        qDebug()<< "Contrasena p: " << resultCPR2;

        if(mat == resultCPR && pa == resultCPR2){
            ui->stackedWidget->setCurrentIndex(2);

            ui->matricula->clear();
            ui->contra->clear();

            return;
        }else if(resultCAl.isEmpty() || resultCAL2.isEmpty() || resultCPR.isEmpty() || resultCPR2.isEmpty()){
            QMessageBox::about(this, "Error", "Los datos ingresados son incorrectos");
            return;
        }
    }

}

//------------------------ Interfaz Alumno -------------------------
void MainWindow::on_mapa_clicked(){
    ui->stackAlumno->setCurrentIndex(0);
}
void MainWindow::on_materias_clicked(){
    ui->stackAlumno->setCurrentIndex(1);
}
void MainWindow::on_graficas_clicked(){
    ui->stackAlumno->setCurrentIndex(2);
}
void MainWindow::on_perfil_clicked(){
    ui->stackAlumno->setCurrentIndex(3);
}
void MainWindow::on_cerrar_sesion_clicked(){
   ui->stackedWidget->setCurrentIndex(0);
}


//------------------------ Interfaz Maestro -------------------------
void MainWindow::on_estudiantes_clicked(){
    ui->stackProfesor->setCurrentIndex(0);
}
void MainWindow::on_materias_2_clicked(){
    ui->stackProfesor->setCurrentIndex(1);
}
void MainWindow::on_graficas_2_clicked(){
    ui->stackProfesor->setCurrentIndex(2);
}
void MainWindow::on_perfil_2_clicked(){
    ui->stackProfesor->setCurrentIndex(3);
}
void MainWindow::on_cerrar_sesion_2_clicked(){
    ui->stackedWidget->setCurrentIndex(0);
}

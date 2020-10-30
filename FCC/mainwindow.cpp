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
    qDebug() << "Cargando materias...";

    int contCM = 1;

    /*aqui se cargan las materias de primer semestre*/
    while (contCM <= 5) {
        QString idMater = QString::number(contCM);
        QString insertMAT1 = "INSERT INTO infomateria(matricula,idMateria,cursada,encurso,disponible,ninguno) VALUES ('" + matricula + "','" + idMater + "',0,0,1,0)";

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

void MainWindow::CargarTablaMaterias(){
    QString materDips = "SELECT m.idMateria AS ID,m.Nombre FROM materia as m"
             " INNER JOIN infomateria as i ON m.idMateria = i.idMateria "
            "WHERE i.matricula = '" + matricula + "' AND i.disponible = 1";

    qDebug()<< materDips;

    QSqlQueryModel *queryMateriaDisp;

    queryMateriaDisp = new QSqlQueryModel();
    queryMateriaDisp->setQuery(materDips);

    ui->tablaMaterias->verticalHeader()->setVisible(false);   //hide header
    ui->tablaMaterias->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tablaMaterias->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tablaMaterias->setModel(queryMateriaDisp);
}

void MainWindow::IndicarMaterias(){
    /*matemáticas*/
        QString mat1 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 1";

        QSqlQuery mater1;
        mater1.exec(mat1);
        mater1.next();

        int curs1,enc1,disp1,ning1;
        curs1 = mater1.value("cursada").toInt();
        enc1 = mater1.value("encurso").toInt();
        disp1 = mater1.value("disponible").toInt();
        ning1 = mater1.value("ninguno").toInt();

        qDebug()<< curs1 << enc1 << disp1 << ning1;

        if(curs1==1){
            ui->mater1->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc1==1){
            ui->mater1->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp1==1){
            ui->mater1->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning1==1){
            ui->mater1->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /**/
        QString mat2 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 2";

        QSqlQuery mater2;
        mater2.exec(mat2);
        mater2.next();

        int curs2,enc2,disp2,ning2;
        curs2 = mater2.value("cursada").toInt();
        enc2 = mater2.value("encurso").toInt();
        disp2 = mater2.value("disponible").toInt();
        ning2 = mater2.value("ninguno").toInt();

        qDebug()<< curs2 << enc2 << disp2 << ning2;

        if(curs2==1){
            ui->mater2->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc2==1){
            ui->mater2->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp2==1){
            ui->mater2->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning2==1){
            ui->mater2->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /*metodologia de la prog*/
        QString mat3 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 3";

        QSqlQuery mater3;
        mater3.exec(mat3);
        mater3.next();

        int curs3,enc3,disp3,ning3;
        curs3 = mater3.value("cursada").toInt();
        enc3 = mater3.value("encurso").toInt();
        disp3 = mater3.value("disponible").toInt();
        ning3 = mater3.value("ninguno").toInt();

        qDebug()<< curs3 << enc3 << disp3 << ning3;

        if(curs3==1){
            ui->mater3->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc3==1){
            ui->mater3->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp3==1){
            ui->mater3->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning3==1){
            ui->mater3->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /*lengua e 1*/
        QString mat4 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 4";

        QSqlQuery mater4;
        mater4.exec(mat4);
        mater4.next();

        int curs4,enc4,disp4,ning4;
        curs4 = mater4.value("cursada").toInt();
        enc4 = mater4.value("encurso").toInt();
        disp4 = mater4.value("disponible").toInt();
        ning4 = mater4.value("ninguno").toInt();

        qDebug()<< curs4 << enc4 << disp4 << ning4;

        if(curs4==1){
            ui->mater4->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc4==1){
            ui->mater4->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp4==1){
            ui->mater4->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning4==1){
            ui->mater4->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /*form humana*/
        QString mat5 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 5";

        QSqlQuery mater5;
        mater5.exec(mat5);
        mater5.next();

        int curs5,enc5,disp5,ning5;
        curs5 = mater5.value("cursada").toInt();
        enc5 = mater5.value("encurso").toInt();
        disp5 = mater5.value("disponible").toInt();
        ning5 = mater5.value("ninguno").toInt();

        qDebug()<< curs5 << enc5 << disp5 << ning5;

        if(curs5==1){
            ui->mater5->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc5==1){
            ui->mater5->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp5==1){
            ui->mater5->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning5==1){
            ui->mater5->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /*calculo diferencial*/
        QString mat6 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 6";

        QSqlQuery mater6;
        mater6.exec(mat6);
        mater6.next();

        int curs6,enc6,disp6,ning6;
        curs6 = mater6.value("cursada").toInt();
        enc6 = mater6.value("encurso").toInt();
        disp6 = mater6.value("disponible").toInt();
        ning6 = mater6.value("ninguno").toInt();

        qDebug()<< curs6 << enc6 << disp6 << ning6;

        if(curs6==1){
            ui->mater6->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc6==1){
            ui->mater6->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp6==1){
            ui->mater6->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning6==1){
            ui->mater6->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /**/
        QString mat7 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 7";

        QSqlQuery mater7;
        mater7.exec(mat7);
        mater7.next();

        int curs7,enc7,disp7,ning7;
        curs7 = mater7.value("cursada").toInt();
        enc7 = mater7.value("encurso").toInt();
        disp7 = mater7.value("disponible").toInt();
        ning7 = mater7.value("ninguno").toInt();

        qDebug()<< curs7 << enc7 << disp7 << ning7;

        if(curs7==1){
            ui->mater7->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc7==1){
            ui->mater7->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp7==1){
            ui->mater7->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning7==1){
            ui->mater7->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /**/
        QString mat8 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 8";

        QSqlQuery mater8;
        mater8.exec(mat8);
        mater8.next();

        int curs8,enc8,disp8,ning8;
        curs8 = mater8.value("cursada").toInt();
        enc8 = mater8.value("encurso").toInt();
        disp8 = mater8.value("disponible").toInt();
        ning8 = mater8.value("ninguno").toInt();

        qDebug()<< curs8 << enc8 << disp8 << ning8;

        if(curs8==1){
            ui->mater8->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc8==1){
            ui->mater8->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp8==1){
            ui->mater8->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning8==1){
            ui->mater8->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /**/
        QString mat9 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 9";

        QSqlQuery mater9;
        mater9.exec(mat9);
        mater9.next();

        int curs9,enc9,disp9,ning9;
        curs9 = mater9.value("cursada").toInt();
        enc9 = mater9.value("encurso").toInt();
        disp9 = mater9.value("disponible").toInt();
        ning9 = mater9.value("ninguno").toInt();

        qDebug()<< curs9 << enc9 << disp9 << ning9;

        if(curs9==1){
            ui->mater9->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc9==1){
            ui->mater9->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp9==1){
            ui->mater9->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning9==1){
            ui->mater9->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /**/
        QString mat10 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 10";

        QSqlQuery mater10;
        mater10.exec(mat10);
        mater10.next();

        int curs10,enc10,disp10,ning10;
        curs10 = mater10.value("cursada").toInt();
        enc10 = mater10.value("encurso").toInt();
        disp10 = mater10.value("disponible").toInt();
        ning10 = mater10.value("ninguno").toInt();

        qDebug()<< curs10 << enc10 << disp10 << ning10;

        if(curs10==1){
            ui->mater10->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc10==1){
            ui->mater10->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp10==1){
            ui->mater10->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning10==1){
            ui->mater10->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /**/
        QString mat11 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 11";

        QSqlQuery mater11;
        mater11.exec(mat11);
        mater11.next();

        int curs11,enc11,disp11,ning11;
        curs11 = mater11.value("cursada").toInt();
        enc11 = mater11.value("encurso").toInt();
        disp11 = mater11.value("disponible").toInt();
        ning11 = mater11.value("ninguno").toInt();

        qDebug()<< curs11 << enc11 << disp11 << ning11;

        if(curs11==1){
            ui->mater11->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc11==1){
            ui->mater11->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp11==1){
            ui->mater11->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning11==1){
            ui->mater11->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /**/
        QString mat12 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 12";

        QSqlQuery mater12;
        mater12.exec(mat12);
        mater12.next();

        int curs12,enc12,disp12,ning12;
        curs12 = mater12.value("cursada").toInt();
        enc12 = mater12.value("encurso").toInt();
        disp12 = mater12.value("disponible").toInt();
        ning12 = mater12.value("ninguno").toInt();

        qDebug()<< curs12 << enc12 << disp12 << ning12;

        if(curs12==1){
            ui->mater12->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc12==1){
            ui->mater12->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp12==1){
            ui->mater12->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning12==1){
            ui->mater12->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /**/
        QString mat13 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 13";

        QSqlQuery mater13;
        mater13.exec(mat13);
        mater13.next();

        int curs13,enc13,disp13,ning13;
        curs13 = mater13.value("cursada").toInt();
        enc13 = mater13.value("encurso").toInt();
        disp13 = mater13.value("disponible").toInt();
        ning13 = mater13.value("ninguno").toInt();

        qDebug()<< curs13 << enc13 << disp13 << ning13;

        if(curs13==1){
            ui->mater13->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc13==1){
            ui->mater13->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp13==1){
            ui->mater13->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning13==1){
            ui->mater13->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /**/
        QString mat14 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 14";

        QSqlQuery mater14;
        mater14.exec(mat14);
        mater14.next();

        int curs14,enc14,disp14,ning14;
        curs14 = mater14.value("cursada").toInt();
        enc14 = mater14.value("encurso").toInt();
        disp14 = mater14.value("disponible").toInt();
        ning14 = mater14.value("ninguno").toInt();

        qDebug()<< curs14 << enc14 << disp14 << ning14;

        if(curs14==1){
            ui->mater14->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc14==1){
            ui->mater14->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp14==1){
            ui->mater14->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning14==1){
            ui->mater14->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /**/
        QString mat15 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 15";

        QSqlQuery mater15;
        mater15.exec(mat15);
        mater15.next();

        int curs15,enc15,disp15,ning15;
        curs15 = mater15.value("cursada").toInt();
        enc15 = mater15.value("encurso").toInt();
        disp15 = mater15.value("disponible").toInt();
        ning15 = mater15.value("ninguno").toInt();

        qDebug()<< curs15 << enc15 << disp15 << ning15;

        if(curs15==1){
            ui->mater15->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc15==1){
            ui->mater15->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp15==1){
            ui->mater15->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning15==1){
            ui->mater15->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /**/
        QString mat16 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 16";

        QSqlQuery mater16;
        mater16.exec(mat16);
        mater16.next();

        int curs16,enc16,disp16,ning16;
        curs16 = mater16.value("cursada").toInt();
        enc16 = mater16.value("encurso").toInt();
        disp16 = mater16.value("disponible").toInt();
        ning16 = mater16.value("ninguno").toInt();

        qDebug()<< curs16 << enc16 << disp16 << ning16;

        if(curs16==1){
            ui->mater16->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc16==1){
            ui->mater16->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp16==1){
            ui->mater16->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning16==1){
            ui->mater16->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /**/
        QString mat18 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 18";

        QSqlQuery mater18;
        mater18.exec(mat18);
        mater18.next();

        int curs18,enc18,disp18,ning18;
        curs18 = mater18.value("cursada").toInt();
        enc18 = mater18.value("encurso").toInt();
        disp18 = mater18.value("disponible").toInt();
        ning18 = mater18.value("ninguno").toInt();

        qDebug()<< curs18 << enc18 << disp18 << ning18;

        if(curs18==1){
            ui->mater18->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc18==1){
            ui->mater18->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp18==1){
            ui->mater18->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning18==1){
            ui->mater18->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /**/
        QString mat19 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 19";

        QSqlQuery mater19;
        mater19.exec(mat19);
        mater19.next();

        int curs19,enc19,disp19,ning19;
        curs19 = mater19.value("cursada").toInt();
        enc19 = mater19.value("encurso").toInt();
        disp19 = mater19.value("disponible").toInt();
        ning19 = mater19.value("ninguno").toInt();

        qDebug()<< curs19 << enc19 << disp19 << ning19;

        if(curs19==1){
            ui->mater19->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc19==1){
            ui->mater19->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp19==1){
            ui->mater19->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning19==1){
            ui->mater19->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /**/
        QString mat20 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 20";

        QSqlQuery mater20;
        mater20.exec(mat20);
        mater20.next();

        int curs20,enc20,disp20,ning20;
        curs20 = mater20.value("cursada").toInt();
        enc20 = mater20.value("encurso").toInt();
        disp20 = mater20.value("disponible").toInt();
        ning20 = mater20.value("ninguno").toInt();

        qDebug()<< curs20 << enc20 << disp20 << ning20;

        if(curs20==1){
            ui->mater20->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc20==1){
            ui->mater20->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp20==1){
            ui->mater20->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning20==1){
            ui->mater20->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /**/
        QString mat21 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 21";

        QSqlQuery mater21;
        mater21.exec(mat21);
        mater21.next();

        int curs21,enc21,disp21,ning21;
        curs21 = mater21.value("cursada").toInt();
        enc21 = mater21.value("encurso").toInt();
        disp21 = mater21.value("disponible").toInt();
        ning21 = mater21.value("ninguno").toInt();

        qDebug()<< curs21 << enc21 << disp21 << ning21;

        if(curs21==1){
            ui->mater21->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc21==1){
            ui->mater21->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp21==1){
            ui->mater21->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning21==1){
            ui->mater21->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /**/
        QString mat22 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 22";

        QSqlQuery mater22;
        mater22.exec(mat22);
        mater22.next();

        int curs22,enc22,disp22,ning22;
        curs22 = mater22.value("cursada").toInt();
        enc22 = mater22.value("encurso").toInt();
        disp22 = mater22.value("disponible").toInt();
        ning22 = mater22.value("ninguno").toInt();

        qDebug()<< curs22 << enc22 << disp22 << ning22;

        if(curs22==1){
            ui->mater22->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc22==1){
            ui->mater22->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp22==1){
            ui->mater22->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning22==1){
            ui->mater22->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /**/
        QString mat23 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 23";

        QSqlQuery mater23;
        mater23.exec(mat23);
        mater23.next();

        int curs23,enc23,disp23,ning23;
        curs23 = mater23.value("cursada").toInt();
        enc23 = mater23.value("encurso").toInt();
        disp23 = mater23.value("disponible").toInt();
        ning23 = mater23.value("ninguno").toInt();

        qDebug()<< curs23 << enc23 << disp23 << ning23;

        if(curs23==1){
            ui->mater23->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc23==1){
            ui->mater23->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp23==1){
            ui->mater23->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning23==1){
            ui->mater23->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /**/
        QString mat24 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 24";

        QSqlQuery mater24;
        mater24.exec(mat24);
        mater24.next();

        int curs24,enc24,disp24,ning24;
        curs24 = mater24.value("cursada").toInt();
        enc24 = mater24.value("encurso").toInt();
        disp24 = mater24.value("disponible").toInt();
        ning24 = mater24.value("ninguno").toInt();

        qDebug()<< curs24 << enc24 << disp24 << ning24;

        if(curs24==1){
            ui->mater24->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc24==1){
            ui->mater24->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp24==1){
            ui->mater24->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning24==1){
            ui->mater24->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /**/
        QString mat25 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 25";

        QSqlQuery mater25;
        mater25.exec(mat25);
        mater25.next();

        int curs25,enc25,disp25,ning25;
        curs25 = mater25.value("cursada").toInt();
        enc25 = mater25.value("encurso").toInt();
        disp25 = mater25.value("disponible").toInt();
        ning25 = mater25.value("ninguno").toInt();

        qDebug()<< curs25 << enc25 << disp25 << ning25;

        if(curs25==1){
            ui->mater25->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc25==1){
            ui->mater25->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp25==1){
            ui->mater25->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning25==1){
            ui->mater25->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /**/
        QString mat26 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 26";

        QSqlQuery mater26;
        mater26.exec(mat26);
        mater26.next();

        int curs26,enc26,disp26,ning26;
        curs26 = mater26.value("cursada").toInt();
        enc26 = mater26.value("encurso").toInt();
        disp26 = mater26.value("disponible").toInt();
        ning26 = mater26.value("ninguno").toInt();

        qDebug()<< curs26 << enc26 << disp26 << ning26;

        if(curs26==1){
            ui->mater26->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc26==1){
            ui->mater26->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp26==1){
            ui->mater26->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning26==1){
            ui->mater26->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /**/
        QString mat27 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 27";

        QSqlQuery mater27;
        mater27.exec(mat27);
        mater27.next();

        int curs27,enc27,disp27,ning27;
        curs27 = mater27.value("cursada").toInt();
        enc27 = mater27.value("encurso").toInt();
        disp27 = mater27.value("disponible").toInt();
        ning27 = mater27.value("ninguno").toInt();

        qDebug()<< curs27 << enc27 << disp27 << ning27;

        if(curs27==1){
            ui->mater27->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc27==1){
            ui->mater27->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp27==1){
            ui->mater27->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning27==1){
            ui->mater27->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /**/
        QString mat28 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 28";

        QSqlQuery mater28;
        mater28.exec(mat28);
        mater28.next();

        int curs28,enc28,disp28,ning28;
        curs28 = mater28.value("cursada").toInt();
        enc28 = mater28.value("encurso").toInt();
        disp28 = mater28.value("disponible").toInt();
        ning28 = mater28.value("ninguno").toInt();

        qDebug()<< curs28 << enc28 << disp28 << ning28;

        if(curs28==1){
            ui->mater28->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc28==1){
            ui->mater28->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp28==1){
            ui->mater28->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning28==1){
            ui->mater28->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /**/
        QString mat29 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 29";

        QSqlQuery mater29;
        mater29.exec(mat29);
        mater29.next();

        int curs29,enc29,disp29,ning29;
        curs29 = mater29.value("cursada").toInt();
        enc29 = mater29.value("encurso").toInt();
        disp29 = mater29.value("disponible").toInt();
        ning29 = mater29.value("ninguno").toInt();

        qDebug()<< curs29 << enc29 << disp29 << ning29;

        if(curs29==1){
            ui->mater29->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc29==1){
            ui->mater29->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp29==1){
            ui->mater29->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning29==1){
            ui->mater29->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /**/
        QString mat30 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 30";

        QSqlQuery mater30;
        mater30.exec(mat30);
        mater30.next();

        int curs30,enc30,disp30,ning30;
        curs30 = mater30.value("cursada").toInt();
        enc30 = mater30.value("encurso").toInt();
        disp30 = mater30.value("disponible").toInt();
        ning30 = mater30.value("ninguno").toInt();

        qDebug()<< curs30 << enc30 << disp30 << ning30;

        if(curs30==1){
            ui->mater30->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc30==1){
            ui->mater30->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp30==1){
            ui->mater30->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning30==1){
            ui->mater30->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /**/
        QString mat31 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 31";

        QSqlQuery mater31;
        mater31.exec(mat31);
        mater31.next();

        int curs31,enc31,disp31,ning31;
        curs31 = mater31.value("cursada").toInt();
        enc31 = mater31.value("encurso").toInt();
        disp31 = mater31.value("disponible").toInt();
        ning31 = mater31.value("ninguno").toInt();

        qDebug()<< curs31 << enc31 << disp31 << ning31;

        if(curs31==1){
            ui->mater31->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc31==1){
            ui->mater31->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp31==1){
            ui->mater31->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning31==1){
            ui->mater31->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /**/
        QString mat32 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 32";

        QSqlQuery mater32;
        mater32.exec(mat32);
        mater32.next();

        int curs32,enc32,disp32,ning32;
        curs32 = mater32.value("cursada").toInt();
        enc32 = mater32.value("encurso").toInt();
        disp32 = mater32.value("disponible").toInt();
        ning32 = mater32.value("ninguno").toInt();

        qDebug()<< curs32 << enc32 << disp32 << ning32;

        if(curs32==1){
            ui->mater32->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc32==1){
            ui->mater32->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp32==1){
            ui->mater32->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning32==1){
            ui->mater32->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /**/
        QString mat33 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 33";

        QSqlQuery mater33;
        mater33.exec(mat33);
        mater33.next();

        int curs33,enc33,disp33,ning33;
        curs33 = mater33.value("cursada").toInt();
        enc33 = mater33.value("encurso").toInt();
        disp33 = mater33.value("disponible").toInt();
        ning33 = mater33.value("ninguno").toInt();

        qDebug()<< curs33 << enc33 << disp33 << ning33;

        if(curs33==1){
            ui->mater33->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc33==1){
            ui->mater33->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp33==1){
            ui->mater33->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning33==1){
            ui->mater33->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /**/
        QString mat34 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 34";

        QSqlQuery mater34;
        mater34.exec(mat34);
        mater34.next();

        int curs34,enc34,disp34,ning34;
        curs34 = mater34.value("cursada").toInt();
        enc34 = mater34.value("encurso").toInt();
        disp34 = mater34.value("disponible").toInt();
        ning34 = mater34.value("ninguno").toInt();

        qDebug()<< curs34 << enc34 << disp34 << ning34;

        if(curs34==1){
            ui->mater34->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc34==1){
            ui->mater34->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp34==1){
            ui->mater34->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning34==1){
            ui->mater34->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /**/
        QString mat35 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 35";

        QSqlQuery mater35;
        mater35.exec(mat35);
        mater35.next();

        int curs35,enc35,disp35,ning35;
        curs35 = mater35.value("cursada").toInt();
        enc35 = mater35.value("encurso").toInt();
        disp35 = mater35.value("disponible").toInt();
        ning35 = mater35.value("ninguno").toInt();

        qDebug()<< curs35 << enc35 << disp35 << ning35;

        if(curs35==1){
            ui->mater35->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc35==1){
            ui->mater35->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp35==1){
            ui->mater35->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning35==1){
            ui->mater35->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /**/
        QString mat36 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 36";

        QSqlQuery mater36;
        mater36.exec(mat36);
        mater36.next();

        int curs36,enc36,disp36,ning36;
        curs36 = mater36.value("cursada").toInt();
        enc36 = mater36.value("encurso").toInt();
        disp36 = mater36.value("disponible").toInt();
        ning36 = mater36.value("ninguno").toInt();

        qDebug()<< curs36 << enc36 << disp36 << ning36;

        if(curs36==1){
            ui->mater36->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc36==1){
            ui->mater36->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp36==1){
            ui->mater36->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning36==1){
            ui->mater36->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /**/
        QString mat37 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 37";

        QSqlQuery mater37;
        mater37.exec(mat37);
        mater37.next();

        int curs37,enc37,disp37,ning37;
        curs37 = mater37.value("cursada").toInt();
        enc37 = mater37.value("encurso").toInt();
        disp37 = mater37.value("disponible").toInt();
        ning37 = mater37.value("ninguno").toInt();

        qDebug()<< curs37 << enc37 << disp37 << ning37;

        if(curs37==1){
            ui->mater37->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc37==1){
            ui->mater37->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp37==1){
            ui->mater37->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning37==1){
            ui->mater37->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /**/
        QString mat38 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 38";

        QSqlQuery mater38;
        mater38.exec(mat38);
        mater38.next();

        int curs38,enc38,disp38,ning38;
        curs38 = mater38.value("cursada").toInt();
        enc38 = mater38.value("encurso").toInt();
        disp38 = mater38.value("disponible").toInt();
        ning38 = mater38.value("ninguno").toInt();

        qDebug()<< curs38 << enc38 << disp38 << ning38;

        if(curs38==1){
            ui->mater38->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc38==1){
            ui->mater38->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp38==1){
            ui->mater38->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning38==1){
            ui->mater38->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /**/
        QString mat39 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 39";

        QSqlQuery mater39;
        mater39.exec(mat39);
        mater39.next();

        int curs39,enc39,disp39,ning39;
        curs39 = mater39.value("cursada").toInt();
        enc39 = mater39.value("encurso").toInt();
        disp39 = mater39.value("disponible").toInt();
        ning39 = mater39.value("ninguno").toInt();

        qDebug()<< curs39 << enc39 << disp39 << ning39;

        if(curs39==1){
            ui->mater39->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc39==1){
            ui->mater39->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp39==1){
            ui->mater39->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning39==1){
            ui->mater39->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /**/
        QString mat40 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 40";

        QSqlQuery mater40;
        mater40.exec(mat40);
        mater40.next();

        int curs40,enc40,disp40,ning40;
        curs40 = mater40.value("cursada").toInt();
        enc40 = mater40.value("encurso").toInt();
        disp40 = mater40.value("disponible").toInt();
        ning40 = mater40.value("ninguno").toInt();

        qDebug()<< curs40 << enc40 << disp40 << ning40;

        if(curs40==1){
            ui->mater40->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc40==1){
            ui->mater40->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp40==1){
            ui->mater40->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning40==1){
            ui->mater40->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /**/
        QString mat41 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 41";

        QSqlQuery mater41;
        mater41.exec(mat41);
        mater41.next();

        int curs41,enc41,disp41,ning41;
        curs41 = mater41.value("cursada").toInt();
        enc41 = mater41.value("encurso").toInt();
        disp41 = mater41.value("disponible").toInt();
        ning41 = mater41.value("ninguno").toInt();

        qDebug()<< curs41 << enc41 << disp41 << ning41;

        if(curs41==1){
            ui->mater41->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc41==1){
            ui->mater41->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp41==1){
            ui->mater41->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning41==1){
            ui->mater41->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /**/
        QString mat42 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 42";

        QSqlQuery mater42;
        mater42.exec(mat42);
        mater42.next();

        int curs42,enc42,disp42,ning42;
        curs42 = mater42.value("cursada").toInt();
        enc42 = mater42.value("encurso").toInt();
        disp42 = mater42.value("disponible").toInt();
        ning42 = mater42.value("ninguno").toInt();

        qDebug()<< curs42 << enc42 << disp42 << ning42;

        if(curs42==1){
            ui->mater42->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc42==1){
            ui->mater42->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp42==1){
            ui->mater42->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning42==1){
            ui->mater42->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /*OPTATIVAS 1--------------------------------------------*/
    /**/
        ui->mater43->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");

        int contOP1 = 43, indic2OP1 = 0;

        while (contOP1 <= 54 && indic2OP1 == 0) {
            QString OPTUNO1 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = '" + QString::number(contOP1) + "'";

            QSqlQuery OPUNO1;
            OPUNO1.exec(OPTUNO1);
            OPUNO1.next();

            int cursOP1,encOP1,dispOP1,ningOP1;
            cursOP1 = OPUNO1.value("cursada").toInt();
            encOP1 = OPUNO1.value("encurso").toInt();
            dispOP1 = OPUNO1.value("disponible").toInt();
            ningOP1 = OPUNO1.value("ninguno").toInt();

            qDebug()<< contOP1 << cursOP1 << encOP1 << dispOP1 << ningOP1;

            if(cursOP1==1){
                ui->mater43->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
                indic2OP1 = 1;
            }
            if(encOP1==1){
                ui->mater43->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
                indic2OP1 = 1;
            }
            if(dispOP1==1){
                ui->mater43->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
                indic2OP1 = 1;
            }

            contOP1 = contOP1 + 1;
        }

    /**/
    /*-------------------------------------------------------*/

    /**/
        QString mat44 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 55";

        QSqlQuery mater44;
        mater44.exec(mat44);
        mater44.next();

        int curs44,enc44,disp44,ning44;
        curs44 = mater44.value("cursada").toInt();
        enc44 = mater44.value("encurso").toInt();
        disp44 = mater44.value("disponible").toInt();
        ning44 = mater44.value("ninguno").toInt();

        qDebug()<< curs44 << enc44 << disp44 << ning44;

        if(curs44==1){
            ui->mater44->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc44==1){
            ui->mater44->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp44==1){
            ui->mater44->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning44==1){
            ui->mater44->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /**/
        QString mat45 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 56";

        QSqlQuery mater45;
        mater45.exec(mat45);
        mater45.next();

        int curs45,enc45,disp45,ning45;
        curs45 = mater45.value("cursada").toInt();
        enc45 = mater45.value("encurso").toInt();
        disp45 = mater45.value("disponible").toInt();
        ning45 = mater45.value("ninguno").toInt();

        qDebug()<< curs45 << enc45 << disp45 << ning45;

        if(curs45==1){
            ui->mater45->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc45==1){
            ui->mater45->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp45==1){
            ui->mater45->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning45==1){
            ui->mater45->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /**/
        QString mat46 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 57";

        QSqlQuery mater46;
        mater46.exec(mat46);
        mater46.next();

        int curs46,enc46,disp46,ning46;
        curs46 = mater46.value("cursada").toInt();
        enc46 = mater46.value("encurso").toInt();
        disp46 = mater46.value("disponible").toInt();
        ning46 = mater46.value("ninguno").toInt();

        qDebug()<< curs46 << enc46 << disp46 << ning46;

        if(curs46==1){
            ui->mater46->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc46==1){
            ui->mater46->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp46==1){
            ui->mater46->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning46==1){
            ui->mater46->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /*OPTATIVAS 2------------------------------------------------------------------------*/
        /**/
            ui->mater47->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");

            int contOP2 = 58, indic2OP2 = 0;

            while (contOP2 <= 68 && indic2OP2 == 0) {
                QString OPTUNO2 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = '" + QString::number(contOP2) + "'";

                QSqlQuery OPUNO2;
                OPUNO2.exec(OPTUNO2);
                OPUNO2.next();

                int cursOP2,encOP2,dispOP2,ningOP2;
                cursOP2 = OPUNO2.value("cursada").toInt();
                encOP2 = OPUNO2.value("encurso").toInt();
                dispOP2 = OPUNO2.value("disponible").toInt();
                ningOP2 = OPUNO2.value("ninguno").toInt();

                qDebug()<< contOP2 << cursOP2 << encOP2 << dispOP2 << ningOP2;

                if(cursOP2==1){
                    ui->mater47->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
                    indic2OP2 = 1;
                }
                if(encOP2==1){
                    ui->mater47->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
                    indic2OP2 = 1;
                }
                if(dispOP2==1){
                    ui->mater47->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
                    indic2OP2 = 1;
                }

                contOP2 = contOP2 + 1;
            }

        /**/
    /*-----------------------------------------------------------------------------------*/

    /*OPTATIVAS DESIT------------------------------------------------------------------------*/
            /**/
                ui->mater48->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");

                int contOP3 = 69, indic2OP3 = 0;

                while (contOP3 <= 71 && indic2OP3 == 0) {
                    QString OPTUNO3 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = '" + QString::number(contOP3) + "'";
                    qDebug()<< OPTUNO3;

                    QSqlQuery OPUNO3;
                    OPUNO3.exec(OPTUNO3);
                    OPUNO3.next();

                    int cursOP3,encOP3,dispOP3,ningOP3;
                    cursOP3 = OPUNO3.value("cursada").toInt();
                    encOP3 = OPUNO3.value("encurso").toInt();
                    dispOP3 = OPUNO3.value("disponible").toInt();
                    ningOP3 = OPUNO3.value("ninguno").toInt();

                    qDebug()<< contOP3 << cursOP3 << encOP3 << dispOP3 << ningOP3;

                    if(cursOP3==1){
                        ui->mater48->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
                        indic2OP3 = 1;
                    }
                    if(encOP3==1){
                        ui->mater48->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
                        indic2OP3 = 1;
                    }
                    if(dispOP3==1){
                        ui->mater48->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
                        indic2OP3 = 1;
                    }

                    contOP3 = contOP3 + 1;
                }

            /**/
    /*---------------------------------------------------------------------------------------*/

    /**/
        QString mat49 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 72";

        QSqlQuery mater49;
        mater49.exec(mat49);
        mater49.next();

        int curs49,enc49,disp49,ning49;
        curs49 = mater49.value("cursada").toInt();
        enc49 = mater49.value("encurso").toInt();
        disp49 = mater49.value("disponible").toInt();
        ning49 = mater49.value("ninguno").toInt();

        qDebug()<< curs49 << enc49 << disp49 << ning49;

        if(curs49==1){
            ui->mater49->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc49==1){
            ui->mater49->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp49==1){
            ui->mater49->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning49==1){
            ui->mater49->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

    /**/
        QString mat50 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 73";

        QSqlQuery mater50;
        mater50.exec(mat50);
        mater50.next();

        int curs50,enc50,disp50,ning50;
        curs50 = mater50.value("cursada").toInt();
        enc50 = mater50.value("encurso").toInt();
        disp50 = mater50.value("disponible").toInt();
        ning50 = mater50.value("ninguno").toInt();

        qDebug()<< curs50 << enc50 << disp50 << ning50;

        if(curs50==1){
            ui->pushButton_41->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/palomitaF.png);");
        }
        if(enc50==1){
            ui->pushButton_41->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/libretaF.png);");
        }
        if(disp50==1){
            ui->pushButton_41->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/disponibleF.png);");
        }
        if(ning50==1){
            ui->pushButton_41->setStyleSheet("background-color: transparent; border-image: url(:/Imagenes/Alumno/candadoF.png);");
        }
    /**/

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
        ui->stackAlumno->setCurrentIndex(0);

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

        IndicarMaterias();

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
            ui->stackProfesor->setCurrentIndex(0);

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
    IndicarMaterias();
    ui->stackAlumno->setCurrentIndex(0);
}
void MainWindow::on_materias_clicked(){
    CargarTablaMaterias();
    ui->stackAlumno->setCurrentIndex(1);
}
void MainWindow::on_pushButton_clicked()
{
}
void MainWindow::on_inscribitButton_clicked()
{
    QString mat[6];
    mat[0] = ui->materiaEdit1->text();
    mat[1] = ui->materiaEdit2->text();
    mat[2] = ui->materiaEdit3->text();
    mat[3] = ui->materiaEdit4->text();
    mat[4] = ui->materiaEdit5->text();
    mat[5] = ui->materiaEdit6->text();
    qDebug() << mat[0] << mat[1] << mat[2] <<mat[3] << mat[4] << mat[5];

    /*Validación de datos*/

    int iii = 0, icont1 = 0;

    while (icont1 <= 5) {
        if( (!(mat[icont1].isEmpty()))){
            iii = iii + 1;
        }

        icont1 = icont1 + 1;
    }

    qDebug()<< iii;

    if(iii<3){
        QMessageBox::about(this, "Error", "Necesita introducir al menos 3 materias y solo materias válidas");
        return;
    }

    /*Inscripción de materias*/

    icont1 = 0;

    while (icont1 <= 5) {
        QString consultaMat1 = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = '" + mat[icont1] + "'";

        QSqlQuery consMat1;
        consMat1.exec(consultaMat1);
        consMat1.next();

        int curs1,encurs1,disp1,ning1;
        curs1 = consMat1.value("cursada").toInt();
        encurs1 = consMat1.value("encurso").toInt();
        disp1 = consMat1.value("disponible").toInt();
        ning1 = consMat1.value("ninguno").toInt();

        qDebug() << curs1 << encurs1 << disp1 << ning1 << mat[icont1];

        if(curs1 == 0 && encurs1 == 0 && disp1 == 1 && ning1 == 0){
            QString consultaOp = "SELECT optativaI,optativaII,optativaDESIT FROM materia WHERE idMateria = '" + mat[icont1] + "'";

            QSqlQuery consOp;
            consOp.exec(consultaOp);
            consOp.next();

            int OP1 = consOp.value("optativaI").toInt();
            int OP2 = consOp.value("optativaII").toInt();
            int OPD = consOp.value("optativaDESIT").toInt();

            if(OP1 == 0 && OP2 == 0 && OPD == 0){
                QString tomarMat = "UPDATE infomateria SET cursada = 0, encurso = 1, disponible = 0, ninguno = 0 WHERE idMateria = '" + mat[icont1] + "' AND matricula = '" + matricula + "'";

                QSqlQuery tomaMat;
                tomaMat.exec(tomarMat);
                tomaMat.next();
            }else{
                /*OPTATIVA 1*/
                if(OP1 == 1 && OP2 == 0 && OPD == 0){
                    /*Desactivar las otras optativas*/
                    QString desacOP1 = "UPDATE infomateria SET ninguno = 1, disponible = 0, cursada = 0, encurso = 0 WHERE idMateria >= 43 AND idMateria <= 54 AND idMateria != '" + mat[icont1] + "' AND matricula = '" + matricula + "'";
                    QSqlQuery desOP1;
                    desOP1.exec(desacOP1);
                    desOP1.next();

                    /*Cargar la optativa*/
                    QString tomarMat = "UPDATE infomateria SET cursada = 0, encurso = 1, disponible = 0, ninguno = 0 WHERE idMateria = '" + mat[icont1] + "' AND matricula = '" + matricula + "'";

                    QSqlQuery tomaMat;
                    tomaMat.exec(tomarMat);
                    tomaMat.next();
                }
                /*OPTATIVA 2*/
                if(OP1 == 0 && OP2 == 1 && OPD == 0){
                    /*Desactivar las otras optativas*/
                    QString desacOP2 = "UPDATE infomateria SET ninguno = 1, disponible = 0, cursada = 0, encurso = 0 WHERE idMateria >= 58 AND idMateria <= 68 AND idMateria != '" + mat[icont1] + "' AND matricula = '" + matricula + "'";
                    QSqlQuery desOP2;
                    desOP2.exec(desacOP2);
                    desOP2.next();

                    /*Cargar la optativa*/
                    QString tomarMat = "UPDATE infomateria SET cursada = 0, encurso = 1, disponible = 0, ninguno = 0 WHERE idMateria = '" + mat[icont1] + "' AND matricula = '" + matricula + "'";

                    QSqlQuery tomaMat;
                    tomaMat.exec(tomarMat);
                    tomaMat.next();
                }
                /*OPTATIVA DESIT*/
                if(OP1 == 0 && OP2 == 0 && OPD == 1){
                    /*Desactivar las otras optativas*/
                    QString desacOP2 = "UPDATE infomateria SET ninguno = 1, disponible = 0, cursada = 0, encurso = 0 WHERE idMateria >= 69 AND idMateria <= 71 AND idMateria != '" + mat[icont1] + "' AND matricula = '" + matricula + "'";
                    QSqlQuery desOP2;
                    desOP2.exec(desacOP2);
                    desOP2.next();

                    /*Cargar la optativa*/
                    QString tomarMat = "UPDATE infomateria SET cursada = 0, encurso = 1, disponible = 0, ninguno = 0 WHERE idMateria = '" + mat[icont1] + "' AND matricula = '" + matricula + "'";

                    QSqlQuery tomaMat;
                    tomaMat.exec(tomarMat);
                    tomaMat.next();
                }
            }
        }else{
            if( (!(mat[icont1].isEmpty()))){
                QString aviso = "La materia con Id " + mat[icont1] + " no pudo inscribirse";
                QMessageBox::about(this, "Error", aviso);
            }
        }

        icont1 = icont1 + 1;
    }

    QMessageBox::about(this, "Información", "Las materias se inscribieron correctamente");

    ui->materiaEdit1->clear();
    ui->materiaEdit2->clear();
    ui->materiaEdit3->clear();
    ui->materiaEdit4->clear();
    ui->materiaEdit5->clear();
    ui->materiaEdit6->clear();
    CargarTablaMaterias();
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
void MainWindow::graficas(){
    qDeleteAll(ui->horizontalFrame->findChildren<QChartView *>());

    QString semestre = ui->semestre->currentText();
    qDebug() << semestre;

    QBarSet *set0 = new QBarSet("En curso");

    QBarSeries *series = new QBarSeries();

    QStringList categories;

    QChart *chart = new QChart();

    int sumavalores;

    QList <int> lista;

    if(semestre=="1er Semestre"){
        int materias = 1, contmat = 0,mat[5];
        QString nombmat[5];

        while(materias <= 5){
            QString queryMatOcup = "SELECT sum(encurso) AS suma FROM infomateria WHERE encurso = 1 AND idMateria = '" + QString::number(materias) + "'";

            QSqlQuery queryMOcup;
            queryMOcup.exec(queryMatOcup);
            queryMOcup.next();

            mat[contmat] = queryMOcup.value("suma").toInt();
            lista.append(mat[contmat]);

            QString matNomb = "SELECT Nombre FROM materia WHERE idMateria = '" + QString::number(materias) + "'";

            QSqlQuery queryNombMat;
            queryNombMat.exec(matNomb);
            queryNombMat.next();

            nombmat[contmat] = queryNombMat.value("Nombre").toString();

            contmat = contmat + 1;
            materias = materias + 1;
        }

        qDebug() << mat[0] << mat[1] << mat[2] << mat[3] << mat[4];
        sumavalores = mat[0] + mat[1] + mat[2] + mat[3] + mat[4];

        *set0 << mat[0] << mat[1] << mat[2] << mat[3] << mat[4];

        series->append(set0);

        categories << nombmat[0] << nombmat[1] << nombmat[2] << nombmat[3] << nombmat[4];

        ui->labelMaterias->setText("Materias del Primer Semestre");
    }
    if(semestre=="2do Semestre"){
        int materias = 6, contmat = 0,mat[6];
        QString nombmat[6];

        while(materias <= 11){
            QString queryMatOcup = "SELECT sum(encurso) AS suma FROM infomateria WHERE encurso = 1 AND idMateria = '" + QString::number(materias) + "'";

            QSqlQuery queryMOcup;
            queryMOcup.exec(queryMatOcup);
            queryMOcup.next();

            mat[contmat] = queryMOcup.value("suma").toInt();
            lista.append(mat[contmat]);

            QString matNomb = "SELECT Nombre FROM materia WHERE idMateria = '" + QString::number(materias) + "'";

            QSqlQuery queryNombMat;
            queryNombMat.exec(matNomb);
            queryNombMat.next();

            nombmat[contmat] = queryNombMat.value("Nombre").toString();

            contmat = contmat + 1;
            materias = materias + 1;
        }

        qDebug() << mat[0] << mat[1] << mat[2] << mat[3] << mat[4] << mat[5];
        sumavalores = mat[0] + mat[1] + mat[2] + mat[3] + mat[4] + mat[5];

        *set0 << mat[0] << mat[1] << mat[2] << mat[3] << mat[4] << mat[5];

        series->append(set0);

        categories << nombmat[0] << nombmat[1] << nombmat[2] << nombmat[3] << nombmat[4] << nombmat[5];

        ui->labelMaterias->setText("Materias del Segundo Semestre");
    }
    if(semestre=="3er Semestre"){
        int materias = 12, contmat = 0,mat[6];
        QString nombmat[6];

        while(materias <= 17){
            QString queryMatOcup = "SELECT sum(encurso) AS suma FROM infomateria WHERE encurso = 1 AND idMateria = '" + QString::number(materias) + "'";

            QSqlQuery queryMOcup;
            queryMOcup.exec(queryMatOcup);
            queryMOcup.next();

            mat[contmat] = queryMOcup.value("suma").toInt();
            lista.append(mat[contmat]);

            QString matNomb = "SELECT Nombre FROM materia WHERE idMateria = '" + QString::number(materias) + "'";

            QSqlQuery queryNombMat;
            queryNombMat.exec(matNomb);
            queryNombMat.next();

            nombmat[contmat] = queryNombMat.value("Nombre").toString();

            contmat = contmat + 1;
            materias = materias + 1;
        }

        qDebug() << mat[0] << mat[1] << mat[2] << mat[3] << mat[4] << mat[5];
        sumavalores = mat[0] + mat[1] + mat[2] + mat[3] + mat[4] + mat[5];

        *set0 << mat[0] << mat[1] << mat[2] << mat[3] << mat[4] << mat[5];

        series->append(set0);

        categories << nombmat[0] << nombmat[1] << nombmat[2] << nombmat[3] << nombmat[4] << nombmat[5];

        ui->labelMaterias->setText("Materias del Tercer Semestre");
    }
    if(semestre=="4to Semestre"){
        int materias = 18, contmat = 0,mat[5];
        QString nombmat[5];

        while(materias <= 22){
            QString queryMatOcup = "SELECT sum(encurso) AS suma FROM infomateria WHERE encurso = 1 AND idMateria = '" + QString::number(materias) + "'";

            QSqlQuery queryMOcup;
            queryMOcup.exec(queryMatOcup);
            queryMOcup.next();

            mat[contmat] = queryMOcup.value("suma").toInt();
            lista.append(mat[contmat]);

            QString matNomb = "SELECT Nombre FROM materia WHERE idMateria = '" + QString::number(materias) + "'";

            QSqlQuery queryNombMat;
            queryNombMat.exec(matNomb);
            queryNombMat.next();

            nombmat[contmat] = queryNombMat.value("Nombre").toString();

            contmat = contmat + 1;
            materias = materias + 1;
        }

        qDebug() << mat[0] << mat[1] << mat[2] << mat[3] << mat[4];
        sumavalores = mat[0] + mat[1] + mat[2] + mat[3] + mat[4];

        *set0 << mat[0] << mat[1] << mat[2] << mat[3] << mat[4];

        series->append(set0);

        categories << nombmat[0] << nombmat[1] << nombmat[2] << nombmat[3] << nombmat[4];

        ui->labelMaterias->setText("Materias del Cuarto Semestre");
    }
    if(semestre=="5to Semestre"){
        int materias = 23, contmat = 0,mat[5];
        QString nombmat[5];

        while(materias <= 27){
            QString queryMatOcup = "SELECT sum(encurso) AS suma FROM infomateria WHERE encurso = 1 AND idMateria = '" + QString::number(materias) + "'";

            QSqlQuery queryMOcup;
            queryMOcup.exec(queryMatOcup);
            queryMOcup.next();

            mat[contmat] = queryMOcup.value("suma").toInt();
            lista.append(mat[contmat]);

            QString matNomb = "SELECT Nombre FROM materia WHERE idMateria = '" + QString::number(materias) + "'";

            QSqlQuery queryNombMat;
            queryNombMat.exec(matNomb);
            queryNombMat.next();

            nombmat[contmat] = queryNombMat.value("Nombre").toString();

            contmat = contmat + 1;
            materias = materias + 1;
        }

        qDebug() << mat[0] << mat[1] << mat[2] << mat[3] << mat[4];
        sumavalores = mat[0] + mat[1] + mat[2] + mat[3] + mat[4];

        *set0 << mat[0] << mat[1] << mat[2] << mat[3] << mat[4];

        series->append(set0);

        categories << nombmat[0] << nombmat[1] << nombmat[2] << nombmat[3] << nombmat[4];

        ui->labelMaterias->setText("Materias del Quinto Semestre");
    }
    if(semestre=="6to Semestre"){
        int materias = 28, contmat = 0,mat[5];
        QString nombmat[5];

        while(materias <= 32){
            QString queryMatOcup = "SELECT sum(encurso) AS suma FROM infomateria WHERE encurso = 1 AND idMateria = '" + QString::number(materias) + "'";

            QSqlQuery queryMOcup;
            queryMOcup.exec(queryMatOcup);
            queryMOcup.next();

            mat[contmat] = queryMOcup.value("suma").toInt();
            lista.append(mat[contmat]);

            QString matNomb = "SELECT Nombre FROM materia WHERE idMateria = '" + QString::number(materias) + "'";

            QSqlQuery queryNombMat;
            queryNombMat.exec(matNomb);
            queryNombMat.next();

            nombmat[contmat] = queryNombMat.value("Nombre").toString();

            contmat = contmat + 1;
            materias = materias + 1;
        }

        qDebug() << mat[0] << mat[1] << mat[2] << mat[3] << mat[4];
        sumavalores = mat[0] + mat[1] + mat[2] + mat[3] + mat[4];

        *set0 << mat[0] << mat[1] << mat[2] << mat[3] << mat[4];

        series->append(set0);

        categories << nombmat[0] << nombmat[1] << nombmat[2] << nombmat[3] << nombmat[4];

        ui->labelMaterias->setText("Materias del Sexto Semestre");
    }
    if(semestre=="7mo Semestre"){
        int materias = 33, contmat = 0,mat[5];
        QString nombmat[5];

        while(materias <= 37){
            QString queryMatOcup = "SELECT sum(encurso) AS suma FROM infomateria WHERE encurso = 1 AND idMateria = '" + QString::number(materias) + "'";

            QSqlQuery queryMOcup;
            queryMOcup.exec(queryMatOcup);
            queryMOcup.next();

            mat[contmat] = queryMOcup.value("suma").toInt();
            lista.append(mat[contmat]);

            QString matNomb = "SELECT Nombre FROM materia WHERE idMateria = '" + QString::number(materias) + "'";

            QSqlQuery queryNombMat;
            queryNombMat.exec(matNomb);
            queryNombMat.next();

            nombmat[contmat] = queryNombMat.value("Nombre").toString();

            contmat = contmat + 1;
            materias = materias + 1;
        }

        qDebug() << mat[0] << mat[1] << mat[2] << mat[3] << mat[4];
        sumavalores = mat[0] + mat[1] + mat[2] + mat[3] + mat[4];

        *set0 << mat[0] << mat[1] << mat[2] << mat[3] << mat[4];

        series->append(set0);

        categories << nombmat[0] << nombmat[1] << nombmat[2] << nombmat[3] << nombmat[4];

        ui->labelMaterias->setText("Materias del Séptimo Semestre");
    }
    if(semestre=="8vo Semestre"){
        int materias = 38, contmat = 0,mat[5];
        QString nombmat[5];

        while(materias <= 42){
            QString queryMatOcup = "SELECT sum(encurso) AS suma FROM infomateria WHERE encurso = 1 AND idMateria = '" + QString::number(materias) + "'";

            QSqlQuery queryMOcup;
            queryMOcup.exec(queryMatOcup);
            queryMOcup.next();

            mat[contmat] = queryMOcup.value("suma").toInt();
            lista.append(mat[contmat]);

            QString matNomb = "SELECT Nombre FROM materia WHERE idMateria = '" + QString::number(materias) + "'";

            QSqlQuery queryNombMat;
            queryNombMat.exec(matNomb);
            queryNombMat.next();

            nombmat[contmat] = queryNombMat.value("Nombre").toString();

            contmat = contmat + 1;
            materias = materias + 1;
        }

        qDebug() << mat[0] << mat[1] << mat[2] << mat[3] << mat[4];
        sumavalores = mat[0] + mat[1] + mat[2] + mat[3] + mat[4];

        *set0 << mat[0] << mat[1] << mat[2] << mat[3] << mat[4];

        series->append(set0);

        categories << nombmat[0] << nombmat[1] << nombmat[2] << nombmat[3] << nombmat[4];

        ui->labelMaterias->setText("Materias del Octavo Semestre");
    }
    if(semestre=="Optativas I"){
        int materias = 43, contmat = 0,mat[12];
        QString nombmat[12];

        while(materias <= 54){
            QString queryMatOcup = "SELECT sum(encurso) AS suma FROM infomateria WHERE encurso = 1 AND idMateria = '" + QString::number(materias) + "'";

            QSqlQuery queryMOcup;
            queryMOcup.exec(queryMatOcup);
            queryMOcup.next();

            mat[contmat] = queryMOcup.value("suma").toInt();
            lista.append(mat[contmat]);

            QString matNomb = "SELECT Nombre FROM materia WHERE idMateria = '" + QString::number(materias) + "'";

            QSqlQuery queryNombMat;
            queryNombMat.exec(matNomb);
            queryNombMat.next();

            nombmat[contmat] = queryNombMat.value("Nombre").toString();

            contmat = contmat + 1;
            materias = materias + 1;
        }

        qDebug() << mat[0] << mat[1] << mat[2] << mat[3] << mat[4] << mat[5] << mat[6] << mat[7] << mat[8] << mat[9] << mat[10] << mat[11];
        sumavalores = mat[0] + mat[1] + mat[2] + mat[3] + mat[4] + mat[5] + mat[6] + mat[7] + mat[8] + mat[9] + mat[10] + mat[11];

        *set0 << mat[0] << mat[1] << mat[2] << mat[3] << mat[4] << mat[5] << mat[6] << mat[7] << mat[8] << mat[9] << mat[10] << mat[11];

        series->append(set0);

        categories << nombmat[0] << nombmat[1] << nombmat[2] << nombmat[3] << nombmat[4] << nombmat[5] << nombmat[6] << nombmat[7] << nombmat[8] << nombmat[9] << nombmat[10] << nombmat[11];

        ui->labelMaterias->setText("Materias del Grupo Optativas I");
    }
    if(semestre=="9no Semestre"){
        int materias = 55, contmat = 0,mat[3];
        QString nombmat[3];

        while(materias <= 57){
            QString queryMatOcup = "SELECT sum(encurso) AS suma FROM infomateria WHERE encurso = 1 AND idMateria = '" + QString::number(materias) + "'";

            QSqlQuery queryMOcup;
            queryMOcup.exec(queryMatOcup);
            queryMOcup.next();

            mat[contmat] = queryMOcup.value("suma").toInt();
            lista.append(mat[contmat]);

            QString matNomb = "SELECT Nombre FROM materia WHERE idMateria = '" + QString::number(materias) + "'";

            QSqlQuery queryNombMat;
            queryNombMat.exec(matNomb);
            queryNombMat.next();

            nombmat[contmat] = queryNombMat.value("Nombre").toString();

            contmat = contmat + 1;
            materias = materias + 1;
        }

        qDebug() << mat[0] << mat[1] << mat[2];
        sumavalores = mat[0] + mat[1] + mat[2];

        *set0 << mat[0] << mat[1] << mat[2];

        series->append(set0);

        categories << nombmat[0] << nombmat[1] << nombmat[2];

        ui->labelMaterias->setText("Materias del Noveno Semestre");
    }
    if(semestre=="Optativas II"){
        int materias = 58, contmat = 0,mat[11];
        QString nombmat[11];

        while(materias <= 68){
            QString queryMatOcup = "SELECT sum(encurso) AS suma FROM infomateria WHERE encurso = 1 AND idMateria = '" + QString::number(materias) + "'";

            QSqlQuery queryMOcup;
            queryMOcup.exec(queryMatOcup);
            queryMOcup.next();

            mat[contmat] = queryMOcup.value("suma").toInt();
            lista.append(mat[contmat]);

            QString matNomb = "SELECT Nombre FROM materia WHERE idMateria = '" + QString::number(materias) + "'";

            QSqlQuery queryNombMat;
            queryNombMat.exec(matNomb);
            queryNombMat.next();

            nombmat[contmat] = queryNombMat.value("Nombre").toString();

            contmat = contmat + 1;
            materias = materias + 1;
        }

        qDebug() << mat[0] << mat[1] << mat[2] << mat[3] << mat[4] << mat[5] << mat[6] << mat[7] << mat[8] << mat[9] << mat[10];
        sumavalores = mat[0] + mat[1] + mat[2] + mat[3] + mat[4] + mat[5] + mat[6] + mat[7] + mat[8] + mat[9] + mat[10];

        *set0 << mat[0] << mat[1] << mat[2] << mat[3] << mat[4] << mat[5] << mat[6] << mat[7] << mat[8] << mat[9] << mat[10];

        series->append(set0);

        categories << nombmat[0] << nombmat[1] << nombmat[2] << nombmat[3] << nombmat[4] << nombmat[5] << nombmat[6] << nombmat[7] << nombmat[8] << nombmat[9] << nombmat[10];

        ui->labelMaterias->setText("Materias del Grupo Optativas II");
    }
    if(semestre=="Optativas DESIT"){
        int materias = 69, contmat = 0,mat[3];
        QString nombmat[3];

        while(materias <= 71){
            QString queryMatOcup = "SELECT sum(encurso) AS suma FROM infomateria WHERE encurso = 1 AND idMateria = '" + QString::number(materias) + "'";

            QSqlQuery queryMOcup;
            queryMOcup.exec(queryMatOcup);
            queryMOcup.next();

            mat[contmat] = queryMOcup.value("suma").toInt();
            lista.append(mat[contmat]);

            QString matNomb = "SELECT Nombre FROM materia WHERE idMateria = '" + QString::number(materias) + "'";

            QSqlQuery queryNombMat;
            queryNombMat.exec(matNomb);
            queryNombMat.next();

            nombmat[contmat] = queryNombMat.value("Nombre").toString();

            contmat = contmat + 1;
            materias = materias + 1;
        }

        qDebug() << mat[0] << mat[1] << mat[2];
        sumavalores = mat[0] + mat[1] + mat[2];

        *set0 << mat[0] << mat[1] << mat[2];

        series->append(set0);

        categories << nombmat[0] << nombmat[1] << nombmat[2];

        ui->labelMaterias->setText("Materias del Grupo Optativas DESIT");
    }
    if(semestre=="10mo Semestre"){
        int materias = 72, contmat = 0,mat[2];
        QString nombmat[2];

        while(materias <= 73){
            QString queryMatOcup = "SELECT sum(encurso) AS suma FROM infomateria WHERE encurso = 1 AND idMateria = '" + QString::number(materias) + "'";

            QSqlQuery queryMOcup;
            queryMOcup.exec(queryMatOcup);
            queryMOcup.next();

            mat[contmat] = queryMOcup.value("suma").toInt();
            lista.append(mat[contmat]);

            QString matNomb = "SELECT Nombre FROM materia WHERE idMateria = '" + QString::number(materias) + "'";

            QSqlQuery queryNombMat;
            queryNombMat.exec(matNomb);
            queryNombMat.next();

            nombmat[contmat] = queryNombMat.value("Nombre").toString();

            contmat = contmat + 1;
            materias = materias + 1;
        }

        qDebug() << mat[0] << mat[1];
        sumavalores = mat[0] + mat[1];

        *set0 << mat[0] << mat[1];

        series->append(set0);

        categories << nombmat[0] << nombmat[1];

        ui->labelMaterias->setText("Materias del Décimo Semestre");
    }

    int max = *std::max_element(lista.begin(),lista.end());

    qDebug() << max;

    series->setLabelsVisible(true);

    chart->addSeries(series);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->legend()->markers(series)[0]->setVisible(false);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,10);
    axisY->setTickCount(5);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    ui->horizontalFrame->layout()->addWidget(chartView);
}
void MainWindow::on_graficas_2_clicked(){
    ui->stackProfesor->setCurrentIndex(2);

    ui->semestre->setCurrentIndex(0);
    graficas();
}
void MainWindow::on_semestre_currentIndexChanged(int index)
{
    graficas();
}
void MainWindow::on_perfil_2_clicked(){
    limpiartabmatnom();
    ui->nombreusuariobuscm->clear();
    ui->resetpassNE->clear();
    ui->resetpassNC->clear();
    ui->resetpassNCR->clear();

    ui->stackProfesor->setCurrentIndex(3);
}
void MainWindow::on_cambiarpass_clicked()
{
    QString matrUss,nuevcontra,nuevcontrarep;

    matrUss = ui->resetpassNE->text();
    nuevcontra = ui->resetpassNC->text();
    nuevcontrarep = ui->resetpassNCR->text();

    /*buscar el nombre de usuario*/
    QString depositaN, queryUserB = "SELECT Nombre FROM estudiante WHERE matricula = '" + matrUss + "'";

    QSqlQuery obtSiUs;
    obtSiUs.exec(queryUserB);
    obtSiUs.next();

    depositaN = obtSiUs.value("Nombre").toString();

    if(depositaN.isEmpty()){
        QMessageBox::about(this, "Error", "No ha introducido una matrícula válida");
        return;
    }

    /*comparar contraseñas*/
    if(nuevcontra != nuevcontrarep){
        QMessageBox::about(this, "Error", "Las contraseñas no son iguales");
        return;
    }

    /*cambiar contraseña*/
    QString cambioP = "UPDATE estudiante SET contrasena = '" + nuevcontra + "' WHERE matricula = '" + matrUss + "'";

    QSqlQuery cambPass;
    cambPass.exec(cambioP);
    cambPass.next();

    QMessageBox::about(this, "Aviso", "Contraseña cambiada exitosamente");

    ui->resetpassNE->clear();
    ui->resetpassNC->clear();
    ui->resetpassNCR->clear();
}
void MainWindow::limpiartabmatnom(){
    QSqlQueryModel *query2;

    query2 = new QSqlQueryModel();
    query2->setQuery("SELECT matricula as Matricula,Nombre from estudiante WHERE Nombre = '1515'");

    ui->tablaMatriculas->setModel(query2);
    ui->tablaMatriculas->setColumnWidth(0,91);
    ui->tablaMatriculas->setColumnWidth(1,340);
}
void MainWindow::on_searchmat_clicked()
{
    QString alumnobusqueda;
    alumnobusqueda = ui->nombreusuariobuscm->text();

    if(alumnobusqueda.isEmpty()){
        QMessageBox::about(this, "Error", "No ha introducido ningún nombre");
        return;
    }

    QString queryBusquedaMat = "SELECT matricula as Matricula,Nombre from estudiante WHERE Nombre LIKE '%" + alumnobusqueda + "%'";

    QSqlQueryModel *queryMatriculaBusc;

    queryMatriculaBusc = new QSqlQueryModel();
    queryMatriculaBusc->setQuery(queryBusquedaMat);

    ui->tablaMatriculas->verticalHeader()->setVisible(false);   //hide header
    //ui->tablaMatriculas->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tablaMatriculas->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tablaMatriculas->setModel(queryMatriculaBusc);
}
void MainWindow::on_cerrar_sesion_2_clicked(){
    limpiartabmatnom();
    ui->nombreusuariobuscm->clear();
    ui->resetpassNE->clear();
    ui->resetpassNC->clear();
    ui->resetpassNCR->clear();

    ui->stackedWidget->setCurrentIndex(0);
}

//----------------------- Botones del mapa --------------------------

void MainWindow::on_mater1_clicked()
{
    /*Verificar materia*/
    QString numMat = "1";

    QString siMateria = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE idMateria = '" + numMat + "' AND matricula = '" + matricula + "'";

    qDebug() << siMateria;

    QSqlQuery sMateria;
    sMateria.exec(siMateria);
    sMateria.next();

    int curs = sMateria.value("cursada").toInt();
    int encur = sMateria.value("encurso").toInt();
    int disp = sMateria.value("disponible").toInt();
    int ning = sMateria.value("ninguno").toInt();

    qDebug() << curs << encur << disp << ning;

    if(curs == 0 && encur == 1 && disp == 0 && ning == 0){
        QMessageBox::StandardButton terminada;
        terminada = QMessageBox::question(this, "Materia cursada", "¿Desea indicar que ha cursado esta materia?", QMessageBox::Yes|QMessageBox::No);

        if(terminada == QMessageBox::Yes){
            /*Actualizar datos materia*/
            QString actDatMat = "UPDATE infomateria SET cursada = 1, encurso = 0, disponible = 0, ninguno = 0 WHERE idMateria = '" + numMat + "' AND matricula = '" + matricula + "'";
            qDebug() << actDatMat;

            QSqlQuery acDatM;
            acDatM.exec(actDatMat);
            acDatM.next();

            /*Actualizar requisitos*/
            QString actDatMat2 = "SELECT idMateria1,idMateria2 FROM requisito WHERE idMateria1 = '" + numMat + "'";

            QSqlQuery acDM2;
            acDM2.exec(actDatMat2);

            while (acDM2.next()) {
                QString matSigM = acDM2.value("idMateria2").toString();

                QString actInfoSig = "UPDATE infomateria SET cursada = 0, encurso = 0, disponible = 1, ninguno = 0 WHERE idMateria = '" + matSigM + "' AND matricula = '" + matricula + "'";

                QSqlQuery aInfS;
                aInfS.exec(actInfoSig);
                aInfS.next();
            }
        }

        IndicarMaterias();
    }
}
void MainWindow::on_mater2_clicked()
{
    /*Verificar materia*/
    QString numMat = "2";

    QString siMateria = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE idMateria = '" + numMat + "' AND matricula = '" + matricula + "'";

    qDebug() << siMateria;

    QSqlQuery sMateria;
    sMateria.exec(siMateria);
    sMateria.next();

    int curs = sMateria.value("cursada").toInt();
    int encur = sMateria.value("encurso").toInt();
    int disp = sMateria.value("disponible").toInt();
    int ning = sMateria.value("ninguno").toInt();

    qDebug() << curs << encur << disp << ning;

    if(curs == 0 && encur == 1 && disp == 0 && ning == 0){
        QMessageBox::StandardButton terminada;
        terminada = QMessageBox::question(this, "Materia cursada", "¿Desea indicar que ha cursado esta materia?", QMessageBox::Yes|QMessageBox::No);

        if(terminada == QMessageBox::Yes){
            /*Actualizar datos materia*/
            QString actDatMat = "UPDATE infomateria SET cursada = 1, encurso = 0, disponible = 0, ninguno = 0 WHERE idMateria = '" + numMat + "' AND matricula = '" + matricula + "'";
            qDebug() << actDatMat;

            QSqlQuery acDatM;
            acDatM.exec(actDatMat);
            acDatM.next();

            /*Actualizar requisitos*/
            QString actDatMat2 = "SELECT idMateria1,idMateria2 FROM requisito WHERE idMateria1 = '" + numMat + "'";

            QSqlQuery acDM2;
            acDM2.exec(actDatMat2);

            while (acDM2.next()) {
                QString matSigM = acDM2.value("idMateria2").toString();

                QString actInfoSig = "UPDATE infomateria SET cursada = 0, encurso = 0, disponible = 1, ninguno = 0 WHERE idMateria = '" + matSigM + "' AND matricula = '" + matricula + "'";

                QSqlQuery aInfS;
                aInfS.exec(actInfoSig);
                aInfS.next();
            }
        }

        IndicarMaterias();
    }
}
void MainWindow::on_mater3_clicked()
{
    /*Verificar materia*/
    QString numMat = "3";

    QString siMateria = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE idMateria = '" + numMat + "' AND matricula = '" + matricula + "'";

    qDebug() << siMateria;

    QSqlQuery sMateria;
    sMateria.exec(siMateria);
    sMateria.next();

    int curs = sMateria.value("cursada").toInt();
    int encur = sMateria.value("encurso").toInt();
    int disp = sMateria.value("disponible").toInt();
    int ning = sMateria.value("ninguno").toInt();

    qDebug() << curs << encur << disp << ning;

    if(curs == 0 && encur == 1 && disp == 0 && ning == 0){
        QMessageBox::StandardButton terminada;
        terminada = QMessageBox::question(this, "Materia cursada", "¿Desea indicar que ha cursado esta materia?", QMessageBox::Yes|QMessageBox::No);

        if(terminada == QMessageBox::Yes){
            /*Actualizar datos materia*/
            QString actDatMat = "UPDATE infomateria SET cursada = 1, encurso = 0, disponible = 0, ninguno = 0 WHERE idMateria = '" + numMat + "' AND matricula = '" + matricula + "'";
            qDebug() << actDatMat;

            QSqlQuery acDatM;
            acDatM.exec(actDatMat);
            acDatM.next();

            /*Actualizar requisitos*/
            QString actDatMat2 = "SELECT idMateria1,idMateria2 FROM requisito WHERE idMateria1 = '" + numMat + "'";

            QSqlQuery acDM2;
            acDM2.exec(actDatMat2);

            while (acDM2.next()) {
                QString matSigM = acDM2.value("idMateria2").toString();

                QString actInfoSig = "UPDATE infomateria SET cursada = 0, encurso = 0, disponible = 1, ninguno = 0 WHERE idMateria = '" + matSigM + "' AND matricula = '" + matricula + "'";

                QSqlQuery aInfS;
                aInfS.exec(actInfoSig);
                aInfS.next();
            }
        }

        IndicarMaterias();
    }
}
void MainWindow::on_mater4_clicked()
{
    /*Verificar materia*/
    QString numMat = "4";

    QString siMateria = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE idMateria = '" + numMat + "' AND matricula = '" + matricula + "'";

    qDebug() << siMateria;

    QSqlQuery sMateria;
    sMateria.exec(siMateria);
    sMateria.next();

    int curs = sMateria.value("cursada").toInt();
    int encur = sMateria.value("encurso").toInt();
    int disp = sMateria.value("disponible").toInt();
    int ning = sMateria.value("ninguno").toInt();

    qDebug() << curs << encur << disp << ning;

    if(curs == 0 && encur == 1 && disp == 0 && ning == 0){
        QMessageBox::StandardButton terminada;
        terminada = QMessageBox::question(this, "Materia cursada", "¿Desea indicar que ha cursado esta materia?", QMessageBox::Yes|QMessageBox::No);

        if(terminada == QMessageBox::Yes){
            /*Actualizar datos materia*/
            QString actDatMat = "UPDATE infomateria SET cursada = 1, encurso = 0, disponible = 0, ninguno = 0 WHERE idMateria = '" + numMat + "' AND matricula = '" + matricula + "'";
            qDebug() << actDatMat;

            QSqlQuery acDatM;
            acDatM.exec(actDatMat);
            acDatM.next();

            /*Actualizar requisitos*/
            QString actDatMat2 = "SELECT idMateria1,idMateria2 FROM requisito WHERE idMateria1 = '" + numMat + "'";

            QSqlQuery acDM2;
            acDM2.exec(actDatMat2);

            while (acDM2.next()) {
                QString matSigM = acDM2.value("idMateria2").toString();

                QString actInfoSig = "UPDATE infomateria SET cursada = 0, encurso = 0, disponible = 1, ninguno = 0 WHERE idMateria = '" + matSigM + "' AND matricula = '" + matricula + "'";

                QSqlQuery aInfS;
                aInfS.exec(actInfoSig);
                aInfS.next();
            }
        }

        IndicarMaterias();
    }
}
void MainWindow::on_mater5_clicked()
{
    /*Verificar materia*/
    QString numMat = "5";

    QString siMateria = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE idMateria = '" + numMat + "' AND matricula = '" + matricula + "'";

    qDebug() << siMateria;

    QSqlQuery sMateria;
    sMateria.exec(siMateria);
    sMateria.next();

    int curs = sMateria.value("cursada").toInt();
    int encur = sMateria.value("encurso").toInt();
    int disp = sMateria.value("disponible").toInt();
    int ning = sMateria.value("ninguno").toInt();

    qDebug() << curs << encur << disp << ning;

    if(curs == 0 && encur == 1 && disp == 0 && ning == 0){
        QMessageBox::StandardButton terminada;
        terminada = QMessageBox::question(this, "Materia cursada", "¿Desea indicar que ha cursado esta materia?", QMessageBox::Yes|QMessageBox::No);

        if(terminada == QMessageBox::Yes){
            /*Actualizar datos materia*/
            QString actDatMat = "UPDATE infomateria SET cursada = 1, encurso = 0, disponible = 0, ninguno = 0 WHERE idMateria = '" + numMat + "' AND matricula = '" + matricula + "'";
            qDebug() << actDatMat;

            QSqlQuery acDatM;
            acDatM.exec(actDatMat);
            acDatM.next();

            /*Actualizar requisitos*/
            QString actDatMat2 = "SELECT idMateria1,idMateria2 FROM requisito WHERE idMateria1 = '" + numMat + "'";

            QSqlQuery acDM2;
            acDM2.exec(actDatMat2);

            while (acDM2.next()) {
                QString matSigM = acDM2.value("idMateria2").toString();

                QString actInfoSig = "UPDATE infomateria SET cursada = 0, encurso = 0, disponible = 1, ninguno = 0 WHERE idMateria = '" + matSigM + "' AND matricula = '" + matricula + "'";

                QSqlQuery aInfS;
                aInfS.exec(actInfoSig);
                aInfS.next();
            }
        }

        IndicarMaterias();
    }
}
void MainWindow::on_mater6_clicked()
{
    /*Verificar materia*/
    QString numMat = "6";

    QString siMateria = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE idMateria = '" + numMat + "' AND matricula = '" + matricula + "'";

    qDebug() << siMateria;

    QSqlQuery sMateria;
    sMateria.exec(siMateria);
    sMateria.next();

    int curs = sMateria.value("cursada").toInt();
    int encur = sMateria.value("encurso").toInt();
    int disp = sMateria.value("disponible").toInt();
    int ning = sMateria.value("ninguno").toInt();

    qDebug() << curs << encur << disp << ning;

    if(curs == 0 && encur == 1 && disp == 0 && ning == 0){
        QMessageBox::StandardButton terminada;
        terminada = QMessageBox::question(this, "Materia cursada", "¿Desea indicar que ha cursado esta materia?", QMessageBox::Yes|QMessageBox::No);

        if(terminada == QMessageBox::Yes){
            /*Actualizar datos materia*/
            QString actDatMat = "UPDATE infomateria SET cursada = 1, encurso = 0, disponible = 0, ninguno = 0 WHERE idMateria = '" + numMat + "' AND matricula = '" + matricula + "'";
            qDebug() << actDatMat;

            QSqlQuery acDatM;
            acDatM.exec(actDatMat);
            acDatM.next();

            /*Actualizar requisitos*/
            QString actDatMat2 = "SELECT idMateria1,idMateria2 FROM requisito WHERE idMateria1 = '" + numMat + "'";

            QSqlQuery acDM2;
            acDM2.exec(actDatMat2);

            while (acDM2.next()) {
                QString matSigM = acDM2.value("idMateria2").toString();

                QString actInfoSig = "UPDATE infomateria SET cursada = 0, encurso = 0, disponible = 1, ninguno = 0 WHERE idMateria = '" + matSigM + "' AND matricula = '" + matricula + "'";

                QSqlQuery aInfS;
                aInfS.exec(actInfoSig);
                aInfS.next();
            }
        }

        IndicarMaterias();
    }
}
void MainWindow::on_mater7_clicked()
{
    /*Verificar materia*/
    QString numMat = "7";

    QString siMateria = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE idMateria = '" + numMat + "' AND matricula = '" + matricula + "'";

    qDebug() << siMateria;

    QSqlQuery sMateria;
    sMateria.exec(siMateria);
    sMateria.next();

    int curs = sMateria.value("cursada").toInt();
    int encur = sMateria.value("encurso").toInt();
    int disp = sMateria.value("disponible").toInt();
    int ning = sMateria.value("ninguno").toInt();

    qDebug() << curs << encur << disp << ning;

    if(curs == 0 && encur == 1 && disp == 0 && ning == 0){
        QMessageBox::StandardButton terminada;
        terminada = QMessageBox::question(this, "Materia cursada", "¿Desea indicar que ha cursado esta materia?", QMessageBox::Yes|QMessageBox::No);

        if(terminada == QMessageBox::Yes){
            /*Actualizar datos materia*/
            QString actDatMat = "UPDATE infomateria SET cursada = 1, encurso = 0, disponible = 0, ninguno = 0 WHERE idMateria = '" + numMat + "' AND matricula = '" + matricula + "'";
            qDebug() << actDatMat;

            QSqlQuery acDatM;
            acDatM.exec(actDatMat);
            acDatM.next();

            /*Actualizar requisitos*/
            QString actDatMat2 = "SELECT idMateria1,idMateria2 FROM requisito WHERE idMateria1 = '" + numMat + "'";

            QSqlQuery acDM2;
            acDM2.exec(actDatMat2);

            while (acDM2.next()) {
                QString matSigM = acDM2.value("idMateria2").toString();

                QString actInfoSig = "UPDATE infomateria SET cursada = 0, encurso = 0, disponible = 1, ninguno = 0 WHERE idMateria = '" + matSigM + "' AND matricula = '" + matricula + "'";

                QSqlQuery aInfS;
                aInfS.exec(actInfoSig);
                aInfS.next();
            }
        }

        IndicarMaterias();
    }
}
void MainWindow::on_mater8_clicked()
{
    /*Verificar materia*/
    QString numMat = "8";

    QString siMateria = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE idMateria = '" + numMat + "' AND matricula = '" + matricula + "'";

    qDebug() << siMateria;

    QSqlQuery sMateria;
    sMateria.exec(siMateria);
    sMateria.next();

    int curs = sMateria.value("cursada").toInt();
    int encur = sMateria.value("encurso").toInt();
    int disp = sMateria.value("disponible").toInt();
    int ning = sMateria.value("ninguno").toInt();

    qDebug() << curs << encur << disp << ning;

    if(curs == 0 && encur == 1 && disp == 0 && ning == 0){
        QMessageBox::StandardButton terminada;
        terminada = QMessageBox::question(this, "Materia cursada", "¿Desea indicar que ha cursado esta materia?", QMessageBox::Yes|QMessageBox::No);

        if(terminada == QMessageBox::Yes){
            /*Actualizar datos materia*/
            QString actDatMat = "UPDATE infomateria SET cursada = 1, encurso = 0, disponible = 0, ninguno = 0 WHERE idMateria = '" + numMat + "' AND matricula = '" + matricula + "'";
            qDebug() << actDatMat;

            QSqlQuery acDatM;
            acDatM.exec(actDatMat);
            acDatM.next();

            /*Actualizar requisitos*/
            QString actDatMat2 = "SELECT idMateria1,idMateria2 FROM requisito WHERE idMateria1 = '" + numMat + "'";

            QSqlQuery acDM2;
            acDM2.exec(actDatMat2);

            while (acDM2.next()) {

                QString matSigM = acDM2.value("idMateria2").toString();

                if(matSigM=="20"){
                    QString consultaPrograII = "SELECT cursada FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 15";

                    QSqlQuery cProgII;
                    cProgII.exec(consultaPrograII);
                    cProgII.next();

                    int consPII = cProgII.value("cursada").toInt();

                    if(consPII==1){
                        QString actInfoSig = "UPDATE infomateria SET cursada = 0, encurso = 0, disponible = 1, ninguno = 0 WHERE idMateria = '" + matSigM + "' AND matricula = '" + matricula + "'";

                        QSqlQuery aInfS;
                        aInfS.exec(actInfoSig);
                        aInfS.next();
                    }
                }else{
                    QString actInfoSig = "UPDATE infomateria SET cursada = 0, encurso = 0, disponible = 1, ninguno = 0 WHERE idMateria = '" + matSigM + "' AND matricula = '" + matricula + "'";

                    QSqlQuery aInfS;
                    aInfS.exec(actInfoSig);
                    aInfS.next();
                }
            }
        }

        IndicarMaterias();
    }
}
void MainWindow::on_mater9_clicked()
{
    /*Verificar materia*/
    QString numMat = "9";

    QString siMateria = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE idMateria = '" + numMat + "' AND matricula = '" + matricula + "'";

    qDebug() << siMateria;

    QSqlQuery sMateria;
    sMateria.exec(siMateria);
    sMateria.next();

    int curs = sMateria.value("cursada").toInt();
    int encur = sMateria.value("encurso").toInt();
    int disp = sMateria.value("disponible").toInt();
    int ning = sMateria.value("ninguno").toInt();

    qDebug() << curs << encur << disp << ning;

    if(curs == 0 && encur == 1 && disp == 0 && ning == 0){
        QMessageBox::StandardButton terminada;
        terminada = QMessageBox::question(this, "Materia cursada", "¿Desea indicar que ha cursado esta materia?", QMessageBox::Yes|QMessageBox::No);

        if(terminada == QMessageBox::Yes){
            /*Actualizar datos materia*/
            QString actDatMat = "UPDATE infomateria SET cursada = 1, encurso = 0, disponible = 0, ninguno = 0 WHERE idMateria = '" + numMat + "' AND matricula = '" + matricula + "'";
            qDebug() << actDatMat;

            QSqlQuery acDatM;
            acDatM.exec(actDatMat);
            acDatM.next();

            /*Actualizar requisitos*/
            QString actDatMat2 = "SELECT idMateria1,idMateria2 FROM requisito WHERE idMateria1 = '" + numMat + "'";

            QSqlQuery acDM2;
            acDM2.exec(actDatMat2);

            while (acDM2.next()) {
                QString matSigM = acDM2.value("idMateria2").toString();

                QString actInfoSig = "UPDATE infomateria SET cursada = 0, encurso = 0, disponible = 1, ninguno = 0 WHERE idMateria = '" + matSigM + "' AND matricula = '" + matricula + "'";

                QSqlQuery aInfS;
                aInfS.exec(actInfoSig);
                aInfS.next();
            }
        }

        IndicarMaterias();
    }
}
void MainWindow::on_mater10_clicked()
{
    /*Verificar materia*/
    QString numMat = "10";

    QString siMateria = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE idMateria = '" + numMat + "' AND matricula = '" + matricula + "'";

    qDebug() << siMateria;

    QSqlQuery sMateria;
    sMateria.exec(siMateria);
    sMateria.next();

    int curs = sMateria.value("cursada").toInt();
    int encur = sMateria.value("encurso").toInt();
    int disp = sMateria.value("disponible").toInt();
    int ning = sMateria.value("ninguno").toInt();

    qDebug() << curs << encur << disp << ning;

    if(curs == 0 && encur == 1 && disp == 0 && ning == 0){
        QMessageBox::StandardButton terminada;
        terminada = QMessageBox::question(this, "Materia cursada", "¿Desea indicar que ha cursado esta materia?", QMessageBox::Yes|QMessageBox::No);

        if(terminada == QMessageBox::Yes){
            /*Actualizar datos materia*/
            QString actDatMat = "UPDATE infomateria SET cursada = 1, encurso = 0, disponible = 0, ninguno = 0 WHERE idMateria = '" + numMat + "' AND matricula = '" + matricula + "'";
            qDebug() << actDatMat;

            QSqlQuery acDatM;
            acDatM.exec(actDatMat);
            acDatM.next();

            /*Actualizar requisitos*/
            QString actDatMat2 = "SELECT idMateria1,idMateria2 FROM requisito WHERE idMateria1 = '" + numMat + "'";

            QSqlQuery acDM2;
            acDM2.exec(actDatMat2);

            while (acDM2.next()) {
                QString matSigM = acDM2.value("idMateria2").toString();

                QString actInfoSig = "UPDATE infomateria SET cursada = 0, encurso = 0, disponible = 1, ninguno = 0 WHERE idMateria = '" + matSigM + "' AND matricula = '" + matricula + "'";

                QSqlQuery aInfS;
                aInfS.exec(actInfoSig);
                aInfS.next();
            }
        }

        IndicarMaterias();
    }
}
void MainWindow::on_mater11_clicked()
{
    /*Verificar materia*/
    QString numMat = "11";

    QString siMateria = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE idMateria = '" + numMat + "' AND matricula = '" + matricula + "'";

    qDebug() << siMateria;

    QSqlQuery sMateria;
    sMateria.exec(siMateria);
    sMateria.next();

    int curs = sMateria.value("cursada").toInt();
    int encur = sMateria.value("encurso").toInt();
    int disp = sMateria.value("disponible").toInt();
    int ning = sMateria.value("ninguno").toInt();

    qDebug() << curs << encur << disp << ning;

    if(curs == 0 && encur == 1 && disp == 0 && ning == 0){
        QMessageBox::StandardButton terminada;
        terminada = QMessageBox::question(this, "Materia cursada", "¿Desea indicar que ha cursado esta materia?", QMessageBox::Yes|QMessageBox::No);

        if(terminada == QMessageBox::Yes){
            /*Actualizar datos materia*/
            QString actDatMat = "UPDATE infomateria SET cursada = 1, encurso = 0, disponible = 0, ninguno = 0 WHERE idMateria = '" + numMat + "' AND matricula = '" + matricula + "'";
            qDebug() << actDatMat;

            QSqlQuery acDatM;
            acDatM.exec(actDatMat);
            acDatM.next();

            /*Actualizar requisitos*/
            QString actDatMat2 = "SELECT idMateria1,idMateria2 FROM requisito WHERE idMateria1 = '" + numMat + "'";

            QSqlQuery acDM2;
            acDM2.exec(actDatMat2);

            while (acDM2.next()) {
                QString matSigM = acDM2.value("idMateria2").toString();

                QString actInfoSig = "UPDATE infomateria SET cursada = 0, encurso = 0, disponible = 1, ninguno = 0 WHERE idMateria = '" + matSigM + "' AND matricula = '" + matricula + "'";

                QSqlQuery aInfS;
                aInfS.exec(actInfoSig);
                aInfS.next();
            }
        }

        IndicarMaterias();
    }
}

void MainWindow::on_mater12_clicked()
{
    /*Verificar materia*/
    QString numMat = "12";

    QString siMateria = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE idMateria = '" + numMat + "' AND matricula = '" + matricula + "'";

    qDebug() << siMateria;

    QSqlQuery sMateria;
    sMateria.exec(siMateria);
    sMateria.next();

    int curs = sMateria.value("cursada").toInt();
    int encur = sMateria.value("encurso").toInt();
    int disp = sMateria.value("disponible").toInt();
    int ning = sMateria.value("ninguno").toInt();

    qDebug() << curs << encur << disp << ning;

    if(curs == 0 && encur == 1 && disp == 0 && ning == 0){
        QMessageBox::StandardButton terminada;
        terminada = QMessageBox::question(this, "Materia cursada", "¿Desea indicar que ha cursado esta materia?", QMessageBox::Yes|QMessageBox::No);

        if(terminada == QMessageBox::Yes){
            /*Actualizar datos materia*/
            QString actDatMat = "UPDATE infomateria SET cursada = 1, encurso = 0, disponible = 0, ninguno = 0 WHERE idMateria = '" + numMat + "' AND matricula = '" + matricula + "'";
            qDebug() << actDatMat;

            QSqlQuery acDatM;
            acDatM.exec(actDatMat);
            acDatM.next();

            /*Actualizar requisitos*/
            QString actDatMat2 = "SELECT idMateria1,idMateria2 FROM requisito WHERE idMateria1 = '" + numMat + "'";

            QSqlQuery acDM2;
            acDM2.exec(actDatMat2);

            while (acDM2.next()) {
                QString matSigM = acDM2.value("idMateria2").toString();

                QString actInfoSig = "UPDATE infomateria SET cursada = 0, encurso = 0, disponible = 1, ninguno = 0 WHERE idMateria = '" + matSigM + "' AND matricula = '" + matricula + "'";

                QSqlQuery aInfS;
                aInfS.exec(actInfoSig);
                aInfS.next();
            }
        }

        IndicarMaterias();
    }
}
void MainWindow::on_mater13_clicked()
{
    /*Verificar materia*/
    QString numMat = "13";

    QString siMateria = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE idMateria = '" + numMat + "' AND matricula = '" + matricula + "'";

    qDebug() << siMateria;

    QSqlQuery sMateria;
    sMateria.exec(siMateria);
    sMateria.next();

    int curs = sMateria.value("cursada").toInt();
    int encur = sMateria.value("encurso").toInt();
    int disp = sMateria.value("disponible").toInt();
    int ning = sMateria.value("ninguno").toInt();

    qDebug() << curs << encur << disp << ning;

    if(curs == 0 && encur == 1 && disp == 0 && ning == 0){
        QMessageBox::StandardButton terminada;
        terminada = QMessageBox::question(this, "Materia cursada", "¿Desea indicar que ha cursado esta materia?", QMessageBox::Yes|QMessageBox::No);

        if(terminada == QMessageBox::Yes){
            /*Actualizar datos materia*/
            QString actDatMat = "UPDATE infomateria SET cursada = 1, encurso = 0, disponible = 0, ninguno = 0 WHERE idMateria = '" + numMat + "' AND matricula = '" + matricula + "'";
            qDebug() << actDatMat;

            QSqlQuery acDatM;
            acDatM.exec(actDatMat);
            acDatM.next();

            /*Actualizar requisitos*/
            QString actDatMat2 = "SELECT idMateria1,idMateria2 FROM requisito WHERE idMateria1 = '" + numMat + "'";

            QSqlQuery acDM2;
            acDM2.exec(actDatMat2);

            while (acDM2.next()) {
                QString matSigM = acDM2.value("idMateria2").toString();

                QString actInfoSig = "UPDATE infomateria SET cursada = 0, encurso = 0, disponible = 1, ninguno = 0 WHERE idMateria = '" + matSigM + "' AND matricula = '" + matricula + "'";

                QSqlQuery aInfS;
                aInfS.exec(actInfoSig);
                aInfS.next();
            }
        }

        IndicarMaterias();
    }
}

void MainWindow::on_mater14_clicked()
{
    /*Verificar materia*/
    QString numMat = "14";

    QString siMateria = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE idMateria = '" + numMat + "' AND matricula = '" + matricula + "'";

    qDebug() << siMateria;

    QSqlQuery sMateria;
    sMateria.exec(siMateria);
    sMateria.next();

    int curs = sMateria.value("cursada").toInt();
    int encur = sMateria.value("encurso").toInt();
    int disp = sMateria.value("disponible").toInt();
    int ning = sMateria.value("ninguno").toInt();

    qDebug() << curs << encur << disp << ning;

    if(curs == 0 && encur == 1 && disp == 0 && ning == 0){
        QMessageBox::StandardButton terminada;
        terminada = QMessageBox::question(this, "Materia cursada", "¿Desea indicar que ha cursado esta materia?", QMessageBox::Yes|QMessageBox::No);

        if(terminada == QMessageBox::Yes){
            /*Actualizar datos materia*/
            QString actDatMat = "UPDATE infomateria SET cursada = 1, encurso = 0, disponible = 0, ninguno = 0 WHERE idMateria = '" + numMat + "' AND matricula = '" + matricula + "'";
            qDebug() << actDatMat;

            QSqlQuery acDatM;
            acDatM.exec(actDatMat);
            acDatM.next();

            /*Actualizar requisitos*/
            QString actDatMat2 = "SELECT idMateria1,idMateria2 FROM requisito WHERE idMateria1 = '" + numMat + "'";

            QSqlQuery acDM2;
            acDM2.exec(actDatMat2);

            while (acDM2.next()) {
                QString matSigM = acDM2.value("idMateria2").toString();

                QString actInfoSig = "UPDATE infomateria SET cursada = 0, encurso = 0, disponible = 1, ninguno = 0 WHERE idMateria = '" + matSigM + "' AND matricula = '" + matricula + "'";

                QSqlQuery aInfS;
                aInfS.exec(actInfoSig);
                aInfS.next();
            }
        }

        IndicarMaterias();
    }
}

void MainWindow::on_mater15_clicked()
{
    /*Verificar materia*/
    QString numMat = "15";

    QString siMateria = "SELECT cursada,encurso,disponible,ninguno FROM infomateria WHERE idMateria = '" + numMat + "' AND matricula = '" + matricula + "'";

    qDebug() << siMateria;

    QSqlQuery sMateria;
    sMateria.exec(siMateria);
    sMateria.next();

    int curs = sMateria.value("cursada").toInt();
    int encur = sMateria.value("encurso").toInt();
    int disp = sMateria.value("disponible").toInt();
    int ning = sMateria.value("ninguno").toInt();

    qDebug() << curs << encur << disp << ning;

    if(curs == 0 && encur == 1 && disp == 0 && ning == 0){
        QMessageBox::StandardButton terminada;
        terminada = QMessageBox::question(this, "Materia cursada", "¿Desea indicar que ha cursado esta materia?", QMessageBox::Yes|QMessageBox::No);

        if(terminada == QMessageBox::Yes){
            /*Actualizar datos materia*/
            QString actDatMat = "UPDATE infomateria SET cursada = 1, encurso = 0, disponible = 0, ninguno = 0 WHERE idMateria = '" + numMat + "' AND matricula = '" + matricula + "'";
            qDebug() << actDatMat;

            QSqlQuery acDatM;
            acDatM.exec(actDatMat);
            acDatM.next();

            /*Actualizar requisitos*/
            QString actDatMat2 = "SELECT idMateria1,idMateria2 FROM requisito WHERE idMateria1 = '" + numMat + "'";

            QSqlQuery acDM2;
            acDM2.exec(actDatMat2);

            while (acDM2.next()) {

                QString matSigM = acDM2.value("idMateria2").toString();

                if(matSigM=="20"){
                    QString consultaAlgLin = "SELECT cursada FROM infomateria WHERE matricula = '" + matricula + "' AND idMateria = 8";

                    QSqlQuery cAlgLin;
                    cAlgLin.exec(consultaAlgLin);
                    cAlgLin.next();

                    int consAL = cAlgLin.value("cursada").toInt();

                    if(consAL==1){
                        QString actInfoSig = "UPDATE infomateria SET cursada = 0, encurso = 0, disponible = 1, ninguno = 0 WHERE idMateria = '" + matSigM + "' AND matricula = '" + matricula + "'";

                        QSqlQuery aInfS;
                        aInfS.exec(actInfoSig);
                        aInfS.next();
                    }
                }else{
                    QString actInfoSig = "UPDATE infomateria SET cursada = 0, encurso = 0, disponible = 1, ninguno = 0 WHERE idMateria = '" + matSigM + "' AND matricula = '" + matricula + "'";

                    QSqlQuery aInfS;
                    aInfS.exec(actInfoSig);
                    aInfS.next();
                }
            }
        }

        IndicarMaterias();
    }
}

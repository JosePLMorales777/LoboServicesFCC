#include "loboservices.h"
#include "ui_loboservices.h"

LoboServices::LoboServices(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoboServices)
{
    ui->setupUi(this);
}

LoboServices::~LoboServices()
{
    delete ui;
}


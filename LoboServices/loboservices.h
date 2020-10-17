#ifndef LOBOSERVICES_H
#define LOBOSERVICES_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class LoboServices; }
QT_END_NAMESPACE

class LoboServices : public QMainWindow
{
    Q_OBJECT

public:
    LoboServices(QWidget *parent = nullptr);
    ~LoboServices();

private:
    Ui::LoboServices *ui;
};
#endif // LOBOSERVICES_H

#ifndef SMIRNOVMAIN_H
#define SMIRNOVMAIN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class SmirnovMain;
}
QT_END_NAMESPACE

class SmirnovMain : public QMainWindow
{
    Q_OBJECT
    QString fileName;

public:
    SmirnovMain(QWidget *parent = nullptr);
    ~SmirnovMain();

private slots:
    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void save();


private:
    Ui::SmirnovMain *ui;
};
#endif // SMIRNOVMAIN_H

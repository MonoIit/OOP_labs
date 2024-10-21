#include "smirnovmain.h"
#include "./ui_smirnovmain.h"
#include <QFileDialog>

SmirnovMain::SmirnovMain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SmirnovMain)
{
    ui->setupUi(this);
}

SmirnovMain::~SmirnovMain()
{
    delete ui;
}

void SmirnovMain::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Load Group", "", "Group Files (*.grp)");
    if (!filename.isEmpty()) {
        ui->widget->loadFromFile(filename);
        ui->widget->populateTable();
    }
}


void SmirnovMain::on_actionSave_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save Group", "", "Group Files (*.grp)");
    if (!filename.isEmpty()) {
        save();
    }
}

void SmirnovMain::save()
{
    ui->widget->saveToFile(fileName);
}


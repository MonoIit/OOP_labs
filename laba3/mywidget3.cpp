#include "mywidget3.h"




template<class Archive>
void MyWidget3::serialize(Archive &ar, const unsigned int version) {
    ar & members;
}


MyWidget3::MyWidget3(QWidget *parent)
    : QWidget(parent), tableWidget(new QTableWidget(this)) {
    setupTable();
    populateTable();
}

void MyWidget3::saveToFile(const QString& path) {
    // Открываем файл на запись
    ofstream file(path.toStdString());

    // Проверка открытие файла
    if (file.is_open())
    {
        boost::archive::text_oarchive oa(file);

        oa << members;
    }
}

void MyWidget3::loadFromFile(const QString& path) {
    // Открываем файл на чтение
    ifstream ifs(path.toStdString());

    // Проверка открытие файла
    if (ifs.is_open())
    {
        clean(); // Очистить текущий список перед загрузкой новых данных

        boost::archive::text_iarchive ia(ifs);

        ia >> members;
    }
}

void MyWidget3::clean() {
    members.clear();
    update();
}

MyWidget3::~MyWidget3() {
    delete tableWidget;
}

void MyWidget3::setupTable() {
    tableWidget->setColumnCount(7);
    tableWidget->setHorizontalHeaderLabels({"Type", "Name", "Age", "Height", "Weight", "Univerisy", "Pass"});
    tableWidget->setRowCount(members.size());
    tableWidget->setGeometry(10, 10, 800, 300);  // Установите размеры и положение таблицы
}


void MyWidget3::populateTable() {
    for (int i = 0; i < members.size(); ++i) {
        auto member = members[i];

        QTableWidgetItem *typeItem = new QTableWidgetItem(member->getType());
        QTableWidgetItem *nameItem = new QTableWidgetItem(member->name);
        QTableWidgetItem *ageItem = new QTableWidgetItem(QString::number(member->age));
        QTableWidgetItem *heightItem = new QTableWidgetItem(QString::number(member->height));
        QTableWidgetItem *weightItem = new QTableWidgetItem(QString::number(member->weight));

        tableWidget->setItem(i, 0, typeItem);
        tableWidget->setItem(i, 1, nameItem);
        tableWidget->setItem(i, 2, ageItem);
        tableWidget->setItem(i, 3, heightItem);
        tableWidget->setItem(i, 4, weightItem);

        // Если это студент, добавим специальность
        if (member->getType() == "Student") {
            auto student = std::dynamic_pointer_cast<SmirnovStudent>(member);
            QTableWidgetItem *universityItem = new QTableWidgetItem(student->university);
            QTableWidgetItem *passItem = new QTableWidgetItem(QString::number(student->pass));
            tableWidget->insertColumn(5);
            tableWidget->insertColumn(6);
            tableWidget->setHorizontalHeaderItem(5, new QTableWidgetItem("university"));
            tableWidget->setItem(i, 5, universityItem);
            tableWidget->setHorizontalHeaderItem(6, new QTableWidgetItem("pass"));
            tableWidget->setItem(i, 6, passItem);
        }
    }
}

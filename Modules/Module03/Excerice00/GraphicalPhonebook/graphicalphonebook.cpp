#include "graphicalphonebook.h"
#include "ui_graphicalphonebook.h"

GraphicalPhonebook::GraphicalPhonebook(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GraphicalPhonebook)
{
    ui->setupUi(this);
}

GraphicalPhonebook::~GraphicalPhonebook()
{
    delete ui;
}

void GraphicalPhonebook::on_addPushButton_clicked()
{
    qDebug() << "bla";
}


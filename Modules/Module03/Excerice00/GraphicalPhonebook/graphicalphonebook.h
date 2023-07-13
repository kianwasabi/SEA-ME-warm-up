#pragma once

#ifndef GRAPHICALPHONEBOOK_H
#define GRAPHICALPHONEBOOK_H

#include <QDialog>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class GraphicalPhonebook; }
QT_END_NAMESPACE

class GraphicalPhonebook : public QDialog
{
    Q_OBJECT

public:
    GraphicalPhonebook(QWidget *parent = nullptr);
    ~GraphicalPhonebook();

private slots:

    void on_addPushButton_clicked();

private:
    Ui::GraphicalPhonebook *ui;
};
#endif // GRAPHICALPHONEBOOK_H

#pragma once

#ifndef GRAPHICALPHONEBOOK_H
#define GRAPHICALPHONEBOOK_H

#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QFile>
//#include <QFileDialog>
#include <QStandardPaths>
#include <QTextStream>
#include <QCheckBox>
#include <QTableWidget>

#include "classphonebook.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class GraphicalPhonebook; }
QT_END_NAMESPACE

class GraphicalPhonebook : public QDialog
{
    Q_OBJECT

public:
    GraphicalPhonebook(QWidget *parent = nullptr);
    ~GraphicalPhonebook();
    void updateContactTable(vector<vector<string>> data);
    void exportContacts(QTableWidget* contactTable, const QString& filename);

private slots:

    void on_addPushButton_clicked();

    void on_exportPushButton_clicked();

    void on_bookmarkPushButton_clicked();

    void on_selectContactLineEdit_textChanged(const QString &arg1);

    void on_removePushButton_clicked();

    void on_editPushButton_clicked();

private:
    Ui::GraphicalPhonebook *ui; //GUI
    Phonebook phonebook; // Phonebook
    // User Inputs
    QString firstnameQString_;
    QString lastnameQString_;
    QString phonenumberQString_;
    QString eMailQString_;
    QString nicknameQString_;
    QString selectQString_;
};
#endif // GRAPHICALPHONEBOOK_H

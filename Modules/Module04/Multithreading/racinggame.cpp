#include "racinggame.h"
#include "ui_racinggame.h"

RacingGame::RacingGame(QWidget *parent):QMainWindow(parent),ui(new Ui::RacingGame)
{
    ui->setupUi(this);
}

RacingGame::~RacingGame()
{
    delete ui;
}

/*Connecting threads to cars*/
void RacingGame::startRace() {
    // Create a new thread for each car and start the threads
    foreach (Car *car, carList) {
        QThread *thread = new QThread();
        CarThread *carThread = new CarThread(car);
        carThread->moveToThread(thread);

        connect(car, &Car::positionChanged, carThread, &CarThread::updatePosition);
        connect(thread, &QThread::started, carThread, &CarThread::run);
        connect(carThread, &CarThread::finished, thread, &QThread::quit);
        connect(carThread, &CarThread::finished, carThread, &CarThread::deleteLater);
        connect(thread, &QThread::finished, thread, &QThread::deleteLater);

        threadList.append(thread);
        carThread->start();
    }
}




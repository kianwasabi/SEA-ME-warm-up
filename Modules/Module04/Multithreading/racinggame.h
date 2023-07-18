#pragma once

#ifndef RACINGGAME_H
#define RACINGGAME_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class RacingGame; }
QT_END_NAMESPACE

class RacingGame : public QMainWindow
{
    Q_OBJECT

public:
    RacingGame(QWidget *parent = nullptr);
    ~RacingGame();

private slots:
    void startRace();
    void pauseRace();
    void exitGame();

private:
    Ui::RacingGame *ui;
    RaceTrack *raceTrack;
    QList<Car*> carList;
    QList<QThread*> threadList;
};
#endif // RACINGGAME_H

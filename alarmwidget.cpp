#include "alarmwidget.h"

#include <QDebug>
#include <QMessageBox>

#include "ui_alarmwidget.h"

alarmwidget::alarmwidget(QDateTime dtime, QWidget* parent)
    : QWidget(parent), ui(new Ui::alarmwidget), dtime(dtime) {
  ui->setupUi(this);

  /// create timer and set interval for it
  timer = new QTimer(this);
  timer->setInterval(1000);

  /// create media player and set mp3 file
  player = new QMediaPlayer(this);
  player->setMedia(QUrl("qrc:/alarmSounds/alien-ship.mp3"));
  ui->lcdNumber->setDigitCount(11);
  ui->lcdNumber->setSegmentStyle(QLCDNumber::Filled);

  //  auto pal = ui->lcdNumber->palette();
  //  pal.setColor(QPalette::Normal, QPalette::WindowText, Qt::black);
  //  pal.setColor(QPalette::Normal, QPalette::Window, Qt::white);
  //  pal.setColor(QPalette::Normal, QPalette::Dark, Qt::white);
  //  pal.setColor(QPalette::Normal, QPalette::Light, Qt::black);
  //  ui->lcdNumber->setAutoFillBackground(1);
  //  ui->lcdNumber->setPalette(pal);
  //  ui->lcdNumber->set
  ui->lcdNumber->display(dtime.toString("dd.MM hh:mm"));

  /// connect timer to update values in widget
  connect(timer, &QTimer::timeout, [this]() {
    /// if time is up
    if (QDateTime::currentDateTime().secsTo(this->dtime) == 0) {
      if (ui->checkBox->isChecked()) {
        /// create message about end of time using QMessageBox
        QMessageBox alarm(this);
        alarm.setText("Wake up!");
        this->dtime = this->dtime.addDays(1);
        ui->lcdNumber->display(this->dtime.toString("dd.MM hh:mm"));
        player->play();
        alarm.exec(), player->stop();
        return;
      }
    }
  });
/// deleting the alarm
  connect(ui->removeButton, &QAbstractButton::clicked, [this] {
    timer->stop();
    deleteLater();
  });

  timer->start();
}

/// destructor
alarmwidget::~alarmwidget() {
  delete ui;
}

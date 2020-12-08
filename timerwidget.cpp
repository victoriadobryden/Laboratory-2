#include "timerwidget.h"

#include <QDebug>
#include <QMessageBox>
#include <QTimer>

#include "ui_timerwidget.h"

timerWidget::timerWidget(QTime time, QWidget* parent)
    : QWidget(parent), time(time), ui(new Ui::timerWidget) {
  ui->setupUi(this);
  
    /// create timer and set interval for it
  timer = new QTimer(this);
  timer->setInterval(1000);
  timer->start();
  ui->lcdNumber->setDigitCount(8);

  ui->lcdNumber->display(time.toString("hh:mm:ss"));

  ///set time data to label in widget
  QTime timeForLabel(this->time.hour(), this->time.minute(),
                     this->time.second());
                     
  /// create media player and set mp3 file
  player = new QMediaPlayer(this);
  player->setMedia(QUrl("qrc:/timerSounds/nuclear-warning.mp3"));

  /// connect timer to update values in widget
  connect(timer, &QTimer::timeout,
          [this, timeForLabel = QTime(this->time.hour(), this->time.minute(),
                                      this->time.second())]() mutable {
  /// decrement time for 1 sec
            timeForLabel = timeForLabel.addSecs(-1);
            ui->lcdNumber->display(timeForLabel.toString("hh:mm:ss"));

  /// if time is up
            if (timeForLabel.secsTo(QTime(0, 0, 0)) == 0) {
              timer->stop();
              player->play();
   /// create message about end of time using QMessageBox
              QMessageBox alarm(this);
              alarm.setText("Time is up!");
              alarm.exec(), player->stop(), deleteLater();
            }
          });
}


///destructor
timerWidget::~timerWidget() {
  delete ui;
}

void timerWidget::on_StopButton_clicked() {
  /// stop timer and delete current timer
  timer->stop();
  deleteLater();
}

void timerWidget::on_pauseButton_clicked() {
/// if clicked on "pause" - stop timer
  if (ui->pauseButton->text() == "Pause") {
    timer->stop();
    ui->pauseButton->setText("Resume");
  } else {
/// if clicked on "resume" - resume timer
    timer->start();
    ui->pauseButton->setText("Pause");
  }
}

#include "smartalarm.h"

#include <QLayout>
#include <QMessageBox>

#include "addalarmdialog.h"
#include "addtimerdialog.h"
#include "alarmwidget.h"
#include "timerwidget.h"
#include "ui_smartalarm.h"

#include <QCloseEvent>

SmartAlarm::SmartAlarm(QWidget* parent)
    : QWidget(parent), ui(new Ui::SmartAlarm) {
  ui->setupUi(this);
  
  /// connect button for add new timer or alarm with event of open corresponging dialog
  connect(ui->addAlarm, &QPushButton::clicked, [this] {
    if (ui->tabWidget->currentWidget()->layout()->count() < 5) {
      if (ui->tabWidget->currentIndex() == 0)
        (new addAlarmDialog(this))->show();
      else if (ui->tabWidget->currentIndex() == 1)
        (new addTimerDialog(this))->show();
    } else
      QMessageBox::warning(
          this, "Warning",
          QString("You can't create more than 5 %1s")
              .arg(ui->tabWidget->currentIndex() == 0 ? "alarm" : "timer"));
  });
}


///destructor
SmartAlarm::~SmartAlarm() {
  delete ui;
}



void SmartAlarm::addAlarm(QDateTime time) {
///add new alarm to the scene
  ui->tab->layout()->addWidget(new alarmwidget(time));
}

void SmartAlarm::addTimer(QTime time) {
///add new timer to the scene
  ui->tab_2->layout()->addWidget(new timerWidget(time));
}
/// close the alarm or timer
void SmartAlarm::closeEvent(QCloseEvent* event) {
  event->accept();
  exit(0);
}

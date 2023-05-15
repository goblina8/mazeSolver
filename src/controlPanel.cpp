#include "controlPanel.hh"

ControlPanel::ControlPanel(QWidget *parent):  QWidget(parent)
{
  QHBoxLayout *horizontal = new QHBoxLayout(this);
  QHBoxLayout *horizontal1 = new QHBoxLayout();
  QHBoxLayout *horizontal2 = new QHBoxLayout();
  QVBoxLayout *vertical1 = new QVBoxLayout(); 
  QVBoxLayout *vertical2 = new QVBoxLayout(); 

  _PaintView = new PaintView(this);
  _CloseButton = new QPushButton(tr("Zamknij"),this);

  QPushButton  *RestartButton = new QPushButton(tr("Wiatr"),this);
  RestartButton->setCheckable(true);
  RestartButton->setObjectName("RestartButton");

  vertical1->addWidget(_PaintView);
  horizontal1->addItem(new QSpacerItem(10,10,QSizePolicy::Minimum,QSizePolicy::Expanding));
  horizontal2->addWidget(RestartButton);  
  horizontal2->addWidget( _CloseButton);
  
  vertical2->addLayout(horizontal1);
  vertical2->addLayout(horizontal2);

  horizontal->addLayout(vertical1);
  horizontal->addLayout(vertical2);

  connect(_CloseButton,SIGNAL(clicked()),this,SIGNAL(ReportClosing()));
  QMetaObject::connectSlotsByName(this);
}

void ControlPanel::on_RestartButton_toggled(bool Checked)
{
  if (Checked) _PaintView->startMove();
          else _PaintView->stopMove();
}
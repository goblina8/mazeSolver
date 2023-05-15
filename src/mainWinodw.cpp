#include "mainWindow.hh"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
  _ControlPanel = new ControlPanel(this);
  setStatusBar(new QStatusBar());
  resize(300,230);
  setCentralWidget(_ControlPanel);
  connect(_ControlPanel,SIGNAL(ReportSign(const QString &)),
          this,SLOT(receiveStatus(const QString &)));
  connect(_ControlPanel,SIGNAL(ReportClosing()),
          this,SLOT(whenClosed()));
}

void MainWindow::receiveStatus(const QString &Napis)
{
  statusBar()->showMessage(Napis);
}
 
bool MainWindow::canBeClosed()
{
  return QMessageBox::question(this,tr("Caution"),
                                 tr("Are you sure about closing the ap"),
                                    QMessageBox::Yes | QMessageBox::No,
                                    QMessageBox::No ) 
          == QMessageBox::Yes;
}
 
void MainWindow::closeEvent( QCloseEvent * event )
{
  if (canBeClosed()) event->accept();
                    else event->ignore();
}

void MainWindow::whenClosed()
{
  if (canBeClosed()) qApp->quit();
}

void MainWindow:: keyPressEvent(QKeyEvent * event)
{
  if(event->key() == Qt::Key_W)
  {
    _ControlPanel->maze()->is_there_path(1);
    _ControlPanel->paintView()->update();
  }
  if(event->key() == Qt::Key_S)
  {
    _ControlPanel->maze()->is_there_path(2);
    _ControlPanel->paintView()->update();
  }
  if(event->key() == Qt::Key_A)
  {
    _ControlPanel->maze()->is_there_path(3);
    _ControlPanel->paintView()->update();
  }
  if(event->key() == Qt::Key_D)
  {
    _ControlPanel->maze()->is_there_path(4);
    _ControlPanel->paintView()->update();
  }
}

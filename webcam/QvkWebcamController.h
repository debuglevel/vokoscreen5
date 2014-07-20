#ifndef QvkWebcamController_H 
#define QvkWebcamController_H

#include <QObject>
#include <QCamera>

class QvkWebcamController : public QObject
{
    Q_OBJECT

public:
  QvkWebcamController();
  virtual ~QvkWebcamController();

public slots:
  void searchDevices();
  QStringList getDeviceDescriptionList();
  QStringList getDeviceName();
  
private slots:

  
private:
    QStringList deviceDescriptionList;
    QStringList deviceNameList;
  
protected:
  
  
};

#endif

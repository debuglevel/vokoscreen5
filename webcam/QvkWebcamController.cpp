#include "QvkWebcamController.h" 


#include <QCameraViewfinder>

QvkWebcamController::QvkWebcamController()
{
}

QvkWebcamController::~QvkWebcamController()
{
}

void QvkWebcamController::searchDevices()
{
    deviceDescriptionList.clear();
    deviceNameList.clear();
    
    QCamera *camera = new QCamera();
    foreach( const QByteArray &deviceName, QCamera::availableDevices() )
    {
        deviceDescriptionList.append( camera->deviceDescription( deviceName ) );
	deviceNameList.append( deviceName );
	qDebug() << deviceName;
	qDebug() << camera->deviceDescription( deviceName );
    }
    
    QCamera *myCamera = new QCamera( deviceNameList.at( 1 ).toLocal8Bit().constData() );

    QCameraViewfinder *viewfinder = new QCameraViewfinder;
    myCamera->setViewfinder(viewfinder);
    viewfinder->show();
    myCamera->start();
    
    
    qDebug() << myCamera->availableMetaData();
    qDebug() << myCamera->isMetaDataAvailable();
}


QStringList QvkWebcamController::getDeviceDescriptionList()
{
  return deviceDescriptionList;
}


QStringList QvkWebcamController::getDeviceName()
{
  return deviceNameList;
}
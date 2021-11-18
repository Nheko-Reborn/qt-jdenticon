#ifndef JDENTICONPLUGIN_H
#define JDENTICONPLUGIN_H

#include <QObject>
#include <QtPlugin>

#include "jdenticoninterface.h"

class JdenticonPlugin
  : public QObject
  , JdenticonInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "im.nheko.JdenticonInterface")
    Q_INTERFACES(JdenticonInterface)

public:
    QString generate(const QString &message, uint16_t size) override;
};

#endif // JDENTICONPLUGIN_H

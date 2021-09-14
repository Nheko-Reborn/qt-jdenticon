#include "jdenticonplugin.h"

#include "identicon.h"

QString
JdenticonPlugin::generate(const QString &message, uint16_t size)
{
    //QByteArray byteArr = QByteArray::fromStdString(message.toStdString());
    QString copy = message;
    Identicon identicon(copy, size);
    return identicon.generateSvg(identicon, false);
}

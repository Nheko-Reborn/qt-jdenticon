#include "jdenticonplugin.h"

#include "identicon.h"

QString
JdenticonPlugin::generate(const QString &message, uint16_t size)
{
    QByteArray byteArr = QByteArray::fromStdString(message.toStdString());
    Identicon identicon(byteArr, size);
    return identicon.generateSvg(identicon, false);
}

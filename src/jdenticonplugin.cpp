#include "jdenticonplugin.h"

#include "identicon.h"

QString
JdenticonPlugin::generate(const QString &message, uint16_t size)
{
    Identicon identicon(message, size);
    return identicon.generateSvg(identicon, false);
}

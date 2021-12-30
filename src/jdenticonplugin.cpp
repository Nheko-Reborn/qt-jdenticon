#include "jdenticonplugin.h"

#include "identicon.h"

QString
JdenticonPlugin::generate(const QString &message, uint16_t size)
{
    return Identicon::generateSvg(message, size, false);
}

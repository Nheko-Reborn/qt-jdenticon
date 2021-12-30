#include <QCoreApplication>
#include <QtDebug>
#include <QtGlobal>

#include "identicon.h"

int
main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<QString> hashes = {
      "@red_sky:ocean.joedonofry.com",
    };
    for (const QString &hash : qAsConst(hashes)) {
        QByteArray hashArr = QByteArray::fromStdString(hash.toStdString());
        qInfo() << hash;
        qInfo() << Identicon::generateSvg(hash, 256, false);
    }
    return 0;
    // return a.exec();
}

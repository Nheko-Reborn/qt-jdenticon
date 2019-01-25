#include <QCoreApplication>
#include <QtGlobal>
#include <QtDebug>
#include "identicon.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<QString> hashes =
    {
        "@red_sky:ocean.joedonofry.com",
    };
    for (QString hash : hashes) {
        QByteArray hashArr = QByteArray::fromStdString(hash.toStdString());
        Identicon test(hashArr, 256);
        qInfo() << hash;
        qInfo() << test.generateSvg(test, false);
    }
    return  0;
    //return a.exec();
}

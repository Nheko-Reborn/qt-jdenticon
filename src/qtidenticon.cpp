#include <QCommandLineParser>
#include <QCoreApplication>
#include <QtDebug>
#include <QtGlobal>

#include <iostream>
#include <string>

#include "identicon.h"

int
main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QCommandLineParser parser;
    parser.setApplicationDescription(
      "Generates SVGs from strings (supplied via command line arguments or taken from stdin). For "
      "each input, the output is:\ninput<newline>SVG<newline>");
    parser.addHelpOption();
    parser.addOption(
      {{"i", "input"}, "Input to feed the generator, can appear multiple times.", "string"});
    parser.process(app);

    QList<QString> inputList = parser.values("input");
    // get strings from stdin if nothing is supplied via command line
    if (inputList.empty()) {
        std::string line;
        while (!std::cin.eof()) {
            std::getline(std::cin, line);
            if (!line.empty()) {
                inputList.append(QString::fromStdString(line));
            }
        }
    }

    for (const auto &input : inputList) {
        std::cout << input.toStdString() << '\n';
        std::cout << Identicon::generateSvg(input, 256, false).toStdString() << '\n';
    }
    return 0;
    // return a.exec();
}

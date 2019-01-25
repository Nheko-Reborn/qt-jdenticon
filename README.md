This is the initial Qt5 port of jdenticon (https://github.com/dmester/jdenticon)

Not all of the features are currently implemented, and there may be bugs in various places.  It also does not have a proper build other than via qmake / Qt Creator.  Consider this a Work In Progress at the moment.

The eventual plan for this is that it will be made into a Qt5 library that can be
used in other applications with a command-line application for use as a standalone
generator.

In order to generate new jdenticon's, the main function in qtidenticon.cpp must be modified.  The program does not yet support command line arguments that allow the input of the text to be jdenticon-ified.



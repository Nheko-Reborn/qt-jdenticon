######################################################################
# Automatically generated by qmake (3.1) Wed Jan 23 02:47:03 2019
######################################################################

TEMPLATE = lib
CONFIG += plugin c++17
TARGET = qtjdenticon
TARGET = $$qtLibraryTarget($$TARGET)
uri = im.nheko.qtjdenticon

INCLUDEPATH = includes
INCLUDEPATH += .
VERSION = 0.3.1

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

CONFIG(debug) {
    DEFINES += QT_NO_DEBUG_OUTPUT
}

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += src/identicon.h \
           src/identiconstyle.h \
           src/qtidenticon.h \
           src/qtidenticon_global.h \
           src/rendering/colortheme.h \
           src/rendering/colorutils.h \
           src/rendering/icongenerator.h \
           src/rendering/rectangle.h \
           src/rendering/renderer.h \
           src/rendering/svgpath.h \
           src/rendering/svgrenderer.h \
           src/rendering/transform.h \
           src/shapes/shape.h \
           src/shapes/shapecategory.h \
           src/shapes/shapedefinitions.h \
           src/shapes/shapeposition.h \
           src/jdenticonplugin.h \
           includes/jdenticoninterface.h
SOURCES += src/identicon.cpp \
           src/qtidenticon.cpp \
           src/rendering/colortheme.cpp \
           src/rendering/colorutils.cpp \
           src/rendering/icongenerator.cpp \
           src/rendering/rectangle.cpp \
           src/rendering/svgpath.cpp \
           src/rendering/svgrenderer.cpp \
           src/rendering/transform.cpp \
           src/shapes/shape.cpp \
           src/shapes/shapecategory.cpp \
           src/shapes/shapedefinitions.cpp \
           src/shapes/shapeposition.cpp \
           src/jdenticonplugin.cpp

# install
target.path = $$[QT_INSTALL_PLUGINS]
INSTALLS += target

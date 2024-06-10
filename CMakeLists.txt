cmake_minimum_required(VERSION 3.20..3.28)

project(qtjdenticon VERSION 0.3.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui)

qt_standard_project_setup()

qt_add_plugin(qtjdenticon)

target_link_libraries(qtjdenticon PUBLIC
    Qt::Core
    Qt::Gui
)

target_sources(qtjdenticon PRIVATE
    src/identicon.h 
    src/identiconstyle.h 
    src/qtidenticon.h 
    src/qtidenticon_global.h 
    src/rendering/colortheme.h 
    src/rendering/colorutils.h 
    src/rendering/icongenerator.h 
    src/rendering/rectangle.h 
    src/rendering/renderer.h 
    src/rendering/svgpath.h 
    src/rendering/svgrenderer.h 
    src/rendering/transform.h 
    src/shapes/shape.h 
    src/shapes/shapecategory.h 
    src/shapes/shapedefinitions.h 
    src/shapes/shapeposition.h 
    src/jdenticonplugin.h 
    includes/jdenticoninterface.h
    src/identicon.cpp 
    src/qtidenticon.cpp 
    src/rendering/colortheme.cpp 
    src/rendering/colorutils.cpp 
    src/rendering/icongenerator.cpp 
    src/rendering/rectangle.cpp 
    src/rendering/svgpath.cpp 
    src/rendering/svgrenderer.cpp 
    src/rendering/transform.cpp 
    src/shapes/shape.cpp 
    src/shapes/shapecategory.cpp 
    src/shapes/shapedefinitions.cpp 
    src/shapes/shapeposition.cpp 
    src/jdenticonplugin.cpp
)

target_compile_definitions(qtjdenticon PRIVATE QT_NO_DEBUG_OUTPUT)

target_include_directories(qtjdenticon PRIVATE includes)

# See KdeInstallDirs for the QT_PLUGIN_PATH lookup logic
find_package(Qt6 COMPONENTS CoreTools CONFIG)
if (TARGET Qt6::qtpaths)
    get_target_property(_qtpaths_executable Qt6::qtpaths LOCATION)

    execute_process(
        COMMAND ${_qtpaths_executable} --qt-query QT_INSTALL_PLUGINS
        RESULT_VARIABLE return_code
        OUTPUT_VARIABLE QT_PLUGIN_PATH
    )
    if(NOT return_code EQUAL 0)
        message(FATAL_ERROR "Failed to query plugin path")
    endif()
    string(STRIP "${QT_PLUGIN_PATH}" QT_PLUGIN_PATH)
else()
    message(FATAL_ERROR "Couldn't find qtpaths executable, can't install plugin")
endif()

install(TARGETS qtjdenticon
    BUNDLE  DESTINATION .
    LIBRARY DESTINATION "${QT_PLUGIN_PATH}"
)

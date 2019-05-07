#qt modules
QT += quick qml multimedia multimediawidgets quick quickcontrols2

#we are using c++ 2011 feautures
CONFIG += c++11


#add .cpp files to the tree project
SOURCES += main.cpp \
            myparentobject.cpp

#add .h files to the tree project
HEADERS += myparentobject.h

#add resource files to the tree project
RESOURCES +=  wearable.qrc
#show all qml file in project tree, why ?
#when you edit them it will be directly
#so it force qt to rebuild qrc file and prevent some issue
OTHER_FILES +=  $$PWD/*.qml \
                $$PWD/qml/*.qml \
                $$PWD/qml/Validation/*.qml\
                $$PWD/qml/Style/*.qml\
                $$PWD/qml/Services/*.qml\
                $$PWD/qml/Reglages/*.qml\
                $$PWD/qml/Language/*.qml\
                $$PWD/qml/Help/*.qml\
                $$PWD/qml/Defauts/*.qml\
                $$PWD/qml/Contacts/*.qml\
                $$PWD/qml/Compteurs/*.qml

################################
# OUR CUSTOM SUB PROJECTS
################################
INCLUDEPATH += $$PWD/Network
include(Network/Network.pri)

INCLUDEPATH += $$PWD/Grafcet
include(Grafcet/Grafcet.pri)

INCLUDEPATH += $$PWD/GPIO
include(GPIO/GPIO.pri)
################################

# ?_? i don't know what it mean, ask QT DOC
TEMPLATE = app

#name of the executable file
TARGET = Ninette

#--------------------------------------------------------

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0



# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

QT -= gui
QT += core network

CONFIG += c++20 console
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += src/

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        src/IrcClient.cpp \
        #src/IrcClientOld.cpp \
        src/main.cpp

HEADERS += \
    src/IrcClient.hpp \
    #src/IrcClientOld.hpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


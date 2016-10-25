TEMPLATE = app

QT += core qml quick widgets sql

SOURCES += main.cpp \
    News.cpp \
    TimeLine.cpp \
    MainNews.cpp \
    Reply.cpp \
    User.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    News.h \
    TimeLine.h \
    MainNews.h \
    Reply.h \
    User.h

deployment.files += database.db
deployment.path = /assets
INSTALLS += deployment
android {
         installPrefix = /assets
     }

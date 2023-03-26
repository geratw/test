QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    creditwindow.cpp \
    defoltwindow.cpp \
    depositwindow.cpp \
    form.cpp \
    main.cpp \
    mainwindow.cpp \
    new.c \
    qcustomplot.cpp \
    resultCredit.c

HEADERS += \
    creditwindow.h \
    defoltwindow.h \
    depositwindow.h \
    form.h \
    mainwindow.h \
    new.h \
    qcustomplot.h \
    resultCredit.h

FORMS += \
    creditwindow.ui \
    defoltwindow.ui \
    depositwindow.ui \
    form.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc

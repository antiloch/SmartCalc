QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../calculate.c \
    ../leksem_creator.c \
    ../number_stack.c \
    ../static_stack.c \
    ../to_postfix_notation.c \
    graph.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ../calculate.h \
    ../leksem_creator.h \
    ../number_stack.h \
    ../static_stack.h \
    ../to_postfix_notation.h \
    graph.h \
    mainwindow.h

FORMS += \
    graph.ui \
    mainwindow.ui

TRANSLATIONS += \
    untitled_en_GB.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

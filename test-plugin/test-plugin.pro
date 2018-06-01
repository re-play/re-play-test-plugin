TEMPLATE = lib
TARGET = test-plugin
QT += qml quick
CONFIG += plugin c++11

TARGET = $$qtLibraryTarget($$TARGET)
uri = RePlay.TestPlugin

# Input
SOURCES += \
        test-plugin_plugin.cpp \
        test.cpp

HEADERS += \
        test-plugin_plugin.h \
        test.h

DISTFILES = qmldir

Debug:LIBS += -L$$OUT_PWD/../re-play-plug/Debug/ -lre-play-plug
Release:LIBS += -L$$OUT_PWD/../re-play-plug/Release/ -lre-play-plug
INCLUDEPATH += ../re-play-plug

!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
    copy_qmldir.target = $$OUT_PWD/qmldir
    copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
    copy_qmldir.commands = $(COPY_FILE) \"$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)\"
    QMAKE_EXTRA_TARGETS += copy_qmldir
    PRE_TARGETDEPS += $$copy_qmldir.target
}

qmldir.files = qmldir
unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
    qmldir.path = $$installPath
    target.path = $$installPath
    INSTALLS += target qmldir
}

SOURCES += \
    main.cpp \
    delegate.cpp


QT += widgets
QT += core
QT += gui

HEADERS += \
    delegate.h

QT += widgets
requires(qtConfig(tableview))

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/itemviews/checkboxdelegate
INSTALLS += target

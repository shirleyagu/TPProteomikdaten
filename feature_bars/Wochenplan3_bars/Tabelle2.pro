SOURCES += \
    main.cpp \
    mytable.cpp \
    delegate.cpp \
    editor.cpp \
    rating.cpp

HEADERS += \
    mytable.h \
    delegate.h \
    editor.h \
    rating.h

QT += widgets


requires(qtConfig(tablewidget))

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/itemviews/stardelegate
INSTALLS += target

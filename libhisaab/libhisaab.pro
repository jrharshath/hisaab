TEMPLATE = lib
TARGET = hisaab
CONFIG += staticlib
INCLUDEPATH += include/
HEADERS = include/utils.h \
    include/tranlogentry.h \
    include/accountsentry.h \
    include/hastags.h \
    include/entry.h \
    include/hisaabdatetime.h \
    include/hisaabratio.h
SOURCES = src/utils.cpp \
    src/tranlogentry.cpp \
    src/accountsentry.cpp \
    src/hastags.cpp \
    src/entry.cpp \
    src/hisaabdatetime.cpp \
    src/hisaabratio.cpp

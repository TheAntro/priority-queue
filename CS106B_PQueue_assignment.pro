TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cc \
    pqueuetest.cc \
    random.cc \
    pqheap.cc

HEADERS += \
    pqueue.hh \
    pqueuetest.hh \
    random.hh

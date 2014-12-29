APP_NAME = OpenGarage

CONFIG += qt warn_on cascades10

include(config.pri)

QT += network

LIBS += -lbb
LIBS += -lbbdata
LIBS += -lbbsystem

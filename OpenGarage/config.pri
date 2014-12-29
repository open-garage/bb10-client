# Config.pri file version 2.0. Auto-generated by IDE. Any changes made by user will be lost!
BASEDIR = $$quote($$_PRO_FILE_PWD_)

device {
    CONFIG(debug, debug|release) {
        profile {
            CONFIG += \
                config_pri_assets \
                config_pri_source_group1
        } else {
            CONFIG += \
                config_pri_assets \
                config_pri_source_group1
        }

    }

    CONFIG(release, debug|release) {
        !profile {
            CONFIG += \
                config_pri_assets \
                config_pri_source_group1
        }
    }
}

simulator {
    CONFIG(debug, debug|release) {
        !profile {
            CONFIG += \
                config_pri_assets \
                config_pri_source_group1
        }
    }
}

config_pri_assets {
    OTHER_FILES += \
        $$quote($$BASEDIR/assets/content/SettingsPage.qml) \
        $$quote($$BASEDIR/assets/content/TogglePage.qml) \
        $$quote($$BASEDIR/assets/helmsdeep.pem)
}

config_pri_source_group1 {
    SOURCES += \
        $$quote($$BASEDIR/src/ApplicationUI.cpp) \
        $$quote($$BASEDIR/src/api/DoorStatusRequest.cpp) \
        $$quote($$BASEDIR/src/api/OpenGarageService.cpp) \
        $$quote($$BASEDIR/src/api/ServiceCall.cpp) \
        $$quote($$BASEDIR/src/api/SystemInfosRequest.cpp) \
        $$quote($$BASEDIR/src/api/ToggleDoorRequest.cpp) \
        $$quote($$BASEDIR/src/controller/SettingsPage.cpp) \
        $$quote($$BASEDIR/src/controller/SettingsSheet.cpp) \
        $$quote($$BASEDIR/src/controller/TogglePage.cpp) \
        $$quote($$BASEDIR/src/main.cpp) \
        $$quote($$BASEDIR/src/model/DoorStatus.cpp) \
        $$quote($$BASEDIR/src/model/SystemInfos.cpp) \
        $$quote($$BASEDIR/src/model/ToggleDoor.cpp)

    HEADERS += \
        $$quote($$BASEDIR/src/ApplicationUI.hpp) \
        $$quote($$BASEDIR/src/api/DoorStatusRequest.h) \
        $$quote($$BASEDIR/src/api/OpenGarageService.h) \
        $$quote($$BASEDIR/src/api/ServiceCall.h) \
        $$quote($$BASEDIR/src/api/SystemInfosRequest.h) \
        $$quote($$BASEDIR/src/api/ToggleDoorRequest.h) \
        $$quote($$BASEDIR/src/controller/SettingsPage.h) \
        $$quote($$BASEDIR/src/controller/SettingsSheet.h) \
        $$quote($$BASEDIR/src/controller/TogglePage.h) \
        $$quote($$BASEDIR/src/model/DoorStatus.h) \
        $$quote($$BASEDIR/src/model/SystemInfos.h) \
        $$quote($$BASEDIR/src/model/ToggleDoor.h)
}

CONFIG += precompile_header

PRECOMPILED_HEADER = $$quote($$BASEDIR/precompiled.h)

lupdate_inclusion {
    SOURCES += \
        $$quote($$BASEDIR/../src/*.c) \
        $$quote($$BASEDIR/../src/*.c++) \
        $$quote($$BASEDIR/../src/*.cc) \
        $$quote($$BASEDIR/../src/*.cpp) \
        $$quote($$BASEDIR/../src/*.cxx) \
        $$quote($$BASEDIR/../src/api/*.c) \
        $$quote($$BASEDIR/../src/api/*.c++) \
        $$quote($$BASEDIR/../src/api/*.cc) \
        $$quote($$BASEDIR/../src/api/*.cpp) \
        $$quote($$BASEDIR/../src/api/*.cxx) \
        $$quote($$BASEDIR/../src/controller/*.c) \
        $$quote($$BASEDIR/../src/controller/*.c++) \
        $$quote($$BASEDIR/../src/controller/*.cc) \
        $$quote($$BASEDIR/../src/controller/*.cpp) \
        $$quote($$BASEDIR/../src/controller/*.cxx) \
        $$quote($$BASEDIR/../src/model/*.c) \
        $$quote($$BASEDIR/../src/model/*.c++) \
        $$quote($$BASEDIR/../src/model/*.cc) \
        $$quote($$BASEDIR/../src/model/*.cpp) \
        $$quote($$BASEDIR/../src/model/*.cxx) \
        $$quote($$BASEDIR/../assets/*.qml) \
        $$quote($$BASEDIR/../assets/*.js) \
        $$quote($$BASEDIR/../assets/*.qs) \
        $$quote($$BASEDIR/../assets/content/*.qml) \
        $$quote($$BASEDIR/../assets/content/*.js) \
        $$quote($$BASEDIR/../assets/content/*.qs)

    HEADERS += \
        $$quote($$BASEDIR/../src/*.h) \
        $$quote($$BASEDIR/../src/*.h++) \
        $$quote($$BASEDIR/../src/*.hh) \
        $$quote($$BASEDIR/../src/*.hpp) \
        $$quote($$BASEDIR/../src/*.hxx)
}

TRANSLATIONS = $$quote($${TARGET}.ts)
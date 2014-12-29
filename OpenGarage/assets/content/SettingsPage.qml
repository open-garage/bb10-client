import bb.cascades 1.2

Container {
    Header {
        title: qsTr("Server Settings") + Retranslate.onLanguageChanged
    }
    StandardListItem {
        objectName: "serverHostItem"
        gestureHandlers: TapHandler {
            onTapped: controller.onServerHostTapped()
        }

        title: qsTr("Host") + Retranslate.onLanguageChanged
    }
    StandardListItem {
        objectName: "serverPortItem"
        gestureHandlers: TapHandler {
            onTapped: controller.onServerPortTapped()
        }

        title: qsTr("Port") + Retranslate.onLanguageChanged
    }
    StandardListItem {
        objectName: "apiTokenItem"
        gestureHandlers: TapHandler {
            onTapped: controller.onApiTokenTapped()
        }

        title: qsTr("API Token") + Retranslate.onLanguageChanged
    }

    Header {
        topMargin: 15

        title: qsTr("About Server") + Retranslate.onLanguageChanged
    }
    StandardListItem {
        objectName: "serverNameItem"

        title: qsTr("Name") + Retranslate.onLanguageChanged
        description: "?"
    }
    StandardListItem {
        objectName: "serverVersionItem"

        title: qsTr("Version") + Retranslate.onLanguageChanged
        description: "?"
    }
}

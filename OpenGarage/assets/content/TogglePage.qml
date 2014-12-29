import bb.cascades 1.2

Container {
    layout: DockLayout {
    }
    leftPadding: 15
    topPadding: 15
    bottomPadding: 15
    rightPadding: 15

    Container {
        horizontalAlignment: HorizontalAlignment.Center
        verticalAlignment: VerticalAlignment.Center
        layout: StackLayout {
            orientation: LayoutOrientation.TopToBottom
        }

        Container {
            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight
            }

            Label {
                text: qsTr("Status:") + Retranslate.onLanguageChanged
            }
            Label {
                objectName: "statusLabel"

                text: qsTr("unknown") + Retranslate.onLanguageChanged
            }
        }
        Button {
            text: qsTr("Open") + Retranslate.onLanguageChanged

            enabled: controller.isOnline && ! controller.isTogglingDoor
            onClicked: controller.openDoor()
        }
        Button {
            text: qsTr("Close") + Retranslate.onLanguageChanged

            enabled: controller.isOnline && ! controller.isTogglingDoor
            onClicked: controller.closeDoor()
        }
    }
}

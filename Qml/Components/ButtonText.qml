/// @author M. A. Serebrennikov
import QtQuick 2.15
import "qrc:/"


Item {
    id: buttonText

    property alias text: textItem.text
    property alias textColor: textItem.color
    property alias backgroundColor: background.color
    property color hoveredColor: Colors.ribbonMenuHovered

    signal clicked()

    implicitWidth: 2*Consts.margin + textItem.width
    implicitHeight: Consts.buttonHeight
    opacity: enabled ? 1.0 : 0.5

    Rectangle {
        id: background
        color: Colors.headerBackground
        anchors.fill: parent
    }

    Text {
        id: textItem

        color: Colors.ribbonMenuText
        font.pixelSize: Consts.fontNormal
        anchors.centerIn: parent
    }

    MouseArea {
        id: mouseArea

        acceptedButtons: Qt.LeftButton
        hoverEnabled: true
        anchors {
            fill: parent
            margins: Consts.marginMouseArea
        }

        onClicked: {
            buttonText.clicked();
        }
    }

    states: [
        State {
            name: "hovered"
            when: mouseArea.containsMouse
            PropertyChanges {
                target: background
                color: hoveredColor
            }
        }
    ]
    transitions: [
        Transition {
            ColorAnimation {
                duration: 300
            }
        }
    ]
}

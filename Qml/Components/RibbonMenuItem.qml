/// @author M. A. Serebrennikov
import QtQuick 2.15
import "qrc:/"
import "qrc:/Components"

Item {
    id: ribbonMenuItem

    property alias text: textItem.text
    property alias backgroundColor: background.color

    property Item contentItem
    property int index: 0
    property bool isCurrent: index === parent.currentIndex

    signal clicked()

    width: 2*Consts.margin20 + textItem.width
    height: Consts.headerHeight

    Rectangle {
        id: background
        color: Colors.headerBackground
        anchors.fill: parent
    }

    Text {
        id: textItem

        color: Colors.ribbonMenuText
        font {
            capitalization: Font.AllUppercase
            pixelSize: Consts.fontNormal
        }
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
            ribbonMenuItem.parent.currentIndex = index
            ribbonMenuItem.clicked();
        }
    }

    states: [
        State {
            name: "current"
            when: ribbonMenuItem.isCurrent
            PropertyChanges {
                target: background
                color: Colors.panelBackground
            }
            PropertyChanges {
                target: textItem
                color: Colors.ribbonMenuTextCurrent
            }
        }
        ,State {
            name: "hovered"
            when: mouseArea.containsMouse
            PropertyChanges {
                target: background
                color: Colors.ribbonMenuHovered
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

    Component.onCompleted: {
        if (contentItem) {
            contentItem.visible = Qt.binding(()=>{ return isCurrent; });
            contentItem.parent = parent.contentContainer;
        }
    }
}

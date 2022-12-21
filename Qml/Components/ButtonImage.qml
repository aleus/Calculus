/// @author M. A. Serebrennikov
import QtQuick 2.15
import "qrc:/"

Item {
    id: buttonImage

    property alias imageSource: image.source
    property alias colorHovered: backgroundHovered.color
    property alias hovered: mouseArea.containsMouse
    signal clicked

    implicitHeight: Consts.buttonHeight

    Rectangle {
        id: backgroundHovered

        color: Colors.transparent
        visible: mouseArea.containsMouse
        anchors.fill: parent
    }

    Image {
        id: image
        anchors.centerIn: parent
        width: 13*dp
        height: 13*dp
        sourceSize: Qt.size(width, height)
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
            buttonImage.clicked();
        }
    }
}

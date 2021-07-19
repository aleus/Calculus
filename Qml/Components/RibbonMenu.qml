/// @author M. A. Serebrennikov
import QtQuick 2.15
import "qrc:/"

Item {
    id: ribbonMenu

    default property alias menuContainer: tabRow.children

    height: header.height + contentContainer.height
    anchors {
        left: parent.left
        right: parent.right
    }

    Rectangle {
        id: header

        color: Colors.headerBackground
        height: Consts.headerHeight
        anchors {
            left: parent.left
            right: parent.right
        }

        Image {
            id: saveButton
            source: "qrc:/Icons/FakeSave.png"
            height: Consts.headerHeight
        }

        Row {
            id: tabRow

            property int currentIndex: -1
            property alias contentContainer: contentContainer

            height: Consts.headerHeight
            anchors.left: saveButton.right

            Component.onCompleted: {
                for (var i in children) {
                    children[i].index = i;
                }
                currentIndex = 0;
            }
        } // Row { id: tabRow
    } // Rectangle { id: header

    Rectangle {
        id: contentContainer

        color: Colors.panelBackground
        height: Consts.ribbonMenuContentHeight
        anchors {
            top: header.bottom
            left: parent.left
            right: parent.right
        }
    }
}

/// @author M. A. Serebrennikov
import QtQuick 2.15
import QtQuick.Window 2.15
import "qrc:/"
import "qrc:/Components"

Rectangle {
    id: header

    readonly property int leftContentWidth: titleItem.x + titleItem.width

    color: Colors.headerBackground
    height: Consts.headerHeight
    anchors {
        top: parent.top
        left: parent.left
        right: parent.right
    }

    Image {
        id: logo

        source: "qrc:/Icons/Logo.png"
        width: 20*dp
        height: 20*dp
        anchors {
            top: parent.top
            left: parent.left
            topMargin: 6*dp
            leftMargin: 10*dp
        }
    }

    Text {
        id: titleItem

        text: qsTr("Calculus")
        color: Colors.white
        font.pixelSize: Consts.fontNormal
        renderType: Text.NativeRendering
        anchors {
            left: logo.right
            leftMargin: 7*dp
            verticalCenter: parent.verticalCenter
        }
    }
}

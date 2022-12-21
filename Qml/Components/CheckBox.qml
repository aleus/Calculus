import QtQuick 2.15
import QtQuick.Controls 2.15 as Controls
import "qrc:/"

Controls.CheckBox {
    id: checkBox

    hoverEnabled: true

    indicator: Rectangle {
        id: indicator

        implicitWidth: 17*dp
        implicitHeight: 17*dp
        x: checkBox.leftPadding
        y: parent.height / 2 - height / 2
        radius: 3*dp
        border {
            width: 1
            color: Colors.control
        }

        Image {
            id: icon

            source: "qrc:/Icons/FakeChecked.png"
            width: 11*dp
            height: 11*dp
            anchors.centerIn: parent
            visible: false
        }
    }

    contentItem: Text {
         text: checkBox.text
         font.pixelSize: Consts.fontNormal
         opacity: enabled ? 1.0 : 0.3
         color: Colors.text
         verticalAlignment: Text.AlignVCenter
         leftPadding: checkBox.indicator.width + checkBox.spacing
     }

    states: [
        State {
            name: "checked"
            when: checkBox.checked
            PropertyChanges {
                target: indicator
                color: Colors.controlActive
                border.color: Colors.controlActive
            }
            PropertyChanges {
                target: icon
                visible: true
            }
        }
        , State {
            name: "hovered"
            when: checkBox.hovered
            PropertyChanges {
                target: indicator
                border.color: Colors.controlActive
            }
        }
    ]
}

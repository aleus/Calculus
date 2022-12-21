import QtQuick 2.15
import QtQuick.Controls 2.15 as Controls
import "qrc:/"
import "qrc:/Components"

ComboBox {
    id: pointsComboBox

    width: 140*dp
    textRole: "text"
    valueRole: "value"
    currentIndex: chartItem.pointSize
    model: [
        { value: 0, text: qsTr("None") },
        { value: 1, text: qsTr("1 px") },
        { value: 2, text: qsTr("2 px") },
        { value: 3, text: qsTr("3 px") },
        { value: 4, text: qsTr("4 px") },
        { value: 5, text: qsTr("5 px") },
        { value: 6, text: qsTr("6 px") }
    ]

    contentItem: Row {
        Item { width:5*dp; height: 1}

        Rectangle {
            color: Colors.orange
            width: 10*dp
            height: 10*dp
            radius: height/2
            anchors.verticalCenter: parent.verticalCenter
        }
        Text {
            text: qsTr("Points - ") + pointsComboBox.displayText
            font.pixelSize: Consts.fontNormal
            opacity: enabled ? 1.0 : 0.3
            color: Colors.text
            leftPadding: pointsComboBox.indicator.width + pointsComboBox.spacing
            anchors.verticalCenter: parent.verticalCenter
        }
    }

    delegate: Controls.ItemDelegate {
        width: pointsComboBox.width
        implicitHeight: Consts.ribbonButtonHeight
        contentItem: Row {
            spacing: Consts.margin
            Item {
                width: 10*dp
                height: 10*dp
                visible: modelData.value > 0

                Rectangle {
                    color: Colors.orange
                    width: modelData.value*2
                    height: width
                    radius: height/2
                    anchors.centerIn: parent
                }
            }

            Text {
                text: modelData.value > 0
                      ? modelData.text
                      : qsTr("None")
                color: Colors.text
                font.pixelSize: Consts.fontNormal
                elide: Text.ElideRight
                anchors.verticalCenter: parent.verticalCenter
            }
        }
        highlighted: pointsComboBox.highlightedIndex === index
    }

    onActivated: {
        chartItem.pointSize = currentValue;
    }
}

/// @author M. A. Serebrennikov
import QtQuick 2.15
import QtQuick.Controls 2.15 as Controls
import "qrc:/"
import "qrc:/Components"

RibbonMenuItem {
    property var chartItem
    property var chartEntity

    text: qsTr("FILE")
    backgroundColor: Colors.blue3
    contentItem: Row {
        spacing: Consts.spacing

        Column {
            spacing: Consts.spacing

            anchors {
                top: parent.top
                topMargin: Consts.margin
            }

            PointsComboBox {
                id: pointsComboBox
                anchors {
                    left: parent.left
                    leftMargin: Consts.margin
                }
            } // ComboBox { id: pointsComboBox
        }

        Column {
            anchors {
                top: parent.top
                topMargin: Consts.margin
            }

            Controls.CheckBox {
                id: hasSinCheckBox

                text: qsTr("Has sin")
                checked: chartEntity.hasSin
                font.pixelSize: Consts.fontNormal
                height: pointsComboBox.height
                onCheckedChanged: {
                    if (checked !== chartEntity.hasSin) {
                        chartEntity.hasSin = checked;
                    }
                }
            }

            Controls.CheckBox {
                id: hasRandCheckBox

                text: qsTr("Has rand")
                checked: chartEntity.hasRand
                font.pixelSize: Consts.fontNormal
                height: pointsComboBox.height
                onCheckedChanged: {
                    if (checked !== chartEntity.hasRand) {
                        chartEntity.hasRand = checked;
                    }
                }
            }
        } // Column {
    } // contentItem: Item {
}

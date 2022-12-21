/// @author M. A. Serebrennikov
import QtQuick 2.15
import QtQuick.Controls 2.15 as Controls
import "qrc:/"

Controls.ComboBox {
    id: comboBox

    hoverEnabled: true

    delegate: Controls.ItemDelegate {
        width: comboBox.width
        implicitHeight: Consts.ribbonButtonHeight
        contentItem: Text {
            text: modelData[textRole]
            color: Colors.text
            font.pixelSize: Consts.fontNormal
            elide: Text.ElideRight
            verticalAlignment: Text.AlignVCenter
        }
        highlighted: comboBox.highlightedIndex === index
    }

    indicator: Image {
        source: "qrc:/Icons/FakeIndicator.png"
        x: comboBox.width - width - comboBox.rightPadding
        y: comboBox.topPadding + (comboBox.availableHeight - height) / 2
        width: 10*dp
        height: 6*dp
    }

    contentItem: Text {
         text: comboBox.displayText
         font.pixelSize: Consts.fontNormal
         opacity: enabled ? 1.0 : 0.3
         color: Colors.text
         verticalAlignment: Text.AlignVCenter
         leftPadding: comboBox.indicator.width + comboBox.spacing
     }

    background: Rectangle {
        id: background

        implicitWidth: 120*dp
        implicitHeight: Consts.ribbonButtonHeight
        color: Colors.panelBackground
        states: [
            State {
                name: "Hovered"
                when: comboBox.hovered
                PropertyChanges {
                    target: background
                    color: Colors.controlHovered
                }
            }
        ]
    }

    popup: Controls.Popup {
         y: comboBox.height - 1
         width: comboBox.width
         implicitHeight: contentItem.implicitHeight
         padding: 1

         contentItem: ListView {
             clip: true
             implicitHeight: contentHeight+2
             model: comboBox.popup.visible ? comboBox.delegateModel : null
             currentIndex: comboBox.highlightedIndex

             Controls.ScrollIndicator.vertical: Controls.ScrollIndicator { }
         }

         background: Rectangle {
             radius: 2
             border {
                 width: 1
                 color: Colors.gray3
             }
         }
     }
}

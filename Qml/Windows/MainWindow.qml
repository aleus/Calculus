/// @author M. A. Serebrennikov
import QtQuick 2.15
import QtQuick.Window 2.15
import QtShark.Window 1.0
import Rogii 1.0
import "qrc:/Windows/MainWindow"
import "qrc:/Components"
import "qrc:/"

Window {
    id: mainWindow

    width: 1000
    height: 700
    visible: true
    title: qsTr("Calculus")
    flags: Qt.Window | Qt.FramelessWindowHint

    FramelessHelper {
        id: framelessHelper

        titleBarHeight: Consts.headerHeight

        Component.onCompleted: {
            addIncludeItem(header);
            addExcludeItem(headerButtons);
        }
    }

    Header {
        id: header
    }

    HeaderButtons {
        id: headerButtons
    }

    RibbonMenu {
        id: ribbonMenu
        anchors.top: header.bottom

        FileMenu {
            chartItem: chartItemMovable.currentChart
        }
        RibbonMenuItem {
            id: viewItem
            text: qsTr("VIEW")
        }
        RibbonMenuItem {
            text: qsTr("DATA")
        }
        RibbonMenuItem {
            text: qsTr("MODE")
        }
        RibbonMenuItem {
            text: qsTr("PYTHON")
        }
    }

    ChartItemMovable {
        id: chartItemMovable

        anchors {
            top: ribbonMenu.bottom
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }
    }
}

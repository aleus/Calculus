/// @author M. A. Serebrennikov
import QtQuick 2.15
import QtQuick.Window 2.15
import QtShark.Window 1.0
import Sp 1.0
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
            addExcludeItem(undoRedoButtons);
        }
    }

    Header {
        id: header
    }

    Row {
        id: undoRedoButtons

        anchors {
            left: header.left
            leftMargin: header.leftContentWidth + Consts.margin
            verticalCenter: header.verticalCenter
        }
        height: undoButton.height

        ButtonText {
            id: undoButton
            text: qsTr("Undo")
            textColor: Colors.white
            enabled: UndoStack.canUndo
            onClicked: {
                UndoStack.undo();
            }
        }

        ButtonText {
            id: redoButton
            text: qsTr("Redo")
            textColor: Colors.white
            enabled: UndoStack.canRedo
            onClicked: {
                UndoStack.redo();
            }
        }
    }

    HeaderButtons {
        id: headerButtons
    }

    RibbonMenu {
        id: ribbonMenu
        anchors.top: header.bottom

        FileMenu {
            chartItem: tripleChart.currentChart
            chartEntity: tripleChart.chartEntity
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

    TripleChart {
        id: tripleChart

        anchors {
            top: ribbonMenu.bottom
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }
    }
}

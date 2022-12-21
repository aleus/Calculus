/// @author M. A. Serebrennikov
import QtQuick 2.15
import QtQuick.Window 2.15
import "qrc:/Components"
import "qrc:/"

Row {
    id: headerButtons

    height: Consts.buttonHeight
    spacing: 1*dp
    anchors {
        right: parent.right
    }

    ButtonImage {
        width: Consts.headerButtonWidth
        imageSource: !hovered
                     ? "qrc:/Icons/Minimize.png"
                     : "qrc:/Icons/MinimizeHovered.png"
        colorHovered: Colors.headerButtonHovered
        onClicked: {
            Window.window.showMinimized();
        }
    }

    ButtonImage {
        width: Consts.headerButtonWidth
        imageSource: !hovered
                     ? "qrc:/Icons/Normalize.png"
                     : "qrc:/Icons/NormalizeHovered.png"
        colorHovered: Colors.headerButtonHovered
        visible: Window.visibility === Window.Maximized
        onClicked: {
            Window.window.showNormal();
        }
    }


    ButtonImage {
        width: Consts.headerButtonWidth
        imageSource: !hovered
                     ? "qrc:/Icons/Maximize.png"
                     : "qrc:/Icons/MaximizeHovered.png"
        colorHovered: Colors.headerButtonHovered
        visible: Window.visibility === Window.Windowed
        onClicked: {
            Window.window.showMaximized();
        }
    }

    ButtonImage {
        width: Consts.headerButtonWidth
        imageSource: !hovered
                     ? "qrc:/Icons/Exit.png"
                     : "qrc:/Icons/ExitHovered.png"
        colorHovered: Colors.headerButtonHoveredRed
        onClicked: {
            Qt.quit();
        }
    }
}

/// @author M. A. Serebrennikov
pragma Singleton

import QtQuick 2.15

QtObject {
    readonly property color blue0: "#536b88"
    readonly property color blue1: "#8798ac"
    readonly property color blue2: "#42566d"
    readonly property color blue3: "#4b607a"
    readonly property color blue4: "#4795f1"
    readonly property color blue5: "#d1dae4"
    readonly property color red0: "#e81123"
    readonly property color white: "#ffffff"
    readonly property color gray0: "#f2f2f2"
    readonly property color gray1: "#333333"
    readonly property color gray2: "#b3b3b3"
    readonly property color gray3: "#d2d2d2"
    readonly property color orange: "#fd8c2f"
    readonly property color black: "#000000"
    readonly property color transparent: "transparent"

    readonly property color headerBackground: blue0
    readonly property color headerButtonHovered: blue1
    readonly property color headerButtonHoveredRed: red0
    readonly property color headerText: white

    readonly property color ribbonMenuText: white
    readonly property color ribbonMenuTextCurrent: blue0
    readonly property color ribbonMenuHovered: blue2

    readonly property color panelBackground: gray0

    readonly property color control: gray2
    readonly property color controlActive: blue4
    readonly property color controlHovered: blue5
    readonly property color text: gray1
}

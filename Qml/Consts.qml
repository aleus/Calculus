/// @author M. A. Serebrennikov
pragma Singleton

import QtQuick 2.15

Item {
    readonly property int spacing: 5*dp
    readonly property int margin: 10*dp
    readonly property int margin20: 20*dp
    readonly property int marginMouseArea: -5*dp

    readonly property int fontNormal: 14*dp

    readonly property int buttonHeight: 32*dp
    readonly property int headerHeight: 32*dp
    readonly property int headerButtonWidth: 45*dp

    readonly property int ribbonMenuContentHeight: 100*dp
    readonly property int ribbonButtonHeight: 32*dp
}

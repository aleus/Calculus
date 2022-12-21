/// @author M. A. Serebrennikov
import QtQuick 2.15

Item {
    id: root

    Loader {
        id: mainWindowLoader

        source: "qrc:/Windows/MainWindow.qml"
        onLoaded: {
            item.visible = true;
        }
    }
}

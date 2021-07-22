/// @author M. A. Serebrennikov
import QtQuick 2.15
import Rogii 1.0
import "qrc:/"

Item {
    id: tripleChart

    property var currentChart: middleChart
    property alias topChart: topChart
    property alias middleChart: middleChart
    property alias rightChart: rightChart
    property real lastX
    property real lastY

    ChartItem {
        id: topChart

        chartData: ExampleChartManager.top
        height: 0.3 * parent.height
        anchors {
            top: parent.topr
            left: parent.left
            right: rightChart.left
        }

        MouseArea {
            anchors.fill: parent

            onPressed: {
                if (mouse.button == Qt.LeftButton) {
                    lastX = mouse.x;
                    lastY = mouse.y;
                }
                currentChart = topChart;
            }

            onPositionChanged: {
                if (mouse.buttons & Qt.LeftButton) {
                    let dx = mouse.x-lastX;
                    let dy = mouse.y-lastY;
                    lastX = mouse.x;
                    lastY = mouse.y;

                    topChart.xShift += dx;
                    topChart.yShift += dy;
                    middleChart.xShift += dx;

                    mouse.accepted = true;
                }
            }

            onWheel: {
                topChart.xScale += wheel.angleDelta.y*0.001;
                middleChart.xScale += wheel.angleDelta.y*0.001;
                rightChart.xScale += wheel.angleDelta.y*0.001;
            }
        }
    } // ChartItem { id: topChart

    ChartItem {
        id: middleChart

        chartData: ExampleChartManager.middle
        anchors {
            top: topChart.bottom
            left: parent.left
            right: rightChart.left
            bottom: parent.bottom
        }

        MouseArea {
            anchors.fill: parent

            onPressed: {
                if (mouse.button == Qt.LeftButton) {
                    lastX = mouse.x;
                    lastY = mouse.y;
                }
                currentChart = middleChart;
            }

            onPositionChanged: {
                if (mouse.buttons & Qt.LeftButton) {
                    let dx = mouse.x-lastX;
                    let dy = mouse.y-lastY;
                    lastX = mouse.x;
                    lastY = mouse.y;

                    middleChart.xShift += dx;
                    middleChart.yShift += dy;
                    rightChart.yShift += dy;
                    topChart.xShift += dx;

                    mouse.accepted = true;
                }
            }

            onWheel: {
                topChart.yScale += wheel.angleDelta.y*0.001;
                middleChart.yScale += wheel.angleDelta.y*0.0005;
                rightChart.yScale += wheel.angleDelta.y*0.0005;

                topChart.xScale += wheel.angleDelta.y*0.001;
                middleChart.xScale += wheel.angleDelta.y*0.001;
                rightChart.xScale += wheel.angleDelta.y*0.0001;
            }
        }
    } // ChartItem { id: middleChart

    ChartItem {
        id: rightChart

        chartData: ExampleChartManager.right
        width: 0.3 * parent.width
        anchors {
            top: topChart.bottom
            right: parent.right
            bottom: parent.bottom
        }

        MouseArea {
            anchors.fill: parent

            onPressed: {
                if (mouse.button == Qt.LeftButton) {
                    lastX = mouse.x;
                    lastY = mouse.y;
                }
                currentChart = rightChart;
            }

            onPositionChanged: {
                if (mouse.buttons & Qt.LeftButton) {
                    let dx = mouse.x-lastX;
                    let dy = mouse.y-lastY;
                    lastX = mouse.x;
                    lastY = mouse.y;

                    rightChart.xShift += dx;
                    rightChart.yShift += dy;
                    middleChart.yShift += dy;

                    mouse.accepted = true;
                }
            }

            onWheel: {
                topChart.yScale += wheel.angleDelta.y*0.001;
                middleChart.yScale += wheel.angleDelta.y*0.001;
                rightChart.yScale += wheel.angleDelta.y*0.001;
            }
        }
    } // ChartItem { id: rightChart

    // Рамка-крест
    Rectangle {
        color: "transparent"
        border {
            width: 1
            color: Colors.gray3
        }
        width: parent.width
        height: 1
        anchors.top: middleChart.top
    }

    Rectangle {
        color: "transparent"
        border {
            width: 1
            color: Colors.gray3
        }
        width: 1
        height: parent.height
        anchors.right: middleChart.right
    }
}

import QtQuick 2.8
import Qt.labs.calendar 1.0
import Qt.labs.folderlistmodel 2.2
import QtQuick.Controls 2.1
import QtPositioning 5.8
import QtQuick.Layouts 1.3

Rectangle {
    id: rectangle
    property alias textEdit: textEdit

    width: 480
    height: 600
    property alias close: close
    property alias rectangle1: rectangle1
    property alias button_1: button_1

    ColumnLayout {
        id: columnLayout
        anchors.fill: parent

        TextEdit {
            id: textEdit
            y: 20
            width: 400
            height: 180
            text: qsTr("Enter some text...")
            Layout.alignment: Qt.AlignLeft | Qt.AlignBottom
            Layout.preferredWidth: 3
            Layout.fillHeight: false
            Layout.minimumWidth: 400
            Layout.fillWidth: false
            Layout.minimumHeight: 100
            anchors.horizontalCenter: parent.horizontalCenter
            textFormat: Text.RichText
            font.pointSize: 11
            transformOrigin: Item.Center
            verticalAlignment: Text.AlignVCenter
            anchors.top: parent.top
            anchors.topMargin: 66
            Rectangle {
                id: rectangle1
                anchors.margins: -10
                color: "transparent"
                anchors.rightMargin: -10
                anchors.bottomMargin: -10
                anchors.leftMargin: -10
                anchors.topMargin: -10
                anchors.fill: parent
                border.width: 1
            }
        }

        Button {
            id: button_1
            width: 480
            height: 180
            text: qsTr("Button")
            Layout.fillHeight: false
            Layout.minimumHeight: 140
            Layout.fillWidth: true
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Button {
            id: close
            width: 480
            height: 180
            text: "Close"
            Layout.fillHeight: false
            Layout.fillWidth: true
            Layout.minimumHeight: 140
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: parent.horizontalCenter
            scale: 1
            spacing: 0
            checked: false
            checkable: false
            highlighted: false
        }
    }
}

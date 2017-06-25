import QtQuick 2.8
import QtQuick.Layouts 1.0
import QtQuick.Window 2.2
import QtQuick.Controls 2.1
import QtPositioning 5.8
import QtLocation 5.8


ApplicationWindow {
    id: window
    visible: true
    width: 480
    height: 600
    title: qsTr("Test for connect")

    Connections{
        target: appCore

        onRes:{
            console.log(qsTr(result))
            mainForm.slotRes(result)
//            title = qsTr(result)
        }
    }
    Item{
        id: item

        signal itemSignal()

    }

    header: ToolBar {
        RowLayout {
            spacing: 20
            anchors.fill: parent


            Item { Layout.fillWidth: true }
            ToolButton{
                id: menuButton
                contentItem: Image{
                    anchors.centerIn: parent
                     source: "qrc:/images/menu_icon.png"
                }

                text:"share"

                onClicked: menu.open()

                Menu {
                    id: menu
                    y: menuButton.height*3/4

                    MenuItem {
                        text: "Close"
                        onClicked:{
                            window.close()
//                            stack.push(saveAsView);
//                            var item = stack.currentItem;
//                            item.setFileName(generateTrackName());
//                            saveConnection.target = item;
                        }

                    }
                }
            }
        }
    }


    MainForm {

        function slotRes(mess){
            textEdit.text = mess
        }
        id: mainForm
        objectName: "mainForm"
        signal butt_cl()

        button_1.onClicked: {
            butt_cl()
        }

        close.onClicked: {
            window.close();
        }

        anchors.fill: parent
//        mouseArea.onClicked: {
//            console.log(qsTr('Clicked on background. Text: "' + textEdit.text + '"'))
//        }
    }

}

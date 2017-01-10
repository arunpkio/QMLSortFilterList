import QtQuick 2.4
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.0
import QtQuick.Controls.Styles 1.2

ApplicationWindow {
    id: appWindow
    visible: true
    width: 320
    height: 480
    color: "#6bdce4"
    property int margin: 12

    ColumnLayout {
        id: mainLayout
        anchors.fill: parent
        anchors.margins: margin

        Rectangle{
            color: "#6bdce4"
            Layout.fillWidth: true
            height: 40
            z: 2
            RowLayout {
                id: rowLayout
                anchors.fill: parent
                anchors.centerIn: parent
                TextField {
                    placeholderText: "Type here.."
                    Layout.fillWidth: true
                    font.pointSize: 12
                    style: TextFieldStyle {
                        textColor: "black"
                        background: Rectangle {
                            radius: 5
                            implicitWidth: 100
                            implicitHeight: 30
                            border.color: "#6bdce4"
                            border.width: 1
                        }
                    }
                    onTextChanged: {
                        filterModel.setFilterString(text);
                    }
                }
                CheckBox {
                    text: "Descending"
                    onCheckedChanged:{
                        filterModel.setSortOrder(checked)
                    }
                    style: CheckBoxStyle {
                        label: Text {
                            color: "white"
                            text: "Descending"
                            font.pointSize: 12
                        }
                        indicator: Rectangle {
                            implicitWidth: 20
                            implicitHeight: 20
                            radius: 3
                            border.color: control.activeFocus ? "darkblue" : "gray"
                            border.width: 1
                            Rectangle {
                                visible: control.checked
                                color: "#555"
                                border.color: "#333"
                                radius: 1
                                anchors.margins: 4
                                anchors.fill: parent
                            }
                        }
                    }
                }
            }
        }

        ListView {
            id: view
            model: filterModel
            Layout.minimumHeight: 25
            Layout.fillHeight: true
            Layout.fillWidth: true
            cacheBuffer: 100
            spacing: 10

            delegate: Rectangle{
                width: parent.width
                radius: 5
                anchors.horizontalCenter: parent.horizontalCenter
                height: 40
                color: Qt.lighter("#6bdce4", 0.8)
                Text {
                    id: nameTxt
                    text: name
                    font.pointSize: 12
                    color: "#FFFFFF"
                    anchors.left: parent.left
                    anchors.leftMargin: 20
                    anchors.verticalCenter: parent.verticalCenter
                }
            }
        }
    }
}

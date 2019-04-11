/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/




import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.0
import QtQuick 2.7
import Qt.labs.settings 1.0
import "../Style"

Item {
    width: 800


    SwipeView {
        id: svSettingsContainer

        anchors.fill: parent

        Item {
            id: settingsPage1
            visible: true



            Rectangle{
                 id:marhe
                 x: 770
                 y: 40
                 width: 30
                 height: 30
                 color: grafcet.HMarche == true ? "green" : "red"
             }



            Switch {
                id: switchEtiq
                x: 525
                y: 83
                text: qsTr("Etiq")
                hoverEnabled: true
                enabled: true
                property bool checkeEtiq: switchEtiq.checked
                checked: checkeEtiq == true ? grafcet.HEtiq =1 : grafcet.HEtiq=0
            }


            Switch {
                id: switchContreEtiq
                x: 525
                y: 173
                text: qsTr("ContreEtiq")
                hoverEnabled: true
                enabled: true
                property bool checkeContreEtiq: switchContreEtiq.checked
                checked: checkeContreEtiq == true ? grafcet.HContreEtiq =1 : grafcet.HContreEtiq=0
            }


            Switch {
                id: switchEtiqContreEtiq
                x: 525
                y: 263
                text: qsTr("EtiqContreEtiq")
                hoverEnabled: true
                enabled: true
                property bool checkeEtiqContreEtiq: switchEtiqContreEtiq.checked

                checked: checkeEtiqContreEtiq == true ? grafcet.HEtiqContreEtiq =1 : grafcet.HEtiqContreEtiq=0
            }

            Text {
                id: etiquette
                x: 165
                y: 85
                text: qsTr("ETIQUETTE")
                visible: true
                font.pixelSize: 30
            }

            Text {
                id: contreetiquette
                x: 165
                y: 175
                text: qsTr("CONTRE ETIQUETTE")
                font.pixelSize: 30
            }

            Text {
                id: etiqContreEtiq
                x: 165
                y: 265
                text: qsTr("ETIQ CONTRE ETIQ")
                font.pixelSize: 30
            }

            Rectangle{
                 id:etiq
                 x: 770
                 y: 88
                 width: 30
                 height: 30
                 color: grafcet.HEtiq == true ? "green" : "red"
             }
            Rectangle{
                 id:ontreEtiq
                 x: 770
                 y: 178
                 width: 30
                 height: 30
                 color: grafcet.HContreEtiq == true ? "green" : "red"
             }
            Rectangle{
                 id:tiqContreEtiq
                 x: 770
                 y: 268
                 width: 30
                 height: 30
                 color: grafcet.HEtiqContreEtiq == true ? "green" : "red"
             }




        }

        Item {
            id: settingsPage2
            visible: true

            Switch {
                id: switchRepEtiq
                x: 525
                y: 83
                text: qsTr("RepEtiq")
                visible: true
                hoverEnabled: true
                enabled: true
                property bool checkeRepEtiq: switchRepEtiq.checked
                checked: checkeRepEtiq == true ? grafcet.HRepEtiq =1 : grafcet.HRepEtiq=0
            }



            Switch {
                id: switchRepCran
                x: 525
                y: 173
                text: qsTr("RepCran")
                hoverEnabled: true
                enabled: true
                property bool checkeRepCran: switchRepCran.checked

                checked: checkeRepCran == true ? grafcet.HRepCran =1 : grafcet.HRepCran=0
            }





            Text {
                id: epEtiq
                x: 165
                y: 85
                text: qsTr("REPERAGE ETIQUETTE")
                visible: true
                font.pixelSize: 30
            }

            Text {
                id: repCran
                x: 165
                y: 175
                text: qsTr("REPERAGE CRAN")
                font.pixelSize: 30
            }

            Rectangle{
                 id:repEtiq
                 x: 770
                 y: 88
                 width: 30
                 height: 30
                 color: grafcet.HRepEtiq == true ? "green" : "red"
             }
            Rectangle{
                 id:epCran
                 x: 770
                 y: 178
                 width: 30
                 height: 30
                 color: grafcet.HRepCran == true ? "green" : "red"
             }


        }

        Settings {


           // property alias checkeMarche: switchMarche.checked
            property alias checkeRepEtiq: switchRepEtiq.checked
            property alias checkeRepCran: switchRepCran.checked
            property alias checkeEtiq: switchEtiq.checked
            property alias checkeContreEtiq: switchContreEtiq.checked
            property alias checkeEtiqContreEtiq: switchEtiqContreEtiq.checked


        }
   }

    PageIndicator {
        y: 412
        anchors.horizontalCenterOffset: 0
        anchors.bottomMargin: 48
        count: svSettingsContainer.count
        currentIndex: svSettingsContainer.currentIndex

        anchors.bottom: svSettingsContainer.bottom
        anchors.horizontalCenter: parent.horizontalCenter
    }
}

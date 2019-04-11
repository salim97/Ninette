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

import QtQuick 2.8
import QtQuick.Controls 2.1 as QQC2
import "Style"
import QtQuick.Controls 2.0



PathView {
    id: circularView

    signal launched(string page)

    readonly property int cX: width / 2
    readonly property int cY: height / 2
    readonly property int itemSize: size / 4
    readonly property int size: Math.min(width - 80, height)
    readonly property int radius: size / 2 - itemSize / 3
    width: 800




    // gestion d'arret d'urgence

    Connections{
        target: myGPIO


        function aruchanged(){

            if(myGPIO.aru==false){


                stopp.visible=true; power.visible = false ; grafcet.HMarche=false ; stopp.enabled =false

            }
            if(myGPIO.aru==true){

                stopp.enabled =true

            }
        }


      Component.onCompleted: {
          console.log("0clickedclicked")
        aruchanged();

    }

        onAruChanged:{
            console.log("00000000000000")
            aruchanged();
        }
    }



// gestion marche / arret

    MouseArea{
        id: stopp
        width: 115
        height: 115
        visible: true
        x: 30
        y: 0
        onClicked: {stopp.visible=false; power.visible = true; grafcet.HMarche=true }

    Image {
        id: stop
        visible: true
        width: 100
        height: 100
        source: "../images/Reload0.png"
    }
    Text {
        x: 22
        y: 41

        text: qsTr("START")
        font.bold: true
    }
        }

    MouseArea{
        id: power
        x: 30
        y: 0
        width: 115
        height: 115
        visible: false

        onClicked: {stopp.visible=true; power.visible = false ; grafcet.HMarche=false }


            AnimatedImage {
                id : run
                visible: true
                width: 100
                height: 100
                source: "../images/Reload.gif"
            }
            Text {
                x: 26
                y: 41

                text: qsTr("STOP")
                font.bold: true
            }

        }



// button shudown Pi

    Image {
        id: off
        x: 720
        y: 0
        width: 80
        height: 80
        source: "../images/off_80.png"

        MouseArea{
            anchors.rightMargin: 0
            anchors.bottomMargin: 0
            anchors.leftMargin: 0
            anchors.topMargin: 0
            anchors.fill: parent

            x: 710
            y: 0
            width: 90
            height: 90
            enabled: true
            onClicked: {myGPIO.shutdown()}
        }


}

    // gestion defaut ( secu reperage / echenlliage )

    Connections{
    target: grafcet

    onDreperageChanged : {

        if(grafcet.dreperage==true){
            click_warning_rep.visible=true;
            stopp.visible=true; power.visible = false ; grafcet.HMarche=false ; stopp.enabled =false
        }

        else{
            click_warning_rep.visible =false;
            stopp.enabled =true
        }


    }

    onDechenlliageChanged:{

        if(grafcet.dechenlliage==true){

            console.log("echenlliage time out")
            click_warning_ech.visible=true;
            stopp.visible=true; power.visible = false ; grafcet.HMarche=false ; stopp.enabled =false
        }

        else{
            click_warning_ech.visible =false;
            stopp.enabled =true
        }
    }


    }

        MouseArea{
        id:click_warning_rep

         x: 535
            y: 315
            width: 265
            height: 111
            visible: false
            enabled: true
            onClicked: { console.log("out warning rep"); grafcet.dreperage=false}
        }

        MouseArea{
        id:click_warning_ech

         x: 535
            y: 315
            width: 265
            height: 111
            visible: false
            enabled: true
            onClicked: { console.log("out warning ech"); grafcet.dechenlliage=false}
        }



    snapMode: PathView.SnapToItem

    model: ListModel {
        ListElement {
            title: qsTr("Validation")
            icon: "validation"
            page: "Validation/ValidationPage.qml"
        }
        ListElement {
            title: qsTr("Languages")
            icon: "language"
            page: "Language/LanguagePage.qml"
        }
        ListElement {
            title: qsTr("Helps")
            icon: "info"
            page: "Help/HelpPage.qml"
        }
        ListElement {
            title: qsTr("Compteurs")
            icon: "Compteur"
            page: "Compteurs/CompteurPage.qml"
        }
        ListElement {
            title: qsTr("Contacts")
            icon: "notifications"
            page: "Contacts/ContactPage.qml"
        }
        ListElement {
            title: qsTr("Reglages")
            icon: "worldclock"
            page: "Reglages/ReglagePage.qml"
        }
        ListElement {
            title: qsTr("Service")
            icon: "settings"
            page: "Services/ServicesPage.qml"
        }
    }

    delegate: QQC2.RoundButton {
        width: circularView.itemSize
        height: circularView.itemSize

        property string title: model.title

        icon.width: 36
        icon.height: 36
        icon.name: model.icon
        opacity: PathView.itemOpacity
        padding: 12

        background: Rectangle {
            radius: width / 2
            border.width: 3
            //border.color: parent.PathView.isCurrentItem ? UIStyle.colorQtPrimGreen : UIStyle.colorQtGray4
            border.color: "blue"

        }

        onClicked: {
            if (PathView.isCurrentItem)
                circularView.launched(Qt.resolvedUrl(page))
            else
                circularView.currentIndex = index
        }
    }

    path: Path {
        startX: circularView.cX
        startY: circularView.cY
        PathAttribute {
            name: "itemOpacity"
            value: 1.0
        }
        PathLine {
            x: circularView.cX + circularView.radius
            y: circularView.cY
        }
        PathAttribute {
            name: "itemOpacity"
            value: 0.7
        }
        PathArc {
            x: circularView.cX - circularView.radius
            y: circularView.cY
            radiusX: circularView.radius
            radiusY: circularView.radius
            useLargeArc: true
            direction: PathArc.Clockwise
        }
        PathAttribute {
            name: "itemOpacity"
            value: 0.5
        }
        PathArc {
            x: circularView.cX + circularView.radius
            y: circularView.cY
            radiusX: circularView.radius
            radiusY: circularView.radius
            useLargeArc: true
            direction: PathArc.Clockwise
        }
        PathAttribute {
            name: "itemOpacity"
            value: 0.3
        }
    }

    Text {
        id: appTitle

        property Item currentItem: circularView.currentItem

        visible: currentItem ? currentItem.PathView.itemOpacity === 1.0 : 0

        text: currentItem ? currentItem.title : ""
        anchors.centerIn: parent
        anchors.verticalCenterOffset: (circularView.itemSize + height) / 2

        font.bold: true
        font.pixelSize: circularView.itemSize / 3
        font.letterSpacing: 1
        color: UIStyle.colorQtGray1
    }
}

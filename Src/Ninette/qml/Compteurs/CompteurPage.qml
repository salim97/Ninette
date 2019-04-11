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

import QtQuick 2.7
import QtQuick.Controls 2.0 as QQ2
//import "../Style"
import QtQuick.Controls 1.4



Item {


    width: 800





    // les manueles

    Text {
        id: text41
        x: 293
        y: 41
        text: qsTr("MANUEL")
        font.underline: true
        font.bold: true
        font.pixelSize: 35
    }

    Rectangle {
        id: manu_marche
        x: 212
        y: 99
        width: 65
        height: 62
        radius:  50
        color: "red"
        border.color: "black"
        border.width: 5
        MouseArea{
            anchors.rightMargin: 0
            anchors.bottomMargin: 0
            anchors.leftMargin: 0
            anchors.topMargin: 0
            anchors.fill: parent

            onPressed: {myGPIO.marche =1
                manu_marche.color= "green"}
            onReleased: {myGPIO.marche =0
                manu_marche.color= "red"}
        }

    }
    Rectangle {
        id: manu_moteur1
        x: 212
        y: 187
        width: 65
        height: 62
        radius:  50
        color: "red"
        border.color: "black"
        border.width: 5
        MouseArea{
            anchors.rightMargin: 0
            anchors.bottomMargin: 0
            anchors.leftMargin: 0
            anchors.topMargin: 0
            anchors.fill: parent
            onPressed: {myGPIO.moteur1 =1
                manu_moteur1.color= "green"}
            onReleased: {myGPIO.moteur1 =0
                manu_moteur1.color= "red"}
        }

    }



    Rectangle {
        id: manu_moteur2
        x: 527
        y: 99
        width: 65
        height: 62
        radius:  50
        color: "red"
        border.color: "black"
        border.width: 5
        MouseArea{
            anchors.rightMargin: 0
            anchors.bottomMargin: 0
            anchors.leftMargin: 0
            anchors.topMargin: 0
            anchors.fill: parent
            onPressed: {myGPIO.moteur2 =1
                manu_moteur2.color= "green"}
            onReleased: {myGPIO.moteur2 =0
                manu_moteur2.color= "red"}
        }

    }
    Rectangle {
        id: manu_lisseur
        x: 527
        y: 187
        width: 65
        height: 62
        radius:  50
        color: "red"
        border.color: "black"
        border.width: 5
        MouseArea{
            anchors.rightMargin: 0
            anchors.bottomMargin: 0
            anchors.leftMargin: 0
            anchors.topMargin: 0
            anchors.fill: parent
            onPressed: {myGPIO.lisseur =1
                manu_lisseur.color= "green"}
            onReleased: {myGPIO.lisseur =0
                manu_lisseur.color= "red"}
        }

    }


    Text {
        id: text1
        x: 19
        y: 115
        text: qsTr("MARCHE")
        font.pixelSize: 25
    }

    Text {
        id: text2
        x: 19
        y: 203
        text: qsTr("POSTE 1")
        font.pixelSize: 25
    }
    Text {
        id: text3
        x: 358
        y: 115
        text: qsTr("POSTE 2")
        font.pixelSize: 25
    }

    Text {
        id: text4
        x: 358
        y: 203
        text: qsTr("LISSEUR")
        font.pixelSize: 25
    }


    // lecture des sortie écran

        Rectangle{
             id:marche
             x: 762
             y: 200
             width: 30
             height: 30
             color: myGPIO.marche == true ? "green" : "red"
         }

        Rectangle{
             id:moteur1
             x: 762
             y: 250
             width: 30
             height: 30
             color: myGPIO.moteur1 == true ? "green" : "red"
         }

        Rectangle{
             id:moteur2
             x: 762
             y: 300
             width: 30
             height: 30
             color: myGPIO.moteur2 == true ? "green" : "red"
         }

        Rectangle{
             id:lisseur
             x: 762
             y: 350
             width: 30
             height: 30
             color: myGPIO.lisseur == true ? "green" : "red"

         }


}


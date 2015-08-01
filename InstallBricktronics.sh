#!/bin/sh

wget https://github.com/wayneandlayne/BricktronicsShield/archive/master.zip
mv master.zip BricktronicsShield.zip
wget https://github.com/wayneandlayne/BricktronicsMotor/archive/master.zip
mv master.zip BricktronicsMotor.zip
wget https://github.com/wayneandlayne/BricktronicsLight/archive/master.zip
mv master.zip BricktronicsLight.zip
wget https://github.com/wayneandlayne/BricktronicsColor/archive/master.zip
mv master.zip BricktronicsColor.zip
wget https://github.com/wayneandlayne/BricktronicsSound/archive/master.zip
mv master.zip BricktronicsSound.zip
wget https://github.com/wayneandlayne/BricktronicsButton/archive/master.zip
mv master.zip BricktronicsButton.zip
wget https://github.com/wayneandlayne/BricktronicsUltrasonic/archive/master.zip
mv master.zip BricktronicsUltrasonic.zip

unzip BricktronicsShield.zip -d BricktronicsShield
unzip BricktronicsMotor.zip -d BricktronicsMotor
unzip BricktronicsLight.zip -d BricktronicsLight
unzip BricktronicsColor.zip -d BricktronicsColor
unzip BricktronicsSound.zip -d BricktronicsSound
unzip BricktronicsButton.zip -d BricktronicsButton
unzip BricktronicsUltrasonic.zip -d BricktronicsUltrasonic

rm BricktronicsShield.zip
rm BricktronicsMotor.zip
rm BricktronicsLight.zip
rm BricktronicsColor.zip
rm BricktronicsSound.zip
rm BricktronicsButton.zip
rm BricktronicsUltrasonic.zip


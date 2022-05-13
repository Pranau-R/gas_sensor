/*
Module: gas_sensor_mics4514.ino
Function:
        To measure the distance between an object and source using Arduino MEGA board and Ultrasonic sensor HC-SR04
Copyright notice:
        This file copyright (C) 2022 by
        MCCI Corporation
        3520 Krums Corners Road
        Ithaca, NY 14850
        An unpublished work. All rights reserved.
        This file is proprietary information, and may not be disclosed or
        copied without the prior permission of MCCI Corporation.
Author:
        Pranau R, MCCI Corporation   May 2022
*/

#include <DFRobot_MICS.h>

#define CALIBRATION_TIME   3

#define MICS_I2C_ADDRESS MICS_ADDRESS_0
DFRobot_MICS_I2C mics(&Wire, MICS_I2C_ADDRESS);

/****************************************************************************\
|
|   Setup Function.
|
\****************************************************************************/

/*
Name: main()
Function:
        To initiate a serial connection between board and display and to check the connectivity as well as powerstate of mics4514.
Definition:
        void setup (void);
Returns:
        Functions returning type void: nothing.
*/

void setup()
  {
  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);

  while(!Serial);
  while(!mics.begin())
    {
    Serial.println ("No Device!");
    delay(2000);
    }
  Serial.println("Device connected successfully!");

  uint8_t mode = mics.getPowerState();

  if(mode == SLEEP_MODE)
    {
    mics.wakeUpMode();
    Serial.println("wake up sensor activated!");
    }
  else
    {
    Serial.println("The sensor is in Wake Up Mode!");
    }

  while(!mics.warmUpTime(CALIBRATION_TIME))
    {
    Serial.println("Please wait until the warm-up time is over!");
    delay(5000);
    }
  Serial.println("The Data of different gases are:");
  delay(3000);
  }

/****************************************************************************\
|
|   Setup Function.
|
\****************************************************************************/

/*
Name: loop()
Function:
        To get the different gas value from the sensor and display it in serial monitor.
Definition:
        void loop (void);
Returns:
        Functions returning type void: nothing.
*/

void loop()
  {
  int count;
  Serial.println();
  float gasDataCO = mics.getGasData(CO);

  if (gasDataCO >= 0)
    {
    Serial.print ("Carbon Monoxide = ");
    Serial.print (gasDataCO, 1);
    Serial.println ("PPM");
    count = 0;

    while (count <= 0)
      {
      digitalWrite(LED_BUILTIN, HIGH);
      delay (200);
      digitalWrite(LED_BUILTIN, LOW);
      delay (200);
      ++count;
      }
    delay(2000);
    }

  float gasDataCH4 = mics.getGasData(CH4);

  if (gasDataCH4 >= 0)
    {
    Serial.print ("Methane = ");
    Serial.print (gasDataCH4, 1);
    Serial.println ("PPM");
    count = 0;

    while (count <= 1)
      {
      digitalWrite(LED_BUILTIN, HIGH);
      delay (200);
      digitalWrite(LED_BUILTIN, LOW);
      delay (200);
      ++count;
      }
    delay(2000);
    }

  float gasDataC2H5OH = mics.getGasData(C2H5OH);

  if (gasDataC2H5OH >= 0)
    {
    Serial.print ("Ethanol = ");
    Serial.print (gasDataC2H5OH, 1);
    Serial.println ("PPM");
    count = 0;

    while (count <= 2)
      {
      digitalWrite(LED_BUILTIN, HIGH);
      delay (200);
      digitalWrite(LED_BUILTIN, LOW);
      delay (200);
      ++count;
      }
    delay(2000);
    }

  float gasDataH2 = mics.getGasData(H2);

  if (gasDataH2 >= 0)
    {
    Serial.print ("Hydrogen = ");
    Serial.print (gasDataH2, 1);
    Serial.println ("PPM");
    count = 0;

    while (count <= 3)
      {
      digitalWrite(LED_BUILTIN, HIGH);
      delay (200);
      digitalWrite(LED_BUILTIN, LOW);
      delay (200);
      ++count;
      }
    delay(2000);
    }

  float gasDataNH3 = mics.getGasData(NH3);

  if (gasDataNH3 >= 0)
    {
    Serial.print ("Ammonia = ");
    Serial.print (gasDataNH3, 1);
    Serial.println ("PPM");
    count = 0;

    while (count <= 4)
      {
      digitalWrite(LED_BUILTIN, HIGH);
      delay (200);
      digitalWrite(LED_BUILTIN, LOW);
      delay (200);
      ++count;
      }
    delay(2000);
    }

  float gasDataNO2 = mics.getGasData(NO2);

  if (gasDataNO2 >= 0)
    {
    Serial.print ("Nitrogen Dioxide = ");
    Serial.print (gasDataNO2, 1);
    Serial.println ("PPM");
    count = 0;

    while (count <= 5)
      {
      digitalWrite(LED_BUILTIN, HIGH);
      delay (200);
      digitalWrite(LED_BUILTIN, LOW);
      delay (200);
      ++count;
      }
    delay (2000);
    }
  delay (2000);
  }

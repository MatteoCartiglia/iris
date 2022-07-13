//---------------------------------------------------------------------------------------------------------------------------------------
//
//
// Author: Matteo Cartiglia <camatteo@ini.uzh.ch>
// Last updated: (Ciara Giles-Doran <gciara@student.ethz.ch>)
//---------------------------------------------------------------------------------------------------------------------------------------

#include "teensyOut.h"
#include "constants.h"

//---------------------------------------------------------------------------------------------------------------------------------------
// TeensyOut constructor
//---------------------------------------------------------------------------------------------------------------------------------------

TeensyOut::TeensyOut(const int outputReqPin, const int outputAckPin, int outputDataPins[], int outputNumDataPins, int outputDelay, bool outputActiveLow)
{
  _outputReqPin = outputReqPin;
  _outputAckPin = outputAckPin;
  _outputDataPins = outputDataPins;
  _outputNumDataPins = outputNumDataPins;
  _outputDelay = outputDelay;
  _outputActiveLow = outputActiveLow;

  setupDecoderComms();
}

//---------------------------------------------------------------------------------------------------------------------------------------
// 
//---------------------------------------------------------------------------------------------------------------------------------------

bool TeensyOut::dataWrite(unsigned int data) 
{
  unsigned long t0 = millis();
  bool handshakeStatus = true;

  setOutputData(data);
  reqWrite(1);

  while(!ackRead())
  {
    if (millis() > t0 + TEENSY_OUTPUT_HANDSHAKE_TIMEOUT)
    {
      handshakeStatus = false;
      break;
    }
  }

  reqWrite(0);
  return handshakeStatus;
}

//---------------------------------------------------------------------------------------------------------------------------------------
// 
//---------------------------------------------------------------------------------------------------------------------------------------

void TeensyOut::setupDecoderComms()
{
  for(int i = 0; i < _outputNumDataPins; i++)
  {
    pinMode(_outputDataPins[i], OUTPUT);
  }

  pinMode(SYN_RST_NMDA_PIN, OUTPUT);
  pinMode(SYN_RST_GABGA_PIN, OUTPUT);
  pinMode(_outputReqPin, OUTPUT);
  pinMode(_outputAckPin, INPUT);
  delay(5);

  digitalWrite(SYN_RST_NMDA_PIN, HIGH);
  delay(1);
  digitalWrite(SYN_RST_GABGA_PIN, HIGH);
  delay(1);
  digitalWrite(SYN_RST_NMDA_PIN, LOW);
  delay(1);
  digitalWrite(SYN_RST_GABGA_PIN, LOW);
  delay(1);

  reqWrite(LOW);
  delay(1);
}

//---------------------------------------------------------------------------------------------------------------------------------------
// 
//---------------------------------------------------------------------------------------------------------------------------------------

bool TeensyOut::ackRead() 
{
  return digitalReadFast(_outputAckPin)^_outputActiveLow;
}

//---------------------------------------------------------------------------------------------------------------------------------------
// 
//---------------------------------------------------------------------------------------------------------------------------------------

void TeensyOut::reqWrite(bool val) 
{
  digitalWriteFast(_outputReqPin, val^_outputActiveLow);

  if (_outputDelay) 
  {
    delayMicroseconds(_outputDelay);
  }
}

//---------------------------------------------------------------------------------------------------------------------------------------
// 
//---------------------------------------------------------------------------------------------------------------------------------------

void TeensyOut::setOutputData(unsigned int data) 
{
  for (int i=0; i<_outputNumDataPins; i++) 
  {
    digitalWriteFast(_outputDataPins[i], bitRead(data, i)^_outputActiveLow);
  }
}

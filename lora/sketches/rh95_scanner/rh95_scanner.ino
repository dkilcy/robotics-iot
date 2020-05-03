// rh95_scanner.ino

// Available bandwidths: 7.8 kHz; 10.4 kHz; 15.6 kHz; 20.8 kHz; 31.2 kHz; 41.7 kHz; 62.5 kHz; 125 kHz; 250 kHz; 500 kHz
//  The top three tend to be the most commonly used
// Available spreading factors: SF7 through to SF12 to adapt the data rate and range trade-off. 
//   Higher spreading factor allows longer range at the expense of lower data rate, and vice versa.
// Reference: https://www.electronics-notes.com/articles/connectivity/lora/radio-rf-interface-physical-layer.php

#include <SPI.h>
#include <RH_RF95.h>

#define RH_FLAGS_ACK            0x80

// Singleton instance of the radio driver
RH_RF95 rf95;

#if 0
#define FREQ_COUNT 5
float _frequencies[] =
{
  915.0,
  917.1,
  917.3,
  917.5,
  917.9
};
#endif

#if 1
// FLiFli: 917 ~ 923

#define FREQ_COUNT 20
float _frequencies[] =
{

#if 0
  902.0,
  902.1,
  902.2,
  902.3,
  902.4,
  902.5,
  902.6,
  902.7,
  902.8,
  902.9,

  903.0,
  903.1,
  903.2,
  903.3,
  903.4,
  903.5,
  903.6,
  903.7,
  903.8,
  903.9,

  904.0,
  904.1,
  904.2,
  904.3,
  904.4,
  904.5,
  904.6,
  904.7,
  904.8,
  904.9,

  905.0,
  905.1,
  905.2,
  905.3,
  905.4,
  905.5,
  905.6,
  905.7,
  905.8,
  905.9,

  906.0,
  906.1,
  906.2,
  906.3,
  906.4,
  906.5,
  906.6,
  906.7,
  906.8,
  906.9,
#endif

  907.0,
  907.1,
  907.2,
  907.3,
  907.4,
  907.5,
  907.6,
  907.7,
  907.8,
  907.9,
  
  908.0,
  908.1,
  908.2,
  908.3,
  908.4,
  908.5,
  908.6,
  908.7,
  908.8,
  908.9,

  909.0,
  909.1,
  909.2,
  909.3,
  909.4,
  909.5,
  909.6,
  909.7,
  909.8,
  909.9,
  
#if 0
  910.0,
  910.1,
  910.2,
  910.3,
  910.4,
  910.5,
  910.6,
  910.7,
  910.8,
  910.9,
 
  911.0,
  911.1,
  911.2,
  911.3,
  911.4,
  911.5,
  911.6,
  911.7,
  911.8,
  911.9,
  
  912.0,
  912.1,
  912.2,
  912.3,
  912.4,
  912.5,
  912.6,
  912.7,
  912.8,
  912.9,

  913.0,
  913.1,
  913.2,
  913.3,
  913.4,
  913.5,
  913.6,
  913.7,
  913.8,
  913.9,

  914.0,
  914.1,
  914.2,
  914.3,
  914.4,
  914.5,
  914.6,
  914.7,
  914.8,
  914.9,
  
  915.0,
  915.1,
  915.2,
  915.3,
  915.4,
  915.5,
  915.6,
  915.7,
  915.8,
  915.9,

  916.0,
  916.1,
  916.2,
  916.3,
  916.4,
  916.5,
  916.6,
  916.7,
  916.8,
  916.9,
  
  917.0,
  917.1,
  917.2,
  917.3,
  917.4,
  917.5,
  917.6,
  917.7,
  917.8,
  917.9,
  
  918.0,
  918.1,
  918.2,
  918.3,
  918.4,
  918.5,
  918.6,
  918.7,
  918.8,
  918.9,

  919.0,
  919.1,
  919.2,
  919.3,
  919.4,
  919.5,
  919.6,
  919.7,
  919.8,
  919.9,

  920.0,
  920.1,
  920.2,
  920.3,
  920.4,
  920.5,
  920.6,
  920.7,
  920.8,
  920.9,

  921.0,
  921.1,
  921.2,
  921.3,
  921.4,
  921.5,
  921.6,
  921.7,
  921.8,
  921.9,

  922.0,
  922.1,
  922.2,
  922.3,
  922.4,
  922.5,
  922.6,
  922.7,
  922.8,
  922.9,

  923.0,
  923.1,
  923.2,
  923.3,
  923.4,
  923.5,
  923.6,
  923.7,
  923.8,
  923.9,

  924.0,
  924.1,
  924.2,
  924.3,
  924.4,
  924.5,
  924.6,
  924.7,
  924.8,
  924.9,

  925.0,
  925.1,
  925.2,
  925.3,
  925.4,
  925.5,
  925.6,
  925.7,
  925.8,
  925.9,

  926.0,
  926.1,
  926.2,
  926.3,
  926.4,
  926.5,
  926.6,
  926.7,
  926.8,
  926.9,

  927.0,
  927.1,
  927.2,
  927.3,
  927.4,
  927.5,
  927.6,
  927.7,
  927.8,
  927.9,

  928.0,
  928.1,
  928.2,
  928.3,
  928.4,
  928.5,
  928.6,
  928.7,
  928.8,
  928.9,
#endif
};
#endif

// How long should a frequency be monitored
#define FREQ_TIME_MS            5000

// Used to track how many packets we have seen on each frequency above
uint16_t _packetCounts[FREQ_COUNT] = { 0 };
uint32_t _freqExpire        = 0;                            // Millisecond at which frequency should change
uint32_t _freqIndex         = 0;                            // Which frequency is currently monitored

uint8_t  _rxBuffer[RH_RF95_MAX_MESSAGE_LEN];                // receive buffer
uint8_t  _rxRecvLen;                                        // number of bytes actually received

char     _printBuffer[512]  = "\0";

// Board control

int reset_lora = 9;
int led = 4;

void rf95_setFrequency(uint32_t index)
{
  if (!rf95.setFrequency(_frequencies[index]))
  {
    Serial.println("setFrequency failed");
    while (1);
  }

  snprintf(_printBuffer, sizeof(_printBuffer), "Freq: %04u (%04u)   ", (uint32_t)(_frequencies[index] * 10), _packetCounts[index]);
  Serial.println(_printBuffer);
}

void setup()
{
  Serial.begin(9600);
  while (!Serial) ; // Wait for serial port to be available

  Serial.println("Start rh95_scanner");

  delay(1000);
  
  pinMode(led, OUTPUT);
  digitalWrite(reset_lora, HIGH);

  if (!rf95.init())
  {
    Serial.println("init failed");
    while (1);
  }

  rf95_setFrequency(_freqIndex);
  rf95.setPromiscuous(true);

  // Update time for changing frequency
  _freqExpire = millis() + FREQ_TIME_MS;

  Serial.println("scanner ready");
}

void loop()
{
  _rxRecvLen = sizeof(_rxBuffer);
  rf95.setModeRx();

  // Handle incoming packet if available
  if (rf95.recv(_rxBuffer, &_rxRecvLen))
  {
    char isAck[4] = { "   " };

    //digitalWrite(led, HIGH);

    _packetCounts[_freqIndex]++;

    if (rf95.headerFlags() & RH_FLAGS_ACK)
    {
      memcpy(isAck, "Ack\0", 3);
    }

    _rxBuffer[_rxRecvLen] = '\0';

    // Prepare delimited output for log
    snprintf(_printBuffer, sizeof(_printBuffer), "%u,%u.%u,%04d,%d,%d,%d,%d,%02X,%s,%d,",
             millis(),
             (uint32_t)(_frequencies[_freqIndex] * 10) / 10,
             (uint32_t)(_frequencies[_freqIndex] * 10) % 10,
             _packetCounts[_freqIndex],
             rf95.lastRssi(),
             rf95.headerFrom(),
             rf95.headerTo(),
             rf95.headerId(),
             rf95.headerFlags(),
             isAck,
             _rxRecvLen
            );

    // Add bytes received as hex values
    for (int i = 0; i < _rxRecvLen; i++)
    {
      snprintf(_printBuffer, sizeof(_printBuffer), "%s %02X", _printBuffer, _rxBuffer[i]);
    }

    // Add bytes received as string - this is usually ugly and useless, but
    // it is here just in case. Maybe someone will send something in plaintext
    snprintf(_printBuffer, sizeof(_printBuffer), "%s,%s", _printBuffer, _rxBuffer);

    Serial.println(_printBuffer);
  }


  // Change frequency if it is time
  if (millis() > _freqExpire)
  {
    rf95.setModeIdle();

    _freqExpire = millis() + FREQ_TIME_MS;
    _freqIndex++;

    if (_freqIndex == FREQ_COUNT)
    {
      _freqIndex = 0;
    }

    rf95_setFrequency(_freqIndex);
  }
}

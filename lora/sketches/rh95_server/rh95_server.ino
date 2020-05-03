// rf95_server.ino

#include <SPI.h>
#include <RH_RF95.h>

// Singleton instance of the radio driver
RH_RF95 rf95;

float frequency = 917.1;

int reset_lora = 9;
int led = 4;

void setup()
{
  Serial.begin(9600);
  while (!Serial) ; // Wait for serial port to be available
  
  Serial.println("Start rh95_server");

  pinMode(led, OUTPUT);
  digitalWrite(reset_lora, HIGH);

  if (!rf95.init())
    Serial.println("init failed");
  
  // Setup ISM frequency
  rf95.setFrequency(frequency);
  // Setup Power,dBm
  rf95.setTxPower(13);

  // Defaults BW Bw = 125 kHz, Cr = 4/5, Sf = 128chips/symbol, CRC on
  Serial.print("Listening on frequency: ");
  Serial.println(frequency);
}

void loop()
{
  if (rf95.available())
  {
    // Should be a message for us now
    uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
    uint8_t len = sizeof(buf);
    if (rf95.recv(buf, &len))
    {
      RH_RF95::printBuffer("request: ", buf, len);
      Serial.print("got request: ");
      Serial.println((char*)buf);
      Serial.print("RSSI: ");
      Serial.println(rf95.lastRssi(), DEC);

      // Send a reply
      uint8_t data[] = "And hello back to you";
      rf95.send(data, sizeof(data));
      rf95.waitPacketSent();
      Serial.println("Sent a reply");
    }
    else
    {
      Serial.println("recv failed");
    }
  } else {
    //Serial.println("rf95 is not available");
  }
}

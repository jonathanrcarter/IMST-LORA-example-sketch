#include "crc.h"  // Lora module from sven

#define DEBUG(x) Serial.println(x);


uint8_t rxbuf[300]; 
uint8_t rx_count =0;

uint8_t lora_devid[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
uint8_t lora_devid_reverse[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
uint8_t lora_appkey[16] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial1.begin(115200);

  if(!lora_join()) Serial.println("Failed to initialize LORA module");
  else Serial.println("Succesfully initialized LoRa module");


}

void loop() {

  // set up and send a lora packet
  uint8_t tx_raw[6];
  tx_raw[0] = 0x01;
  tx_raw[1] = 0x02;
  tx_raw[2] = 0x03;
  tx_raw[3] = 0x04;
  tx_raw[4] = 0x05;
  tx_raw[5] = 0x06;
  lora_tx_reliable(tx_raw,6);                          // Send a packet without a required response (We do not want to run down the battery in case of backend-failure, rather have lost packets)

  // sleep for 1 min
  delay(60000);

}




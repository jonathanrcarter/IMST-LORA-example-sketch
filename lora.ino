#define DEVMGMT_ID 0x01
#define LORAWAN_ID 0x10

#define DEVMGMT_MSG_PING_REQ 0x01
#define DEVMGMT_MSG_PING_RSP 0x02
#define DEVMGMT_MSG_GET_DEVICE_INFO_REQ 0x03
#define DEVMGMT_MSG_GET_DEVICE_INFO_RSP 0x04
#define DEVMGMT_MSG_GET_FW_INFO_REQ 0x05
#define DEVMGMT_MSG_GET_FW_INFO_RSP 0x06
#define DEVMGMT_MSG_RESET_REQ 0x07
#define DEVMGMT_MSG_RESET_RSP 0x08
#define DEVMGMT_MSG_SET_OPMODE_REQ 0x09
#define DEVMGMT_MSG_SET_OPMODE_RSP 0x0A
#define DEVMGMT_MSG_GET_OPMODE_REQ 0x0B
#define DEVMGMT_MSG_GET_OPMODE_RSP 0x0C
#define DEVMGMT_MSG_SET_RTC_REQ 0x0D
#define DEVMGMT_MSG_SET_RTC_RSP 0x0E
#define DEVMGMT_MSG_GET_RTC_REQ 0x0F
#define DEVMGMT_MSG_GET_RTC_RSP 0x10

#define DEVMGMT_STATUS_OK 0x00                //Operation successful
#define DEVMGMT_STATUS_ERROR 0x01             //Operation failed
#define DEVMGMT_STATUS_CMD_NOT_SUPPORTED 0x02 //Command is not supported
#define DEVMGMT_STATUS_WRONG_PARAMETER 0x03

#define LORAWAN_MSG_ACTIVATE_DEVICE_REQ 0x01
#define LORAWAN_MSG_ACTIVATE_DEVICE_RSP 0x02
#define LORAWAN_MSG_GET_ACT_PARAMS_REQ 0x03
#define LORAWAN_MSG_GET_ACT_PARAMS_RSP 0x04
#define LORAWAN_MSG_SET_JOIN_PARAM_REQ 0x05
#define LORAWAN_MSG_SET_JOIN_PARAM_RSP 0x06
#define LORAWAN_MSG_GET_JOIN_PARAM_REQ 0x07
#define LORAWAN_MSG_GET_JOIN_PARAM_RSP 0x08
#define LORAWAN_MSG_JOIN_NETWORK_REQ 0x09
#define LORAWAN_MSG_JOIN_NETWORK_RSP 0x0A
#define LORAWAN_MSG_JOIN_NETWORK_TX_IND 0x0B
#define LORAWAN_MSG_JOIN_NETWORK_IND 0x0C
#define LORAWAN_MSG_SEND_UDATA_REQ 0x0D
#define LORAWAN_MSG_SEND_UDATA_RSP 0x0E
#define LORAWAN_MSG_SEND_UDATA_TX_IND 0x0F
#define LORAWAN_MSG_RECV_UDATA_IND 0x10
#define LORAWAN_MSG_SEND_CDATA_REQ 0x11
#define LORAWAN_MSG_SEND_CDATA_RSP 0x12
#define LORAWAN_MSG_SEND_CDATA_TX_IND 0x13
#define LORAWAN_MSG_RECV_CDATA_IND 0x14
#define LORAWAN_MSG_RECV_ACK_IND 0x15
#define LORAWAN_MSG_RECV_NO_ACK 0x16
#define LORAWAN_MSG_SET_RSTACK_CONFIG_REQ 0x19
#define LORAWAN_MSG_SET_RSTACK_CONFIG_RSP 0x1A
#define LORAWAN_MSG_GET_RSTACK_CONFIG_REQ 0x1B
#define LORAWAN_MSG_GET_RSTACK_CONFIG_RSP 0x1C
#define LORAWAN_MSG_DEACTIVATE_DEVICE_REQ 0x21
#define LORAWAN_MSG_DEACTIVATE_DEVICE_RSP 0x22
#define LORAWAN_MSG_FACTORY_RESET_REQ 0x23
#define LORAWAN_MSG_FACTORY_RESET_RSP 0x24
#define LORAWAN_MSG_SET_DEVICE_EUI_REQ 0x25
#define LORAWAN_MSG_SET_DEVICE_EUI_RSP 0x26
#define LORAWAN_MSG_GET_DEVICE_EUI_REQ 0x27
#define LORAWAN_MSG_GET_DEVICE_EUI_RSP 0x28
#define LORAWAN_MSG_GET_NWK_STATUS_REQ 0x29
#define LORAWAN_MSG_GET_NWK_STATUS_RSP 0x2A

#define LORAWAN_STATUS_OK 0x00                      //Operation successful
#define LORAWAN_STATUS_ERROR 0x01                   //Operation failed
#define LORAWAN_STATUS_CMD_NOT_SUPPORTED 0x02       //Command is not supported
#define LORAWAN_STATUS_WRONG_PARAMETER 0x03         //HCI message contains wrong parameter
#define LORAWAN_STATUS_WRONG_DEVICE_MODE 0x04       //Stack is running in a wrong mode
#define LORAWAN_STATUS_DEVICE_NOT_ACTIVATED 0x05    //Device is not activated
#define LORAWAN_STATUS_DEVICE_BUSY 0x06             //Device is busy, command rejected
#define LORAWAN_STATUS_QUEUE_FULL 0x07              //Message queue is full, command rejected
#define LORAWAN_STATUS_LENGTH_ERROR 0x08            //HCI message length is invalid
#define LORAWAN_STATUS_NO_FACTORY_SETTINGS 0x09     //Factory Settings EEPROM block missing

#define LORA_CHANNEL_0 0 // 868 100 000 Hz
#define LORA_CHANNEL_1 1 // 868 300 000 Hz
#define LORA_CHANNEL_2 2 // 868 500 000 Hz
#define LORA_CHANNEL_3 3 // 868 850 000 Hz
#define LORA_CHANNEL_4 4 // 869 050 000 Hz
#define LORA_CHANNEL_5 5 // 869 525 000 Hz

#define LORA_RATE_0 0 // LoRa / SF12 125 kHz 250
#define LORA_RATE_1 1 // LoRa / SF11 125 kHz 440
#define LORA_RATE_2 2 // LoRa / SF10 125 kHz 980
#define LORA_RATE_3 3 // LoRa / SF9 125 kHz 1760
#define LORA_RATE_4 4 // LoRa / SF8 125 kHz 3125
#define LORA_RATE_5 5 // LoRa / SF7 125 kHz 5470
#define LORA_RATE_6 6 // LoRa / SF7 250 kHz 11000
#define LORA_RATE_7 7 // FSK / 50kbps 50000

#define LORA_MODE_0 0 //Standard Application Mode / Default Mode
#define LORA_MODE_1 1 // Reserved
#define LORA_MODE_2 2 // Reserved
#define LORA_MODE_3 3 // Customer Mode

boolean lora_init()
{
   uint8_t retry=0;
   while(retry<3)
   {
     if(!lora_ping()) 
     {      
      delay(5000);
      lora_reset();
     }
     else 
     {
      return true;
     }
     retry++;
   }
   return false;
}

boolean lora_ping()
{
   lora_send_command(DEVMGMT_ID, DEVMGMT_MSG_PING_REQ,0, 0);
   uint8_t dst = 0;
   uint8_t msgid = 0;  
   bool result = lora_receive_message(1000,&dst,&msgid,rxbuf);
   if(dst!=DEVMGMT_ID || msgid!=DEVMGMT_MSG_PING_RSP) return false;
   if(rxbuf[2] != DEVMGMT_STATUS_OK) 
    {
    //  lora_error_handler(dst,rxbuf[2]);
    //  return false;
    }
   return true;
}

boolean lora_reset()
{
   lora_send_message(DEVMGMT_ID, DEVMGMT_MSG_RESET_REQ,0, 0);
   uint8_t dst = 0;
   uint8_t msgid = 0;
   bool result = lora_receive_message(1000,&dst,&msgid,rxbuf);
   if(dst!=DEVMGMT_ID || msgid!=DEVMGMT_MSG_RESET_RSP) return false;
   if(rxbuf[2] != DEVMGMT_STATUS_OK) 
    {
      lora_error_handler(dst,rxbuf[2]);
      return false;
    }
   return true;
}

boolean lora_join() {
  // set customer mode
  uint8_t msg1[1];
  msg1[0] = 0x03;
  lora_send_command(DEVMGMT_ID,DEVMGMT_MSG_GET_OPMODE_REQ,msg1, 1);

  /* await response */
   uint8_t dst = 0;
   uint8_t msgid = 0;  
   bool result = lora_receive_message(1000,&dst,&msgid,rxbuf);
   /* should check status of respnse here  TODO*/

  
  // set the device id
  lora_send_command(LORAWAN_ID,LORAWAN_MSG_SET_DEVICE_EUI_REQ,lora_devid_reverse, 16);

  /* await response */
   dst = 0;
   msgid = 0;  
   result = lora_receive_message(1000,&dst,&msgid,rxbuf);
   /* should check status of respnse here  TODO*/


  // set application mode
  msg1[0] = 0x00;
  lora_send_command(DEVMGMT_ID,DEVMGMT_MSG_GET_OPMODE_REQ,msg1, 1);


  /* await response */
   dst = 0;
   msgid = 0;  
   result = lora_receive_message(1000,&dst,&msgid,rxbuf);
   /* should check status of respnse here  TODO*/

  uint8_t join_msg[24];
  for (int i=0; i < 8; i++) {
    join_msg[i] = lora_devid[i];
  }
  for (int i=0; i < 16; i++) {
    join_msg[i+8] = lora_appkey[i];
  }
  lora_send_command(LORAWAN_ID,LORAWAN_MSG_SET_JOIN_PARAM_REQ,join_msg, 24);


  /* await response */
   dst = 0;
   msgid = 0;  
   result = lora_receive_message(1000,&dst,&msgid,rxbuf);
   /* should check status of respnse here  TODO*/


  // join
  lora_send_command(LORAWAN_ID,LORAWAN_MSG_JOIN_NETWORK_REQ,0, 0);  


  /* await response */
   dst = 0;
   msgid = 0;  
   result = lora_receive_message(1000,&dst,&msgid,rxbuf);
   /* should check status of respnse here  TODO*/


  for (int i=0; i < 10; i++) {
    // determine activation status
    lora_send_command(LORAWAN_ID,LORAWAN_MSG_GET_NWK_STATUS_REQ,0, 0);

      /* await response */
     dst = 0;
     msgid = 0;  
     result = lora_receive_message(1000,&dst,&msgid,rxbuf);

    /* check status response */
     if (msgid == LORAWAN_MSG_GET_NWK_STATUS_RSP) {
        // 0 = not active
        // 1 = ABP
        // 2 = OTA
        if(rxbuf[2] == 0x02) return true;
     }
      delay(1000);
     
  }
  
}


boolean lora_wait_for_packet_status()
{
   uint8_t dst = 0;
   uint8_t msgid = 0;
   bool result = lora_receive_message(10000,&dst,&msgid,rxbuf);
   if(dst!=LORAWAN_ID  || msgid!=LORAWAN_MSG_SEND_UDATA_TX_IND || msgid!= LORAWAN_MSG_SEND_CDATA_TX_IND ) return false;
   if(rxbuf[2] == 0x00) return true;
   if(rxbuf[2] == 0x01)
   {
      DEBUG("Channel");
      DEBUG(rxbuf[3]);
      DEBUG("Rate");
      DEBUG(rxbuf[4]);
      if(msgid==LORAWAN_MSG_SEND_CDATA_TX_IND) {
        DEBUG("NUM");
        DEBUG(rxbuf[5]);
      }
      return true;
   }
   return false; 
}

boolean lora_tx_unreliable(uint8_t* msg,uint8_t len)
{
  lora_send_message(LORAWAN_ID, LORAWAN_MSG_SEND_UDATA_REQ,msg, len);
  uint8_t dst = 0;
  uint8_t msgid = 0;
  bool result = lora_receive_message(4000,&dst,&msgid,rxbuf);

  if(!result || dst!=LORAWAN_ID  || msgid!=LORAWAN_MSG_SEND_UDATA_RSP)
  {
    DEBUG("Failed sending packet to radio");
    return false;
  }
  
  if(rxbuf[2]!=LORAWAN_STATUS_OK) 
    {
      lora_error_handler(dst,rxbuf[2]);
      return false;
    }

 lora_wait_for_packet_status();   
 dst=0;msgid=0;rxbuf[0]=0;
 result = lora_receive_message(10000,&dst,&msgid,rxbuf);
 if(msgid==0x16) DEBUG("RX TIMEOUT"); 
}

boolean lora_tx_reliable(uint8_t* msg,uint8_t len)
{
  lora_send_message(LORAWAN_ID, LORAWAN_MSG_SEND_CDATA_REQ,msg, len);
  uint8_t dst = 0;
  uint8_t msgid = 0;
  uint8_t result = lora_receive_message(4000,&dst,&msgid,rxbuf);

  if(!result || dst!=LORAWAN_ID  || msgid!=LORAWAN_MSG_SEND_CDATA_RSP)
  {
    DEBUG("Failed sending packet to radio");
    return false;
  }
  
  if(rxbuf[2]!=LORAWAN_STATUS_OK) 
    {
      lora_error_handler(dst,rxbuf[2]);
      return false;
    }

 lora_wait_for_packet_status();   
 dst=0;msgid=0;rxbuf[0]=0;
 result = lora_receive_message(10000,&dst,&msgid,rxbuf);
 rx_count = result;
 DEBUG("RXC:");
 DEBUG(rx_count);
 if(msgid==0x16) DEBUG("... RX TIMEOUT"); 
}

uint8_t lora_available()
{
  return rx_count;
}


void lora_error_handler(uint8_t endpoint,uint8_t error)
{
  if(endpoint==DEVMGMT_ID)
  {
    String error_out = "LoRa device error - : ";
    switch(error)
    {
      case 1:
      error_out+="ERROR";
      break;
      case 2:
      error_out+="COMMAND NOT SUPPORTED";
      break;
      case 3:
      error_out+="WRONG PARAMETER";
      break;
      default:
      error_out+="UNKOWN ERROR";
      break;
    }
    Serial.println(error_out);
  }
  if(endpoint==LORAWAN_ID)
  {
    String error_out = "LoRa stack error - : ";
    switch(error)
    {
      case 1:
      error_out+="ERROR";
      break;
      case 2:
      error_out+="COMMAND NOT SUPPORTED";
      break;
      case 3:
      error_out+="WRONG PARAMETER";
      break;
      case 4:
      error_out+="WRONG DEVICE MODE";
      break;  
      case 5:
      error_out+="DEVICE NOT ACTIVATED";
      break; 
      case 6:
      error_out+="DEVICE BUSY";
      break;      
      case 7:
      error_out+="QUEUE FULL";
      break;      
      case 8:
      error_out+="LENGTH ERROR";
      break;      
      case 9:
      error_out+="NO FACTORY SETTINGS";
      break;
      default:
      error_out+="UNKNOWN ERROR";
      break;
    }
    Serial.println(error_out);
  }
}


void lora_send_command(uint8_t dst, uint8_t msgid, uint8_t* tx, uint8_t len)
{
  len++;
  uint8_t packet[len+6];
  packet[0] = 0xC0;
  packet[1] = dst;
  packet[2] = msgid;
  uint8_t i=0;
  for(i=0;i<len;i++)
  {
    packet[i+3] = *tx++;
  }
  uint16_t crc16 = CRC16_Calc(&packet[1], 2+len, CRC16_INIT_VALUE);
  crc16 = ~crc16;
  
  packet[3+len] = crc16&0xFF;
  packet[3+len+1] = crc16>>8;
  packet[3+len+2] = 0xC0;
  DEBUG("... Transmitting packet");

  i=0;
  while(i++<45) Serial1.write(0x00);
  Serial1.write(packet,3+len+3);
}


void lora_send_message(uint8_t dst, uint8_t msgid, uint8_t* tx, uint8_t len)
{
  len++;
  uint8_t packet[len+6];
  packet[0] = 0xC0;
  packet[1] = dst;
  packet[2] = msgid;
  packet[3] = 0x01;
  uint8_t i=0;
  for(i=0;i<len;i++)
  {
    packet[i+4] = *tx++;
  }
  uint16_t crc16 = CRC16_Calc(&packet[1], 2+len, CRC16_INIT_VALUE);
  crc16 = ~crc16;
  
  packet[3+len] = crc16&0xFF;
  packet[3+len+1] = crc16>>8;
  packet[3+len+2] = 0xC0;
  DEBUG("... Transmitting packet");

  i=0;
  while(i++<45) Serial1.write(0x00);
  Serial1.write(packet,3+len+3);
}

uint8_t lora_receive_message(uint16_t timeout, uint8_t* dst, uint8_t* msgid, uint8_t* buff)
{
  uint32_t current_time = millis();
  while(Serial1.available()<6) // wait for at least the headers
    {
      if(millis()>(current_time+timeout)) 
        {
          DEBUG("... Message receive timeout");
          return 0; // response timeout
        }
    }

  if(Serial1.read()!= 0xC0)
    {
      DEBUG("... Invalid SLIP Wrapper start");
      return 0; // Invalid slip wrapper
    }

  uint8_t packet_length=2; // Implicit from packet;
  *dst = Serial1.read();
  *msgid = Serial1.read();
  buff[0] = *dst;
  buff[1] = *msgid;
  while(Serial1.available())
  {
   while(Serial1.available())
   {
    buff[packet_length] = Serial1.read();
   // Serial.println(buff[packet_length],HEX);
    packet_length++;
   }
   delay(1); // Give the port time to receive next char
  }
  uint8_t j=0;
  DEBUG("... Length: ");
  DEBUG(packet_length);
  DEBUG("... Content: ");
//  for(j=0;j<packet_length;j++)
//  {
//  Serial.println(buff[j],HEX);
//  }
  if(packet_length==0 || buff[packet_length-1]!=0xC0)
    {
      DEBUG("... Invalid SLIP Wrapper end");
      return 0; // No valid crc or slip wrapper
    }
    
  uint16_t msgcrc = (buff[packet_length-2]<<8) | (buff[packet_length-3]&0xFF);
  uint16_t crc16 = CRC16_Calc(buff, packet_length-3, CRC16_INIT_VALUE);
  crc16 = ~crc16;

  if(msgcrc!=crc16) {
    String returnstr = "... Invalid CRC, expected: ";
    returnstr +=msgcrc;
    returnstr +=", got ";
    returnstr +=crc16;
    DEBUG(returnstr);
    return 0;
  }
  DEBUG("... Received a packet");
  return packet_length-3;
}


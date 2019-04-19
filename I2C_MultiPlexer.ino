#include "TDA743X.h"

TDA7430 uPA;
//TDA7431 uPA;
//TDA7432 uPA;

void setup() {
  Wire.begin();
  uPA.InstalWire(&Wire);
  // Instal Wire

  uPA.setMultiPlexer(Yes_UseSwitch,Use_TCA9548A);
  //                 Value        ,Name IC
  // Default => No_UseSwitch 
  // Value   => No_UseSwitch or Yes_UseSwitch
  
  uPA.setAddressMultiPlexer(0x70   ,0 ,0 ,0 ,0);
  //                        Address,A0,A1,A2,0
  
  uPA.setChannel(0);
  //             Value
  // Value => 0 ~ 7

}

void loop() {
  // put your main code here, to run repeatedly:
}

# TDA743X => Library TDA7430 or TDA7431 or TDA7432

Example Param:
#include "TDA743X.h"
TDA7430 uPA;

void setup(){
  Wire.begin();
  Serial.begin(9600);
  int value = uPA.begin();
  if(value != Process_OK){
    return;
  }
}

void loop(){

}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TDA7430 & TDA7431
  int8_t begin();             
  int8_t begin(byte Address); //Address  
  int8_t begin(byte Address,  //Address
               byte Addr);    //pin Addr
  // Address => 0x80 (FIX => TDA7430)
  // Addr => pinAddr (Only TDA7431)

  int8_t UseValue(int8_t val); // Default => Use_POSITIVE
  // Use_POSITIVE or Use_NEGATIVE
  
  int8_t Input(int8_t val);   //Input
  // TDA7430 maks Input => 4
  // TDA7431 maks Input => 1 (FIX)
  
  int8_t Volume(int8_t val);  //Volume
  // UserValue == Use_POSITIVE => Volume 0 ~ 63
  // UserValue == Use_NEGATIVE => Volume -63 ~ 0
  
  int8_t Bass(int8_t val);    //Bass 
  // value => -7 ~ 7
  
  int8_t Middle(int8_t val);  //Middle
  // value => -7 ~ 7
  
  int8_t Treble(int8_t val);  //Treble
  // value => -7 ~ 7
  
  int8_t Balance(int8_t val);               //Value
  int8_t Balance(int8_t val,int8_t val2);   //Value,channel
  // UserValue == Use_POSITIVE => value 0 ~ 79
  // UserValue == Use_NEGATIVE => Volume -79 ~ 0
  // Channel => ATT_LR,ATT_RR,ATT_LF, or ATT_RF

  int8_t NaturalBase(int8_t val); //NaturalBase
  // Value => NATURALBASE_ACTIVE or NATURALBASE_OFF
  
  int8_t EnableNaturalBase();     //Enable
  int8_t DisableNaturalBase();    //Disable

  int8_t RearSwitch(int8_t val);  //Rear
  // value => REAR_ACTIVE or REAR_OFF
  
  int8_t EnableRear();            //Enable
  int8_t DisableRear();           //Disable

  int8_t SurroundMode(int8_t val);  //Surround Mode
  int8_t Surround_SIMULATED();      //SIMULATED
  int8_t Surround_MUSIC();          //MUSIC
  int8_t Surround_MOVIE();          //MOVIE
  int8_t Surround_OFF();            //OFF
  // value => Surr_SIMULATED,Surr_MUSIC,Surr_MOVIE, or Surround_OFF
  
  int8_t EffectControl(int8_t val); //EffectControl
  // value => -6 ~ -21
  
  int8_t PhaseResistor(int8_t val);     // 0 -  255
  int8_t PhaseResistor(int8_t val,      // 0 - 3
                       int8_t val1,     // 0 - 3
                       int8_t val2,     // 0 - 3
                       int8_t val3);    // 0 - 3
//   int8_t PhaseResistor1(int8_t val);    // 0 - 3
//   int8_t PhaseResistor2(int8_t val);    // 0 - 3
//   int8_t PhaseResistor3(int8_t val);    // 0 - 3
//   int8_t PhaseResistor4(int8_t val);    // 0 - 3

  int8_t VoiceCanceller(int8_t val);    //VoiceCanceler
  // value => VOICECANCELLER_OFF or VOICECANCELLER_ON
  
  int8_t DisableVoiceCanceller();       //Disable
  int8_t EnableVoiceCanceller();        //Enable

  int8_t SelectorRecOut(int8_t val);    // Value
  int8_t SelectorRecOut(int8_t val,     // Value
                        int8_t val2);   // Channel
  int8_t RecOut_3BAND();                // 3Band
  int8_t RecOut_SURR();                 // Surr
  int8_t RecOut_REAR();                 // Rear
  int8_t RecOut_OFF();                  // Off
  int8_t RecOut_FLAT();                 // Flat
  // Value => Out_3BAND,Out_SURR,Out_REAR,Out_OFF, or Out_FLAT
  // Channel => ATT_LR,ATT_RR,ATT_LF, or ATT_RF
  
  int8_t Mute(int8_t val);              // Value
  int8_t Mute(int8_t val,int8_t val2);  // Value,Channel
  int8_t DisableMute();                 // Disable
  int8_t EnableMute();                  // Enable
  // Value => MUTE_OFF or MUTE_ON
  // Channel => ATT_LR,ATT_RR,ATT_LF, or ATT_RF
  
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  TDA7432
  
  int8_t Volume(int8_t val);  //Volume
  // UserValue == Use_POSITIVE => Volume 0 ~ 63
  // UserValue == Use_NEGATIVE => Volume -63 ~ 0
  
  int8_t Bass(int8_t val);    //Bass 
  // value => -7 ~ 7
  
  int8_t Treble(int8_t val);  //Treble
  // value => -7 ~ 7
  
  int8_t UseValue(int8_t val); // Default => Use_POSITIVE
  // Use_POSITIVE or Use_NEGATIVE
  
  int8_t Balance(int8_t val);               //Value
  int8_t Balance(int8_t val,int8_t val2);   //Value,channel
  // UserValue == Use_POSITIVE => value 0 ~ 79
  // UserValue == Use_NEGATIVE => Volume -79 ~ 0
  // Channel => ATT_LR,ATT_RR,ATT_LF, or ATT_RF

  int8_t Input(int8_t val);   //Input
  // TDA7430 maks Input => 2
  
  int8_t Mute(int8_t val);              // Value
  int8_t Mute(int8_t val,int8_t val2);  // Value,Channel
  int8_t DisableMute();                 // Disable
  int8_t EnableMute();                  // Enable
  // Value => MUTE_OFF or MUTE_ON
  // Channel => ATT_LR,ATT_RR,ATT_LF, or ATT_RF
  
  int8_t Loudness(int8_t val);          // Value
  // UserValue == Use_POSITIVE => Loudness 0 ~ 15
  // UserValue == Use_NEGATIVE => Loudness -15 ~ 0
  
  int8_t ModeLoudness(int8_t val);      // Value
  // Value => Loudness_ON or Loudness_OFF
  int8_t EnableModeLoudness();          // Enable
  int8_t DisableModeLoudness();         // Disable

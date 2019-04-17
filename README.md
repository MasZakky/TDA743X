# TDA743X => Library TDA7430 or TDA7431 or TDA7432

Example Param: </br>
#include "TDA743X.h" </br>
TDA7430 uPA;  </br>

void setup(){ </br>
  Wire.begin(); </br>
  Serial.begin(9600); </br>
  int value = uPA.begin(); </br>
  if(value == Process_OK){ </br>
    Serial.println("Process_OK");  </br>
    return; </br>
  } // if </br>
  else{ </br>
    Serial.println("Process_ERROR"); </br>
  } </br>
} </br>
</br>
void loop(){ </br>
</br>
} </br>
</br>
</br>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
<h6>TDA7430 & TDA7431 </h6></br>
  int8_t begin(); </br>            
  int8_t begin(byte Address); //Address </br>
  int8_t begin(byte Address,  //Address </br>
               byte Addr);    //pin Addr </br>
  // Address => 0x80 (FIX => TDA7430) </br>
  // Addr => pinAddr (Only TDA7431) </br>
  </br>
  int8_t UseValue(int8_t val); // Default => Use_POSITIVE </br>
  // Use_POSITIVE or Use_NEGATIVE </br>
  </br>
  int8_t Input(int8_t val);   //Input </br>
  // TDA7430 maks Input => 4 </br>
  // TDA7431 maks Input => 1 (FIX) </br>
  </br>
  int8_t Volume(int8_t val);  //Volume </br>
  // UserValue == Use_POSITIVE => Volume 0 ~ 63 </br>
  // UserValue == Use_NEGATIVE => Volume -63 ~ 0 </br>
  </br>
  int8_t Bass(int8_t val);    //Bass </br>
  // value => -7 ~ 7 </br>
  </br>
  int8_t Middle(int8_t val);  //Middle </br>
  // value => -7 ~ 7
  </br>
  int8_t Treble(int8_t val);  //Treble </br>
  // value => -7 ~ 7 </br>
  </br>
  int8_t Balance(int8_t val);               //Value </br>
  int8_t Balance(int8_t val,int8_t val2);   //Value,channel </br>
  // UserValue == Use_POSITIVE => value 0 ~ 79 </br>
  // UserValue == Use_NEGATIVE => Volume -79 ~ 0 </br>
  // Channel => ATT_LR,ATT_RR,ATT_LF, or ATT_RF </br> 
  </br>
  int8_t NaturalBase(int8_t val); //NaturalBase </br>
  // Value => NATURALBASE_ACTIVE or NATURALBASE_OFF </br>
   </br>
  int8_t EnableNaturalBase();     //Enable </br>
  int8_t DisableNaturalBase();    //Disable </br>
 </br>
  int8_t RearSwitch(int8_t val);  //Rear </br>
  // value => REAR_ACTIVE or REAR_OFF </br>
   </br>
  int8_t EnableRear();            //Enable </br>
  int8_t DisableRear();           //Disable </br>
 </br>
  int8_t SurroundMode(int8_t val);  //Surround Mode </br>
  int8_t Surround_SIMULATED();      //SIMULATED </br>
  int8_t Surround_MUSIC();          //MUSIC </br>
  int8_t Surround_MOVIE();          //MOVIE </br>
  int8_t Surround_OFF();            //OFF </br>
  // value => Surr_SIMULATED,Surr_MUSIC,Surr_MOVIE, or Surround_OFF </br>
   </br>
  int8_t EffectControl(int8_t val); //EffectControl </br>
  // value => -6 ~ -21 </br>
   </br>
  int8_t PhaseResistor(int8_t val);     // 0 -  255 </br>
  int8_t PhaseResistor(int8_t val,      // 0 - 3 </br>
                       int8_t val1,     // 0 - 3 </br>
                       int8_t val2,     // 0 - 3 </br>
                       int8_t val3);    // 0 - 3 </br>
//   int8_t PhaseResistor1(int8_t val);    // 0 - 3 </br>
//   int8_t PhaseResistor2(int8_t val);    // 0 - 3 </br>
//   int8_t PhaseResistor3(int8_t val);    // 0 - 3 </br>
//   int8_t PhaseResistor4(int8_t val);    // 0 - 3 </br>
 </br>
  int8_t VoiceCanceller(int8_t val);    //VoiceCanceler </br>
  // value => VOICECANCELLER_OFF or VOICECANCELLER_ON </br>
   </br>
  int8_t DisableVoiceCanceller();       //Disable </br>
  int8_t EnableVoiceCanceller();        //Enable </br>
 </br>
  int8_t SelectorRecOut(int8_t val);    // Value </br>
  int8_t SelectorRecOut(int8_t val,     // Value </br>
                        int8_t val2);   // Channel </br>
  int8_t RecOut_3BAND();                // 3Band </br>
  int8_t RecOut_SURR();                 // Surr </br>
  int8_t RecOut_REAR();                 // Rear </br>
  int8_t RecOut_OFF();                  // Off </br>
  int8_t RecOut_FLAT();                 // Flat </br>
  // Value => Out_3BAND,Out_SURR,Out_REAR,Out_OFF, or Out_FLAT </br>
  // Channel => ATT_LR,ATT_RR,ATT_LF, or ATT_RF </br>
   </br>
  int8_t Mute(int8_t val);              // Value </br>
  int8_t Mute(int8_t val,int8_t val2);  // Value,Channel </br>
  int8_t DisableMute();                 // Disable </br>
  int8_t EnableMute();                  // Enable </br>
  // Value => MUTE_OFF or MUTE_ON </br>
  // Channel => ATT_LR,ATT_RR,ATT_LF, or ATT_RF </br>
   </br>
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  <h6>TDA7432</h6>
   </br>
  int8_t Volume(int8_t val);  //Volume </br>
  // UserValue == Use_POSITIVE => Volume 0 ~ 63 </br> </br>
  // UserValue == Use_NEGATIVE => Volume -63 ~ 0 </br>
   </br>
  int8_t Bass(int8_t val);    //Bass  </br>
  // value => -7 ~ 7 </br>
   </br>
  int8_t Treble(int8_t val);  //Treble </br>
  // value => -7 ~ 7 </br>
   </br>
  int8_t UseValue(int8_t val); // Default => Use_POSITIVE </br>
  // Use_POSITIVE or Use_NEGATIVE </br>
   </br>
  int8_t Balance(int8_t val);               //Value </br>
  int8_t Balance(int8_t val,int8_t val2);   //Value,channel </br>
  // UserValue == Use_POSITIVE => value 0 ~ 79 </br>
  // UserValue == Use_NEGATIVE => Volume -79 ~ 0 </br>
  // Channel => ATT_LR,ATT_RR,ATT_LF, or ATT_RF </br>
 </br>
  int8_t Input(int8_t val);   //Input  </br>
  // TDA7430 maks Input => 2 </br>
   </br>
  int8_t Mute(int8_t val);              // Value </br>
  int8_t Mute(int8_t val,int8_t val2);  // Value,Channel </br>
  int8_t DisableMute();                 // Disable </br>
  int8_t EnableMute();                  // Enable </br>
  // Value => MUTE_OFF or MUTE_ON </br>
  // Channel => ATT_LR,ATT_RR,ATT_LF, or ATT_RF </br>
   </br>
  int8_t Loudness(int8_t val);          // Value </br>
  // UserValue == Use_POSITIVE => Loudness 0 ~ 15 </br>
  // UserValue == Use_NEGATIVE => Loudness -15 ~ 0 </br>
   </br>
  int8_t ModeLoudness(int8_t val);      // Value </br>
  // Value => Loudness_ON or Loudness_OFF </br>
  int8_t EnableModeLoudness();          // Enable </br>
  int8_t DisableModeLoudness();         // Disable </br>
 </br>

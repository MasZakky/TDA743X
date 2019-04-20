#include "TDA743X.h"

TDA7432 uPA;

void setup() {
  Wire.begin();
  uPA.setAddress(0x80);
  
  uPA.InstalWire(&Wire);      // Instal Wire
//  uPA.InstalWire(&Wire1);   // Instal Wire1
//  uPA.InstalWire(&Wire2);   // Instal Wire2

  uPA.UseValue(Use_POSITIVE);   //UsePOSITIVE
//  uPA.UseValue(Use_NEGATIVE);   //UseNEGATIVE

  uPA.Input(1);       // Input 1
//  uPA.Input(2);       // Input 2
  
  uPA.Volume(0);      // 0  dB (1dB Step)
  // UseValue == Use_POSITIVE => 0 ~ 63  => 0 dB ~ -63dB
  // UseValue == Use_NEGATIVE => -63 ~0  => 0 dB ~ -63dB
  
  uPA.Bass(7);        // 14 dB 
  // Value -7 ~ 7  => -14dB ~ 14dB (2dB Step)
  
  uPA.Treble(7);      // 14 dB
  // Value -7 ~ 7  => -14dB ~ 14dB (2dB Step);

  uPA.Balance(0);         // 0 dB ALL OUTPUT (1dB Step)
//  uPA.Balance(0,ATT_LR);  // 0 dB Output ATT_LR
//  uPA.Balance(0,ATT_RR);  // 0 dB Output ATT_RR
//  uPA.Balance(0,ATT_LF);  // 0 dB Output ATT_LF
//  uPA.Balance(0,ATT_RF);  // 0 dB Output ATT_RF

  uPA.Mute(MUTE_OFF);           //MUTE_OFF
//  uPA.Mute(MUTE_ON);            // MUTE_ON
//  uPA.Mute(MUTE_OFF,ATT_LR);    // MUTE_OFF ,ATT_LR  
//  uPA.Mute(MUTE_ON, ATT_RR);    // MUTE_ON  ,ATT_LR
//  uPA.Mute(MUTE_OFF,ATT_LR);    // MUTE_OFF ,ATT_RR  
//  uPA.Mute(MUTE_ON, ATT_RR);    // MUTE_ON  ,ATT_RR
//  uPA.Mute(MUTE_OFF,ATT_LR);    // MUTE_OFF ,ATT_LF  
//  uPA.Mute(MUTE_ON, ATT_RR);    // MUTE_ON  ,ATT_LF
//  uPA.Mute(MUTE_OFF,ATT_LR);    // MUTE_OFF ,ATT_RF  
//  uPA.Mute(MUTE_ON, ATT_RR);    // MUTE_ON  ,ATT_RF
//  uPA.DisableMute();        // Disable
//  uPA.EnableMute();         // Enable

  uPA.Loudness(0);      // 0dB (1dB Step)
  // UseValue == Use_POSITIVE => 0 ~ 15  => 0 dB ~ -15dB
  // UseValue == Use_NEGATIVE => -15 ~0  => 0 dB ~ -15dB

  uPA.ModeLoudness(Loudness_ON);      // Loudness_ON
//  uPA.ModeLoudness(Loudness_OFF);   // Loudness_OFF
//  uPA.EnableModeLoudness();         // Loudness_ON  or Enable
//  uPA.DisableModeLoudness();        // Loudness_OFF or Disable
}

void loop() {
  // put your main code here, to run repeatedly:
}

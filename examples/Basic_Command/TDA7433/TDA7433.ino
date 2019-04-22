#include "TDA743X.h"

TDA7433 uPA;

void setup() {
  Wire.begin();
  uPA.begin();
  
uPA.InstalWire(&Wire);      // Instal Wire
//  uPA.InstalWire(&Wire1);   // Instal Wire1
//  uPA.InstalWire(&Wire2);   // Instal Wire2

uPA.UseValue(Use_POSITIVE);   //UsePOSITIVE
//  uPA.UseValue(Use_NEGATIVE);   //UseNEGATIVE

uPA.Input(1);       // Input 1
//  uPA.Input(2);       // Input 2
//  uPA.Input(3);       // Input 3
  
uPA.Volume(0);      // 0  dB (1dB Step)
  // UserValue == Use_POSITIVE => Volume 0 ~ 63  => 0dB ~ -31.5dB 
  // UserValue == Use_NEGATIVE => Volume -63 ~ 0 => -31.5dB ~ 0dB 
  
uPA.Bass(7);        // 14 dB 
  // Value -7 ~ 7  => -14dB ~ 14dB (2dB Step)
  
uPA.Treble(7);      // 14 dB
  // Value -7 ~ 7  => -14dB ~ 14dB (2dB Step);

uPA.Balance(0);         // 0 dB ALL OUTPUT (1dB Step)
//  uPA.Balance(0,ATT_LR);  // 0 dB Output ATT_LR
//  uPA.Balance(0,ATT_RR);  // 0 dB Output ATT_RR
//  uPA.Balance(0,ATT_LF);  // 0 dB Output ATT_LF
//  uPA.Balance(0,ATT_RF);  // 0 dB Output ATT_RF
  // UserValue == Use_POSITIVE => Balance 0 ~ 79  => 0dB ~ -79dB (1dB Step)
  // UserValue == Use_NEGATIVE => Balance -79 ~ 0 => -79dB ~ 0dB (1dB Step)
  // Channel => ATT_LR,ATT_RR,ATT_LF, or ATT_RF

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
  // Value   => MUTE_OFF or MUTE_ON 
  // Channel => ATT_LR,ATT_RR,ATT_LF, or ATT_RF 

uPA.ExtendedBassRange(Yes_ExtendedBassRange);
//  uPA.ExtendedBassRange(Not_ExtendedBassRange);
  // Value   => Yes_ExtendedBassRange or Not_ExtendedBassRange
  
uPA.SymmetricalBassCut(Not_SymmetricalBassCut);
//  uPA.SymmetricalBassCut(Yes_SymmetricalBassCut);
  // Value   => Not_SymmetricalBassCut or Yes_SymmetricalBassCut
}

void loop() {
  // put your main code here, to run repeatedly:
}

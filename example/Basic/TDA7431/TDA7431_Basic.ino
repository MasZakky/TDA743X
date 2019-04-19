#include "TDA743X.h"

TDA7431 uPA;

void setup() {
  Wire.begin();
  uPA.begin();
//  uPA.begin(0x80);  // Address
  
  uPA.InstalWire(&Wire);      // Instal Wire
//  uPA.InstalWire(&Wire1);   // Instal Wire1
//  uPA.InstalWire(&Wire2);   // Instal Wire2

  uPA.UseValue(Use_POSITIVE);   //UsePOSITIVE
//  uPA.UseValue(Use_NEGATIVE);   //UseNEGATIVE

//  uPA.Input(1);       // FIX

  uPA.Volume(0);      // 0  dB (1dB Step)
  // UseValue == Use_POSITIVE => 0 ~ 63  => 0 dB ~ -63dB
  // UseValue == Use_NEGATIVE => -63 ~0  => 0 dB ~ -63dB
  
  uPA.Bass(7);        // 14 dB 
  // Value -7 ~ 7  => -14dB ~ 14dB (2dB Step)
  
  uPA.Middle(7);      // 14 dB
  // Value -7 ~ 7  => -14dB ~ 14dB (2dB Step);
  
  uPA.Treble(7);      // 14 dB
  // Value -7 ~ 7  => -14dB ~ 14dB (2dB Step);

  uPA.Balance(0);         // 0 dB ALL OUTPUT (1dB Step)
//  uPA.Balance(0,ATT_LR);  // 0 dB Output ATT_LR
//  uPA.Balance(0,ATT_RR);  // 0 dB Output ATT_RR
//  uPA.Balance(0,ATT_LF);  // 0 dB Output ATT_LF
//  uPA.Balance(0,ATT_RF);  // 0 dB Output ATT_RF

  uPA.NaturalBase(NATURALBASE_ACTIVE);  // NATURALBASE_ACTIVE
//  uPA.NaturalBase(NATURALBASE_OFF);   // NATURALBASE_OFF
//  uPA.EnableNaturalBase();            // Enable  or Active
//  uPA.DisableNaturalBase();           // Disable or Off

  uPA.SelectorRecOut(Out_3BAND);          // Channel ATT_LR & ATT_RR  
//  uPA.SelectorRecOut(Out_SURR);           // Channel ATT_LR & ATT_RR  
//  uPA.SelectorRecOut(Out_REAR);           // Channel ATT_LR & ATT_RR  
//  uPA.SelectorRecOut(Out_OFF);            // Channel ATT_LR & ATT_RR   
//  uPA.SelectorRecOut(Out_FLAT);           // Channel ATT_LR & ATT_RR 
//  uPA.SelectorRecOut(Out_3BAND,ATT_LR);   // Channel ATT_LR 
//  uPA.SelectorRecOut(Out_SURR, ATT_LR);   // Channel ATT_LR 
//  uPA.SelectorRecOut(Out_REAR, ATT_LR);   // Channel ATT_LR 
//  uPA.SelectorRecOut(Out_OFF,  ATT_LR);   // Channel ATT_LR 
//  uPA.SelectorRecOut(Out_FLAT, ATT_LR);   // Channel ATT_LR 
//  uPA.SelectorRecOut(Out_3BAND,ATT_RR);   // Channel ATT_RR  
//  uPA.SelectorRecOut(Out_SURR, ATT_RR);   // Channel ATT_RR  
//  uPA.SelectorRecOut(Out_REAR, ATT_RR);   // Channel ATT_RR  
//  uPA.SelectorRecOut(Out_OFF,  ATT_RR);   // Channel ATT_RR   
//  uPA.SelectorRecOut(Out_FLAT, ATT_RR);   // Channel ATT_RR  
//  uPA.RecOut_3BAND();                     // 3BAND
//  uPA.RecOut_SURR();                      // SURR
//  uPA.RecOut_REAR();                      // REAR
//  uPA.RecOut_OFF();                       // OFF
//  uPA.RecOut_FLAT();                      // FLAT

  uPA.(MUTE_OFF);           //MUTE_OFF
//  uPA.(MUTE_ON);            // MUTE_ON
//  uPA.(MUTE_OFF,ATT_LR);    // MUTE_OFF ,ATT_LR  
//  uPA.(MUTE_ON, ATT_RR);    // MUTE_ON  ,ATT_LR
//  uPA.(MUTE_OFF,ATT_LR);    // MUTE_OFF ,ATT_RR  
//  uPA.(MUTE_ON, ATT_RR);    // MUTE_ON  ,ATT_RR
//  uPA.(MUTE_OFF,ATT_LR);    // MUTE_OFF ,ATT_LF  
//  uPA.(MUTE_ON, ATT_RR);    // MUTE_ON  ,ATT_LF
//  uPA.(MUTE_OFF,ATT_LR);    // MUTE_OFF ,ATT_RF  
//  uPA.(MUTE_ON, ATT_RR);    // MUTE_ON  ,ATT_RF
//  uPA.DisableMute();        // Disable
//  uPA.EnableMute();         // Enable

}

void loop() {
  // put your main code here, to run repeatedly:
}

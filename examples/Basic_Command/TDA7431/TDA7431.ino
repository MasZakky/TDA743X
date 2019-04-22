#include "TDA743X.h"

TDA7431 uPA;

void setup() {
  Wire.begin();
  uPA.begin();
//  uPA.begin(0x80);  // Address
//  uPA.begin(0x80,1);
  
uPA.InstalWire(&Wire);      // Instal Wire
//  uPA.InstalWire(&Wire1);   // Instal Wire1
//  uPA.InstalWire(&Wire2);   // Instal Wire2

uPA.UseValue(Use_POSITIVE);   //UsePOSITIVE
//  uPA.UseValue(Use_NEGATIVE);   //UseNEGATIVE

//  uPA.Input(1);       // FIX

uPA.Volume(0);      // 0  dB (1dB Step)
  // UserValue == Use_POSITIVE => Volume 0 ~ 63  => 0dB ~ -31.5dB (0.5dB Step)
  // UserValue == Use_NEGATIVE => Volume -63 ~ 0 => -31.5dB ~ 0dB (0.5dB Step)
  
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
  // UserValue == Use_POSITIVE => Balance 0 ~ 79  => 0dB ~ -79dB (1dB Step)
  // UserValue == Use_NEGATIVE => Balance -79 ~ 0 => -79dB ~ 0dB (1dB Step)
  // Channel => ATT_LR,ATT_RR,ATT_LF, or ATT_RF 
  
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

uPA.RearSwitch(REAR_ACTIVE);
// uPA.int8_t RearSwitch(REAR_OFF);
// uPA.EnableRear();            
// uPA.DisableRear();           

uPA.SurroundMode(Surr_OFF);  
// uPA.SurroundMode(Surr_MUSIC);  
// uPA.SurroundMode(Surr_SIMULATED);  
// uPA.SurroundMode(Surr_MOVIE);  
// uPA.Surround_SIMULATED();    
// uPA.Surround_MUSIC();         
// uPA.Surround_MOVIE();        
// uPA.Surround_OFF();     
  // Value   => Surr_SIMULATED,Surr_MUSIC,Surr_MOVIE, or Surr_OFF 

uPA.EffectControl(-6); // -6 ~ -21

// uPA.PhaseResistor(int8_t val);     // 0 - 255 
uPA.PhaseResistor(3,3,3,3);

uPA.VoiceCanceller(VOICECANCELLER_OFF); 
// uPA.VoiceCanceller(VOICECANCELLER_ON); 
// uPA.DisableVoiceCanceller();
// uPA.EnableVoiceCanceller();
  
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

}

void loop() {
  // put your main code here, to run repeatedly:
}

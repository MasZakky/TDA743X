# TDA743X 
<h3>Library</h3>
<ul>
  <li><a href="https://www.mouser.com/datasheet/2/389/CD00000226-470817.pdf"                      target="_blank">TDA7430</a> OK</li>
  <li><a href="https://www.mouser.com/datasheet/2/389/CD00000226-470817.pdf"                      target="_blank">TDA7431</a> OK</li>
  <li><a href="https://www.st.com/resource/en/datasheet/CD00000874.pdf"                           target="_blank">TDA7432</a> OK</li>
  <li><a href="https://www.st.com/resource/en/datasheet/cd00000878.pdf"                           target="_blank">TDA7433</a> OK</li>
  <li><a href="http://pdf.datasheetcatalog.com/datasheet/stmicroelectronics/4062.pdf"             target="_blank">TDA7434</a> OK</li>
  <li><a href="https://www.st.com/resource/en/datasheet/CD00001003.pdf"                           target="_blank">TDA7438</a> OK</li>
  <li><a href="https://www.st.com/resource/en/datasheet/cd00004906.pdf"                           target="_blank">TDA7439</a> OK</li>
<ul>

<h3>Download Library !! </h3>
<h4>(Right Mouse Button + Open Link In New Tab)</h4>
<ul>
  <li><a href=https://github.com/MasZakky/SendTrans">Library SendTrans</a></li>
  <li><a href=https://github.com/MasZakky/TDA743X"  >Library TDA743X</a></li>
  <li><a href=https://github.com/MasZakky/TDA744X"  >Library TDA744X</a></li>
  <li><a href=https://github.com/MasZakky/PT231X"   >Library PT231X</a></li>
</ul>

<h5>Example Param</h5>

    #include "TDA743X.h"
    TDA7430 uPA;  
    //TDA7431 uPA;
    //TDA7432 uPA;
    //TDA7433 uPA;
    //TDA7434 uPA;
    //TDA7435 uPA;
    //TDA7437 uPA;
    //TDA7438 uPA;
    //TDA7439 uPA;
    
    void setup(){ 
      Wire.begin();
      uPA.InstalWire(&Wire);
      Serial.begin(9600); 
      
      if(uPA.InstalWire(&Wire) != Process_OK) Serial.println("Process_ERROR");
      else Serial.println("Process_OK");
      
      if(uPA.begin() =! Process_OK) Serial.print("Process_ERROR");
      else Serial.println("Process_OK");
      
    } // void setup
    
    void loop(){
    // Do something?
    } 

<h3> Main </h3>
<h4><a href="https://github.com/MasZakky/SendTrans" target="_blank"> Command </a>: </h4>
      
    1. int8_t InstalWire(TwoWire *val);
         Default => NULL
         Syntax:
         - InstalWire(&Wire);
         - InstalWire(&Wire1);
         - InstalWire(&Wire2);
         
    // additional
    2. int8_t setMultiPlexer(int8_t val,int8_t val2);
                       Value     ,IC MuliPlexer
         Default => Not_UseSwitch & Use_TCA9548A 
         Value   => Not_UseSwitch or Yes_UseSwitch
         IC      => Use_TCA9548A
    
    3. int8_t setAddressMultiPlexer(byte Address,byte val1,byte val2,byte val3,byte val4);
                                 Value       ,A0       ,A1       ,A2       ,A3 or 0
         Default     => _AddressTCA9548A & A0 = 0 & A1 = 0 & A2 = 0 & A3 = 0                           
         Value       => Address IC MuliPlexer
         pinAddr     => A0,A1,A2,A3/0
    
    4. int8_t setChannel(int8_t val);
                      Channel
         Default => 0
         Channel => 0 ~ 7
    
<h3>TDA7430 & TDA7431 </h3>
<h4> Command : </h4>

    1.  int8_t begin();            
    2.  int8_t begin(byte Address); 
    3.  int8_t begin(byte Address,byte Addr);
                    Address     ,pinAddr
          Address => 0x80 (FIX => TDA7430 & TDA7431) 
          Addr    => pinAddr (Only TDA7431) 

    4.  int8_t UseValue(int8_t val); 
          Default => Use_POSITIVE 
          Value   => Use_POSITIVE or Use_NEGATIVE 

    5.  int8_t Input(int8_t val); 
          Default  => 1
          TDA7430 maks Input => 4       (4 Stereo)
          TDA7431 maks Input => 1 (FIX) (1 Stereo)
    
    6.  int8_t Volume(int8_t val);
          Default => 0 (0dB)
          UserValue == Use_POSITIVE => Volume 0 ~ 63  => 0dB ~ -31.5dB (0.5dB Step)
          UserValue == Use_NEGATIVE => Volume -63 ~ 0 => -31.5dB ~ 0dB (0.5dB Step)
    
    7.  int8_t Bass(int8_t val);
          Default => 7 (14dB)
          Value   => -7 ~ 7 => -14dB ~ 14dB (2dB Step)
    
    8.  int8_t Middle(int8_t val);
          Default => 7 (14dB)
          Value   => -7 ~ 7 => -14dB ~ 14dB (2dB Step)
    
    9.  int8_t Treble(int8_t val);
          Default => 7 (14dB)
          Value   => -7 ~ 7 => -14dB ~ 14dB (2dB Step)
  
    10. int8_t Balance(int8_t val);
    11. int8_t Balance(int8_t val,int8_t val2);   
                       Value     ,Channel 
          Default => 0dB  
          UserValue == Use_POSITIVE => Balance 0 ~ 79  => 0dB ~ -79dB (1dB Step)
          UserValue == Use_NEGATIVE => Balance -79 ~ 0 => -79dB ~ 0dB (1dB Step)
          Channel => ATT_LR,ATT_RR,ATT_LF, or ATT_RF 
  
    12. int8_t NaturalBase(int8_t val);
          Default => NATURALBASE_ACTIVE 
          Value   => NATURALBASE_ACTIVE or NATURALBASE_OFF 
    
    13. int8_t EnableNaturalBase(); 
    14. int8_t DisableNaturalBase();
 
    15. int8_t SurroundMode(int8_t val);  
    16. int8_t Surround_SIMULATED();    
    17. int8_t Surround_MUSIC();         
    18. int8_t Surround_MOVIE();        
    19. int8_t Surround_OFF();          
          Default => Surr_OFF
          Value   => Surr_SIMULATED,Surr_MUSIC,Surr_MOVIE, or Surr_OFF 
    
    20. int8_t EffectControl(int8_t val);
          Default => -6
          Value   => -6 ~ -21 (1 Step)
    
    21. int8_t PhaseResistor(int8_t val);     // 0 - 255 
    22. int8_t PhaseResistor(int8_t val,      // 0 - 3 
                             int8_t val1,     // 0 - 3 
                             int8_t val2,     // 0 - 3 
                             int8_t val3);    // 0 - 3 
          Default => 255
   
    23. int8_t VoiceCanceller(int8_t val); 
          Default => VOICECANCELLER_OFF
          Value   => VOICECANCELLER_OFF or VOICECANCELLER_ON 
    
    24. int8_t DisableVoiceCanceller();
    25. int8_t EnableVoiceCanceller();
   
    26. int8_t SelectorRecOut(int8_t val);
    27. int8_t SelectorRecOut(int8_t val,int8_t val2);
                              Value     ,Channel
    28. int8_t RecOut_3BAND();
    29. int8_t RecOut_SURR(); 
    30. int8_t RecOut_REAR(); 
    31. int8_t RecOut_OFF();  
    32. int8_t RecOut_FLAT(); 
          Default => Out_3BAND
          Value   => Out_3BAND,Out_SURR,Out_REAR,Out_OFF, or Out_FLAT 
          Channel => ATT_LR or ATT_RR     
       
    33. int8_t Mute(int8_t val);              
    34. int8_t Mute(int8_t val,int8_t val2);  
                    Value     ,Channel
    35. int8_t DisableMute();                 
    36. int8_t EnableMute();   
          Default => MUTE_OFF
          Value   => MUTE_OFF or MUTE_ON
          Channel => ATT_LR,ATT_RR,ATT_LF, or ATT_RF
   
    // Only TDA7431
    37. int8_t RearSwitch(int8_t val);
          Default => REAR_ACTIVE
          Value   => REAR_ACTIVE or REAR_OFF 
   
    38. int8_t EnableRear();            
    39. int8_t DisableRear();           
   
     

<h3>TDA7432 & TDA7433 & TDA7434</h3>
<h4> Command : </h4>

    1.  int8_t begin();

    2.  int8_t Volume(int8_t val); 
          Default => 0 (0dB)
          UserValue == Use_POSITIVE => Volume 0 ~ 63  => 0dB ~ -31.5dB 
          UserValue == Use_NEGATIVE => Volume -63 ~ 0 => -31.5dB ~ 0dB 
    
    3.  int8_t Bass(int8_t val);
          Default => 7 (14dB)
          Value   => -7 ~ 7 => -14dB ~ 14dB (2dB Step)
          
    4.  int8_t Treble(int8_t val);
          Default => 7 (14dB)
          Value   => -7 ~ 7 => -14dB ~ 14dB (2dB Step)    

    5.  int8_t UseValue(int8_t val);
          Default => Use_POSITIVE 
          Value   => Use_POSITIVE or Use_NEGATIVE 
    
    6.  int8_t Balance(int8_t val);               
    7.  int8_t Balance(int8_t val,int8_t val2);   
                       Value     ,Channel
          Default => 0 (0dB)
          UserValue == Use_POSITIVE => Balance 0 ~ 79  => 0dB ~ -79dB (1dB Step)
          UserValue == Use_NEGATIVE => Balance -79 ~ 0 => -79dB ~ 0dB (1dB Step)
          Channel => ATT_LR,ATT_RR,ATT_LF, or ATT_RF

    8.  int8_t Input(int8_t val);
          Default => 1
          TDA7432 maks Input => 2 ( 1 Stereo + 1 Mono )
          TDA7433 maks Input => 3 ( 2 Stereo + 1 Mono )
          TDA7434 maks Input => 3 ( 2 Stereo + 1 Mono )
          
    9.  int8_t Mute(int8_t val);              
    10. int8_t Mute(int8_t val,int8_t val2);  
                    Value     ,Channel    
    11. int8_t DisableMute();                 
    12. int8_t EnableMute();
          Default => MUTE_OFF
          Value   => MUTE_OFF or MUTE_ON 
          Channel => ATT_LR,ATT_RR,ATT_LF, or ATT_RF 

    13. int8_t ExtendedBassRange(int8_t val);
          Default => Yes_ExtendedBassRange
          Value   => Yes_ExtendedBassRange or Not_ExtendedBassRange
          
    14. int8_t SymmetricalBassCut(int8_t val);
          Default => Not_SymmetricalBassCut
          Value   => Not_SymmetricalBassCut or Yes_SymmetricalBassCut
 
       // Only TDA7432 & TDA7434 
    15. int8_t Loudness(int8_t val);          
          Default => 0 (0dB)
          UserValue == Use_POSITIVE => Loudness 0 ~ 15  => 0dB ~ -15dB (1dB)
          UserValue == Use_NEGATIVE => Loudness -15 ~ 0 => -15dB ~ 0dB (1dB)
     
    16. int8_t ModeLoudness(int8_t val);      
          Default => Loudness_ON
          Value   => Loudness_ON or Loudness_OFF
    
    17. int8_t EnableModeLoudness(); 
    18. int8_t DisableModeLoudness();

<h3>TDA7438 & TDA7439 </h3>
<h4> Command : </h4>

    1.  int8_t begin();

    2.  int8_t UseValue(int8_t val); 
          Default => Use_POSITIVE 
          Value   => Use_POSITIVE or Use_NEGATIVE 

    3.  int8_t Input(int8_t val); 
          Default  => 1
          TDA7438 maks Input => 3       (3 Stereo)
          TDA7439 maks Input => 4 (FIX) (4 Stereo)
          
    4.  int8_t Gain(int8_t val);
          Default => 15 (30dB)
          Value   => 0 ~ 15 => 0dB ~ 30dB (2dB Step);
    
    5.  int8_t Volume(int8_t val);
          Default => 0 (0dB)
          UserValue == Use_POSITIVE => Volume 0 ~ 47  => 0dB ~ -47dB (1dB Step)
          UserValue == Use_NEGATIVE => Volume -47 ~ 0 => -47dB ~ 0dB (1dB Step)
    
    6.  int8_t Bass(int8_t val);
          Default => 7 (14dB)
          Value   => -7 ~ 7 => -14dB ~ 14dB (2dB Step)
    
    7.  int8_t Middle(int8_t val);
          Default => 7 (14dB)
          Value   => -7 ~ 7 => -14dB ~ 14dB (2dB Step)
    
    8.  int8_t Treble(int8_t val);
          Default => 7 (14dB)
          Value   => -7 ~ 7 => -14dB ~ 14dB (2dB Step)
  
    9.  int8_t Balance(int8_t val);
    10. int8_t Balance(int8_t val,int8_t val2);   
                       Value     ,Channel 
          Default => 0dB  
          UserValue == Use_POSITIVE => Balance 0 ~ 79  => 0dB ~ -79dB (1dB Step)
          UserValue == Use_NEGATIVE => Balance -79 ~ 0 => -79dB ~ 0dB (1dB Step)
          Channel => ATT_LR or ATT_RR

    
    11. int8_t Mute(int8_t val);              
    12. int8_t Mute(int8_t val,int8_t val2);  
                    Value     ,Channel    
    13. int8_t DisableMute();                 
    14. int8_t EnableMute();
          Default => MUTE_OFF
          Value   => MUTE_OFF or MUTE_ON 
          Channel => ATT_LR or ATT_RR 

<h4>Notice</h4>
<pre><h5> 
    if  defined(__AVR_AT90Mega169__)  or defined(__AVR_ATmega169__)   or
        defined(__AVR_AT90Mega165__)  or defined(__AVR_ATmega165__)   or
        defined(__AVR_ATmega325__)    or defined(__AVR_ATmega3250__)  or
        defined(__AVR_ATmega645__)    or defined(__AVR_ATmega6450__)  or
        defined(__AVR_ATmega329__)    or defined(__AVR_ATmega3290__)  or
        defined(__AVR_ATmega649__)    or defined(__AVR_ATmega6490__)  or
        defined(__AVR_ATtiny25__)     or defined(__AVR_ATtiny45__)    or defined(__AVR_ATtiny85__) or
        defined(__AVR_AT90Tiny26__)   or defined(__AVR_ATtiny26__)    or
        defined(__AVR_ATtiny84__)     or defined(__AVR_ATtiny44__)    or
        defined(__AVR_AT90Tiny2313__) or defined(__AVR_ATtiny2313__)
            Automatic disable "InstalWire" and "Wire" will be replaced with "TinyWireM" 
            Download<a href="https://github.com/adafruit/TinyWireM" target="_blank"> TinyWireM library </a>
        
        
        
</h5></pre>

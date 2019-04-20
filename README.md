# TDA743X 
<h3>Library</h3>
<ul>
  <li><a href="https://www.mouser.com/datasheet/2/389/CD00000226-470817.pdf"         >TDA7430</a></li>
  <li><a href="https://www.mouser.com/datasheet/2/389/CD00000226-470817.pdf"         >TDA7431</a></li>
  <li><a href="https://www.st.com/resource/en/datasheet/CD00000874.pdf"              >TDA7432</a></li>
  <li><a href="https://www.st.com/resource/en/datasheet/cd00000878.pdf"              >TDA7433</a></li>
  <li><a href="http://pdf.datasheetcatalog.com/datasheet/stmicroelectronics/4062.pdf">TDA7434</a></li>
  <li><a href="http://pdf.datasheetcatalog.com/datasheets/105/324990_DS.pdf"         >TDA7435</a></li>
  <li><a href="http://pdf.datasheetcatalog.com/datasheet/SGSThomsonMicroelectronics/mXruwsz.pdf">TDA7437</a></li>
  <li><a href="https://www.st.com/resource/en/datasheet/CD00001003.pdf"              >TDA7438</a></li>
  <li><a href="https://www.st.com/resource/en/datasheet/cd00004906.pdf"              >TDA7439</a></li>
<ul>


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
      Serial.begin(9600); 
      
      if(uPA.InstalWire(&Wire) != Process_OK) Serial.println("Process_ERROR");
      else Serial.println("Process_OK");
      
      if(uPA.begin() =! Process_OK) Serial.print("Process_ERROR");
      else Serial.println("Process_OK");
      
    } // void setup
    
    void loop(){
    // Do something?
    } 

    

<h3>TDA7430 & TDA7431 </h3>

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
          TDA7430 maks Input => 4 
          TDA7431 maks Input => 1 (FIX)
    
    6.  int8_t Volume(int8_t val);
          Default => 0 (0dB)
          UserValue == Use_POSITIVE => Volume 0 ~ 63  => 0dB ~ -31.5dB (0.5dB Step)
          UserValue == Use_NEGATIVE => Volume -63 ~ 0 => -31.5dB ~ 0dB (0.5dB Step)
    
    7.  int8_t Bass(int8_t val);
          Default => 7 (14dB)
          Value   => -7 ~ 7 => -14dB ~ 14dB (2dB Step)
    
    8.  int8_t Middle(int8_t val);
          Default => 7 (14dB)
          Value => -7 ~ 7 => -14dB ~ 14dB (2dB Step)
    
    9.  int8_t Treble(int8_t val);
          Default => 7 (14dB)
          Value => -7 ~ 7 => -14dB ~ 14dB (2dB Step)
  
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
 
    15. int8_t RearSwitch(int8_t val);
          Default => REAR_ACTIVE
          Value   => REAR_ACTIVE or REAR_OFF 
   
    16. int8_t EnableRear();            
    17. int8_t DisableRear();           
   
    18. int8_t SurroundMode(int8_t val);  
    19. int8_t Surround_SIMULATED();    
    20. int8_t Surround_MUSIC();         
    21. int8_t Surround_MOVIE();        
    22. int8_t Surround_OFF();          
          Default => Surr_OFF
          Value   => Surr_SIMULATED,Surr_MUSIC,Surr_MOVIE, or Surround_OFF 
    
    23. int8_t EffectControl(int8_t val);
          Default => -6
          Value   => -6 ~ -21 (1 Step)
    
    24. int8_t PhaseResistor(int8_t val);     // 0 - 255 
    25. int8_t PhaseResistor(int8_t val,      // 0 - 3 
                             int8_t val1,     // 0 - 3 
                             int8_t val2,     // 0 - 3 
                             int8_t val3);    // 0 - 3 
          Default => 255
   
    26. int8_t VoiceCanceller(int8_t val); 
          Default => VOICECANCELLER_OFF
          Value   => VOICECANCELLER_OFF or VOICECANCELLER_ON 
    
    27. int8_t DisableVoiceCanceller();
    28. int8_t EnableVoiceCanceller();
   
    29. int8_t SelectorRecOut(int8_t val);
    30. int8_t SelectorRecOut(int8_t val,int8_t val2);
                          Value     ,Channel
    31. int8_t RecOut_3BAND();
    32. int8_t RecOut_SURR(); 
    33. int8_t RecOut_REAR(); 
    34. int8_t RecOut_OFF();  
    35. int8_t RecOut_FLAT(); 
          Default => Out_3BAND
          Value   => Out_3BAND,Out_SURR,Out_REAR,Out_OFF, or Out_FLAT 
          Channel => ATT_LR or ATT_RR     
       
    36. int8_t Mute(int8_t val);              
    37. int8_t Mute(int8_t val,int8_t val2);  
                    Value     ,Channel
    39. int8_t DisableMute();                 
    40. int8_t EnableMute();                  
          Value   => MUTE_OFF or MUTE_ON
          Channel => ATT_LR,ATT_RR,ATT_LF, or ATT_RF
     

<h3>TDA7432</h3>

    1.  int8_t Volume(int8_t val); 
          Default => 0 (0dB)
          UserValue == Use_POSITIVE => Volume 0 ~ 63  => 0dB ~ -31.5dB 
          UserValue == Use_NEGATIVE => Volume -63 ~ 0 => -31.5dB ~ 0dB 
    
    2.  int8_t Bass(int8_t val);
          Default => 7 (14dB)
          Value => -7 ~ 7 => -14dB ~ 14dB (2dB Step)
          
    3.  int8_t Treble(int8_t val);
          Default => 7 (14dB)
          Value => -7 ~ 7 => -14dB ~ 14dB (2dB Step)    

    4.  int8_t UseValue(int8_t val);
          Default => Use_POSITIVE 
          Value   => Use_POSITIVE or Use_NEGATIVE 
    
    5.  int8_t Balance(int8_t val);               
    6.  int8_t Balance(int8_t val,int8_t val2);   
                       Value     ,Channel
          Default => 0 (0dB)
          UserValue == Use_POSITIVE => Balance 0 ~ 79  => 0dB ~ -79dB (1dB Step)
          UserValue == Use_NEGATIVE => Balance -79 ~ 0 => -79dB ~ 0dB (1dB Step)
          Channel => ATT_LR,ATT_RR,ATT_LF, or ATT_RF

    7.  int8_t Input(int8_t val);
          Default => 1
          TDA7432 maks Input => 2 
          TDa7433 maks Input => 3
          
    8.  int8_t Mute(int8_t val);              
    9.  int8_t Mute(int8_t val,int8_t val2);  
                    Value     ,Channel    
    10. int8_t DisableMute();                 
    11. int8_t EnableMute();
          Default => MUTE_OFF
          Value   => MUTE_OFF or MUTE_ON 
          Channel => ATT_LR,ATT_RR,ATT_LF, or ATT_RF 

    12. int8_t Loudness(int8_t val);          
          Default => 0 (0dB)
          UserValue == Use_POSITIVE => Loudness 0 ~ 15  => 0dB ~ -15dB (1dB)
          UserValue == Use_NEGATIVE => Loudness -15 ~ 0 => -15dB ~ 0dB (1dB)
     
    13. int8_t ModeLoudness(int8_t val);      
          Default => Loudness_ON
          Value   => Loudness_ON or Loudness_OFF
    
    14. int8_t EnableModeLoudness(); 
    15. int8_t DisableModeLoudness();


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
            Download<a href="https://github.com/adafruit/TinyWireM">TinyWireM library</a>
        
</h5></pre>

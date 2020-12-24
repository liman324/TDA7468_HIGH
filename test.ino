#include <Wire.h>
#include <TDA7468.h>
  TDA7468 tda;
  
void setup(){ 
  Serial.begin(9600);Wire.begin();
}

void loop(){
  audio();
  delay(1000);
}
// https://rcl-radio.ru/wp-content/uploads/2019/05/tda7468.pdf
void audio(){
  tda.setInput(0,0,0); 
   // setInput(input,mute_mic,mic)
       // input 0...4 === IN1...IN4 //выбор входа
       // mute_mic 0...1 === OFF...ON //при включении входы переходят в режим MUTE, в звуковом тракте остаётся микрофон, если его вход активирован
       // mic 0...3 === gain 14dB...0dB // mic 4 === OFF //активация микрофонного входа и установка предусиления для него
///////////////////////////////////////////////////////////////       
  tda.setGain(0);
  //  setGain(gain);
       // gain 0...7 === 0...14 dB // step 2dB //установка предусиления
//////////////////////////////////////////////////////////////       
  tda.setSurround(0,0,0,0);
  //  setSurround(sur,gain,mix,buf); 
       // sur 1 === on // 0 === off (SURROUND MODE)
       // gain 0...3 === 0...12 dB  (GAIN)
       // mix 0...7                 (MIXING)
       // buf 1 === on // 0 === off (BUFFER GAIN)    
  tda.setVol_R(62); // VOLUME R 0...62 //регулирование громкости правого канала
  tda.setVol_L(62); // VOLUME L 0...62 //регулирование громкости левого канала
  tda.setTreb_Bass(0,0); // -14...14 step 2 dB (TREBLE,BASS)
  tda.setOutput(1); // MUTE 0 === ON // 1 === OFF //активация режима MUTE для выхода всего звукового тракта
  tda.setAlc(0,0,0,0,0,0);
  //  setAlc(mode,detector,circ,attack,tresh,rez);
       // mode 1 on 0 off 
       // detector 1 on 0 off 
       // circ 1 on 0 off 
       // attack 12k5 25k 50k 100k 0...3
       // tresh 700mVrms 485mVrms 320mVrms 170mVrms 0...3
       // rez MODE 1: Fixed Resistor / MODE 2: Adaptive 0...1
}

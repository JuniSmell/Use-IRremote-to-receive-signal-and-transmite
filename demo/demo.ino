// 這個程式是從範例"SendRawDemo"改過來的。
#include <Arduino.h>
#include "PinDefinitionsAndMore.h" //用來設定輸入與輸出腳位等等
#include <IRremote.hpp>

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(115200);
}


const uint16_t reverse[] = {6080,470, 630,1470, 1630,470, 630,1470, 1630,470, 1630,470, 680,1420, 680,1420, 1630};//倒立 
const uint16_t sit[] = {6030,520, 1630,470, 630,1470, 1630,470, 1630,470, 630,1470, 630,1470, 630,1470, 630};//坐下
const uint16_t getDown[] = {6080,420, 1680,470, 1630,470, 680,1420, 1630,470, 680,1420, 1630,470, 680,1420, 680};//趴下
const uint16_t hello[]={6080,420, 1680,470, 630,1470, 1630,420, 1680,420, 680,1470, 680,1420, 1630,470, 680};//問好
const uint16_t pushUp[]={6030,470, 680,1520, 1530,470, 680,1420, 1680,470, 630,1420, 680,1470, 1630,470, 630};//俯臥撐
const uint16_t story[]={6080,420, 1730,420, 630,1420, 1680,470, 1630,420, 1680,470, 680,1420, 1630,470, 1630};//講故事
const uint16_t cute[]={6080,420, 1680,420, 1680,420, 680,1420, 1680,420, 680,1470, 680,1420, 680,1420, 680};//撒嬌
const uint16_t sing[]={6030,470, 1680,420, 680,1420, 1680,420, 1680,420, 1680,470, 630,1470, 630,1470, 1630};//唱歌
const uint16_t sleep[]={6080,470, 1680,420, 1630,470, 680,1420, 1680,420, 1680,420, 680,1420, 1680,420, 1680};//睡覺
const uint16_t freeze[]={6080,420, 1680,470, 1630,420, 680,1470, 1630,420, 680,1470, 680,1420, 1630,470, 680};//停止
const uint16_t frontLegIn[]={6080,470, 1630,470, 1630,470, 680,1420, 1630,470, 680,1470, 1580,470, 1680,420, 1680};//前腿進
const uint16_t forward1[]={6080,470, 680,1420, 1630,470, 1630,470, 1630,470, 680,1420, 680,1420, 680,1420, 680};//前進1
const uint16_t forward2[]={6080,470, 680,1420, 1680,420, 1680,420, 1630,470, 680,1420, 680,1420, 680,1420, 680};//前進2
const uint16_t forward3[]={6080,420, 680,1420, 1680,420, 1680,420, 1680,420, 680,1470, 630,1470, 630,1470, 630};//前進3
const uint16_t forward4[]={6030,470, 680,1420, 1680,470, 1630,420, 1680,420, 680,1470, 630,1470, 630,1470, 630};//前進4
const uint16_t forward5[]={6030,470, 680,1420, 1680,420, 1630,470, 1630,470, 680,1420, 680,1420, 680,1420, 680};//前進5
const uint16_t forward6[]={6030,470, 680,1420, 1680,420, 1680,420, 1680,420, 680,1470, 630,1470, 630,1470, 630};//前進6
const uint16_t forward7[]={6030,470, 680,1420, 1680,420, 1680,470, 1630,420, 680,1420, 680,1420, 680,1420, 680};//前進7
const uint16_t forward8[]={6080,420, 680,1420, 1680,420, 1680,420, 1680,420, 680,1470, 630,1470, 630,1470, 630};//前進8
const uint16_t forward9[]={6080,470, 680,1420, 1630,470, 1630,470, 1630,470, 680,1420, 680,1420, 680,1420, 680};//前進9
const uint16_t forward10[]={6080,470, 630,1470, 1630,470, 1630,470, 1630,470, 680,1420, 680,1420, 680,1420, 680};//前進10
const uint16_t frontLegBack[]={6080,470, 1680,420, 1680,420, 680,1420, 1680,420, 1680,470, 630,1470, 630,1470, 1630};//前腿退
const uint16_t backLegIn1[]={6030,470, 680,1420, 1680,420, 680,1420, 1680,420, 680,1420, 1680,420, 680,1470, 630};//後腿進1
const uint16_t backLegIn2[]={6080,470, 680,1420, 1630,470, 680,1420, 1630,470, 680,1420, 1680,420, 680,1420, 680};//後腿進2
const uint16_t backLegIn3[]={6080,470, 630,1470, 1630,470, 680,1420, 1630,470, 680,1420, 1630,470, 680,1420, 680};//後腿進3
const uint16_t backLegIn4[]={6080,470, 680,1420, 1680,420, 680,1420, 1680,420, 680,1420, 1680,420, 680,1420, 680};//後腿進4
const uint16_t backLegIn5[]={6080,420, 680,1470, 1630,420, 680,1470, 1630,470, 630,1470, 1630,470, 630,1470, 680};//後腿進5
const uint16_t backLegIn6[]={6080,420, 680,1470, 1630,470, 680,1420, 1630,470, 680,1420, 1630,470, 680,1420, 680};//後腿進6
const uint16_t backLegIn7[]={6080,420, 1680,470, 680,1420, 1630,470, 680,1420, 1630,470, 680,1420, 1630,470, 680};//後腿進7
const uint16_t backLegIn8[]={6080,420, 1680,470, 630,1470, 1630,470, 680,1420, 1630,470, 680,1420, 1630,470, 680};//後腿進8
const uint16_t backLegIn9[]={6080,470, 1630,470, 680,1420, 1630,470, 680,1420, 1680,420, 680,1420, 1680,420, 680};//後腿進9
const uint16_t backLegIn10[]={6080,420, 1730,420, 630,1470, 1630,470, 630,1470, 1630,470, 680,1420, 1630,470, 680};//後腿進10
const uint16_t coding[]={6080,470, 1630,470, 680,1420, 1680,420, 1680,420, 680,1420, 1680,420, 680,1420, 680};//編程
const uint16_t backLegBack1[]={6080,420, 680,1470, 1630,470, 1630,470, 1630,470, 1630,470, 680,1420, 680,1420, 1630};//後腿退1
const uint16_t backLegBack2[]={6080,420, 680,1420, 1680,420, 1680,420, 1680,420, 1680,420, 680,1470, 630,1470, 1630};//後腿退2
const uint16_t backLegBack3[]={6030,470, 680,1420, 1680,420, 1680,420, 1680,420, 1680,420, 680,1420, 680,1420, 1680};//後腿退3
const uint16_t backLegBack4[]={6080,420, 680,1470, 1630,470, 1630,470, 1630,470, 1630,470, 680,1470, 630,1420, 1630};//後腿退4
const uint16_t backLegBack5[]={6080,470, 680,1420, 1680,420, 1680,420, 1680,420, 1680,420, 680,1420, 680,1420, 1680};//後腿退5
const uint16_t backLegBack6[]={6080,470, 630,1470, 1630,470, 1630,470, 1630,470, 1630,470, 680,1420, 680,1420, 1630};//後腿退6
const uint16_t backLegBack7[]={6080,420, 680,1470, 1630,470, 1630,470, 1630,470, 1630,470, 680,1420, 680,1420, 1630};//後腿退7
const uint16_t backLegBack8[]={6080,470, 680,1420, 1630,470, 1630,470, 1630,470, 1630,470, 680,1420, 680,1420, 1630};//後腿退8
const uint16_t backLegBack9[]={6080,470, 680,1420, 1630,470, 1630,470, 1630,470, 1630,470, 680,1420, 680,1420, 1680};//後腿退9
const uint16_t backLegBack10[]={6080,470, 1680,420, 680,1420, 1680,420, 680,1420, 1680,420, 680,1420, 1680,420, 680};//後腿退10
const uint16_t soundOn[]={6080,420, 680,1470, 1630,470, 1630,420, 1680,470, 630,1470, 1630,470, 1630,470, 1630};//音量+
const uint16_t stand1[]={5980,520, 630,1420, 1680,470, 1630,520, 1530,520, 1630,470, 630,1470, 1630,470, 1630};//立正1
const uint16_t stand2[]={6030,420, 680,1470, 1630,420, 1680,520, 1580,470, 1630,470, 630,1520, 1580,470, 1630};//立正2
const uint16_t stand3[]={6080,520, 580,1470, 1630,470, 1630,520, 1580,520, 1580,470, 680,1420, 1630,520, 1580};//立正3
const uint16_t stand4[]={6030,520, 630,1420, 1630,570, 1530,520, 1580,470, 1630,520, 630,1420, 1630,520, 1580};//立正4
const uint16_t stand5[]={5980,470, 680,1470, 1580,470, 1630,520, 1580,520, 1580,520, 630,1420, 1680,420, 1630};//立正5
const uint16_t stand6[]={6080,470, 630,1470, 1630,470, 1630,470, 1630,470, 1630,520, 580,1470, 1630,520, 1580};//立正6
const uint16_t stand7[]={6030,520, 1580,520, 630,1470, 1580,520, 630,1470, 1580,520, 630,1470, 1580,470, 680};//立正7
const uint16_t stand8[]={6080,470, 1630,470, 680,1470, 1580,520, 630,1420, 1630,520, 630,1420, 1680,520, 580};//立正8
const uint16_t stand9[]={5980,520, 1630,470, 630,1470, 1580,470, 680,1470, 1630,470, 630,1520, 1580,470, 630};//立正9
const uint16_t stand10[]={6030,470, 1680,420, 680,1420, 1680,420, 680,1420, 1680,470, 630,1470, 1630,470, 630};//立正10
const uint16_t soundDown[]={6030,520, 1630,420, 680,1420, 1680,420, 1680,420, 680,1470, 1630,470, 1630,470, 1630};//音量-

void loop() {
  Serial.println("0:倒立\n1:坐下\n2:趴下\n3:問好\n4:俯臥撐\n5:講故事\n6:撒嬌\n7:唱歌\n8:睡覺\n9:停止\na:前腿進\nb:前進\nc:前腿退\nd:後腿進\ne:編程\nf:後腿退\ng:音量+\nh:立正\ni:音量-");
  Serial.print("Please type the action:");
  while( !Serial.available() );
  char c = Serial.read();
  Serial.println( c );
  switch( c ) {
    case '0':
            IrSender.sendRaw(reverse, sizeof(reverse) / sizeof(reverse[0]), 9);
            delay(193);//因為發現遙控器本身發射不同組訊號的最短間隔約為194~190ms，其中測量時193ms最常出現，所以就直接複製原廠193的設定。
            break;
    case'1':
            IrSender.sendRaw(sit, sizeof(sit) / sizeof(sit[0]), 9);
            delay(193);
            break;
    case'2':
            IrSender.sendRaw(getDown, sizeof(getDown) / sizeof(getDown[0]), 9);
            delay(193);
            break;
    case'3':
            IrSender.sendRaw(hello, sizeof(hello) / sizeof(hello[0]), 9);
            delay(193);
            break;
    case'4':
            IrSender.sendRaw(pushUp, sizeof(pushUp) / sizeof(pushUp[0]), 9);
            delay(193);
            break;
    case'5':
            IrSender.sendRaw(story, sizeof(story) / sizeof(story[0]), 9);
            delay(193);
            break;
    case'6':
            IrSender.sendRaw(cute, sizeof(cute) / sizeof(cute[0]), 9);
            delay(193);
            break;
    case'7':
            IrSender.sendRaw(sing, sizeof(sing) / sizeof(sing[0]), 9);
            delay(193);
            break;
    case'8':
            IrSender.sendRaw(sleep, sizeof(sleep) / sizeof(sleep[0]), 9);
            delay(193);
            break;
    case'9':
            IrSender.sendRaw(freeze, sizeof(freeze) / sizeof(freeze[0]), 9);
            delay(193);
            break;
    case'a':
            IrSender.sendRaw(frontLegIn, sizeof(frontLegIn) / sizeof(frontLegIn[0]), 9);
            delay(193);
            break;
    case'b':
            IrSender.sendRaw(forward1, sizeof(forward1) / sizeof(forward1[0]), 9);
            delay(193);
            IrSender.sendRaw(forward2, sizeof(forward2) / sizeof(forward2[0]), 9);
            delay(193);
            IrSender.sendRaw(forward3, sizeof(forward3) / sizeof(forward3[0]), 9);
            delay(193);
            IrSender.sendRaw(forward4, sizeof(forward4) / sizeof(forward4[0]), 9);
            delay(193);
            IrSender.sendRaw(forward5, sizeof(forward5) / sizeof(forward5[0]), 9);
            delay(193);
            IrSender.sendRaw(forward6, sizeof(forward6) / sizeof(forward6[0]), 9);
            delay(193);
            IrSender.sendRaw(forward7, sizeof(forward7) / sizeof(forward7[0]), 9);
            delay(193);
            IrSender.sendRaw(forward8, sizeof(forward8) / sizeof(forward8[0]), 9);
            delay(193);
            IrSender.sendRaw(forward9, sizeof(forward9) / sizeof(forward9[0]), 9);
            delay(193);
            IrSender.sendRaw(forward10, sizeof(forward10) / sizeof(forward10[0]), 9);
            delay(193);
            break;
    case'c':
            IrSender.sendRaw(frontLegBack, sizeof(frontLegBack) / sizeof(frontLegBack[0]), 9);
            delay(193);
            break;
    case'd':
            IrSender.sendRaw(backLegIn1, sizeof(backLegIn1) / sizeof(backLegIn1[0]), 9);
            delay(193);
            IrSender.sendRaw(backLegIn2, sizeof(backLegIn2) / sizeof(backLegIn2[0]), 9);
            delay(193);
            IrSender.sendRaw(backLegIn3, sizeof(backLegIn3) / sizeof(backLegIn3[0]), 9);
            delay(193);
            IrSender.sendRaw(backLegIn4, sizeof(backLegIn4) / sizeof(backLegIn4[0]), 9);
            delay(193);
            IrSender.sendRaw(backLegIn5, sizeof(backLegIn5) / sizeof(backLegIn5[0]), 9);
            delay(193);
            IrSender.sendRaw(backLegIn6, sizeof(backLegIn6) / sizeof(backLegIn6[0]), 9);
            delay(193);
            IrSender.sendRaw(backLegIn7, sizeof(backLegIn7) / sizeof(backLegIn7[0]), 9);
            delay(193);
            IrSender.sendRaw(backLegIn8, sizeof(backLegIn8) / sizeof(backLegIn8[0]), 9);
            delay(193);
            IrSender.sendRaw(backLegIn9, sizeof(backLegIn9) / sizeof(backLegIn9[0]), 9);
            delay(193);
            IrSender.sendRaw(backLegIn10, sizeof(backLegIn10) / sizeof(backLegIn10[0]), 9);
            delay(193);
            break;
    case'e':
            IrSender.sendRaw(coding, sizeof(coding) / sizeof(coding[0]), 9);
            delay(193);
            break;
    case'f':
            IrSender.sendRaw(backLegBack1, sizeof(backLegBack1) / sizeof(backLegBack1[0]), 9);
            delay(193);
            IrSender.sendRaw(backLegBack2, sizeof(backLegBack2) / sizeof(backLegBack2[0]), 9);
            delay(193);
            IrSender.sendRaw(backLegBack3, sizeof(backLegBack3) / sizeof(backLegBack3[0]), 9);
            delay(193);
            IrSender.sendRaw(backLegBack4, sizeof(backLegBack4) / sizeof(backLegBack4[0]), 9);
            delay(193);
            IrSender.sendRaw(backLegBack5, sizeof(backLegBack5) / sizeof(backLegBack5[0]), 9);
            delay(193);
            IrSender.sendRaw(backLegBack6, sizeof(backLegBack6) / sizeof(backLegBack6[0]), 9);
            delay(193);
            IrSender.sendRaw(backLegBack7, sizeof(backLegBack7) / sizeof(backLegBack7[0]), 9);
            delay(193);
            IrSender.sendRaw(backLegBack8, sizeof(backLegBack8) / sizeof(backLegBack8[0]), 9);
            delay(193);
            IrSender.sendRaw(backLegBack9, sizeof(backLegBack9) / sizeof(backLegBack9[0]), 9);
            delay(193);
            IrSender.sendRaw(backLegBack10, sizeof(backLegBack10) / sizeof(backLegBack10[0]), 9);
            delay(193);
            break;
    case'g':
            IrSender.sendRaw(soundOn, sizeof(soundOn) / sizeof(soundOn[0]), 9);
            delay(193);
            break;
    case'h':
            IrSender.sendRaw(stand1, sizeof(stand1) / sizeof(stand1[0]), 9);
            delay(193);
            IrSender.sendRaw(stand2, sizeof(stand2) / sizeof(stand2[0]), 9);
            delay(193);
            IrSender.sendRaw(stand3, sizeof(stand3) / sizeof(stand3[0]), 9);
            delay(193);
            IrSender.sendRaw(stand4, sizeof(stand4) / sizeof(stand4[0]), 9);
            delay(193);
            IrSender.sendRaw(stand5, sizeof(stand5) / sizeof(stand5[0]), 9);
            delay(193);
            IrSender.sendRaw(stand6, sizeof(stand6) / sizeof(stand6[0]), 9);
            delay(193);
            IrSender.sendRaw(stand7, sizeof(stand7) / sizeof(stand7[0]), 9);
            delay(193);
            IrSender.sendRaw(stand8, sizeof(stand8) / sizeof(stand8[0]), 9);
            delay(193);
            IrSender.sendRaw(stand9, sizeof(stand9) / sizeof(stand9[0]), 9);
            delay(193);
            IrSender.sendRaw(stand10, sizeof(stand10) / sizeof(stand10[0]), 9);
            delay(193);
            break;
    case'i':
            IrSender.sendRaw(soundDown, sizeof(soundDown) / sizeof(soundDown[0]), 9);
            delay(193);
            break;
    default:
    break;
  }
}

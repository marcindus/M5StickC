/*
*******************************************************************************
* Copyright (c) 2021 by M5Stack
*                  Equipped with M5StickC sample source code
*                          配套  M5StickC 示例源代码
* Visit for more information: https://docs.m5stack.com/en/core/m5stickc
* 获取更多资料请访问: https://docs.m5stack.com/zh_CN/core/m5stickc
*
* describe: HEX.  灯板
* date: 2021/8/17
*******************************************************************************
  Please connect to Port , Control HEX Unit to run rainbow light show.
  请连接端口,控制HEX Unit 彩虹灯显示。
*/

#include <M5StickC.h>

#include "FastLED.h"

#define Neopixel_PIN 32
#define NUM_LEDS     37

CRGB leds[NUM_LEDS];
uint8_t gHue = 0;  // Initial tone value.  起始色调数值

void setup() {
    M5.begin();  // Init M5StickC.  初始化M5StickC
    M5.Lcd.setTextColor(YELLOW);
    M5.Lcd.println("HEX Example");
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.setCursor(0, 40);
    M5.Lcd.println("Display rainbow effect");

    // Neopixel initialization.  初始化灯带
    FastLED.addLeds<WS2811, Neopixel_PIN, GRB>(leds, NUM_LEDS)
        .setCorrection(TypicalLEDStrip);
    FastLED.setBrightness(5);  // set the LED brightness to 5. 设置灯带的亮度为5
}

void loop() {
    fill_rainbow(
        leds, NUM_LEDS, gHue,
        7);  // Set the leds from 0 to 37 beads to gradient rainbow color, the
             // starting tone value to gHue, and the color difference between
             // adjacent beads to 7.
             // 将leds灯带的从0~37个灯珠设置为渐变彩虹色,起始色调数值设置为gHue,相邻灯珠色差为7
    FastLED.show();  // Updated LED color.  更新LED色彩
    EVERY_N_MILLISECONDS(20) {
        gHue++;
    }  // The program is executed every 20 milliseconds.
       // 每20毫秒执行一次其中的程序
}

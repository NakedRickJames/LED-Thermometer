#include <FastLED.h>
#include <ezButton.h>
ezButton button1(3);
ezButton button2(6);
ezButton button3(2);

#define DATA_PIN 5
//#define CLK_PIN   4
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS 100
#define MAX_AMPS 500
#define volts 5


  CRGB leds[NUM_LEDS];

#define BRIGHTNESS 100
#define FRAMES_PER_SECOND 120


void setup() {
  delay(3000);                  // 3 second delay for recovery
  button1.setDebounceTime(50);  // set debounce time to 50 milliseconds
  button2.setDebounceTime(50);  // set debounce time to 50 milliseconds
  button3.setDebounceTime(50);  // set debounce time to 50 milliseconds

  // tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  //FastLED.addLeds<LED_TYPE,DATA_PIN,CLK_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);

  // set master brightness control
  FastLED.setBrightness(BRIGHTNESS);

  FastLED.setMaxPowerInVoltsAndMilliamps(volts, MAX_AMPS);

  //FastLED.clear();
  //FastLED.show();
  

}

uint8_t gHue = 0; // rotating "base color" used by many of the patterns

void loop() {
  button1.loop();  // MUST call the loop() function first
  button2.loop();  // MUST call the loop() function first
  button3.loop();  // MUST call the loop() function first
  int btn1State = button1.getState();
  int btn2State = button2.getState();
  int btn3State = button3.getState();
  FastLED.clear();

  if (button1.isPressed())
    
    FastLED.clear();
    fill_rainbow( leds, NUM_LEDS - 80, gHue, 7);
    EVERY_N_MILLISECONDS( 5 ) { gHue++; }
    slowly cycle the "base color" through the rainbow
    FastLED.show();} 
    FastLED.delay(1000 / FRAMES_PER_SECOND);
    

  if(button1.isReleased())
    FastLED.clear();

  if (button2.isPressed())

    FastLED.clear();
    fill_rainbow( leds, NUM_LEDS - 40, gHue, 7);
    EVERY_N_MILLISECONDS( 5 ) { gHue++; }
      // slowly cycle the "base color" through the rainbow

    FastLED.show(); 
    FastLED.delay(1000 / FRAMES_PER_SECOND);

  if(button2.isReleased())
    FastLED.clear();
    
  if (button3.isPressed())

    FastLED.clear();
    fill_rainbow( leds, NUM_LEDS, gHue, 7);
    EVERY_N_MILLISECONDS( 5 ) { gHue++; }
      // slowly cycle the "base color" through the rainbow

    FastLED.show(); 
    FastLED.delay(1000 / FRAMES_PER_SECOND);

  if(button3.isReleased())
    FastLED.clear();



  FastLED.clear();
  FastLED.show();
}




# arduino puck lighting

## wiring diagram
![Images](https://github.com/msatbsx/arduino-puck-lighting/blob/master/img/wiring.png?raw=true)

## setup:
setup color temperature by changing the values in `arduino-puck-lighting.ino`:
```
CRGB color_calibrated = CRGB(255, 255, 255);
```
where
- values can be changed 0-255
- 0 is off, 255 max brightnes
- order of colors is cool/warm/amber
- if order of colors does not match LED, can be changed in `#define COLOR_ORDER`

Recomended initial setting is CRGB(255, 255, 255)

## FAQs & troubleshooting
- why the strips are bilinking while power up? This is for testing purposes, if all led's and all colors are working. To remove it, please comment lines 39-47.
- LEDs are not lighing after successfully downloading the program. Check:
    - check if the pins in described in the file are matching those connected to the strips. 
    - check if ground from power supply is connected to Arduino.
    - check number of strip and other setting values. 
    - check value of color_calibrated variable. 
    - check if number of .addleds are matching no of strip constant `#define NUM_STRIPS`
- still not working? Contact owner of this repo. 
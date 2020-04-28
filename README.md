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


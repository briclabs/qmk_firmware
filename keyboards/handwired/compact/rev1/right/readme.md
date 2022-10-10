# Compact (Right)

A compact, split, ergonomic keyboard, with a unique key layout.
Powered by the QMK Proton-C (STM32F303), and two Adafruit 2946 LED drivers (IS31FL3731) to supply per-key RGB.
Hardware based on Ergodox and inspired by Iris.
Firmware based on Moonlander.

* Keyboard Maintainer: [BricLabs](https://github.com/briclabs/compact-keyboard)
* Hardware Supported: QMK Proton-C, Adafruit 2946 Breakout for IS31FL3731.
* Hardware Availability: DIY; handwired is possible, PCB is a lot easier.

Make example for this keyboard (after setting up your build environment):

    make handwired/compact/<revision>/<side>:default

Flashing example for this keyboard:

    make handwired/compact/<revision>/<side>:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

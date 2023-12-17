# Kimiko Rev2 - Residuum22

This is my customised QMK firmware for the Kimiko Split Keyboard (Rev2) with the following hardware:

- RP2040 controllers
- OLED screens (SSD1306)
- rotary encoders (under the OLED screens)
- per-key LEDs

## How to use

1. [Set up](https://docs.qmk.fm/#/newbs_getting_started) your QMK Environment
2. Clone this repository into your `<QMK home>/keyboards/keycapsss/kimiko/rev2/keymaps` directory
3. If you have different hardware, [change the source code](https://github.com/Keycapsss/Kimiko/blob/master/Keymap.md#customize-the-default-keymap) accordingly
4. Build the firmware using following the QMK CLI command: `qmk compile -c -kb keycapsss/kimiko/rev2 -km KimikoRev2KeymapByResiduum22 -e CONVERT_TO=promicro_rp2040 -j 16`
5. Put each side of the keyboard into bootloader mode and copy the firmware from `<QMK home>/.build` directory to the RP2040s.
   Namely: `keycapsss_kimiko_rev2_KimikoRev2KeymapByResiduum22_promicro_rp2040.uf2`

Don't forget to set the [handedness](https://docs.qmk.fm/#/feature_split_keyboard?id=handedness-by-eeprom) of each side in the EEPROM.

**Special thanks to [ABS96](https://github.com/ABS96) for the base layout and fuctions**
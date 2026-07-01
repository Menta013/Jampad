# Jampad QMK firmware

Starter QMK firmware for the 3x3 Jampad using a Seeed Studio XIAO RP2040.

## Hardware map

| Function | XIAO pin | RP2040 GPIO |
|---|---:|---:|
| Matrix row 0 | D0 | GP26 |
| Matrix row 1 | D1 | GP27 |
| Matrix row 2 | D2 | GP28 |
| Matrix column 0 | D3 | GP29 |
| OLED SDA | D4 | GP6 |
| OLED SCL | D5 | GP7 |
| Matrix column 1 | D6 | GP0 |
| Matrix column 2 | D7 | GP1 |
| Encoder A | D8 | GP2 |
| Encoder B | D9 | GP4 |
| SK6812 data | D10 | GP3 |

The matrix diodes are configured `COL2ROW`.

## Default controls

| Undo | Copy | Paste |
|---|---|---|
| Previous track | Play/Pause | Next track |
| Escape | Windows screenshot | Delete |

Turning the encoder controls system volume.

## Build

Copy this `jampad_qmk` folder into:

    qmk_firmware/keyboards/jampad

Then run from the QMK firmware directory:

    qmk compile -kb jampad -km default

The resulting `.uf2` file will be placed in the QMK firmware root.

## Flash

1. Disconnect the XIAO.
2. Hold its **BOOT** button.
3. Connect USB while continuing to hold BOOT.
4. Release BOOT when the `RPI-RP2` drive appears.
5. Copy the compiled `.uf2` file onto that drive.

## Hardware notes

- The encoder push-button pins S1 and S2 are unconnected in the supplied
  schematic and PCB. Rotation works; pressing the knob cannot be detected.
- The SK6812 is powered from 5 V while its data signal is 3.3 V. This often
  works for a short trace and one LED, but it is outside the most conservative
  logic-level margin. If the LED flickers or fails, use a 3.3-to-5 V level
  shifter or power the LED from 3.3 V if its specific part permits it.
- If the encoder direction is reversed, swap `pin_a` and `pin_b` in
  `keyboard.json`.
- If one encoder detent changes volume more than once, change its `resolution`
  from `4` to `2` in `keyboard.json`.

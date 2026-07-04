# Jampad Build Journal

## Project overview

Jampad is a compact 3×3 mechanical macropad powered by a through-hole Seeed Studio XIAO RP2040. It includes nine MX-compatible switches, a rotary encoder, a 0.91-inch OLED, one addressable RGB LED, QMK firmware, and a custom two-piece 3D-printed enclosure.

## June 28, 2026 — Initial design

I started by defining the main features and laying out the first schematic in KiCad. I chose the XIAO RP2040 because it is compact, supports USB HID, and has enough GPIO for the switch matrix, OLED, encoder, and RGB LED.

The initial electrical design included:

- A 3×3 switch matrix
- Nine 1N4148 matrix diodes
- An EC11-style rotary encoder
- A 128×32 I²C OLED
- An SK6812 MINI-E status LED
- Four M3 mounting holes

## June 29, 2026 — PCB and component models

I assigned footprints, placed the components, and routed the two-layer PCB. The finished board is approximately 76.2 × 99.54 mm, keeping it below the program's 100 × 100 mm limit.

I also gathered 3D models for the XIAO RP2040, MX switches, OLED, and encoder so I could inspect the complete assembly mechanically before manufacturing.

## June 30, 2026 — Enclosure design

I exported the PCB as a STEP model and brought the electronics into Fusion 360. I designed a two-piece enclosure consisting of:

- A bottom case with PCB mounting standoffs and a USB-C opening
- A top plate with nine switch cutouts
- An OLED window
- An encoder-shaft opening
- Four M3 assembly holes

I adjusted the component and case alignment using rigid groups, projected geometry, and the Align tool. The top and bottom pieces were then exported separately for 3D printing.

## July 1, 2026 — Firmware

I created QMK firmware for the XIAO RP2040. The hardware pin map is:

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
| RGB data | D10 | GP3 |

The default keymap is:

| Undo | Copy | Paste |
|---|---|---|
| Previous track | Play/Pause | Next track |
| Escape | Windows screenshot | Delete |

Turning the encoder changes the system volume. The encoder's push contacts are not connected in this PCB revision, so pressing the knob does not generate an input.

The first QMK build exposed an outdated RGB LED configuration name. I replaced `RGBLED_NUM` with `RGBLIGHT_LED_COUNT`, rebuilt the firmware, and successfully produced `jampad_default.uf2`.

## July 1, 2026 — Electrical verification

A schematic-parity check found that one pad on each matrix diode had not inherited its intended switch net. A normal DRC did not flag this as an unrouted connection because each affected net only contained one assigned pad.

I updated the PCB from the schematic and repaired the nine switch-to-diode routes:

- SW1–D2, SW2–D3, SW3–D4
- SW4–D5, SW5–D6, SW6–D7
- SW7–D8, SW8–D9, SW9–D10

After the repair, KiCad reported zero unconnected pads, no diode net conflicts, and no copper-clearance errors. I regenerated the Gerbers and drill files from the corrected board.

## July 1, 2026 — Submission preparation

I organized the project into CAD, PCB, Firmware, production, and assets folders. I added:

- KiCad source files
- QMK source and compiled UF2 firmware
- Gerbers and drill files
- Complete assembly and individual case STEP files
- Project screenshots
- A bill of materials
- A README and ship-post draft

## July 3, 2026 — Hackboard V3

I updated the Fusion 360 assembly and saved the latest editable model as `CAD/Hackboard_V3.f3z`. The repository keeps the STEP exports alongside the native Fusion archive so the design remains both editable and easy to review.

## Current status

The project now includes the complete PCB design, production files, enclosure models, firmware, documentation, and updated CAD source. The next physical steps are PCB fabrication, case printing, soldering, flashing the firmware, and testing every input on the assembled Jampad.

## Lessons learned

- Run schematic-parity checks in addition to normal PCB DRC.
- Keep imported CAD parts grouped before moving or aligning an assembly.
- Check mechanical clearances using the real component models.
- Preserve editable source files as well as manufacturing exports.
- Compile firmware early enough to catch configuration changes before assembly.

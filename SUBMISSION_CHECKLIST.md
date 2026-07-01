# Jampad submission checklist

## Source files

- [x] `PCB/` contains `.kicad_pro`, `.kicad_sch`, and `.kicad_pcb`
- [x] `Firmware/` contains the complete QMK source
- [x] `CAD/` contains the PCB mechanical STEP
- [ ] Export the complete assembled Fusion design to
  `CAD/Jampad_Complete_Assembly.step`

## Production files

- [x] Compiled QMK firmware saved as `production/firmware.uf2`
- [ ] Repair the nine diode net/routing issues
- [ ] Re-run PCB DRC and schematic parity successfully
- [ ] Create `production/gerbers.zip` only after DRC passes
- [ ] Export `production/Top.step`
- [ ] Export `production/Bottom.step`

## README

- [x] Overall assembly/case screenshot
- [x] Schematic screenshot
- [x] PCB render
- [x] BOM
- [x] Description and controls
- [ ] Replace screenshots with final polished views if desired

## Publishing

- [ ] Create a GitHub repository
- [ ] Copy this project into the cloned repository
- [ ] Commit and push the files
- [ ] Make the ship post in `#hackpad-ships`
- [ ] Complete the submission form


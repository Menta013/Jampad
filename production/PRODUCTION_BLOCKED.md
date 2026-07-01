# Do not order this PCB yet

The KiCad 10 DRC and schematic-parity check found a production-blocking issue:

- `D2` through `D10` pad 1 (`K`) have no PCB net assigned.
- The schematic expects those pads to use `Net-(D2-K)` through
  `Net-(D10-K)`.
- Those are the nine connections between the switches and their matrix
  diodes. If they remain open, the key matrix will not work.

The generated files in `production/gerbers/` are retained only as diagnostic
drafts. They have intentionally not been packaged as `gerbers.zip`.

## Required KiCad repair

1. Open `PCB/Hackboard_v1.kicad_sch`.
2. Confirm each switch connects in series with its corresponding diode.
3. In PCB Editor, run **Tools → Update PCB from Schematic** (`F8`).
4. Confirm diode pad 1 receives the expected `Net-(Dx-K)` net.
5. Route each missing switch-to-diode connection.
6. Run DRC with schematic parity enabled.
7. Do not export final Gerbers until there are:
   - zero unconnected pads,
   - zero missing-net or net-conflict violations,
   - no copper clearance errors.

Silkscreen overlaps can be cleaned separately; they do not normally break
electrical operation. The dangling 5 V via and the duplicate `REF**` mounting
hole references should also be reviewed.


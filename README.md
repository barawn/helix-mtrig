# helix-mtrig
HELIX Master Trigger

## Interfaces

* 4x merger trigger interface
* 2x merger trigger interface + MGT
* 5x ATRG outputs
* 5x dual-ToF trigger inputs
* SFP transceiver w/MGT interface
* +5V power input
* PPS input (50 ohm terminated, up to +5.5V logic)
* External trigger input (50 ohm terminated, up to 5.5V logic)
* Trigger output (~2.5V logic high into 50 ohms)
* USB JTAG/debug console
* External PCIe x4 interface for proxy master merger use

## Power consumption

| Chip | Qty | Rail |	Current |	Power |
| ---- | --- | ---- | ------- | ----- | 
| SN65LVDS100 |	62 |	2.5 |	0.025 |	3.875 |
| SI5395 core |	1  |	1.8	| 0.135	| 0.243 |
| SI5395 core	| 1  |	3.3	| 0.12	| 0.396 |
| SI5395 output |	10 | 2.5 |	0.015	| 0.375 |
| SI53307 core | 1 |	2.5	| 0.065	| 0.1625 |
| SI53307 output | 2	| 2.5 |	0.02	| 0.1 |
| TTEAALJANF-40 |	1	| 3.3	| 0.006	| 0.0198 |
| SN65MLVD128	| 1	| 3.3 |	0.112	| 0.3696 |

Total so far ~5.5W. FPGA estimate coming soon.

Power excludes all devices expected to be powered down during flight (PCIe, USB debug, etc.).

## Clocks

* 50 MHz local oscillator
* 40 MHz VCTCXO master HELIX clock
* 100 MHz auxiliary PCIe clock

### Clock synthesis

* 40 MHz -> 10x TOF + FPGA (SI5395)
* 40 MHz -> 80 MHz -> MGT + FPGA (SI5395)
* 125 MHz PCIe -> 250 MHz PCIe (ICS874003I-02)
* 50 MHz -> 200 MHz (internal to FPGA)

## FPGA

Artix-7 200T in 676-pin package.

## Status

* Schematic ~done, excepting FPGA connections
* Layout in progress

## TO DO

* Replace aux PCIe clock with one that shuts down

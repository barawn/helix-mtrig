#ifndef HELIX_MTRIG_CONFIG_H
#define HELIX_MTRIG_CONFIG_H

#include <unistd.h>

typedef union {
  uint16_t reg;           // full register
  struct {
    uint16_t TRIGEN:1;    // master trigger enable
    uint16_t EXT:1;       // external trigger enable
    uint16_t ZLO:1;       // ZLO enable
    uint16_t ZHI:1;       // ZHI enable
    uint16_t PPSTRIG:1;   // PPS trig enable
    uint16_t RANDTRIG:1;  // RAND trig enable
    uint16_t SOFTTRIG:1;  // SOFT trig enable
    uint16_t :1;          // reserved
    uint16_t UPDDELAY:8;  // delay for trigger enable after update
  } bit;
} MTRIG_TRIGEN_t;

typedef union {
  uint16_t reg;           // full register
  struct {
    uint16_t :15;           // *configuration* reserved registers
    uint16_t CPUINHIBIT:1;  // hold trigger INHIBIT until cleared by CPU
  } bit;
} MTRIG_CPUCONTROL_t;

typedef union {
  uint16_t reg;           // full register
  struct {
    uint16_t ZLOBOREDELAY:8; // ZLO bore paddle trigger delay
    uint16_t ZHIBOREDELAY:8; // ZHI bore paddle trigger delay
  } bit;
} MTRIG_BOREDELAY_t;

typedef union {
  uint16_t reg;           // full register
  struct {
    uint16_t FINE:8;    // ATRG fine delay (78 ps steps, max 186)
    uint16_t COARSE:6;  // ATRG coarse delay
    uint16_t :2;
  } bit;
} MTRIG_ATRGDELAY_t;

typedef union {
  uint16_t reg;           // full register
  struct {
    uint16_t MASK:6;      // busy mask
    uint16_t :10;         // reserved for writes
  } bit;
} MTRIG_BUSYCTRL_t;

typedef union {
  uint16_t reg;           // full register
  struct {
    uint16_t RST:6;       // issue a pulse on FST_CTRL
    uint16_t :10;           // reserved
  } bit;
} MTRIG_RSTCTRL_t;

typedef union {
  uint16_t reg;           // full register
  struct {
    uint16_t SYSCLK:8;    // SYSCLK sync delay
    uint16_t TRIGCLK:8;   // TRIGCLK sync delay
  } bit;
} MTRIG_SYNCDELAY_t;

typedef union {
  uint16_t reg;           // full register
  struct {
    uint16_t HOLDOFF:10;  // PPS holdoff (milliseconds)
    uint16_t :4;
    uint16_t PPSINV:1;    // PPS is inverted
    uint16_t INTPPS:1;    // use internal PPS
  } bit;
} MTRIG_PPSCTRL_t;

typedef union {
  uint16_t reg;           // full register
  struct {
    uint16_t SYSOFFSET:8; // system clock offset for trigger events
    uint16_t TRIGOFFSET:8; // trigger clock offset for trigger events
  } bit;
} MTRIG_EVENTOFFSET_t;

// These are *all* the registers, obviously some of them are read-only.
// those are skipped in the update function
typedef struct {
  uint16_t            IDENT;        // identification register
  uint16_t            SERNO;        // serial number
  uint16_t            VERSION;      // major/minor revision of firmware
  uint16_t            DATE;         // date of compilation
  MTRIG_TRIGEN_t      TRIGEN;       // trigger enable register
  uint16_t            INHIBITLEN;   // number of 80 MHz clocks to hold off trigger
  MTRIG_CPUCONTROL_t  CPUCONTROL;   // direct CPU control register
  uint16_t            RANDTRIG;     // sets random trigger rate (units of 0.5 Hz)
  uint16_t            ZLOLOGIC[5];  // LUT initialization for ZLO trigger
  uint16_t            ZHILOGIC[5];  // LUT initialization for ZHI trigger
  MTRIG_BOREDELAY_t   BOREDELAY;    // bore paddle trigger delays
  uint16_t            ZLOPRESCALE;  // ZLO prescaler (linear prescale!)
  uint16_t            ZHIPRESCALE;  // ZHI prescaler (linear prescale!)
  uint16_t            AUXLEN;       // length of any auxiliary trigger (PPS, SOFT, EXT, RAND)
  MTRIG_ATRGDELAY_t   ATRGDELAY;    // ATRG delay
  uint16_t            ATRGLEN;      // ATRG pulse length
  uint16_t            STRGDELAY;    // STRG delay in 80 MHz periods (12.5 ns)
  uint16_t            STRGLEN;      // STRG length in 80 MHz periods
  MTRIG_BUSYCTRL_t    BUSYCTRL;     // BUSY mask and active BUSY
  MTRIG_RSTCTRL_t     RSTCTRL;      // control for issuing pulses on FST_CTRL
  uint16_t            reserved0;
  uint16_t            reserved1;
  uint16_t            PPS[2];       // PPS value. This should be skipped if you don't want to update it.
  uint16_t            SYSCLK_PPS[2]; // SYSCLK pps value, use only for sync
  uint16_t            SYSCLK_FREQ[2];// SYSCLK frequency, read only
  uint16_t            TRIGCLK_PPS[2]; // TRIGCLK pps value, use only for sync
  uint16_t            TRIGCLK_FREQ[2]; // TRIGCLK frequency
  uint16_t            DEADCLK_PPS[2];  // DEADCLK counter, use only to reset deadcount
  uint16_t            DEADCLK_FREQ[2]; // DEADCLK frequency
  uint16_t            SYSCLK_PPS_H;  // SYSCLK pps high word (47:32)
  uint16_t            TRIGCLK_PPS_H;  // TRIGCLK pps high word (47:32)
  uint16_t            DEADCLK_PPS_H;  // DEADCLK pps high word (47:32)
  MTRIG_SYNCDELAY_t   SYCNDELAY;      // SYNC delay values
  MTRIG_PPSCTRL_t     PPSCTRL;        // PPS control value
  uint16_t            reserved2;
  uint16_t            EVENTEXPANDRATE; // expanded event rate (must be power of 2 minus 1)
  uint16_t            TRIGNO[2];       // current trigger number
  MTRIG_EVENTOFFSET_t EVENTOFFSET;     // event trigger time offset
  uint16_t            reserved3;
  uint16_t            reserved4;
  uint16_t            reserved5;
  uint16_t            TRIGCONF;        // trigger config word in each event
} MTRIG_CONFIG_t;

void helix_mtrig_config_default(MTRIG_CONFIG_t *config);

#endif

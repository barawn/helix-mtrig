#include <stdio.h>
#include "helix_mtrig_config.h"

MTRIG_CONFIG_t mtrig_config;

int main() {
  // initialize
  helix_mtrig_config_default(&mtrig_config);
  // enable the external trigger and PPS trigger
  mtrig_config.TRIGEN.bit.TRIGEN = 1;
  mtrig_config.TRIGEN.bit.PPSTRIG = 1;
  mtrig_config.TRIGEN.bit.EXT = 1;
  printf("set trigen to %2.2x\n", mtrig_config.TRIGEN.reg);
}

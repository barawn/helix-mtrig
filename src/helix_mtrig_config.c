#include "helix_mtrig_config.h"

void helix_mtrig_config_default(MTRIG_CONFIG_t *config) {
  // just try something for now
  config->ZLOLOGIC[0] = 0xFFFF;
  config->ZLOLOGIC[1] = 0xFFFF;
  config->ZLOLOGIC[2] = 0xFFFF;
  config->ZLOLOGIC[3] = 0xFFFF;
}

#include "safeshutd.h"

std::ofstream sslog("/var/log/safeshutd.log");

int main() {
  setup_daemon();

  if (!bcm2835_init()) {
    sslog << "GPIO init failed!" << endl;
    return 1;
  }

  std::atexit([] {
    sslog << "Cleaning up GPIO!" << endl;
    bcm2835_close();
  });

  std::ofstream f;

  std::signal(SIGINT, [](int) {
    sslog << "\b\bSIGINT caught!" << endl;
    std::exit(0);
  });

  sslog << "Hello GPIO!" << endl;

  bcm2835_gpio_fsel(LED_PIN, BCM2835_GPIO_FSEL_OUTP);

  int cnt = 20;
  while (cnt--) {
    bcm2835_gpio_write(LED_PIN, HIGH);
    bcm2835_delay(500);
    bcm2835_gpio_write(LED_PIN, LOW);
    bcm2835_delay(500);
  }

  return 0;
}

void setup_daemon() {
  daemon(false, false);
}

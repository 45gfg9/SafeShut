#include <iostream>
#include <csignal>
#include <bcm2835.h>

using std::cout;
using std::endl;

const int PIN = 12;

int main() {
  if (!bcm2835_init()) {
    cout << "GPIO init failed!" << endl;
    return 1;
  }

  std::atexit([] {
    cout << "Cleaning up GPIO!" << endl;
    bcm2835_close();
  });

  std::signal(SIGINT, [](int) {
    cout << "\b\bSIGINT caught!" << endl;
    std::exit(0);
  });

  cout << "Hello GPIO!" << endl;

  bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_OUTP);

  int cnt = 20;
  while (cnt--) {
    bcm2835_gpio_write(PIN, HIGH);
    bcm2835_delay(500);
    bcm2835_gpio_write(PIN, LOW);
    bcm2835_delay(500);
  }

  return 0;
}

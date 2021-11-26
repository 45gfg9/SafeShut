#ifndef __SAFESHUTD__
#define __SAFESHUTD__

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <csignal>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <getopt.h>
#include <bcm2835.h>

#include "pins.h"

using std::endl;

extern std::ofstream sslog;

void setup_daemon();

#endif

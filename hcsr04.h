// ============================================================
//  hcsr04.h — Sensor ultrasónico HC-SR04 para PICasp
//  Versión: 1.0.0
// ============================================================

#ifndef HCSR04_H
#define HCSR04_H

#include <stdint.h>
#include <picasp.h>

// ── API pública ───────────────────────────────────────────────
// Uso:
//   HCSR04.begin(RB0, RB1);
//   uint16_t cm = HCSR04.readCm();

void     HCSR04_begin(pin_t trigPin, pin_t echoPin);
uint16_t HCSR04_readCm(void);
uint16_t HCSR04_readMm(void);
uint16_t HCSR04_readInch(void);

#endif // HCSR04_H

// ============================================================
//  hcsr04.h — Sensor ultrasónico HC-SR04 para PICasp
//  Versión: 1.0.0
//  Sintaxis compatible con notación de punto PICasp/Arduino
// ============================================================

#ifndef HCSR04_H
#define HCSR04_H

#include <stdint.h>
#include <picasp.h>

// ── Timeout máximo del sensor (38ms) ─────────────────────────
#define HCSR04_TIMEOUT_US 38000UL

// ── Estructura del sensor ─────────────────────────────────────
typedef struct {
    pin_t trigPin;
    pin_t echoPin;
} HCSR04;

// ── API pública ───────────────────────────────────────────────
// Uso con notación de punto:
//   HCSR04 sensor;
//   HCSR04.begin(&sensor, RB0, RB1);
//   uint16_t cm = HCSR04.readCm(&sensor);

void     HCSR04_begin(HCSR04* sensor, pin_t trigPin, pin_t echoPin);
uint16_t HCSR04_readCm(HCSR04* sensor);
uint16_t HCSR04_readMm(HCSR04* sensor);
uint16_t HCSR04_readInch(HCSR04* sensor);

#endif // HCSR04_H

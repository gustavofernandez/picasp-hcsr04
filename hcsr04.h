// ============================================================
//  hcsr04.h — Sensor ultrasónico HC-SR04 para PICasp
//  Versión: 1.1.0
// ============================================================
#ifndef HCSR04_H
#define HCSR04_H

#include <stdint.h>
#include <picasp.h>

// ── Funciones planas (siguen disponibles) ─────────────────────
void     HCSR04_begin   (pin_t trigPin, pin_t echoPin);
uint16_t HCSR04_readCm  (void);
uint16_t HCSR04_readMm  (void);
uint16_t HCSR04_readInch(void);

// ── Objeto Arduino-style ──────────────────────────────────────
// Uso:
//   HCSR04.begin(RB0, RB1);
//   uint16_t cm = HCSR04.readCm();
typedef struct {
    void     (*begin)   (pin_t trigPin, pin_t echoPin);
    uint16_t (*readCm)  (void);
    uint16_t (*readMm)  (void);
    uint16_t (*readInch)(void);
} HCSR04_t;

extern HCSR04_t HCSR04;

#endif // HCSR04_H

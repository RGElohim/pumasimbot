/**
 * @file camara_capture.h
 * @brief Librería para captura de imágenes desde cámara web
 */

#ifndef CAMARA_CAPTURE_H
#define CAMARA_CAPTURE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

/**
 * @brief Captura una foto desde la cámara indicada y la guarda en disco.
 * 
 * @param indice_camara Índice del dispositivo USB (0 para la integrada, en mi caso, 4 para logitech).
 * @param ruta_salida Ruta y nombre del archivo resultante (ej. "foto.jpg" o "/tmp/captura.png").
 * @return true si se capturó y guardó con éxito, false si ocurrió un error.
 */
bool capturar_y_guardar_foto(int indice_camara, const char* ruta_salida, int ancho, int alto);

/**
 * @brief Intenta capturar una foto automáticamente probando la cámara externa (4) y luego la integrada (0).
 * 
 * @param ruta_salida Ruta del archivo donde se guardará la imagen.
 * @return true si la captura fue exitosa.
 */
bool capturar_foto_auto(const char* ruta_salida);

#ifdef __cplusplus
}
#endif

#endif // CAMARA_CAPTURE_H

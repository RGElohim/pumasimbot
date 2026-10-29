#include "camara_capture.h"
#include <opencv2/opencv.hpp>
#include <iostream>

bool capturar_y_guardar_foto(int indice_camara, const char* ruta_salida, int ancho, int alto) {
    if (!ruta_salida) {
        std::cerr << "[Error Cámara] La ruta de salida no es válida." << std::endl;
        return false;
    }

    // Abrir el dispositivo usando el backend de Linux (V4L2)
    cv::VideoCapture cap(indice_camara, cv::CAP_V4L2);

    if (!cap.isOpened()) {
        // Reintento genérico por si falla V4L2 explícito
        cap.open(indice_camara);
        if (!cap.isOpened()) {
            std::cerr << "[Error Cámara] No se pudo abrir el dispositivo en el índice: " 
                      << indice_camara << std::endl;
            return false;
        }
    }

   // 1. CONFIGURAR EL FORMATO DE VIDEO A MJPEG PARA MEJOR COMPATIBILIDAD
cap.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'));

    // 2. CONFIGURAR ANCHO Y ALTO SOLICITADOS
    cap.set(cv::CAP_PROP_FRAME_WIDTH, ancho);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, alto);



    // Descartar los primeros 5 fotogramas para dar tiempo al sensor 
    // a regular el balance de blancos, enfoque y brillo automático.
    cv::Mat frame;
    for (int i = 0; i < 5; ++i) {
        cap >> frame;
    }

    // Captura del fotograma definitivo
    cap >> frame;

    if (frame.empty()) {
        std::cerr << "[Error Cámara] Se obtuvo un fotograma vacío." << std::endl;
        cap.release();
        return false;
    }

    // Guardar la imagen en el formato deseado (.jpg, .png, etc.)
    bool guardado_ok = cv::imwrite(ruta_salida, frame);
    cap.release(); // Cerrar el dispositivo

    if (guardado_ok) {
        std::cout << "[Info Cámara] Imagen guardada correctamente en: " << ruta_salida << std::endl;
    } else {
        std::cerr << "[Error Cámara] Falló al escribir el archivo en: " << ruta_salida << std::endl;
    }

    return guardado_ok;
}

bool capturar_foto_auto(const char* ruta_salida) {
    // Probar primero el índice 4 (Cámara externa Logitech C920)
    if (capturar_y_guardar_foto(4, ruta_salida, 640, 480)) {
        return true;
    }
    
    // Si la cámara 4 falla, reintentar con el índice 0 (cámara integrada)
    std::cout << "[Info Cámara] Intentando con la cámara en el índice 0..." << std::endl;
    return capturar_y_guardar_foto(0, ruta_salida, 640, 480);
}

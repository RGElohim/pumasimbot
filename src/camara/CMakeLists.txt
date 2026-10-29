# Buscar el paquete de OpenCV instalado en el sistema
#instalar previamente OpenCV en el sistema para que CMake pueda encontrarlo si no se ha hecho previamente.
find_package(OpenCV REQUIRED)

# Crear una librería con el código de la cámara
add_library(camara_lib STATIC
    camara_capture.cpp
    camara_capture.h
)

# Indicar los directorios de inclusión de OpenCV
target_include_directories(camara_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${OpenCV_INCLUDE_DIRS}
)

# Enlazar OpenCV con librería
target_link_libraries(camara_lib PUBLIC
    ${OpenCV_LIBS}
)
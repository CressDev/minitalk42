
## Descripción

**Minitalk** es un programa de comunicación que permite el intercambio de mensajes entre dos procesos usando únicamente señales UNIX (`SIGUSR1` y `SIGUSR2`). Este proyecto forma parte del currículo de 42 School y demuestra el manejo de señales, comunicación entre procesos y gestión de memoria en C.

## Características

- Comunicación bidireccional** entre cliente y servidor
- Transmisión bit a bit usando señales UNIX
- Gestión robusta de memoria sin memory leaks
- Confirmación de recepción entre procesos
- Manejo de errores completo
- Soporte para Unicode y caracteres especiales

## Arquitectura del Sistema

### Servidor
- Recibe el PID al iniciar y lo muestra
- Escucha señales `SIGUSR1` (bit 1) y `SIGUSR2` (bit 0)
- Reconstruye los caracteres bit a bit
- Confirma la recepción al cliente
- Imprime el mensaje completo al recibirlo

### Cliente
- Envía mensajes al servidor usando su PID
- Convierte cada carácter a representación binaria
- Transmite bit a bit usando señales
- Espera confirmación antes del siguiente bit
- Recibe confirmación final del servidor

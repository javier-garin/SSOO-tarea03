# SSOO-tarea03

En esta tarea 3 hemos implementado 2 funciones, la principal (main) y una funcion signal_handler que interpretará las señales recibidas
Al inicio de todo el programa incluimos las librerias a usar.
La funcion signal_hanlder solo mostrará el mensaje que indica que no se puede terminar el proceso por los medios convencionales (ctrl+c, ctrl+z, ctrl+\).
Nuestra funcion main inicia declarando las variables que utilizaremos, luego el fork() para crear al proceso hijo.
Utilizamos un if para determinar que codigo deberán ejecutar los procesos padre e hijo.
El proceso hijo que es el numero impar solo imprime el numero junto a su PID, se le suma +2 al numero y con un sleep_for controlamos la velocidad del programa, todo dentro de un for que va desde 0 hasta 50 (sin incluir).
El proceso padre que es el numero de Fibonacci, el cual se imrpime el primero, se hacen los calculos de sumar el nuevo numero con el anterior para obtener el siguiente numero, luego nuevamente utilizamos un sleep_for para controlar la velocidad del programa, al igual que el proceso hijo, todo esta dentro de un for que va desde 0 hasta 50 (sin incluirlo).

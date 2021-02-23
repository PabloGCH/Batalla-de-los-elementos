=================================================================
                          COMPILACION

- Es necesario instalar las libreria de SDL2 y un complemento
de esta llamado SDL2_image para compilarlo para ello solo es
necesario introducir lo siguiente en la terminal:
    Para SDL2:

        sudo apt-get install libsdl2-dev

    Para SDL2_image:
    
        sudo apt-get install libsdl2-image-dev

- Una vez tenga todas las librerias solo es necesario escribir
"make" (sin las comillas) en la terminal. Al finalizar creara
un archivo llamado "Bdle" el cual es el ejecutable del juego
=================================================================
                          IMPORTANTE

- El juego debe ejecutarse desde la terminal introduciendo
"./Bdle", ya que los menus del juego se muestran atraves de la
terminal (No pusimos los menus en la ventana de SDL porque
requeria trabajar con fuentes, y nos habria tomado tiempo
del que no disponiamos)
- Una vez ejecutado el juego, se abrira una segunda ventana, esta
Mostrara el tablero con los personajes en el. Es aconsejable
moverla hacia un lado de la pantalla y enfocar solo la terminal.
Esto es debido a que todos los inputs se dan mediante la terminal
y no en eventos de SDL, y al no recibir eventos la computadora
puede llegar a la conclusion erronea de que el programa 
no responde (Si aparece el mensaje cliquear esperar, despues de 2
o 3 veces deja de aparecer).
=================================================================
                          COMENTARIOS

- Los personajes son representados por fichas, estas tienen un
borde de color azul oscuro para el jugador 2 y gris oscuro para
el jugador 1.

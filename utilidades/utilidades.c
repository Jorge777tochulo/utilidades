////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// ZONA DE IMPORTACIÓN: FICHEROS NECESARIOS A INCLUIR
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#include "utilidades.h"   // Mi propia colección de subprogramas útiles.



////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// ZONA DE MACROS, CONSTANTES Y VARIABLES GLOBALES: PARA USO GLOBAL.
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

char MSJxERROR[] = "¡VALOR NO VÁLIDO!";
char MSJxPAUSA[] = "Pulse INTRO para continuar... ";

int codigoError; // VARIABLE GLOBAL: Visible por todos los subprogramas.



////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// ZONA DE CÓDIGO: CUERPOS DE LOS SUBPROGRAMAS DECLARADOS ANTES.
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void esperarINTRO (void);
//
//  USO:
//
//    Programa que produce una espera hasta que se pulse INTRO.
//
//  DETALLES:
//
//    Es un envoltorio de la función vaciarBuffer(), a la cual delega todo el
//    trabajo. Es una manera de crear "sinónimos" de acciones, es decir, de
//    tener disponibles varios nombres para hacer lo mismo.
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    vaciarBuffer()
//
//      Se delega toda la carga de trabajo a esta función.
//
////////////////////////////////////////////////////////////////////////////////

void esperarINTRO (void)
{
  vaciarBuffer();
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//     void descartarEntrada (void)

//
//  USO:
//
//    Programa que descarta cualquier dato pendiente en el buffer de entrada.
//
//  DETALLES:
//
//   Esta función simplemente llama a vaciarBuffer(), que es la que realmente
//    hace el trabajo. Se usa para tener otro nombre más claro para la misma acción.
//
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    vaciarBuffer()
//
//      Se delega toda la carga de trabajo a esta función.
//
////////////////////////////////////////////////////////////////////////////////

void descartarEntrada (void)
{
  vaciarBuffer();
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void vaciarBuffer (void);
//
//  USO:
//
//    Programa que espera que el usuario pulse teclas a la espera de INTRO.
//
//  DETALLES:
//
//    Se basa en un bucle que va pidiendo letras del buffer de teclado y no
//    termina hasta que detecta que ha encontrado un "INTRO" (0x10). Cualquier
//    otro código ASCII introducido por el usuario se descarta. Se produce ECO
//    de cualquier tecla pulsada.
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    getchar()
//
//      Es el programa estándar ("prefabricado") que hace la logística de
//      comunicarse con el sistema operativo y con el hardware del teclado.
//
////////////////////////////////////////////////////////////////////////////////

void vaciarBuffer (void)
{
  // ENTER CREADO EN DEFINE = ASCII(10) = 0x0A
  
  // MEDIANTE BUCLE DO-WHILE:
  char letra;
  do
  {
    letra = getchar();
  } while (letra != ENTER);
  
  // MEDIANTE BUBLE WHILE:
  // while (getchar() != '\n')   ; // Bucle vacío
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//     void borrarPantalla (void)

//
//  USO:
//
//    Sirve para limpiar la pantalla.
//
//  DETALLES:
//
//  Esta función borra todo lo que hay en la pantalla llamando a
//    limpiarPantalla(), que es la que hace realmente el trabajo.

//
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    limpiarPantalla()
//
//    Esta función es la que se encarga de limpiar la pantalla.
//
////////////////////////////////////////////////////////////////////////////////

void borrarPantalla (void)
{
  limpiarPantalla();
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//     void limpiarPantalla (void)

//
//  USO:
//
//    Sirve para limpiar la pantalla.
//
//  DETALLES:
//
//    Esta función usa system(BORRAR) para limpiar la pantalla.
//    BORRAR suele guardar el comando que se necesita para hacerlo
//    (por ejemplo "cls" o "clear").

//
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//     system()
//
//    Se usa para ejecutar el comando que limpia la pantalla.
//
////////////////////////////////////////////////////////////////////////////////

void limpiarPantalla (void)
{
  system(BORRAR);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void bajar (int nlineas);
//
//  USO:
//
//    Permite bajar el cursor en la pantalla, tantas líneas como se le indique.
//
//  DETALLES:
//
//    Crea tantas líneas en blanco como se le suministre como dato. No ubica el
//    cursor de texto en ninguna coordenada concreta, sino que genera contenido
//    en blanco en la pantalla, desplazando el punto donde se escribirá texto en
//    acciones posteriores. Utiliza para ello un bucle en cuyo interior se llama
//    a printf() con el código ASCII de salto de línea '\n' ó 0x10.
//
//  PARÁMETROS DE ENTRADA:
//
//    nlineas
//
//      Variable entera que recibirá del exterior el número de líneas en blanco
//      que se va a desplazar el cursor hacia abajo.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    printf()
//
//      Es el programa estándar ("prefabricado") que hace la logística de
//      emitir por pantalla.
//
////////////////////////////////////////////////////////////////////////////////

void bajar (int nlineas)
{
  while(nlineas>0)
  {
    printf("\n");   // No se puede usar "mostrar()" porque crearíamos un bucle de llamadas.
    
    nlineas--;
  }
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void abajo (int nfils)

//
//  USO:
//
//    Sirve para bajar un número de líneas en la pantalla.

//
//  DETALLES:
//
//   Esta función llama a bajar(nfiles), que es la que realmente
//    se encarga de mover hacia abajo las líneas indicadas.

//
//
//  PARÁMETROS DE ENTRADA:
//
//  nfiles → número de líneas que se quieren bajar.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//      bajar()
//
//    Es la función que realiza el movimiento hacia abajo.
//
////////////////////////////////////////////////////////////////////////////////

void abajo (int nfils)
{
  bajar(nfils);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void saltar (int nfils)

//
//  USO:
//
//    Sirve para saltar un número de líneas en la pantalla.

//
//  DETALLES:
//
//   Esta función llama a saltar(nfiles), que es la que realmente
//    se encarga de saltarse  las líneas indicadas.

//
//
//  PARÁMETROS DE ENTRADA:
//
//  nfiles → número de líneas que se quieren saltar.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//      bajar()
//
//    Es la función que realiza el movimiento de saltar.
//
////////////////////////////////////////////////////////////////////////////////

void saltar (int nfils)
{
  bajar(nfils);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarFils (int nfils)

//
//  USO:
//
//    Sirve para desplazar un número de líneas en la pantalla.

//
//  DETALLES:
//
//   Esta función llama a bajar(nfiles), que es la que realmente
//    se encarga de desplazar  las líneas indicadas.

//
//
//  PARÁMETROS DE ENTRADA:
//
//  nfiles → número de líneas que se quieren desplazar.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//      bajar()
//
//    Es la función que realiza el movimiento de desplazar.
//
////////////////////////////////////////////////////////////////////////////////

void desplazarFils (int nfils)
{
  bajar(nfils);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarV (int nfils)

//
//  USO:
//
//    Sirve para desplazar un número de líneas en la pantalla verticalmente.

//
//  DETALLES:
//
//   Esta función llama a bajar(nfiles), que es la que realmente
//    se encarga de desplazar las líneas indicadas verticalmente.

//
//
//  PARÁMETROS DE ENTRADA:
//
//  nfiles → número de líneas que se quieren desplazar verticalmente.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//      bajar()
//
//    Es la función que realiza el movimiento de desplazar verticalmete.
//
////////////////////////////////////////////////////////////////////////////////

void desplazarV (int nfils)
{
  bajar(nfils);
}

/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    void desplazarV(int nfils);
//
// USO:
//
//    Programa que produce un desplazamiento vertical en la consola.
//
// DETALLES:
//
//    Es un envoltorio de la función bajar(), a la cual delega todo el
//    trabajo. Es una manera de crear "sinónimos" de acciones para que
//    el código sea más legible según el contexto.
//
// PARÁMETROS DE ENTRADA:
//
//    nfils: Número de líneas que se desea desplazar hacia abajo.
//
// VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
// FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar()
//       Se delega toda la carga de trabajo a esta función.
//
/////////////////////////////////////////////////////////////////////////////

void desplazarY (int nfils)
{
  bajar(nfils);
}

/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    void indentar(int columnas);
//
// USO:
//
//    Añade espacios en blanco al principio de una línea.
//
// DETALLES:
//
//    Sirve para dejar un margen a la izquierda. Se usa printf directo 
//    para evitar que el programa se raye llamando a otras funciones.
//
// PARÁMETROS DE ENTRADA:
//
//    columnas: Cuántos espacios queremos poner.
//
// VALOR DE SALIDA:
//
//    No devuelve nada.
//
// FUNCIONES DE LAS QUE DEPENDE:
//
//    printf()
//
/////////////////////////////////////////////////////////////////////////////

void indentar (int ncolumnas)
{
  for(int i=0; i<ncolumnas; i++)
  {
    printf(" ");   // No se puede usar "mostrar()" porque crearíamos un bucle de llamadas.
  }
}

/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    void derecha(int ncols);
//
// USO:
//
//    Mueve el cursor hacia la derecha antes de escribir.
//
// DETALLES:
//
//    Es un sinónimo de indentar(). Se usa para que el código sea más 
//    fácil de leer cuando queremos alinear algo a la derecha.
//
// PARÁMETROS DE ENTRADA:
//
//    ncols: El número de espacios que queremos desplazar.
//
// VALOR DE SALIDA:
//
//    No devuelve nada.
//
// FUNCIONES DE LAS QUE DEPENDE:
//
//    indentar()
//
/////////////////////////////////////////////////////////////////////////////

void derecha (int ncols)
{
  indentar(ncols);
}

/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    void tabular(int ncols);
//
// USO:
//
//    Sirve para organizar el texto en columnas.
//
// DETALLES:
//
//    Es otro sinónimo de indentar(). Se llama así para que el código
//    se entienda mejor cuando estamos haciendo tablas o listas.
//
// PARÁMETROS DE ENTRADA:
//
//    ncols: El número de espacios para la tabulación.
//
// VALOR DE SALIDA:
//
//    No devuelve nada.
//
// FUNCIONES DE LAS QUE DEPENDE:
//
//    indentar()
//
/////////////////////////////////////////////////////////////////////////////

void tabular (int ncols)
{
  indentar(ncols);
}

/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    void desplazarCols(int ncols);
//
// USO:
//
//    Desplaza el texto hacia la derecha por columnas.
//
// DETALLES:
//
//    Es un sinónimo de indentar(). Se usa para que el código sea claro
//    cuando el objetivo es mover la posición horizontal del texto.
//
// PARÁMETROS DE ENTRADA:
//
//    ncols: Cantidad de espacios (columnas) que se quiere desplazar.
//
// VALOR DE SALIDA:
//
//    No devuelve nada.
//
// FUNCIONES DE LAS QUE DEPENDE:
//
//    indentar()
//
/////////////////////////////////////////////////////////////////////////////

void desplazarCols (int ncols)
{
  indentar(ncols);
}

/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    void desplazarX(int ncols);
//
// USO:
//
//    Mueve el texto de forma horizontal (en el eje X).
//
// DETALLES:
//
//    Es un sinónimo de indentar(). Se llama así para aclarar que el 
//    movimiento es lateral, como en las gráficas de matemáticas.
//
// PARÁMETROS DE ENTRADA:
//
//    ncols: El número de espacios que se desplaza a la derecha.
//
// VALOR DE SALIDA:
//
//    No devuelve nada.
//
// FUNCIONES DE LAS QUE DEPENDE:
//
//    indentar()
//
/////////////////////////////////////////////////////////////////////////////

void desplazarX (int ncols)
{
  indentar(ncols);
}

/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    void desplazarH(int ncols);
//
// USO:
//
//    Mueve el texto de forma horizontal por la pantalla.
//
// DETALLES:
//
//    Es un sinónimo de indentar(). La "H" sirve para recordar que el
//    desplazamiento es Horizontal (de izquierda a derecha).
//
// PARÁMETROS DE ENTRADA:
//
//    ncols: El número de espacios que queremos desplazar.
//
// VALOR DE SALIDA:
//
//    No devuelve nada.
//
// FUNCIONES DE LAS QUE DEPENDE:
//
//    indentar()
//
////////////////////////////////////////////

void desplazarH (int ncols)
{
  indentar(ncols);
}

Esta función es la que une todo lo anterior. Sirve para mover el cursor a un punto exacto de la pantalla (como si fuera una coordenada).

Aquí tienes la ficha resumida:

Código y Documentación en C
C
/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    void posicionar(int nfils, int ncols);
//
// USO:
//
//    Coloca el cursor en una posición concreta de la pantalla.
//
// DETALLES:
//
//    Combina bajar() e indentar() para elegir la fila y la columna 
//    donde queremos empezar a escribir. Es como dar una dirección exacta.
//
// PARÁMETROS DE ENTRADA:
//
//    nfils: Cuántas líneas bajamos (posición vertical).
//    ncols: Cuántos espacios nos movemos (posición horizontal).
//
// VALOR DE SALIDA:
//
//    No devuelve nada.
//
// FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar()
//    tabular() (que a su vez llama a indentar)
//
/////////////////////////////////////////////////////////////////////////////

void posicionar (int nfils, int ncols)
{
  bajar(nfils);
  tabular(ncols);
}

/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    void desplazar(int nfils, int ncols);
//
// USO:
//
//    Mueve el cursor a una posición específica de la pantalla.
//
// DETALLES:
//
//    Es un sinónimo de posicionar(). Se usa para que el código sea más
//    fácil de leer cuando queremos decir "muévete a este sitio".
//
// PARÁMETROS DE ENTRADA:
//
//    nfils: El número de filas que bajamos.
//    ncols: El número de columnas que nos movemos a la derecha.
//
// VALOR DE SALIDA:
//
//    No devuelve nada.
//
// FUNCIONES DE LAS QUE DEPENDE:
//
//    posicionar()
//
/////////////////////////////////////////////////////////////////////////////

void desplazar (int nfils, int ncols)
{
  posicionar(nfils, ncols);
}

/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    void desplazarXY(int nfils, int ncols);
//
// USO:
//
//    Mueve el cursor usando coordenadas de filas y columnas.
//
// DETALLES:
//
//    Es un sinónimo de posicionar(). Se llama así para que parezca que
//    estamos trabajando sobre un plano con coordenadas X e Y.
//
// PARÁMETROS DE ENTRADA:
//
//    nfils: El número de filas (eje Y).
//    ncols: El número de columnas (eje X).
//
// VALOR DE SALIDA:
//
//    No devuelve nada.
//
// FUNCIONES DE LAS QUE DEPENDE:
//
//    posicionar()
//
/////////////////////////////////////////////////////////////////////////////

void desplazarXY (int nfils, int ncols)
{
  posicionar(nfils, ncols);
}

/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    void retardoSegundos(int segundosmax);
//
// USO:
//
//    Hace que el programa se detenga durante unos segundos.
//
// DETALLES:
//
//    Obliga al ordenador a contar números muy altos sin hacer nada más.
//    Se usan varios bucles metidos unos dentro de otros para que el 
//    tiempo de espera sea lo más parecido a segundos reales.
//
// PARÁMETROS DE ENTRADA:
//
//    segundosmax: El número de segundos que queremos que dure la pausa.
//
// VALOR DE SALIDA:
//
//    No devuelve nada.
//
// FUNCIONES DE LAS QUE DEPENDE:
//
//    Ninguna.
//
/////////////////////////////////////////////////////////////////////////////

void retardoSegundos (int segundosmax)
{
  // POSIBILIDAD: Poner en función de la que usa milisegundos.
  
  // AJUSTAR CEROS DE LOS BUCLES PARA APROXIMAR EL PERIODO.

  for(int nseg=0; nseg < segundosmax ; nseg++)
  {
    for(int j=0; j<100; j++)
      for(int j=0; j<1000; j++)
        for(int k=0; k<1000; k++)   ;
  }
}

///////////
//
// FUNCIÓN:
//
//    void retardoMilisegundos(int milisegundosmax);
//
// USO:
//
//    Hace que el programa se detenga durante un tiempo muy breve.
//
// DETALLES:
//
//    Es una pausa de precisión. Sirve para esperar milésimas de segundo.
//    Igual que con los segundos, el ordenador se pone a contar números 
//    en bucle para "perder el tiempo" de forma controlada.
//
// PARÁMETROS DE ENTRADA:
//
//    milisegundosmax: El número de milisegundos que queremos esperar.
//
// VALOR DE SALIDA:
//
//    No devuelve nada.
//
// FUNCIONES DE LAS QUE DEPENDE:
//
//    Ninguna.
//
/////////////////////////////////////////////////////////////////////////////

void retardoMilisegundos (int milisegundosmax)
{
  int i, j;
  
  // AJUSTAR CEROS DE LOS BUCLES PARA APROXIMAR EL PERIODO.

  for (int nmiliseg=0; nmiliseg<milisegundosmax ; nmiliseg++)
    for (i=0; i<100; i++)
      for (j=0; j<1000; j++)   ;
}


/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    void retrasoMilisegundos(int milisegundos);
//
// USO:
//
//    Crea una pausa exacta usando el reloj del sistema.
//
// DETALLES:
//
//    A diferencia de los bucles de antes, esta función pregunta la hora al
//    ordenador constantemente hasta que han pasado los milisegundos 
//    que le pedimos. Es mucho más precisa y no depende de la velocidad
//    del procesador.
//
// PARÁMETROS DE ENTRADA:
//
//    milisegundos: El tiempo exacto que queremos esperar.
//
// VALOR DE SALIDA:
//
//    No devuelve nada.
//
// FUNCIONES DE LAS QUE DEPENDE:
//
//    clock() y la constante CLOCKS_PER_SEC (de la librería <time.h>).
//
/////////////////////////////////////////////////////////////////////////////

void retrasoMilisegundos (int milisegundos)
{
  double e = 0;

  clock_t t0 = clock();   // clock_t es un tipo interno equivalente a UINT32.
  
  do
  {
    
    e = 1000*(double)(clock()-t0)/CLOCKS_PER_SEC;

  } while (e<milisegundos);
}


/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    void esperarSegundos(int segundos);
//
// USO:
//
//    Detiene el programa durante unos segundos de forma automática.
//
// DETALLES:
//
//    Es una función "todo terreno". Si el ordenador usa Windows, usa una
//    orden llamada Sleep; si usa otro sistema (como Linux), usa sleep.
//    Así el programa funciona bien en cualquier ordenador.
//
// PARÁMETROS DE ENTRADA:
//
//    segundos: El tiempo que queremos que el programa se pare.
//
// VALOR DE SALIDA:
//
//    No devuelve nada.
//
// FUNCIONES DE LAS QUE DEPENDE:
//
//    Sleep() de Windows o sleep() de librerías estándar.
//
/////////////////////////////////////////////////////////////////////////////

void esperarSegundos (int segundos)
{
  #ifdef SO_WINDOWS
    Sleep(segundos*1000);
  #else
    sleep(segundos);
  #endif
}

/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    void esperarMilisegundos(int milisegundos);
//
// USO:
//
//    Hace una pausa precisa de milésimas de segundo.
//
// DETALLES:
//
//    Al igual que la de segundos, esta función detecta si estás en Windows 
//    o en otro sistema. Es muy útil para pequeñas pausas en animaciones 
//    o para que el texto no aparezca de golpe.
//
// PARÁMETROS DE ENTRADA:
//
//    milisegundos: El tiempo de espera (1000 milisegundos = 1 segundo).
//
// VALOR DE SALIDA:
//
//    No devuelve nada.
//
// FUNCIONES DE LAS QUE DEPENDE:
//
//    Sleep() en Windows o usleep() en otros sistemas.
//
/////////////////////////////////////////////////////////////////////////////

void esperarMilisegundos (int milisegundos)
{
  #ifdef SO_WINDOWS
    Sleep(milisegundos);
  #else
    usleep(milisegundos*1000);   // Alternativa: nanosleep() de "time.h".
  #endif
}

/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    void pausa(void);
//
// USO:
//
//    Detiene el programa durante un momento predefinido.
//
// DETALLES:
//
//    Es un atajo que llama a pausaEstandar con unos valores fijos 
//    (1 y 2). Se usa para no tener que escribir los números a mano 
//    cada vez que queremos que el programa se pare un poco.
//
// PARÁMETROS DE ENTRADA:
//
//    Ninguno (void).
//
// VALOR DE SALIDA:
//
//    No devuelve nada.
//
// FUNCIONES DE LAS QUE DEPENDE:
//
//    pausaEstandar()
//
/////////////////////////////////////////////////////////////////////////////

void pausa (void)
{
  pausaEstandar(1, 2);
}

/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    void pausaEstandar(int nfils, int ncols);
//
// USO:
//
//    Muestra un mensaje de pausa en una posición fija de la pantalla.
//
// DETALLES:
//
//    Llama a pausaGenerica usando un mensaje ya definido (MSJxPAUSA). 
//    Se asegura de que el mensaje aparezca en la fila y columna que le 
//    digamos, y le dice al programa que no borre la pantalla (FALSE).
//
// PARÁMETROS DE ENTRADA:
//
//    nfils: La fila donde queremos que salga el mensaje.
//    ncols: La columna donde queremos que salga el mensaje.
//
// VALOR DE SALIDA:
//
//    No devuelve nada.
//
// FUNCIONES DE LAS QUE DEPENDE:
//
//    pausaGenerica()
//
/////////////////////////////////////////////////////////////////////////////

void pausaEstandar (int nfils, int ncols)
{
  pausaGenerica(MSJxPAUSA, nfils, ncols, FALSE);
}

/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    void pausaGenerica(char msjtxt[], int nfils, int ncols, boolean nuevalinea);
//
// USO:
//
//    Muestra un mensaje personalizado y espera a que el usuario pulse INTRO.
//
// DETALLES:
//
//    Es la función principal para detener el programa. Primero escribe el 
//    texto en la posición elegida y luego se queda "congelada" llamando a 
//    esperarINTRO() hasta que el usuario reaccione.
//
// PARÁMETROS DE ENTRADA:
//
//    msjtxt[]: El texto que queremos que aparezca (el mensaje).
//    nfils: La fila de la pantalla.
//    ncols: La columna de la pantalla.
//    nuevalinea: Indica si queremos saltar de línea después del mensaje.
//
// VALOR DE SALIDA:
//
//    No devuelve nada.
//
// FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje_x_y()
//    esperarINTRO()
//
/////////////////////////////////////////////////////////////////////////////

void pausaGenerica (char msjtxt[], int nfils, int ncols, boolean nuevalinea)
{
  mensaje_x_y(msjtxt, nfils, ncols, nuevalinea);

  esperarINTRO();
}

/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    void texto(char msjtxt[]);
//
// USO:
//
//    Escribe una cadena de caracteres (un mensaje) en la pantalla.
//
// DETALLES:
//
//    Es un sinónimo de la función estándar puts(). Se utiliza para que 
//    el código sea más legible para personas que no hablan inglés o 
//    que prefieren términos más descriptivos.
//
// PARÁMETROS DE ENTRADA:
//
//    msjtxt[]: El texto que queremos mostrar.
//
// VALOR DE SALIDA:
//
//    No devuelve nada.
//
// FUNCIONES DE LAS QUE DEPENDE:
//
//    puts() (de la librería estándar <stdio.h>)
//
/////////////////////////////////////////////////////////////////////////////

void texto (char msjtxt[])
{
  puts(msjtxt);
}

/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    void separar(void);
//
// USO:
//
//    Añade una línea en blanco en la consola.
//
// DETALLES:
//
//    Es una función estética. Simplemente imprime un salto de línea (\n)
//    para separar bloques de texto y que la interfaz sea más limpia.
//
// PARÁMETROS DE ENTRADA:
//
//    Ninguno.
//
// VALOR DE SALIDA:
//
//    No devuelve nada.
//
// FUNCIONES DE LAS QUE DEPENDE:
//
//    mostrar()
//
/////////////////////////////////////////////////////////////////////////////

void separar()
{
  mostrar("\n");
}

/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    void nuevaLinea(void);
//
// USO:
//
//    Baja el cursor a la línea siguiente.
//
// DETALLES:
//
//    Es un sinónimo de saltar(1). Se utiliza para que el código sea más
//    descriptivo cuando solo queremos bajar una línea y no un número 
//    variable de ellas.
//
// PARÁMETROS DE ENTRADA:
//
//    Ninguno (void).
//
// VALOR DE SALIDA:
//
//    No devuelve nada.
//
// FUNCIONES DE LAS QUE DEPENDE:
//
//    saltar()
//
/////////////////////////////////////////////////////////////////////////////

void nuevaLinea (void)
{
  saltar(1);
}

/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    void mostrar(char msjtxt[]);
//
// USO:
//
//    Muestra un mensaje en la posición actual del cursor.
//
// DETALLES:
//
//    Es una versión simplificada de mostrar_x_y(). Al usar los valores 
//    0 para filas y 0 para columnas, el texto aparece inmediatamente 
//    después de lo último que se haya escrito.
//
// PARÁMETROS DE ENTRADA:
//
//    msjtxt[]: La cadena de texto o mensaje que queremos imprimir.
//
// VALOR DE SALIDA:
//
//    No devuelve nada.
//
// FUNCIONES DE LAS QUE DEPENDE:
//
//    mostrar_x_y()
//
/////////////////////////////////////////////////////////////////////////////

void mostrar (char msjtxt[])
{
  mostrar_x_y (msjtxt, 0, 0);
}

/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    void mostrar_x_y(char msjtxt[], int nfils, int ncols);
//
// USO:
//
//    Muestra un texto en una posición específica sin avanzar a la siguiente línea.
//
// DETALLES:
//
//    Es una versión simplificada de mensaje_x_y(). Utiliza el valor 
//    FALSE para el parámetro 'nuevalinea', lo que significa que el cursor 
//    se quedará justo al final del texto impreso. Es ideal para mostrar 
//    etiquetas de datos (ej: "Nombre: ").
//
// PARÁMETROS DE ENTRADA:
//
//    msjtxt[]: El texto que queremos imprimir.
//    nfils: Cuántas filas bajar antes de escribir.
//    ncols: Cuántas columnas desplazar a la derecha antes de escribir.
//
// VALOR DE SALIDA:
//
//    No devuelve nada.
//
// FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje_x_y()
//
/////////////////////////////////////////////////////////////////////////////

void mostrar_x_y (char msjtxt[], int nfils, int ncols)
{
  mensaje_x_y (msjtxt, nfils, ncols, FALSE);
}

/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    void escribir(char msjtxt[]);
//
// USO:
//
//    Escribe un mensaje en la posición actual del cursor.
//
// DETALLES:
//
//    Es un atajo de escribir_x_y(). Al pasarle los valores 0 y 0, el texto
//    se imprime en el lugar donde se quedó el cursor tras la última 
//    operación, sin añadir saltos ni desplazamientos extra.
//
// PARÁMETROS DE ENTRADA:
//
//    msjtxt[]: La cadena de texto que queremos imprimir.
//
// VALOR DE SALIDA:
//
//    No devuelve nada.
//
// FUNCIONES DE LAS QUE DEPENDE:
//
//    escribir_x_y()
//
/////////////////////////////////////////////////////////////////////////////

void escribir (char msjtxt[])
{
  escribir_x_y (msjtxt, 0, 0);
}

/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    void escribir_x_y(char msjtxt[], int nfils, int ncols);
//
// USO:
//
//    Escribe un texto en una posición determinada sin saltar de línea.
//
// DETALLES:
//
//    Funciona exactamente igual que mostrar_x_y(). Se mantiene para ofrecer
//    flexibilidad en el lenguaje (usar "escribir" o "mostrar" según prefiera
//    el programador) y asegura que el cursor se quede al final del mensaje.
//
// PARÁMETROS DE ENTRADA:
//
//    msjtxt[]: El texto que se va a imprimir.
//    nfils: Desplazamiento vertical (filas).
//    ncols: Desplazamiento horizontal (columnas).
//
// VALOR DE SALIDA:
//
//    No devuelve nada.
//
// FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje_x_y()
//
/////////////////////////////////////////////////////////////////////////////

void escribir_x_y (char msjtxt[], int nfils, int ncols)
{
  mensaje_x_y (msjtxt, nfils, ncols, FALSE);
}

/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    void imprimir(char msjtxt[]);
//
// USO:
//
//    Muestra un texto en la posición actual donde se encuentre el cursor.
//
// DETALLES:
//
//    Es un atajo de imprimir_x_y(). Se utiliza para imprimir mensajes de 
//    forma sencilla, sin desplazamientos adicionales y manteniendo el 
//    cursor en la misma línea al terminar.
//
// PARÁMETROS DE ENTRADA:
//
//    msjtxt[]: El texto que queremos que aparezca en pantalla.
//
// VALOR DE SALIDA:
//
//    No devuelve nada.
//
// FUNCIONES DE LAS QUE DEPENDE:
//
//    imprimir_x_y()
//
/////////////////////////////////////////////////////////////////////////////

void imprimir (char msjtxt[])
{
  imprimir_x_y (msjtxt, 0, 0);
}

/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    void imprimir_x_y(char msjtxt[], int nfils, int ncols);
//
// USO:
//
//    Escribe un texto en una posición específica sin saltar a la línea siguiente.
//
// DETALLES:
//
//    Es idéntica a mostrar_x_y() y escribir_x_y(). Se asegura de que el 
//    parámetro 'nuevalinea' sea FALSE para que, tras imprimir el mensaje, 
//    el cursor se quede pegado al final del texto (muy útil para pedir 
//    datos justo después del mensaje).
//
// PARÁMETROS DE ENTRADA:
//
//    msjtxt[]: El texto a mostrar.
//    nfils: Filas de desplazamiento.
//    ncols: Columnas de desplazamiento.
//
// VALOR DE SALIDA:
//
//    No devuelve nada.
//
// FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje_x_y()
//
/////////////////////////////////////////////////////////////////////////////

void imprimir_x_y (char msjtxt[], int nfils, int ncols)
{
  mensaje_x_y (msjtxt, nfils, ncols, FALSE);
}

/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    void mensaje(char msjtxt[], int nfils, int ncols);
//
// USO:
//
//    Escribe un mensaje en una posición determinada sin saltar de línea.
//
// DETALLES:
//
//    Es una función de conveniencia que llama a mensaje_x_y(). Se diferencia
//    de las versiones anteriores en que su nombre es más genérico ("mensaje").
//    Mantiene el parámetro 'nuevalinea' como FALSE para que el cursor no
//    baje a la siguiente fila automáticamente.
//
// PARÁMETROS DE ENTRADA:
//
//    msjtxt[]: El texto que se desea mostrar.
//    nfils: El número de filas a desplazar.
//    ncols: El número de columnas a desplazar.
//
// VALOR DE SALIDA:
//
//    No devuelve nada.
//
// FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje_x_y()
//
/////////////////////////////////////////////////////////////////////////////

void mensaje (char msjtxt[], int nfils, int ncols)
{
  mensaje_x_y (msjtxt, nfils, ncols, FALSE);
}

/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    void mensaje_x_y(char msjtxt[], int nfils, int ncols, boolean nuevalinea);
//
// USO:
//    Control total sobre la impresión: posición (filas/columnas) y salto de línea.
//
// DETALLES:
//    Es la función base que utilizan todas las demás (mostrar, escribir, etc.).
//    Primero mueve el cursor verticalmente (saltar) y horizontalmente (tabular),
//    luego imprime el texto y, finalmente, decide si añade un salto de línea
//    según el valor lógico de 'nuevalinea'.
//
// PARÁMETROS DE ENTRADA:
//    msjtxt[]:   El mensaje a mostrar.
//    nfils:      Cuántas líneas bajar antes de escribir.
//    ncols:      Cuántos espacios (tabulaciones) mover a la derecha.
//    nuevalinea: Si es TRUE, salta a la siguiente línea tras el mensaje.
//                Si es FALSE, el cursor se queda al final del texto.
//
// VALOR DE SALIDA:
//    No devuelve nada.
//
// FUNCIONES DE LAS QUE DEPENDE:
//    saltar(), tabular(), printf()
//
/////////////////////////////////////////////////////////////////////////////

void mensaje_x_y (char msjtxt[], int nfils, int ncols, boolean nuevalinea)
{
  saltar(nfils);
  tabular(ncols);
  printf("%s", msjtxt);
  
  if (nuevalinea)   printf("\n");   // ALTERNATIVA: if (nuevalinea)   putchar(ENTER);
}

/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    void iniciaAleatorizador(void);
//
// USO:
//
//    Prepara el ordenador para generar números al azar diferentes cada vez.
//
// DETALLES:
//
//    Si no usas esta función, el ordenador siempre dará los mismos números 
//    "aleatorios" cada vez que abras el programa. Al usar time(NULL), 
//    usamos la hora actual como "semilla", asegurando que cada partida 
//    sea distinta.
//
// PARÁMETROS DE ENTRADA:
//
//    Ninguno (void).
//
// VALOR DE SALIDA:
//
//    No devuelve nada.
//
// FUNCIONES DE LAS QUE DEPENDE:
//
//    srand() (de <stdlib.h>) y time() (de <time.h>).
//
/////////////////////////////////////////////////////////////////////////////

void iniciaAleatorizador (void)
{
  srand(time(NULL));
}

/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    int generaAleatorioEntero(int limite);
//
// USO:
//
//    Obtiene un número entero al azar entre 0 y el límite indicado.
//
// DETALLES:
//
//    Utiliza el operador de módulo (%) para "cortar" el número que da el
//    ordenador y que siempre caiga dentro del rango que queremos. 
//    Es importante recordar que el número devuelto será como máximo 
//    'limite - 1'.
//
// PARÁMETROS DE ENTRADA:
//
//    limite: El tope superior del rango (no incluido).
//
// VALOR DE SALIDA:
//    
//    Devuelve el número aleatorio generado.
//
// FUNCIONES DE LAS QUE DEPENDE:
//
//    rand() (de <stdlib.h>).
//
/////////////////////////////////////////////////////////////////////////////

int generaAleatorioEntero (int limite)
{
  // Generará un número entre 0 y limite - 1, nunca llega a limite.
  return (rand() % limite);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int obtenerEntero (void);
//
//  USO:
//
//    Sustitución mejorada de scanf() que impide que queden letras almacenadas
//    en el buffer de teclado para posteriores operaciones de entrada de datos.
//
//  DETALLES:
//
//    La función scanf() no retira el código ASCII de la letra INTRO del buffer
//    de teclado ni posibles letras después de un texto que se pueda convertir
//    en una cantidad. Nos ayudamos de otra función creada en esta librería,
//    vaciarBuffer() para ello. No muestra ningún mensaje por pantalla.
//
// PARÁMETROS DE ENTRADA:
//
//    Ninguno
//
//
//  VALOR DE SALIDA:
//
//    Devuelve al exterior el valor entero que a su vez ha recibido en la
//    variable "valor" de la función scanf(), mediante paso por referencia.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    scanf()
//
//      Es el programa estándar ("prefabricado") que hace la logística de
//      leer caracteres del teclado y convertirlos en la cantidad entera.
//
////////////////////////////////////////////////////////////////////////////////

int obtenerEntero (void)
{
  int valor;
  
  scanf("%d", &valor);
  vaciarBuffer();

  return valor;
}

/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    char obtenerCaracterASCII(void);
//
// USO:
//
//    Captura un carácter o símbolo desde el teclado.
//
// DETALLES:
//
//    Es un sinónimo de obtenerLetra(). Se utiliza para dejar claro en el 
//    código que lo que nos interesa es el valor del carácter según la 
//    tabla ASCII, sea una letra, un número o un signo de puntuación.
//
// PARÁMETROS DE ENTRADA:
//
//    Ninguno.
//
// VALOR DE SALIDA:
//
//    Devuelve el carácter (char) que el usuario haya pulsado.
//
// FUNCIONES DE LAS QUE DEPENDE:
//
//    obtenerLetra()
//
/////////////////////////////////////////////////////////////////////////////

char obtenerCaracterASCII()
{
  return obtenerLetra();
}

Esta es una función de entrada de datos muy robusta. Su objetivo no es solo capturar una tecla, sino asegurarse de que lo que el usuario escribe sea un carácter estándar y, lo más importante, mantener el "buffer" (la memoria temporal del teclado) limpio para que el programa no se vuelva loco en la siguiente pregunta.

Código y Documentación en C
C
/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    char obtenerLetra(void);
//
// USO:
//
//    Captura un carácter del teclado y limpia el buffer de entrada.
//
// DETALLES:
//
//    1. Lee un carácter con getchar().
//    2. Filtra que sea ASCII estándar (menor que 128). Si es un carácter
//       especial extraño, devuelve el carácter nulo '\0'.
//    3. Si el usuario escribió varias letras o pulsó INTRO, llama a 
//       vaciarBuffer() para eliminar los restos y que no afecten a la 
//       siguiente lectura.
//
// PARÁMETROS DE ENTRADA:
//
//    Ninguno (void).
//
// VALOR DE SALIDA:
//
//    La letra capturada (si es válida) o '\0' (si no lo es).
//
// FUNCIONES DE LAS QUE DEPENDE:
//
//    getchar() (de <stdio.h>), vaciarBuffer()
//
/////////////////////////////////////////////////////////////////////////////

char obtenerLetra (void)   // Sólo ASCII VÁLIDO.
{
  char letra, valida;
  
  letra = getchar();
  
  if (letra < 128)
    valida = letra; // Devolveremos la letra
  else
    valida = '\0';  // Devolveremos la letra nula.
  
  // VACIAMOS POSIBLES CÓDIGOS EN EL BUFFER.
  //   Se incluye el INTRO EXTRA y una posible escritura de múltiples letras.
  if (letra != ENTER)   vaciarBuffer();

  return valida;
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirEntero (char msjtxt[], int ncols);
//
//  USO:
//
//    Muestra un mensaje en pantalla para pedir un dato entero al usuario. El
//    mensaje es configurable y desplazable un número de caracteres desde la
//    izquierda de la pantalla.
//
//  DETALLES:
//
//    Es como un printf() más un scanf(), mejorados. Puede desplazarse el texto
//    recibido mediante un segundo dato entero. También impide problemas del
//    buffer de teclado con scanf(). Para ello, delega el emitir el mensaje por
//    pantalla a las funciones msj() y mostrar(), y la toma del dato entero a la
//    función obtenerEntero().
//
//  PARÁMETROS DE ENTRADA:
//
//    mensaje
//
//      Variable de tipo vector de caracteres donde se recibirá el texto que se
//      debe mostrar, que debe ser una cadena terminada en '\0'.
//
//    tabs
//
//      Variable entera donde se recibirá del exterior el número de espacios en
//      blanco a añadir antes del mensaje.
//
//  VALOR DE SALIDA:
//
//    Devuelve al programa donde se invoque, un valor entero que a su vez esta
//    función ha recibido desde la función obtenerEntero().
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    msj()
//
//      Se encarga efectivamente de mostrar el mensaje.
//
//    mostrar()
//
//      Usada para añadir en pantalla un texto adicional después del mensaje.
//
//    obtenerEntero()
//
//      Es la función que se encarga en la práctica de obtener la cantidad.
//
////////////////////////////////////////////////////////////////////////////////

int pedirEntero (char msjtxt[], int ncols)
{
  mensaje(msjtxt, 0, ncols);
  mostrar(": ");
  
  return obtenerEntero();
}

/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    int pedirEnteroPositivo(char msjtxt[], int ncols, boolean mostrarerror);
//
// USO:
//
//    Pide un número al usuario y no le deja avanzar hasta que sea 0 o mayor.
//
// DETALLES:
//
//    Es como un guardia de seguridad. Muestra tu mensaje, lee lo que el 
//    usuario escribe y chequea si es un número negativo. Si el usuario 
//    se equivoca y pone algo como "-5", la función muestra un aviso de 
//    error y le vuelve a preguntar otra vez, en un bucle infinito hasta 
//    que ponga un número válido.
//
// PARÁMETROS DE ENTRADA:
//
//    msjtxt[]: El texto de la pregunta (ej: "Dime tu edad").
//    ncols: Cuántas columnas de espacio dejar a la izquierda.
//    mostrarerror: Si es TRUE, avisa al usuario cuando se equivoca. 
//                  Si es FALSE, simplemente repite la pregunta en silencio.
//
// VALOR DE SALIDA:
//
//    Devuelve el número entero (ya verificado como positivo) que puso el usuario.
//
// FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje(), mostrar(), obtenerEntero(), nuevaLinea(), mensaje_x_y()
//
/////////////////////////////////////////////////////////////////////////////

int pedirEnteroPositivo (char msjtxt[], int ncols, boolean mostrarerror)
{
  int num;
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    mostrar(": ");
    num = obtenerEntero();
    
    if (mostrarerror)
    {
      if (num < 0)
      {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
    
  } while (num < 0);
  
  return num;
}

/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    int pedirEnteroIntervalo(char msjtxt[], int ncols, boolean mostrarerror, int min, int max);
//
// USO:
//
//    Pide un número y obliga al usuario a que esté entre un mínimo y un máximo.
//
// DETALLES:
//
//    Es la función de validación más completa. Muestra el mensaje y, entre 
//    corchetes, informa al usuario del rango permitido [min, max]. Si el 
//    usuario mete un número fuera de ese "intervalo" (por ejemplo, un 20 
//    cuando el máximo es 10), la función da un error y le obliga a repetir.
//
// PARÁMETROS DE ENTRADA:
//
//    msjtxt[]: El texto de la pregunta.
//    ncols: Espacios de margen a la izquierda.
//    mostrarerror: Si es TRUE, imprime "ERROR" si el número no vale.
//    min: El número más pequeño permitido.
//    max: El número más grande permitido.
//
// VALOR DE SALIDA:
//
//    Devuelve el número ya comprobado y dentro del rango.
//
// FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje(), obtenerEntero(), nuevaLinea(), mensaje_x_y()
//
/////////////////////////////////////////////////////////////////////////////

int pedirEnteroIntervalo (char msjtxt[], int ncols, boolean mostrarerror, int min, int max)
{
  int num;
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    printf(" [%d,%d]: ", min, max);
    
    num = obtenerEntero();
    
    if (mostrarerror)
    {
      if (num < min || num > max)
      {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
    
  } while (num < min || num > max);
  
  return num;
}

/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    int pedirLetra(char msjtxt[], int ncols, boolean mostrarerror, char letra);
//
// USO:
//
//    Obliga al usuario a pulsar una letra específica para poder avanzar.
//
// DETALLES:
//
//    Esta función es muy útil para confirmaciones. Convierte tanto la letra 
//    que tú quieres como la que el usuario escribe a MAYÚSCULAS (gracias a 
//    toupper). Así, si pides una 'S', no importa si el usuario pulsa 's' 
//    minúscula o 'S' mayúscula; ambas se aceptarán como válidas. Si pulsa 
//    cualquier otra, se mostrará un error y se repetirá la pregunta.
//
// PARÁMETROS DE ENTRADA:
//
//    msjtxt[]: El mensaje que se muestra (ej: "¿Deseas salir? Pulse S").
//    ncols: Espacio de margen a la izquierda.
//    mostrarerror: Si es TRUE, avisa con un mensaje de "ERROR" si falla.
//    letra: La letra exacta que el usuario debe pulsar.
//
// VALOR DE SALIDA:
//
//    Devuelve la letra que el usuario pulsó (ya convertida a mayúsculas).
//
// FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje(), mostrar(), obtenerLetra(), toupper(), nuevaLinea(), mensaje_x_y()
//
/////////////////////////////////////////////////////////////////////////////

int pedirLetra (char msjtxt[], int ncols, boolean mostrarerror, char letra)
{
  char pedida;
  
  letra = toupper(letra);
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    mostrar(": ");
    
    pedida = obtenerLetra();
    pedida = toupper(pedida);   // Convertimos a mayúsculas para simplificar casos.
    
    if (mostrarerror)
    {
      if (letra != pedida)
      {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
    
  } while (letra != pedida);
  
  return pedida;
}

/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    int pedirConfirmacion(char msjtxt[], int ncols, boolean mostrarerror);
//
// USO:
//
//    Obliga al usuario a responder con un "SÍ" o un "NO" para continuar.
//
// DETALLES:
//
//    Esta función es ideal para decisiones críticas (como borrar un archivo 
//    o salir del juego). Utiliza dos constantes (SI y NO) para mostrar las 
//    opciones entre corchetes. Si el usuario pulsa cualquier otra tecla, 
//    la función considera que es un error, le avisa y le obliga a elegir 
//    una de las dos opciones válidas.
//
// PARÁMETROS DE ENTRADA:
//
//    msjtxt[]: El mensaje de pregunta (ej: "¿Deseas borrar la partida?").
//    ncols: Espacio de margen a la izquierda.
//    mostrarerror: Si es TRUE, muestra un aviso de "ERROR" al fallar.
//
// VALOR DE SALIDA:
//
//    Devuelve la letra que eligió el usuario (ya sea la constante SI o NO).
//
// FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje(), obtenerLetra(), toupper(), nuevaLinea(), mensaje_x_y()
//
/////////////////////////////////////////////////////////////////////////////

int pedirConfirmacion (char msjtxt[], int ncols, boolean mostrarerror)
{
  char letra;
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    printf(" [%c/%c]: ", SI, NO);
    
    letra = obtenerLetra();
    letra = toupper(letra);   // Convertimos a mayúsculas para simplificar casos.
    
    if (mostrarerror)
    {
      if (letra != SI && letra != NO)
      {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
    
  } while (letra != SI && letra != NO);
  
  return letra;
}

/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    boolean validarLetraUnica(char original, char dada, boolean sensibleamayusculas);
//
// USO:
//    Compara dos letras y devuelve TRUE si son iguales.
//
// DETALLES:
//    Permite elegir si la comparación ignora las mayúsculas (usando FALSE).
//    Si no es sensible, convierte ambas letras a mayúsculas antes de comparar.
//
// PARÁMETROS:
//    original: Letra de referencia.
//    dada: Letra a comprobar.
//    sensibleamayusculas: TRUE (estricto) / FALSE (ignora mayúsculas/minúsculas).
//
// RETORNO:
//    TRUE si coinciden, FALSE si no.
//
/////////////////////////////////////////////////////////////////////////////

boolean validarLetraUnica (char original, char dada, boolean sensibleamayusculas)
{
  if (!sensibleamayusculas)
  {
    original = toupper(original);
      dada   = toupper(dada);
  }
  
  return (original == dada);
}

/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    boolean validarLetraConjunto(char letra, char seleccion[], boolean sensibleamayusculas);
//
// USO:
//    Comprueba si una letra pertenece a un grupo de letras aceptables.
//
// DETALLES:
//    Recorre una lista (string) buscando la letra. Si la encuentra, devuelve TRUE.
//    Permite decidir si importa la diferencia entre mayúsculas y minúsculas.
//
// PARÁMETROS:
//    letra: La letra que queremos verificar.
//    seleccion[]: La lista de letras válidas (ej: "aeiou" para vocales).
//    sensibleamayusculas: TRUE (estricto) / FALSE (ignora mayúsculas).
//
// RETORNO:
//    TRUE si la letra está en la lista, FALSE si no está.
//
/////////////////////////////////////////////////////////////////////////////

boolean validarLetraConjunto (char letra, char seleccion[], boolean sensibleamayusculas)
{
  boolean resultado = FALSE;
  int largo = strlen(seleccion);
  
  for(int i = 0; i < largo ; i++)
  {
    if (validarLetraUnica(letra, seleccion[i], sensibleamayusculas))
    {
      resultado = TRUE;
      break;
    }
  }
  
  return resultado;
}

/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    char *cadenaOpcionesDisponibles(char entrada[]);
//
// USO:
//    Convierte un grupo de letras en una lista separada por barras (ej: "ABC" -> "A/B/C").
//
// DETALLES:
//    Reserva memoria dinámica (malloc) para crear una nueva cadena de texto.
//    Recorre la entrada insertando una '/' entre cada carácter y finaliza
//    correctamente la cadena con '\0'. Si la entrada es NULL o vacía, lo gestiona.
//
// PARÁMETROS:
//    entrada[]: Las letras que quieres formatear.
//
// RETORNO:
//    Un puntero a la nueva cadena formateada. 
//    
//
/////////////////////////////////////////////////////////////////////////////

char *cadenaOpcionesDisponibles (char entrada[])
{
  if (entrada == NULL) return NULL;   // Si no dan nada, petas máximus ...
  
  char *textoinicial, *textofinal;
  
  textoinicial = entrada;
  
  int largoinicial, largofinal;
  
  largoinicial = strlen(textoinicial);

  if (largoinicial == 0)
  {
    // Nos dan cadena vacía, así que generamos vacía. Pero consideramos el '\0'.
    largofinal = 1;
    textofinal = (char *) malloc(1*sizeof(char));
    textofinal[0] = '\0';
  }
  else
  {
    // CASO 1: "A" -> "A" => largo 2 = 1 (letra) + 1 ('\0')
    // CASO 2: "ABC" -> "A/B/C" => largo 6 = 3 (letras) + 2 (sepadores) +1 ('\0'); 
    largofinal = 2 * largoinicial;
    textofinal = (char *) malloc(largofinal*sizeof(char));
    
    if (textofinal != NULL)
    {
      int j = 0;
      for (int i = 0; i < largoinicial; i++, j++)
      {
        textofinal[j] = textoinicial[i];
        j++;
        textofinal[j] = '/';
      }
      
      // Sustituimos la última '/' por un ' 0'.
      j--;
      textofinal[j] = '\0';
    }
  }

  return textofinal;
}

/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    int pedirLetraSeleccion(char msjtxt[], int ncols, boolean mostrarerror, 
//                            char seleccion[], boolean sensibleamayusculas);
//
// USO:
//    Muestra un mensaje con varias opciones y obliga a elegir una de ellas.
//
// DETALLES:
//    Crea visualmente la lista de opciones (ej: [A/B/C]) usando memoria 
//    dinámica. Comprueba si la tecla pulsada está en el grupo permitido y, 
//    al terminar, libera la memoria usada y devuelve la letra validada.
//
// PARÁMETROS:
//    msjtxt[]: El texto de la pregunta.
//    ncols: Margen izquierdo.
//    mostrarerror: TRUE para avisar si el usuario falla.
//    seleccion[]: Letras válidas juntas (ej: "WASD").
//    sensibleamayusculas: Si importa distinguir 'a' de 'A'.
//
// RETORNO:
//    La letra elegida (en mayúsculas si no es sensible).
//
/////////////////////////////////////////////////////////////////////////////

int pedirLetraSeleccion (char msjtxt[], int ncols, boolean mostrarerror, char seleccion[], boolean sensibleamayusculas)
{
  // HACER: Evitar que falle con «seleccion» a valor NULL.
  
  // Usar «cadenaOpcionesDisponibles()» implica luego liberar memoria con «free()».
  char *editada = cadenaOpcionesDisponibles(seleccion);
  
  char letra;
  
  boolean validada;
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    mostrar(" [");
    printf("%s", editada);
    mostrar("]: ");
    
    letra = obtenerLetra();

    validada = validarLetraConjunto(letra, seleccion, sensibleamayusculas);
    
    if (mostrarerror)
    {
      if (!validada)
      {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
  } while (!validada);
  
  // Liberamos la memoria para cadena modificada.
  free(editada);
  
  // Si no era sensible a mayúsculas, siempre la devolvemos mayúscula.
  if (!sensibleamayusculas)   letra = toupper(letra);
  
  return letra;
}



#ifdef SO_WINDOWS

#include <conio.h>

/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    char obtenerTeclaInteractiva(void);
//
// USO:
//    Captura una tecla al instante, incluyendo flechas de dirección.
//
// DETALLES:
//    Usa _getch() para leer sin esperar al Enter. Si detecta un código de 
//    "tecla especial" (0 o 224), realiza una segunda lectura para saber 
//    qué flecha es. También normaliza teclas como Enter o Retroceso para 
//    que el resto del programa las entienda fácilmente.
//
// PARÁMETROS:
//    Ninguno.
//
// RETORNO:
//    El carácter de la tecla pulsada o una constante (ARRIBA, ABAJO, etc.).
//
/////////////////////////////////////////////////////////////////////////////

char obtenerTeclaInteractiva(void)
{
  int caracter = _getch();   // En Windows, getch() ya es bloqueante por defecto.

  if (caracter == 0 || caracter == 224)
  {
    // Tecla especial, depende de un segundo código. Lo leemos.
    caracter = _getch();
    
    switch(caracter)
    {
      case 72: caracter = TECLA_ARRIBA;    break;   // Flecha Arriba
      case 80: caracter = TECLA_ABAJO;     break;   // Flecha Abajo
      case 75: caracter = TECLA_IZQUIERDA; break;   // Flecha Izquierda
      case 77: caracter = TECLA_DERECHA;   break;   // Flecha Derecha
      default: caracter = TECLA_NULA;               // Tecla nula.
    }
    else
    {
      // Normalización de teclas conflictivas no estándar.
      switch(caracter)
      {
        case 13: caracter = TECLA_ENTER;
        case 8:  caracter = TECLA_RETROCESO;
      }
    }
    
    return (char)caracter;
}

#else

#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

/////////////////////////////////////////////////////////////////////////////
//
// FUNCIÓN:
//
//    int obtenerTeclaInteractiva(void);
//
// USO:
//    Captura teclas al instante (sin pulsar ENTER) en sistemas Linux/Unix.
//
// DETALLES:
//    Modifica temporalmente la terminal para desactivar el "modo canónico" 
//    (que espera al ENTER) y el "eco" (que muestra lo que escribes). 
//    Gestiona secuencias de escape complejas para traducir las flechas 
//    del teclado ('A', 'B', 'C', 'D') en comandos que el programa entienda.
//
// PARÁMETROS:
//    Ninguno.
//
// RETORNO:
//    El código de la tecla pulsada (Normal o Especial).
//
/////////////////////////////////////////////////////////////////////////////

int obtenerTeclaInteractiva(void)
{
  struct termios terminaloriginal, terminalnueva;
  int caracter;

  // 1. Obtenemos la configuración actual de la terminal.
  tcgetattr(STDIN_FILENO, &terminaloriginal);
  terminalnueva = terminaloriginal;

  // 2. Desactivamos el modo canónico (espera de INTRO) y el ECO (ver la tecla al pulsar).
  terminalnueva.c_lflag &= ~(ICANON | ECHO); // Quitamos espera de INTRO y eco
  tcsetattr(STDIN_FILENO, TCSANOW, &terminalnueva);
  
  // 3. El programa se detiene aquí hasta recibir un carácter.
  // Las flechas envían una secuencia de escape: 27 (ESC), 91 ('['), y una letra.
  caracter = getchar();
  
  if (caracter == ESCAPE)
  {
    // Cambiamos a NO BLOQUEANTE un instante para ver si hay bytes extra
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
    
    // Pedimos a ver si hay otro caracter.
    int siguiente = getchar();
    
    // ¿Es '[' (91)?
    if (siguiente == '[')
    {
      // Lo desechamos simplemente no usando "siguiente".

      // Pedimos el tercer código de caracter generado.
      caracter = getchar();
      
      while ((siguiente = getchar()) != EOF && siguiente != -1);

      switch(caracter)
      {
        case 'A': caracter = TECLA_ARRIBA;    break;   // Flecha Arriba
        case 'B': caracter = TECLA_ABAJO;     break;   // Flecha Abajo
        case 'D': caracter = TECLA_IZQUIERDA; break;   // Flecha Izquierda
        case 'C': caracter = TECLA_DERECHA;   break;   // Flecha Derecha
        default:  caracter = TECLA_NULA;      break;
      }
    }
    else
    {
      if (siguiente == EOF || siguiente == -1)
      {
        // Era sólo la tecla ESCAPE.
        caracter = TECLA_ESCAPE;
      }
      else
      {
        // Era una secuencia no contemplada.
        caracter = TECLA_NULA;
      }
    }

    // Restauramos el modo BLOQUEANTE de la terminal.
    fcntl(STDIN_FILENO, F_SETFL, flags);
  }

  // 4. Restauramos la configuración original antes de salir.
  tcsetattr(STDIN_FILENO, TCSANOW, &terminaloriginal);
  
  return caracter;
}

#endif

# Práctica 2 - Programar un simulador de una Máquina de Turing

#### Asignatura: Complejidad Computacional
#### Autora: Vanessa Valentina Villalba Pérez alu0101265704@ull.edu.es
### Implementación realizada: Máquina de Turing con cinta infinita en ambas direcciones y con movimientos L,R y S

## Objetivo de la entrega
* El objetivo de la práctica consiste en programar un simulador de una Máquina de
Turing, realizando un diseño orientado a objetos.

## Ejecución del programa
* Para poder ejecutar el programa se ha de ejecutar el siguiente comando:
  
```
make run
```
* Seguidamente, el programa le pedirá que introduzca el path correspondiente al fichero con la definición formal de la máquina de Turing a utilizar. Por ejemplo: [input/MT1.txt](input/MT1.txt)
* Luego, se deberá introducir la cadena de entrada para la/las cintas de la MT. Por ejemplo: aab
* Se mostrará por consola el estado de la/las cintas en cada iteración y, si la cadena fue aceptada o no, así como el estado de la/las cintas al finalizar la ejecución. Adicionalmente, le preguntará si desea repetir la ejecución. 

## Limpieza tras la compilación
```
make clean
```

## Estructura de ficheros
```
.
├── include
│   ├── Alphabet.h
│   ├── State.h
│   ├── Symbol.h
│   ├── Tape.h
│   ├── Transition.h
│   └── TuringMachine.h
├── input
│   ├── Ejemplo_MT.txt
│   ├── MT1.txt
│   └── MT2.txt
├── LICENSE
├── Makefile
├── obj
├── Practica2_2021.pdf
├── README.md
└── src
    ├── Alphabet.cc
    ├── Main.cc
    ├── State.cc
    ├── Symbol.cc
    ├── Tape.cc
    ├── Transition.cc
    └── TuringMachine.cc
```

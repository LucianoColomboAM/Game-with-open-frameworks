#pragma once
#include "ofMain.h"
//CLASES DEL SNAKE
#include "ofSnake.h"
#include "ofFood.h"



//CLASES DEL FB
#include "bird.hpp"
#include "pipes.hpp"
#include <vector>

class ofApp : public ofBaseApp {


public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);


	void Situaciones();
	void botones(int x, int y);
	void Fechas();
	void HUD();
	void Perdiste();

	int mouseX;
	int mouseY;


	int EstadoDelJuego = 0;
	int situacion;
	float dadoSIT;
	float dadoSITN;
	float dadoMJ;
	int dado;
	int tiempo = 1;
	bool loop = true;

	//int puntos=1;
	//stats
	int kp;
	int nivel = 1;
	int gasto = 50;
	int paga = 5;
	int dinero = 100;
	int felicidad = 100;
	int cansancio = 20;
	int dia = 21, mes = 1, año = 2022;
	bool embarazo = false;
	bool manorota = false;
	
	string mensaje1	= "Segui trabajando.";
	string mensaje2 = "Estamos perdiendo plata.";
	string mensaje3 = "Concentrate en el laburo";
	string mensaje4 = "Deja el telefono.";
	string mensaje5 = "Dale que no tenemos todo el dia.";
	string mensaje6 = "No te distraigas.";
	string mensaje7 = "Mira que la jornada pasa volando";
	string mensaje8 = "La plata no descansa.";
	string mensaje9 = "Tenes que ser mas eficiente.";
	string mensaje10 = "Dale que te queda poco tiempo.";


	ofSoundPlayer Sound1;
	ofSoundPlayer Sound2;
	ofSoundPlayer Sound3;
	ofSoundPlayer Sound4;
	ofTrueTypeFont textos;
	ofTrueTypeFont fuente;
	ofImage logo;
	ofImage boton;
	ofImage celular;
	ofImage fondo;
	ofImage fondo1;
	ofImage HUDf;
	ofImage mensaje;
	string texto;
	string textoSituacion;

	
// COSAS DEL SNAKE 		
	ofSnake mySnake{};
	ofFood myFood{};

	// Variables enteras para guardar los valores.
	int vidas;
	int puntos;

	// Creamos un objeto del tipo fuente.
	ofTrueTypeFont fuentePixel;

// COSAS DEL FLAPPY BIRD

	void setupFB();
	void updateFB();
	void drawFB();
	void KPFB();


	enum GameState {
		IN_PROGRESS,
		PAUSED,
		FINISHED
	};



	//GameState
	GameState current_state = PAUSED;

	//Constants
	const int gravity_value = 2;
	const int speed = 29;
	const int spawn_time = 30;

	//Counters
	int wall_moveSpeed = 5;
	int number_of_pipes = 1;
	int spawn_timer = 0;

	//Functions
	void drawBird();
	void drawPipes();
	void resetVars();
	void addInitialPole();

	//Game Objects
	bird flappy;
	ofImage pipes1;
	ofImage fp;


	//Vectos.
	std::vector<pipes> pipes_vector;
	
	


		
};

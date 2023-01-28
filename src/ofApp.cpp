#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetWindowShape(1600, 1200);
	ofSetWindowTitle("Explotado");
	//ofToggleFullscreen();
	//ofHideCursor();
//	fondo.load("fondo.png");
	logo.load("logo2.png");
	textos.load("handwriting.ttf", 40);
	fuente.load("arial.ttf",10);
	//SetupHA();
	setupFB();
	pipes1.load("pipes.png");
	fp.load("fp.png");
	//ofSetFrameRate(120);
	Sound1.load("ambiente.wav");
	Sound2.load("grapa.wav");
	Sound3.load("dollar.wav");
	Sound4.load("ticket.wav");
	Sound1.play();
	Sound1.setLoop(loop);
}

//--------------------------------------------------------------
void ofApp::update(){
	
	//if (EstadoDelJuego == 2 && dadoMJ >= 0 && dadoMJ < 1) {UpdateHA(); }
	if (EstadoDelJuego == 2 && dadoMJ >= 1 && dadoMJ < 2) { updateFB(); }
	if (EstadoDelJuego == 2 && dadoMJ >= 2 && dadoMJ < 3) {}
	 
}

//--------------------------------------------------------------
void ofApp::draw(){
			switch (EstadoDelJuego) 
			{	
			case 1:
	
				fondo.load("fondococina.png");
				fondo.draw(0, 0, ofGetWidth(), ofGetHeight());
				HUD();
				Situaciones();
			

				if (dadoSIT== -1.0)
				{
				
				boton.load("botonlaburar.png");
				boton.draw(ofGetWidth()/2-boton.getWidth()/2, ofGetHeight()-200);
					if (EstadoDelJuego == 1 && kp == OF_KEY_UP)
					{
						
						Sound2.play();
						EstadoDelJuego = 2;
						dadoSIT = ofRandom(0.0, 17.0);
						dadoMJ = ofRandom(1.0, 3.0);
						//dadoMJ = 2;
						puntos = 0;
						vidas = 3;
						resetVars();
						addInitialPole();
						ofResetElapsedTimeCounter();
						kp = ' ';
						
					} 
				}
				break;

			case 2:
				tiempo = ofGetElapsedTimef();
				//Sound1.setVolume(12.0f);
				//cout << tiempo;

				
				if (EstadoDelJuego == 2 && dadoMJ >= 1 && dadoMJ < 2) {
					
					drawFB(); 
				}
				if (EstadoDelJuego == 2 && dadoMJ >= 2 && dadoMJ <= 3) {
					fondo.load("fondosn.jpeg");
					fondo.draw(0, 0, ofGetWidth(), ofGetHeight());
					mySnake.drawSnake();
					myFood.drawFood();
					if (mySnake.eat(myFood.myPos)) {
						myFood.pickLocation();
						puntos = puntos + 1;
						Sound3.play();
					}
				}

				if (tiempo % 3 == 0) {
					dado = ofRandom(0, 21);
				}

				if (dado == 1) {
					mensaje.load("mensaje.png");
					mensaje.draw(0, 0, ofGetWidth(), ofGetHeight());
					ofSetColor(0);
					fuente.drawString(mensaje1, 100, 50);
					ofSetColor(255);
					
				}

				if (dado == 2) {
					mensaje.load("mensaje.png");
					mensaje.draw(0, 0, ofGetWidth(), ofGetHeight());
					ofSetColor(0);
					fuente.drawString(mensaje2, 100, 50);
					ofSetColor(255);
				}
				if (dado == 3) {
					mensaje.load("mensaje.png");
					mensaje.draw(0, 0, ofGetWidth(), ofGetHeight());
					ofSetColor(0);
					fuente.drawString(mensaje3, 100, 50);
					ofSetColor(255);
				}
				if (dado == 4) {
					mensaje.load("mensaje.png");
					mensaje.draw(0, 0, ofGetWidth(), ofGetHeight());
					ofSetColor(0);
					fuente.drawString(mensaje4, 100 , 50);
					ofSetColor(255);
				}
				if (dado == 5) {
					mensaje.load("mensaje.png");
					mensaje.draw(0, 0, ofGetWidth(), ofGetHeight());
					ofSetColor(0);
					fuente.drawString(mensaje5, 100 , 50);
					ofSetColor(255);
				}
				if (dado == 6) {
					mensaje.load("mensaje.png");
					mensaje.draw(0, 0, ofGetWidth(), ofGetHeight());
					ofSetColor(0);
					fuente.drawString(mensaje6, 100 , 50);
					ofSetColor(255);
				}
				if (dado == 7) {
					mensaje.load("mensaje.png");
					mensaje.draw(0, 0, ofGetWidth(), ofGetHeight());
					ofSetColor(0);
					fuente.drawString(mensaje7, 100 , 50);
					ofSetColor(255);
				}
				if (dado == 8) {
					mensaje.load("mensaje.png");
					mensaje.draw(0, 0, ofGetWidth(), ofGetHeight());
					ofSetColor(0);
					fuente.drawString(mensaje8, 100, 50);
					ofSetColor(255);
				}
				if (dado == 9) {
					mensaje.load("mensaje.png");
					mensaje.draw(0, 0, ofGetWidth(), ofGetHeight());
					ofSetColor(0);
					fuente.drawString(mensaje9, 100 , 50);
					ofSetColor(255);
				}
				if (dado == 10) {
					mensaje.load("mensaje.png");
					mensaje.draw(0, 0, ofGetWidth(), ofGetHeight());
					ofSetColor(0);
					fuente.drawString(mensaje10, 100, 50);
					ofSetColor(255);
				}

				
				if (tiempo %15==0 && tiempo > 0 && dadoMJ >= 0 && dadoMJ < 1 || vidas <=-1) {
					dinero = dinero + (puntos * paga);
					EstadoDelJuego = 3;
					dadoSITN = ofRandom(0.0, 1.0);
					dadoSIT = ofRandom(0.0, 17.0);
					Sound1.setVolume(1.0f);
					kp = ' ';
				}

				if (tiempo % 15 == 0 && tiempo > 0 && dadoMJ >= 2 && dadoMJ < 3) {
					dinero = dinero + (puntos * paga);
					cout << dinero;
					EstadoDelJuego = 3;
					dadoSITN = ofRandom(0.0, 1.0);
					dadoSIT = ofRandom(0.0, 17.0);
					Sound1.setVolume(1.0f);
					kp = ' ';
				}
			//
				if (tiempo % 15 == 0 && tiempo > 0 && dadoMJ >= 1 && dadoMJ < 2 || current_state== FINISHED && dadoMJ >= 1 && dadoMJ < 2)
				{
					EstadoDelJuego = 3;
					dadoSITN = ofRandom(0.0, 1.0); 
					dadoSIT = ofRandom(0.0, 17.0);
					kp = ' ';
				}
				break;

			case 3:
				//ACA DEBERIA PREGUNTARSE SI SE HACEN HORAS EXTRAS, ALGUNAS SITUACIONES POST TRABAJO, Y VOLVER A EstadoDelJuego 1 O 2
				//Fechas(dia,mes,año);

				fondo.load("fondocamino1.png");
				fondo.draw(0, 0, ofGetWidth(), ofGetHeight());
				Fechas();
				HUD();


			   
				fuente.drawString("Recuerda que al final de cada dia se restara tu dinero menos tu gasto, si tu dinero es menor a 0 perderas", 10, ofGetHeight()-10);
		
				
				
				if (dadoSITN >= 0.9) 
				{

					boton.load("horasextra.png");
					boton.draw(0, 0,ofGetWidth(),ofGetHeight());

					if (paga == 0) paga <= 1;
					if (EstadoDelJuego == 3 && kp == OF_KEY_UP)
					{
						Sound2.play();
						EstadoDelJuego = 1;
						dinero = dinero - gasto;
						dia++;
						dadoSIT = ofRandom(0.0, 17.0);
						kp = ' ';
						if (dinero < 0) {
							EstadoDelJuego = 4;
						}
						else {
							EstadoDelJuego = 1;
						}
					}
					
					if (EstadoDelJuego == 3 && kp == OF_KEY_DOWN)
					{
						Sound2.play();
						EstadoDelJuego = 2;
						dadoSIT = ofRandom(0.0, 17.0);
						puntos = 0;
						vidas = 3;
						resetVars();
						addInitialPole();
						kp = ' ';


					
					}
				
				}
				else if (dadoSITN<0.9)
				{
					
					boton.load("botonirse.png");
					boton.draw(ofGetWidth() / 2 - boton.getWidth() / 2, ofGetHeight() - 200);
					if (EstadoDelJuego == 3 && kp == OF_KEY_UP)
					{
						Sound2.play();
						dia++;
						dadoSIT = ofRandom(0.0, 17.0);
						
						kp = ' ';
						dinero = dinero - gasto;
						if (dinero < 0) {
							EstadoDelJuego = 4;
						}
						else {
							EstadoDelJuego = 1;
						}

					}
					
				}

				
			
				
				break;


			case 4:
				//PERDISTE
				Perdiste();
				
			default:
				fondo.load("fondocamino2.png");
				fondo.draw(0, 0, ofGetWidth(), ofGetHeight());
				logo.draw(0,0, ofGetWidth(), ofGetHeight());
				boton.load("botonlaburar.png");
				boton.draw(ofGetWidth() / 2 - boton.getWidth() / 2, ofGetHeight() - 200);

				//if (EstadoDelJuego == 0 && mouseX > 300 && mouseX < 500 && mouseY > 500 && mouseY < 575  )
				if (EstadoDelJuego == 0 && kp== OF_KEY_UP )
				{
					Sound2.play();
					EstadoDelJuego = 1;
					kp = ' ';
				}
			}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	kp = key;

	
		if (dadoMJ >= 1 && dadoMJ <= 2) {
			int upper_key = toupper(key);
		
		

			if (upper_key == OF_KEY_UP && current_state == IN_PROGRESS) {
				flappy.fly(speed);

			}

			if (upper_key == OF_KEY_UP && current_state == FINISHED) {
				resetVars();
				addInitialPole();
				current_state == IN_PROGRESS;
			}

			if (upper_key == OF_KEY_UP && current_state == PAUSED) {
				if (current_state == PAUSED) {
					current_state = IN_PROGRESS;
				}
			}
		
		}

		if (dadoMJ >= 2 && dadoMJ <= 3) {
			switch (key) {

			case OF_KEY_LEFT: // left
				mySnake.setDir(-79, 0);
				break;
			case OF_KEY_RIGHT: // right
				mySnake.setDir(79, 0);
				break;
			case OF_KEY_UP: // up
				mySnake.setDir(0, -19);
				break;
			case OF_KEY_DOWN: // down
				mySnake.setDir(0, 19);
				break;
			}
		}
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	
}
//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	mouseX = x;
	mouseY = y;


	
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){


}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void ofApp::Situaciones() {

		if (paga <= 0) paga == 3;
		if (dadoSIT < 1.0 && dadoSIT >= 0.0) {
			celular.load("celular0.png");
			celular.draw(0, 0, ofGetWidth(), ofGetHeight());


			if (kp == OF_KEY_DOWN) {
				Sound4.play();
				nivel = nivel + 1;
				paga = paga + 10;
				dadoSIT = -1.0;
				kp = ' ';
			}
			if (kp == OF_KEY_UP) {
				Sound4.play();
				dadoSIT= -1.0;
				kp = ' ';
			}
			
			
		}
		if (dadoSIT <= 2.0 && dadoSIT > 1.0) {
			celular.load("celular1.png");
			celular.draw(0, 0, ofGetWidth(), ofGetHeight());


			if (kp == OF_KEY_UP) {
				Sound4.play();
				dinero = dinero - 40;
				felicidad = felicidad - 20;
				cansancio = cansancio + 40;
				dadoSIT= -1.0;
				kp = ' ';
			}
			if (kp == OF_KEY_DOWN) {
				Sound4.play();
				felicidad = felicidad - 30;
				cansancio = cansancio + 60;
				dadoSIT= -1.0;
				kp = ' ';
			}
		}
		if (dadoSIT <= 3.0 && dadoSIT > 2.0&& embarazo == false) {
			celular.load("celular2.png");
			celular.draw(0, 0, ofGetWidth(), ofGetHeight());


			if ( kp== OF_KEY_UP  )
			{
				Sound4.play();
				gasto = gasto + 20;
				dinero = dinero - 50;
				felicidad = felicidad + 10;
				cansancio = cansancio + 10;
				dadoSIT = -1.0;
				embarazo == true;
				kp = ' ';
			}
			if (kp == OF_KEY_DOWN) {
				Sound4.play();
				paga = ofRandom(3,10);
				dia = dia + 14;
				dadoSIT = -1.0;
				kp = ' ';
			}
		}
		else if (dadoSIT <= 3.0 && dadoSIT > 2.0 && embarazo == true) { dadoSIT = -1.0; }

		if (dadoSIT <= 4.0 && dadoSIT > 3.0 ) {
			celular.load("celular3.png");
			celular.draw(0, 0, ofGetWidth(), ofGetHeight());

			if (kp == OF_KEY_DOWN) {
				Sound4.play();
				dinero = dinero - 10;
				felicidad = felicidad + 10;
				dadoSIT= -1.0;
				kp = ' ';
			}
			if (kp == OF_KEY_UP) {
				Sound4.play();
				felicidad = felicidad - 10;
				dadoSIT= -1.0;
				kp = ' ';
			}
		}
		if (dadoSIT <= 5.0 && dadoSIT > 4.0) {
			celular.load("celular4.png");
			celular.draw(0, 0, ofGetWidth(), ofGetHeight());



			if (kp == OF_KEY_UP) {
				Sound4.play();
				paga = paga - 3;
				dadoSIT= -1.0;
				kp = ' ';
			}
		
		}
		if (dadoSIT <= 6.0 && dadoSIT > 5.0) {
			celular.load("celular5.png");
			celular.draw(0, 0, ofGetWidth(), ofGetHeight());



			if (kp == OF_KEY_UP) {
				Sound4.play();
				dadoSIT= -1.0;
				paga = paga - 10;
				kp = ' ';
			}
		
		}
		if (dadoSIT <= 7.0 && dadoSIT > 6.0) {
			celular.load("celular6.png");
			celular.draw(0, 0, ofGetWidth(), ofGetHeight());



			if (kp == OF_KEY_UP) {
				Sound4.play();
				dadoSIT= -1.0;
				nivel = 1;
				paga = 10;
				dia = dia + 14;
				Fechas();
				kp = ' ';
			}
		
		}
		if (dadoSIT <= 8.0 && dadoSIT > 7.0) {
			celular.load("celular7.png");
			celular.draw(0, 0, ofGetWidth(), ofGetHeight());




			if (kp == OF_KEY_UP) {
				Sound4.play();
				dadoSIT= -1.0;
				dinero = dinero - 30;
				paga = paga - 2;
				kp = ' ';
			}
		
		}
		if (dadoSIT <= 9.0 && dadoSIT > 8.0) {
			celular.load("celular8.png");
			celular.draw(0, 0, ofGetWidth(), ofGetHeight());


			if (kp == OF_KEY_UP) {
				Sound4.play();
				dinero = dinero - 10;
				felicidad = felicidad + 10;
				dadoSIT = -1.0;
				kp = ' ';
			}
			if (kp == OF_KEY_DOWN) {
				Sound4.play();
				felicidad = felicidad - 30;
				dadoSIT = -1.0;
				kp = ' ';
			}
		}
		if (dadoSIT <= 10.0 && dadoSIT > 9.0) {
			celular.load("celular9.png");
			celular.draw(0, 0, ofGetWidth(), ofGetHeight());

		

			if (kp == OF_KEY_UP) {
				Sound4.play();
				paga = paga - 3;
				dadoSIT = -1.0;
				kp = ' ';
			}
		
		}
		if (dadoSIT <= 11.0 && dadoSIT > 10.0) {
			celular.load("celular10.png");
			celular.draw(0, 0, ofGetWidth(), ofGetHeight());


			if (kp == OF_KEY_UP) {
				Sound4.play();
				paga = paga - 10;
				dinero = dinero - 50;
				dadoSIT = -1.0;
				kp = ' ';
			}
		
		}
		if (dadoSIT <= 12.0 && dadoSIT > 11.0) {
			celular.load("celular11.png");
			celular.draw(0, 0, ofGetWidth(), ofGetHeight());

			if (kp == OF_KEY_UP) {
				Sound4.play();
				felicidad = felicidad + 10;
				dinero = dinero - 70;
				dadoSIT= -1.0;
				kp = ' ';
			}
			if (kp == OF_KEY_DOWN) {
				felicidad = felicidad - 10;
				dadoSIT= -1.0;
				kp = ' ';
			}
		}
		if (dadoSIT <= 13.0 && dadoSIT > 12.0) {
			celular.load("celular12.png");
			celular.draw(0, 0, ofGetWidth(), ofGetHeight());

		

			if (kp == OF_KEY_UP) {
				Sound4.play();
				dia = dia + 14;
				nivel = 1;
				paga = 10;
				dadoSIT= -1.0;
				kp = ' ';
			}
		}
		if (dadoSIT <= 14.0 && dadoSIT > 13.0) {
			celular.load("celular13.png");
			celular.draw(0, 0, ofGetWidth(), ofGetHeight());


			if (kp == OF_KEY_DOWN) {
				Sound4.play();
				felicidad = felicidad - 70;
				dinero = dinero - 120;
				dadoSIT= -1.0;
				kp = ' ';
			}
			if (kp == OF_KEY_UP) {
				Sound4.play();
				felicidad = felicidad -80;
				dadoSIT= -1.0;
				kp = ' ';
			}
		}
		if (dadoSIT <= 15.0 && dadoSIT > 14.0 && manorota==false) {
			celular.load("celular14.png");
			celular.draw(0, 0, ofGetWidth(), ofGetHeight());


			if (kp == OF_KEY_UP) {
				Sound4.play();
				dia = dia + 1;
				gasto = gasto + 80;
				dinero = dinero - 100;
				dadoSIT= -1.0;
				manorota == true;
				kp = ' ';
			}

			if (kp == OF_KEY_DOWN) {
				Sound4.play();
				felicidad = felicidad - 40;
				dadoSIT = -1.0;
				kp = ' ';
			}
		}

		else if (dadoSIT <= 15.0 && dadoSIT > 14.0 && manorota == true) { dadoSIT = -1.0; }


		if (dadoSIT <= 16.0 && dadoSIT > 15.0) {
			celular.load("celular15.png");
			celular.draw(0, 0, ofGetWidth(), ofGetHeight());

			

			if (kp == OF_KEY_UP) {
				Sound4.play();
				dinero= dinero -50;
				dadoSIT= -1.0;
				kp = ' ';
			}

		}
		



		if (dadoSIT <= 17.0 && dadoSIT > 16.0) {
			celular.load("celular16.png");
			celular.draw(0, 0, ofGetWidth(), ofGetHeight());


			if (kp == OF_KEY_UP) {
				Sound4.play();
				paga = + 10;
				dinero = dinero - 200;
				dadoSIT= -1.0;
				kp = ' ';
			}
			if (kp == OF_KEY_DOWN) {
				Sound4.play();
				nivel = nivel + 1;
				paga = paga - 5;
				dadoSIT= -1.0;
				kp = ' ';
			}
		}

		if (dia == 18 && mes ==6) {
			celular.load("celular17.png");
			celular.draw(0, 0, ofGetWidth(), ofGetHeight());


			if (kp == OF_KEY_UP) {
				Sound4.play();
				dadoSIT= -1.0;
				gasto = gasto + 30;
				felicidad = felicidad + 10;
				kp = ' ';
			}
			if (kp == OF_KEY_DOWN) {
				Sound4.play();
				dadoSIT= -1.0;
				felicidad = felicidad - 10;
				kp = ' ';
			}
		}


		if (dia == 24 && mes == 12) {
			celular.load("celular18.png");
			celular.draw(0, 0, ofGetWidth(), ofGetHeight());


			if (kp == OF_KEY_DOWN) {
				Sound4.play();
				gasto = gasto + ofRandom(50, 90);
				felicidad = felicidad + 20;
				dadoSIT = -1.0;
				kp = ' ';
			}
			if (kp == OF_KEY_UP) {
				Sound4.play();
				felicidad = felicidad - 15;
				dadoSIT = -1.0;
				kp = ' ';
			}
		}

		if (dia == 31 && mes == 12)
		{
			celular.load("celular19.png");
			celular.draw(0, 0, ofGetWidth(), ofGetHeight());


			if (kp == OF_KEY_DOWN) {
				Sound4.play();
				gasto = gasto + 30;
				dadoSIT = -1.0;
				kp = ' ';
			}
			if (kp == OF_KEY_UP) {
				Sound4.play();
				dadoSIT = -1.0;
				kp = ' ';
			}
		}

}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void ofApp::Fechas(){

	if (mes == 1 && dia >= 32) {
		mes = 2;
		dia = 1;
	}
	if (mes == 2 && dia >= 29) {
		mes = 3;
		dia = 1;
	}
	if (mes == 3 && dia >= 32) {
		mes = 4;
		dia = 1;
	}
	if (mes == 4 && dia >= 31) {
		mes = 5;
		dia = 1;
	}
	if (mes == 5 && dia >= 32) {
		mes = 6;
		dia = 1;
	}
	if (mes == 6 && dia >= 31) {
		mes = 7;
		dia = 1;
	}
	if (mes == 7 && dia >= 32) {
		mes = 8;
		dia = 1;
	}
	if (mes == 8 && dia >= 32) {
		mes = 9;
		dia = 1;
	}
	if (mes == 9 && dia >= 31) {
		mes = 10;
		dia = 1;
	}
	if (mes == 10 && dia >= 32) {
		mes = 11;
		dia = 1;
	}
	if (mes == 11 && dia >= 31) {
		mes = 12;
		dia = 1;
	}
	if (mes == 12 && dia >= 32) {
		mes = 1;
		dia = 1;
		año++;
	}
	
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void ofApp::Perdiste() {

	fondo.load("perdiste.png");
	fondo.draw(0,0,ofGetWidth(),ofGetHeight());

}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void ofApp::HUD() {

	HUDf.load("papel.png");
	HUDf.draw(0,0, ofGetWidth(), ofGetHeight());

	string puntajen = "NIVEL: " + ofToString(nivel);
	textos.drawString(puntajen, 120, 120);

	string puntajec = "CANSANCIO: " + ofToString(cansancio);
	textos.drawString(puntajec, 120, 157);

	string puntajef = "FELICIDAD: " + ofToString(felicidad);
	textos.drawString(puntajef, 120, 190);

	string puntajep = "PAGA: " + ofToString(paga);
	textos.drawString(puntajep, 120, 230);

	string puntajeg = "GASTO: " + ofToString(gasto);
	textos.drawString(puntajeg, 120, 260);

	string puntajed = "DINERO: " + ofToString(dinero);
	textos.drawString(puntajed, 120, 300);


	string textoAño = ofToString(dia) + " del " + ofToString(mes) + " del " + ofToString(año);
	textos.drawString(textoAño, ofGetWidth()-400, 180);

}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//FLAPPY BIRD//FLAPPY BIRD//FLAPPY BIRD//FLAPPY BIRD//FLAPPY BIRD//FLAPPY BIRD//FLAPPY BIRD
//FLAPPY BIRD//FLAPPY BIRD//FLAPPY BIRD//FLAPPY BIRD//FLAPPY BIRD//FLAPPY BIRD//FLAPPY BIRD
void ofApp::resetVars() {
	//Resetting Variables
	pipes_vector.clear();
	number_of_pipes == 5;
	current_state = IN_PROGRESS;
	wall_moveSpeed = 15;
	number_of_pipes = 5;
	spawn_timer = 0;
	current_state = PAUSED;
	flappy.birdSetup(ofGetWidth() / 2, ofGetHeight() / 2, ofGetHeight(), ofGetWidth());
}

//--------------------------------------------------------------
void ofApp::addInitialPole() {
	for (int i = 0; i < number_of_pipes; i++) {
		pipes_vector.push_back(*new pipes);
		pipes_vector[i].pipeSetup(ofGetHeight(), ofGetWidth(), ofGetWidth());
	}
}
void ofApp::drawPipes() {
	for (int i = 0; i < pipes_vector.size(); i++) {
		//Collision detection
		if (flappy.isDead(pipes_vector[i].getTopPipe(), pipes_vector[i].getBottomPipe(), pipes_vector[i].getGapSize(), pipes_vector[i].getXCor())) {
			wall_moveSpeed = 0;
			dinero = dinero + (paga*pipes_vector.size());
			current_state = FINISHED;
		}

		for (int j = 0; j < 2; j++) {
			if (j == 0) {
				//ofDrawRectangle(pipes_vector[i].getXCor(), 44, 50, pipes_vector[i].getTopPipe());
				pipes1.draw(pipes_vector[i].getXCor(), 0, 50, pipes_vector[i].getTopPipe());
			}
			else if (j == 1) {
				//ofDrawRectangle(pipes_vector[i].getXCor(), pipes_vector[i].getBottomPipe(), 50, 900);
				pipes1.draw(pipes_vector[i].getXCor(), pipes_vector[i].getBottomPipe(), 50, 900);
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::drawBird() {

	//ofDrawRectangle(flappy.getXCor(), flappy.getYCor(), 50, 50);
	fp.draw(flappy.getXCor(), flappy.getYCor(), 50, 50);
}


void ofApp::setupFB()
{
	ofSetBackgroundAuto(true);
	flappy.birdSetup(ofGetWidth() / 2, ofGetHeight() / 2, ofGetHeight(), ofGetWidth());
	addInitialPole();
}

void ofApp::updateFB()
{

	if (current_state == IN_PROGRESS) {
		flappy.gravity(gravity_value);
		for (int i = 0; i < pipes_vector.size(); i++) {
			pipes_vector[i].movePipe(wall_moveSpeed);
		}
		spawn_timer++;
		if (spawn_timer == spawn_time) {
			Sound3.play();
			pipes_vector.push_back(*new pipes);
			pipes_vector[number_of_pipes].pipeSetup(ofGetHeight(), ofGetWidth(), ofGetWidth());
			number_of_pipes++;
			spawn_timer = 0;
		}
	}
}

void ofApp::drawFB()
{
	
	fondo.load("fondofp.png");
	fondo.draw(0, 0, ofGetWidth(), ofGetHeight());
	drawBird();
	drawPipes();
	if (current_state == PAUSED) {
		ofDrawBitmapString("PRESS UP TO START", 258, 384);
	}
//FPS Counter.
	string message = "fps: " + ofToString(ofGetFrameRate()) + " Dinero ganado" + (ofToString(pipes_vector.size()*paga ));
	ofDrawBitmapString(message, 10, 20);
	
}

void ofApp::KPFB()
{

	//Q changes the color of the birds


}
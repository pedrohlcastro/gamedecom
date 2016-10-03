#include <GL/glew.h>
#include <GL/freeglut.h>
#include <SOIL/SOIL.h>
#include <bits/stdc++.h>
#include "estruturasPrincipais.h"
#include "personagem.h"
using namespace std;

//construtor da classe movimento
Movimento::Movimento(){
	this->pontos.x = -100;
	this->pontos.y = 0;
	this->comprimento = 20;
	this->gravidadePulo = 1.5;
	this->alturaPulo = 80;
	this->situacao = normal;
}

void Movimento::incPontoY(float inc){
	this->pontos.y += inc;
}

void Movimento::pula(){
	cout << "x " << this->pontos.x << "y " << this->pontos.y << endl;
	if (this->pontos.y > 0 && this->pontos.y < this->alturaPulo){
		this->pontos.y += 0.6 - this->gravidadePulo;
		this->gravidadePulo += 0.18;
	}
	if (this->pontos.y < 0){
		this->gravidadePulo = 0;
		this->pontos.y = 0;
	}
	if (this->pontos.y >= this->alturaPulo){ // CASO ELE CHEGUE NO LIM ESTABELECIDO, CAI.
		this->pontos.y -= 0.6;
	}
}

Sentido Movimento::getSituacao (){
	return this->situacao;
}

void Movimento::mudaSituacao(Sentido situacao){
	this->situacao = situacao;
}

ponto Movimento::getCoord(){
	return this->pontos;
}

void Movimento::desenhaPersonagem(){
	Movimento::pula();

	glPushMatrix();
		glTranslatef(this->pontos.x, this->pontos.y, 1);
		//printf("%f %f\n",this->pontoParede.x, this->pontoParede.y );
		glBegin(GL_POLYGON);
			glVertex2f(0,0);
			glVertex2f(this->comprimento,0);
			glVertex2f(this->comprimento,this->comprimento);
			glVertex2f(0,this->comprimento);
		glEnd();
	glPopMatrix();
}
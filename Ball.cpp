#include "Ball.h"
#include <stdlib.h>
#include "ofGraphics.h"


Ball::Ball(void)
{
	positionX = (float)(rand()%640);
	positionY = 10.0f;
	velocityX = 1.0f;
	velocityY = 1.0f;

	radius = 30;
	//initial color of the ball is perfect Green
	colorRed = 0;
	colorGreen = 255;

	hitCount = 0;
}


Ball::~Ball(void)
{
}

void Ball::setPosition( float posX, float posY )
{
	positionX = posX;
	positionY = posY;
}

void Ball::setColor( int hitCount )
{
	colorRed = ( 0* ( 1-( hitCount/MAX_HIT_COUNT-1 ) ) ) +  ( 255 * ( hitCount/MAX_HIT_COUNT-1 ) );
	colorGreen = ( 255* ( 1-( hitCount/MAX_HIT_COUNT-1 ) ) ) +  ( 0 * ( hitCount/MAX_HIT_COUNT-1 ) );
}

void Ball::isCollided( float posX, float posY )
{

}

void Ball::display()
{
	update();

	ofSetColor(colorRed, colorGreen, 0);
	ofCircle(positionX, positionY, radius);
}

void Ball::update()
{
	positionX += velocityX;
	positionY += velocityY;
	setColor(hitCount);

	if(positionX + radius >= ofGetViewportWidth() || positionX - radius <= 0) {
		velocityX = (-1) * velocityX;
	}
	if( positionY + radius >= ofGetViewportHeight() || positionY - radius <= 0) {
		velocityY = (-1) * velocityY;
	}

}

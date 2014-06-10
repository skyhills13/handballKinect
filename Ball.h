#pragma once

#define MAX_HIT_COUNT 5

class Ball
{
public:
	Ball(void);
	~Ball(void);

	float positionX;
	float positionY;
	//velocity is basically constant
	float velocityX;
	float velocityY;
	
	int radius;
	int colorRed;
	int colorGreen;
	//int colorBlue;

	int hitCount;

	void setPosition(float posX, float posY);
	void setColor(int hitCount);
	void isCollided(float posX, float posY);

	void display();
	void update();

};


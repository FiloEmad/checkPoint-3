#include "grid.h"
#include "game.h"
#include "gameConfig.h"
#include <cstdlib>
#include <time.h>
#include <iostream>
using namespace std;


grid::grid(point r_uprleft, int wdth, int hght, game* pG)
{
	uprLeft = r_uprleft;
	height = hght;
	width = wdth;
	pGame = pG;
	rows = height / config.gridSpacing;
	cols = width / config.gridSpacing;
	shapeCount = 0;

	for (int i = 0; i < MaxShapeCount; i++)
		shapeList[i] = nullptr;

	activeShape = nullptr;

}

grid::~grid()
{
	for (int i = 0; i < shapeCount; i++)
		delete shapeList[i];
}

void grid::draw() const
{
	clearGridArea();
	window* pWind = pGame->getWind();
	
	pWind->SetPen(config.gridDotsColor,1);
	pWind->SetBrush(config.gridDotsColor);

	//draw dots showing the grid reference points
	for (int r = 1; r < rows; r++)
		for (int c = 0; c < cols; c++)
			pWind->DrawCircle(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y, 1);
			//pWind->DrawPixel(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y);

	//Draw ALL shapes
	for (int i = 0; i < shapeCount; i++)
		if (shapeList[i])
		{
			shapeList[i]->draw();	//draw each shape
		}

	//Draw the active shape
	if(activeShape)
		activeShape->draw();
}

void grid::clearGridArea() const
{
	window* pWind = pGame->getWind();	
	pWind->SetPen(config.bkGrndColor, 1);
	pWind->SetBrush(config.bkGrndColor);
	pWind->DrawRectangle(uprLeft.x, uprLeft.y, uprLeft.x + width, uprLeft.y + height);
}

//Adds a shape to the randomly created shapes list.
bool grid::addShape(shape* newShape)
{
	//TODO:
	// 1- Check that the shape can be drawn witout being clipped by grid boundaries
	// 2- check shape count doesn't exceed maximum count
	// return false if any of the checks fail
	
	
	//Here we assume that the above checks are passed
	if (newShape->draw()==true)
	{
		shapeList[shapeCount++] = newShape;
		return true;
	}
	else
	{
		return false;
	}
}

void grid::setActiveShape(shape* actShape)
{
	delete activeShape;
	activeShape = actShape;
}

void grid::DelActiveShape()
{
	delete activeShape; activeShape = nullptr;
	draw();
}

void grid::IncActiveShape() const
{
	clearGridArea();
	window* pWind = pGame->getWind();

	pWind->SetPen(config.gridDotsColor, 1);
	pWind->SetBrush(config.gridDotsColor);

	//draw dots showing the grid reference points
	for (int r = 1; r < rows; r++)
		for (int c = 0; c < cols; c++)
			pWind->DrawCircle(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y, 1);
	//pWind->DrawPixel(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y);

//Draw ALL shapes
	for (int i = 0; i < shapeCount; i++)
		if (shapeList[i])
			shapeList[i]->draw();	//draw each shape

	//Draw the active shape
	if (activeShape)
		activeShape->resize(1);
}

void grid::DecActiveShape() const
{
	clearGridArea();
	window* pWind = pGame->getWind();

	pWind->SetPen(config.gridDotsColor, 1);
	pWind->SetBrush(config.gridDotsColor);

	//draw dots showing the grid reference points
	for (int r = 1; r < rows; r++)
		for (int c = 0; c < cols; c++)
			pWind->DrawCircle(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y, 1);
	//pWind->DrawPixel(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y);

//Draw ALL shapes
	for (int i = 0; i < shapeCount; i++)
		if (shapeList[i])
			shapeList[i]->draw();	//draw each shape

	//Draw the active shape
	if (activeShape)
		activeShape->resize(0);
}

void grid::RotateActiveShapeR() const
{
	clearGridArea();
	window* pWind = pGame->getWind();

	pWind->SetPen(config.gridDotsColor, 1);
	pWind->SetBrush(config.gridDotsColor);

	//draw dots showing the grid reference points
	for (int r = 1; r < rows; r++)
		for (int c = 0; c < cols; c++)
			pWind->DrawCircle(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y, 1);
	//pWind->DrawPixel(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y);

//Draw ALL shapes
	for (int i = 0; i < shapeCount; i++)
		if (shapeList[i])
			shapeList[i]->draw();	//draw each shape

	//Draw the active shape
	if (activeShape)
		activeShape->rotate(1);
}

void grid::RotateActiveShapeL() const
{
	clearGridArea();
	window* pWind = pGame->getWind();

	pWind->SetPen(config.gridDotsColor, 1);
	pWind->SetBrush(config.gridDotsColor);

	//draw dots showing the grid reference points
	for (int r = 1; r < rows; r++)
		for (int c = 0; c < cols; c++)
			pWind->DrawCircle(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y, 1);
	//pWind->DrawPixel(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y);

//Draw ALL shapes
	for (int i = 0; i < shapeCount; i++)
		if (shapeList[i])
			shapeList[i]->draw();	//draw each shape

	//Draw the active shape
	if (activeShape)
		activeShape->rotate(0);
}

void grid::MoveActiveShapeR()const
{
	clearGridArea();
	window* pWind = pGame->getWind();

	pWind->SetPen(config.gridDotsColor, 1);
	pWind->SetBrush(config.gridDotsColor);

	//draw dots showing the grid reference points
	for (int r = 1; r < rows; r++)
		for (int c = 0; c < cols; c++)
			pWind->DrawCircle(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y, 1);
	//pWind->DrawPixel(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y);

//Draw ALL shapes
	for (int i = 0; i < shapeCount; i++)
		if (shapeList[i])
			shapeList[i]->draw();	//draw each shape

	//Draw the active shape
	if (activeShape)
		activeShape->move(0);
}

void grid::MoveActiveShapeL()const
{
	clearGridArea();
	window* pWind = pGame->getWind();

	pWind->SetPen(config.gridDotsColor, 1);
	pWind->SetBrush(config.gridDotsColor);

	//draw dots showing the grid reference points
	for (int r = 1; r < rows; r++)
		for (int c = 0; c < cols; c++)
			pWind->DrawCircle(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y, 1);
	//pWind->DrawPixel(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y);

//Draw ALL shapes
	for (int i = 0; i < shapeCount; i++)
		if (shapeList[i])
			shapeList[i]->draw();	//draw each shape

	//Draw the active shape
	if (activeShape)
		activeShape->move(1);
}

void grid::MoveActiveShapeUP()const
{
	clearGridArea();
	window* pWind = pGame->getWind();

	pWind->SetPen(config.gridDotsColor, 1);
	pWind->SetBrush(config.gridDotsColor);

	//draw dots showing the grid reference points
	for (int r = 1; r < rows; r++)
		for (int c = 0; c < cols; c++)
			pWind->DrawCircle(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y, 1);
	//pWind->DrawPixel(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y);

//Draw ALL shapes
	for (int i = 0; i < shapeCount; i++)
		if (shapeList[i])
			shapeList[i]->draw();	//draw each shape

	//Draw the active shape
	if (activeShape)
		activeShape->move(3);
}

void grid::MoveActiveShapeDOWN()const
{
	clearGridArea();
	window* pWind = pGame->getWind();

	pWind->SetPen(config.gridDotsColor, 1);
	pWind->SetBrush(config.gridDotsColor);

	//draw dots showing the grid reference points
	for (int r = 1; r < rows; r++)
		for (int c = 0; c < cols; c++)
			pWind->DrawCircle(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y, 1);
	//pWind->DrawPixel(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y);

//Draw ALL shapes
	for (int i = 0; i < shapeCount; i++)
		if (shapeList[i])
			shapeList[i]->draw();	//draw each shape

	//Draw the active shape
	if (activeShape)
		activeShape->move(2);
}

void grid::RefreshGrid()
{
	for (int i = 0; i < MaxShapeCount; i++)
	{
		if (shapeList[i])
		{
			delete shapeList[i];
			shapeList[i] = nullptr;
		}
	}
	shapeCount = 0;
	delete activeShape;
	activeShape = nullptr;
}

bool grid::check()
{
	int a_k, a_t, s_k, s_t; point a_p, s_p; ShapeType act, ran;
	act = activeShape->getType();
	activeShape->Getters(a_k, a_t, a_p);
	int c = 0;
	int ii;
	int l = 2 * pGame->getLevel() - 1;
	for (int i = 0; i < l; i++)
	{
		ran = shapeList[i]->getType();
		shapeList[i]->Getters(s_k, s_t, s_p);
		if (a_k == s_k && a_t == s_t && s_p.x == a_p.x && s_p.y == a_p.y && act == ran)
		{
			c++;
			ii = i;
		}
	}
	if (c == 0)
	{
		return false;
	}
	else
	{
		delete activeShape; activeShape = nullptr;
		delete shapeList[ii]; shapeList[ii] = nullptr;
		draw();
		return true;
	}
}

void grid::hint() {
	int indx = 2;
	static time_t startTime = time(NULL);
	int timer = 20;
	time_t currentTime = time(NULL);
	int elapsedSeconds = currentTime - startTime;
	timer -= elapsedSeconds;
	for (int i = shapeCount; i > 0 + 1; i--)
	{

		if (shapeList[i] != nullptr)
		{
			
			if (timer != 0 || timer > 0)
			{
				shapeList[i]->setColor(RED);
				draw();
				indx = i;
				i = -1;
			}
		}
		
	}
	//if (timer==0||)
	shapeList[indx]->setColor(BLACK);

	
	draw();

}

int grid::getshapecount() const
{

	return shapeCount;

}

shape* grid::getshapelist() const
{
	int a, b; point c;
	shapeList[0]->Getters(a, b, c);
	return *shapeList;
}
void grid::createA(shape* arr[], int size) {

	for (int i = 0; i < size; i++) {
		arr[i] = shapeList[i];
	}
}


shape* grid::getactiveshape() const
{
	return activeShape;
}
#include "operations.h"
#include "game.h"
#include "CompositeShapes.h"
#include "shape.h"
#include <cstdlib>
#include <time.h>
#include <iostream>
#include<fstream>
using namespace std;
/////////////////////////////////// class operation  //////////////////
operation::operation(game* r_pGame)
{
	pGame = r_pGame;
}


/////////////////////////////////// class operAddSign  //////////////////

operAddSign::operAddSign(game* r_pGame) :operation(r_pGame)
{
}
void operAddSign::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new Sign(pGame, signShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);
	pGrid->draw();
}

/////////////////////////////////// class operAddHome  //////////////////

operAddHome::operAddHome(game* r_pGame) : operation(r_pGame)
{
}
void operAddHome::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new Home(pGame, signShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);
	pGrid->draw();
}

/////////////////////////////////// class operAddHat  //////////////////

operAddHat::operAddHat(game* r_pGame) : operation(r_pGame)
{
}
void operAddHat::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new Hat(pGame, signShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);
	pGrid->draw();
}

/////////////////////////////////// class operAddFlag  //////////////////

operAddFlag::operAddFlag(game* r_pGame) : operation(r_pGame)
{
}
void operAddFlag::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new Flag(pGame, signShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);
	pGrid->draw();
}

/////////////////////////////////// class operAddLolypop  //////////////////

operAddLolypop::operAddLolypop(game* r_pGame) : operation(r_pGame)
{
}
void operAddLolypop::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new lolypop(pGame, signShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);
	pGrid->draw();
}
operAddtree::operAddtree(game* r_pGame) : operation(r_pGame)
{
}
void operAddtree::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new ChristmasTree(pGame, signShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);
	pGrid->draw();
}
operAddbullet::operAddbullet(game* r_pGame) : operation(r_pGame)
{
}
void operAddbullet::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new Bullet(pGame, signShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);
	pGrid->draw();
}
////////////////////////////////////////////////Buttoms///////////////////////////////////////////////
operhint::operhint(game* r_pGame) : operation(r_pGame)
{
}
void operhint::Act()
{
	grid* pGrid = pGame->getGrid();
	pGrid->hint();
}
operrefresh::operrefresh(game* r_pGame) : operation(r_pGame)
{
}
void operrefresh::Act()
{
	grid* pGrid = pGame->getGrid();
	pGrid->RefreshGrid();
	pGrid->draw();
}
opersave::opersave(game* r_pGame) : operation(r_pGame)
{
}
void opersave::Act()
{
	ofstream Progress("progress.txt");
	FILE* progress = fopen("progress.txt", "w");
	int c = pGame->getLives();
	int s = pGame->getScore();
	int l = pGame->getLevel();
	fprintf(progress, "%d", c);
	fprintf(progress, "%d", s);
	fprintf(progress, "%d", l);

	shape* shapess[1000];
	pGame->getGrid()->createA(shapess, pGame->getGrid()->getshapecount());


	for (int i = 0; i < pGame->getGrid()->getshapecount(); i++) {
		cout << c;
		shapess[i]->save(progress);
		cout << l;
	}

	shape* kk = pGame->getGrid()->getactiveshape();
	kk->save(progress);
	fclose(progress);
}

/////////////////////////////////// class operDelShape  //////////////////

operDelShape::operDelShape(game* r_pGame) :operation(r_pGame)
{
}
void operDelShape::Act()
{
	grid* pGrid = pGame->getGrid();
	pGrid->DelActiveShape();
}

/////////////////////////////////// class operIncShape  //////////////////

operIncShape::operIncShape(game* r_pGame) :operation(r_pGame)
{
}
void operIncShape::Act()
{
	grid* pGrid = pGame->getGrid();
	pGrid->IncActiveShape();
}

/////////////////////////////////// class operDecShape  //////////////////

operDecShape::operDecShape(game* r_pGame) :operation(r_pGame)
{
}
void operDecShape::Act()
{
	grid* pGrid = pGame->getGrid();
	pGrid->DecActiveShape();
}

/////////////////////////////////// class rotater  //////////////////

rotater::rotater(game* r_pGame) : operation(r_pGame)
{
}
void rotater::Act()
{
	grid* pGrid = pGame->getGrid();
	pGrid->RotateActiveShapeR();
}

/////////////////////////////////// class rotatel  //////////////////

rotatel::rotatel(game* r_pGame) : operation(r_pGame)
{
}
void rotatel::Act()
{
	grid* pGrid = pGame->getGrid();
	pGrid->RotateActiveShapeL();
}


operDrawLevel::operDrawLevel(game* r_pGame) : operation(r_pGame)
{
}

void operDrawLevel::Act()
{
	grid* pGrid = pGame->getGrid();
	pGrid->RefreshGrid();
	int l = pGame->getLevel();
	int level = 2 * l - 1;
	srand(time(NULL));
	double theta = 22.0 / 56.0;
	shape* p_shape = nullptr;
	int red, blue, yello;
	for (int i = 0; i < level; i++)
	{
		red = rand() % 255; blue = rand() % 255; yello = rand() % 255;
		int k, s; point ref;
		k = rand() % 20 - 10;
		double c = rand() % 8;
		int rows = (config.windHeight - config.toolBarHeight - config.statusBarHeight) / config.gridSpacing;
		int cols = (config.windWidth / config.gridSpacing) / 2;
		s = rand() % 7;
		ref.x = (rand() % cols + 1) * 30;
		ref.y = (rand() % (rows) + 1) * 30 + config.toolBarHeight;
		if (s == 0)
		{
			p_shape = new Sign(pGame, ref);
		}
		if (s == 1)
		{
			p_shape = new Home(pGame, ref);
		}
		if (s == 2)
		{
			p_shape = new Bullet(pGame, ref);
		}
		if (s == 3)
		{
			p_shape = new ChristmasTree(pGame, ref);
		}
		if (s == 4)
		{
			p_shape = new Hat(pGame, ref);
		}
		if (s == 5)
		{
			p_shape = new Flag(pGame, ref);
		}
		if (s == 6)
		{
			p_shape = new lolypop(pGame, ref);
		}
		color r_color(red, blue, yello);
		p_shape->setColor(BLACK);
		p_shape->setparamaters(k, theta * c);
		bool check = pGrid->addShape(p_shape);
		if (check == false)
		{
			i--;
		}
		//delete p_shape; p_shape = nullptr;
	}
	pGrid->draw();
}


operSelectLevel::operSelectLevel(game* r_pGame) : operation(r_pGame)
{
}
void operSelectLevel::Act()
{
	keytype inpt;
	operation* f = nullptr;
	char cKeyData;
	inpt = pGame->getWind()->WaitKeyPress(cKeyData);
	if (cKeyData == ASCII) {
		if (isdigit(cKeyData))
			pGame->setLevel(cKeyData);
		f = new operDrawLevel(pGame);
	}
}

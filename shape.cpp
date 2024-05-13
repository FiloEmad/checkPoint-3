#include "shape.h"
#include "game.h"
#include "gameConfig.h"

shape::shape(game* r_pGame, point ref)
{
	RefPoint = ref;
	pGame = r_pGame;
	fillColor = config.fillColor;
	borderColor = config.penColor;
}

void shape::setRefPoint(point p)
{
	RefPoint = p;
}
point shape::getRefPoint() const
{
	return RefPoint;
}

void shape::setparamaters(int n_k, double n_th)
{
	k = n_k; theta = n_th;
}

void shape::Getters(int& s, int& t, point& p)
{
	s = k; t = theta; p = RefPoint;
}

void shape::save(FILE* prog)
{
	fprintf(prog, "%d", k);

}

ShapeType shape::getType()
{
	return type;
}





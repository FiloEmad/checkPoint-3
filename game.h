#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "toolbar.h"
#include "operations.h"
#include "grid.h"



//Main class that coordinates the game operation
class game
{

	/// Add more members if needed

	toolbar* gameToolbar;
	int counter = 5;;
	int level = 0;
	int score = 0;

	window* pWind;	//Pointer to the CMU graphics window
	grid* shapesGrid;

public:
	game();
	~game();

	string getSrting() const;	 //Returns a string entered by the user
	void createWind(int, int, int, int); //creates the game window
	void clearStatusBar() const;	//Clears the status bar
	void printMessage(string msg) const;	//Print a message on Status bar
	void createToolBar();		//creates the toolbar
	void createGrid();		//creates the shapes grid
	void printstatus(int counter, int score, int level);
	window* getWind() const;		//returns a pointer to the graphics window
	grid* getGrid() const;		//returns a pointer to the shapes grid
	int getLevel() const;
	void setLevel(int l);
	void checkplay();
	int getScore() const;
	int getLives() const;
	void levelup();
	void Timer();

	//creates an operation according to the toolbar item clicked
	operation* createRequiredOperation(toolbarItem clickedItem);
	void chechMovement();



	void run();	//start the game

};
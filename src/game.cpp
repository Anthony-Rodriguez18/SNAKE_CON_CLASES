/*Grupo: El profesor y las chicas super poderosas        CIENCIA DE LA COMPUTACIÓN I  CCOMP2-1
INTEGRANTES:
- Josue Carpio
- Ariana Leon
- Anthony Rodriguez */
#include "../include/basic.h"

Game::Game(int width_, int height_): width { width_ }, height { height_ }
{
    this->state = GameState::GAME;
    this->map = new Map();
	this->velocidad = 100000000;
	this->a=0;
}

Game::~Game()
{
    ;
}

/*void Game::configure()
{
    system("MODE con cols=24 lines=25");
}*/

void Game::init()
{
    //this->configure();

    this->snakes.push_back(new Snake(KeyboardType::WASD,SnakeType::snake1));
	// this->snakes[0]=new Snake(Keyboard::WASD)
    this->snakes.push_back(new Snake(KeyboardType::IJKL,SnakeType::snake2));
    

    /*for (auto i = snakes.begin(); i != snakes.end(); ++i) 
    {
        (*i)->setDirection(Direction::STOP);
    }*/ 

    this->map->setSnakes(this->snakes);
    this->play();
}

void Game::play()
{
	
    while(this->state == GameState::GAME)
    {
		velocidad = velocidad - 10000;
        this->map->draw();
        this->map->generateTail();
        this->events();
        
        bool collided = this->map->collision();
        // if (collided)
        //     this->finish();
		while (a < velocidad) {
			a++;
		}
		a = 0;

        //Sleep(100); 
    }
}

void Game::finish()
{
    this->state = GameState::END;
}

void Game::menu()
{
	char seguir;
	std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ JUEGO TERMINADO $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << std::endl;
	std::cout << "Desean continuar? (y,n):";
	std::cin >> seguir;
	if (seguir == 'y' || seguir == 'Y')
	{
		std::cout << "\n \n \n";
		std::cout << "\n";
		this->play();
		std::cout << "\n";
		std::cout << "\n";
		std::cout << "\n";
	}
	else
		this->state = GameState::END;
}

void Game::events()
{
	snakes.at(0)->keyPressEvent();
	snakes.at(0)->move();
	snakes.at(1)->keyPressEvent();
	snakes.at(1)->move();
	/*if (this->keyboardType == KeyboardType::WASD)
	{
		snakes.at(0)->keyPressEvent();
		snakes.at(0)->move();
	}
	if (this->keyboardType == KeyboardType::IJKL)
	{
		snakes.at(1)->keyPressEvent();
		snakes.at(1)->move();
	}*/
	
    /*for (auto i = snakes.begin(); i != snakes.end(); ++i) 
    {
        (*i)->keyPressEvent();
        (*i)->move();
    }*/
}

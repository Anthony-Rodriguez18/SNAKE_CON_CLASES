/*Grupo: El profesor y las chicas super poderosas        CIENCIA DE LA COMPUTACIÓN I  CCOMP2-1
INTEGRANTES:
- Josue Carpio
- Ariana Leon
- Anthony Rodriguez */
#include "../include/basic.h"

Map::Map()
{
    this->generateFruit();
}

Map::~Map()
{
    ;
}

void Map::draw()
{
    
	
	//std::cout<<"Vidas Snake 1: "<<setLIVE
	
	
    //std::cout<<"Vidas Snake2: "<<setLIVE;
    std::cout << std::endl;
    std::cout << " ";
    
    for (int i = 0; i < WIDTH+2; i++)
        std::cout << "$";

    std::cout << std::endl;

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (j == 0)
                std::cout << " $";

            bool charExist = false;
            if (i == this->fruitY && j == this->fruitX) {
                std::cout << "+";
                charExist = true;
            }

            for (auto s = snakes.begin(); s != snakes.end(); ++s)
            {
                if (!charExist && i == (*s)->getY() && j == (*s)->getX())
                    std::cout << std::string(1,(*s)-> getSnakeType());
                
				else if (!charExist)
                {
                    bool print = false;
                    for (int k = 0; k < (*s)->getNTail(); k++)
                    {
                        if ((*s)->getTailX()[k] == j && (*s)->getTailY()[k] == i)
                        {
                            std::cout << std::string(1,(*s)-> getSnakeType());
                            print = true;
                        }
                    }
                    if (!print)
                        std::cout << " ";
                }
            
            } 

            if (j == WIDTH - 1)
                std::cout << "$";
        }
        std::cout << std::endl;
    }

    std::cout << " ";
    for (int i = 0; i < WIDTH+2; i++)
        std::cout << "$";
	
	for (auto s = snakes.begin(); s != snakes.end(); ++s)
	{
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "VIDAS - "<< std::string(1,(*s)-> getSnakeType()) <<": "<<(*s)-> getLIVE()<< std::endl;
		std::cout << "SCORE - "<< std::string(1,(*s)-> getSnakeType()) <<": "<<(*s)-> getSCORE()<< std::endl;
	}
	
	
}

void Map::generateTail()
{
    for (auto s = snakes.begin(); s != snakes.end(); ++s)
    {
        int prevX = (*s)->getTailX()[0];
        int prevY = (*s)->getTailY()[0];
        int prev2X, prev2Y;
        (*s)->getTailX()[0] = (*s)->getX();
        (*s)->getTailY()[0] = (*s)->getY();
        
        for (int i = 1; i < (*s)->getNTail(); i++)
        {
            prev2X = (*s)->getTailX()[i];
            prev2Y = (*s)->getTailY()[i];
            (*s)->getTailX()[i] = prevX;
            (*s)->getTailY()[i] = prevY;
            prevX = prev2X;
            prevY = prev2Y;
        }
    }
}

void Map::generateFruit()
{
    this->fruitX = rand() % WIDTH;
    this->fruitY = rand() % HEIGHT;
}

bool Map::collision()
{
    for (auto s = snakes.begin(); s != snakes.end(); ++s)
    {

        if ((*s)->getX() > WIDTH) 
        {
            (*s)->setX(0);
			(*s)->setLIVE((*s)->getLIVE()-1);
        }
        else if ((*s)->getX() < 0) 
        {
            (*s)->setX(WIDTH);
			(*s)->setLIVE((*s)->getLIVE()-1);
        }
        else if ((*s)->getY() > HEIGHT)
        {
            (*s)->setY(0);
			(*s)->setLIVE((*s)->getLIVE()-1);
        }
        else if ((*s)->getY() < 0)
        {
            (*s)->setY(HEIGHT);
			(*s)->setLIVE((*s)->getLIVE()-1);
        }
		
		/*for (int i=0; i<(*s)->getNTail(), i++){
			if ((*s)->getTailX()[i]==(*s)->getX() && (*s)->getTAILy()[i]==(*s)->getY())
			(*s)->(setColision()-1);
		}*/
		

        for (int i = 0; i < (*s)->getNTail(); i++) {
            if ((*s)->getTailX()[i] == (*s)->getX() && (*s)->getTailY()[i] == (*s)->getY())    
			(*s)->setLIVE((*s)->getLIVE()-1);
        }
		
		/*for (int i = 0; i < (*s)->getNTail(); i++) {
            if ((*s)->getTailX((*s)-> getSnakeType(snake1))[i] == (*s)->getX((*s)-> getSnakeType(snake2)) && (*s)->getTailY((*s)-> getSnakeType(snake1))[i] == (*s)->getY((*s)-> getSnakeType(snake2)))    
			(*s)->setLIVE((*s)->getLIVE()-1);
        }*/

        if ((*s)->getX() == this->fruitX && (*s)->getY() == this->fruitY)
        {
            srand(time(0));

            this->generateFruit();
            (*s)->setNTail((*s)->getNTail() + 1);
			if ((*s)->getNTail()==5)
			{
				(*s)->setLIVE((*s)->getLIVE()+1);
			}
				
			(*s)->setSCORE((*s)->getSCORE()+10);
        }
    }
    return false;
}

/*void men() {
	char seguir;
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ JUEGO TERMINADO $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	cout << "Desean continuar? (y,n):";
	cin >> seguir;
	if (seguir == 'y' || seguir == 'Y')
	{
		cout << "\n \n \n";
		cout << "\n";
		juego = true;
		system(cls)
		cout << "\n";
		cout << "\n";
		cout << "\n";
	}
	else
		juego = false;
}*/
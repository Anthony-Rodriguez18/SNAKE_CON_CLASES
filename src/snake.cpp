/*Grupo: El profesor y las chicas super poderosas        CIENCIA DE LA COMPUTACIÓN I  CCOMP2-1
INTEGRANTES:
- Josue Carpio
- Ariana Leon
- Anthony Rodriguez */
#include "../include/basic.h"

Snake::Snake(KeyboardType keyboardType_, SnakeType snakeType_) : keyboardType { keyboardType_ } , TypeSnake {snakeType_}
{
    this->x = rand() % WIDTH;
    this->y = rand() % HEIGHT;
	this->live=5;
	this->score=0;
    this->direction = Direction::STOP;
    this->nTail = 0;
	this->choques=0;
}

Snake::~Snake()
{
    ;
}

void Snake::move()
{
    switch (this->direction)
    {
    case Direction::LEFT:
        this->x--;
        break;
    case Direction::RIGHT:
        this->x++;
        break;
    case Direction::UP:
        this->y--;
        break;
    case Direction::DOWN:
        this->y++;
        break;
    default:
        break;
    }
}

void Snake::keyPressEvent()
{
    if (_kbhit())
    {
        if (this->keyboardType == KeyboardType::WASD) 
        {
            switch (_getch())
            {
                case 'a':
                    this->direction = Direction::LEFT;
                    break;
                case 'd':
                    this->direction = Direction::RIGHT;
                    break;
                case 'w':
                    this->direction = Direction::UP;
                    break;
                case 's':
                    this->direction = Direction::DOWN;
                    break;
				case 'q':
					menu();
					break;
                default:
                    break;
            }
        } 
        if (this->keyboardType == KeyboardType::IJKL) 
        {
             switch (_getch())
            {
                case 'j':
                    this->direction = Direction::LEFT;
                    break;
                case 'l':
                    this->direction = Direction::RIGHT;
                    break;
                case 'i':
                    this->direction = Direction::UP;
                    break;
                case 'k':
                    this->direction = Direction::DOWN;
                    break;
				case 'Q':
					menu();
					break;
                default:
                    break;
            }
        }
    }
}

void Snake::menu()
{
	/*char seguir;
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
		this->state = GameState::END;*/
}
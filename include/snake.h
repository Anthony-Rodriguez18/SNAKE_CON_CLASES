/*Grupo: El profesor y las chicas super poderosas        CIENCIA DE LA COMPUTACIÓN I  CCOMP2-1
INTEGRANTES:
- Josue Carpio
- Ariana Leon
- Anthony Rodriguez */
#ifndef SNAKE_H_
#define SNAKE_H_

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };

enum KeyboardType { WASD = 0, IJKL };
enum SnakeType {snake1='@', snake2='&'};

class Snake
{
    protected:
        const KeyboardType keyboardType;
		const SnakeType TypeSnake;

        int x;
        int y;
		int live;
		int score;
		int choques;
        Direction direction;

        int nTail;
        int tailX[TAIL_SIZE];
        int tailY[TAIL_SIZE];

    public:
        Snake(KeyboardType,SnakeType);
        ~Snake();

        int getX() { return this->x; }
        int getY() { return this->y; }
		int getLIVE() { return this->live; }
		int getSCORE() { return this->score; }
		int getColision() { return this->choques; }
        Direction getDirection() { return this->direction; }
		SnakeType getSnakeType() { return this->TypeSnake; }
        int getNTail() { return this->nTail; }
        int* getTailX() { return this->tailX; }
        int* getTailY() { return this->tailY; }

        void setX(int x_) { this->x = x_; }
        void setY(int y_) { this->y = y_; }
		void setLIVE(int live_) { this->live = live_; }
		void setSCORE(int score_) { this->score = score_; }
		void setColision(int choque_) { this->choques= choque_; }
        void setDirection(Direction direction_) { this->direction = direction_; }
        void setNTail(int nTail_) { this->nTail = nTail_; }

        void menu();
		void move();
        void keyPressEvent();
};

#endif
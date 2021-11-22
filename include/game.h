/*Grupo: El profesor y las chicas super poderosas        CIENCIA DE LA COMPUTACIÓN I  CCOMP2-1
INTEGRANTES:
- Josue Carpio
- Ariana Leon
- Anthony Rodriguez */
enum GameState { GAME, END };

class Game
{
    protected:
        const int width;
        const int height;
		double velocidad;
		int a;

        GameState state;

        std::vector<Snake *> snakes;

        Map *map;

    public:
        Game(int, int);
        ~Game();

        //void configure();
        void init();
        void play();
        void finish();
		void menu();
        void events();
};
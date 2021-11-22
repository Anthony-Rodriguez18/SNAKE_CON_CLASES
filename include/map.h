/*Grupo: El profesor y las chicas super poderosas        CIENCIA DE LA COMPUTACIÓN I  CCOMP2-1
INTEGRANTES:
- Josue Carpio
- Ariana Leon
- Anthony Rodriguez */
class Map
{
    protected:
        std::vector<Snake *> snakes;

        int fruitX;
        int fruitY;

    public:
        Map();
        ~Map();

        void setSnakes(std::vector<Snake *> snakes_) { this->snakes = snakes_; }

        void draw();
        void generateTail();
        void generateFruit();
        bool collision();
};
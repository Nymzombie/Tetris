class Squares
{
public:
    int id = -100; // Kolejna liczba porz¹dkowa
    int active = -100; // 0 - Figura spada; 1 - Figura spad³a
    int x_cord = -100; // Okreœla pozycjê X figury (1-10)
    int y_cord = -100; // Okreœla pozycjê Y figury (1-20)
    int color = -100; // Okreœla kolor figury (tylko efekt wizualny)
    int main_block = 0; // Okresla, czy blok jest elementem osi obrotu figury
    int figure_type = 0; // Okreœla jaki to typ figury
};
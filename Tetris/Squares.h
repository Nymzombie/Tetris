class Squares
{
public:
    int id = -100; // Kolejna liczba porz�dkowa
    int active = -100; // 0 - Figura spada; 1 - Figura spad�a
    int x_cord = -100; // Okre�la pozycj� X figury (1-10)
    int y_cord = -100; // Okre�la pozycj� Y figury (1-20)
    int color = -100; // Okre�la kolor figury (tylko efekt wizualny)
    int main_block = 0; // Okresla, czy blok jest elementem osi obrotu figury
    int figure_type = 0; // Okre�la jaki to typ figury
};
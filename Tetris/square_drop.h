class square_drop {
public:

    void clear_row(int& score, std::unique_ptr<std::vector<Squares>>& objects_ptr)
    {
        int temp_tab[22] = {}; // Zapas dlugosci 2, poniewaz blok moze pojawic sie ponad plansza (ycord > 20), wowczas program by sie crashowal

        for (int i = 0; i < (*objects_ptr).size(); i++)
        {
            if ((*objects_ptr)[i].active == 1)
            {
                temp_tab[(*objects_ptr)[i].y_cord]++;
            }
        }
        for (int i = 0; i < 20; i++)
        {
            if (temp_tab[i] == 10)
            {
                for (int j = static_cast<int>((*objects_ptr).size()) - 1; j >= 0; j--)
                {
                    if ((*objects_ptr)[j].y_cord == i)
                    {
                        
                        (*objects_ptr).erase((*objects_ptr).begin() + j);

                    }
                    else if ((*objects_ptr)[j].y_cord > i)
                    {
                        (*objects_ptr)[j].y_cord--;
                    }
                }
                score += 10;
                clear_row(score, objects_ptr);
                break;
            }
        }
    }

    void every_tick_drop(int& score, int& game, std::unique_ptr<std::vector<Squares>>& objects_ptr)
    {
        int dropped = 0;
        int counter = 0;
        int movable_square[4] = {};

        for (int i = 0; i < (*objects_ptr).size(); i++)
        {
            if ((*objects_ptr)[i].active == 0)
            {
                movable_square[counter] = i;
                counter++;
            }
        }

        for (int i = 0; i < 4; i++)
        {
            if ((*objects_ptr)[movable_square[i]].y_cord == 1)
            {
                dropped = 1;
            }
        }

        if (dropped == 0)
        {
            for (int j = 0; j < (*objects_ptr).size(); j++)
            {
                if ((*objects_ptr)[j].active == 1)
                {
                    for (int i = 0; i < 4; i++)
                    {
                        if ((*objects_ptr)[movable_square[i]].y_cord - 1 == (*objects_ptr)[j].y_cord && (*objects_ptr)[movable_square[i]].x_cord == (*objects_ptr)[j].x_cord)
                        {
                            dropped = 1;
                        }
                    }
                }
            }
            for (int i = 0; i < 4; i++)
            {
                if ((*objects_ptr)[movable_square[i]].y_cord == 1)
                {
                    dropped = 1;
                }
            }

        }
        if (dropped == 0)
        {
            for (int i = 0; i < 4; i++)
            {
                (*objects_ptr)[movable_square[i]].y_cord--;
            }
        }

        else if (dropped == 1)
        {
            for (int i = 0; i < 4; i++)
            {
                (*objects_ptr)[movable_square[i]].active = 1;
            }
            clear_row(score, objects_ptr);
            Generate_figure().generate_figure(game, objects_ptr);
        }
    }
};
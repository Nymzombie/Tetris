class Square_move {
public:
    void square_move_left(std::unique_ptr<std::vector<Squares>>& objects_ptr)
    {
        int counter = 0;
        int movable_square[4] = {};
        int unable = 0;

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
            if ((*objects_ptr)[movable_square[i]].x_cord == 1)
            {
                unable = 1;
            }
        }

        if (unable == 0)
        {
            for (int j = 0; j < (*objects_ptr).size(); j++)
            {
                if ((*objects_ptr)[j].active == 1)
                {
                    for (int i = 0; i < 4; i++)
                    {
                        if ((*objects_ptr)[movable_square[i]].x_cord - 1 == (*objects_ptr)[j].x_cord && (*objects_ptr)[movable_square[i]].y_cord == (*objects_ptr)[j].y_cord)
                        {
                            unable = 1;
                        }
                    }
                }
            }
        }
        if (unable == 0)
        {
            for (int i = 0; i < 4; i++)
            {
                (*objects_ptr)[movable_square[i]].x_cord--;
            }
        }
    }

    void square_move_right(std::unique_ptr<std::vector<Squares>>& objects_ptr)
    {
        int counter = 0;
        int movable_square[4] = {};
        int unable = 0;

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
            if ((*objects_ptr)[movable_square[i]].x_cord == 10)
            {
                unable = 1;
            }
        }

        if (unable == 0)
        {
            for (int j = 0; j < (*objects_ptr).size(); j++)
            {
                if ((*objects_ptr)[j].active == 1)
                {
                    for (int i = 0; i < 4; i++)
                    {
                        if ((*objects_ptr)[movable_square[i]].x_cord + 1 == (*objects_ptr)[j].x_cord && (*objects_ptr)[movable_square[i]].y_cord == (*objects_ptr)[j].y_cord)
                        {
                            unable = 1;
                        }
                    }
                }
            }
        }
        if (unable == 0)
        {
            for (int i = 0; i < 4; i++)
            {
                (*objects_ptr)[movable_square[i]].x_cord++;
            }
        }
    }

    void square_rotate_counterclockwise(std::unique_ptr<std::vector<Squares>>& objects_ptr)
    {
        int counter = 0;
        int movable_square[4] = {};
        int unable = 0;
        int figure = 0;
        int main_figure = -1;
        int collision = 0;


        for (int i = 0; i < (*objects_ptr).size(); i++)
        {
            if ((*objects_ptr)[i].active == 0)
            {
                if ((*objects_ptr)[i].main_block == 1)
                {
                    main_figure = i;
                }

                movable_square[counter] = i;
                counter++;
            }
        }

        if ((*objects_ptr)[main_figure].x_cord == 1 || (*objects_ptr)[main_figure].x_cord == 10 || (*objects_ptr)[main_figure].y_cord == 1 || (*objects_ptr)[main_figure].y_cord == 20)
        {
            collision = 1;
        }

        figure = (*objects_ptr)[movable_square[0]].figure_type;


        if (figure == 1 || figure == 4 || figure == 5 || figure == 6 || figure == 7)
        {
            for (int i = 0; i < (*objects_ptr).size(); i++)
            {
                if ((*objects_ptr)[i].x_cord - 1 == (*objects_ptr)[main_figure].x_cord ||
                    (*objects_ptr)[i].x_cord + 1 == (*objects_ptr)[main_figure].x_cord ||
                    (*objects_ptr)[i].x_cord == (*objects_ptr)[main_figure].x_cord)
                {
                    for (int j = 0; j < 20; j++)
                    {
                        if ((*objects_ptr)[i].y_cord - 1 == (*objects_ptr)[main_figure].y_cord ||
                            (*objects_ptr)[i].y_cord + 1 == (*objects_ptr)[main_figure].y_cord ||
                            (*objects_ptr)[i].y_cord == (*objects_ptr)[main_figure].y_cord)
                        {
                            if ((*objects_ptr)[i].active == 1)
                            {
                                collision = 1;
                                break;
                            }
                        }
                    }
                }
            }


            if (collision == 0)
            {
                for (int i = 0; i < 4; i++)
                {

                    if ((*objects_ptr)[movable_square[i]].x_cord + 1 == (*objects_ptr)[main_figure].x_cord && (*objects_ptr)[movable_square[i]].y_cord == (*objects_ptr)[main_figure].y_cord)
                    {
                        (*objects_ptr)[movable_square[i]].x_cord++;
                        (*objects_ptr)[movable_square[i]].y_cord--;
                    }
                    else if ((*objects_ptr)[movable_square[i]].x_cord == (*objects_ptr)[main_figure].x_cord && (*objects_ptr)[movable_square[i]].y_cord + 1 == (*objects_ptr)[main_figure].y_cord)
                    {
                        (*objects_ptr)[movable_square[i]].x_cord++;
                        (*objects_ptr)[movable_square[i]].y_cord++;
                    }
                    else if ((*objects_ptr)[movable_square[i]].x_cord - 1 == (*objects_ptr)[main_figure].x_cord && (*objects_ptr)[movable_square[i]].y_cord == (*objects_ptr)[main_figure].y_cord)
                    {
                        (*objects_ptr)[movable_square[i]].x_cord--;
                        (*objects_ptr)[movable_square[i]].y_cord++;
                    }
                    else if ((*objects_ptr)[movable_square[i]].x_cord == (*objects_ptr)[main_figure].x_cord && (*objects_ptr)[movable_square[i]].y_cord - 1 == (*objects_ptr)[main_figure].y_cord)
                    {
                        (*objects_ptr)[movable_square[i]].x_cord--;
                        (*objects_ptr)[movable_square[i]].y_cord--;
                    }
                    if ((*objects_ptr)[movable_square[i]].x_cord + 1 == (*objects_ptr)[main_figure].x_cord && (*objects_ptr)[movable_square[i]].y_cord + 1 == (*objects_ptr)[main_figure].y_cord)
                    {
                        (*objects_ptr)[movable_square[i]].x_cord += 2;
                    }
                    else if ((*objects_ptr)[movable_square[i]].x_cord + 1 == (*objects_ptr)[main_figure].x_cord && (*objects_ptr)[movable_square[i]].y_cord - 1 == (*objects_ptr)[main_figure].y_cord)
                    {
                        (*objects_ptr)[movable_square[i]].y_cord -= 2;
                    }
                    else if ((*objects_ptr)[movable_square[i]].x_cord - 1 == (*objects_ptr)[main_figure].x_cord && (*objects_ptr)[movable_square[i]].y_cord - 1 == (*objects_ptr)[main_figure].y_cord)
                    {
                        (*objects_ptr)[movable_square[i]].x_cord -= 2;
                    }
                    else if ((*objects_ptr)[movable_square[i]].x_cord - 1 == (*objects_ptr)[main_figure].x_cord && (*objects_ptr)[movable_square[i]].y_cord + 1 == (*objects_ptr)[main_figure].y_cord)
                    {
                        (*objects_ptr)[movable_square[i]].y_cord += 2;
                    }
                }
            }
        }
        else if (figure == 2)
        {
            int colission = 0;
            int figure_type = 0;
            for (int i = 0; i < 4; i++)
            {
                if ((*objects_ptr)[movable_square[i]].x_cord + 2 == (*objects_ptr)[main_figure].x_cord)
                {
                    if (1 > (*objects_ptr)[main_figure].y_cord - 2 ||
                        20 < (*objects_ptr)[main_figure].y_cord - 2 ||
                        1 > (*objects_ptr)[main_figure].y_cord + 1 ||
                        20 < (*objects_ptr)[main_figure].y_cord + 1)
                    {
                        colission = 1;
                    }

                    figure_type = 1;
                    for (int j = 0; j < (*objects_ptr).size(); j++)
                    {
                        if ((*objects_ptr)[j].x_cord == (*objects_ptr)[main_figure].x_cord)
                        {
                            if ((*objects_ptr)[j].y_cord == (*objects_ptr)[main_figure].y_cord - 2 ||
                                (*objects_ptr)[j].y_cord == (*objects_ptr)[main_figure].y_cord - 1 ||
                                (*objects_ptr)[j].y_cord == (*objects_ptr)[main_figure].y_cord ||
                                (*objects_ptr)[j].y_cord == (*objects_ptr)[main_figure].y_cord + 1)
                            {
                                if ((*objects_ptr)[j].active == 1)
                                {
                                    colission = 1;
                                }
                            }
                        }
                    }
                }
                else if ((*objects_ptr)[movable_square[i]].y_cord + 2 == (*objects_ptr)[main_figure].y_cord)
                {
                    if (1 > (*objects_ptr)[main_figure].x_cord - 1 ||
                        10 < (*objects_ptr)[main_figure].x_cord - 1 ||
                        1 > (*objects_ptr)[main_figure].x_cord + 2 ||
                        10 < (*objects_ptr)[main_figure].x_cord + 2)
                    {
                        colission = 1;
                    }
                    figure_type = 2;
                    for (int j = 0; j < (*objects_ptr).size(); j++)
                    {
                        if ((*objects_ptr)[j].y_cord == (*objects_ptr)[main_figure].y_cord)
                        {
                            if ((*objects_ptr)[j].x_cord == (*objects_ptr)[main_figure].y_cord - 1 ||
                                (*objects_ptr)[j].x_cord == (*objects_ptr)[main_figure].y_cord ||
                                (*objects_ptr)[j].x_cord == (*objects_ptr)[main_figure].y_cord + 1 ||
                                (*objects_ptr)[j].x_cord == (*objects_ptr)[main_figure].y_cord + 2)
                            {
                                if ((*objects_ptr)[j].active == 1)
                                {
                                    colission = 1;
                                }
                            }
                        }
                    }
                }
                else if ((*objects_ptr)[movable_square[i]].x_cord - 2 == (*objects_ptr)[main_figure].x_cord)
                {
                    if (1 > (*objects_ptr)[main_figure].y_cord + 2 ||
                        20 < (*objects_ptr)[main_figure].y_cord + 2 ||
                        1 > (*objects_ptr)[main_figure].y_cord - 1 ||
                        20 < (*objects_ptr)[main_figure].y_cord - 1)
                    {
                        colission = 1;
                    }
                    figure_type = 3;
                    for (int j = 0; j < (*objects_ptr).size(); j++)
                    {
                        if ((*objects_ptr)[j].y_cord == (*objects_ptr)[main_figure].y_cord)
                        {
                            if ((*objects_ptr)[j].y_cord == (*objects_ptr)[main_figure].y_cord - 1 ||
                                (*objects_ptr)[j].y_cord == (*objects_ptr)[main_figure].y_cord ||
                                (*objects_ptr)[j].y_cord == (*objects_ptr)[main_figure].y_cord + 1 ||
                                (*objects_ptr)[j].y_cord == (*objects_ptr)[main_figure].y_cord + 2)
                            {
                                if ((*objects_ptr)[j].active == 1)
                                {
                                    colission = 1;
                                }
                            }
                        }
                    }
                }
                else if ((*objects_ptr)[movable_square[i]].y_cord - 2 == (*objects_ptr)[main_figure].y_cord)
                {
                    if (1 > (*objects_ptr)[main_figure].x_cord - 2 ||
                        10 < (*objects_ptr)[main_figure].x_cord - 2 ||
                        1 > (*objects_ptr)[main_figure].x_cord + 1 ||
                        10 < (*objects_ptr)[main_figure].x_cord + 1)
                    {
                        colission = 1;
                    }
                    figure_type = 4;
                    for (int j = 0; j < 200; j++)
                    {
                        if ((*objects_ptr)[j].x_cord == (*objects_ptr)[main_figure].x_cord)
                        {
                            if ((*objects_ptr)[j].x_cord == (*objects_ptr)[main_figure].y_cord - 2 ||
                                (*objects_ptr)[j].x_cord == (*objects_ptr)[main_figure].y_cord - 1 ||
                                (*objects_ptr)[j].x_cord == (*objects_ptr)[main_figure].y_cord ||
                                (*objects_ptr)[j].x_cord == (*objects_ptr)[main_figure].y_cord + 1)
                            {
                                if ((*objects_ptr)[j].active == 1)
                                {
                                    colission = 1;
                                }
                            }
                        }
                    }
                }
            }

            if (colission == 0)
            {
                for (int i = 0; i < 4; i++)
                {
                    if ((*objects_ptr)[movable_square[i]].x_cord + 2 == (*objects_ptr)[main_figure].x_cord)
                    {
                        (*objects_ptr)[movable_square[i]].x_cord += 2;
                        (*objects_ptr)[movable_square[i]].y_cord -= 2;
                    }
                    else if ((*objects_ptr)[movable_square[i]].y_cord + 2 == (*objects_ptr)[main_figure].y_cord)
                    {
                        (*objects_ptr)[movable_square[i]].x_cord += 2;
                        (*objects_ptr)[movable_square[i]].y_cord += 2;
                    }
                    else if ((*objects_ptr)[movable_square[i]].x_cord - 2 == (*objects_ptr)[main_figure].x_cord)
                    {
                        (*objects_ptr)[movable_square[i]].x_cord -= 2;
                        (*objects_ptr)[movable_square[i]].y_cord += 2;
                    }
                    else if ((*objects_ptr)[movable_square[i]].y_cord - 2 == (*objects_ptr)[main_figure].y_cord)
                    {
                        (*objects_ptr)[movable_square[i]].x_cord -= 2;
                        (*objects_ptr)[movable_square[i]].y_cord -= 2;
                    }



                    if ((*objects_ptr)[movable_square[i]].x_cord + 1 == (*objects_ptr)[main_figure].x_cord)
                    {
                        (*objects_ptr)[movable_square[i]].x_cord += 1;
                        (*objects_ptr)[movable_square[i]].y_cord -= 1;
                    }
                    else if ((*objects_ptr)[movable_square[i]].y_cord + 1 == (*objects_ptr)[main_figure].y_cord)
                    {
                        (*objects_ptr)[movable_square[i]].x_cord += 1;
                        (*objects_ptr)[movable_square[i]].y_cord += 1;
                    }
                    else if ((*objects_ptr)[movable_square[i]].x_cord - 1 == (*objects_ptr)[main_figure].x_cord)
                    {
                        (*objects_ptr)[movable_square[i]].x_cord -= 1;
                        (*objects_ptr)[movable_square[i]].y_cord += 1;
                    }
                    else if ((*objects_ptr)[movable_square[i]].y_cord - 1 == (*objects_ptr)[main_figure].y_cord)
                    {
                        (*objects_ptr)[movable_square[i]].x_cord -= 1;
                        (*objects_ptr)[movable_square[i]].y_cord -= 1;
                    }
                }
            }
        }
    }

    void square_rotate_clockwise(std::unique_ptr<std::vector<Squares>>& objects_ptr)
    {
        int counter = 0;
        int movable_square[4] = {};
        int unable = 0;
        int figure = 0;
        int main_figure = -1;
        int collision = 0;


        for (int i = 0; i < (*objects_ptr).size(); i++)
        {
            if ((*objects_ptr)[i].active == 0)
            {
                if ((*objects_ptr)[i].main_block == 1)
                {
                    main_figure = i;
                }

                movable_square[counter] = i;
                counter++;
            }
        }

        if ((*objects_ptr)[main_figure].x_cord == 1 || (*objects_ptr)[main_figure].x_cord == 10 || (*objects_ptr)[main_figure].y_cord == 1 || (*objects_ptr)[main_figure].y_cord == 20)
        {
            collision = 1;
        }

        figure = (*objects_ptr)[movable_square[0]].figure_type;


        if (figure == 1 || figure == 4 || figure == 5 || figure == 6 || figure == 7)
        {
            for (int i = 0; i < 200; i++)
            {
                if ((*objects_ptr)[i].x_cord - 1 == (*objects_ptr)[main_figure].x_cord ||
                    (*objects_ptr)[i].x_cord + 1 == (*objects_ptr)[main_figure].x_cord ||
                    (*objects_ptr)[i].x_cord == (*objects_ptr)[main_figure].x_cord)
                {
                    for (int j = 0; j < 20; j++)
                    {
                        if ((*objects_ptr)[i].y_cord - 1 == (*objects_ptr)[main_figure].y_cord ||
                            (*objects_ptr)[i].y_cord + 1 == (*objects_ptr)[main_figure].y_cord ||
                            (*objects_ptr)[i].y_cord == (*objects_ptr)[main_figure].y_cord)
                        {
                            if ((*objects_ptr)[i].active == 1)
                            {
                                collision = 1;
                                break;
                            }
                        }
                    }
                }
            }


            if (collision == 0)
            {

                for (int i = 0; i < 4; i++)
                {
                    if ((*objects_ptr)[movable_square[i]].x_cord + 1 == (*objects_ptr)[main_figure].x_cord && (*objects_ptr)[movable_square[i]].y_cord == (*objects_ptr)[main_figure].y_cord)
                    {
                        (*objects_ptr)[movable_square[i]].x_cord++;
                        (*objects_ptr)[movable_square[i]].y_cord++;
                    }
                    else if ((*objects_ptr)[movable_square[i]].x_cord == (*objects_ptr)[main_figure].x_cord && (*objects_ptr)[movable_square[i]].y_cord + 1 == (*objects_ptr)[main_figure].y_cord)
                    {
                        (*objects_ptr)[movable_square[i]].x_cord--;
                        (*objects_ptr)[movable_square[i]].y_cord++;
                    }
                    else if ((*objects_ptr)[movable_square[i]].x_cord - 1 == (*objects_ptr)[main_figure].x_cord && (*objects_ptr)[movable_square[i]].y_cord == (*objects_ptr)[main_figure].y_cord)
                    {
                        (*objects_ptr)[movable_square[i]].x_cord--;
                        (*objects_ptr)[movable_square[i]].y_cord--;
                    }
                    else if ((*objects_ptr)[movable_square[i]].x_cord == (*objects_ptr)[main_figure].x_cord && (*objects_ptr)[movable_square[i]].y_cord - 1 == (*objects_ptr)[main_figure].y_cord)
                    {
                        (*objects_ptr)[movable_square[i]].x_cord++;
                        (*objects_ptr)[movable_square[i]].y_cord--;
                    }
                    if ((*objects_ptr)[movable_square[i]].x_cord + 1 == (*objects_ptr)[main_figure].x_cord && (*objects_ptr)[movable_square[i]].y_cord + 1 == (*objects_ptr)[main_figure].y_cord)
                    {
                        (*objects_ptr)[movable_square[i]].y_cord += 2;
                    }
                    else if ((*objects_ptr)[movable_square[i]].x_cord + 1 == (*objects_ptr)[main_figure].x_cord && (*objects_ptr)[movable_square[i]].y_cord - 1 == (*objects_ptr)[main_figure].y_cord)
                    {
                        (*objects_ptr)[movable_square[i]].x_cord += 2;
                    }
                    else if ((*objects_ptr)[movable_square[i]].x_cord - 1 == (*objects_ptr)[main_figure].x_cord && (*objects_ptr)[movable_square[i]].y_cord - 1 == (*objects_ptr)[main_figure].y_cord)
                    {
                        (*objects_ptr)[movable_square[i]].y_cord -= 2;
                    }
                    else if ((*objects_ptr)[movable_square[i]].x_cord - 1 == (*objects_ptr)[main_figure].x_cord && (*objects_ptr)[movable_square[i]].y_cord + 1 == (*objects_ptr)[main_figure].y_cord)
                    {
                        (*objects_ptr)[movable_square[i]].x_cord -= 2;
                    }
                }
            }
        }
        else if (figure == 2)
        {
            int colission = 0;
            int figure_type = 0;
            for (int i = 0; i < 4; i++)
            {
                if ((*objects_ptr)[movable_square[i]].x_cord + 2 == (*objects_ptr)[main_figure].x_cord)
                {
                    if (1 > (*objects_ptr)[main_figure].y_cord + 2 ||
                        20 < (*objects_ptr)[main_figure].y_cord + 2 ||
                        1 > (*objects_ptr)[main_figure].y_cord - 1 ||
                        20 < (*objects_ptr)[main_figure].y_cord - 1)
                    {
                        colission = 1;
                    }

                    figure_type = 1;
                    for (int j = 0; j < (*objects_ptr).size(); j++)
                    {
                        if ((*objects_ptr)[j].x_cord == (*objects_ptr)[main_figure].x_cord)
                        {
                            if ((*objects_ptr)[j].y_cord == (*objects_ptr)[main_figure].y_cord + 2 ||
                                (*objects_ptr)[j].y_cord == (*objects_ptr)[main_figure].y_cord + 1 ||
                                (*objects_ptr)[j].y_cord == (*objects_ptr)[main_figure].y_cord ||
                                (*objects_ptr)[j].y_cord == (*objects_ptr)[main_figure].y_cord - 1)
                            {
                                if ((*objects_ptr)[j].active == 1)
                                {
                                    colission = 1;
                                }
                            }
                        }
                    }
                }
                else if ((*objects_ptr)[movable_square[i]].y_cord + 2 == (*objects_ptr)[main_figure].y_cord)
                {
                    if (1 > (*objects_ptr)[main_figure].x_cord - 2 ||
                        10 < (*objects_ptr)[main_figure].x_cord - 2 ||
                        1 > (*objects_ptr)[main_figure].x_cord + 1 ||
                        10 < (*objects_ptr)[main_figure].x_cord + 1)
                    {
                        colission = 1;
                    }
                    figure_type = 2;
                    for (int j = 0; j < (*objects_ptr).size(); j++)
                    {
                        if ((*objects_ptr)[j].y_cord == (*objects_ptr)[main_figure].y_cord)
                        {
                            if ((*objects_ptr)[j].x_cord == (*objects_ptr)[main_figure].y_cord + 1 ||
                                (*objects_ptr)[j].x_cord == (*objects_ptr)[main_figure].y_cord ||
                                (*objects_ptr)[j].x_cord == (*objects_ptr)[main_figure].y_cord - 1 ||
                                (*objects_ptr)[j].x_cord == (*objects_ptr)[main_figure].y_cord - 2)
                            {
                                if ((*objects_ptr)[j].active == 1)
                                {
                                    colission = 1;
                                }
                            }
                        }
                    }
                }
                else if ((*objects_ptr)[movable_square[i]].x_cord - 2 == (*objects_ptr)[main_figure].x_cord)
                {
                    if (1 > (*objects_ptr)[main_figure].y_cord - 2 ||
                        20 < (*objects_ptr)[main_figure].y_cord - 2 ||
                        1 > (*objects_ptr)[main_figure].y_cord + 1 ||
                        20 < (*objects_ptr)[main_figure].y_cord + 1)
                    {
                        colission = 1;
                    }
                    figure_type = 3;
                    for (int j = 0; j < (*objects_ptr).size(); j++)
                    {
                        if ((*objects_ptr)[j].y_cord == (*objects_ptr)[main_figure].y_cord)
                        {
                            if ((*objects_ptr)[j].y_cord == (*objects_ptr)[main_figure].y_cord + 1 ||
                                (*objects_ptr)[j].y_cord == (*objects_ptr)[main_figure].y_cord ||
                                (*objects_ptr)[j].y_cord == (*objects_ptr)[main_figure].y_cord - 1 ||
                                (*objects_ptr)[j].y_cord == (*objects_ptr)[main_figure].y_cord - 2)
                            {
                                if ((*objects_ptr)[j].active == 1)
                                {
                                    colission = 1;
                                }
                            }
                        }
                    }
                }
                else if ((*objects_ptr)[movable_square[i]].y_cord - 2 == (*objects_ptr)[main_figure].y_cord)
                {
                    if (1 > (*objects_ptr)[main_figure].x_cord - 1 ||
                        10 < (*objects_ptr)[main_figure].x_cord - 1 ||
                        1 > (*objects_ptr)[main_figure].x_cord + 2 ||
                        10 < (*objects_ptr)[main_figure].x_cord + 2)
                    {
                        colission = 1;
                    }
                    figure_type = 4;
                    for (int j = 0; j < (*objects_ptr).size(); j++)
                    {
                        if ((*objects_ptr)[j].x_cord == (*objects_ptr)[main_figure].x_cord)
                        {
                            if ((*objects_ptr)[j].x_cord == (*objects_ptr)[main_figure].y_cord + 2 ||
                                (*objects_ptr)[j].x_cord == (*objects_ptr)[main_figure].y_cord + 1 ||
                                (*objects_ptr)[j].x_cord == (*objects_ptr)[main_figure].y_cord ||
                                (*objects_ptr)[j].x_cord == (*objects_ptr)[main_figure].y_cord - 1)
                            {
                                if ((*objects_ptr)[j].active == 1)
                                {
                                    colission = 1;
                                }
                            }
                        }
                    }
                }
            }

            if (colission == 0)
            {
                for (int i = 0; i < 4; i++)
                {
                    if ((*objects_ptr)[movable_square[i]].x_cord + 2 == (*objects_ptr)[main_figure].x_cord)
                    {
                        (*objects_ptr)[movable_square[i]].x_cord += 2;
                        (*objects_ptr)[movable_square[i]].y_cord += 2;
                    }
                    else if ((*objects_ptr)[movable_square[i]].y_cord + 2 == (*objects_ptr)[main_figure].y_cord)
                    {
                        (*objects_ptr)[movable_square[i]].x_cord -= 2;
                        (*objects_ptr)[movable_square[i]].y_cord += 2;
                    }
                    else if ((*objects_ptr)[movable_square[i]].x_cord - 2 == (*objects_ptr)[main_figure].x_cord)
                    {
                        (*objects_ptr)[movable_square[i]].x_cord -= 2;
                        (*objects_ptr)[movable_square[i]].y_cord -= 2;
                    }
                    else if ((*objects_ptr)[movable_square[i]].y_cord - 2 == (*objects_ptr)[main_figure].y_cord)
                    {
                        (*objects_ptr)[movable_square[i]].x_cord += 2;
                        (*objects_ptr)[movable_square[i]].y_cord -= 2;
                    }



                    if ((*objects_ptr)[movable_square[i]].x_cord + 1 == (*objects_ptr)[main_figure].x_cord)
                    {
                        (*objects_ptr)[movable_square[i]].x_cord += 1;
                        (*objects_ptr)[movable_square[i]].y_cord += 1;
                    }
                    else if ((*objects_ptr)[movable_square[i]].y_cord + 1 == (*objects_ptr)[main_figure].y_cord)
                    {
                        (*objects_ptr)[movable_square[i]].x_cord -= 1;
                        (*objects_ptr)[movable_square[i]].y_cord += 1;
                    }
                    else if ((*objects_ptr)[movable_square[i]].x_cord - 1 == (*objects_ptr)[main_figure].x_cord)
                    {
                        (*objects_ptr)[movable_square[i]].x_cord -= 1;
                        (*objects_ptr)[movable_square[i]].y_cord -= 1;
                    }
                    else if ((*objects_ptr)[movable_square[i]].y_cord - 1 == (*objects_ptr)[main_figure].y_cord)
                    {
                        (*objects_ptr)[movable_square[i]].x_cord += 1;
                        (*objects_ptr)[movable_square[i]].y_cord -= 1;
                    }
                }
            }
        }
    }
};
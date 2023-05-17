class Generate_figure {
public:
    void generate_figure(int& game, std::unique_ptr<std::vector<Squares>>& objects_ptr)
    {
        bool already_lost = 0;
        for (int i = 0; i < (*objects_ptr).size(); i++)
        {
            if ((*objects_ptr)[i].x_cord == 4 && (*objects_ptr)[i].y_cord == 20 ||
                (*objects_ptr)[i].x_cord == 5 && (*objects_ptr)[i].y_cord == 20 ||
                (*objects_ptr)[i].x_cord == 5 && (*objects_ptr)[i].y_cord == 19 ||
                (*objects_ptr)[i].x_cord == 6 && (*objects_ptr)[i].y_cord == 20 ||
                (*objects_ptr)[i].x_cord == 6 && (*objects_ptr)[i].y_cord == 19 ||
                (*objects_ptr)[i].x_cord == 7 && (*objects_ptr)[i].y_cord == 20)
            {
                already_lost = 1;
                game = 1;
            }
        }

        if (already_lost == false)
        {
            srand(static_cast<unsigned int>(time(NULL)));
            int number = (rand() % 7) + 1;

            int loop_counter = 0;



            for (int i = 0; i < 4; i++)
            {
                int unused_slot = 0;

                objects_ptr->push_back({});
                objects_ptr->back().id = static_cast<int>(objects_ptr->size());
                objects_ptr->back().active = 0;
                objects_ptr->back().color = number;


                if (number == 1)
                {
                    if (loop_counter == 0)
                    {
                        objects_ptr->back().x_cord = 4;
                        objects_ptr->back().y_cord = 20;
                    }
                    else if (loop_counter == 1)
                    {
                        objects_ptr->back().x_cord = 5;
                        objects_ptr->back().y_cord = 20;
                        objects_ptr->back().main_block = 1;
                    }
                    else if (loop_counter == 2)
                    {
                        objects_ptr->back().x_cord = 6;
                        objects_ptr->back().y_cord = 20;
                    }
                    else if (loop_counter == 3)
                    {
                        objects_ptr->back().x_cord = 6;
                        objects_ptr->back().y_cord = 19;
                    }
                    objects_ptr->back().figure_type = number;
                    loop_counter++;
                }
                else if (number == 2)
                {
                    if (loop_counter == 0)
                    {
                        objects_ptr->back().x_cord = 4;
                        objects_ptr->back().y_cord = 20;
                    }
                    else if (loop_counter == 1)
                    {
                        objects_ptr->back().x_cord = 5;
                        objects_ptr->back().y_cord = 20;
                    }
                    else if (loop_counter == 2)
                    {
                        objects_ptr->back().x_cord = 6;
                        objects_ptr->back().y_cord = 20;
                        objects_ptr->back().main_block = 1;
                    }
                    else if (loop_counter == 3)
                    {
                        objects_ptr->back().x_cord = 7;
                        objects_ptr->back().y_cord = 20;
                    }
                    loop_counter++;
                    objects_ptr->back().figure_type = number;
                }
                else if (number == 3)
                {
                    if (loop_counter == 0)
                    {
                        objects_ptr->back().x_cord = 5;
                        objects_ptr->back().y_cord = 20;
                    }
                    else if (loop_counter == 1)
                    {
                        objects_ptr->back().x_cord = 6;
                        objects_ptr->back().y_cord = 20;
                    }
                    else if (loop_counter == 2)
                    {
                        objects_ptr->back().x_cord = 5;
                        objects_ptr->back().y_cord = 19;
                    }
                    else if (loop_counter == 3)
                    {
                        objects_ptr->back().x_cord = 6;
                        objects_ptr->back().y_cord = 19;
                    }
                    loop_counter++;
                    objects_ptr->back().figure_type = number;
                }
                else if (number == 4)
                {
                    if (loop_counter == 0)
                    {
                        objects_ptr->back().x_cord = 5;
                        objects_ptr->back().y_cord = 20;
                    }
                    else if (loop_counter == 1)
                    {
                        objects_ptr->back().x_cord = 5;
                        objects_ptr->back().y_cord = 19;
                    }
                    else if (loop_counter == 2)
                    {
                        objects_ptr->back().x_cord = 6;
                        objects_ptr->back().y_cord = 20;
                        objects_ptr->back().main_block = 1;
                    }
                    else if (loop_counter == 3)
                    {
                        objects_ptr->back().x_cord = 7;
                        objects_ptr->back().y_cord = 20;
                    }
                    loop_counter++;
                    objects_ptr->back().figure_type = number;
                }
                else if (number == 5)
                {
                    if (loop_counter == 0)
                    {
                        objects_ptr->back().x_cord = 4;
                        objects_ptr->back().y_cord = 20;
                    }
                    else if (loop_counter == 1)
                    {
                        objects_ptr->back().x_cord = 5;
                        objects_ptr->back().y_cord = 20;
                        objects_ptr->back().main_block = 1;
                    }
                    else if (loop_counter == 2)
                    {
                        objects_ptr->back().x_cord = 5;
                        objects_ptr->back().y_cord = 19;
                    }
                    else if (loop_counter == 3)
                    {
                        objects_ptr->back().x_cord = 6;
                        objects_ptr->back().y_cord = 19;
                    }
                    loop_counter++;
                    objects_ptr->back().figure_type = number;
                }
                else if (number == 6)
                {
                    if (loop_counter == 0)
                    {
                        objects_ptr->back().x_cord = 4;
                        objects_ptr->back().y_cord = 20;
                    }
                    else if (loop_counter == 1)
                    {
                        objects_ptr->back().x_cord = 5;
                        objects_ptr->back().y_cord = 20;
                        objects_ptr->back().main_block = 1;
                    }
                    else if (loop_counter == 2)
                    {
                        objects_ptr->back().x_cord = 6;
                        objects_ptr->back().y_cord = 20;
                    }
                    else if (loop_counter == 3)
                    {
                        objects_ptr->back().x_cord = 5;
                        objects_ptr->back().y_cord = 19;
                    }
                    loop_counter++;
                    objects_ptr->back().figure_type = number;
                }
                else if (number == 7)
                {
                    if (loop_counter == 0)
                    {
                        objects_ptr->back().x_cord = 5;
                        objects_ptr->back().y_cord = 19;
                    }
                    else if (loop_counter == 1)
                    {
                        objects_ptr->back().x_cord = 6;
                        objects_ptr->back().y_cord = 19;
                    }
                    else if (loop_counter == 2)
                    {
                        objects_ptr->back().x_cord = 6;
                        objects_ptr->back().y_cord = 20;
                        objects_ptr->back().main_block = 1;
                    }
                    else if (loop_counter == 3)
                    {
                        objects_ptr->back().x_cord = 7;
                        objects_ptr->back().y_cord = 20;
                    }
                    loop_counter++;
                    objects_ptr->back().figure_type = number;
                }
            }
        }
    }
};
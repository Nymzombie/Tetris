class game_main {
public:
    void start_The_game(sf::RenderWindow& window)
    {
        std::vector<Squares> objects_list = {};
        std::unique_ptr<std::vector<Squares>> objects_ptr = std::make_unique<std::vector<Squares>>(objects_list);

        int score = 0;
        int game = -1;
        int key_pressed = 0;
        int fps_counter = 0;

        sf::Event event;

        FreeConsole();

        std::chrono::milliseconds duration(50);
        std::this_thread::sleep_for(duration);


        while (window.isOpen())
        {
            while (window.pollEvent(event) || key_pressed == 0)
            {
                window.setPosition(sf::Vector2i(440, 0));

                window.clear();

                Drawing().draw_background(window);

                Drawing().draw_right_panel(window);

                Drawing().draw_score(window, score);

                Drawing().draw_intro(window);

                window.display();

                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }

                if (event.type == sf::Event::KeyPressed)
                {
                    key_pressed = 1;

                }

            }



            if (key_pressed == 1)
            {

                Generate_figure().generate_figure(game, objects_ptr);

                game = 0;


                // Glowna pêtla programu

                while (window.isOpen())
                {

                    sf::Event event;
                    while (window.pollEvent(event))
                    {
                        //obsluga zamkniecia
                        if (event.type == sf::Event::Closed)
                        {
                            window.close();
                        }

                        if (event.type == sf::Event::KeyPressed)
                        {
                            keyboard_handler().keyboard(event, score, game, window, objects_ptr);
                        }

                    }


                    window.clear();

                    Drawing().draw_background(window);

                    Drawing().draw_squares(window, objects_ptr);

                    Drawing().draw_right_panel(window);


                    if (game == 1)
                    {
                        key_pressed = 0;

                        while (window.pollEvent(event) || key_pressed == 0)
                        {
                            window.clear();

                            Drawing().draw_background(window);

                            Drawing().draw_right_panel(window);

                            Drawing().draw_score(window, score);

                            Drawing().draw_game_over(window);

                            window.display();


                            if (event.type == sf::Event::Closed)
                            {
                                window.close();
                            }

                            if (event.type == sf::Event::KeyPressed)
                            {
                                key_pressed = 1;
                            }

                        }

                        game_main().start_The_game(window);
                    }

                    Drawing().draw_score(window, score);

                    window.display();

                    if (game == 0)
                    {
                        Calculations().every_tick(score, game, objects_ptr);
                    }
                }
            }
        }
    }
};
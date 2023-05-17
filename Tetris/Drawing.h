class Drawing {

public:
    void draw_background(sf::RenderWindow& window)
    {
        sf::Texture background_tx;
        background_tx.loadFromFile("images/background.png");
        sf::Sprite background;
        background.setTexture(background_tx);

        window.draw(background);
    }

    void draw_squares(sf::RenderWindow& window, std::unique_ptr<std::vector<Squares>>& objects_ptr)
    {
        for (int i = 0; i < objects_ptr->size(); i++)
        {
            std::string image_path;

            if ((*objects_ptr)[i].color == 1)
            {
                image_path = "images/blue.png";
            }
            else if ((*objects_ptr)[i].color == 2)
            {
                image_path = "images/cyan.png";
            }
            else if ((*objects_ptr)[i].color == 3)
            {
                image_path = "images/yellow.png";
            }
            else if ((*objects_ptr)[i].color == 4)
            {
                image_path = "images/orange.png";
            }
            else if ((*objects_ptr)[i].color == 5)
            {
                image_path = "images/red.png";
            }
            else if ((*objects_ptr)[i].color == 6)
            {
                image_path = "images/purple.png";
            }
            else
            {
                image_path = "images/green.png";
            }

            int x_cord = (*objects_ptr)[i].x_cord;
            int y_cord = (*objects_ptr)[i].y_cord;

            int drawing_x_cord = (x_cord - 1) * 51 + 166;
            int drawing_y_cord = (20 - y_cord) * 51 + 10;

            sf::Texture texture;
            texture.loadFromFile(image_path);
            sf::Sprite sprite;
            sprite.setTexture(texture);

            sprite.setPosition(static_cast<float>(drawing_x_cord), static_cast<float>(drawing_y_cord));

            window.draw(sprite);
        }
    }

    void draw_score(sf::RenderWindow& window, int& score)
    {
        sf::Font font;
        font.loadFromFile("fonts/font.ttf");

        sf::Text score_txt;
        score_txt.setFont(font);
        score_txt.setCharacterSize(50);
        score_txt.setFillColor(sf::Color::White);
        score_txt.setString("Your Score:");
        score_txt.setPosition(750, 75);

        window.draw(score_txt);

        sf::Text score_txt2;
        score_txt2.setFont(font);
        score_txt2.setCharacterSize(50);
        score_txt2.setFillColor(sf::Color::White);
        score_txt2.setString(std::to_string(score));
        score_txt2.setPosition(750, 130);

        window.draw(score_txt2);

    }

    void draw_right_panel(sf::RenderWindow& window)
    {

        sf::Font font;
        font.loadFromFile("fonts/font.ttf");

        sf::Text controls_main;
        controls_main.setFont(font);
        controls_main.setCharacterSize(50);
        controls_main.setFillColor(sf::Color::White);
        controls_main.setString("CONTROLS");
        controls_main.setPosition(725, 300);

        window.draw(controls_main);

        sf::RectangleShape underline_1(sf::Vector2f(305, 3));
        underline_1.setFillColor(sf::Color::Yellow);
        underline_1.setPosition(700, 380);

        window.draw(underline_1);

        sf::Text line_controls_1;
        line_controls_1.setFont(font);
        line_controls_1.setCharacterSize(30);
        line_controls_1.setFillColor(sf::Color::White);
        line_controls_1.setString("A - Move left");
        line_controls_1.setPosition(700, 400);

        window.draw(line_controls_1);

        sf::Text line_controls_2;
        line_controls_2.setFont(font);
        line_controls_2.setCharacterSize(30);
        line_controls_2.setFillColor(sf::Color::White);
        line_controls_2.setString("D - Move right");
        line_controls_2.setPosition(700, 450);

        window.draw(line_controls_2);

        sf::Text line_controls_3;
        line_controls_3.setFont(font);
        line_controls_3.setCharacterSize(30);
        line_controls_3.setFillColor(sf::Color::White);
        line_controls_3.setString("Q - Rotate counterclokwise");
        line_controls_3.setPosition(700, 500);

        window.draw(line_controls_3);

        sf::Text line_controls_4;
        line_controls_4.setFont(font);
        line_controls_4.setCharacterSize(30);
        line_controls_4.setFillColor(sf::Color::White);
        line_controls_4.setString("E - Rotate clockwise");
        line_controls_4.setPosition(700, 550);

        window.draw(line_controls_4);

        sf::Text line_controls_5;
        line_controls_5.setFont(font);
        line_controls_5.setCharacterSize(30);
        line_controls_5.setFillColor(sf::Color::White);
        line_controls_5.setString("ESC - Quit the program");
        line_controls_5.setPosition(700, 600);

        window.draw(line_controls_5);

        sf::Text main_text;
        main_text.setFont(font);
        main_text.setCharacterSize(50);
        main_text.setFillColor(sf::Color::White);
        main_text.setString("Informations");
        main_text.setPosition(725, 700);

        window.draw(main_text);

        sf::RectangleShape underline(sf::Vector2f(305, 3));
        underline.setFillColor(sf::Color::Yellow);
        underline.setPosition(700, 780);

        window.draw(underline);

        sf::Text line1;
        line1.setFont(font);
        line1.setCharacterSize(30);
        line1.setFillColor(sf::Color::White);
        line1.setString("Final project");
        line1.setPosition(700, 800);

        window.draw(line1);

        sf::Text line2;
        line2.setFont(font);
        line2.setCharacterSize(30);
        line2.setFillColor(sf::Color::White);
        line2.setString("CYBERSECURITY");
        line2.setPosition(700, 850);

        window.draw(line2);

        sf::Text line3;
        line3.setFont(font);
        line3.setCharacterSize(30);
        line3.setFillColor(sf::Color::White);
        line3.setString("Wroclaw University");
        line3.setPosition(700, 900);

        window.draw(line3);

        sf::Text line4;
        line4.setFont(font);
        line4.setCharacterSize(30);
        line4.setFillColor(sf::Color::White);
        line4.setString("Of Science and Technology");
        line4.setPosition(700, 950);

        window.draw(line4);

    }

    void draw_game_over(sf::RenderWindow& window)
    {
        sf::Font font;
        font.loadFromFile("fonts/font.ttf");

        sf::Text game_over;
        game_over.setFont(font);
        game_over.setCharacterSize(170);
        game_over.setFillColor(sf::Color::White);
        game_over.setString("GAME");
        game_over.setPosition(200, 200);

        window.draw(game_over);

        sf::Text game_over_2;
        game_over_2.setFont(font);
        game_over_2.setCharacterSize(170);
        game_over_2.setFillColor(sf::Color::White);
        game_over_2.setString("OVER");
        game_over_2.setPosition(200, 420);

        window.draw(game_over_2);

    }

    void draw_intro(sf::RenderWindow& window)
    {
        static auto last_cast = std::chrono::high_resolution_clock::now();
        auto current_time = std::chrono::high_resolution_clock::now();
        auto from_last_cast = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - last_cast).count();

        last_cast = current_time;

        static int counter;
        counter += static_cast<int>(from_last_cast);

        std::string dots = "";

        if (counter >= 1300)
        {
            counter -= 1300;
        }
        else if (counter >= 1000)
        {
            dots = "...";
        }
        else if (counter >= 666)
        {
            dots = "..";
        }
        else if (counter >= 333)
        {
            dots = ".";
        }

        sf::Font font;
        font.loadFromFile("fonts/font.ttf");

        sf::Text Press;
        Press.setFont(font);
        Press.setCharacterSize(65);
        Press.setFillColor(sf::Color::White);
        Press.setString("Press any key");
        Press.setPosition(225, 350);

        window.draw(Press);

        sf::Text start;
        start.setFont(font);
        start.setCharacterSize(65);
        start.setFillColor(sf::Color::White);
        start.setString("To start the game" + dots);
        start.setPosition(175, 450);

        window.draw(start);



    }

};
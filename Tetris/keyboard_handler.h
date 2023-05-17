class keyboard_handler {
public:
    void keyboard(sf::Event event, int& score, int& game, sf::RenderWindow& window, std::unique_ptr<std::vector<Squares>>& objects_ptr)
    {
        if (game == 0)
        {
            if (event.key.code == sf::Keyboard::S)
                square_drop().every_tick_drop(score, game, objects_ptr);
            else if (event.key.code == sf::Keyboard::A)
                Square_move().square_move_left(objects_ptr);
            else if (event.key.code == sf::Keyboard::D)
                Square_move().square_move_right(objects_ptr);
            else if (event.key.code == sf::Keyboard::Q)
                Square_move().square_rotate_counterclockwise(objects_ptr);
            else if (event.key.code == sf::Keyboard::E)
                Square_move().square_rotate_clockwise(objects_ptr);
        }
        if (event.key.code == sf::Keyboard::Escape)
            window.close();
    }
};
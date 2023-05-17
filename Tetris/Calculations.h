class Calculations {
public:
    void every_tick(int& score, int& game, std::unique_ptr<std::vector<Squares>>& objects_ptr)
    {
        static int counter;
        if (game == 0)
        {
            static auto last_cast = std::chrono::high_resolution_clock::now();
            auto current_time = std::chrono::high_resolution_clock::now();
            auto from_last_cast = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - last_cast).count();

            last_cast = current_time;

            
            counter += static_cast<int>(from_last_cast);
            if (counter >= 250)
            {
                counter = 0;
            }
            else if (counter >= 150) {
                square_drop().every_tick_drop(score, game, objects_ptr);
                counter -= 150;
            }
        }
    }
};
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int BLOCK_SIZE = 32; // Kích thước mỗi khối
const int GRID_WIDTH = WINDOW_WIDTH / BLOCK_SIZE;
const int GRID_HEIGHT = WINDOW_HEIGHT / BLOCK_SIZE;

// Lớp đại diện cho một khối
enum BlockType { AIR, DIRT, STONE };
struct Block {
    BlockType type;
    sf::RectangleShape shape;
};

// Lớp đại diện cho người chơi
struct Player {
    sf::RectangleShape shape;
    float x, y;
    float speed = 200.0f; // Tốc độ di chuyển (pixel/giây)
};

int main() {
    // Tạo cửa sổ
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Minecraft 2D Simulation");
    window.setFramerateLimit(60);

    // Khởi tạo lưới thế giới
    std::vector<std::vector<Block>> world(GRID_HEIGHT, std::vector<Block>(GRID_WIDTH));
    for (int y = 0; y < GRID_HEIGHT; ++y) {
        for (int x = 0; x < GRID_WIDTH; ++x) {
            world[y][x].type = (y > GRID_HEIGHT / 2) ? DIRT : AIR;
            world[y][x].shape.setSize(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE));
            world[y][x].shape.setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE);
            if (world[y][x].type == DIRT) {
                world[y][x].shape.setFillColor(sf::Color(139, 69, 19)); // Màu đất
            } else {
                world[y][x].shape.setFillColor(sf::Color::Transparent); // Không khí
            }
        }
    }

    // Khởi tạo người chơi
    Player player;
    player.shape.setSize(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE));
    player.shape.setFillColor(sf::Color::Blue);
    player.x = WINDOW_WIDTH / 2.0f;
    player.y = WINDOW_HEIGHT / 4.0f;
    player.shape.setPosition(player.x, player.y);

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Cập nhật vị trí người chơi
        float deltaTime = clock.restart().asSeconds();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && player.y > 0) {
            player.y -= player.speed * deltaTime;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && player.y < WINDOW_HEIGHT - BLOCK_SIZE) {
            player.y += player.speed * deltaTime;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && player.x > 0) {
            player.x -= player.speed * deltaTime;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && player.x < WINDOW_WIDTH - BLOCK_SIZE) {
            player.x += player.speed * deltaTime;
        }
        player.shape.setPosition(player.x, player.y);

        // Vẽ
        window.clear(sf::Color::Cyan); // Bầu trời
        for (const auto& row : world) {
            for (const auto& block : row) {
                window.draw(block.shape);
            }
        }
        window.draw(player.shape);
        window.display();
    }

    return 0;
}
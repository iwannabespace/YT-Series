#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <raylib.h>
#include <string>

class Application
{
public:
    Application();
    void run();
private:
    void OnWindowEvents();
    void DrawUI();
private:
    float wWidth = 1280;
    float wHeight = 800;
    Font font;

    Vector2 scrollPanelScroll = { 0, 0 };
    Rectangle scrollPanelView = { 0 };

    Vector2 chatAreaScroll = { 0, 0 };
    Rectangle chatAreaView = { 0 };

    std::string textboxBuffer;
};

#endif
#include "../include/application.hpp"
#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

Application::Application()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    InitWindow(wWidth, wHeight, "ChatApp");
    MaximizeWindow();

    GuiLoadStyle("styles/genesis/style_genesis.rgs");

    // font = LoadFontEx("fonts/Roboto/Roboto.ttf", 32, nullptr, 0);
    // GuiSetFont(font);

    textboxBuffer.resize(250);
}

void Application::run()
{
    while (!WindowShouldClose())
    {
        OnWindowEvents();

        BeginDrawing();
            ClearBackground(BLACK);
            DrawUI();
        EndDrawing();
    }

    UnloadFont(font);
    CloseWindow();
}

void Application::DrawUI()
{
    wWidth = GetScreenWidth();
    wHeight = GetScreenHeight();

    Rectangle scrollPanelBounds = { 
        0, 0, 300, wHeight,
    };

    Rectangle scrollPanelContent = { 0 };

    GuiScrollPanel(scrollPanelBounds, "Available Chats", scrollPanelContent, &scrollPanelScroll, &scrollPanelView);

    Rectangle chatAreaBounds = { scrollPanelBounds.x + scrollPanelBounds.width, 0, wWidth - (scrollPanelBounds.x + scrollPanelBounds.width), wHeight - (50 + 5) };
    Rectangle chatAreaContent = { 0 };
    GuiScrollPanel(chatAreaBounds, nullptr, chatAreaContent, &chatAreaScroll, &chatAreaView);

    Rectangle textboxBounds = { scrollPanelBounds.x + scrollPanelBounds.width, wHeight - 52, wWidth - (scrollPanelBounds.width + 200), 50 };
    GuiTextBox(textboxBounds, textboxBuffer.data(), textboxBuffer.size(), true);
}

void Application::OnWindowEvents()
{
    if (IsWindowResized())
    {
        wWidth = GetScreenWidth();
        wHeight = GetScreenHeight();
    }
}
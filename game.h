#ifndef TAK__GAME_H__
#define TAK__GAME_H__

#include "engine.h"
#include <string>

class Shader;
class Texture;

class Game
{
    public:
        Game(const std::string& name, const std::string& version);
        virtual ~Game();

        virtual bool LoadResource() = 0;
        virtual bool UnloadResource() = 0;
        virtual void Update(float elapsedTime) = 0;
        virtual void KeyPressEvent(unsigned char key) = 0;
        virtual void KeyReleaseEvent(unsigned char key) = 0;
        virtual void MouseMoveEvent(int x, int y) = 0;
        virtual void MousePressEvent(const MOUSE_BUTTON &button, int x, int y) = 0;
        virtual void MouseReleaseEvent(const MOUSE_BUTTON &button, int x, int y) = 0;
        virtual void WindowFocusEvent(bool hasFocus) = 0;
        virtual void WindowResizeEvent(int width, int height) = 0;

        virtual Shader* GetDefaultShader() = 0;
        virtual Texture* GetDefaultTexture() = 0;

        const std::string& GetName() const;
        const std::string& GetVersion() const;

        int GetFps() const;

    public:
        struct ConfigInfo
        {
            uint InitialWidth;
            uint InitialHeight;
            uint AntialiasingFactor;

            Vector3f ClearColor;

            bool ShowCursor;
            bool CenterMouse;

            ConfigInfo()
            {
                InitialWidth = 640;
                InitialHeight = 480;

                AntialiasingFactor = 0;

                ClearColor = Vector3f(0, 0, 0);

                ShowCursor = true;
                CenterMouse = false;
            };
        } Config;

    protected:
        void AddSyncValue(SyncValue* sv);

        Scene& GetScene() const;

    private:
        SyncValueManager* m_syncValueManager;
        std::string m_name;
        std::string m_version;

        Engine* m_engine;
        Scene* m_scene;

        friend class Engine;
};

#endif // GAME_H__

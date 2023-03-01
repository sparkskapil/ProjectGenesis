#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vector>
#include "spdlog/spdlog.h"
#include "SDL.h"
#include "SDL_vulkan.h"
#include "vulkan/vulkan.h"
#include "assert.h"

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

class Genesis
{
public:
    void run()
    {
        initWindow();
        initVulkan();
        mainLoop();
        cleanup();
    }

    void initWindow()
    {
        SDL_Init(SDL_INIT_EVERYTHING);

        m_Window = SDL_CreateWindow("Genesis",
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            WIDTH, HEIGHT,
            SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_VULKAN);
        genCriticalAssert(m_Window != nullptr, L"Could not create SDL window.");
    }

    void initVulkan()
    {
        createInstance();
    }

    void mainLoop()
    {
        SDL_Event event;
        while (true)
        {
            if (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                    break;
            }
        }
    }

    void cleanup()
    {
        SDL_DestroyWindow(m_Window);
        SDL_Quit();
    }

    void createInstance()
    {
        VkApplicationInfo appInfo{};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName = "Hello Triangle";
        appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.pEngineName = "No Engine";
        appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.apiVersion = VK_API_VERSION_1_0;

        VkInstanceCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        createInfo.pApplicationInfo = &appInfo;

        uint32_t sdlExtensionCount = 0;
        SDL_Vulkan_GetInstanceExtensions(m_Window, &sdlExtensionCount, NULL);

        std::vector<const char*> sdlExtensions(sdlExtensionCount);
        SDL_Vulkan_GetInstanceExtensions(m_Window, &sdlExtensionCount, sdlExtensions.data());

        createInfo.enabledExtensionCount = sdlExtensionCount;
        createInfo.ppEnabledExtensionNames = sdlExtensions.data();

        createInfo.enabledLayerCount = 0;

        genCriticalAssert(vkCreateInstance(&createInfo, nullptr, &m_Instance) == VK_SUCCESS, L"Failed to create instance!");
    }

private:
    SDL_Window* m_Window;
    VkInstance m_Instance;
};

int main()
{
    Genesis app;

    try
    {
        log_info(L"Starting App");
        app.run();
        log_info(L"Stopping App");
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
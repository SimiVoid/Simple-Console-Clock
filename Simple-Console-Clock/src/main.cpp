#include <iostream>
#include <chrono>
#include <thread>
#include <ctime>
#include <cstdio>

int main(int argc, char const* argv[])
{
#define CSI "\e["
    fputs(CSI "?25l", stdout);
#undef CSI
	
    std::thread clockThread([]() {
		while(true) {
            auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

            std::cout << "\x1B[H" << std::ctime(&now);

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
        });

    while (true)
    {

    }

    clockThread.detach();
	
    return 0;
}

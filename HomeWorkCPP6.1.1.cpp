#include <iostream>
#include <chrono>
#include <thread>

void client(int max_client, int& queue) {
    
    while (max_client > queue) {

        queue++;
        std::this_thread::sleep_for(std::chrono::seconds(1));

        std::cout << "Clients + 1: " << queue << std::endl;
   }
}

void the_operator(int& queue) {

    do {

        std::this_thread::sleep_for(std::chrono::seconds(2));
        queue--;

        std::cout << "Clients - 1: " << queue << std::endl;

    } while (queue > 0);
}

int main()
{
    int queue = 0;
    int max_client = 10;

    std::thread flow_1(client, max_client, std::ref(queue));
    std::thread flow_2(the_operator, std::ref(queue));

    flow_1.join();
    flow_2.join();
}

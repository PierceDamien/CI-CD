#pragma once

#include <assert.h>

#include <iostream>
#include <string>
#include <vector>

class bulk_handler {
   private:
    using commands = std::vector<std::string>;

    std::vector<std::string> commands_user;

    const size_t static_size;

    bool use_dynamic_size = false;

    void clear_io_buffer();
    void add_command();
    void run_block();
    void show_commands();

   public:
    bulk_handler() : static_size(3) {commands_user.reserve(16); };
    bulk_handler(int& argc) : static_size(argc) {commands_user.reserve(16);};

    void start();
};
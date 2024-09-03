#include "bulk_runner.h"

#include "bulk_command.h"

bool bulk_runner::is_full() const { return queue.size() == static_size; }

void bulk_runner::add_to_bulk(std::unique_ptr<bulk_command> command) {
    queue.push_back(std::move(command));
    if (!dynamic && is_full()) {
        run_queue();
    }
}

void bulk_runner::run_queue() {
    for (auto& com : queue) {
        com->command_action();
    };
    queue.clear();
}
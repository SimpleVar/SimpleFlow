#pragma once
#include "input_source.hpp"
#include <vector>
#include <memory>
#include <cstddef>

namespace sf {

class InputManager {
    std::vector<std::unique_ptr<InputSource>> srcs_;
    std::size_t active_ = 0;
public:
    void add(std::unique_ptr<InputSource> src) {
        src->init();
        srcs_.push_back(std::move(src));
    }

    std::size_t count() const { return srcs_.size(); }

    void setActive(std::size_t idx) {
        if (idx < srcs_.size()) active_ = idx;
    }

    TrackingData poll() {
        if (srcs_.empty()) return {0, 0, 0};
        return srcs_[active_]->poll();
    }

    void shutdown() {
        for (auto& s : srcs_) s->shutdown();
    }
};

}

#include <gtest/gtest.h>
#include "core/input_manager.hpp"
#include "core/input_source.hpp"
#include <memory>

class FakeInput : public sf::InputSource {
    float x_, y_;
public:
    FakeInput(float x, float y) : x_(x), y_(y) {}
    bool init() override { return true; }
    void shutdown() override {}
    sf::TrackingData poll() override { return {x_, y_, 1.0f}; }
    const char* name() const override { return "fake"; }
};

TEST(InputManagerTest, AddSource) {
    sf::InputManager mgr;
    auto src = std::make_unique<FakeInput>(0.5f, 0.5f);
    mgr.add(std::move(src));
    EXPECT_EQ(mgr.count(), 1);
}

TEST(InputManagerTest, PollActiveSource) {
    sf::InputManager mgr;
    mgr.add(std::make_unique<FakeInput>(0.3f, 0.7f));
    auto d = mgr.poll();
    EXPECT_FLOAT_EQ(d.x, 0.3f);
    EXPECT_FLOAT_EQ(d.y, 0.7f);
}

TEST(InputManagerTest, SwitchSource) {
    sf::InputManager mgr;
    mgr.add(std::make_unique<FakeInput>(0.1f, 0.2f));
    mgr.add(std::make_unique<FakeInput>(0.8f, 0.9f));
    mgr.setActive(1);
    auto d = mgr.poll();
    EXPECT_FLOAT_EQ(d.x, 0.8f);
}

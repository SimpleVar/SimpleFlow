#include <gtest/gtest.h>
#include "core/input_source.hpp"

class MockInput : public sf::InputSource {
public:
    bool init() override { return true; }
    void shutdown() override {}
    sf::TrackingData poll() override { return {0.5f, 0.5f, 1.0f}; }
    const char* name() const override { return "mock"; }
};

TEST(InputSourceTest, PollReturnsData) {
    MockInput src;
    src.init();
    auto d = src.poll();
    EXPECT_FLOAT_EQ(d.x, 0.5f);
    EXPECT_FLOAT_EQ(d.y, 0.5f);
    EXPECT_FLOAT_EQ(d.confidence, 1.0f);
}

TEST(InputSourceTest, HasName) {
    MockInput src;
    EXPECT_STREQ(src.name(), "mock");
}

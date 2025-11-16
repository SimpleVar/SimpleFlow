#include <gtest/gtest.h>
#include "config/config.hpp"
#include <fstream>
#include <filesystem>

class ConfigTest : public ::testing::Test {
protected:
    std::string tmp = "test_config.toml";
    void TearDown() override {
        std::filesystem::remove(tmp);
    }
};

TEST_F(ConfigTest, LoadFromFile) {
    std::ofstream f(tmp);
    f << "[input]\ntype = \"head\"\nsensitivity = 1.5\n";
    f.close();

    sf::Config cfg;
    EXPECT_TRUE(cfg.load(tmp));
    EXPECT_EQ(cfg.get<std::string>("input.type"), "head");
    EXPECT_FLOAT_EQ(cfg.get<float>("input.sensitivity"), 1.5f);
}

TEST_F(ConfigTest, DefaultValues) {
    sf::Config cfg;
    EXPECT_EQ(cfg.get<int>("missing.key", 42), 42);
}

TEST_F(ConfigTest, SetValue) {
    sf::Config cfg;
    cfg.set("user.name", "test");
    EXPECT_EQ(cfg.get<std::string>("user.name"), "test");
}

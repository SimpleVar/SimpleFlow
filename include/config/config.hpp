#pragma once
#include <toml++/toml.hpp>
#include <string>
#include <string_view>
#include <vector>

namespace sf {

class Config {
    toml::table tbl_;

    toml::node* navigate(std::string_view path) {
        std::vector<std::string> parts;
        std::string cur;
        for (char c : path) {
            if (c == '.') {
                if (!cur.empty()) parts.push_back(std::move(cur));
                cur.clear();
            } else {
                cur += c;
            }
        }
        if (!cur.empty()) parts.push_back(std::move(cur));

        toml::node* n = &tbl_;
        for (std::size_t i = 0; i < parts.size() - 1; ++i) {
            if (auto* t = n->as_table()) {
                n = t->get(parts[i]);
                if (!n) return nullptr;
            } else {
                return nullptr;
            }
        }
        if (auto* t = n->as_table()) {
            return t->get(parts.back());
        }
        return nullptr;
    }

public:
    bool load(const std::string& path) {
        try {
            tbl_ = toml::parse_file(path);
            return true;
        } catch (...) {
            return false;
        }
    }

    template<typename T>
    T get(std::string_view path, T def = T{}) {
        auto* n = navigate(path);
        if (!n) return def;
        if (auto v = n->value<T>()) return *v;
        return def;
    }

    template<typename T>
    void set(std::string_view path, T val) {
        std::vector<std::string> parts;
        std::string cur;
        for (char c : path) {
            if (c == '.') {
                if (!cur.empty()) parts.push_back(std::move(cur));
                cur.clear();
            } else {
                cur += c;
            }
        }
        if (!cur.empty()) parts.push_back(std::move(cur));

        toml::table* t = &tbl_;
        for (std::size_t i = 0; i < parts.size() - 1; ++i) {
            if (!t->contains(parts[i])) {
                t->insert(parts[i], toml::table{});
            }
            t = t->get(parts[i])->as_table();
        }
        t->insert_or_assign(parts.back(), val);
    }

    bool save(const std::string& path) {
        std::ofstream f(path);
        if (!f) return false;
        f << tbl_;
        return true;
    }
};

}

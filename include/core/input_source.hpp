#pragma once

namespace sf {

struct TrackingData {
    float x;
    float y;
    float confidence;
};

class InputSource {
public:
    virtual ~InputSource() = default;
    virtual bool init() = 0;
    virtual void shutdown() = 0;
    virtual TrackingData poll() = 0;
    virtual const char* name() const = 0;
};

}

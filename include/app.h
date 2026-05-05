#ifndef cmdprxAPP_H
#define cmdprxAPP_H

namespace aiteam {

class App {
public:
    App()  = default;
    ~App() = default;

    [[nodiscard]] bool init(int argc, char* argv[]);
    [[nodiscard]] bool run();

private:
    bool initialized_ { false };
};

}  // namespace aiteam

#endif
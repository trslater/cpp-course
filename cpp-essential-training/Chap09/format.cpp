// format.cpp by Bill Weinman [bw.org]
// updated 2022-06-22

#include <fmt/core.h>
#include <string>
#include <string_view>
#include <vector>
#include <numbers>

using fmt::format;
using std::string;
using std::vector;
using std::numbers::pi;

template<typename T>
struct Frac {
    T n;
    T d;
};

// format specialization
template <typename T>
struct fmt::formatter<Frac<T>> : fmt::formatter<unsigned> {
    template <typename Context>
    auto format(const Frac<T>& f, Context& ctx) const {
        return format_to(ctx.out(), "{}/{}", f.n, f.d);
    }
};

// format print
template<typename... Args>
constexpr void print(const std::string_view str_fmt, Args&&... args) {
    fputs(fmt::vformat(str_fmt, fmt::make_format_args(args...)).c_str(), stdout);
}

int main() {
    const int inta { 47 };
    const char* human { "earthlings" };
    const string alien { "vulcans" };
    const double dpi { pi };

    print("inta is {}\n", inta);
    print("Hello {}\n", human);

    print("Hello {} we are {}\n", human, alien);
    print("Hello {1} we are {0}\n", human, alien);

    print("π is {}\n", dpi);
    print("π is {:.5}\n", dpi);
    print("inta is {1:}, π is {0:.5}\n", dpi, inta);

    print("inta is [{:*<10}]\n", inta);
    print("inta is [{:0>10}]\n", inta);
    print("inta is [{:^10}]\n", inta);
    print("inta is [{:_^10}]\n", inta);

    print("{:>8}: [{:04X}]\n", "Hex", inta);
    print("{:>8}: [{:4o}]\n", "Octal", inta);
    print("{:>8}: [{:4d}]\n", "Decimal", inta);

    Frac<long> n{ 3, 5 };
    print("Frac: {}\n", n);
}

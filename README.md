# ForwardAD: Lightweight Forward-Mode Automatic Differentiation in C++

`ForwardAD` is a header-only, zero-dependency C++ library that implements **Forward-Mode Automatic Differentiation (AD)** using dual number arithmetic ($a + b\epsilon$). It evaluates function values and exact derivatives concurrently to floating-point precision, bypassing symbolic differentiation overhead and finite-difference numerical errors.

---

## Key Features

* **Dual Number Arithmetic**: Native representation of dual numbers carrying primal values and tangent derivatives simultaneously.
* **Exact Machine-Precision Derivatives**: Computes derivatives in a single forward pass without truncation or roundoff errors.
* **Operator Overloading**: Full support for standard binary arithmetic operators (`+`, `-`, `*`, `/`) between dual numbers and scalars.
* **Transcendental Function Support**: Overloaded elementary functions (`sin`, `cos`, `exp`) implementing the Chain Rule automatically.
* **Header-Only & Zero Dependencies**: Built strictly using standard C++17 utilities and `<cmath>`.

---

## How It Works

A dual number is expressed as:

$$v = a + b\epsilon \quad \text{where } \epsilon^2 = 0 \quad (\epsilon \neq 0)$$

* **$a$ (Primal):** Evaluates the function value $f(x)$.
* **$b$ (Tangent):** Evaluates the exact derivative $f'(x)$.

When passed through composite functions, operator overloading propagates derivatives via the structural rule $\epsilon^2 = 0$ and the Chain Rule the below equation can be derived from Taylor Series:

$$f(a + b\epsilon) = f(a) + f'(a)b\epsilon$$

---

## Project Structure

```text
forward_ad/
├── include/
│   └── dual.hpp       # Dual number class and operator overloads
├── src/
│   └── main.cpp       # Example usage and verification tests
├── CMakeLists.txt     # Build configuration
└── README.md
```

## Quick Start and Usage 

```
#include <iostream>
#include "dual.hpp"

// Define a mathematical function: f(x) = exp(sin(x))

Dual f(const Dual& x) {
    return exp(sin(x));
}

int main() {

    double x_val = 0.0;
    
    // Seed input: x = 0.0, dx/dx = 1.0

    Dual x(x_val, 1.0);

    Dual result = f(x);

    std::cout << "f(" << x_val << ")  = " << result.real_part << std::endl;
    std::cout << "f'(" << x_val << ") = " << result.derivative_part << std::endl;

    return 0;
}
```

## Build and Run

### Prerequisite

* Modern C++ Compiler (g++ or clang) with C++17 support
* CMake (version 3.14+)


## Compilation Commands

```
cd forward_ad #clone the repo and enter directory

mkdir -p build && cd build

cmake ..
make

./ad_demo
```
#include <iostream>
#include <cmath>
#include <vector>

double fractionalDerivative(double coeff, double alpha, int degree) {
    // Calculate the fractional derivative using the formula (k^alpha * coeff)
    return std::pow(degree, alpha) * coeff;
}

double fractionalKnotInvariant(const std::vector<double>& polyCoeffs, double alpha) {
    double invariant = 0.0;
    for (int i = 0; i < polyCoeffs.size(); ++i) {
        invariant += fractionalDerivative(polyCoeffs[i], alpha, i);
    }
    return invariant;
}

int main() {
    // Example coefficients of a knot polynomial (Alexander polynomial for a simple knot)
    std::vector<double> knotPoly = {1.0, -3.0, 3.0, -1.0}; // Example coefficients
    double alpha = 0.5;  // Fractional order

    double invariant = fractionalKnotInvariant(knotPoly, alpha);

    std::cout << "Fractional Knot Invariant (alpha = " << alpha << "): " << invariant << std::endl;

    return 0;
}

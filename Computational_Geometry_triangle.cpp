double fixAngle(double A) {
    return A > 1 ? 1 : (A < -1 ? -1 : A);
}

// sin(A)/a = sin(B) / b = sin(C) / c
double getSide_a(double b, double A, double B) {
    return (sin(A) * b) / sin(B);
}

double getAngle_A(double a, double b, double B) {
    return asin(fixAngle((a * sin(B) / b)));
}

// a ^ 2 = b ^ 2 + c ^ 2 - 2bc * cos(A)
double getAngle_A_abc(double a, double b, double c) {
    return acos(fixAngle((b * b + c * c - a * a) / (2 * b * c)));
}

// Area of triangle using with 3 points
double triangleArea(point p1, point p2, point p3) {
    // length(p1 - p2) = sqrt((p1.x - p2.x) ^ 2 + (p1.y - p2.y) ^ 2)
    double a = length(p1 - p2), b = length(p1 - p3), c = length(p2 - p3);
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c)); // Heron's formula
}

// Area of triangle using with 3 medians
double triangleArea(double m1, double m2, double m3) {
    if (m1 <= 0 || m2 <= 0 || m3 <= 0) return -1; // impossipole
    double s = 0.5 * (m1 + m2 + m3);
    double medians_area = s * (s - m1) * (s - m2) * (s - m3);
    double area = 4.0 / 3.0 * sqrt(medians_area);
    if (medians_area <= 0.0 || area <= 0) return -1; // impossipole
    return area;
}

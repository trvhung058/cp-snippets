double MaxF(double left, double right) {
    for (int i = 1; i <= 100; ++i) {
        double x1 = left + (right - left) / 3.0;
        double x2 = right - (right - left) / 3.0;

        if (f(x1) > f(x2)) right = x2;
        else left = x1;
    }

    return f(left);
}
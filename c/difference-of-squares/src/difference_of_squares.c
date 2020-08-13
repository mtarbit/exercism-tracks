int square(int n) {
    return n * n;
}

int sum_of_integers(int n) {
    // https://oeis.org/A000217
    return (n * (n + 1)) / 2;
}

int sum_of_squares(int n) {
    // https://oeis.org/A000330
    return (n * (n + 1) * ((2 * n) + 1)) / 6;
}

int square_of_sum(int n) {
    return square(sum_of_integers(n));
}

int difference_of_squares(int n) {
    return square_of_sum(n) - sum_of_squares(n);
}

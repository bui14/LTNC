int getTotalX(vector<int>& a, vector<int>& b) {
    int dem = 0;
    int gcd_b = b[0];
    for (size_t i = 1; i < b.size(); i++) {
        gcd_b = gcd(gcd_b, b[i]);
    }
    int lcm_a = a[0];
    for (size_t i = 1; i < a.size(); i++) {
        lcm_a = lcm(lcm_a, a[i]);
    }
    for (int i = lcm_a; i <= gcd_b; i++) {
        if (gcd_b % i == 0) dem++;
    }
    return dem;
}
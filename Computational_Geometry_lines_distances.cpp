int dcomp(double a, double b){
    return fabs(a - b) <= eps ? 0 : a < b ? 1 : -1;
}
// check is 3 points on the same line?
bool isCollinear (point a, point b, point c) {
    //cp = cross product
    return fabs(cp(b - a, c - a)) < EPS;
}
// Ray a-b
bool isPointOnRay (point a, point b, point c) {
    if (!isCollinear(a, b, c))
        return false;
    // dp = dot product
    return dcomp(dp(b - a, c - a), 0) == 1;
}
//segment a-b
bool isPointOnSegment (point a, point b, point c) {
    double acb = length(a - b), ac = length(a - c), cb = length(b - c);
    return dcomp(acb - (ac + cb), 0) == 0;
}
// distance from point c to line a-b
double distToLine (point a, point b, point c) {
    double dist = cp(b - a, c - a) / length(a - b);
    return fabs(dist);
}

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
//distance from point p2 to segment p0 - p1
double distToSegment(point p0, point p1, point p2) {
    double dl, d2;
    point v1 = p1 - p0, v2 = p2 - p0;
    //left segment
    if ((d1 = dp(v1, v2)) <= 0)
        return length(p2 - p0);
    //right segment
    if ((d2 = dp(v1, v1)) <= d1)
        return length(p2 - p1);
    //else on segment
    double t = dl / d2;
    return length(p2 - (p0 + v1 * t));
}
// not more efficient than distToSegment but use it if u forget 
int main() {
    //point p0(50, 50), p1(100, 100), p2(500, 17); //right
    //point p0(50, 50), p1(100, 100), p2(-70, 17); // left
    point p0(50, 50), p1(100, 100), p2(70, 100);
    p1 -= p0, p2 -= p0, p0 = 0; // shift to origin, so cancel p0

    double ang = angle(p1);
    p1 = rotate0(p1, -ang); //p0 - p1 now is on the x-axis
    p2 = rotate0(p2, -ang);
    //using p2.x, you can know distance trivially
    if(p2.X <= 0) cout << length(p2) //left segment
    else if(p2.X >= p1.X) cout << length(p2 - p1) //right segment
    else cout << fabs(p2.Y) //above segment
    return 0;
}

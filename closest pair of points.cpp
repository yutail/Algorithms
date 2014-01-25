//1. Sort points according to their x-coordinates.
//2. Split the set of points into two equal-sized subsets by a vertical line x=xmid.
//3. Solve the problem recursively in the left and right subsets. This yields the left-side and right-side minimum distances dLmin and dRmin, respectively.
//4. Find the minimal distance dLRmin among the pair of points in which one point lies on the left of the dividing vertical and the second point lies to the right.
//5. The final answer is the minimum among dLmin, dRmin, and dLRmin.

struct Point {
    int x;
    int y;
};

bool compareX(Point p1, Point p2) {
    return (p1.x < p2.x);
}

bool compareY(Point p1, Point p2) {
    return (p1.y < p2.y);
}

float dist(Point p1, Point p2) {
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

float bruteForce(vector<Point> &P) {
    float d = FLT_MAX;
    for (int i=0; i<P.size(); i++) {
        for (int j=i+1; j<P.size(); j++) {
            float tmp = dist(P[i], p[j]);
            if (tmp < d)
                d = tmp;
        }
    }
    return d;
}

float crossCloset(vector<Point> &P, float dmin) {
    std::sort(P.begin(), P.end(), compareY);
    int n = P.size();
    
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n && (P[j]-P[i])<dmin; j++) {
            if (dist(P[j], P[i]) < dmin)
                dmin = dist(P[j], P[i]);
        }
    }
    return dmin;
}

float closetPairHelper(vector<Point> &P) {
    int n = P.size();
    if (n <= 3)
        return bruteForce(P);
    
    int mid = n /2;
    Point midPoint = P[mid];
    
    vector<Point> PLeft(P.begin(), P.begin()+mid);
    vector<Point> PRight(P.begin()+mid, P.end());
    
    float dLmin = closetPairHelper(PLeft);
    float dRmin = closetPairHelper(PRight);
    
    float dmin = min(dLmin, dRmin);
    
    vector<Point> crossPoint;
    for (int i=0; i<n; i++) {
        if (abs(P[i].x-midPoint.x) < dmin)
            crossPoint.push_back(P[i]);
    }
    float crossmin = crossCloset(crossPoint, dmin);
    return min(dmin, crossmin);
}

float closetPair(vector<Point> &P) {
    std::sort(P.begin(), P.end(), compareX);

    return closetPairHelper(P);
}


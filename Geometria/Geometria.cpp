#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
using namespace std; 

struct Point{
    double x, y;
    Point(){} 
    Point(double a,double b) {
        x = a;
        y = b;
    } 

    double angle() {
        return atan2(y,x);
    }

    double mod() {
        return sqrt(x*x+y*y);
    }

    Point unit() {
        double modulo = mod();
        return Point(x/modulo, y/modulo);
    }
};

Point operator +(const Point &a, const Point &b) {
    return Point(a.x + b.x, a.y + b.y);
}

Point operator -(const Point &a, const Point &b) {
    return Point(a.x - b.x, a.y-b.y); 
}

Point operator *(const Point &a, double k) {
    return Point(a.x*k,a.y*k); 
}

Point operator /(const Point &a, double k) {
    return Point(a.x/k, a.y/k); 
}
 
bool operator <(const Point &a, const Point &b) {
    if(a.x != b.x) {
        return a.x < b.x;
    } else {
        return  a.y < b.y;
    }
}

ostream& operator<<(ostream& os, Point p) {
    return os << "Este es el Punto ===>("<< p.x << "," << p.y << ")";
}

double dist(const Point &A, const Point &B) {
    return hypot(A.x-B.x,A.y - B.y);
}

double dot(const Point &A, const Point &B) {
    return A.x * B.x + A.y * B.y; 
}

double cross(const Point &V, const Point &U) {
    return V.x * U.y - V.y * U.x;
}

double areaP(const Point &V, const Point &U) {
    return abs(cross(V,U));
}

double area(const Point &A, const Point &B, const Point &C) {
    return cross(B - A, C - A);
}

double areaTriangulo(const Point &A, const Point &B, const Point &C) {
    return abs(area(A,B,C))/2.; 
}

double areaHeron(double a, double b, double c) {
    double s = (a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

// bool is_triangle(Point &A, Point &B, Point &C) {
//     double a = dist(A,B);// cuadrado
//     double b = dist(A,C);// cuadrado
//     double c = dist(B,C);// cuadrado
//     double s = max(a,b,c);
//     return 2.0*s == a+b+c;
// }

Point lineIntersection(const Point &A,const Point &B,const Point &C,const Point &D) {
    return A+(B-A)*(cross(C-A,D-C)/cross(B-A,D-C));
}

bool onSegment(const Point &A, const Point&B, const Point &P) {
    return areaTriangulo(A,B,P) == 0 && 
        (P.x >= min(A.x,B.x) && P.x <= max(A.x,B.x)) && 
        (P.y >= min(A.y,B.y) && P.y <= max(A.y,B.y));
}

bool intersectsSegment(const Point &A,const Point &B,const Point &C,const Point &D) {
    double A1 = area(C,A,D);
    double A2 = area(C,B,D); 
    double A3 = area(A,B,C);
    double A4 = area(A,B,D);  

    if(((A1 > 0 && A2 < 0) || (A1<0 && A2>0)) && 
        ((A3 > 0 && A4 < 0) || (A3<0 && A4>0)))  {
            return true;
    }

    if(A1 == 0 && onSegment(C,D,A)) {
        return true;
    }

    if(A2 == 0 && onSegment(C,D,B)) {
        return true;
    }

    if(A3 == 0 && onSegment(A,B,C)) {
        return true;
    }

    if(A4 == 0 && onSegment(A,B,D)) {
        return true;
    }

    return false;
}

bool isConvex(const vector<Point> &polign) {
    int nroPoints = polign.size();
    int areasPositive =  0, areasNegative = 0;
    for(int i = 0; i < nroPoints ;i++) 
    {
        double areaPoints = area(polign[i],polign[(i+1)%nroPoints],polign[(i+2)%nroPoints]);
        if(areaPoints>0) {
           areasPositive++;
        } else if(areaPoints<0) {
           areasNegative++;
        }
    }
    return areasPositive == 0 || areasNegative == 0;
}

bool pointInConvex(const vector<Point> &polign, const Point &P) {
    int nroPoints = polign.size();
    int areasPositive =  0, areasNegative = 0;
    for(int i = 0; i < nroPoints ;i++) 
    { 
        double areaPoints = area(P,polign[i],polign[(i+1)%nroPoints]);
        if(areaPoints>0) {
           areasPositive++;
        } else if(areaPoints<0) {
           areasNegative++;
        }
    }
    return areasPositive == 0 || areasNegative == 0;
} 

double areaPoligono(const vector<Point> &poligono) {
    int nroPoints = poligono.size(); 
    double areaTotal = 0; 
    for(int i = 1; i < nroPoints - 1; i++)
    {
        areaTotal += area(poligono[0],poligono[i],poligono[i+1]); 
    }
    return abs(areaTotal/2);
}

vector<Point> convexHull(vector<Point> &points) {
    sort(points.begin(),points.end());
    int k = 0;
    Point hulls[points.size()+100];
    
    for(int i = 0; i<points.size();i++)
    {
        while(k>=2 && area(hulls[k-2],hulls[k-1],points[i])<=0) 
        {
            k--;
        }
        hulls[k++] = points[i];
    }

    for(int i = points.size()-2, t = k;i>=0; i--) 
    {
        while( k > t && area(hulls[k-2],hulls[k-1],points[i])<= 0)
        {
            k--;
        }
        hulls[k++] = points[i];
    }
    
    return vector<Point> (hulls,hulls+k-1);
}


int main(){
    input;
    int n;
    vector<Point> poligono;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        poligono.push_back(Point(x,y));
    }
    int m;
    scanf("%d",&m);
    for(int i = 0; i < m; i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        Point P(x,y);
        if(pointInConvex(poligono,P)){
            printf("inside\n");
        } else {
            printf("outside\n");
        }
    }
    return 0;
}

#include <iostream>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct Punkt{
    float x, y;
};

struct Linia {
    Punkt pkt1, pkt2;
};

struct Okrag {
    Punkt sr;
    float r;
};

struct Prostokat {
    Punkt leftTop, rightBottom;
};

float distance(const Punkt& punkt1, const Punkt& punkt2)
{
    return sqrt(pow(punkt2.x - punkt1.x, 2) + pow(punkt2.y - punkt1.y, 2));
}

bool isPerpendicular(const Linia& line1, const Linia& line2) {
    // prostopadle gdy iloczyn nachylenia linii wynosi -1
    return (line1.pkt2.y - line1.pkt1.y) * (line2.pkt2.y - line2.pkt1.y) +
           (line1.pkt2.x - line1.pkt1.x) * (line2.pkt2.x - line2.pkt1.x) == 0;
}

float isInOutOnCircle(const Okrag &circle, const Punkt  &point)
{
    float dis = distance(circle.sr, point);
    if(circle.r == dis)
        return 0;
    else if(dis < circle.r)
        return dis/circle.r;
    else
        return dis/circle.r;
}

float biggestParimeter(const vector<Okrag> &v)
{
    float maxR = 0.0;
    for(const auto &i : v)
    {
        if(i.r > maxR)
            maxR = i.r;
    }
    return 2.0 * M_PI * maxR;
}

Prostokat czesc_wspolna_prostokatow(const Prostokat& rec1, const Prostokat& rec2) {
    Prostokat czesc_wspolna;

    czesc_wspolna.leftTop.x = std::max(prostokat1.lewy_gorny.x, prostokat2.lewy_gorny.x);
    czesc_wspolna.leftTop.y = std::max(prostokat1.lewy_gorny.y, prostokat2.lewy_gorny.y);
    czesc_wspolna.rightBottom.x = std::min(prostokat1.prawy_dolny.x, prostokat2.prawy_dolny.x);
    czesc_wspolna.rightBottom.y = std::min(prostokat1.prawy_dolny.y, prostokat2.prawy_dolny.y);

    // Sprawdzenie, czy prostokąty mają część wspólną
    if (czesc_wspolna.lewy_gorny.x > czesc_wspolna.prawy_dolny.x ||
        czesc_wspolna.lewy_gorny.y > czesc_wspolna.prawy_dolny.y) {
        // Brak części wspólnej, zwracamy prostokąt o wymiarach zerowych
        return { {0.0, 0.0}, {0.0, 0.0} };
    }

    return czesc_wspolna;
}




int main()
{
    Punkt p1 = {1.0, 2.0};
    Punkt p2 = {4.0, 6.0};
    cout << "Distance between points: " << distance(p1, p2) << endl;

    Okrag o = {{0.0, 0.0}, 4.0};
    Punkt p3 = {3.0, 4.0};
    cout << "Is point in, out or on the circle : " << isInOutOnCircle(o, p3) << endl;

    return 0;
}

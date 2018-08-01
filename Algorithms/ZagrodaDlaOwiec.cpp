//Login: Nukat
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
	int x, y, poz;
};

bool compare(const Point& poi1, const Point& poi2)
{
	if (poi1.y == poi2.y)
	{
		if (poi1.x == poi2.x)
		{
			return poi1.poz < poi2.poz;
		}
		else
			return poi1.x < poi2.x;
	}
	else
		return (poi1.y < poi2.y);

}

void print(vector<Point> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i].x << " " << vec[i].y << " " << vec[i].poz << "\n";
	}
}

int orientation(const Point& a, const Point& b, const Point& c)
{
	return  (c.y - a.y)*(b.x - a.x) - (b.y - a.y)*(c.x - a.x);
}

double distance(const Point& a, const Point& b)
{
	return sqrt((b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y));
}

int main()
{
	int t, n, x, y, podst = 1, ccw = 0, cw = 0;
	double dist = 0.0;
	vector<Point> points, counterClockWise, clockWise;

	cin >> t;

	while (t--)
	{
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;

			Point point;
			point.x = x;
			point.y = y;
			point.poz = i+1;

			points.push_back(point);
		}

		sort(points.begin(), points.end(), compare);

		//print(points);

		for (int i = 1; i < points.size(); i++)
		{
			if (!((points[i - 1].x == points[i].x) && (points[i - 1].y == points[i].y))) 
			{
				points[podst] = points[i];
				podst++;
			}
		}

		points.resize(podst);
		counterClockWise.resize(podst * 2);
		clockWise.resize(podst * 2);

		for (int i = 0; i < points.size(); i++)
		{
			while (ccw >= 2 && orientation(counterClockWise[ccw - 2], counterClockWise[ccw - 1], points[i]) <= 0 )
				ccw--;
			
			while (cw >= 2 && orientation(clockWise[cw - 2], clockWise[cw - 1], points[i]) >= 0 )
				cw--;

			counterClockWise[ccw] = points[i];
			clockWise[cw] = points[i];

			ccw++;
			cw++;
		}

		counterClockWise.resize(ccw);
		clockWise.resize(cw);

		for (int i = (int) clockWise.size() - 2; i > 0; i--)
		{
			counterClockWise.push_back(clockWise[i]);
		}

		for (int i = 0; i < counterClockWise.size()-1; i++)
		{
			dist += distance(counterClockWise[i], counterClockWise[i + 1]);
		}

		dist += distance(counterClockWise[counterClockWise.size() - 1], counterClockWise[0]);

		printf("%.2f", dist);
		cout << "\n";

		for (int i = 0; i < counterClockWise.size(); i++)
		{
			cout << counterClockWise[i].poz << " ";
		}

		cout << "\n" << "\n";


		counterClockWise.clear();
		clockWise.clear();
		points.clear();
		dist = 0.0;
		ccw = 0;
		cw = 0;
		podst = 1;
	}

    return 0;
}
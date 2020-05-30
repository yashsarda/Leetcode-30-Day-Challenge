/*
We have a list of points on the plane.  Find the K closest points to the origin (0, 0).

(Here, the distance between two points on a plane is the Euclidean distance.)

You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)
*/
/*
priority queue or radix sort does the trick

Euclidiean distance = sqrt((x2 - x1)^2 + (y2 - y1)^2);
Since x1 = y1 = 0;
distance = sqrt(x2^2 + y2^2)
*/
struct point
{
    int x;
    int y;
    double distance;
};
struct cmp
{
    bool operator()(point& A, point& B)
    {
        return (A.distance > B.distance);
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {

        int rows = points.size();
        priority_queue<point, vector<point>, cmp > pq;

        for(int i = 0; i < rows; i++) {
            int xd = points[i][0];
            int yd = points[i][1];
            double distance = sqrt(xd * xd + yd * yd);
            pq.push({ xd, yd, distance });
        }
        vector<vector<int> > answer;
        while(K-- > 0) {
            point t = pq.top();
            pq.pop();
            answer.push_back({ t.x, t.y });
        }
        return answer;
    }
};

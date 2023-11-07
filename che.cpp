#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long

typedef pair<long long, long long> pii;


struct Event {
    Event(int i, int i1, int pos) {
        this->x = i;
        this->type = i1;
        this->pos = pos;
    }

    int x, type, pos;
};


struct Segment {
    Segment(int i, int i1) {
        this->a = i;
        this->b = i1;
    }

    int a;
    int b;
};

bool compare(Event a, Event b) {
    return (a.x < b.x || (a.x == b.x && a.type > b.type));
}

bool compare2(Segment a, Segment b) {
    return a.b < b.b;
}

void scanline(vector<Segment> &segments, vector<int> &points) {
    vector<int> segnum(sz(points));
    vector<Event> events;

    // Segment is open: 1; Segment is closed: -1;
    for (int i = 0; i < sz(segments); ++i) {
        events.push_back(Event(segments[i].a, 1, i));
        events.push_back(Event(segments[i].b, -1, i));
    }

    for (int i = 0; i < sz(points); ++i) {
        events.push_back(Event(points[i], 0, i));
    }

    sort(events.begin(), events.end(), compare);

    int cnt = 0;

    for (Event e: events) {
        if(e.type < 0 && cnt <= 0){
            continue;
        }
        cnt += e.type;

        if (e.type == 0)
            segnum[e.pos] = cnt;
    }

    for (int i = 0; i < sz(segnum); ++i) {
        cout << segnum[i] << " ";
    }
}

void solution() {
    int n, m;
    cin >> n >> m;
    vector<Segment> segments;
    vector<int> points(m);

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        segments.push_back(Segment(a, b));
    }

    sort(all(segments), compare2);

    for (int i = 0; i < m; i++) {
        int point;
        cin >> point;
        points[i] = point;
    }

    scanline(segments, points);
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solution();
}
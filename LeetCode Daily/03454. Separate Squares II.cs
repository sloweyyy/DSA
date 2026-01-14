public class Solution {
    public double SeparateSquares(int[][] squares) {
        int n = squares.Length;
        var events = new List<Event>(2 * n);
        var xs = new List<long>(2 * n);

        long minY = long.MaxValue;
        for (int i = 0; i < n; i++) {
            long x1 = squares[i][0];
            long y1 = squares[i][1];
            long l = squares[i][2];
            long x2 = x1 + l;
            long y2 = y1 + l;

            minY = Math.Min(minY, y1);
            xs.Add(x1);
            xs.Add(x2);
            events.Add(new Event(y1, x1, x2, +1));
            events.Add(new Event(y2, x1, x2, -1));
        }

        xs.Sort();
        xs = DedupSorted(xs);
        events.Sort((a, b) => a.Y.CompareTo(b.Y));

        // Segment tree over x-intervals between unique x coordinates.
        var st = new SegTree(xs);

        // Sweep in y, building prefix area at each unique y event.
        var ys = new List<long>();
        var prefix = new List<double>();     // area below y
        var coverAfter = new List<double>(); // covered x-length after processing events at y (for slab to next y)

        long prevY = events[0].Y;
        double area = 0.0;
        int idx = 0;

        while (idx < events.Count) {
            long y = events[idx].Y;
            // Add slab area from prevY to y using coverage after processing prevY.
            long dy = y - prevY;
            if (dy != 0) {
                area += st.CoveredLength * (double)dy;
                prevY = y;
            }

            // Area strictly below y.
            ys.Add(y);
            prefix.Add(area);

            // Apply all events at this y.
            while (idx < events.Count && events[idx].Y == y) {
                var e = events[idx++];
                int l = LowerBound(xs, e.X1);
                int r = LowerBound(xs, e.X2);
                if (l < r) st.Add(l, r - 1, e.Delta); // update segments [l, r-1]
            }

            coverAfter.Add(st.CoveredLength);
        }

        double total = area; // after last event, no more slabs contribute
        double half = total / 2.0;

        // If union area is 0 (shouldn't per constraints), return minY.
        if (half <= 0) return (double)minY;

        // Find minimal y where area below y >= half.
        for (int i = 0; i < ys.Count; i++) {
            if (prefix[i] >= half) return (double)ys[i];
            if (i + 1 >= ys.Count) break;

            double len = coverAfter[i];
            long dy = ys[i + 1] - ys[i];
            if (dy == 0 || len == 0) continue;

            double nextArea = prefix[i] + len * (double)dy;
            if (nextArea >= half) {
                // half lies within this slab; compute exact minimal y.
                return ys[i] + (half - prefix[i]) / len;
            }
        }

        // Fallback (shouldn't happen): return last event y.
        return (double)ys[ys.Count - 1];
    }

    private static List<long> DedupSorted(List<long> a) {
        if (a.Count == 0) return a;
        var res = new List<long>(a.Count);
        long prev = a[0];
        res.Add(prev);
        for (int i = 1; i < a.Count; i++) {
            if (a[i] != prev) {
                prev = a[i];
                res.Add(prev);
            }
        }
        return res;
    }

    private static int LowerBound(List<long> a, long x) {
        int lo = 0, hi = a.Count;
        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            if (a[mid] < x) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }

    private readonly struct Event {
        public readonly long Y;
        public readonly long X1;
        public readonly long X2;
        public readonly int Delta;
        public Event(long y, long x1, long x2, int delta) {
            Y = y; X1 = x1; X2 = x2; Delta = delta;
        }
    }

    private sealed class SegTree {
        private readonly List<long> _xs;
        private readonly int _nSeg;     // number of elementary segments = xs.Count - 1
        private readonly int[] _cnt;    // cover count
        private readonly double[] _len; // covered length

        public double CoveredLength => _nSeg <= 0 ? 0.0 : _len[1];

        public SegTree(List<long> xs) {
            _xs = xs;
            _nSeg = Math.Max(0, xs.Count - 1);
            // 4 * n is enough for segment tree
            _cnt = new int[Math.Max(4, 4 * _nSeg + 5)];
            _len = new double[Math.Max(4, 4 * _nSeg + 5)];
        }

        // Update inclusive segment indices [lSeg, rSeg] in [0, _nSeg-1]
        public void Add(int lSeg, int rSeg, int delta) {
            if (_nSeg <= 0 || lSeg > rSeg) return;
            Add(1, 0, _nSeg - 1, lSeg, rSeg, delta);
        }

        private void Add(int node, int nl, int nr, int ql, int qr, int delta) {
            if (ql <= nl && nr <= qr) {
                _cnt[node] += delta;
                Pull(node, nl, nr);
                return;
            }
            int mid = nl + ((nr - nl) >> 1);
            if (ql <= mid) Add(node << 1, nl, mid, ql, qr, delta);
            if (qr > mid) Add((node << 1) | 1, mid + 1, nr, ql, qr, delta);
            Pull(node, nl, nr);
        }

        private void Pull(int node, int nl, int nr) {
            if (_cnt[node] > 0) {
                // fully covered
                _len[node] = (double)(_xs[nr + 1] - _xs[nl]);
            } else if (nl == nr) {
                _len[node] = 0.0;
            } else {
                _len[node] = _len[node << 1] + _len[(node << 1) | 1];
            }
        }
    }
}
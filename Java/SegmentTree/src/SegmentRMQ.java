public class SegmentRMQ {
    private int st[];
    private int N;
    SegmentRMQ(int n) {
        st = new int[4 * n + 1];
        N = n;
    }

    private static int left(int p) {
        return (p << 1);
    }

    private static int right(int p) {
        return (p << 1) + 1;
    }

    private void build(int a[], int p, int L, int R) {
        if (L == R) {
            st[p] = a[L];
            return;
        }
        build(a, left(p), L, (L + R)/2);
        build(a, right(p), (L + R)/2 + 1, R);
        int p1 = st[left(p)]; int p2 = st[right(p)];
        st[p] = Math.min(p1, p2);
    }

    public void build(int a[]) {
        build(a, 1, 0, N - 1);
    }

    private int RMQ(int p, int L, int R, int i, int j) {
        if (i > R || j < L) return -1;
        if (L >= i && R <= j) return st[p];

        int p1 = RMQ(left(p), L, (L + R)/2, i, j);
        int p2 = RMQ(right(p), (L + R)/2 + 1, R, i, j);

        if (p1 == -1) return p2;
        if (p2 == -1) return p1;

        return Math.min(p1, p2);
    }

    public int RMQ(int i, int j) {
        return RMQ(1, 0, N - 1, i, j);
    }

    private void update(int p, int L, int R, int index, int v) {
        if (L == R && L == index) {
            st[p] = v;
            return;
        }

        if (index >= L && index <= (L + R)/2)
            update(left(p), L, (L + R)/2, index, v);
        else
            update(right(p), (L + R)/2 + 1, R, index, v);
        int p1 = st[left(p)]; int p2 = st[right(p)];
        st[p] = Math.min(p1, p2);
    }

    public void update(int index, int v) {
        update(1, 0, N - 1, index, v);
    }
}

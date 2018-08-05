// 1D Fenwick Tree

struct BIT {
    ll tree[MAX];
    int MaxVal;
    void init(int sz=1e7) {
        memset(tree, 0, sizeof tree);
        MaxVal = sz+1;
    }
    void update(int idx, ll val) {
        for( ;idx <= MaxVal; idx += (idx & -idx))
            tree[idx] += val;
    }
    void update(int l, int r, ll val) {
        if(l > r) swap(l, r);
        update(l, val);
        update(r+1, -val);
    }
    ll read(int idx) {
        ll sum = 0;
        for( ;idx > 0; idx -= (idx & -idx))
            sum += tree[idx];
        return sum;
    }
    ll read(int l, int r) {
        ll ret = read(r) - read(l-1);
        return ret;
    }
    ll readSingle(int idx) {             // Point read in log(n)
        ll sum = tree[idx];
        if(idx > 0) {
            int z = idx - (idx & -idx);
            --idx;
            while(idx != z) {
                sum -= tree[idx];
                idx -= (idx & -idx);
        }}   
        return sum;
    }
    int search(int cSum) {
        int pos = -1, lo = 1, hi = MaxVal, mid;
        while(lo <= hi) {
            mid = (lo+hi)/2;
            if(read(mid) >= cSum) {     // read(mid) >= cSum : to find the lowest index of cSum value
                pos = mid;              // read(mid) == cSum : to find the greatest index of cSum value
                hi = mid-1;
            }
            else
                lo = mid+1;
        }
        return pos;
    }
    ll size() {
        return read(MaxVal);
    }
    // Modified BIT, this section can be used to add/remove/read 1 to all elements from 1 to pos
    // all of the inverse functions must be used, for any manipulation
    ll invRead(int idx) {           // gives summation from 1 to idx
        return read(MaxVal-idx);
    }
    void invInsert(int idx) {       // adds 1 to all index less than idx
        update(MaxVal-idx, 1);
    }
    void invRemove(int idx) {       // removes 1 from idx
        update(MaxVal-idx, -1);
    }
    void invUpdate(int idx, ll val) {
        update(MaxVal-idx, val);
}};

// --------------------------- 2D Fenwick Tree -------------------------
/* /\
 y  |
    |   (x1,y2) -------- (x2,y2)
    |          |       |
    |          |       |
    |          |       |
    |          ---------
    |   (x1,y1)			(x2, y1)
    |
    |___________________________
   (0, 0)                   x-->		*/

struct FTree2D {
    ll tree[MAX][MAX] = {0};
    int xMax, yMax;
    void init(int xx, int yy) {
        xMax = xx, yMax = yy;
    }
    void update(int x, int y, int val) {
        for(int x1 = x; x1 <= xMax; x1 += x1 & -x1)
            for(int y1 = y; y1 <= yMax; y1 += y1 & -y)
                tree[x1][y1] += val;
    }
    ll read(int x, int y) {
        ll sum = 0;
        for(int x1 = x; x1 > 0; x1 -= x1 & -x1)
            for(int y1 = y; y1 > 0; y1 -= y1 & -y1)
                sum += tree[x1][y1];
        return sum;
    }
    ll readSingle(int x, int y) {
        return read(x, y) - read(x-1, y) - read(x, y-1) + read(x-1, y-1);
    }
    void updateSquare(int x1, int y1, int x2, int y2, int val) {
        update(x1, y1, val);
        update(x1, y2+1, -val);
        update(x2+1, y1, -val);
        update(x2+1, y2+1, val);
    }
    ll readSquare(int x1, int y1, int x2, int y2) {                // p1 : lower left point, p2 : upper right point
        return  read(x2, y2) - read(x1-1, y2) - read(x2, y1-1) + read(x1-1, y1-1);
}};
//// --------------------------- 3D Fenwick Tree -------------------------

ll tree[105][105][105];
ll xMax = 100, yMax = 100, zMax = 100;
void update(int x, int y, int z, ll val) {
    int y1, z1;
    while(x <= xMax) {
        y1 = y;
        while(y1 <= yMax) {
            z1 = z;
            while(z1 <= zMax) {
                tree[x][y1][z1] += val;
                z1 += (z1 & -z1);
            }
            y1 += (y1 & -y1);
        }
        x += (x & -x);
}}
ll read(int x, int y, int z) {
    ll sum = 0;
    int y1, z1;
    while(x > 0) {
        y1 = y;
        while(y1 > 0) {
            z1 = z;
            while(z1 > 0) {
                sum += tree[x][y1][z1];
                z1 -= (z1 & -z1);
            }
            y1 -= (y1 & -y1);
        }
        x -= (x & -x);
    }
    return sum;
}
ll readRange(ll x1, ll y1, ll z1, ll x2, ll y2, ll z2) {
    --x1, --y1, --z1;
    return  read(x2, y2, z2)
	    - read(x1, y2, z2)
	    - read(x2, y1, z2)
	    - read(x2, y2, z1)
	    + read(x1, y1, z2)
	    + read(x1, y2, z1)
	    + read(x2, y1, z1)
	    - read(x1, y1, z1);
}
void updateRange(int x1, int y1, int z1, int x2, int y2, int z2) {		// Not tested yet!!
    update(x1, y1, z1, val);
    update(x2+1, y1, z1, -val);
    update(x1, y2+1, z1, -val);
    update(x1, y1, z2+1, -val);
    update(x2+1, y2+1, z1, val);
    update(x1, y2+1, z2+1, val);
    update(x2+1, y1, z2+1, val);
    update(x2+1, y2+1, z2+1, -val);
}
// Pattens to built BIT update read:
// always starts with first(starting point), add val
// take (1 to n) elements from ending point with all combination add it to staring point, add (-1)^n * val

# Mountain route solver

The goal is to **find the minimum travel time** from a start cell to a target cell on a rectangular height map.

---

## Terrain and walking cost

* The map is a grid of `W × H` square cells.
* Each cell holds a non‑negative integer **height**.
* You may move only to the four orthogonally adjacent cells.
* Moving from height **B** to height **A** costs

  * **`A − B + 1` minutes** if `A > B`,
  * **`1` minute** if `A ≤ B`.

---

## Lifts

One‑way lifts allow instant travel between two cells but depart on a schedule.

* A lift is defined by a **start cell `(ux, uy)`**, an **end cell `(vx, vy)`**,
  its **travel time `t`** and a **departure period `T`**.
* It departs at absolute times 0, `T`, `2 T`, …
* If you reach the start cell at minute `τ`, you wait
  `wait = (T − (τ mod T)) mod T` minutes, then ride `t` minutes.

---

## Input format

```
W H           # width, height
sx sy         # start column, start row
tx ty         # target column, target row
L             # number of lifts
# L lines follow
ux uy vx vy t T   # lift description
...
# Height map: H rows × W integers
a11 a12 ... a1W
...
aH1 ...  aHW
```

All integers are non‑negative and fit in 32‑bit signed range.

---

## Output

```
Minimal travel time (in minutes) from start to target.
```

---

### Example 1

*Input*

```
9 8 0 0 8 7 0
0 0 0 0 0 0 0 0 8
0 9 9 9 9 9 9 9 0
0 1 0 1 0 0 0 9 0
0 9 0 0 0 1 0 9 0
0 9 1 1 1 1 0 9 0
0 9 0 0 0 0 0 9 0
0 9 9 9 9 1 9 9 0
8 0 0 0 0 0 0 0 0
```

*Output*

```
18
```

### Example 2

*Input*

```
9 9 0 0 8 8 5
0 1 2 0 5 2
0 1 2 0 1 3
2 0 4 0 3 7
4 1 8 8 20 11
4 2 8 8 10 12
0 9 0 9 0 9 0 9 0
0 9 0 9 0 9 0 9 0
0 9 0 9 0 9 0 9 0
0 9 0 9 0 9 0 9 0
0 9 0 9 0 9 0 9 0
0 9 0 9 0 9 0 9 0
0 9 0 9 0 9 0 9 0
0 9 0 9 0 9 0 9 0
0 9 0 9 0 9 0 9 0
```

*Output*

```
22
```

> The task is typically solved with Dijkstra's algorithm while accounting for lift waiting times.
